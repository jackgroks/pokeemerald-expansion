// Phase 4 R6c (HMS Plymouth, 2026-05-20): C-function stubs for the residual
// undefined-reference cluster on rc-main.
//
// Functions here all share the `callnative` signature
// (void X(struct ScriptContext *ctx)) and are called from .inc scripts via
// the `callnative` macro in pe-expansion. Each was stripped from pe by an
// earlier Phase 2 minimal-strip pass (or never existed because the feature
// it serves was HnS-side authored) but the call sites still reference them.
//
// Stubs are no-ops; call sites are either Phase-2-deferred BattleFrontier
// territory, pe-Hoenn-unreachable territory, or HM/repel/PC flows that HnS
// re-routes through its own scripts. Restoring the real implementations
// happens during a future facility-by-facility port pass.

#include "global.h"
#include "script.h"

// Berry-tree ready check.
// Called from data/scripts/berry_tree.inc - HnS reimplements berry trees via
// its own apricorn-tree-derived mechanism (see data/scripts/apricorn_tree.inc).
void Berry_Ready(struct ScriptContext *ctx)
{
    (void)ctx;
}

// PC ChallengeViewer task spawn.
// Called from data/scripts/pc.inc - tx_challenges UI hook;
// HnS does not surface a challenge viewer.
void Task_ChallengeViewer(struct ScriptContext *ctx)
{
    (void)ctx;
}

// Object-event trainer-range readback into a script var.
// Called from data/scripts/item_ball_scripts.inc - returns the trainer
// sight-range for the calling object template.
void GetObjectEventTrainerRangeFromTemplate(struct ScriptContext *ctx)
{
    (void)ctx;
}

// Item hold-effect parameter readback (repel.inc uses this to compute
// effective repel-step counts from the active repel item).
// Stub returns no result; repel scripting falls through to default behavior.
void ItemId_GetHoldEffectParam_Script(struct ScriptContext *ctx)
{
    (void)ctx;
}

// Time-based encounter table swap.
// Called from many HnS map scripts and from AbandonedShip/ArtisanCave/
// BattleFrontier_OutsideWest maps. HnS day/night encounter routing happens
// elsewhere; this stub keeps the script chain compiling without changing
// the active encounter table.
void SetTimeBasedEncounters(struct ScriptContext *ctx)
{
    (void)ctx;
}
