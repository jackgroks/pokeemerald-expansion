#ifndef GUARD_CONSTANTS_BATTLE_FRONTIER_HNS_H
#define GUARD_CONSTANTS_BATTLE_FRONTIER_HNS_H

/* ============================================================================
 * RC HnS Battle Frontier facility-selector compatibility banner
 * (Phase 5-prep R6e, HMS Vanguard).
 *
 * HnS extended pe's `SPECIAL_BATTLE_*` enum with one identifier per Battle
 * Frontier facility. Pe ships only `SPECIAL_BATTLE_SECRET_BASE` (1),
 * `SPECIAL_BATTLE_EREADER` (2), and `SPECIAL_BATTLE_MULTI` (3); the
 * per-facility selectors (TOWER, DOME, PALACE, ARENA, FACTORY, PIKE_SINGLE,
 * PIKE_DOUBLE, LANCE, PYRAMID) are referenced by HnS-landed scripts in
 * Battle Frontier rooms + SlateportCity_BattleTentBattleRoom.
 *
 * Disposition: ALL Battle Frontier and Battle Tent facilities are
 * Phase-2-deferred-indefinitely per user direction 2026-05-19. The maps
 * are unreachable in HnS Johto play (no NPC/warp leads to them). The
 * runtime dispatcher `DoSpecialTrainerBattle` in pe does not switch on
 * these new values; the constants exist purely to clear the gas-pass
 * `.if non-constant` errors so the build progresses past event_scripts.o.
 *
 * Slot policy: additive new values starting at 10 (above pe's 1..3) to
 * avoid colliding with `SPECIAL_BATTLE_SECRET_BASE/EREADER/MULTI`. The
 * exact numeric value is semantically irrelevant since the maps are
 * unreachable; uniqueness is preserved in case Phase-2 cleanup later
 * adds runtime routing.
 *
 * SPECIAL_BATTLE_LANCE is HnS-Johto-specific (post-E4 Lance Multi-Battle
 * sequence) — same treatment.
 *
 * Upstream-merge rule: If RHH ever adds per-facility SPECIAL_BATTLE_*
 * values, prefer theirs and drop this file's collisions. If RHH bumps
 * `SPECIAL_BATTLE_MULTI` past 9, push these slot values up to avoid
 * collision.
 * ============================================================================ */

#define SPECIAL_BATTLE_TOWER       10
#define SPECIAL_BATTLE_DOME        11
#define SPECIAL_BATTLE_PALACE      12
#define SPECIAL_BATTLE_ARENA       13
#define SPECIAL_BATTLE_FACTORY     14
#define SPECIAL_BATTLE_PIKE_SINGLE 15
#define SPECIAL_BATTLE_PIKE_DOUBLE 16
#define SPECIAL_BATTLE_LANCE       17
#define SPECIAL_BATTLE_PYRAMID     18

#endif // GUARD_CONSTANTS_BATTLE_FRONTIER_HNS_H
