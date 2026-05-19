Common_EventScript_SetGymTrainers::
	switch VAR_0x8008
	case 1, VioletCity_Gym_SetGymTrainers
	case 2, AzaleaTown_Gym_SetGymTrainers
	case 3, GoldenrodCity_Gym_SetGymTrainers
	case 4, EcruteakCity_Gym_SetGymTrainers
	case 5, CianwoodCity_Gym_SetGymTrainers
	case 6, OlivineCity_Gym_SetGymTrainers
	case 7, MahoganyTown_Gym_SetGymTrainers
	case 8, BlackthornCity_Gym_SetGymTrainers
	case 9, PewterCity_Gym_SetGymTrainers
	case 10, CeruleanCity_Gym_SetGymTrainers
	case 11, VermilionCity_Gym_SetGymTrainers
	case 12, CeladonCity_Gym_SetGymTrainers
	case 13, SaffronCity_Gym_SetGymTrainers
	case 14, FuchsiaCity_Gym_SetGymTrainers
	case 15, CinnabarIsland_Gym_SetGymTrainers
	case 16, ViridianCity_Gym_SetGymTrainers
	end

VioletCity_Gym_SetGymTrainers::
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_ROD (trainers) -- port engine surface
	settrainerflag TRAINER_ROD
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_ABE (trainers) -- port engine surface
	settrainerflag TRAINER_ABE
	return

AzaleaTown_Gym_SetGymTrainers::
	settrainerflag TRAINER_BENNY
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_AL (trainers) -- port engine surface
	settrainerflag TRAINER_AL
	settrainerflag TRAINER_JOSH
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_AMY_AND_MAY (trainers) -- port engine surface
	settrainerflag TRAINER_AMY_AND_MAY
	return

GoldenrodCity_Gym_SetGymTrainers::
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_CARRIE (trainers) -- port engine surface
	settrainerflag TRAINER_CARRIE
	settrainerflag TRAINER_BRIDGET
	settrainerflag TRAINER_VICTORIA
	settrainerflag TRAINER_SAMANTHA
	return

EcruteakCity_Gym_SetGymTrainers::
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_JEFFREY (trainers) -- port engine surface
	settrainerflag TRAINER_JEFFREY
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_PING (trainers) -- port engine surface
	settrainerflag TRAINER_PING
	settrainerflag TRAINER_MARTHA
	settrainerflag TRAINER_GRACE
	return

CianwoodCity_Gym_SetGymTrainers::
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_YOSHI (trainers) -- port engine surface
	settrainerflag TRAINER_YOSHI
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_LAO (trainers) -- port engine surface
	settrainerflag TRAINER_LAO
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_NOB (trainers) -- port engine surface
	settrainerflag TRAINER_NOB
	settrainerflag TRAINER_LUNG
	return

OlivineCity_Gym_SetGymTrainers::

	return

MahoganyTown_Gym_SetGymTrainers::
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_ROXANNE (trainers) -- port engine surface
	settrainerflag TRAINER_ROXANNE
	settrainerflag TRAINER_RONALD
	settrainerflag TRAINER_CLARISSA
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_BRAD (trainers) -- port engine surface
	settrainerflag TRAINER_BRAD
	settrainerflag TRAINER_DOUGLAS
	return

BlackthornCity_Gym_SetGymTrainers::
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_MIKE (trainers) -- port engine surface
	settrainerflag TRAINER_MIKE
	settrainerflag TRAINER_PAUL
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_LOLA (trainers) -- port engine surface
	settrainerflag TRAINER_LOLA
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_CODY (trainers) -- port engine surface
	settrainerflag TRAINER_CODY
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_FRAN (trainers) -- port engine surface
	settrainerflag TRAINER_FRAN
	return

PewterCity_Gym_SetGymTrainers::
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_JERRY (trainers) -- port engine surface
	settrainerflag TRAINER_JERRY
	return

CeruleanCity_Gym_SetGymTrainers::
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_DIANA (trainers) -- port engine surface
	settrainerflag TRAINER_DIANA
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_BRIANA (trainers) -- port engine surface
	settrainerflag TRAINER_BRIANA
	settrainerflag TRAINER_PARKER
	return

VermilionCity_Gym_SetGymTrainers::
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_GREGORY (trainers) -- port engine surface
	settrainerflag TRAINER_GREGORY
	settrainerflag TRAINER_VINCENT
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_HORTON (trainers) -- port engine surface
	settrainerflag TRAINER_HORTON
	return

CeladonCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_MICHELLE
	settrainerflag TRAINER_TANYA
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_JULIA (trainers) -- port engine surface
	settrainerflag TRAINER_JULIA
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_JO_AND_ZOE (trainers) -- port engine surface
	settrainerflag TRAINER_JO_AND_ZOE
	return

SaffronCity_Gym_SetGymTrainers::
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_REBECCA (trainers) -- port engine surface
	settrainerflag TRAINER_REBECCA
	settrainerflag TRAINER_FRANKLIN
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_DORIS (trainers) -- port engine surface
	settrainerflag TRAINER_DORIS
	settrainerflag TRAINER_JARED
	return

FuchsiaCity_Gym_SetGymTrainers::
	settrainerflag TRAINER_ALICE
	settrainerflag TRAINER_LINDA
	// TODO(pe-migration): missing in pe-expansion -- TRAINER_CINDY (trainers) -- port engine surface
	settrainerflag TRAINER_CINDY
	settrainerflag TRAINER_BARRY
	return

CinnabarIsland_Gym_SetGymTrainers::
	return

ViridianCity_Gym_SetGymTrainers::
	return
