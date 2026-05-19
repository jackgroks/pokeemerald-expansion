.set LOCALID_SSAQUA_1F_DOORSAILOR, 4
.set LOCALID_SSAQUA_1F_GRANDPA, 2

SSAqua_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SSAqua_1F_OnFrame
	.byte 0

SSAqua_1F_OnFrame::
	// TODO(pe-migration): missing in pe-expansion -- VAR_SSAQUA_STATE (vars) -- port engine surface
	map_script_2 VAR_SSAQUA_STATE, 5, SSAqua_1F_EventScript_Arrived
	.2byte 0

SSAqua_1F_EventScript_Arrived::
	lock
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 10  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	playse SE_DING_DONG
	msgbox SSAqua_1F_Text_Sailor1_InVermilion, MSGBOX_DEFAULT
	closemessage
	// TODO(pe-migration): missing in pe-expansion -- VAR_SSAQUA_STATE (vars) -- port engine surface
	setvar VAR_SSAQUA_STATE, 6
	release
	end

SSAqua_1F_EventScript_DoorSailor::
	lock
	faceplayer
	// TODO(pe-migration): missing in pe-expansion -- VAR_SSAQUA_STATE (vars) -- port engine surface
	goto_if_ge VAR_SSAQUA_STATE, 5, SSAqua_1F_EventScript_DoorSailorArrived
	msgbox SSAqua_1F_Text_Sailor1_ToVermilion, MSGBOX_NPC
	end

SSAqua_1F_EventScript_DoorSailorArrived::
	msgbox SSAqua_1F_Text_SailorDoorArrived, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, SSAqua_1F_EventScript_LeaveBoat
	closemessage
	release
	end

