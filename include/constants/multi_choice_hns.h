#ifndef GUARD_CONSTANTS_MULTI_CHOICE_HNS_H
#define GUARD_CONSTANTS_MULTI_CHOICE_HNS_H

/*
 * HnS-only multichoice menu IDs - Phase 4 R6b (HMS Norfolk, 2026-05-20).
 *
 * HnS scripts reference 15 multichoice menu names that pe-expansion does not
 * have. These are passed to the `multichoice` / `multichoicedefault` script
 * commands, which index into pe sMultichoiceLists[] at src/data/script_menu.h
 * to resolve menu option text. Without these #defines every HnS .inc file
 * referencing one fails C-compile with undeclared-identifier cascades.
 *
 * Operationalization: ADDITIVE EXTENSION of pe MULTI_ namespace. Pe vanilla
 * slot range occupies IDs 0..158 in include/constants/script_menu.h, with
 * MULTI_NONE = 255 as the sentinel. HnS additions occupy 159..173 (15 slots),
 * well below MULTI_NONE so the sentinel arithmetic at src/script_menu.c is
 * unaffected.
 *
 * Stub disposition: link-resolution only. These IDs are NOT wired into
 * sMultichoiceLists[] this round (that lookup table currently spans 0..158).
 * Any script that actually invokes one of these menus at runtime would index
 * out-of-bounds into sMultichoiceLists, which is acceptable for Phase 5 mGBA
 * smoke because the HnS scripts that exercise these menus (radio tower
 * elder quiz, Olivine harbor dialog, prize Pokemon corner, etc.) gate on
 * progression flags currently set FALSE by the HnS frozen-state, so none
 * fire pre-Falkner.
 *
 * Proper menu-option authoring (MultichoiceList_HnsDaysOfWeek etc., wired
 * into sMultichoiceLists with new MULTICHOICE() entries) queued as
 * feat/port-hns-multichoice-menus post-Phase-6.
 *
 * Schema-additive against pe: net-new IDs (zero collisions with pe MULTI_).
 * Apostrophe-free docstring per gnu17 cpp quirk.
 *
 * Sorted alphabetically (matches r6b_multi.txt audit order).
 */

#define MULTI_5FLOORS                 159
#define MULTI_7FLOORS                 160
#define MULTI_DAYS_OF_WEEK            161
#define MULTI_ELDERQUIIZ1             162
#define MULTI_ELDERQUIIZ2             163
#define MULTI_ELDERQUIIZ3             164
#define MULTI_ELDERQUIIZ4             165
#define MULTI_ELDERQUIIZ5             166
#define MULTI_GAME_CORNER_DOLLS2      167
#define MULTI_GOLDSILVER              168
#define MULTI_HOENN_STARTERS          169
#define MULTI_KURT_BALLS              170
#define MULTI_OLIVINE_HARBOR          171
#define MULTI_PRIZE_MONS              172
#define MULTI_VERMILION_HARBOR        173

#endif // GUARD_CONSTANTS_MULTI_CHOICE_HNS_H
