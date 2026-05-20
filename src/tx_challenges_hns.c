// HnS tx_randomizer_and_challenges script-callable native functions, ported
// as no-op stubs.
//
// This file provides linkage for the 11 HnS-only callnative symbols invoked
// from HnS-imported scripts (data/maps/**/scripts.inc) that toggle the HnS
// tx_randomizer / tx_challenges subsystem. Pe-expansion does not ship that
// subsystem and pe scripts have no equivalent. The stubs are pure no-ops:
// scripts that invoke these toggles run to completion without state change,
// leaving the (non-existent) feature in its default-off state.
//
// Family disposition: pe has no analogous engine surface to port to. Proper
// port (the full tx_randomizer_and_challenges feature: static randomizer of
// trainer parties, items, and wild encounters, plus a suite of post-game
// challenge modes) is a multi-day separate-feature undertaking. Queued as
// feat/port-hns-tx-randomizer post-Phase-6.
//
// Categories:
//   - DisableChallengesAfterBeatingGame*: 9 functions, each tied to a
//     specific HnS post-game challenge mode (evo-limit run, expensive-
//     challenge run, mirror-mode run, mirror-thief run, no-item-player
//     run, no-item-trainer run, one-type run, party-limit run, pokecenter-
//     challenge run). HnS invokes them from BattleFrontier_PokemonCenter_1F
//     to lock challenges after Hall-of-Fame entry.
//   - StaticRandomizer toggle: 2 functions (Enable/Disable). HnS invokes
//     them from NewBarkTown_Lab (Prof Elm intro), GoldenrodCity_GameCorner
//     (slot prize selection), and CianwoodPokecenter (Suicune dialog) to
//     gate the static-randomizer feature.
//
// Apostrophe-free docstring per gnu17 cpp quirk noted in flags_hns.h.

#include "global.h"
#include "tx_challenges_hns.h"

// ---------------------------------------------------------------------------
// Disable*Challenges*AfterBeatingGame* family (9 functions)
// ---------------------------------------------------------------------------

void DisableChallengesAfterBeatingGameEvoLimit(void)
{
    // no-op stub.
}

void DisableChallengesAfterBeatingGameExpensiveChallenge(void)
{
    // no-op stub.
}

void DisableChallengesAfterBeatingGameMirror(void)
{
    // no-op stub.
}

void DisableChallengesAfterBeatingGameMirrorThief(void)
{
    // no-op stub.
}

void DisableChallengesAfterBeatingGameNoItemPlayer(void)
{
    // no-op stub.
}

void DisableChallengesAfterBeatingGameNoItemTrainer(void)
{
    // no-op stub.
}

void DisableChallengesAfterBeatingGameOneType(void)
{
    // no-op stub.
}

void DisableChallengesAfterBeatingGamePartyLimit(void)
{
    // no-op stub.
}

void DisableChallengesAfterBeatingGamePkmCenterChallenge(void)
{
    // no-op stub.
}

// ---------------------------------------------------------------------------
// StaticRandomizer toggle (2 functions)
// ---------------------------------------------------------------------------

void DisableStaticRandomizer(void)
{
    // no-op stub.
}

void EnableStaticRandomizer(void)
{
    // no-op stub.
}
