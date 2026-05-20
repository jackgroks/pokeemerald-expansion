#ifndef GUARD_CONSTANTS_MAP_BATTLE_SCENE_HNS_H
#define GUARD_CONSTANTS_MAP_BATTLE_SCENE_HNS_H

/*
 * HnS (Heart & Soul) Johto Elite Four battle scene IDs - Phase 4 R5c
 * (HMS Diamond II, 2026-05-20).
 *
 * HnS map JSONs for the Indigo Plateau Elite Four rooms (Will, Koga, Karen)
 * reference MAP_BATTLE_SCENE_WILL / MAP_BATTLE_SCENE_KOGA /
 * MAP_BATTLE_SCENE_KAREN as the per-room battle backdrop selector. pe-side
 * `include/constants/map_types.h` defines an `enum MapBattleScene` covering
 * pe-Hoenn E4 (SIDNEY, PHOEBE, GLACIA, DRAKE) plus FRONTIER, and aliases the
 * pe-FRLG E4 (LORELEI, BRUNO, AGATHA, LANCE) and LINK to NORMAL. HnS-Johto E4
 * names are not in either set.
 *
 * Operationalization: ADDITIVE ALIAS onto pe-side MAP_BATTLE_SCENE_NORMAL,
 * mirroring the pattern at map_types.h lines 31-37 (pe-FRLG E4 aliases). This
 * gets HnS maps compile-clean. The visual backdrop rendered at the HnS E4
 * fights will be the plain interior backdrop until a future HnS-graphics port
 * authors proper Will/Koga/Karen backdrop tilesets and extends the
 * `enum MapBattleScene` with three new slots.
 *
 * Note: MAP_BATTLE_SCENE_BRUNO is already aliased to MAP_BATTLE_SCENE_NORMAL
 * at map_types.h:34 (pe-FRLG E4 alias) - HnS-Johto reuses Bruno-the-name for
 * the same E4-room role, so no new alias is needed for Bruno.
 *
 * Schema-additive against map_types.h: zero name collisions; the
 * `enum MapBattleScene` is not modified.
 *
 * Upstream-merge rule: if RHH ever extends MapBattleScene with proper Johto
 * E4 entries, drop the corresponding aliases here.
 */

#define MAP_BATTLE_SCENE_WILL    MAP_BATTLE_SCENE_NORMAL
#define MAP_BATTLE_SCENE_KOGA    MAP_BATTLE_SCENE_NORMAL
#define MAP_BATTLE_SCENE_KAREN   MAP_BATTLE_SCENE_NORMAL

#endif // GUARD_CONSTANTS_MAP_BATTLE_SCENE_HNS_H
