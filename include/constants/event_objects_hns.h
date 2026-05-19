#ifndef GUARD_CONSTANTS_EVENT_OBJECTS_HNS_H
#define GUARD_CONSTANTS_EVENT_OBJECTS_HNS_H

/*
 * HnS (Heart & Soul) Johto/Kanto OBJ_EVENT_GFX constants — Phase 5-prep R6b
 * (HMS Diadem, 2026-05-19).
 *
 * HnS event scripts and map JSONs reference object-event graphics IDs by HnS-
 * authored names (OBJ_EVENT_GFX_FALKNER, OBJ_EVENT_GFX_SILVER, ...) that pe-
 * expansion's `event_objects.h` does not define. This header fills the gap
 * with 39 additive #defines that alias HnS names onto pe's existing OBJ_EVENT_
 * GFX numeric slots, mirroring the Operationalization-I additive-alias pattern
 * established by `opponents_hns.h` (HMS Defiant, R5).
 *
 * Audit input: `.context/chore/migrate-to-pe-expansion/r6-audit/objgfx_gap_full.txt`
 * (40 OBJ_EVENT_GFX_* undefined in pe, audited by HMS Dasher). The 40th entry,
 * OBJ_EVENT_GFX_MON_BASE, is intentionally EXCLUDED from this header — it is
 * a species-indexed engine port handled separately in R6c (HMS Druid).
 *
 * Strategy: every HnS slot collides with a pre-existing pe-Hoenn slot at the
 * same numeric value. Rather than allocate new slots (which would require
 * bumping NUM_OBJ_EVENT_GFX and shifting OBJ_EVENT_GFX_VARS), this header
 * preserves HnS's authored slot numbers verbatim. Both pe-Hoenn and HnS names
 * for the same slot are now valid identifiers that expand to the same integer;
 * the visual rendered at runtime depends on which graphics asset the
 * `object_event_graphics_info_pointers` table has at that slot. T-tooling
 * (graphics_file_rules.mk overlay, future Phase 5+ asset port) replaces the
 * pe-Hoenn asset at colliding slots with HnS's authored graphic; until then
 * the pe-Hoenn sprite shows as a placeholder. NUM_OBJ_EVENT_GFX is NOT bumped
 * because no new numeric slot is introduced.
 *
 * Failure modes the user can expect at Phase 5 mGBA smoke:
 *   - Falkner (slot 125) renders as pe's ROXANNE sprite until graphics port.
 *   - Silver (slot 135) renders as pe's WALLY sprite until graphics port.
 *   - Etc. — visual placeholders are EXPECTED and ACCEPTED for now; compile
 *     and event-flow correctness are the R6b deliverable.
 *
 * Schema-additive against `event_objects.h`: zero existing definitions
 * touched; no NUM_OBJ_EVENT_GFX bump; no OBJ_EVENT_GFX_VARS shift.
 *
 * Sorted alphabetically within each section; one #define per line; collision-
 * checked against `event_objects.h` (zero redefinition — all 39 names are
 * pe-undefined).
 */

// ----- Gym Leaders (Johto) -----
#define OBJ_EVENT_GFX_FALKNER                    125
#define OBJ_EVENT_GFX_BUGSY                      126
#define OBJ_EVENT_GFX_WHITNEY                    127
#define OBJ_EVENT_GFX_MORTY                      128
#define OBJ_EVENT_GFX_JASMINE                    129
#define OBJ_EVENT_GFX_CHUCK                      130
#define OBJ_EVENT_GFX_PRYCE                      132
#define OBJ_EVENT_GFX_CLAIR                      218

// ----- Gym Leaders (Kanto-side, HnS-canonical) -----
// TODO(Phase 5+): real sprite assets for SURGE/JANINE/SILVER must be ported;
// until then these resolve to pe-Hoenn sprites at the colliding slot.
#define OBJ_EVENT_GFX_SURGE                       73
#define OBJ_EVENT_GFX_JANINE                      74
#define OBJ_EVENT_GFX_SILVER                     135

// ----- Elite Four (Johto) -----
#define OBJ_EVENT_GFX_WILL                       121
#define OBJ_EVENT_GFX_KAREN                      124

// ----- Team Rocket Executives -----
// TODO(Phase 5+): port real Team Rocket sprites; placeholder pe-Hoenn villain
// sprites (MAGMA_MEMBER_M/F, ARCHIE, MAXIE) render until then.
#define OBJ_EVENT_GFX_PETREL                     119
#define OBJ_EVENT_GFX_ARIANA                     120
#define OBJ_EVENT_GFX_PROTON                     195
#define OBJ_EVENT_GFX_ARCHER                     196

// ----- Story NPCs -----
// TODO(Phase 5+): port PROF_ELM, KURT, EUSINE, KIMONO_GIRL, SAGE sprites.
#define OBJ_EVENT_GFX_PROF_ELM                    64
#define OBJ_EVENT_GFX_SAGE                        68
#define OBJ_EVENT_GFX_KURT                        85
#define OBJ_EVENT_GFX_KIMONO_GIRL                116
#define OBJ_EVENT_GFX_EUSINE                     190

// ----- Trainer Class Sprites -----
// TODO(Phase 5+): port BURGLAR, FIREBREATHER, JUGGLER, ENGINEER, SCIENTIST_F,
// NURSE_CHANSEY, ATTENDANT (both variants) sprites; placeholder pe-Hoenn
// trainer-class sprites render until then.
#define OBJ_EVENT_GFX_ATTENDANT_M                 25
#define OBJ_EVENT_GFX_ATTENDANT                   30
#define OBJ_EVENT_GFX_SCIENTIST_M                 46
#define OBJ_EVENT_GFX_ENGINEER                    53
#define OBJ_EVENT_GFX_BURGLAR                     54
#define OBJ_EVENT_GFX_FIREBREATHER                67
#define OBJ_EVENT_GFX_UNUSED_WOMAN_4              99
#define OBJ_EVENT_GFX_JUGGLER                    110
#define OBJ_EVENT_GFX_SCIENTIST_F                115
#define OBJ_EVENT_GFX_NURSE_CHANSEY              225

// ----- Special Sprites (events, vehicles, set-pieces) -----
// TODO(Phase 5+): port HnS-authored graphics for the Red Gyarados encounter
// (SHINY_GYARADOS), the Snorlax blockade (BIG_SNORLAX), the Burned Tower
// silhouette (LEGENDARY_SHADOW), the Slowpoke Well event (SLOWPOKE_NO_TAIL),
// the Magnet Train (TRAIN_BACK/FRONT), and the HM Whirlpool field object.
#define OBJ_EVENT_GFX_SHINY_GYARADOS              76
#define OBJ_EVENT_GFX_LEGENDARY_SHADOW           141
#define OBJ_EVENT_GFX_BIG_SNORLAX                177
#define OBJ_EVENT_GFX_TRAIN_FRONT                114
#define OBJ_EVENT_GFX_TRAIN_BACK                 202
#define OBJ_EVENT_GFX_WHIRLPOOL                  203
#define OBJ_EVENT_GFX_SLOWPOKE_NO_TAIL           211

#endif // GUARD_CONSTANTS_EVENT_OBJECTS_HNS_H
