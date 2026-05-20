#ifndef GUARD_PE_HOENN_STRIP_STUBS_H
#define GUARD_PE_HOENN_STRIP_STUBS_H

// Phase 2 minimal-strip stub header.
//
// pe-engine C code (battle_*, contest_util, decoration, pokenav_*, region_map,
// data.c, etc.) contains references to pe-Hoenn MAPSEC_/LOCALID_/TRAINER_CLASS_
// constants that Phase 3's T9 migration dropped. Restoring those constants
// additively (the prior `_hns.h` mirror pattern) would let the references
// resolve, but the surrounding C-side logic (Hoenn-specific cinematic gates,
// Hoenn nurse/mart NPC scripts, Hoenn-only contest dispatch) is unreachable
// in HnS Johto/Kanto play regardless.
//
// This header stubs every undeclared MAPSEC_/LOCALID_/TRAINER_CLASS_ to a
// safe value so the compares/array-indexes evaluate to "no match" and the
// surrounding branches become dead code. The dead branches will be cleaned
// up surgically in facility-by-facility cleanup features. For now, this
// gets the build past C-compile so the link stage can be reached.
//
// Per HMS Medway's R6f recce (2026-05-19 night): the user authorized "I
// don't care about Hoenn MAPSECs, they're being deleted later" — these
// stubs are the lightweight path to that future deletion. Restored at
// MAPSEC_NONE / 0 so consumer loops terminate and equality checks fail.

