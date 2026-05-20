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
