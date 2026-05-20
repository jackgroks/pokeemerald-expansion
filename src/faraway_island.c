// Phase 2 minimal-strip: Faraway Island is a pe-Hoenn Mew-event island
// triggered by the Old Sea Map ticket distribution, unreachable in HnS
// Johto/Kanto play. The original module implemented Mew's hide-and-seek
// movement AI on the island. All public API functions are stubbed to safe
// defaults (no Mew present, no movement, no step counter).
//
// LOCALID_FARAWAY_ISLAND_MEW is the Hoenn-side event referenced from
// scripts that won't fire in HnS play. Restore the original file when
// Hoenn content is being authored.

#include "global.h"
#include "event_object_movement.h"
#include "faraway_island.h"

u32 GetMewMoveDirection(void)
{
    return DIR_NONE;
}

bool8 ShouldMewShakeGrass(struct ObjectEvent *objectEvent)
{
    (void)objectEvent;
    return FALSE;
}

void UpdateFarawayIslandStepCounter(void) { }

bool8 ObjectEventIsFarawayIslandMew(struct ObjectEvent *objectEvent)
{
    (void)objectEvent;
    return FALSE;
}

bool8 IsMewPlayingHideAndSeek(void)
{
    return FALSE;
}
