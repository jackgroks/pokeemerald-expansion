.set LOCALID_GOLDENROD_ROCKET_SCOUT, 11

GoldenrodCity_MapScripts::
	.byte 0

GoldenrodCity_EventScript_Trigger:: @flagheap
	// TODO(pe-migration): missing in pe-expansion -- FLAG_SHOWN_ELM_TOGEPI (flags) -- port engine surface
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, GoldenrodCity_Elm_Togepi_Call
	// TODO(pe-migration): missing in pe-expansion -- FLAG_VISITED_GOLDENROD_CITY (flags) -- port engine surface
	setflag FLAG_VISITED_GOLDENROD_CITY
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_GOLDENROD_ROCKETS (flags) -- port engine surface
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_GOLDENROD_BILL (flags) -- port engine surface
	setflag FLAG_HIDE_GOLDENROD_BILL
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO (flags) -- port engine surface
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER (flags) -- port engine surface
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1 (flags) -- port engine surface
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL (flags) -- port engine surface
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2 (flags) -- port engine surface
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
	
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_GOLDENROD_BEAUTY (flags) -- port engine surface
	clearflag FLAG_HIDE_GOLDENROD_BEAUTY
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_GOLDENROD_ROCKET_SCOUT (flags) -- port engine surface
	clearflag FLAG_HIDE_GOLDENROD_ROCKET_SCOUT
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_GOLDENROD_NPCS (flags) -- port engine surface
	clearflag FLAG_HIDE_GOLDENROD_NPCS
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GOT_RETURN (flags) -- port engine surface
	clearflag FLAG_GOT_RETURN
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GOT_FRUSTRATION (flags) -- port engine surface
	clearflag FLAG_GOT_FRUSTRATION
	clearflag FLAG_RECEIVED_BIKE
	// TODO(pe-migration): missing in pe-expansion -- FLAG_RECEIVED_SQUIRTBOTTLE (flags) -- port engine surface
	clearflag FLAG_RECEIVED_SQUIRTBOTTLE
	clearflag FLAG_GOT_EEVEE
	// TODO(pe-migration): missing in pe-expansion -- FLAG_SYS_PC_BILL (flags) -- port engine surface
	clearflag FLAG_SYS_PC_BILL
	// TODO(pe-migration): missing in pe-expansion -- FLAG_RETURNED_MACHINE_PART (flags) -- port engine surface
	clearflag FLAG_RETURNED_MACHINE_PART
	// TODO(pe-migration): missing in pe-expansion -- FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR (flags) -- port engine surface
	clearflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GOLDENROD_MACHOKE_1 (flags) -- port engine surface
	clearflag FLAG_GOLDENROD_MACHOKE_1
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GOLDENROD_MACHOKE_2 (flags) -- port engine surface
	clearflag FLAG_GOLDENROD_MACHOKE_2
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GOLDENROD_MACHOKE_3 (flags) -- port engine surface
	clearflag FLAG_GOLDENROD_MACHOKE_3
	// TODO(pe-migration): missing in pe-expansion -- FLAG_COMPLETED_SWITCHES (flags) -- port engine surface
	clearflag FLAG_COMPLETED_SWITCHES
	// TODO(pe-migration): missing in pe-expansion -- FLAG_ENABLE_RADIO (flags) -- port engine surface
	clearflag FLAG_ENABLE_RADIO
	// TODO(pe-migration): missing in pe-expansion -- FLAG_KANTO_RADIO_GOT (flags) -- port engine surface
	clearflag FLAG_KANTO_RADIO_GOT
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GOLDENROD_NPC_TRADE_COMPLETED (flags) -- port engine surface
	clearflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GOT_SKILL_SWAP (flags) -- port engine surface
	clearflag FLAG_GOT_SKILL_SWAP
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_RADIOTOWER_GATE (flags) -- port engine surface
	clearflag FLAG_HIDE_RADIOTOWER_GATE
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR (flags) -- port engine surface
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GOT_MARY_BRIGHT_POWDER (flags) -- port engine surface
	clearflag FLAG_GOT_MARY_BRIGHT_POWDER
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GOT_QUICK_CLAW (flags) -- port engine surface
	clearflag FLAG_GOT_QUICK_CLAW
	// TODO(pe-migration): missing in pe-expansion -- FLAG_GOT_MAGNET (flags) -- port engine surface
	clearflag FLAG_GOT_MAGNET

	// TODO(pe-migration): missing in pe-expansion -- VAR_BUG_CONTEST_STATE (vars) -- port engine surface
	setvar VAR_BUG_CONTEST_STATE, 0
	// TODO(pe-migration): missing in pe-expansion -- VAR_KENYA (vars) -- port engine surface
	setvar VAR_KENYA, 0
	// TODO(pe-migration): missing in pe-expansion -- VAR_LUGIA_OR_HOOH (vars) -- port engine surface
	setvar VAR_LUGIA_OR_HOOH, 0
	// TODO(pe-migration): missing in pe-expansion -- VAR_TRAIN (vars) -- port engine surface
	setvar VAR_TRAIN, 0
	// TODO(pe-migration): missing in pe-expansion -- VAR_ELEVATOR (vars) -- port engine surface
	setvar VAR_ELEVATOR, 0
	// TODO(pe-migration): missing in pe-expansion -- VAR_GOLDENROD_CITY_STATE (vars) -- port engine surface
	setvar VAR_GOLDENROD_CITY_STATE, 1
	release
	end

