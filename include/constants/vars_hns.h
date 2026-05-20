#ifndef GUARD_CONSTANTS_VARS_HNS_H
#define GUARD_CONSTANTS_VARS_HNS_H

/*
 * HnS (Heart & Soul) Johto/Kanto progression VARs - Phase 5-prep R6e-followup
 * (HMS Defiant, 2026-05-20).
 *
 * HnS authored 66 story-progression VARs that pe-expansion does not have.
 * These VARs are referenced by HnS scripts (setvar/compare/copyvar) for
 * per-city/per-event progression state machines (e.g. VAR_AZALEA_TOWN_STATE,
 * VAR_BUG_CONTEST_STATE, VAR_KANTO_ROCKET_STORY_STATE). Without #defines,
 * 21 HnS .inc files fail asm-eval with ".if non-constant" cascades.
 *
 * Operationalization: ADDITIVE EXTENSION of pe-VARS region. The pe-vanilla
 * persistent slot range (0x4000..0x40FF, 256 slots, every slot allocated) is
 * unchanged; HnS VARs occupy fresh slots (VARS_START + 0x100)..(VARS_START + 0x141),
 * extending VARS_END from 0x40FF to HNS_VARS_END (0x4141). See
 * pe-expansion/CLAUDE.md "Non-additive bumps" entry for the arithmetic chain
 * and saveblock impact (SaveBlock1.vars[] grows from 512 to 644 bytes;
 * +132 bytes well within SECTOR_DATA_SIZE * 4 = 15872 budget).
 *
 * Audit source: cross-grep of all VAR_ refs in pokeemerald-expansion/data/maps/*
 * scripts.inc against pe-vars.h + vars_frlg.h definitions, then sorted
 * alphabetically. Matches the T5 TODO(pe-migration) comment count (67 minus
 * VAR_GARBAGEVAR which was already aliased to VAR_UNUSED_0x40FF in R3).
 *
 * Schema-additive against pe: net-new VAR names (zero collisions with pe-side
 * existing 360 VAR_* defines, verified by intersection grep before authoring).
 *
 * Slot semantics: the HnS-original VAR values (also in 0x40xx range) cannot
 * be copied verbatim because every pe slot in 0x4000..0x40FF is already taken.
 * Every HnS VAR is re-slotted onto fresh (VARS_START + 0x100 + N) slots in
 * alphabetical order matching the audit list. RC is pre-release, so save-state
 * invalidation from slot reassignment is moot.
 *
 * Re-included from constants/vars.h immediately after the vanilla VAR block
 * and before VARS_END (which is rebased to HNS_VARS_END).
 *
 * Sorted alphabetically; one entry per line.
 */

#define HNS_VARS_START                                               (VARS_START + 0x100)

