// Phase 2 minimal-strip: pe-Hoenn landmark system stubbed for HnS Johto/Kanto.
//
// Original sLandmarkLists referenced 50+ Hoenn-specific MAPSEC values (ROUTE_103..134,
// MT_CHIMNEY, etc.) dropped by Phase 3's T9 emission. The pe-Hoenn region's "landmark
// hover" pokenav feature is not reachable in HnS play; this stub returns NULL for
// every lookup so the consumer (pokenav_region_map.c) falls through cleanly.
//
// When Johto/Kanto-side landmark coverage is desired, populate sLandmarkLists with
// HnS-region MAPSECs (MAPSEC_ROUTE_1..28, MAPSEC_ROUTE_29..48, etc.) and the matching
// Landmark_* entries adjacent.

#include "global.h"
#include "constants/region_map_sections.h"
#include "landmark.h"

const u8 *GetLandmarkName(mapsec_u8_t mapSection, u8 id, u8 count)
{
    (void)mapSection;
    (void)id;
    (void)count;
    return NULL;
}