GoldenrodCity_Trigger_Music::
	// TODO(pe-migration): missing in pe-expansion -- VAR_GOLDENROD_CITY_STATE (vars) -- port engine surface
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_Trigger_MusicNotYet
	// TODO(pe-migration): missing in pe-expansion -- VAR_GOLDENROD_CITY_STATE (vars) -- port engine surface
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, GoldenrodCity_Trigger_MusicNotYet
	playbgm MUS_DUMMY, TRUE	@ MUS_HG_ROCKET_TAKEOVER
	setvar VAR_TEMP_0, 1 
	end

GoldenrodCity_Trigger_MusicNotYet::
	setvar VAR_TEMP_0, 1
	end

GoldenrodCity_Elm_Togepi_Call::
	lock
	pokenavcall GoldenrodCity_Text_ElmCall
	waitmessage
	delay 30
	release
	return

GoldenrodCity_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Youngster::
	msgbox GoldenrodCity_Text_Youngster1, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Youngster2::
	msgbox GoldenrodCity_Text_Youngster2, MSGBOX_NPC
	end

GoldenrodCity_EventScript_CooltrainerF::
	lock
	faceplayer
	// TODO(pe-migration): missing in pe-expansion -- FLAG_HIDE_GOLDENROD_ROCKET_SCOUT (flags) -- port engine surface
	goto_if_set FLAG_HIDE_GOLDENROD_ROCKET_SCOUT, GoldenrodCity_EventScript_CooltrainerFCleared
	msgbox GoldenrodCity_Text_CooltrainerF1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_CooltrainerFCleared::
	msgbox GoldenrodCity_Text_CooltrainerF1_Cleared, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_NameRaterSign::
	msgbox GoldenrodCity_Text_NameRaterSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_RocketScout::
	lock
	msgbox GoldenrodCity_Text_RocketScout1, MSGBOX_DEFAULT
	closemessage
	PLAYSE SE_PIN
	applymovement LOCALID_GOLDENROD_ROCKET_SCOUT, Common_Movement_ExclamationMark
	delay 20
	faceplayer
	msgbox GoldenrodCity_Text_RocketScout2, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_ROCKET_SCOUT, DIR_NORTH
	release
	end

