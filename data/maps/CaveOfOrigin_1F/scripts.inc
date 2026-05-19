CaveOfOrigin_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CaveOfOrigin_1F_OnTransition
	.byte 0

CaveOfOrigin_1F_OnTransition:
	// TODO(pe-migration): missing in pe-expansion -- FLAG_FINITE_TMS (flags) -- port engine surface
	call_if_set FLAG_FINITE_TMS, CaveOfOrigin_EventScript_DisableTriggers
	end
