// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SQUISHY_CONSENSUS_CONSENSUS_H
#define SQUISHY_CONSENSUS_CONSENSUS_H

#if defined(_MSC_VER) || defined(macintosh) || defined(__APPLE__) || defined(__APPLE_CC__)
typedef signed int            int32_t;
typedef unsigned int          uint32_t;
#endif

#if defined(linux) || defined(__linux)
#include <stdint.h>
#endif

#if defined(_WINDOWS) || defined(_WIN32)
#if defined(__MINGW__) || defined(__MINGW32__) || defined(__MINGW64__)
/** x86_64-w64-mingw32-gcc detect */
#include <stdint.h>
#endif
#endif

/** The minimum allowed block version (network rule) */
static const int32_t MIN_BLOCK_VERSION = 4;
/** The minimum allowed transaction version (network rule) */
static const int32_t SPROUT_MIN_TX_VERSION = 1;
/** The minimum allowed Overwinter transaction version (network rule) */
static const int32_t OVERWINTER_MIN_TX_VERSION = 3;
/** The maximum allowed Overwinter transaction version (network rule) */
static const int32_t OVERWINTER_MAX_TX_VERSION = 3;
/** The minimum allowed Sapling transaction version (network rule) */
static const int32_t SAPLING_MIN_TX_VERSION = 4;
/** The maximum allowed Sapling transaction version (network rule) */
static const int32_t SAPLING_MAX_TX_VERSION = 4;
/** The maximum allowed size for a serialized block, in bytes (network rule) */
//static const unsigned int MAX_BLOCK_SIZE = 2000000;
/** The maximum allowed number of signature check operations in a block (network rule) */
extern unsigned int MAX_BLOCK_SIGOPS;
/** The maximum size of a transaction (network rule) */
static const unsigned int MAX_TX_SIZE_BEFORE_SAPLING = 100000;
static const unsigned int MAX_TX_SIZE_AFTER_SAPLING = (2 * MAX_TX_SIZE_BEFORE_SAPLING); //MAX_BLOCK_SIZE;
/** The minimum value which is invalid for expiry height, used by CTransaction and CMutableTransaction */
static constexpr uint32_t TX_EXPIRY_HEIGHT_THRESHOLD = 500000000;

/** Flags for LockTime() */
enum {
    /* Use GetMedianTimePast() instead of nTime for end point timestamp. */
    LOCKTIME_MEDIAN_TIME_PAST = (1 << 1),
};

/** Used as the flags parameter to CheckFinalTx() in non-consensus code */
static const unsigned int STANDARD_LOCKTIME_VERIFY_FLAGS = LOCKTIME_MEDIAN_TIME_PAST;

static const int WITNESS_SCALE_FACTOR = 4;

#endif // SQUISHY_CONSENSUS_CONSENSUS_H
