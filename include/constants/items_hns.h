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

#endif // GUARD_CONSTANTS_ITEMS_HNS_H
