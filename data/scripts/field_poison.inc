EventScript_FieldPoison::
	lockall
	special TryFieldPoisonWhiteOut
	waitstate
	goto_if_eq VAR_RESULT, FLDPSN_WHITEOUT, EventScript_FieldWhiteOut
	goto_if_eq VAR_RESULT, FLDPSN_FRONTIER_WHITEOUT, EventScript_FrontierFieldWhiteOut
	releaseall
	end

EventScript_FieldWhiteOut::
	// TODO(pe-migration): missing in pe-expansion -- FLAG_SYS_BUG_CONTEST_MODE (flags) -- port engine surface
	goto_if_set FLAG_SYS_BUG_CONTEST_MODE, BugContest_EventScript_WhiteOut
	message gText_PlayerWhitedOut
	waitmessage
	waitbuttonpress
	special Script_FadeOutMapMusic
	waitstate
	fadescreen FADE_TO_BLACK
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, EventScript_SetRespawnLavaridgePkmnCenter
	special SetCB2WhiteOut
	waitstate
	end

EventScript_SetRespawnLavaridgePkmnCenter::
	setrespawn HEAL_LOCATION_LAVARIDGE_TOWN
	return

EventScript_FrontierFieldWhiteOut::
	message gText_PlayerWhitedOut
	waitmessage
	waitbuttonpress
	pike_inchallenge
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePike_EventScript_Retire
	setvar VAR_RESULT, 0 @ TODO: revisit later — no pe equivalent identified. HnS-only "pyramid_inchallenge"; never in Battle Pyramid under HnS Johto, so neither pyramid retire branch fires.
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost  @ On Pyramid floor
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost  @ On Pyramid peak
	trainerhill_inchallenge
	goto_if_eq VAR_RESULT, TRUE, TrainerHill_1F_EventScript_Lost
	special Script_FadeOutMapMusic
	waitstate
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate
	end
