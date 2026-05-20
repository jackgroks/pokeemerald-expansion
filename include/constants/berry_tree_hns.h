#ifndef GUARD_CONSTANTS_BERRY_TREE_HNS_H
#define GUARD_CONSTANTS_BERRY_TREE_HNS_H

/*
 * HnS (Heart & Soul) Johto/Kanto berry tree IDs - Phase 4 R5c (HMS Diamond II,
 * 2026-05-20).
 *
 * HnS authored 38 additional berry-tree slots (BERRY_TREE_CHERI_1 ..
 * BERRY_TREE_TAMATO_3, indexes 90..127) that pe-expansion does not define.
 * pe-side `include/constants/berry.h` defines slots 1..89 (Hoenn berry trees)
 * and reserves the remainder of the 128-slot table as "Remainder are unused"
 * (see berry.h line 146-148). HnS reuses those reserved slots verbatim for its
 * own Johto/Kanto-region berry trees.
 *
 * Operationalization: ADDITIVE EXTENSION inside the existing
 * BERRY_TREES_COUNT (128) budget. No slot bumps, no SaveBlock growth, no
 * schema changes. SaveBlock1.berryTrees[BERRY_TREES_COUNT] (sized 128 since
 * 2003) already covers every HnS slot. Each HnS slot value matches the
 * upstream HnS source verbatim at pokemonHnS/include/constants/berry.h lines
 * 130-167, so HnS-side map.json berry-tree references resolve byte-identical
 * to the HnS source after T7 (berry-tree port).
 *
 * Schema-additive against pe-side berry.h: zero name collisions (verified by
 * intersection grep between pe-side defines and HnS-side defines).
 * BERRY_TREES_COUNT remains 128.
 *
 * Audit input: build-log undef-ref scrape (HANDOFF.md R5c entry counts 38
 * BERRY_TREE_* unresolved symbols). Each entry below maps 1:1 onto HnS-side
 * source.
 *
 * Upstream-merge rule: if RHH ever defines any of these 38 names (extremely
 * unlikely - these are Johto/Kanto-region berry locations specific to HnS
 * authoring), prefer RHH-side slot and drop the entry here.
 */

#define BERRY_TREE_CHERI_1      90
#define BERRY_TREE_CHERI_2      91
#define BERRY_TREE_CHESTO_1     92
#define BERRY_TREE_CHESTO_2     93
#define BERRY_TREE_PECHA_1      94
#define BERRY_TREE_PECHA_2      95
#define BERRY_TREE_RAWST_1      96
#define BERRY_TREE_RAWST_2      97
#define BERRY_TREE_ASPEAR_1     98
#define BERRY_TREE_ASPEAR_2     99
#define BERRY_TREE_LEPPA_1      100
#define BERRY_TREE_LEPPA_2      101
#define BERRY_TREE_ORAN_1       102
#define BERRY_TREE_ORAN_2       103
#define BERRY_TREE_PERSIM_1     104
#define BERRY_TREE_PERSIM_2     105
#define BERRY_TREE_LUM_1        106
#define BERRY_TREE_LUM_2        107
#define BERRY_TREE_SITRUS_1     108
#define BERRY_TREE_SITRUS_2     109
#define BERRY_TREE_POMEG_1      110
#define BERRY_TREE_POMEG_2      111
#define BERRY_TREE_POMEG_3      112
#define BERRY_TREE_KELPSY_1     113
#define BERRY_TREE_KELPSY_2     114
#define BERRY_TREE_KELPSY_3     115
#define BERRY_TREE_QUALOT_1     116
#define BERRY_TREE_QUALOT_2     117
#define BERRY_TREE_QUALOT_3     118
#define BERRY_TREE_HONDEW_1     119
#define BERRY_TREE_HONDEW_2     120
#define BERRY_TREE_HONDEW_3     121
#define BERRY_TREE_GREPA_1      122
#define BERRY_TREE_GREPA_2      123
#define BERRY_TREE_GREPA_3      124
#define BERRY_TREE_TAMATO_1     125
#define BERRY_TREE_TAMATO_2     126
#define BERRY_TREE_TAMATO_3     127

#endif // GUARD_CONSTANTS_BERRY_TREE_HNS_H
