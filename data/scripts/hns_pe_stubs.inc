@ Phase 4 R6c (HMS Plymouth, 2026-05-20): script-label stubs for the residual
@ undefined-reference cluster from the rc-main link pass.
@
@ Two flavors of stub live here:
@   1. SCRIPT LABEL STUBS - empty bytecode arrays (just `end`/`return`) for
@      label symbols that pe-expansion references from data/event_scripts.s
@      stdscripts/specials tables or from .inc msgbox/call/case sites, but
@      doesn't define anywhere. These resolve link-time undef-refs without
@      altering runtime behavior because the call sites are either Battle
@      Frontier (unreachable in HnS Johto play per Phase 2 deferral) or
@      HM-use/PC-transfer/gift-mon flows that HnS reimplements through its
@      own scripts.
@   2. MoveTutor_AfterChooseBoxMon - declared `extern const u8 X[]` in
@      include/event_scripts.h:694 and referenced from src/chooseboxmon.c:49
@      (SELECT_PC_MON_MOVE_TUTOR dispatch entry). pe upstream defines this
@      somewhere we don't have - probably stripped in an earlier Phase 2 pass.
@
@ Pattern matches pe's idiomatic empty-event-script stubs (e.g., places where
@ `end` alone is a complete script that just terminates and releases control).

@ ===== HM/field-move scripts (call sites in field_move_scripts / berry_tree) =====

EventScript_UseCutGrass::
	end

EventScript_UseDig::
	end

EventScript_UseDefog::
	end

EventScript_UseRockClimb::
	end

EventScript_SprayWoreOff::
	end

@ ===== PC / box-link / item flows =====

EventScript_AccessPokemonBoxLink::
	end

EventScript_CurrentTooFast::
	end

EventScript_ObjectApproachPlayer::
	end

@ ===== Standard script table entries (event_scripts.s stdscripts) =====

Std_PutItemAway::
	end

Std_ReceivedItem::
	end

@ ===== Common gift-mon scripts (called from many HnS Johto/Kanto maps) =====
@ NOTE: HnS-side gift-mon ceremony scripts call these as a tail-end "release"
@ stub. Empty `return` is functionally a no-op which is the intended behavior
@ when HnS's own givemon/setflag/msgbox sequence has already completed.

Common_EventScript_GiftMon::
	return

Common_EventScript_GiftMonNamed::
	return

@ ===== Berry-tree callnative target =====
@ Berry_Ready is referenced via `callnative Berry_Ready` from data/scripts/berry_tree.inc.
@ pe-expansion upstream implements this as a C function (callnative dispatches to
@ a void(struct ScriptContext *) signature). The C-side stub lives in
@ src/hns_pe_stubs.c; this label is intentionally not redefined here.

@ ===== BattleFrontier PokemonCenter case dispatch target =====
@ Debug_Script_1_Closemessage is referenced from BattleFrontier_PokemonCenter_1F/scripts.inc
@ as a `case NO,` / `case MULTI_B_PRESSED,` jump destination. The BattleFrontier surface
@ is intentionally deferred to Phase 2 facility cleanup; this stub just terminates the
@ script branch cleanly so the asm pass resolves.

Debug_Script_1_Closemessage::
	closemessage
	end

@ ===== MoveTutor box-mon dispatch =====
@ extern declared in include/event_scripts.h:694 as `const u8 X[]`.
@ Used by src/chooseboxmon.c SELECT_PC_MON_MOVE_TUTOR slot as the post-selection
@ continuation script. HnS doesn't use the box-mon move-tutor flow (it uses Crystal-
@ style direct overworld move tutors instead), so an empty script that just terminates
@ is the appropriate stub.

MoveTutor_AfterChooseBoxMon::
	end