// pe-Hoenn MAPSEC stubs (149 total in build log; ~110 unique listed here)
// All resolve to MAPSEC_NONE so any `regionMapSectionId == MAPSEC_X` check fails
// for any non-NONE map (which all HnS play maps are).
#define MAPSEC_ABANDONED_SHIP            MAPSEC_NONE
#define MAPSEC_ALTERING_CAVE             MAPSEC_NONE
#define MAPSEC_ALTERING_CAVE_FRLG        MAPSEC_NONE
#define MAPSEC_ANCIENT_TOMB              MAPSEC_NONE
#define MAPSEC_AQUA_HIDEOUT              MAPSEC_NONE
#define MAPSEC_AQUA_HIDEOUT_OLD          MAPSEC_NONE
#define MAPSEC_ARTISAN_CAVE              MAPSEC_NONE
#define MAPSEC_BERRY_FOREST              MAPSEC_NONE
#define MAPSEC_BIRTH_ISLAND_FRLG         MAPSEC_NONE
#define MAPSEC_BOND_BRIDGE               MAPSEC_NONE
#define MAPSEC_CANYON_ENTRANCE           MAPSEC_NONE
#define MAPSEC_CAPE_BRINK                MAPSEC_NONE
#define MAPSEC_CAVE_OF_ORIGIN            MAPSEC_NONE
#define MAPSEC_DESERT_RUINS              MAPSEC_NONE
#define MAPSEC_DESERT_UNDERPASS          MAPSEC_NONE
#define MAPSEC_DEWFORD_TOWN              MAPSEC_NONE
#define MAPSEC_DILFORD_CHAMBER           MAPSEC_NONE
#define MAPSEC_DOTTED_HOLE               MAPSEC_NONE
#define MAPSEC_DYNAMIC                   MAPSEC_NONE
#define MAPSEC_EMBER_SPA                 MAPSEC_NONE
#define MAPSEC_EVER_GRANDE_CITY          MAPSEC_NONE
#define MAPSEC_FALLARBOR_TOWN            MAPSEC_NONE
#define MAPSEC_FIERY_PATH                MAPSEC_NONE
#define MAPSEC_FIERY_PATH2               MAPSEC_NONE
#define MAPSEC_FIVE_ISLAND               MAPSEC_NONE
#define MAPSEC_FIVE_ISLE_MEADOW          MAPSEC_NONE
#define MAPSEC_FOUR_ISLAND               MAPSEC_NONE
#define MAPSEC_GRANITE_CAVE              MAPSEC_NONE
#define MAPSEC_GREEN_PATH                MAPSEC_NONE
#define MAPSEC_ICEFALL_CAVE              MAPSEC_NONE
#define MAPSEC_INSIDE_OF_TRUCK           MAPSEC_NONE
#define MAPSEC_ISLAND_CAVE               MAPSEC_NONE
#define MAPSEC_JAGGED_PASS               MAPSEC_NONE
#define MAPSEC_JAGGED_PASS2              MAPSEC_NONE
#define MAPSEC_KANTO_SAFARI_ZONE         MAPSEC_NONE
#define MAPSEC_KANTO_VICTORY_ROAD        MAPSEC_NONE
#define MAPSEC_KINDLE_ROAD               MAPSEC_NONE
#define MAPSEC_LAVARIDGE_TOWN            MAPSEC_NONE
#define MAPSEC_LIPTOO_CHAMBER            MAPSEC_NONE
#define MAPSEC_LITTLEROOT_TOWN           MAPSEC_NONE
#define MAPSEC_LOST_CAVE                 MAPSEC_NONE
#define MAPSEC_MAGMA_HIDEOUT             MAPSEC_NONE
#define MAPSEC_MARINE_CAVE               MAPSEC_NONE
#define MAPSEC_MAUVILLE_CITY             MAPSEC_NONE
#define MAPSEC_MEMORIAL_PILLAR           MAPSEC_NONE
#define MAPSEC_METEOR_FALLS              MAPSEC_NONE
#define MAPSEC_METEOR_FALLS2             MAPSEC_NONE
#define MAPSEC_MIRAGE_ISLAND             MAPSEC_NONE
#define MAPSEC_MIRAGE_TOWER              MAPSEC_NONE
#define MAPSEC_MONEAN_CHAMBER            MAPSEC_NONE
#define MAPSEC_MT_CHIMNEY                MAPSEC_NONE
#define MAPSEC_MT_EMBER                  MAPSEC_NONE
#define MAPSEC_MT_PYRE                   MAPSEC_NONE
#define MAPSEC_NAVEL_ROCK                MAPSEC_NONE
#define MAPSEC_NAVEL_ROCK_FRLG           MAPSEC_NONE
#define MAPSEC_NEW_MAUVILLE              MAPSEC_NONE
#define MAPSEC_OLDALE_TOWN               MAPSEC_NONE
#define MAPSEC_ONE_ISLAND                MAPSEC_NONE
#define MAPSEC_OUTCAST_ISLAND            MAPSEC_NONE
#define MAPSEC_PACIFIDLOG_TOWN           MAPSEC_NONE
#define MAPSEC_PATTERN_BUSH              MAPSEC_NONE
#define MAPSEC_PETALBURG_CITY            MAPSEC_NONE
#define MAPSEC_PETALBURG_WOODS           MAPSEC_NONE
#define MAPSEC_POKEMON_LEAGUE            MAPSEC_NONE
#define MAPSEC_POKEMON_MANSION           MAPSEC_NONE
#define MAPSEC_RESORT_GORGEOUS           MAPSEC_NONE
#define MAPSEC_RIXY_CHAMBER              MAPSEC_NONE
#define MAPSEC_ROCKET_WAREHOUSE          MAPSEC_NONE
#define MAPSEC_ROUTE_101                 MAPSEC_NONE
#define MAPSEC_ROUTE_102                 MAPSEC_NONE
#define MAPSEC_ROUTE_103                 MAPSEC_NONE
#define MAPSEC_ROUTE_104                 MAPSEC_NONE
#define MAPSEC_ROUTE_105                 MAPSEC_NONE
#define MAPSEC_ROUTE_106                 MAPSEC_NONE
#define MAPSEC_ROUTE_107                 MAPSEC_NONE
#define MAPSEC_ROUTE_108                 MAPSEC_NONE
#define MAPSEC_ROUTE_109                 MAPSEC_NONE
#define MAPSEC_ROUTE_110                 MAPSEC_NONE
#define MAPSEC_ROUTE_111                 MAPSEC_NONE
#define MAPSEC_ROUTE_112                 MAPSEC_NONE
#define MAPSEC_ROUTE_113                 MAPSEC_NONE
#define MAPSEC_ROUTE_114                 MAPSEC_NONE
#define MAPSEC_ROUTE_115                 MAPSEC_NONE
#define MAPSEC_ROUTE_116                 MAPSEC_NONE
#define MAPSEC_ROUTE_117                 MAPSEC_NONE
#define MAPSEC_ROUTE_118                 MAPSEC_NONE
#define MAPSEC_ROUTE_119                 MAPSEC_NONE
#define MAPSEC_ROUTE_120                 MAPSEC_NONE
#define MAPSEC_ROUTE_121                 MAPSEC_NONE
#define MAPSEC_ROUTE_122                 MAPSEC_NONE
#define MAPSEC_ROUTE_123                 MAPSEC_NONE
#define MAPSEC_ROUTE_124                 MAPSEC_NONE
#define MAPSEC_ROUTE_125                 MAPSEC_NONE
#define MAPSEC_ROUTE_126                 MAPSEC_NONE
#define MAPSEC_ROUTE_127                 MAPSEC_NONE
#define MAPSEC_ROUTE_128                 MAPSEC_NONE
#define MAPSEC_ROUTE_129                 MAPSEC_NONE
#define MAPSEC_ROUTE_130                 MAPSEC_NONE
#define MAPSEC_ROUTE_131                 MAPSEC_NONE
#define MAPSEC_ROUTE_132                 MAPSEC_NONE
#define MAPSEC_ROUTE_133                 MAPSEC_NONE
#define MAPSEC_ROUTE_134                 MAPSEC_NONE
#define MAPSEC_ROUTE_23                  MAPSEC_NONE
#define MAPSEC_ROUTE_4_POKECENTER        MAPSEC_NONE
#define MAPSEC_RUIN_VALLEY               MAPSEC_NONE
#define MAPSEC_RUSTBORO_CITY             MAPSEC_NONE
#define MAPSEC_RUSTURF_TUNNEL            MAPSEC_NONE
#define MAPSEC_SCORCHED_SLAB             MAPSEC_NONE
#define MAPSEC_SCUFIB_CHAMBER            MAPSEC_NONE
#define MAPSEC_SEAFLOOR_CAVERN           MAPSEC_NONE
#define MAPSEC_SEALED_CHAMBER            MAPSEC_NONE
#define MAPSEC_SECRET_BASE               MAPSEC_NONE
#define MAPSEC_SEVAULT_CANYON            MAPSEC_NONE
#define MAPSEC_SEVEN_ISLAND              MAPSEC_NONE
#define MAPSEC_SEVII_ISLE_22             MAPSEC_NONE
#define MAPSEC_SEVII_ISLE_23             MAPSEC_NONE
#define MAPSEC_SEVII_ISLE_24             MAPSEC_NONE
#define MAPSEC_SHOAL_CAVE                MAPSEC_NONE
#define MAPSEC_SIX_ISLAND                MAPSEC_NONE
#define MAPSEC_SKY_PILLAR                MAPSEC_NONE
#define MAPSEC_SLATEPORT_CITY            MAPSEC_NONE
#define MAPSEC_SPECIAL_AREA              MAPSEC_NONE
#define MAPSEC_TANOBY_CHAMBERS           MAPSEC_NONE
#define MAPSEC_TANOBY_KEY                MAPSEC_NONE
#define MAPSEC_TANOBY_RUINS              MAPSEC_NONE
#define MAPSEC_TERRA_CAVE                MAPSEC_NONE
#define MAPSEC_THREE_ISLAND              MAPSEC_NONE
#define MAPSEC_THREE_ISLE_PATH           MAPSEC_NONE
#define MAPSEC_THREE_ISLE_PORT           MAPSEC_NONE
#define MAPSEC_TRAINER_TOWER             MAPSEC_NONE
#define MAPSEC_TRAINER_TOWER_2           MAPSEC_NONE
#define MAPSEC_TREASURE_BEACH            MAPSEC_NONE
#define MAPSEC_TWO_ISLAND                MAPSEC_NONE
#define MAPSEC_UNDERWATER_105            MAPSEC_NONE
#define MAPSEC_UNDERWATER_124            MAPSEC_NONE
#define MAPSEC_UNDERWATER_125            MAPSEC_NONE
#define MAPSEC_UNDERWATER_126            MAPSEC_NONE
#define MAPSEC_UNDERWATER_127            MAPSEC_NONE
#define MAPSEC_UNDERWATER_128            MAPSEC_NONE
#define MAPSEC_UNDERWATER_129            MAPSEC_NONE
#define MAPSEC_UNDERWATER_MARINE_CAVE    MAPSEC_NONE
#define MAPSEC_UNDERWATER_SEAFLOOR_CAVERN MAPSEC_NONE
#define MAPSEC_UNDERWATER_SEALED_CHAMBER MAPSEC_NONE
#define MAPSEC_UNDERWATER_SOOTOPOLIS     MAPSEC_NONE
#define MAPSEC_VERDANTURF_TOWN           MAPSEC_NONE
#define MAPSEC_VIAPOIS_CHAMBER           MAPSEC_NONE
#define MAPSEC_WATER_LABYRINTH           MAPSEC_NONE
#define MAPSEC_WATER_PATH                MAPSEC_NONE
#define MAPSEC_WEEPTH_CHAMBER            MAPSEC_NONE