SSAqua_1F_EventScript_LeaveBoat::
	fadescreenswapbuffers FADE_TO_BLACK

	@Kanto FLAGHEAP
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_COPYCAT_CLEFAIRY_DOLL (flags) -- port engine surface
	setflag FLAG_HIDE_COPYCAT_CLEFAIRY_DOLL
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_CERULEAN_GYM_TRAINERS (flags) -- port engine surface
	setflag FLAG_HIDE_CERULEAN_GYM_TRAINERS
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_CERULEAN_CAPE_ROCKET (flags) -- port engine surface
	setflag FLAG_HIDE_CERULEAN_CAPE_ROCKET
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_CERULEAN_GYM_ROCKET (flags) -- port engine surface
	setflag FLAG_HIDE_CERULEAN_GYM_ROCKET
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDDEN_ITEM_MACHINE_PART (flags) -- port engine surface
	setflag FLAG_HIDDEN_ITEM_MACHINE_PART
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_ROUTE25_MISTY (flags) -- port engine surface
	setflag FLAG_HIDE_ROUTE25_MISTY
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_ROUTE25_EUSINE (flags) -- port engine surface
	setflag FLAG_HIDE_ROUTE25_EUSINE
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_ROUTE25_SUICUNE (flags) -- port engine surface
	setflag FLAG_HIDE_ROUTE25_SUICUNE
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_CELADON_EUSINE (flags) -- port engine surface
	setflag FLAG_HIDE_CELADON_EUSINE
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_SEAFOAM_GYMGUY (flags) -- port engine surface
	setflag FLAG_HIDE_SEAFOAM_GYMGUY
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_VIRIDIAN_BLUE (flags) -- port engine surface
	setflag FLAG_HIDE_VIRIDIAN_BLUE
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_ROUTE14_EUSINE (flags) -- port engine surface
	setflag FLAG_HIDE_ROUTE14_EUSINE
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_ROUTE14_SUICUNE (flags) -- port engine surface
	setflag FLAG_HIDE_ROUTE14_SUICUNE
	
	// TODO(pe-migration): missing in pe-expansion -- FLAG_BADGE09_GET (flags) -- port engine surface
	clearflag FLAG_BADGE09_GET
	// TODO(pe-migration): missing in pe-expansion -- FLAG_BADGE10_GET (flags) -- port engine surface
	clearflag FLAG_BADGE10_GET
	// TODO(pe-migration): missing in pe-expansion -- FLAG_BADGE11_GET (flags) -- port engine surface
	clearflag FLAG_BADGE11_GET
	// TODO(pe-migration): missing in pe-expansion -- FLAG_BADGE12_GET (flags) -- port engine surface
	clearflag FLAG_BADGE12_GET
	// TODO(pe-migration): missing in pe-expansion -- FLAG_BADGE13_GET (flags) -- port engine surface
	clearflag FLAG_BADGE13_GET
	// TODO(pe-migration): missing in pe-expansion -- FLAG_BADGE14_GET (flags) -- port engine surface
	clearflag FLAG_BADGE14_GET
	// TODO(pe-migration): missing in pe-expansion -- FLAG_BADGE15_GET (flags) -- port engine surface
	clearflag FLAG_BADGE15_GET
	// TODO(pe-migration): missing in pe-expansion -- FLAG_BADGE16_GET (flags) -- port engine surface
	clearflag FLAG_BADGE16_GET
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GOT_VERMILION_HP_UP (flags) -- port engine surface
	clearflag FLAG_GOT_VERMILION_HP_UP
	// TODO(pe-migration): missing in pe-expansion -- FLAG_KANTO_RADIO_GOT (flags) -- port engine surface
	clearflag FLAG_KANTO_RADIO_GOT
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_VERMILION_SNORLAX (flags) -- port engine surface
	clearflag FLAG_HIDE_VERMILION_SNORLAX
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_FAN_CLUB_CLEFAIRY_DOLL (flags) -- port engine surface
	clearflag FLAG_HIDE_FAN_CLUB_CLEFAIRY_DOLL
	clearflag FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES
	// TODO(pe-migration): missing in pe-expansion -- FLAG_RETURNED_MACHINE_PART (flags) -- port engine surface
	clearflag FLAG_RETURNED_MACHINE_PART
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GOT_TM_PSYCHIC (flags) -- port engine surface
	clearflag FLAG_GOT_TM_PSYCHIC
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GOT_HOENN_STARTER (flags) -- port engine surface
	clearflag FLAG_GOT_HOENN_STARTER
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GOT_UP_GRADE (flags) -- port engine surface
	clearflag FLAG_GOT_UP_GRADE
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GOT_CLEANSE_TAG (flags) -- port engine surface
	clearflag FLAG_GOT_CLEANSE_TAG
	// TODO(pe-migration): missing in pe-expansion -- FLAG_ROUTE25_GOT_NUGGET (flags) -- port engine surface
	clearflag FLAG_ROUTE25_GOT_NUGGET
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_POWER_PLANT_ENGINEER (flags) -- port engine surface
	clearflag FLAG_HIDE_POWER_PLANT_ENGINEER
	clearflag FLAG_HIDE_ZAPDOS
	clearflag FLAG_HIDE_ARTICUNO
	clearflag FLAG_HIDE_MOLTRES
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GOT_TM_REST (flags) -- port engine surface
	clearflag FLAG_GOT_TM_REST
	clearflag FLAG_GOT_SUPER_ROD
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_CINNABAR_BLUE (flags) -- port engine surface
	clearflag FLAG_HIDE_CINNABAR_BLUE
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GOT_ROUTE2_NUGGET (flags) -- port engine surface
	clearflag FLAG_GOT_ROUTE2_NUGGET
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GOT_VIRIDIAN_TM_SLUDGE_BOMB (flags) -- port engine surface
	clearflag FLAG_GOT_VIRIDIAN_TM_SLUDGE_BOMB
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GOT_ROUTE_14_AERIAL_ACE (flags) -- port engine surface
	clearflag FLAG_GOT_ROUTE_14_AERIAL_ACE
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_PEWTER_ROOT_FOSSIL (flags) -- port engine surface
	clearflag FLAG_HIDE_PEWTER_ROOT_FOSSIL
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_PEWTER_CLAW_FOSSIL (flags) -- port engine surface
	clearflag FLAG_HIDE_PEWTER_CLAW_FOSSIL
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_MTMOON_SILVER (flags) -- port engine surface
	clearflag FLAG_HIDE_MTMOON_SILVER
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GOT_TM_STEEL_WING (flags) -- port engine surface
	clearflag FLAG_GOT_TM_STEEL_WING
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_CERULEANCAVE_GUARD (flags) -- port engine surface
	clearflag FLAG_HIDE_CERULEANCAVE_GUARD
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_MTSILVER_RED (flags) -- port engine surface
	clearflag FLAG_HIDE_MTSILVER_RED
	clearflag FLAG_HIDE_MEWTWO
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_LATIAS (flags) -- port engine surface
	clearflag FLAG_HIDE_LATIAS
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_LATIOS (flags) -- port engine surface
	clearflag FLAG_HIDE_LATIOS
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_GROUDON (flags) -- port engine surface
	clearflag FLAG_HIDE_GROUDON
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_KYOGRE (flags) -- port engine surface
	clearflag FLAG_HIDE_KYOGRE
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_RAYQUAZA (flags) -- port engine surface
	clearflag FLAG_HIDE_RAYQUAZA
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_SEAFOAM_BLAINE (flags) -- port engine surface
	clearflag FLAG_HIDE_SEAFOAM_BLAINE

	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_CELADON_FALKNER (flags) -- port engine surface
	clearflag FLAG_HIDE_CELADON_FALKNER
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_VIRIDIAN_BUGSY (flags) -- port engine surface
	clearflag FLAG_HIDE_VIRIDIAN_BUGSY
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_DEPTSTORE_WHITNEY (flags) -- port engine surface
	clearflag FLAG_HIDE_DEPTSTORE_WHITNEY
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_BELLCHIME_MORTY (flags) -- port engine surface
	clearflag FLAG_HIDE_BELLCHIME_MORTY
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_CAFE_JASMINE (flags) -- port engine surface
	clearflag FLAG_HIDE_CAFE_JASMINE
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_LAKE_PRYCE (flags) -- port engine surface
	clearflag FLAG_HIDE_LAKE_PRYCE
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_DEN_CLAIR (flags) -- port engine surface
	clearflag FLAG_HIDE_DEN_CLAIR


	// TODO(pe-migration): missing in pe-expansion -- VAR_KANTO_ROCKET_STORY_STATE (vars) -- port engine surface
	setvar VAR_KANTO_ROCKET_STORY_STATE, 0
	// TODO(pe-migration): missing in pe-expansion -- VAR_BILLS_GRANDPA (vars) -- port engine surface
	setvar VAR_BILLS_GRANDPA, 0


	// TODO(pe-migration): missing in pe-expansion -- VAR_FAN_CLUB_CLEFAIRY (vars) -- port engine surface
	setvar VAR_FAN_CLUB_CLEFAIRY, 0
	// TODO(pe-migration): missing in pe-expansion -- VAR_FAN_CLUB_GUY (vars) -- port engine surface
	setvar VAR_FAN_CLUB_GUY, 0
	// TODO(pe-migration): missing in pe-expansion -- VAR_CLEFAIRY_DOLL_STATE (vars) -- port engine surface
	setvar VAR_CLEFAIRY_DOLL_STATE, 0
	// TODO(pe-migration): missing in pe-expansion -- VAR_NUM_BADGES (vars) -- port engine surface
	setvar VAR_NUM_BADGES, 8
	// TODO(pe-migration): missing in pe-expansion -- VAR_VERMILION_CITY_STATE (vars) -- port engine surface
	setvar VAR_VERMILION_CITY_STATE, 1

	// TODO(pe-migration): missing in pe-expansion -- VAR_KANTO_SAFARI_ZONE_PROGRESS (vars) -- port engine surface
	setvar VAR_KANTO_SAFARI_ZONE_PROGRESS, 0 
	// TODO(pe-migration): missing in pe-expansion -- FLAG_IN_KANTO_SAFARI_ZONE (flags) -- port engine surface
	clearflag FLAG_IN_KANTO_SAFARI_ZONE 
	// TODO(pe-migration): missing in pe-expansion -- FLAG_IS_KANTO_CHAMPION (flags) -- port engine surface
	clearflag FLAG_IS_KANTO_CHAMPION 
	// TODO(pe-migration): missing in pe-expansion -- VAR_BAOBA_QUEST_STATE (vars) -- port engine surface
	setvar VAR_BAOBA_QUEST_STATE, 0 
	// TODO(pe-migration): missing in pe-expansion -- VAR_CINNABAR_ISLAND_STATE (vars) -- port engine surface
	setvar VAR_CINNABAR_ISLAND_STATE, 0 
	// TODO(pe-migration): missing in pe-expansion -- VAR_MT_SILVER_STATE (vars) -- port engine surface
	setvar VAR_MT_SILVER_STATE, 0, 
	// TODO(pe-migration): missing in pe-expansion -- VAR_PALLETTOWN_LABSTATE (vars) -- port engine surface
	setvar VAR_PALLETTOWN_LABSTATE, 0 
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_LEAGUE_BLACKBELT (flags) -- port engine surface
	clearflag FLAG_HIDE_LEAGUE_BLACKBELT 
	
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_DOJO_FALKNER (flags) -- port engine surface
	setflag FLAG_HIDE_DOJO_FALKNER
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_DOJO_BUGSY (flags) -- port engine surface
	setflag FLAG_HIDE_DOJO_BUGSY
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_DOJO_WHITNEY (flags) -- port engine surface
	setflag FLAG_HIDE_DOJO_WHITNEY
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_DOJO_MORTY (flags) -- port engine surface
	setflag FLAG_HIDE_DOJO_MORTY
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_DOJO_CHUCK (flags) -- port engine surface
	setflag FLAG_HIDE_DOJO_CHUCK
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_DOJO_JASMINE (flags) -- port engine surface
	setflag FLAG_HIDE_DOJO_JASMINE
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_DOJO_PRYCE (flags) -- port engine surface
	setflag FLAG_HIDE_DOJO_PRYCE
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_DOJO_CLAIR (flags) -- port engine surface
	setflag FLAG_HIDE_DOJO_CLAIR
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_DOJO_BROCK (flags) -- port engine surface
	setflag FLAG_HIDE_DOJO_BROCK
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_DOJO_MISTY (flags) -- port engine surface
	setflag FLAG_HIDE_DOJO_MISTY
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_DOJO_SURGE (flags) -- port engine surface
	setflag FLAG_HIDE_DOJO_SURGE
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_DOJO_ERIKA (flags) -- port engine surface
	setflag FLAG_HIDE_DOJO_ERIKA
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_DOJO_JANINE (flags) -- port engine surface
	setflag FLAG_HIDE_DOJO_JANINE
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_DOJO_SABRINA (flags) -- port engine surface
	setflag FLAG_HIDE_DOJO_SABRINA
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_DOJO_BLAINE (flags) -- port engine surface
	setflag FLAG_HIDE_DOJO_BLAINE
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_DOJO_BLUE (flags) -- port engine surface
	setflag FLAG_HIDE_DOJO_BLUE
	@end flagheap
	// TODO(pe-migration): missing in pe-expansion -- VAR_SSAQUA_STATE (vars) -- port engine surface
	setvar VAR_SSAQUA_STATE, 7
	// TODO(pe-migration): missing in pe-expansion -- MAP_VERMILION_CITY_PORT_INSIDE (map_groups) -- port engine surface
	warp MAP_VERMILION_CITY_PORT_INSIDE, 8, 9
	release
	end

