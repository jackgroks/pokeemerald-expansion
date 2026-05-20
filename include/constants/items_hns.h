#ifndef GUARD_CONSTANTS_ITEMS_HNS_H
#define GUARD_CONSTANTS_ITEMS_HNS_H

/* ============================================================================
 * RC HnS item-name compatibility banner (Phase 5-prep R6a, HMS Decoy).
 *
 * This file is intentionally empty of #defines. It exists to document the
 * disposition of the HnS-side ITEM_TM_* / ITEM_HM_* surface against pe's
 * macro-generated naming:
 *
 *   - pe's FOREACH_TM(F) / FOREACH_HM(F) in include/constants/tms_hms.h
 *     auto-generate ITEM_TM_<NAME> and ITEM_HM_<NAME> aliases for every
 *     entry. HnS's TM01-TM55 list is identical to pe's; therefore 55 of
 *     56 HnS TM/HM name references resolve as-is, with no aliases needed.
 *
 *   - The one outlier is HM09 / WHIRLPOOL. HnS treats Whirlpool as HM09
 *     (Whirl Islands plot gate); pe shipped only HM01-HM08. R6a extended
 *     FOREACH_HM with F(WHIRLPOOL), which:
 *       * Generated ITEM_HM_WHIRLPOOL automatically.
 *       * Required inserting ITEM_HM09 = 690 in items.h, cascading a
 *         one-time +1 renumber of ITEM_OVAL_CHARM..ITEM_GLIMMORANITE
 *         (690..873 -> 691..874). See pokeemerald-expansion/CLAUDE.md
 *         "RC bump history" for the rationale.
 *       * Added an [ITEM_HM_WHIRLPOOL] data entry in src/data/items.h
 *         mirroring [ITEM_HM_DIVE].
 *       * NUM_HIDDEN_MACHINES auto-bumped 8 -> 9 via
 *         (0 FOREACH_HM(PLUS_ONE)) in include/item.h.
 *
 * No further HnS-specific item aliases are required at this layer. If new
 * HnS items surface during Phase 5 mGBA smoke that are NOT TM/HM names,
 * land them here as additive #defines rather than re-numbering items.h.
 * ============================================================================ */

/* ============================================================================
 * Phase 4 R6b HnS-only key items (HMS Norfolk, 2026-05-20).
 *
 * 17 HnS-only item symbols referenced by HnS-imported scripts (map.json
 * giveitem / additem / removeitem calls, scripts.inc literals) with no
 * pe-expansion equivalent. Disposition: BETA-STUB to ITEM_NONE for link
 * resolution. Reasoning:
 *
 *   - ROM-produce-critical path is link-resolution only. Semantic item
 *     behavior (e.g., ITEM_GS_BALL plot gate to Ilex Forest / Celebi,
 *     ITEM_SILVER_WING / ITEM_RAINBOW_WING legendary encounter gates,
 *     ITEM_RADIO + ITEM_PASS quest items) is post-Phase-6 polish.
 *   - Stubbing to ITEM_NONE makes giveitem / removeitem calls no-op
 *     gracefully (additem of ITEM_NONE is checked by AddBagItem and
 *     returns FALSE without modifying inventory). checkitem of ITEM_NONE
 *     returns FALSE so scripts gating on these items fall through to the
 *     no-feature path.
 *   - Proper item ports queued as feat/port-hns-key-items post-Phase-6;
 *     each item gets a real slot in items.h + items.h data entry +
 *     bag-pocket assignment.
 *
 * Apostrophe-free docstring per gnu17 cpp quirk noted in flags_hns.h.
 * ============================================================================ */

#define ITEM_CLEAR_BELL              ITEM_NONE
#define ITEM_EXP_SHARE_SMALL         ITEM_NONE
#define ITEM_FERTILIZER              ITEM_NONE
#define ITEM_GS_BALL                 ITEM_NONE
#define ITEM_INFINITE_RARE_CANDIES   ITEM_NONE
#define ITEM_INFINITE_REPEL          ITEM_NONE
#define ITEM_LOST_ITEM               ITEM_NONE
#define ITEM_MACHINE_PART            ITEM_NONE
#define ITEM_MYSTERY_EGG             ITEM_NONE
#define ITEM_PASS                    ITEM_NONE
#define ITEM_RADIO                   ITEM_NONE
#define ITEM_RAINBOW_WING            ITEM_NONE
#define ITEM_RED_SCALE               ITEM_NONE
#define ITEM_SECRET_POTION           ITEM_NONE
#define ITEM_SILVER_WING             ITEM_NONE
#define ITEM_SQUIRT_BOTTLE           ITEM_NONE
#define ITEM_TIDAL_BELL              ITEM_NONE

#endif // GUARD_CONSTANTS_ITEMS_HNS_H
