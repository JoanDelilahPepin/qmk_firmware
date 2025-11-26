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

#include "d3lilah_qmk.h"

// Main macro processing function
bool process_record_d3lilah(uint16_t keycode, keyrecord_t *record) {
    // Only process our custom keycodes
    if (keycode < D3L_MD_H1 || keycode >= D3L_MAX_KEYCODE) {
        return true;
    }

    // Route to appropriate handler based on keycode range
    if (keycode >= D3L_MD_H1 && keycode <= D3L_TODO) {
        return process_markdown_macros(keycode, record);
    } else if (keycode >= D3L_CUT_LINE_S && keycode <= D3L_WRAP_BRACK) {
        return process_text_editing_macros(keycode, record);
    } else if (keycode >= D3L_OBS_DAILY && keycode <= D3L_LGC_MARKER) {
        return process_app_macros(keycode, record);
    } else if (keycode >= D3L_DATE && keycode <= D3L_TIME) {
        return process_utility_macros(keycode, record);
    }

    return true;
}