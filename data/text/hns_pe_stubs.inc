@ Phase 4 R6c (HMS Plymouth, 2026-05-20): text-label stubs for the residual
@ undefined-reference cluster from the rc-main link pass.
@
@ Each label is a `gText_*` / `gBirchDexRatingText_*` / `MoveTutor_Text_*` /
@ `Route123_*_Text_*` symbol referenced by an HnS-imported .inc msgbox/message
@ call but missing from pe (either Phase-2-stripped or HnS-engine-name only).
@ Stub strings are minimal placeholder text - all call sites are either
@ unreachable in HnS Johto play, or land on flows where the placeholder is
@ acceptable until proper Crystal-flavor copy is authored.
@
@ All labels use `::` (global visibility) so they resolve link-time refs from
@ both .inc and .c consumers.

@ ===== Birch dex-rating extension texts =====
@ Referenced from data/scripts/prof_birch.inc:61,66 (HnS-side dex-rating gate
@ added when VAR_NEWBARKTOWN_LABSTATE == 3 or 4). Pe's pokedex_rating.inc
@ doesn't ship these.

gBirchDexRatingText_GoFindMrPokemon::
	.string "Go find MR. POKéMON.$"

gBirchDexRatingText_Robbery::
	.string "Investigate the lab incident.$"

@ ===== Standard PC / item / box text =====
@ Referenced from data/scripts/obtain_item.inc, pc_transfer.inc,
@ pkmn_center_nurse.inc, MauvilleCity_GameCorner/scripts.inc.

gText_PutItemInPC::
	.string "Put away the item in your PC?$"

gText_TooBadBagAndPCAreFull::
	.string "Too bad! Your BAG and PC are full.$"

gText_YouAlreadyHaveThis::
	.string "You already have this.$"

gText_PkmnTransferredBillsPC::
	.string "POKéMON was transferred to BILL's PC.$"

gText_PkmnTransferredBillsPCBoxFull::
	.string "POKéMON transferred. BOX is now full.$"

@ ===== Pkmn-center challenge counter (tx_challenges integration) =====
@ Referenced from pkmn_center_nurse.inc - HnS doesn't surface visit-count
@ challenges in-game, but the message branch exists in the script.

gText_PkmnCenterChallenge_NoVisitsLeft::
	.string "You have no visits left.$"

@ ===== Route 123 berry-master mulch-reward text =====
@ Referenced from Route123_BerryMastersHouse/scripts.inc:27. The map itself
@ is pe-Hoenn Route 123 - unreachable in HnS Johto/Kanto play.

Route123_BerryMastersHouse_Text_YoureDeservingOfMulch::
	.string "You're deserving of MULCH.$"

@ ===== MoveTutor extension text =====
@ Referenced from data/scripts/move_tutors.inc:453 - adjacent to existing
@ MoveTutor_Text_ThisMoveCanOnlyBeLearnedOnce. HnS adds a "Finite" variant
@ for once-only tutors with a finite use counter.

MoveTutor_Text_ThisMoveCanOnlyBeLearnedOnceFinite::
	.string "This move can only be learned once.$"
