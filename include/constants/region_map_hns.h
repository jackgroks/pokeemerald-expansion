#ifndef GUARD_CONSTANTS_REGION_MAP_HNS_H
#define GUARD_CONSTANTS_REGION_MAP_HNS_H

/*
 * HnS (Heart & Soul) Johto/Kanto MAPSEC additive stubs - Phase 4 R5c
 * (HMS Diamond II, 2026-05-20).
 *
 * HnS authored 13 region-map sections that pe-side `region_map_sections.h` does
 * not enumerate and that `pe_hoenn_strip_stubs.h` does not pre-stub. These are
 * referenced by HnS map-header data (MapHeader.regionMapSectionId) and by HnS
 * scripts via `setrespawn`, region-map UI, and dex-area display paths.
 *
 * The pe-side enum at region_map_sections.h is auto-generated from
 * src/data/region_map/region_map_sections.json (see banner at the top of the
 * generated file). Adding HnS sections to the JSON would re-emit the enum
 * additively; doing it via macro stubs here is the lighter equivalent until
 * the T-tooling extension lands.
 *
 * Operationalization: ADDITIVE STUB to MAPSEC_NONE (mirrors the pattern in
 * pe_hoenn_strip_stubs.h for pe-Hoenn MAPSECs that survived T9 dropping but
 * stayed referenced by pe-Hoenn battle/contest/region_map code). Stubbing to
 * MAPSEC_NONE means any equality check (`if (regionMapSectionId == MAPSEC_X)`)
 * fails for the HnS map carrying that section; the UI sees the section as
 * "none" until a proper port lands. Each affected HnS map can run mechanically
 * (battle, NPC interaction, transitions) but its region-map / dex-area /
 * setrespawn UX is degraded until then.
 *
 * Surfaces stubbed:
 *   - CAVE_OF_SHOCK / CAVE_OF_SHOCK2 - HnS post-game cave dungeon (two area IDs).
 *   - DRACO_CHAMBER / DRACO_CHAMBER2 - HnS Blackthorn dragon shrine (two IDs).
 *   - EMBEDDED_TOWER2 - HnS second-floor area of the Embedded Tower wing.
 *   - SAFARI_ZONE_AREA1..AREA6 - HnS Johto Safari Zone six-zone layout.
 *     pe-Hoenn has MAPSEC_SAFARI_ZONE (single section); HnS subdivides into 6.
 *   - SEVII_ISLE_6 / SEVII_ISLE_7 - HnS Kanto post-game island slots (pe-FRLG
 *     ships 22/23/24; HnS additionally references 6/7).
 *
 * Schema-additive against region_map_sections.h: zero existing enum entries
 * touched; MAPSEC_COUNT not bumped. The auto-generated enum file is unchanged.
 *
 * Upstream-merge rule: if T-tooling later extends the source JSON with these
 * sections, the re-emitted enum will collide with these macros - drop the
 * affected #define here at that time and let the enum entry take over.
 */

#define MAPSEC_CAVE_OF_SHOCK         MAPSEC_NONE
#define MAPSEC_CAVE_OF_SHOCK2        MAPSEC_NONE
#define MAPSEC_DRACO_CHAMBER         MAPSEC_NONE
#define MAPSEC_DRACO_CHAMBER2        MAPSEC_NONE
#define MAPSEC_EMBEDDED_TOWER2       MAPSEC_NONE
#define MAPSEC_SAFARI_ZONE_AREA1     MAPSEC_NONE
#define MAPSEC_SAFARI_ZONE_AREA2     MAPSEC_NONE
#define MAPSEC_SAFARI_ZONE_AREA3     MAPSEC_NONE
#define MAPSEC_SAFARI_ZONE_AREA4     MAPSEC_NONE
#define MAPSEC_SAFARI_ZONE_AREA5     MAPSEC_NONE
#define MAPSEC_SAFARI_ZONE_AREA6     MAPSEC_NONE
#define MAPSEC_SEVII_ISLE_6          MAPSEC_NONE
#define MAPSEC_SEVII_ISLE_7          MAPSEC_NONE

#endif // GUARD_CONSTANTS_REGION_MAP_HNS_H
