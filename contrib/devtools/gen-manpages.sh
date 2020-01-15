#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

KPCD=${KPCD:-$SRCDIR/kringleprojectcoind}
KPCCLI=${KPCCLI:-$SRCDIR/kringleprojectcoin-cli}
KPCTX=${KPCTX:-$SRCDIR/kringleprojectcoin-tx}
KPCQT=${KPCQT:-$SRCDIR/qt/kringleprojectcoin-qt}

[ ! -x $KPCD ] && echo "$KPCD not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
KPCVER=($($KPCCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for kringleprojectcoind if --version-string is not set,
# but has different outcomes for kringleprojectcoin-qt and kringleprojectcoin-cli.
echo "[COPYRIGHT]" > footer.h2m
$KPCD --version | sed -n '1!p' >> footer.h2m

for cmd in $KPCD $KPCCLI $KPCTX $KPCQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${KPCVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${KPCVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
