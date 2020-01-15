// Copyright (c)  The Bitcoin Core developers
// Copyright (c) 2017 The Raven Core developers
// Copyright (c) 2018 The Rito Core developers
// Copyright (c) 2020 The KringleProjectCoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef KPC_KPCCONSENSUS_H
#define KPC_KPCCONSENSUS_H

#include <stdint.h>

#if defined(BUILD_KPC_INTERNAL) && defined(HAVE_CONFIG_H)
#include "config/kringleprojectcoin-config.h"
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBKPCCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define KPCCONSENSUS_API_VER 1

typedef enum kringleprojectcoinconsensus_error_t
{
    kringleprojectcoinconsensus_ERR_OK = 0,
    kringleprojectcoinconsensus_ERR_TX_INDEX,
    kringleprojectcoinconsensus_ERR_TX_SIZE_MISMATCH,
    kringleprojectcoinconsensus_ERR_TX_DESERIALIZE,
    kringleprojectcoinconsensus_ERR_AMOUNT_REQUIRED,
    kringleprojectcoinconsensus_ERR_INVALID_FLAGS,
} kringleprojectcoinconsensus_error;

/** Script verification flags */
enum
{
    kringleprojectcoinconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    kringleprojectcoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    kringleprojectcoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    kringleprojectcoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    kringleprojectcoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    kringleprojectcoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    kringleprojectcoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    kringleprojectcoinconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = kringleprojectcoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH | kringleprojectcoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               kringleprojectcoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | kringleprojectcoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               kringleprojectcoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | kringleprojectcoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not nullptr, err will contain an error/success code for the operation
EXPORT_SYMBOL int kringleprojectcoinconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, kringleprojectcoinconsensus_error* err);

EXPORT_SYMBOL int kringleprojectcoinconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, kringleprojectcoinconsensus_error* err);

EXPORT_SYMBOL unsigned int kringleprojectcoinconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // KPC_KPCCONSENSUS_H
