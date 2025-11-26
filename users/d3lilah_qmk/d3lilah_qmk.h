/* Copyright 2024 d3lilah
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#include "quantum.h"

// Custom keycodes using QK_KB range for VIA compatibility
// VIA supports QK_KB_0 through QK_KB_31 (32 custom keycodes)
enum d3lilah_custom_keycodes {
    // === MARKDOWN/WRITING (0-7) ===
    D3L_MD_H1 = QK_KB_0,        // Markdown Header 1
    D3L_MD_H2,                  // Markdown Header 2
    D3L_MD_H3,                  // Markdown Header 3
    D3L_BOLD,                   // Bold text (Cmd+B)
    D3L_ITALIC,                 // Italic text (Cmd+I)
    D3L_CLR_FMT,                // Clear formatting
    D3L_EM_DASH,                // Em dash with spaces
    D3L_TODO,                   // Todo checkbox

    // === TEXT EDITING (8-15) ===
    D3L_CUT_LINE_S,             // Cut to line start
    D3L_CUT_LINE_E,             // Cut to line end
    D3L_CUT_WORD_P,             // Cut previous word
    D3L_CUT_WORD_N,             // Cut next word
    D3L_CUT_PARA,               // Cut paragraph
    D3L_WRAP_QUOTE,             // Wrap in quotes
    D3L_WRAP_PAREN,             // Wrap in parentheses
    D3L_WRAP_BRACK,             // Wrap in brackets

    // === OBSIDIAN (16-19) ===
    D3L_OBS_DAILY,              // Obsidian daily note
    D3L_OBS_SEARCH,             // Obsidian search
    D3L_OBS_GRAPH,              // Obsidian graph view
    D3L_OBS_CMD,                // Obsidian command palette

    // === GOOGLE DOCS (20-23) ===
    D3L_GDOC_H1,                // Google Docs Header 1
    D3L_GDOC_H2,                // Google Docs Header 2
    D3L_GDOC_H3,                // Google Docs Header 3
    D3L_GDOC_NORM,              // Google Docs Normal text

    // === LOGIC PRO (24-29) ===
    D3L_LGC_SPLIT,              // Logic Pro split region
    D3L_LGC_JOIN,               // Logic Pro join regions
    D3L_LGC_FADE,               // Logic Pro crossfade
    D3L_LGC_COLOR,              // Logic Pro color regions
    D3L_LGC_BOUNCE,             // Logic Pro bounce
    D3L_LGC_MARKER,             // Logic Pro add marker

    // === UTILITY (30-31) ===
    D3L_DATE,                   // Insert current date
    D3L_TIME,                   // Insert current time

    // Mark the end of our custom keycodes
    D3L_MAX_KEYCODE
};

// Function prototypes
bool process_record_d3lilah(uint16_t keycode, keyrecord_t *record);

// Module handlers
bool process_markdown_macros(uint16_t keycode, keyrecord_t *record);
bool process_text_editing_macros(uint16_t keycode, keyrecord_t *record);
bool process_app_macros(uint16_t keycode, keyrecord_t *record);
bool process_utility_macros(uint16_t keycode, keyrecord_t *record);