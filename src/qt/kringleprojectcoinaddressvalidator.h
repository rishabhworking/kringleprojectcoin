// Copyright (c)  The Bitcoin Core developers
// Copyright (c) 2017 The Raven Core developers
// Copyright (c) 2018 The Rito Core developers
// Copyright (c) 2020 The KringleProjectCoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef KPC_QT_KPCADDRESSVALIDATOR_H
#define KPC_QT_KPCADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class KringleProjectCoinAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit KringleProjectCoinAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

/** KringleProjectCoin address widget validator, checks for a valid kringleprojectcoin address.
 */
class KringleProjectCoinAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit KringleProjectCoinAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const;
};

#endif // KPC_QT_KPCADDRESSVALIDATOR_H