// pe-Hoenn LOCALID stubs (56 total in build log)
// All resolve to 0 (player or first NPC slot) so any object-event lookup
// falls through cleanly. The Hoenn-specific event scripts that use these
// are unreachable in HnS play.
#define LOCALID_CONTESTANT_1             0
#define LOCALID_CONTESTANT_2             0
#define LOCALID_CONTESTANT_3             0
#define LOCALID_CONTESTANT_4             0
#define LOCALID_DEWFORD_NURSE            0
#define LOCALID_EVER_GRANDE_NURSE        0
#define LOCALID_FALLARBOR_MART_CLERK     0
#define LOCALID_FALLARBOR_NURSE          0
#define LOCALID_FARAWAY_ISLAND_MEW       0
#define LOCALID_FORTREE_MART_CLERK       0
#define LOCALID_FORTREE_NURSE            0
#define LOCALID_FRONTIER_MART_CLERK      0
#define LOCALID_FRONTIER_NURSE           0
#define LOCALID_LAVARIDGE_MART_CLERK     0
#define LOCALID_LAVARIDGE_NURSE          0
#define LOCALID_LEAGUE_NURSE             0
#define LOCALID_LILYCOVE_NURSE           0
#define LOCALID_MAUVILLE_MART_CLERK      0
#define LOCALID_MAUVILLE_NURSE           0
#define LOCALID_MOSSDEEP_MART_CLERK      0
#define LOCALID_MOSSDEEP_NURSE           0
#define LOCALID_OLDALE_MART_CLERK        0
#define LOCALID_OLDALE_NURSE             0
#define LOCALID_PACIFIDLOG_NURSE         0
#define LOCALID_PETALBURG_MART_CLERK     0
#define LOCALID_PETALBURG_NURSE          0
#define LOCALID_ROUTE111_GABBY_1         0
#define LOCALID_ROUTE111_GABBY_2         0
#define LOCALID_ROUTE111_GABBY_3         0
#define LOCALID_ROUTE111_PLAYER_FALLING  0
#define LOCALID_ROUTE111_TY_1            0
#define LOCALID_ROUTE111_TY_2            0
#define LOCALID_ROUTE111_TY_3            0
#define LOCALID_ROUTE118_GABBY_1         0
#define LOCALID_ROUTE118_GABBY_2         0
#define LOCALID_ROUTE118_GABBY_3         0
#define LOCALID_ROUTE118_TY_1            0
#define LOCALID_ROUTE118_TY_2            0
#define LOCALID_ROUTE118_TY_3            0
#define LOCALID_ROUTE120_GABBY_1         0
#define LOCALID_ROUTE120_GABBY_2         0
#define LOCALID_ROUTE120_TY_1            0
#define LOCALID_ROUTE120_TY_2            0
#define LOCALID_RUSTBORO_MART_CLERK      0
#define LOCALID_RUSTBORO_NURSE           0
#define LOCALID_SLATEPORT_ENERGY_GURU    0
#define LOCALID_SLATEPORT_MART_CLERK     0
#define LOCALID_SLATEPORT_NURSE          0
#define LOCALID_SOOTOPOLIS_MART_CLERK    0
#define LOCALID_SOOTOPOLIS_NURSE         0
#define LOCALID_TOWER_LOBBY_REPORTER     0
#define LOCALID_TRUCK_BOX_BOTTOM_L       0
#define LOCALID_TRUCK_BOX_BOTTOM_R       0
#define LOCALID_TRUCK_BOX_TOP            0
#define LOCALID_VERDANTURF_MART_CLERK    0
#define LOCALID_VERDANTURF_NURSE         0

