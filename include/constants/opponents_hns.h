#ifndef GUARD_CONSTANTS_OPPONENTS_HNS_H
#define GUARD_CONSTANTS_OPPONENTS_HNS_H

/*
 * HnS (Heart & Soul) Johto/Kanto trainer constants — Phase 5-prep R5 (HMS Defiant, 2026-05-19).
 *
 * Trainerproc consumes `src/data/trainers.party` (HnS roster, 484 trainers + 6 RC debug)
 * and emits `src/data/trainers.h` with designated initializers indexed by HnS-authored
 * names (TRAINER_SAYO, TRAINER_FALKNER_1, TRAINER_KIP2, ...). Those names need slot-
 * resolving #defines so trainers.h compiles and HnS scripts (setvar/trainerbattle/etc.)
 * see constant expressions instead of undefined symbols.
 *
 * Of HnS's 864 trainer constants, 490 are referenced by HnS's trainers.party (the rest are
 * enum-only slots). Of those 490 referenced names:
 *   - 155 are already defined in pe's `opponents.h` (same name; slot may or may not match).
 *     Where pe and HnS use the same slot for the same name, no action needed. Where pe
 *     uses a different slot for the same name, pe's #define wins for source references
 *     and the slot HnS chose holds whatever T3+trainerproc placed there from trainers.party.
 *   - 335 are HnS-only and entirely undefined in pe — this file fills that gap.
 *
 * Operationalization: ADDITIVE ALIAS (Operationalization I). HnS #defines are added on
 * top of pe's existing constants. Most HnS slots collide with pe's existing pe-Hoenn
 * slot allocations (e.g., HnS TRAINER_SAYO = 2 lives at the same slot as pe's
 * TRAINER_GRUNT_AQUA_HIDEOUT_1 = 2). This is intentional: trainers.h was overwritten by
 * T3+trainerproc with HnS data at HnS-assigned slots, so pe's old #defines (still intact
 * for C-compile reasons) now point at HnS data. Pe Hoenn code referencing pe's old names
 * is unreachable in HnS Johto play (per pe's native always-compile + runtime-flag-gate
 * pattern + Phase 2 deferral disposition). This file does NOT strip those pe defines —
 * Phase 2 facility cleanup will handle that on demand, facility-by-facility.
 *
 * Schema-additive against `opponents.h`: pe's TRAINERS_COUNT_EMERALD bumps 861 → 864 to
 * accommodate slots 861-863 (Noland/Proton/Kip2 in HnS). MAX_TRAINERS_COUNT_EMERALD
 * stays at 864 — already sufficient. NUM_FLAG_BYTES unchanged.
 *
 * Sorted by HnS slot ascending; one #define per line; collision-checked against
 * `opponents.h` + `opponents_frlg.h` (zero redefinition).
 */

