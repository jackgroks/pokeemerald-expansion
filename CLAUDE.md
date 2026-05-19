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
