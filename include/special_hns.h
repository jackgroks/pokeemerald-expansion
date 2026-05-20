#ifndef GUARD_SPECIAL_HNS_H
#define GUARD_SPECIAL_HNS_H

// Externs for HnS-only script-callable special functions. Implementations
// live in src/special_hns.c as no-op stubs; proper ports queued as
// individual post-Phase-6 features. See that file for category mapping.

// tx_randomizer_and_challenges family
u8 GetMaxPartySize(void);
bool8 IsPokecenterChallengeActivated(void);
bool8 IsNuzlockeNicknamingActive(void);
bool8 IsRandomItemsActivated(void);
bool8 IsRandomMovesActivated(void);
void CheckIfChallengesAreActive(void);
void CheckIfRandomizerIsActive(void);
void ToggleShinyColors(void);
u16 RandomItem(void);
u16 RandomItemHidden(void);

// Bug Contest family
void EnterBugContestMode(void);
void ExitBugContestMode(void);
bool8 JudgeBugContestMon(void);
bool8 TransferBugContestMon(void);
bool8 ShowBugContestChosenMon(void);
bool8 RemoveSafariBalls(void);

// Braille fossil / legendary puzzles
bool8 CheckAerodactyl(void);
bool8 CheckCelebi(void);
bool8 CheckHooh(void);
bool8 CheckKabuto(void);
bool8 CheckOmanyte(void);
bool8 CheckTogepi(void);

// HnS stat-editor NPC
void SetHpEvs(void);
void SetAtkEvs(void);
void SetDefEvs(void);
void SetSpdEvs(void);
void SetSpAtkEvs(void);
void SetSpDefEvs(void);
void SetHpIvs(void);
void SetAtkIvs(void);
void SetDefIvs(void);
void SetSpdIvs(void);
void SetSpAtkIvs(void);
void SetSpDefIvs(void);
void SetHpStat(void);
void SetAtkStat(void);
void SetDefStat(void);
void SetSpdStat(void);
void SetSpAtkStat(void);
void SetSpDefStat(void);

// Misc HnS QoL specials
void DoSlidingPuzzle(void);
void NameRival(void);
void HaircutBrother1(void);
void ForceSaveGame(void);
void CreateWonderTradePokemon(void);
void ChangeBoxPokemonNickname(void);
void CheckPkm(void);
void SwitchMonAbility(void);
bool16 TryChangeDeoxysForm(void);
void GetBattleFrontierTutorMoveIndex(void);

#endif // GUARD_SPECIAL_HNS_H
