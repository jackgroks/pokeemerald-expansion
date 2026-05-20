@ Phase 4 R6c-followup-3 (2026-05-20): admiral-direct stubs for 12
@ BattleFrontier text symbols referenced by pe engine tables but
@ orphaned by Phase 2 minimal-strip. These are link-time-only stubs;
@ proper port (or proper strip of the consuming engine tables in
@ src/data/battle_frontier/battle_frontier_exchange_corner.h and
@ gNatureGirlMessages in src/pokemon.c) is queued as the deferred Phase 2
@ facility-cleanup feature. Until then, every reference resolves to an
@ empty string; the engine tables compile and link, but selecting the
@ associated game item or NPC dialog displays a blank message. Both
@ surfaces (Battle Frontier ExchangeServiceCorner + Lounge5) are
@ pe-Hoenn-unreachable in HnS Johto/Kanto play, so user impact is zero.

BattleFrontier_ExchangeServiceCorner_Text_KissCushionDesc::
	.string "$"

BattleFrontier_ExchangeServiceCorner_Text_KissPosterDesc::
	.string "$"

BattleFrontier_ExchangeServiceCorner_Text_SmoochumDollDesc::
	.string "$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighAttackLow::
	.string "$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighDefenseLow::
	.string "$"

BattleFrontier_Lounge5_Text_NatureGirlAttackHighSupportLow::
	.string "$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighAttackLow::
	.string "$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighDefenseLow::
	.string "$"

BattleFrontier_Lounge5_Text_NatureGirlDefenseHighSupportLow::
	.string "$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighAttackLow::
	.string "$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighDefenseLow::
	.string "$"

BattleFrontier_Lounge5_Text_NatureGirlSupportHighSupportLow::
	.string "$"