GoldenrodCity_EventScript_Rocket1::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket2::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket3::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket3, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket4::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket4, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket5::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket5, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket6::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket6, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Woman::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Hiker::
	lock
	faceplayer
	// TODO(pe-migration): missing in pe-expansion -- FLAG_DAY_POKEMON (flags) -- port engine surface
	goto_if_set FLAG_DAY_POKEMON, GoldenrodCity_EventScript_Hiker2
	msgbox GoldenrodCity_Text_HikerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Hiker2::
	msgbox GoldenrodCity_Text_HikerNight, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Snubbull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SNUBBULL, CRY_MODE_NORMAL
	msgbox GoldenrodCity_Text_Snubbull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodCity_EventScript_Mime::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MR_MIME, CRY_MODE_NORMAL
	msgbox GoldenrodCity_Text_MrMime, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodCity_EventScript_SignUnderground::
	lock
	msgbox GoldenrodCity_Text_UndergroundSouthSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignDept::
	lock
	msgbox GoldenrodCity_Text_DeptStoreSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignBike::
	lock
	msgbox GoldenrodCity_Text_BikeShopSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignTrain::
	lock
	msgbox GoldenrodCity_Text_StationSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignGym::
	lock
	msgbox GoldenrodCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignFlower::
	lock
	msgbox GoldenrodCity_Text_FlowerShopSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignRadio::
	lock
	msgbox GoldenrodCity_Text_RadioTowerSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignGameCorner::
	lock
	msgbox GoldenrodCity_Text_GameCornerSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_EventScript_Beauty::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Beauty, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Text_Beauty:
	.string "This is the GOLDENROD GYM!\p"
	.string "Our leader WHITNEY is not here\n"
	.string "right now. She might be at the\l"
	.string "RADIO TOWER.$"

GoldenrodCity_Text_Woman:
	.string "I used to train in WHITNEY's GYM,\n"
	.string "but all her crying gave me a\l"
	.string "headache.$"

GoldenrodCity_Text_HikerDay:
	.string "When I went into the GAME CORNER\n"
	.string "it was night time... How long was I\l"
	.string "in there?!$"

GoldenrodCity_Text_HikerNight:
	.string "When I went into the GAME CORNER\n"
	.string "it was day time... How long was I\l"
	.string "in there?!$"

GoldenrodCity_Text_Snubbull:
	.string "SNUBBULL: SNUUUBUUUULL!$"

GoldenrodCity_Text_MrMime:
	.string "............................$"

GoldenrodCity_Text_ElmCall:
	.string "PROF.ELM: Hello, {PLAYER}?\n"
	.string "Has that EGG hatched yet?\p"
	.string "Once it hatches, don't forget to\n"
	.string "bring it by the lab! I need to\l"
	.string "see it!$"

GoldenrodCity_Text_PokefanM:
	.string "They built the new RADIO TOWER\n"
	.string "to replace the old creaky one.$"

GoldenrodCity_Text_Youngster1:
	.string "I know there's a new BIKE SHOP,\n"
	.string "but I can't find it anywhere.$"

GoldenrodCity_Text_CooltrainerF1:
	.string "Is that man in black dressed up\n"
	.string "like a TEAM ROCKET member?\p"
	.string "How silly!$"

GoldenrodCity_Text_CooltrainerF1_Cleared:
	.string "Was that man in black really part\n"
	.string "of TEAM ROCKET? I can't believe it!$"

GoldenrodCity_Text_CooltrainerF2:
	.string "The RADIO TOWER in GOLDENROD CITY\n"
	.string "is quite the landmark.\p"
	.string "They're running a campaign now.\p"
	.string "They'll give you a shiny new\n"
	.string "RADIO if you can pass their quiz.$"

GoldenrodCity_Text_CooltrainerF2_GotCard:
	.string "Oh, your POKéGEAR already works\n"
	.string "as a radio!$"

GoldenrodCity_Text_Youngster2:
	.string "E-he-he-he…\p"
	.string "I got in trouble for playing in\n"
	.string "the DEPT.STORE basement.$"

