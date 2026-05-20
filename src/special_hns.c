// HnS-only script-callable special functions, ported as no-op stubs.
//
// This file provides linkage for the 50 HnS-only SPECIAL_* symbols referenced
// by HnS-imported scripts (data/scripts/**/*.inc + map.json scripts) that have
// no pe-expansion equivalent. The stubs return safe defaults so the link
// stage resolves and scripts that branch on these return values fall through
// to their non-feature path (no bug contest, no randomizer, etc.).
//
// Categories:
//   - tx_randomizer_and_challenges: full HnS feature, returns "feature off".
//   - Bug Contest: full HnS minigame, no-op + return "transfer/judge ok".
//   - Sliding puzzle (Mirage Tower / Stark Mountain analogue): no-op.
//   - Stat-Editor NPC (HnS Goldenrod Pokecenter): no-op EV/IV/stat setters.
//   - Braille fossil/legendary puzzles (HnS variant): return "puzzle not solved".
//   - Misc HnS QoL: NameRival, HaircutBrother1, ChangeBoxPokemonNickname,
//     CreateWonderTradePokemon, ForceSaveGame, CheckPkm, ToggleShinyColors,
//     SwitchMonAbility, GetBattleFrontierTutorMoveIndex, TryChangeDeoxysForm.
//
// Each stub keeps the HnS C signature so the link table resolves. Proper
// ports are queued post-Phase-6 as individual feature branches per family
// (e.g., feat/port-hns-bug-contest, feat/port-hns-tx-randomizer).

#include "global.h"
#include "special_hns.h"

// ---------------------------------------------------------------------------
// tx_randomizer_and_challenges family
// ---------------------------------------------------------------------------

u8 GetMaxPartySize(void)
{
    return PARTY_SIZE;
}

bool8 IsPokecenterChallengeActivated(void)
{
    return FALSE;
}

bool8 IsNuzlockeNicknamingActive(void)
{
    return FALSE;
}

bool8 IsRandomItemsActivated(void)
{
    return FALSE;
}

bool8 IsRandomMovesActivated(void)
{
    return FALSE;
}

void CheckIfChallengesAreActive(void)
{
    // no-op stub. Real port: sets gSpecialVar_Result to TRUE/FALSE based on
    // gSaveBlock_TX_Challenges state.
}

void CheckIfRandomizerIsActive(void)
{
    // no-op stub.
}

void ToggleShinyColors(void)
{
    // no-op stub. Real port: flips shiny palette flag for randomizer mode.
}

u16 RandomItem(void)
{
    return 0;
}

u16 RandomItemHidden(void)
{
    return 0;
}

// ---------------------------------------------------------------------------
// Bug Contest family (HnS National Park minigame)
// ---------------------------------------------------------------------------

void EnterBugContestMode(void)
{
    // no-op stub.
}

void ExitBugContestMode(void)
{
    // no-op stub.
}

bool8 JudgeBugContestMon(void)
{
    return FALSE;
}

bool8 TransferBugContestMon(void)
{
    return FALSE;
}

bool8 ShowBugContestChosenMon(void)
{
    return FALSE;
}

bool8 RemoveSafariBalls(void)
{
    return FALSE;
}

// ---------------------------------------------------------------------------
// Braille fossil / legendary puzzles (HnS Whirl Islands, Cinnabar variant)
// ---------------------------------------------------------------------------

bool8 CheckAerodactyl(void)
{
    return FALSE;
}

bool8 CheckCelebi(void)
{
    return FALSE;
}

bool8 CheckHooh(void)
{
    return FALSE;
}

bool8 CheckKabuto(void)
{
    return FALSE;
}

bool8 CheckOmanyte(void)
{
    return FALSE;
}

bool8 CheckTogepi(void)
{
    return FALSE;
}

// ---------------------------------------------------------------------------
// HnS stat-editor NPC (Goldenrod Pokecenter analogue)
// All set the chosen mons stat to gSpecialVar_0x8005 / gSpecialVar_0x8006.
// Stubs no-op; later port can call CalculateMonStats after setting.
// ---------------------------------------------------------------------------

void SetHpEvs(void)  {}
void SetAtkEvs(void) {}
void SetDefEvs(void) {}
void SetSpdEvs(void) {}
void SetSpAtkEvs(void) {}
void SetSpDefEvs(void) {}

void SetHpIvs(void)  {}
void SetAtkIvs(void) {}
void SetDefIvs(void) {}
void SetSpdIvs(void) {}
void SetSpAtkIvs(void) {}
void SetSpDefIvs(void) {}

void SetHpStat(void)  {}
void SetAtkStat(void) {}
void SetDefStat(void) {}
void SetSpdStat(void) {}
void SetSpAtkStat(void) {}
void SetSpDefStat(void) {}

// ---------------------------------------------------------------------------
// Misc HnS QoL specials
// ---------------------------------------------------------------------------

void DoSlidingPuzzle(void)
{
    // no-op stub. Real port: launches HnS sliding puzzle minigame from
    // src/sliding_puzzle.c (Mirage Tower / Stark Mountain analogue).
}

void NameRival(void)
{
    // no-op stub. Real port: invokes naming-screen UI for rival name token.
    // Queued as long-term goal in recap (rival-naming UX event).
}

void HaircutBrother1(void)
{
    // no-op stub. Real port: Goldenrod haircut-brothers friendship boost.
}

void ForceSaveGame(void)
{
    // no-op stub. Real port: forced TrySavingData() invocation; safe to
    // leave as no-op since auto-saves still happen at heal/PC interactions.
}

void CreateWonderTradePokemon(void)
{
    // no-op stub. Real port: HnS wonder-trade NPC handler.
}

void ChangeBoxPokemonNickname(void)
{
    // no-op stub. Real port: invokes naming-screen UI for stored-box mon.
}

void CheckPkm(void)
{
    // no-op stub. Real port: gSpecialVar_Result set based on Pokemon-check
    // criterion (HnS Pokeathlon / special-event entry gate).
}

void SwitchMonAbility(void)
{
    // no-op stub. Real port: toggles ability slot on chosen party mon
    // (HnS Ability Capsule analogue, pre-Gen-6).
}

bool16 TryChangeDeoxysForm(void)
{
    return FALSE;
}

void GetBattleFrontierTutorMoveIndex(void)
{
    // no-op stub. Real port: sets gSpecialVar_Result to tutor-move index
    // based on gSpecialVar_0x8004 (HnS Battle Frontier move-tutor surface).
}