// HnS Johto trainer classes — pe doesn't ship these. T3 trainer port aliased
// trainer SLOTS via opponents_hns.h but not classes. Stub to TRAINER_CLASS_PKMN_TRAINER_1
// (0) which is pe's default. Battle dialogue/AI may be slightly off until proper
// class porting; trainer fights still work mechanically.
#define TRAINER_CLASS_FIREBREATHER       TRAINER_CLASS_PKMN_TRAINER_1
#define TRAINER_CLASS_JUGGLER            TRAINER_CLASS_PKMN_TRAINER_1
#define TRAINER_CLASS_KIMONO_GIRL        TRAINER_CLASS_PKMN_TRAINER_1
#define TRAINER_CLASS_POLICEMAN          TRAINER_CLASS_PKMN_TRAINER_1
#define TRAINER_CLASS_PSYCHIC_M          TRAINER_CLASS_PKMN_TRAINER_1
#define TRAINER_CLASS_SAGE               TRAINER_CLASS_PKMN_TRAINER_1
#define TRAINER_CLASS_TEAM_ROCKET        TRAINER_CLASS_PKMN_TRAINER_1

// HnS-specific TRAINER_ENCOUNTER_MUSIC_* (encounter jingles). Pe has HG_*
// prefixed variants but not HnS's bare names. Alias to closest HG match.
#define TRAINER_ENCOUNTER_MUSIC_ROCKET   TRAINER_ENCOUNTER_MUSIC_HG_SUSPICIOUS_1
#define TRAINER_ENCOUNTER_MUSIC_SILVER   TRAINER_ENCOUNTER_MUSIC_HG_BOY_2

// HnS move-name typo bridges (HnS source uses MOVE_SMELLING_SALT, pe uses
// MOVE_SMELLINGSALT). Per pe-CLAUDE.md additive-alias pattern.
#define MOVE_SMELLING_SALT               MOVE_SMELLINGSALT

#endif // GUARD_PE_HOENN_STRIP_STUBS_H
