@ HnS-only script-callable specials, additively appended to gSpecials[].
@
@ This file is .include'd from data/specials.inc at the bottom of the
@ gSpecials[] table. The def_special macro auto-generates SPECIAL_<Name>
@ constants via assembler .set directives, so no separate enum header is
@ required. C implementations live in src/special_hns.c (no-op stubs);
@ proper ports queued post-Phase-6.
@
@ Ordering matches r6_specials_needed.txt for easy audit. Anchored at the
@ end of pe's existing 641-entry table; HnS-only constants resolve to
@ slot numbers >= 641.

	def_special ChangeBoxPokemonNickname
	def_special CheckAerodactyl
	def_special CheckCelebi
	def_special CheckHooh
	def_special CheckIfChallengesAreActive
	def_special CheckIfRandomizerIsActive
	def_special CheckKabuto
	def_special CheckOmanyte
	def_special CheckPkm
	def_special CheckTogepi
	def_special CreateWonderTradePokemon
	def_special DoSlidingPuzzle
	def_special EnterBugContestMode
	def_special ExitBugContestMode
	def_special ForceSaveGame
	def_special GetBattleFrontierTutorMoveIndex
	def_special GetMaxPartySize
	def_special HaircutBrother1
	def_special IsNuzlockeNicknamingActive
	def_special IsPokecenterChallengeActivated
	def_special IsRandomItemsActivated
	def_special IsRandomMovesActivated
	def_special JudgeBugContestMon
	def_special NameRival
	def_special RandomItem
	def_special RandomItemHidden
	def_special RemoveSafariBalls
	def_special SetAtkEvs
	def_special SetAtkIvs
	def_special SetAtkStat
	def_special SetDefEvs
	def_special SetDefIvs
	def_special SetDefStat
	def_special SetHpEvs
	def_special SetHpIvs
	def_special SetHpStat
	def_special SetSpAtkEvs
	def_special SetSpAtkIvs
	def_special SetSpAtkStat
	def_special SetSpDefEvs
	def_special SetSpDefIvs
	def_special SetSpDefStat
	def_special SetSpdEvs
	def_special SetSpdIvs
	def_special SetSpdStat
	def_special ShowBugContestChosenMon
	def_special SwitchMonAbility
	def_special ToggleShinyColors
	def_special TransferBugContestMon
	def_special TryChangeDeoxysForm
