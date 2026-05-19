ShoalCave_LowTideStairsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ShoalCave_LowTideStairsRoom_OnLoad
	.byte 0

ShoalCave_LowTideStairsRoom_OnLoad:
	call ShoalCave_LowTideStairsRoom_EventScript_SetShoalItemMetatiles
	end

ShoalCave_LowTideStairsRoom_EventScript_SetShoalItemMetatiles::
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	goto_if_set FLAG_GARBAGEFLAG, ShoalCave_LowTideStairsRoom_EventScript_SetShoalItemMetatilesEnd
	setmetatile 11, 11, METATILE_Cave_ShoalCave_DirtPile_Large, TRUE
	return

ShoalCave_LowTideStairsRoom_EventScript_SetShoalItemMetatilesEnd::
	return

ShoalCave_LowTideStairsRoom_EventScript_ShoalSalt3::
	lockall
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	goto_if_set FLAG_GARBAGEFLAG, ShoalCave_LowTideStairsRoom_EventScript_ReceivedShoalSalt
	giveitem ITEM_SHOAL_SALT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setmetatile 11, 11, METATILE_Cave_ShoalCave_DirtPile_Small, FALSE
	special DrawWholeMapView
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	setflag FLAG_GARBAGEFLAG
	releaseall
	end

ShoalCave_LowTideStairsRoom_EventScript_ReceivedShoalSalt::
	msgbox ShoalCave_Text_WasShoalSaltNowNothing, MSGBOX_DEFAULT
	releaseall
	end