GoldenrodCity_Text_Lass:
	.string "That man inside rates your\n"
	.string "POKéMON nicknames.\p"
	.string "He can even rename them.$"

GoldenrodCity_Text_Gramps:
	.string "Whew! This town is so big,\n"
	.string "I can't find anything at all.$"

GoldenrodCity_Text_RocketScout1:
	.string "So this is the RADIO TOWER…$"

GoldenrodCity_Text_RocketScout2:
	.string "What do you want, pest?\n"
	.string "Scram already!$"

GoldenrodCity_Text_Rocket1:
	.string "Stay out of the way!\n"
	.string "Beat it, kid!$"

GoldenrodCity_Text_Rocket2:
	.string "Take over the RADIO TOWER…\p"
	.string "What? It's none of your business!$"

GoldenrodCity_Text_Rocket3:
	.string "POKéMON? They're just tools\n"
	.string "we use to make money!$"

GoldenrodCity_Text_Rocket4:
	.string "Our dream will soon come true…\p"
	.string "It was a long, hard struggle…$"

GoldenrodCity_Text_Rocket5:
	.string "Hey, brat! You don't belong here!\n"
	.string "Get lost already!$"

GoldenrodCity_Text_Rocket6:
	.string "Come and taste the terror of\n"
	.string "TEAM ROCKET!$"

GoldenrodCity_Text_StationSign:
	.string "GOLDENROD CITY STATION$"

GoldenrodCity_Text_RadioTowerSign:
	.string "GOLDENROD CITY RADIO TOWER$"

GoldenrodCity_Text_DeptStoreSign:
	.string "Full Selection of POKéMON Goods!\p"
	.string "GOLDENROD CITY DEPT.STORE$"

GoldenrodCity_Text_GymSign:
	.string "GOLDENROD CITY POKéMON GYM\n"
	.string "LEADER: WHITNEY\p"
	.string "The Incredibly Pretty Girl!$"

GoldenrodCity_Text_CitySign:
	.string "GOLDENROD CITY\p"
	.string "The Festive City of Opulent Charm$"

GoldenrodCity_Text_BikeShopSign:
	.string "The World is a Cycle Path!\n"
	.string "BIKE SHOP$"

GoldenrodCity_Text_GameCornerSign:
	.string "Your Playground!\p"
	.string "GOLDENROD CITY GAME CORNER$"

GoldenrodCity_Text_NameRaterSign:
	.string "NAME RATER\p"
	.string "Get Your POKéMON Nicknames Rated$"

GoldenrodCity_Text_UndergroundNorthSign:
	.string "UNDERGROUND ENTRANCE$"

GoldenrodCity_Text_UndergroundSouthSign:
	.string "UNDERGROUND ENTRANCE$"


GoldenrodCity_Text_FlowerShopSign:
	.string "Blooming Beautiful FLOWER SHOP$"

GoldenrodCity_Text_MoveTutorAsk:
	.string "I can teach your POKéMON some\n"
	.string "amazing moves!\p"
	.string "Should I teach one?$"

GoldenrodCity_Text_MoveTutorCost:
	.string "It'll cost you 1000 coins.\n"
	.string "Okay?$"

GoldenrodCity_Text_MoveTutorDecline:
	.string "Aww… But these moves are great!$"

GoldenrodCity_Text_MoveTutorWhich:
	.string "Wahahah! You won't regret it!\p"
	.string "Which move should I teach?$"

GoldenrodCity_Text_MoveTutorNoCash:
	.string "Too bad. Guess I'll need to\n"
	.string "get some cash from home…$"

GoldenrodCity_Text_MoveTutorUnderstand:
	.string "If you understand this move,\n"
	.string "you've made it as a trainer.$"

GoldenrodCity_Text_MoveTutorFarewell:
	.string "Wahahah! Farewell, kid!$"

GoldenrodCity_Text_MoveTutorBut:
	.string "B-but…$"

GoldenrodCity_Text_MoveTutorNotEnoughCoins:
	.string "…You don't have enough coins…$"