SSAqua_1F_EventScript_RoomSailor::
	msgbox SSAqua_1F_Text_Sailor2_FirstTime, MSGBOX_NPC
	end

SSAqua_1F_EventScript_Sailor3::
	msgbox SSAqua_1F_Text_Sailor3, MSGBOX_NPC
	end

SSAqua_1F_Trigger_Grandpa::
	lock
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_SSAQUA_1F_GRANDPA (flags) -- port engine surface
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 28, SSAqua_1F_EventScript_GrandpaEnterLeft
	call_if_eq VAR_TEMP_0, 29, SSAqua_1F_EventScript_GrandpaEnterRight
	applymovement OBJ_EVENT_ID_PLAYER, SSAqua_1F_Movement_PlayerSlideRight
	waitmovement 0
	applymovement LOCALID_SSAQUA_1F_GRANDPA, Common_Movement_WalkRight1
	waitmovement 0
	msgbox SSAqua_1F_Text_Grandpa, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SSAQUA_1F_GRANDPA, SSAqua_1F_Movement_GrandpaLeave
	waitmovement 0
	playse SE_DOOR
	removeobject LOCALID_SSAQUA_1F_GRANDPA
	
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_SSAQUA_1F_GRANDPA (flags) -- port engine surface
	setflag FLAG_HIDE_SSAQUA_1F_GRANDPA		@flagheap
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_SSAQUA_ROOM_SSE_GRANDDAUGHTER (flags) -- port engine surface
	setflag FLAG_HIDE_SSAQUA_ROOM_SSE_GRANDDAUGHTER

	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_SSAQUA_SAILOR (flags) -- port engine surface
	clearflag FLAG_HIDE_SSAQUA_SAILOR
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_SSAQUA_CAPTAINS_ROOM_GRANDDAUGHTER (flags) -- port engine surface
	clearflag FLAG_HIDE_SSAQUA_CAPTAINS_ROOM_GRANDDAUGHTER

	// TODO(pe-migration): missing in pe-expansion -- VAR_SSAQUA_STATE (vars) -- port engine surface
	setvar VAR_SSAQUA_STATE, 2
	release
	end

