// Phase 2 minimal-strip: Mirage Tower is a pe-Hoenn Route 111 event,
// unreachable in HnS Johto/Kanto play. The original module managed sprite
// pulse-blend effects, dynamic tile generation, and player-falling cinematic
// for the tower interior. All public API functions are stubbed.
//
// LOCALID_ROUTE111_PLAYER_FALLING is the Hoenn-side event referenced from
// scripts that won't fire in HnS play. Restore the original file when Hoenn
// content is being authored (or delete after facility-by-facility strip).

#include "global.h"
#include "mirage_tower.h"

void ClearMirageTowerPulseBlendEffect(void) { }
void ClearMirageTowerPulseBlend(void) { }
void TryStartMirageTowerPulseBlendEffect(void) { }

// Phase 4 R6c (HMS Plymouth, 2026-05-20): extend stubs to cover the full
// pe-Hoenn Mirage Tower script-callable surface referenced from data/specials.inc.
// All are void(void) script-callable specials; unreachable in HnS Johto/Kanto play.
void DoMirageTowerCeilingCrumble(void) { }
void SetMirageTowerVisibility(void) { }
void StartMirageTowerDisintegration(void) { }
void StartMirageTowerFossilFallAndSink(void) { }
void StartMirageTowerShake(void) { }
void StartPlayerDescendMirageTower(void) { }
