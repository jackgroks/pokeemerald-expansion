# pokeemerald-expansion (engine submodule)

This `CLAUDE.md` is the engine-fork CLAUDE.md for `pokeemerald-expansion`
as embedded in ReinforcedCrystal. The engine itself is a fork of
`rh-hideout/pokeemerald-expansion` tracked at
`https://github.com/jackgroks/pokeemerald-expansion`, with RC's accumulated
trunk on the `rc-main` branch.

## Upstream-canonical conventions

For upstream conventions (PR workflow, branching, contribution scope,
maintainer matrix) see `@CONTRIBUTING.md`. Engine-level modifications
committed in this submodule should still follow those conventions because
they may eventually be PR'd upstream.

## Save-state flag discipline (load-bearing)

Pe stores save-state flags in `gSaveBlock1.flags[NUM_FLAG_BYTES]` (see
`include/global.h:1128`). All `FLAG_*` constants are defined as macro
arithmetic over a base offset:

- `TRAINER_FLAGS_START = 0x500` (`include/constants/flags.h:1348`)
- `TRAINER_FLAGS_END = TRAINER_FLAGS_START + MAX_TRAINERS_COUNT - 1`
- `SYSTEM_FLAGS = TRAINER_FLAGS_END + 1` (currently `0x860`)
- All system flags are `(SYSTEM_FLAGS + N)` (e.g.
  `FLAG_SYS_POKEMON_GET = (SYSTEM_FLAGS + 0x0)`).

**Never hardcode flag values as numeric literals (e.g., `0x86X`).** Always
go through `SYSTEM_FLAGS + N` (or the named `FLAG_*` constant) so that
bumping `MAX_TRAINERS_COUNT_EMERALD` shifts every dependent flag offset
correctly without manual auditing.

`NUM_FLAG_BYTES` is derived from `FLAGS_COUNT` via
`ROUND_BITS_TO_BYTES(FLAGS_COUNT)`; saveblock layout depends on it. Bumping
trainer count without bumping `MAX_TRAINERS_COUNT` keeps flag layout stable.

**RC bump history:**

- 2026-05-19 (HMS Defiant, Phase 5-prep R5) — `TRAINERS_COUNT_EMERALD`
  bumped 861 → 864 to accommodate HnS-only trainer slots 861-863.
  `MAX_TRAINERS_COUNT_EMERALD` left at 864 (already sufficient).
  `NUM_FLAG_BYTES` unchanged; saveblock layout unchanged. See
  `include/constants/opponents_hns.h` for the HnS-only constants and the
  Operationalization-I disposition note.

Future upstream merges preserve the RC bump unless RHH bumps higher. If
RHH bumps `MAX_TRAINERS_COUNT_EMERALD`, take the larger of the two values
and re-verify `SYSTEM_FLAGS` arithmetic resolves correctly.

## Non-additive bumps (one-time, documented)

These are deliberate departures from the "additive by default" schema rule
above. Each is documented here so future upstream merges and downstream
audits can reconcile them.

- **2026-05-19 (HMS Decoy, Phase 5-prep R6a) — items.h enum renumber.**
  Extended `FOREACH_HM` in `include/constants/tms_hms.h` with
  `F(WHIRLPOOL)` to give HnS its HM09 (Whirl Islands plot gate). This
  forced inserting `ITEM_HM09 = 690` between `ITEM_HM08 = 689` and the
  existing `ITEM_OVAL_CHARM = 690`, cascading a +1 renumber of all 184
  explicit numeric entries from `ITEM_OVAL_CHARM` through
  `ITEM_GLIMMORANITE` (range 690..873 -> 691..874).
  - **Why accepted:** RC is pre-release, so save-state invalidation from
    renumbered item IDs is moot. The cascade is mechanical and one-time;
    no consumer reads these enum values as numeric literals.
  - **Auto-derived:** `NUM_HIDDEN_MACHINES` resolves to 9 via
    `(0 FOREACH_HM(PLUS_ONE))` in `include/item.h:21`. `gTMHMItemMoveIds`
    in `src/item.c` picks up the new entry via `UNPACK_HM_ITEM_ID`.
  - **Companion files:** `[ITEM_HM_WHIRLPOOL]` data entry added in
    `src/data/items.h` mirroring `[ITEM_HM_DIVE]`. Banner documenting the
    HnS TM/HM disposition lives at `include/constants/items_hns.h`.
  - **Upstream-merge rule:** If RHH ever adds their own HM09 or extends
    `FOREACH_HM`, take theirs and remove RC's `F(WHIRLPOOL)` only if their
    list already contains it; otherwise prepend RC's entry to theirs and
    re-run the renumber pass against any newly-added items that landed
    in the 690+ range.

