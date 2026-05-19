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
