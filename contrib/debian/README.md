
Debian
====================
This directory contains files used to package kringleprojectcoind/kringleprojectcoin-qt
for Debian-based Linux systems. If you compile kringleprojectcoind/kringleprojectcoin-qt yourself, there are some useful files here.

## kringleprojectcoin: URI support ##


kringleprojectcoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install kringleprojectcoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your kringleprojectcoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/kringleprojectcoin128.png` to `/usr/share/pixmaps`

kringleprojectcoin-qt.protocol (KDE)

