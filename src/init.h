// Copyright (c) 2011-2018 The Bitcoin Core developers
// Copyright (c) 2017 The Raven Core developers
// Copyright (c) 2018 The Rito Core developers
// Copyright (c) 2020 The KringleProjectCoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef KPC_INIT_H
#define KPC_INIT_H

#include <string>
#include "amount.h"

// Dev fee will go for about 1 year and then cease.
// 50% of the dev fee goes toward a community fund that will be used for paying bounties.
// 50% of the dev fee goes toward a core dev fund as a founders reward for ongoing developments of KringleProjectCoin Core
#define DEV_ADDRESS "KPCBurnxxxxxxxxxxxxxxxxxxxxxZ8gFNy"
#define DEV_FUND_UNTIL 0
CAmount GetDevCoin(CAmount reward);
#define ASSET_ACTIVATION_HEIGHT 100

class CScheduler;

class CWallet;

namespace boost
{
    class thread_group;
} // namespace boost

void StartShutdown();

bool ShutdownRequested();

/** Interrupt threads */
void Interrupt(boost::thread_group &threadGroup);

void Shutdown();

//!Initialize the logging infrastructure
void InitLogging();

//!Parameter interaction: change current parameters depending on various rules
void InitParameterInteraction();

/** Initialize kringleprojectcoin core: Basic context setup.
 *  @note This can be done before daemonization. Do not call Shutdown() if this function fails.
 *  @pre Parameters should be parsed and config file should be read.
 */
bool AppInitBasicSetup();

/**
 * Initialization: parameter interaction.
 * @note This can be done before daemonization. Do not call Shutdown() if this function fails.
 * @pre Parameters should be parsed and config file should be read, AppInitBasicSetup should have been called.
 */
bool AppInitParameterInteraction();

/**
 * Initialization sanity checks: ecc init, sanity checks, dir lock.
 * @note This can be done before daemonization. Do not call Shutdown() if this function fails.
 * @pre Parameters should be parsed and config file should be read, AppInitParameterInteraction should have been called.
 */
bool AppInitSanityChecks();

/**
 * Lock kringleprojectcoin core data directory.
 * @note This should only be done after daemonization. Do not call Shutdown() if this function fails.
 * @pre Parameters should be parsed and config file should be read, AppInitSanityChecks should have been called.
 */
bool AppInitLockDataDirectory();

/**
 * KringleProjectCoin core main initialization.
 * @note This should only be done after daemonization. Call Shutdown() if this function fails.
 * @pre Parameters should be parsed and config file should be read, AppInitLockDataDirectory should have been called.
 */
bool AppInitMain(boost::thread_group &threadGroup, CScheduler &scheduler);

/** The help message mode determines what help message to show */
enum HelpMessageMode
{
    HMM_KPCD,
    HMM_KPC_QT
};

/** Help for options shared between UI and daemon (for -help) */
std::string HelpMessage(HelpMessageMode mode);

/** Returns licensing information (for -version) */
std::string LicenseInfo();

#endif // KPC_INIT_H
