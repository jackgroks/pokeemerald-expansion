EverGrandeCity_SidneysRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_SidneysRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_SidneysRoom_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_SidneysRoom_OnFrame
	.byte 0

EverGrandeCity_SidneysRoom_OnTransition:
	setflag FLAG_MET_SCOTT_IN_EVERGRANDE
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GARBAGEFLAG (flags) -- port engine surface
	setflag FLAG_GARBAGEFLAG
	end

EverGrandeCity_SidneysRoom_OnLoad:
	// TODO(pe-migration): missing in pe-expansion -- FLAG_DEFEATED_ELITE_4_WILL (flags) -- port engine surface
	call_if_set FLAG_DEFEATED_ELITE_4_WILL, EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom
	// TODO(pe-migration): missing in pe-expansion -- VAR_GARBAGEVAR (vars) -- port engine surface
	call_if_eq VAR_GARBAGEVAR, 1, EverGrandeCity_SidneysRoom_EventScript_CloseDoor
	end

EverGrandeCity_SidneysRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_SidneysRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_SidneysRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_SidneysRoom_OnFrame:
	// TODO(pe-migration): missing in pe-expansion -- VAR_GARBAGEVAR (vars) -- port engine surface
	map_script_2 VAR_GARBAGEVAR, 0, EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	// TODO(pe-migration): missing in pe-expansion -- VAR_GARBAGEVAR (vars) -- port engine surface
	setvar VAR_GARBAGEVAR, 1
	releaseall
	end

EverGrandeCity_SidneysRoom_EventScript_Sidney::
	lock
	faceplayer
	// TODO(pe-migration): missing in pe-expansion -- FLAG_DEFEATED_ELITE_4_WILL (flags) -- port engine surface
	goto_if_set FLAG_DEFEATED_ELITE_4_WILL, EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech
	// TODO(pe-migration): missing in pe-expansion -- FLAG_SIDNEY_REMATCH (flags) -- port engine surface
	goto_if_set FLAG_SIDNEY_REMATCH, EverGrandeCity_SidneysRoom_EventScript_SidneyRematch
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_SidneysRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SIDNEY, EverGrandeCity_SidneysRoom_Text_Defeat
	goto EverGrandeCity_SidneysRoom_EventScript_Defeated
	end

EverGrandeCity_SidneysRoom_EventScript_SidneyRematch::
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_SidneysRoom_Text_IntroSpeech2, MSGBOX_DEFAULT
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_LUCY_BF_BRAIN (trainers) -- port engine surface
	trainerbattle_no_intro TRAINER_LUCY_BF_BRAIN, EverGrandeCity_SidneysRoom_Text_Defeat2
	goto EverGrandeCity_SidneysRoom_EventScript_Defeated
	end

EverGrandeCity_SidneysRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_SidneysRoom_EventScript_Defeated::
	// TODO(pe-migration): missing in pe-expansion -- FLAG_DEFEATED_ELITE_4_WILL (flags) -- port engine surface
	setflag FLAG_DEFEATED_ELITE_4_WILL
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_SidneysRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_SidneysRoom_Text_IntroSpeech:
	.string "Welcome, challenger!\n"
	.string "I'm SIDNEY of the ELITE FOUR.\p"
	.string "I like that look you're giving me.\n"
	.string "I guess you'll give me a good match.\l"
	.string "That's good! Looking real good!\p"
	.string "All right! You and me, let's enjoy\n"
	.string "a battle that can only be staged\l"
	.string "here in the POKéMON LEAGUE!$"

EverGrandeCity_SidneysRoom_Text_IntroSpeech2:
	.string "Welcome back, challenger!\n"
	.string "I'm SIDNEY of the ELITE FOUR.\p"
	.string "But you already know me!\n"
	.string "I guess you'll give me a good match\l"
	.string "again. Looking real good!\p"
	.string "All right! You and me, let's enjoy\n"
	.string "a battle that can only be staged\l"
	.string "here in the POKéMON LEAGUE!\p"
	.string "This time, I won't lose.$"

EverGrandeCity_SidneysRoom_Text_Defeat:
	.string "Well, how do you like that? I lost!\n"
	.string "Eh, it was fun, so it doesn't matter.$"

EverGrandeCity_SidneysRoom_Text_Defeat2:
	.string "Well, how do you like that? I lost!\n"
	.string "Again! It doesn't matter. It was fun.$"

EverGrandeCity_SidneysRoom_Text_PostBattleSpeech:
	.string "Well, listen to what this loser has\n"
	.string "to say.\p"
	.string "You've got what it takes to go far.\n"
	.string "Now, go on to the next room and enjoy\l"
	.string "your next battle!$"