#define VAR_AZALEA_TOWN_STATE                                        (HNS_VARS_START + 0x00)
#define VAR_BAOBA_QUEST_STATE                                        (HNS_VARS_START + 0x01)
#define VAR_BILLS_GRANDPA                                            (HNS_VARS_START + 0x02)
#define VAR_BLACKTHORN_CITY_STATE                                    (HNS_VARS_START + 0x03)
#define VAR_BLACKTHORN_GYM_STATE                                     (HNS_VARS_START + 0x04)
#define VAR_BUG_CONTEST_STATE                                        (HNS_VARS_START + 0x05)
#define VAR_CERULEAN_CITY_STATE                                      (HNS_VARS_START + 0x06)
#define VAR_CHERRYGROVE_CITY_STATE                                   (HNS_VARS_START + 0x07)
#define VAR_CIANWOOD_CITY_STATE                                      (HNS_VARS_START + 0x08)
#define VAR_CINNABAR_ISLAND_STATE                                    (HNS_VARS_START + 0x09)
#define VAR_CLEFAIRY_DOLL_STATE                                      (HNS_VARS_START + 0x0A)
#define VAR_COMPLETED_HO_OH                                          (HNS_VARS_START + 0x0B)
#define VAR_COMPLETED_LUGIA                                          (HNS_VARS_START + 0x0C)
#define VAR_DRAGONS_DEN_QUIZ                                         (HNS_VARS_START + 0x0D)
#define VAR_ECRUTEAK_CITY_STATE                                      (HNS_VARS_START + 0x0E)
#define VAR_ECRUTEAK_CITY_THEATER                                    (HNS_VARS_START + 0x0F)
#define VAR_ELECTRODES_FAINTED                                       (HNS_VARS_START + 0x10)
#define VAR_ELEVATOR                                                 (HNS_VARS_START + 0x11)
#define VAR_ENTEI_EVENT                                              (HNS_VARS_START + 0x12)
#define VAR_FAN_CLUB_CLEFAIRY                                        (HNS_VARS_START + 0x13)
#define VAR_FAN_CLUB_GUY                                             (HNS_VARS_START + 0x14)
#define VAR_FUCHSIA_CITY_STATE                                       (HNS_VARS_START + 0x15)
#define VAR_GETFLY                                                   (HNS_VARS_START + 0x16)
#define VAR_GOLDENROD_CITY_STATE                                     (HNS_VARS_START + 0x17)
#define VAR_ICE_PATH_STATE                                           (HNS_VARS_START + 0x18)
#define VAR_ILEX_FOREST_FARFETCHD                                    (HNS_VARS_START + 0x19)
#define VAR_KANTO_ROCKET_STORY_STATE                                 (HNS_VARS_START + 0x1A)
#define VAR_KANTO_SAFARI_ZONE_PROGRESS                               (HNS_VARS_START + 0x1B)
#define VAR_KENYA                                                    (HNS_VARS_START + 0x1C)
#define VAR_LAKE_OF_RAGE_FISHERMAN                                   (HNS_VARS_START + 0x1D)
#define VAR_LEAGUE_STATE                                             (HNS_VARS_START + 0x1E)
#define VAR_LUGIA_OR_HOOH                                            (HNS_VARS_START + 0x1F)
#define VAR_MAHOGANY_TOWN_STATE                                      (HNS_VARS_START + 0x20)
#define VAR_MT_SILVER_STATE                                          (HNS_VARS_START + 0x21)
#define VAR_NEWBARK_TOWN_STATE                                       (HNS_VARS_START + 0x22)
#define VAR_NEWBARKTOWN_LABSTATE                                     (HNS_VARS_START + 0x23)
#define VAR_NUM_BADGES                                               (HNS_VARS_START + 0x24)
#define VAR_OLIVINE_CITY_STATE                                       (HNS_VARS_START + 0x25)
#define VAR_PALLETTOWN_LABSTATE                                      (HNS_VARS_START + 0x26)
#define VAR_PEWTER_CITY_STATE                                        (HNS_VARS_START + 0x27)
#define VAR_RAIKOU_EVENT                                             (HNS_VARS_START + 0x28)
#define VAR_ROCKET_HIDEOUT_STATUE_1                                  (HNS_VARS_START + 0x29)
#define VAR_ROCKET_HIDEOUT_STATUE_2                                  (HNS_VARS_START + 0x2A)
#define VAR_ROCKET_HIDEOUT_STATUE_3                                  (HNS_VARS_START + 0x2B)
#define VAR_ROCKET_HIDEOUT_STATUE_4                                  (HNS_VARS_START + 0x2C)
#define VAR_ROCKET_HIDEOUT_STATUE_5                                  (HNS_VARS_START + 0x2D)
#define VAR_ROCKET_PASSWORD                                          (HNS_VARS_START + 0x2E)
#define VAR_ROUTE22_GIOVANNI_STATE                                   (HNS_VARS_START + 0x2F)
#define VAR_ROUTE27_BAOBA_CALL                                       (HNS_VARS_START + 0x30)
#define VAR_ROUTE27_STATE                                            (HNS_VARS_START + 0x31)
#define VAR_ROUTE39_BARN                                             (HNS_VARS_START + 0x32)
#define VAR_RUINSOFALPH_STATE                                        (HNS_VARS_START + 0x33)
#define VAR_SAFARI_ZONE_GATE_STATE                                   (HNS_VARS_START + 0x34)
#define VAR_SAFFRON_CITY_STATE                                       (HNS_VARS_START + 0x35)
#define VAR_SHUCKIE                                                  (HNS_VARS_START + 0x36)
#define VAR_SLOWPOKE_TAIL                                            (HNS_VARS_START + 0x37)
#define VAR_SPROUT_TOWER                                             (HNS_VARS_START + 0x38)
#define VAR_SSAQUA_STATE                                             (HNS_VARS_START + 0x39)
#define VAR_SUICUNE_ENCOUNTERS                                       (HNS_VARS_START + 0x3A)
#define VAR_SUICUNE_EVENT                                            (HNS_VARS_START + 0x3B)
#define VAR_TIME_BASED_ENCOUNTER                                     (HNS_VARS_START + 0x3C)
#define VAR_TOHJO_FALLS_GIOVANNI_STATE                               (HNS_VARS_START + 0x3D)
#define VAR_TRAIN                                                    (HNS_VARS_START + 0x3E)
#define VAR_VERMILION_CITY_STATE                                     (HNS_VARS_START + 0x3F)
#define VAR_VIOLET_CITY_KIMONO_GIRL                                  (HNS_VARS_START + 0x40)
#define VAR_VIOLET_CITY_STATE                                        (HNS_VARS_START + 0x41)

#define HNS_VARS_END                                                 VAR_VIOLET_CITY_STATE

#endif // GUARD_CONSTANTS_VARS_HNS_H
