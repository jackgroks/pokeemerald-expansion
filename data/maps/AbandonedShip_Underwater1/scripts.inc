AbandonedShip_Underwater1_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Underwater1_OnResume
	.byte 0

AbandonedShip_Underwater1_OnResume:
	@ Phase 2 minimal-strip: AbandonedShip_HiddenFloor{Corridors,Rooms}
	@ removed from build (HnS Sevii side-mission, not on Phase 5 path).
	@ Dive trigger neutered; restore alongside facility-cleanup feature.
	@ setdivewarp MAP_ABANDONED_SHIP_HIDDEN_FLOOR_CORRIDORS, 0, 10
	end

