Route26North_MapScripts::
	.byte 0

Route26North_Trigger::
	// TODO(pe-migration): missing in pe-expansion -- FLAG_VISITED_RECEPTION_GATE (flags) -- port engine surface
	setflag FLAG_VISITED_RECEPTION_GATE
	setvar VAR_TEMP_0, 1
	end
