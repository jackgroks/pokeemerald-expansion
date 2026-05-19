static const struct InGameTrade sIngameTrades[] =
{
    [INGAME_TRADE_SEEDOT] =
    {
        .nickname = _("BUDDY"),
        .species = SPECIES_BUDEW,
        .ivs = {5, 4, 5, 4, 4, 4},
        .abilityNum = 0,
        .otId = 38726,
        .conditions = {30, 5, 5, 5, 5},
        .personality = 0x84,
        .heldItem = ITEM_CHESTO_BERRY,
        .mailNum = -1,
        .otName = _("KOBE"),
        .otGender = FEMALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_RALTS
    },
    [INGAME_TRADE_ONIX] =
    {
        .nickname = _("ROCKY"),
        .species = SPECIES_ONIX,
        .ivs = {4, 4, 4, 5, 5, 4},
        .abilityNum = 1,
        .otId = 48926,
        .conditions = {5, 5, 30, 5, 5},
        .personality = 0x96,
        .heldItem = ITEM_PERSIM_BERRY,
        .mailNum = 0,
        .otName = _("RUDY"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_BELLSPROUT
    },
    [INGAME_TRADE_HORSEA] =
    {
        .nickname = _("SEASOR"),
        .species = SPECIES_HORSEA,
        .ivs = {5, 4, 4, 4, 5, 4},
        .abilityNum = 0,
        .otId = 46285,
        .conditions = {5, 5, 5, 5, 30},
        .personality = 0x7F,
        .heldItem = ITEM_WAVE_MAIL,
        .mailNum = 1,
        .otName = _("SKYLAR"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_BAGON
    },
    [INGAME_TRADE_MEOWTH] =
    {
        .nickname = _("MEOWOW"),
        .species = SPECIES_MEOWTH,
        .ivs = {4, 5, 4, 5, 4, 4},
        .abilityNum = 0,
        .otId = 91481,
        .conditions = {5, 5, 5, 30, 5},
        .personality = 0x8B,
        .heldItem = ITEM_RETRO_MAIL,
        .mailNum = 2,
        .otName = _("ISIS"),
        .otGender = FEMALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_SKITTY
    },
    [INGAME_TRADE_MACHOP] =
    {
        .nickname = _("MUSCLE"),
        .species = SPECIES_MACHOP,
        .ivs = {4, 4, 4, 5, 5, 4},
        .abilityNum = 0,
        .otId = 44312,
        .conditions = {5, 5, 30, 5, 5},
        .personality = 0x19,
        .heldItem = ITEM_MACHO_BRACE,
        .mailNum = 0,
        .otName = _("JOSE"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_DROWZEE
    },
    [INGAME_TRADE_VOLTORB] =
    {
        .nickname = _("BILLY"),
        .species = SPECIES_VOLTORB,
        .ivs = {4, 4, 4, 5, 5, 4},
        .abilityNum = 1,
        .otId = 29189,
        .conditions = {5, 5, 30, 5, 5},
        .personality = 0x00000000,
        .heldItem = ITEM_CHERI_BERRY,
        .mailNum = 0,
        .otName = _("TIM"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_KRABBY
    },
    [INGAME_TRADE_MR_MIME] =
    {
        .nickname = _("MIMIEN"),
        .species = SPECIES_MR_MIME,
        .ivs = {4, 4, 4, 5, 5, 4},
        .abilityNum = 0,
        .otId = 10283,
        .conditions = {5, 5, 30, 5, 5},
        .personality = 0x00000008,
        .heldItem = ITEM_SMOKE_BALL,
        .mailNum = 0,
        .otName = _("EMY"),
        .otGender = FEMALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_DODRIO
    },
    [INGAME_TRADE_MAGNETON] =
    {
        .nickname = _("MAGGIE"),
        .species = SPECIES_MAGNETON,
        .ivs = {4, 4, 4, 5, 5, 4},
        .abilityNum = 0,
        .otId = 50082,
        .conditions = {5, 5, 30, 5, 5},
        .personality = 0x00000008,
        .heldItem = ITEM_METAL_COAT,
        .mailNum = 0,
        .otName = _("LORENZO"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_DUGTRIO
    },
    [INGAME_TRADE_HAUNTER] =
    {
        .nickname = _("PAUL"),
        .species = SPECIES_HAUNTER,
        .ivs = {4, 4, 4, 5, 5, 4},
        .abilityNum = 0,
        .otId = 15616,
        .conditions = {5, 5, 30, 5, 5},
        .personality = 0x0000008F,
        .heldItem = ITEM_LUM_BERRY,
        .mailNum = 0,
        .otName = _("MONDO"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_XATU
    },
    [INGAME_TRADE_PIKACHU] =
    {
        .nickname = _("VOLTY"),
        .species = SPECIES_PIKACHU,
        .ivs = {4, 4, 4, 5, 5, 4},
        .abilityNum = 0,
        .otId = 33038,
        .conditions = {5, 5, 30, 5, 5},
        .personality = 0xA0C6230D,
        .heldItem = ITEM_LIGHT_BALL,
        .mailNum = 0,
        .otName = _("SURGE"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_PIKACHU
    },
    [INGAME_TRADE_BELDUM] =
    {
        .nickname = _("IRON"),
        .species = SPECIES_BELDUM,
        .ivs = {4, 4, 4, 5, 5, 4},
        .abilityNum = 0,
        .otId = 23478,
        .conditions = {5, 5, 30, 5, 5},
        .personality = 0x00000002,
        .heldItem = ITEM_METAL_COAT,
        .mailNum = 0,
        .otName = _("STEVEN"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_FORRETRESS
    },
    [INGAME_TRADE_BONSLY] =
    {
        .nickname = _("WOODY"),
        .species = SPECIES_BONSLY,
        .ivs = {4, 4, 4, 5, 5, 4},
        .abilityNum = 0,
        .otId = 16845,
        .conditions = {5, 5, 30, 5, 5},
        .personality = 0x00000007,
        .heldItem = ITEM_ORAN_BERRY,
        .mailNum = 0,
        .otName = _("BROCK"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_RHYHORN
    },
    [INGAME_TRADE_STEELIX] =
    {
        .nickname = _("RUSTY"),
        .species = SPECIES_STEELIX,
        .ivs = {4, 4, 4, 5, 5, 4},
        .abilityNum = 0,
        .otId = 26491,
        .conditions = {5, 5, 30, 5, 5},
        .personality = 0x00000082,
        .heldItem = ITEM_SOOTHE_BELL,
        .mailNum = 0,
        .otName = _("JASMINE"),
        .otGender = MALE,
        .sheen = 10,
        .requestedSpecies = SPECIES_MEOWTH
    }
};
