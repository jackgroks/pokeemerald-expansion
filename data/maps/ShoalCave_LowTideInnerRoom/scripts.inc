ShoalCave_LowTideInnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ShoalCave_LowTideInnerRoom_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, ShoalCave_LowTideInnerRoom_OnTransition
	.byte 0

ShoalCave_LowTideInnerRoom_OnTransition:
	// TODO(pe-migration): missing in pe-expansion -- FLAG_SYS_LAKE_OF_RAGE_TIDE (flags) -- port engine surface
	goto_if_set FLAG_SYS_LAKE_OF_RAGE_TIDE, ShoalCave_LowTideInnerRoom_EventScript_SetHighTide
	goto ShoalCave_LowTideInnerRoom_EventScript_SetLowTide

ShoalCave_LowTideInnerRoom_EventScript_SetHighTide::
	setmaplayoutindex LAYOUT_SHOAL_CAVE_HIGH_TIDE_INNER_ROOM
	end

ShoalCave_LowTideInnerRoom_EventScript_SetLowTide::
	setmaplayoutindex LAYOUT_SHOAL_CAVE_LOW_TIDE_INNER_ROOM
	end

ShoalCave_LowTideInnerRoom_OnLoad:
	call ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles
	end

ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles::
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	goto_if_set FLAG_GARBAGEFLAG, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles2
	// TODO(pe-migration): missing in pe-expansion -- FLAG_SYS_LAKE_OF_RAGE_TIDE (flags) -- port engine surface
	goto_if_set FLAG_SYS_LAKE_OF_RAGE_TIDE, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles2
	setmetatile 31, 8, METATILE_Cave_ShoalCave_DirtPile_Large, TRUE
	goto ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles2
	end

ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles2::
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	goto_if_set FLAG_GARBAGEFLAG, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles3
	// TODO(pe-migration): missing in pe-expansion -- FLAG_SYS_LAKE_OF_RAGE_TIDE (flags) -- port engine surface
	goto_if_set FLAG_SYS_LAKE_OF_RAGE_TIDE, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles3
	setmetatile 14, 26, METATILE_Cave_ShoalCave_DirtPile_Large, TRUE
	goto ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles3
	end

ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles3::
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	goto_if_set FLAG_GARBAGEFLAG, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles4
	setmetatile 41, 20, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
	goto ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles4
	end

ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles4::
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	goto_if_set FLAG_GARBAGEFLAG, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles5
	setmetatile 41, 10, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
	goto ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles5
	end

ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles5::
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	goto_if_set FLAG_GARBAGEFLAG, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles6
	setmetatile 6, 9, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
	goto ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles6
	end

ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatiles6::
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	goto_if_set FLAG_GARBAGEFLAG, ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatilesEnd
	setmetatile 16, 13, METATILE_Cave_ShoalCave_BlueStone_Large, TRUE
	return

ShoalCave_LowTideInnerRoom_EventScript_SetShoalItemMetatilesEnd::
	return

ShoalCave_LowTideInnerRoom_EventScript_ShoalShell1::
	lockall
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	goto_if_set FLAG_GARBAGEFLAG, ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalShell
	giveitem ITEM_SHOAL_SHELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setmetatile 41, 20, METATILE_Cave_ShoalCave_BlueStone_Small, FALSE
	special DrawWholeMapView
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	setflag FLAG_GARBAGEFLAG
	releaseall
	end

ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalShell::
	msgbox ShoalCave_Text_WasShoallShellNowNothing, MSGBOX_DEFAULT
	releaseall
	end

ShoalCave_LowTideInnerRoom_EventScript_ShoalShell2::
	lockall
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	goto_if_set FLAG_GARBAGEFLAG, ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalShell
	giveitem ITEM_SHOAL_SHELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setmetatile 41, 10, METATILE_Cave_ShoalCave_BlueStone_Small, FALSE
	special DrawWholeMapView
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	setflag FLAG_GARBAGEFLAG
	releaseall
	end

ShoalCave_LowTideInnerRoom_EventScript_ShoalShell3::
	lockall
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	goto_if_set FLAG_GARBAGEFLAG, ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalShell
	giveitem ITEM_SHOAL_SHELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setmetatile 6, 9, METATILE_Cave_ShoalCave_BlueStone_Small, FALSE
	special DrawWholeMapView
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	setflag FLAG_GARBAGEFLAG
	releaseall
	end

ShoalCave_LowTideInnerRoom_EventScript_ShoalShell4::
	lockall
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	goto_if_set FLAG_GARBAGEFLAG, ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalShell
	giveitem ITEM_SHOAL_SHELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setmetatile 16, 13, METATILE_Cave_ShoalCave_BlueStone_Small, FALSE
	special DrawWholeMapView
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	setflag FLAG_GARBAGEFLAG
	releaseall
	end

ShoalCave_LowTideInnerRoom_EventScript_ShoalSalt1::
	lockall
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	goto_if_set FLAG_GARBAGEFLAG, ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalSalt
	giveitem ITEM_SHOAL_SALT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setmetatile 31, 8, METATILE_Cave_ShoalCave_DirtPile_Small, FALSE
	special DrawWholeMapView
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	setflag FLAG_GARBAGEFLAG
	releaseall
	end

ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalSalt::
	msgbox ShoalCave_Text_WasShoalSaltNowNothing, MSGBOX_DEFAULT
	releaseall
	end

ShoalCave_LowTideInnerRoom_EventScript_ShoalSalt2::
	lockall
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	goto_if_set FLAG_GARBAGEFLAG, ShoalCave_LowTideInnerRoom_EventScript_ReceivedShoalSalt
	giveitem ITEM_SHOAL_SALT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setmetatile 14, 26, METATILE_Cave_ShoalCave_DirtPile_Small, FALSE
	special DrawWholeMapView
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	setflag FLAG_GARBAGEFLAG
	releaseall
	end
