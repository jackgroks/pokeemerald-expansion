// Phase 2 minimal-strip: FRLG Sevii Islands are not part of HnS Johto/Kanto.
// Original sKantoSubregionMapsecs classified Kanto MAPSECs into Sevii
// subregions for region-map purposes. HnS doesn't ship Sevii content, so
// every Kanto MAPSEC reports as KANTO_SUBREGION_KANTO. The Sevii MAPSEC
// constants (MAPSEC_ONE_ISLAND..MAPSEC_VIAPOIS_CHAMBER) were dropped by T9.

#include "global.h"
#include "regions.h"

enum KantoSubRegion GetKantoSubregion(u32 mapSecId)
{
    (void)mapSecId;
    return KANTO_SUBREGION_KANTO;
}