SSAqua_1F_EventScript_GrandpaEnterLeft::
	applymovement LOCALID_SSAQUA_1F_GRANDPA, SSAqua_1F_Movement_GrandpaEnterLeft
	waitmovement 0
	return

SSAqua_1F_EventScript_GrandpaEnterRight::
	applymovement LOCALID_SSAQUA_1F_GRANDPA, SSAqua_1F_Movement_GrandpaEnterRight
	waitmovement 0
	return

SSAqua_1F_Movement_GrandpaEnterLeft:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SSAqua_1F_Movement_GrandpaEnterRight:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SSAqua_1F_Movement_PlayerSlideRight:
	face_left
	lock_facing_direction
	walk_fast_right
	unlock_facing_direction
	step_end

SSAqua_1F_Movement_GrandpaLeave:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

SSAqua_1F_Text_Sailor1_ToVermilion:
    .string "FAST SHIP S.S.AQUA is en route to\n"
    .string "VERMILION CITY.\p"
    .string "We will make an announcement when\n"
    .string "we arrive.$"

SSAqua_1F_Text_Sailor1_ToOlivine:
    .string "FAST SHIP S.S.AQUA is en route to\n"
    .string "OLIVINE CITY.\p"
    .string "We will make an announcement when\n"
    .string "we arrive.$"

SSAqua_1F_Text_Sailor2_FirstTime:
    .string "Here's your cabin.\p"
    .string "If your POKéMON are hurt, take a\n"
    .string "nap in the bed.\p"
    .string "That will heal them.$"

SSAqua_1F_Text_Sailor3:
    .string "The passengers are all trainers.\p"
    .string "They're all itching to battle in\n"
    .string "their cabins.$"

SSAqua_1F_Text_Grandpa:
    .string "Whoa! Excuse me. I was in a hurry!\p"
    .string "My granddaughter is missing!\p"
    .string "She's just a wee girl. If you see\n"
    .string "her, please let me know!$"

SSAqua_1F_Text_Sailor1_InOlivine:
    .string "FAST SHIP S.S.AQUA has arrived in\n"
    .string "OLIVINE CITY.$"

SSAqua_1F_Text_Sailor1_InVermilion:
    .string "FAST SHIP S.S.AQUA has arrived in\n"
    .string "VERMILION CITY.$"


SSAqua_1F_Text_SailorDoorArrived:
    .string "We have arrived in VERMILION CITY.\n"
    .string "Would you like to disembark?$"
