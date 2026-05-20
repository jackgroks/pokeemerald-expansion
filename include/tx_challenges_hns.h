#ifndef GUARD_TX_CHALLENGES_HNS_H
#define GUARD_TX_CHALLENGES_HNS_H

// Externs for HnS tx_randomizer_and_challenges script-callable functions
// (Disable*Challenges* family + StaticRandomizer toggle). Implementations
// live in src/tx_challenges_hns.c as no-op stubs; proper port queued as
// feat/port-hns-tx-randomizer post-Phase-6. See that file for the full
// disposition note.

void DisableChallengesAfterBeatingGameEvoLimit(void);
void DisableChallengesAfterBeatingGameExpensiveChallenge(void);
void DisableChallengesAfterBeatingGameMirror(void);
void DisableChallengesAfterBeatingGameMirrorThief(void);
void DisableChallengesAfterBeatingGameNoItemPlayer(void);
void DisableChallengesAfterBeatingGameNoItemTrainer(void);
void DisableChallengesAfterBeatingGameOneType(void);
void DisableChallengesAfterBeatingGamePartyLimit(void);
void DisableChallengesAfterBeatingGamePkmCenterChallenge(void);
void DisableStaticRandomizer(void);
void EnableStaticRandomizer(void);

#endif // GUARD_TX_CHALLENGES_HNS_H