#define TRAINER_SAYO                           2
#define TRAINER_SCOTT                          3
#define TRAINER_SEAN                           4
#define TRAINER_SETH                           5
#define TRAINER_TROY                           6
#define TRAINER_TULLY                          7
#define TRAINER_TYLER                          8
#define TRAINER_ROD                            9
#define TRAINER_TONY                           10
#define TRAINER_ARNOLD                         12
#define TRAINER_VALERIE                        14
#define TRAINER_JOYCE                          15
#define TRAINER_TREVOR                         16
#define TRAINER_ZEKE                           17
#define TRAINER_ZUKI                           18
#define TRAINER_FALKNER_1                      19
#define TRAINER_TODD                           20
#define TRAINER_TOM                            21
#define TRAINER_VERONICA                       22
#define TRAINER_THERESA                        23
#define TRAINER_TIM                            24
#define TRAINER_TIMOTHY                        25
#define TRAINER_FALKNER_2                      26
#define TRAINER_SID                            27
#define TRAINER_STANLY                         28
#define TRAINER_REBECCA                        29
#define TRAINER_DEVIN                          32
#define TRAINER_GRANT                          33
#define TRAINER_CASSIE                         34
#define TRAINER_JEFFREY                        36
#define TRAINER_GRUNT_33                       37
#define TRAINER_NORMAN                         38
#define TRAINER_KRISE                          44
#define TRAINER_GRUNT_16                       45
#define TRAINER_RAYMOND                        46
#define TRAINER_KUNI                           47
#define TRAINER_KYLE                           48
#define TRAINER_LAO                            49
#define TRAINER_LEA_AND_PIA                    50
#define TRAINER_REENA                          51
#define TRAINER_REX                            52
#define TRAINER_RICH                           53
#define TRAINER_RICKY                          54
#define TRAINER_ROB                            55
#define TRAINER_ROBERT                         56
#define TRAINER_CODY                           58
#define TRAINER_ELAINE                         75
#define TRAINER_BARNEY                         90
#define TRAINER_EMMA                           94
#define TRAINER_GIOVANNI                       95
#define TRAINER_ERICK                          101
#define TRAINER_ERIK                           102
#define TRAINER_ERIN                           103
#define TRAINER_ERNEST                         104
#define TRAINER_GRUNT_18                       114
#define TRAINER_KIPP                           115
#define TRAINER_WAI                            116
#define TRAINER_GRUNT_19                       117
#define TRAINER_ELLEN                          118
#define TRAINER_GRUNT_20                       120
#define TRAINER_GRUNT_21                       121
#define TRAINER_GRUNT_22                       122
#define TRAINER_GRUNT_23                       123
#define TRAINER_ARIANA_1                       127
#define TRAINER_ARIANA_2                       132
#define TRAINER_TERU                           146
#define TRAINER_KENNY                          152
#define TRAINER_JO_AND_ZOE                     154
#define TRAINER_JASMINE_1_3                    180
#define TRAINER_JED                            189
#define TRAINER_CINDY                          190
#define TRAINER_STEPHEN                        192
#define TRAINER_STEVE                          193
#define TRAINER_NORTON                         195
#define TRAINER_JENN                           196
#define TRAINER_JEREMY                         197
#define TRAINER_JERRY                          198
#define TRAINER_JESSICA                        199
#define TRAINER_JILL                           200
#define TRAINER_COREY                          203
#define TRAINER_KOGA_2                         204
#define TRAINER_DARYL                          206
#define TRAINER_DAVE                           207
#define TRAINER_DAWN                           208
#define TRAINER_DENIS                          209
#define TRAINER_DIANA                          210
#define TRAINER_KOJI                           211
#define TRAINER_DANIEL                         212
#define TRAINER_NAOKO                          216
#define TRAINER_COLETTE                        217
#define TRAINER_NATHAN                         219
#define TRAINER_NEAL                           220
#define TRAINER_NICK                           221
#define TRAINER_NICO                           222
#define TRAINER_RIVAL_TOTODILE_5               226
#define TRAINER_RIVAL_TOTODILE_6               228
#define TRAINER_RIVAL_TOTODILE_7               229
#define TRAINER_RED_2                          231
#define TRAINER_GAVEN                          238
#define TRAINER_GINA                           239
#define TRAINER_GLENN                          240
#define TRAINER_GORDON                         241
#define TRAINER_GREGG                          242
#define TRAINER_PRYCE_2                        244
#define TRAINER_BENJAMIN                       248
#define TRAINER_LANCE_1                        249
#define TRAINER_LANCE_2                        250
#define TRAINER_RIVAL_CHIKORITA_1              251
#define TRAINER_RIVAL_CHIKORITA_2              252
#define TRAINER_RIVAL_CHIKORITA_3              253
#define TRAINER_DICK                           266
#define TRAINER_PING                           268
#define TRAINER_ARCHER_1                       273
#define TRAINER_ARCHER_4                       276
#define TRAINER_ARCHER_5                       277
#define TRAINER_PETREL_2                       278
#define TRAINER_PROTON_2                       279
#define TRAINER_BLUE_2                         282
#define TRAINER_GRUNT_26                       294
#define TRAINER_LTSURGE                        302
#define TRAINER_ERIKA                          303
#define TRAINER_SABRINA                        304
#define TRAINER_JANINE                         305
#define TRAINER_BLAINE                         306
#define TRAINER_EUGENE                         318
#define TRAINER_RIVAL_TOTODILE_3               326
#define TRAINER_KENNETH                        327
#define TRAINER_FIDEL                          328
#define TRAINER_FRAN                           329
#define TRAINER_FRITZ                          330
#define TRAINER_GAKU                           331
#define TRAINER_MASA                           339
#define TRAINER_CYBIL                          343
#define TRAINER_MATHEW                         346
#define TRAINER_MEG_AND_PEG                    347
#define TRAINER_MEGAN                          348
#define TRAINER_MICHAEL                        349
#define TRAINER_RIVAL_CYNDAQUIL_2              351
#define TRAINER_ABE                            358
#define TRAINER_AL                             360
#define TRAINER_ALFRED                         361
#define TRAINER_ALLAN                          362
#define TRAINER_ANDRE                          363
#define TRAINER_LEWIS                          364
#define TRAINER_LI                             365
#define TRAINER_LISA                           366
#define TRAINER_LIZ                            367
#define TRAINER_LLOYD                          368
#define TRAINER_GARRETT                        374
#define TRAINER_JULIA                          375
#define TRAINER_WILL_2                         376
#define TRAINER_GRUNT_14                       378
#define TRAINER_BRUNO_1                        379
#define TRAINER_BRUNO_2                        380
#define TRAINER_KOGA_1                         383
#define TRAINER_KIM                            384
#define TRAINER_BOB                            387
#define TRAINER_CHUCK_2                        402
#define TRAINER_LOIS                           404
#define TRAINER_GRUNT_15                       408
#define TRAINER_DANNY                          414
#define TRAINER_KENJI                          417
#define TRAINER_JASMINE_2                      427
#define TRAINER_GRUNT_28                       428
#define TRAINER_JAKE                           430
#define TRAINER_JAMES                          431
#define TRAINER_JASON                          432
#define TRAINER_JAY                            433
#define TRAINER_CHUCK_1_2                      442
#define TRAINER_GRUNT_30                       449
#define TRAINER_GRUNT                          464
#define TRAINER_GRUNT_31                       465
#define TRAINER_GRUNT_32                       466
#define TRAINER_PETREL_1                       467
#define TRAINER_ARCHER                         468
#define TRAINER_DARIN                          470
#define TRAINER_KAZU                           474
#define TRAINER_GRUNT_8                        475
#define TRAINER_KEITH                          477
#define TRAINER_KELLY                          478
#define TRAINER_KEN                            479
#define TRAINER_AMY_AND_MAY                    481
#define TRAINER_ANN_AND_ANNE                   482
#define TRAINER_RUTH                           483
#define TRAINER_RYAN                           486
#define TRAINER_MIKE                           492
#define TRAINER_MIKEY                          497
#define TRAINER_MIKI                           498
#define TRAINER_MILLER                         499
#define TRAINER_MITCH                          500
#define TRAINER_CARRIE                         502
#define TRAINER_RIVAL_TOTODILE_4               503
#define TRAINER_CLYDE                          506
#define TRAINER_CHUCK_1                        510
#define TRAINER_GRUNT_27                       511
#define TRAINER_LOLA                           512
#define TRAINER_JASMINE_1                      513
#define TRAINER_LORI                           515
#define TRAINER_MARGRET                        516
#define TRAINER_MARKUS                         517
#define TRAINER_MARTIN                         518
#define TRAINER_THOM_AND_KAE                   520
#define TRAINER_DUFF_AND_EDA                   521
#define TRAINER_CHUCK_1_3                      538
#define TRAINER_JOE                            539
#define TRAINER_CLAIR_1                        541
#define TRAINER_CLAIR_2                        542
#define TRAINER_BROCK                          543
#define TRAINER_MISTY                          544
#define TRAINER_PRYCE_1                        546
#define TRAINER_RUSS                           547
#define TRAINER_RIVAL_CHIKORITA_4              552
#define TRAINER_RIVAL_CHIKORITA_5              555
#define TRAINER_RIVAL_CHIKORITA_6              556
#define TRAINER_RIVAL_CHIKORITA_7              557
#define TRAINER_RIVAL_CYNDAQUIL_1              558
#define TRAINER_GRUNT_3                        559
#define TRAINER_EUSINE                         560
#define TRAINER_GRUNT_4                        562
#define TRAINER_GRUNT_5                        563
#define TRAINER_GRUNT_6                        564
#define TRAINER_GRUNT_7                        565
#define TRAINER_VANCE                          567
#define TRAINER_TOBY                           569
#define TRAINER_TERRELL                        570
#define TRAINER_HARVEY                         574
#define TRAINER_CHOW                           577
#define TRAINER_PRYCE_1_2                      578
#define TRAINER_THEO                           579
#define TRAINER_GRUNT_24                       580
#define TRAINER_WALT                           586
#define TRAINER_WALTER                         587
#define TRAINER_WILTON                         588
#define TRAINER_YOSHI                          589
#define TRAINER_ZACH                           590
#define TRAINER_BLUE                           595
#define TRAINER_BUGSY_1                        596
#define TRAINER_WHITNEY_1                      604
#define TRAINER_RIVAL_TOTODILE_1               605
#define TRAINER_WHITNEY_2                      607
#define TRAINER_MORTY_1                        608
#define TRAINER_MORTY_2                        609
#define TRAINER_JAMIE                          610
#define TRAINER_BRIAN                          613
#define TRAINER_HARRY                          614
#define TRAINER_RIVAL_CYNDAQUIL_4              621
#define TRAINER_RIVAL_CYNDAQUIL_5              622
#define TRAINER_RIVAL_CYNDAQUIL_6              623
#define TRAINER_RIVAL_CYNDAQUIL_7              624
#define TRAINER_RIVAL_TOTODILE_2               625
#define TRAINER_ELLIOT                         626
#define TRAINER_RUSSELL                        648
#define TRAINER_KENDRA                         650
#define TRAINER_JASMINE_1_2                    651
#define TRAINER_RAY                            654
#define TRAINER_CHARLES                        655
#define TRAINER_BAILEY                         670
#define TRAINER_ANDY                           674
#define TRAINER_GRUNT_17                       693
#define TRAINER_JOEL                           694
#define TRAINER_JIMMY                          696
#define TRAINER_BUGSY_2                        697
#define TRAINER_GRUNT_11                       698
#define TRAINER_BRAD                           701
#define TRAINER_GRUNT_10                       705
#define TRAINER_PRYCE_1_3                      707
#define TRAINER_GRUNT_25                       709
#define TRAINER_CARA                           712
#define TRAINER_GRUNT_13                       714
#define TRAINER_JOHNNY                         715
#define TRAINER_RICHARDO                       717
#define TRAINER_NARD                           718
#define TRAINER_JIM                            733
#define TRAINER_WILL_1                         736
#define TRAINER_BRIANA                         737
#define TRAINER_GREGORY                        739
#define TRAINER_GRUNT_29                       740
#define TRAINER_GRUNT_2                        741
#define TRAINER_MARVIN                         742
#define TRAINER_GRUNT_9                        743
#define TRAINER_ETHAN                          746
#define TRAINER_RIVAL_CYNDAQUIL_3              749
#define TRAINER_BILL                           750
#define TRAINER_KATE                           753
#define TRAINER_ARNIE                          757
#define TRAINER_NOB                            759
#define TRAINER_JOHN                           760
#define TRAINER_ETO                            763
#define TRAINER_ETHEL                          764
#define TRAINER_HILLARY                        767
#define TRAINER_DIRK                           774
#define TRAINER_DON                            775
#define TRAINER_DORIS                          776
#define TRAINER_EDNA                           777
#define TRAINER_ETO_2                          778
#define TRAINER_ETO_3                          779
#define TRAINER_QUENTIN                        782
#define TRAINER_QUINN                          783
#define TRAINER_RACHAEL                        784
#define TRAINER_RALPH                          785
#define TRAINER_CARLENE                        802
#define TRAINER_JIN                            803
#define TRAINER_BRET                           805
#define TRAINER_SAM                            808
#define TRAINER_BROOKE                         812
#define TRAINER_BURT                           813
#define TRAINER_CALVIN                         814
#define TRAINER_CAMERON                        815
#define TRAINER_HAL                            816
#define TRAINER_HANK                           817
#define TRAINER_HAROLD                         818
#define TRAINER_HARRIS                         819
#define TRAINER_HORTON                         828
#define TRAINER_IAN                            829
#define TRAINER_IRWIN                          830
#define TRAINER_ISSAC                          831
#define TRAINER_OTIS                           832
#define TRAINER_PARRY                          833
#define TRAINER_PATON                          834
#define TRAINER_PETER                          835
#define TRAINER_RON                            840
#define TRAINER_ROSS                           841
#define TRAINER_ROXANNE                        842
#define TRAINER_ROY                            843
#define TRAINER_BORIS                          849
#define TRAINER_NICOLE                         850
#define TRAINER_LUCY_BF_BRAIN                  853
#define TRAINER_BRANDON_BF_BRAIN               854
#define TRAINER_GRUNT_12                       855
#define TRAINER_TUCKER_BF_BRAIN                856
#define TRAINER_ANABEL_BF_BRAIN                857
#define TRAINER_GRETA_BF_BRAIN                 858
#define TRAINER_SPENSER_BF_BRAIN               860
#define TRAINER_NOLAND_BF_BRAIN                861
#define TRAINER_PROTON_1                       862

/* Phase 4 R6c extension (HMS Plymouth, 2026-05-20): +3 slots for HnS
 * E4-rematch and Steven-rematch trainers referenced from
 * data/maps/EverGrandeCity_DrakesRoom and data/maps/MeteorFalls_StevensCave.
 * TRAINERS_COUNT_EMERALD bumps 864 → 867; MAX_TRAINERS_COUNT_EMERALD stays
 * at 864 in opponents.h until the next NUM_FLAG_BYTES re-check.
 * trainers.party will populate these slots in a future authoring pass;
 * for now the slots exist purely to resolve the script-side undefs.
 */
#define TRAINER_KIP                            863
#define TRAINER_KIP2                           864
#define TRAINER_STEVEN2                        865

#endif  // GUARD_CONSTANTS_OPPONENTS_HNS_H
