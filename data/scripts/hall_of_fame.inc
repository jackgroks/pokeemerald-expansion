EverGrandeCity_HallOfFame_EventScript_SetGameClearFlags::
	special SetChampionSaveWarp
	setflag FLAG_IS_CHAMPION
	call EverGrandeCity_HallOfFame_EventScript_ResetDefeatedEventLegendaries
	call_if_eq VAR_FOSSIL_MANIAC_STATE, 0, EverGrandeCity_HallOfFame_EventScript_SetDesertUnderpassCommentReady
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	clearflag FLAG_GARBAGEFLAG
	call EverGrandeCity_HallOfFame_EventScript_ResetEliteFour
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	setflag FLAG_GARBAGEFLAG
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_INVISIBLE_NINJA_BOY
	setvar VAR_STEVENS_HOUSE_STATE, 2
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	setflag FLAG_GARBAGEFLAG
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	clearflag FLAG_GARBAGEFLAG
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	clearflag FLAG_GARBAGEFLAG
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_HIDE_SAFARI_ZONE_SOUTH_CONSTRUCTION_WORKERS
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	clearflag FLAG_GARBAGEFLAG
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	setflag FLAG_GARBAGEFLAG
	special UpdateTrainerFanClubGameClear
	call_if_unset FLAG_RECEIVED_SS_TICKET, EverGrandeCity_HallOfFame_EventScript_ReadyReceiveSSTicketEvent
	call_if_unset FLAG_RECEIVED_BELDUM, EverGrandeCity_HallOfFame_EventScript_ShowStevensHouseBeldum
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	call_if_eq VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0, EverGrandeCity_HallOfFame_EventScript_ReadyDexUpgradeEvent
	return

EverGrandeCity_HallOfFame_EventScript_ResetDefeatedEventLegendaries::
	clearflag FLAG_DEFEATED_MEW
	clearflag FLAG_DEFEATED_LATIAS_OR_LATIOS
	clearflag FLAG_DEFEATED_DEOXYS
	clearflag FLAG_DEFEATED_LUGIA
	clearflag FLAG_DEFEATED_HO_OH
	return

EverGrandeCity_HallOfFame_EventScript_SetDesertUnderpassCommentReady::
	setvar VAR_FOSSIL_MANIAC_STATE, 1
	return

EverGrandeCity_HallOfFame_EventScript_ShowStevensHouseBeldum::
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	clearflag FLAG_GARBAGEFLAG
	return

EverGrandeCity_HallOfFame_EventScript_ReadyReceiveSSTicketEvent::
	// TODO(pe-migration): missing in pe-expansion -- VAR_GARBAGEVAR (vars) -- port engine surface
	setvar VAR_GARBAGEVAR, 3
	// TODO(pe-migration): missing in pe-expansion -- VAR_GARBAGEVAR (vars) -- port engine surface
	setvar VAR_GARBAGEVAR, 3
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	clearflag FLAG_GARBAGEFLAG
	return

EverGrandeCity_HallOfFame_EventScript_ReadyDexUpgradeEvent::
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1
	return