- **2026-05-19 (HMS Warspite, Phase 5-prep R6d) — SYSTEM_FLAGS region
  extended by 658 slots; DAILY_FLAGS_START rebased.**
  Added `include/constants/flags_hns.h` with 658 HnS-only progression
  flag `#define`s, each `(SYSTEM_FLAGS + 0xC0 + N)` for N in 0..657 (slot
  range `(SYSTEM_FLAGS + 0xC0)..(SYSTEM_FLAGS + 0x351)`). `flags.h` now
  `#include`s `flags_hns.h` after the vanilla SYSTEM_FLAGS block and
  before the `DAILY_FLAGS_START` declaration. `DAILY_FLAGS_START` was
  rebased from `(FLAG_UNUSED_0x91F + (8 - FLAG_UNUSED_0x91F % 8))`
  (= `SYSTEM_FLAGS + 0xC0`) to
  `(FLAG_HNS_LAST_SLOT + (8 - FLAG_HNS_LAST_SLOT % 8))`
  (= `SYSTEM_FLAGS + 0x358`).
  - **Auto-derived bumps:** `DAILY_FLAGS_END`, `NUM_DAILY_FLAGS`,
    `FLAGS_COUNT`, and `NUM_FLAG_BYTES` all recompute via their existing
    arithmetic chains. `NUM_FLAG_BYTES` grows from 300 to 415 (+115
    bytes); `SaveBlock1.flags[]` array auto-resizes; `SaveBlock1` grows
    by 115 bytes total. Compile-time asserts at `src/save.c:80-83`
    confirm `sizeof(struct SaveBlock1)` stays within
    `SECTOR_DATA_SIZE * 4 = 15872` bytes (verified passing post-R6d).
  - **Why this is non-additive:** the `DAILY_FLAGS_START` definition
    itself changed (from `FLAG_UNUSED_0x91F`-based to
    `FLAG_HNS_LAST_SLOT`-based). All existing `FLAG_DAILY_*` and
    `FLAG_UNUSED_0x9XX` macros that resolve through `DAILY_FLAGS_START`
    shift their absolute byte offset by +83 bytes. No code reads flag
    offsets as numeric literals (verified via grep — all access goes
    through the `flags[id/8]` arithmetic at `src/event_data.c:232`), so
    the shift is safe.
  - **Slot semantics:** HnS's own flag values (e.g., `0x3A3`, `0x4F4`,
    `(SYSTEM_FLAGS + 0x85)`) collide with pe's TRAINER_FLAGS range
    (`0x500..0x85F`) and cannot be copied verbatim. All 658 are re-slotted
    onto fresh `(SYSTEM_FLAGS + 0xC0 + N)` slots in alphabetical order
    matching the audit list at
    `../.context/chore/migrate-to-pe-expansion/r6-audit/flag_confirmed_hns.txt`.
    Zero name collisions with pe's existing 1878 `FLAG_*` defines
    (verified by intersection grep before authoring).
  - **Upstream-merge rule:** If RHH later defines any of these 658 names
    (unlikely — they're HnS Johto/Kanto-specific), prefer RHH's slot and
    drop RC's `flags_hns.h` entry for that name. If RHH bumps
    `DAILY_FLAGS_START`'s base computation, re-anchor `FLAG_HNS_LAST_SLOT`
    on the new chain rather than the literal `+ 0x351` offset.

- **2026-05-20 (HMS Defiant, Phase 5-prep R6e-followup) — VARS region
  extended by 66 slots; VARS_END rebased.**
  Added `include/constants/vars_hns.h` with 66 HnS-only progression VAR
  `#define`s, each `(VARS_START + 0x100 + N)` for N in 0..65 (slot range
  `(VARS_START + 0x100)..(VARS_START + 0x141)` = `0x4100..0x4141`). `vars.h`
  now `#include`s `vars_hns.h` after the vanilla VAR block and before the
  `VARS_END` definition. `VARS_END` was rebased from the literal `0x40FF`
  to `HNS_VARS_END` (= `VAR_VIOLET_CITY_STATE` = `(VARS_START + 0x141)`).
  - **Auto-derived bumps:** `VARS_COUNT` recomputes via
    `(VARS_END - VARS_START + 1)` from 256 to 322. `SaveBlock1.vars[]`
    auto-resizes from 512 bytes (256 * 2) to 644 bytes (322 * 2); +132
    bytes total. Compile-time assert at `src/save.c:82` confirms
    `sizeof(struct SaveBlock1)` stays within
    `SECTOR_DATA_SIZE * 4 = 15872` bytes (verified passing post-bump).
  - **Why this is non-additive:** the `VARS_END` definition itself
    changed (from literal `0x40FF` to `HNS_VARS_END`-based). Pe's vanilla
    persistent VAR range was completely full (every slot in
    `0x4000..0x40FF` allocated through `VAR_UNUSED_0x40FF`), so additive
    placement required extending the END marker. No code reads VAR
    offsets as numeric literals (verified via grep — all access goes
    through `VarGet`/`VarSet` at `src/event_data.c`, which indexes into
    `gSaveBlock1Ptr->vars[]` via arithmetic), so the SaveBlock1 byte
    shift downstream of `vars[]` is safe.
  - **Slot semantics:** HnS's own VAR values (also in the `0x4000..0x40FF`
    range) cannot be copied verbatim because every pe slot in that range
    is already taken. All 66 are re-slotted onto fresh
    `(VARS_START + 0x100 + N)` slots in alphabetical order matching the
    audit list. Zero name collisions with pe's existing 360 `VAR_*`
    defines across `vars.h` + `vars_frlg.h` (verified by intersection
    grep before authoring).
  - **Upstream-merge rule:** If RHH later defines any of these 66 names
    (unlikely — they're HnS Johto/Kanto-specific), prefer RHH's slot and
    drop RC's `vars_hns.h` entry for that name. If RHH extends `VARS_END`
    past `0x40FF` themselves, anchor `HNS_VARS_START` on the new
    `VARS_END + 1` rather than the literal `+ 0x100` offset.

- **2026-05-20 (HMS Plymouth, Phase 4 R6c) — VARS region extended by 8
  more slots (66 -> 74); VARS_END re-rebased on VAR_UNUSED_HNS_VAR7.**
  Extension to the original 2026-05-20 (Defiant) bump above. Added 8 HnS
  Kanto-progression VARs (`VAR_CELADON_CITY_STATE`, `VAR_LAVENDER_TOWN_STATE`,
  `VAR_PALLET_TOWN_STATE`, `VAR_VIRIDIAN_CITY_STATE`, plus 4
  `VAR_UNUSED_HNS_VAR{4..7}` placeholder slots) that the original
  Johto-focused vars_hns.h pass missed. Slot range extends from
  `(HNS_VARS_START + 0x42)..(HNS_VARS_START + 0x49)`.
  - **Auto-derived bumps:** `HNS_VARS_END` rebases from `VAR_VIOLET_CITY_STATE`
    (= `HNS_VARS_START + 0x41` = `0x4141`) to `VAR_UNUSED_HNS_VAR7`
    (= `HNS_VARS_START + 0x49` = `0x4149`). `VARS_END` resolves to the new
    `HNS_VARS_END` (no edit in `vars.h` required). `VARS_COUNT` recomputes
    via `(VARS_END - VARS_START + 1)` from 322 to 330. `SaveBlock1.vars[]`
    auto-resizes from 644 to 660 bytes (+16 bytes). The compile-time assert
    at `src/save.c:82` continues to pass (well within the
    `SECTOR_DATA_SIZE * 4 = 15872`-byte budget).
  - **Why this is non-additive (still):** Same reasoning as the original
    Defiant entry — extending `HNS_VARS_END` shifts the SaveBlock1 byte
    layout downstream of `vars[]`. Pre-release, no consumer reads VAR
    offsets as numeric literals.
  - **Upstream-merge rule:** Same as the original Defiant entry; if RHH
    defines any of these 8 names (extremely unlikely — Kanto-specific
    HnS progression), prefer RHH's slot.

- **2026-05-20 (HMS Plymouth, Phase 4 R6c) — TRAINERS_COUNT_EMERALD bumped
  864 -> 866; MAX_TRAINERS_COUNT_EMERALD bumped 864 -> 866.**
  Added 3 HnS trainer slots (`TRAINER_KIP` = 863, `TRAINER_KIP2` = 864,
  `TRAINER_STEVEN2` = 865) referenced from
  `data/maps/EverGrandeCity_DrakesRoom/scripts.inc` (HnS E4-rematch path)
  and `data/maps/MeteorFalls_StevensCave/scripts.inc` (Steven-rematch).
  - **Auto-derived:** Trainer flag range `TRAINER_FLAGS_START` ..
    `TRAINER_FLAGS_END` (= `TRAINER_FLAGS_START + MAX_TRAINERS_COUNT - 1`)
    grows by 2 slots. `SYSTEM_FLAGS` (= `TRAINER_FLAGS_END + 1`) shifts
    by +2 bits (~0 bytes since well within an existing byte). No
    `NUM_FLAG_BYTES` change observed.
  - **Why accepted:** RC pre-release; trainerproc emits initializers
    keyed by these HnS slot names — without the `#define`s, trainers.h
    fails to compile.
  - **Upstream-merge rule:** Same as the 2026-05-19 (Defiant) bump.

## Phase 4 R6c additive stubs (HMS Plymouth, 2026-05-20)

Phase 4 R6c is the final-stretch mop-up captain round before Phase 5 mGBA
smoke. It cleared a residual 56-symbol undef-ref cluster across mixed
families with the lightest-touch stubs that resolve link-time refs:

- **`src/mirage_tower.c` extended** with 6 additional `void X(void) { }`
  script-callable specials (DoMirageTowerCeilingCrumble,
  SetMirageTowerVisibility, StartMirageTowerDisintegration,
  StartMirageTowerFossilFallAndSink, StartMirageTowerShake,
  StartPlayerDescendMirageTower). Same Phase 2 minimal-strip stub pattern
  as the pre-existing 3 stubs. Surface is pe-Hoenn-unreachable in HnS play.
- **`src/faraway_island.c` extended** with 2 additional `void X(void) { }`
  specials (SetMewAboveGrass, DestroyMewEmergingGrassSprite). Same pattern.
- **`src/hns_pe_stubs.c` (NEW)** holds 5 `callnative`-flavor C stubs
  (`void X(struct ScriptContext *)`) for Berry_Ready, Task_ChallengeViewer,
  GetObjectEventTrainerRangeFromTemplate, ItemId_GetHoldEffectParam_Script,
  SetTimeBasedEncounters. All are no-ops; call sites are either Phase-2-
  deferred (BattleFrontier, tx_challenges) or HnS-rerouted (berry trees
  via apricorn_tree.inc, repels, time-based encounter swaps).
- **`data/scripts/hns_pe_stubs.inc` (NEW)** holds 14 script-label stubs
  for Std_/EventScript_/Common_EventScript_/MoveTutor_/Debug_Script_1_
  labels referenced by HnS-imported map scripts and the
  `event_scripts.s` stdscripts table. Each stub is a minimal `end` or
  `return` (or `closemessage; end` for Debug_Script_1_Closemessage).
- **`data/text/hns_pe_stubs.inc` (NEW)** holds 9 `.string`-flavor text
  stubs for gText_*, gBirchDexRatingText_*, MoveTutor_Text_*, and
  Route123_*_Text_* labels referenced by HnS-imported scripts. All use
  `::` global visibility.
- **`data/text/braille.inc` extended** with 3 empty-braille stubs for
  Regidrago_Braille_Text, Regieleki_Braille_Sapphire,
  Regigigas_Braille_Text. Map sites (AquaHideout_UnusedRubyMap1/2,
  GraniteCave_B2F) are pe-Hoenn-unused in HnS play.
- **`include/constants/metatile_hns.h` (NEW)** stubs
  METATILE_R26_21_Broken_Window to 0 (METATILE_NONE-equivalent). Wired
  into the metatile namespace by `#include` from
  `include/constants/metatile_labels.h` after the vanilla METATILE_RS*
  block. Single-site reference at
  `data/maps/NewBarkTown_Lab/scripts.inc:381`.
- **`include/constants/pe_hoenn_strip_stubs.h` extended** with 2 more
  LOCALID stubs (LOCALID_RUSTURF_TUNNEL_WANDA,
  LOCALID_RUSTURF_TUNNEL_WANDAS_BF) - missed in the original strip.
  Same `0` stub pattern as the existing block.
- **Wire-up edits:** `data/event_scripts.s` extended with two
  `.include` lines (the new hns_pe_stubs .incs). `include/constants/metatile_labels.h`
  extended with `#include "constants/metatile_hns.h"`. `include/constants/opponents.h`
  TRAINERS_COUNT_EMERALD + MAX_TRAINERS_COUNT_EMERALD bumped to 866.

The 12 remaining BattleFrontier_* undef refs are intentionally deferred to
a Phase 2 facility-cleanup feature; they have engine-side entanglement
(saveblock fields, tutoring tables) that requires a proper port rather
than a stub.

## Additive renames (HnS-engine-name → pe-native infrastructure)

These are *not* non-additive (no slot bumps, no schema growth, no value
changes) but are documented here because future upstream merges need to know
the alias exists, and downstream auditors should not confuse them for
stub-aliases.

- **2026-05-19 (HMS Druid, Phase 5-prep R6c) — `OBJ_EVENT_GFX_MON_BASE`
  aliased to pe's `OBJ_EVENT_MON`.**
  Pe-expansion ships RHH's follower-pokemon feature, which encodes "this
  object event is a species sprite" by ORing bit-14 (`OBJ_EVENT_MON = (1u
  << 14)`) into `graphicsId`. HnS uses the same scheme under a different
  constant name (`OBJ_EVENT_GFX_MON_BASE = 0x200` plus an 11-bit mask).
  Aliasing in `include/constants/event_objects_hns.h`:
  ```
  #define OBJ_EVENT_GFX_MON_BASE  OBJ_EVENT_MON
  ```
  makes 2782 HnS-imported `OBJ_EVENT_GFX_MON_BASE+SPECIES_X` references
  resolve to pe's native `OBJ_EVENT_GFX_SPECIES(X)` form. Pe already
  implements the full dispatch (`SpeciesToGraphicsInfo` at
  `src/event_object_movement.c:3218-3219`), the masks
  (`OBJ_EVENT_MON_SPECIES_MASK`), the consumer macros (`IS_OW_MON_OBJ`,
  `OW_SPECIES`, `OW_SHINY`, `OW_FEMALE`), and all downstream call sites.
  No engine code added; no graphics-info table edits; no slot bumps.
  - **Companion data patch:** HnS's `+SPECIES_SHINY_TAG` shiny encoding
    (additive offset) does not match pe's bit-13-shiny scheme. The one
    affected site (`data/maps/Route20/map.json`, Dennis's Red Gyarados /
    shiny Magikarp) is rewritten to `OBJ_EVENT_GFX_SPECIES_SHINY(MAGIKARP)`.
  - **Upstream-merge rule:** If RHH ever defines `OBJ_EVENT_GFX_MON_BASE`
    upstream (unlikely — the upstream name is `OBJ_EVENT_MON`), drop RC's
    alias. If the bit-14 / bit-13 / bit-12 scheme in `event_objects.h`
    changes value (extremely unlikely without a save-data bump), re-verify
    the alias still resolves to a flag bit and not a bare integer.

## Schema discipline

Per `@~/.claude/rules/schema-discipline.md`, schema changes are additive by
default. RC additions to engine-owned schemas (e.g., new `TRAINER_*` slots,
new `FLAG_*` constants, new `VAR_*` constants, new `MUS_*` aliases) live
adjacent to the producer and append to existing enums/blocks rather than
re-numbering them. Non-additive changes (slot renumbering, type widening of
fields used by save data) require an audit pass against consumers before
landing.

## Branching model

Per `@../.context/reference/romhack-conventions.md`:

- `master` — pristine upstream mirror; fast-forward only.
- `rc-main` — RC's accumulated trunk; receives `--no-ff` merges from
  feature branches.
- `feat/<name>` — feature branches off `rc-main`, merged back on
  completion.

Outer-repo submodule pointer is bumped to track `rc-main` after merges
land. Per the established "no-asymmetry" pattern, the outer pointer bump
should be a single commit at the end of a submodule branch's work, not
interleaved with outer non-pointer commits.

## Migration-era notes

ReinforcedCrystal is in the middle of a migration arc
(`chore/migrate-to-pe-expansion`) that ports HnS Johto/Kanto content onto
this engine. T-tools at `../tools/migration/` are the canonical mechanism;
hand-patches are reserved for one-off surfaces. Migration handoff lives at
`../.context/chore/migrate-to-pe-expansion/HANDOFF.md`.

The build mutates `src/data/heal_locations.json` during codegen. Before
staging any submodule commit:
`git checkout src/data/heal_locations.json`.
