#ifndef GUARD_CONSTANTS_METATILE_HNS_H
#define GUARD_CONSTANTS_METATILE_HNS_H

/*
 * HnS (Heart & Soul) Johto/Kanto metatile constants - Phase 4 R6c
 * (HMS Plymouth, 2026-05-20).
 *
 * HnS authored metatile-label #defines for its bespoke tilesets that
 * pe-expansion does not have. Only one such symbol surfaces in the
 * post-R6b residual:
 *
 *   METATILE_R26_21_Broken_Window - referenced from
 *   data/maps/NewBarkTown_Lab/scripts.inc:381 in a setmetatile call
 *   that's part of the lab-window-shattering cinematic on Day 1.
 *
 * Stubbed to 0 (METATILE_NONE-equivalent); the cinematic will visually
 * show the default tile until the matching HnS-side tileset is ported
 * and the metatile re-pointed to the real broken-window tile index.
 *
 * Wired into the metatile namespace by include from constants/metatile_labels.h
 * after the vanilla METATILE_RSMossdeepGym block.
 */

#define METATILE_R26_21_Broken_Window  0

#endif // GUARD_CONSTANTS_METATILE_HNS_H
