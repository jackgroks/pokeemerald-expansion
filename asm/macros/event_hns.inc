@ ===================================================================
@ event_hns.inc — HnS-imported script macros additive to pe-expansion
@
@ Phase 4 stub-aliases (Round 1, 2026-05-20). HnS scripts reference
@ macro names that don't exist in pe-expansion's event.inc. Each macro
@ here either (a) aliases an HnS name to pe's existing equivalent
@ (semantically lossy where engine opcodes differ; documented inline),
@ or (b) emits the same bytes pe would emit for the closest analogue.
@
@ Tracking: queued for proper Phase 4 engine ports — each entry below
@ notes the upstream proper-fix. Until ported, these compile-stubs let
@ HnS-imported scripts assemble at the cost of minor runtime behavior
@ delta. None block Phase 5 mGBA smoke (Falkner playthrough).
@
@ Include site: appended at bottom of asm/macros/event.inc.
@ ===================================================================

@ HnS's applymovement2: "applymovement but doesnt remove follower".
@ HnS emits opcode 0xe8 (no-arg-without-map) or 0x50 (with map).
@ Pe lacks the 0xe8 opcode entirely. Alias to pe's applymovement
@ (opcode SCR_OP_APPLYMOVEMENT for no-map / SCR_OP_APPLYMOVEMENTAT for
@ with-map). Cosmetic delta only: in HnS-script-original behavior the
@ player's follower remains visible during the cutscene; under pe's
@ runtime the follower is briefly hidden. Proper fix queued: port
@ HnS's 0xe8 opcode handler into pe's script_cmd_table.
	.macro applymovement2 localId:req, movements:req, map
		applymovement \localId, \movements, \map
	.endm

@ HnS opcodes 0xee/0xef/0xf0: byte-passthrough stubs.
@ Pe lacks the runtime handlers; scripts that execute these will see
@ undefined behavior. None are on Phase 5 (Falkner) critical path.
@ Proper fix queued: add the HnS opcode handlers to pe's script_cmd_table:
@   0xee baobacheckmon  — Safari Zone Baoba contest check
@   0xef giveoddegg     — Day Care Odd Egg variant
@   0xf0 givebp         — Battle Points reward
@   0xf4 checknuzlocke  — randomizer / nuzlocke runtime flag
@   0xf5 checkrandomizer — randomizer runtime flag

	.macro baobacheckmon number:req
		.byte 0xee
		.2byte \number
	.endm

	.macro giveoddegg number:req
		.byte 0xef
		.2byte \number
	.endm

	.macro givebp number:req
		.byte 0xf0
		.2byte \number
	.endm

	.macro checknuzlocke
		.byte 0xf4
		.byte 0xf4
	.endm

	.macro checkrandomizer
		.byte 0xf5
		.byte 0xf5
	.endm
