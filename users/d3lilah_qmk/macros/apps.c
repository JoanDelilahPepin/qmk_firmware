/* Copyright 2024 d3lilah
 * Application-specific macros (Obsidian, Google Docs, Logic Pro)
 */

#include "../d3lilah_qmk.h"

bool process_app_macros(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;  // Only process on key press
    }

    switch (keycode) {
        // === OBSIDIAN ===
        case D3L_OBS_DAILY:
            // Open daily note (Cmd+Shift+D)
            tap_code16(LGUI(LSFT(KC_D)));
            return false;

        case D3L_OBS_SEARCH:
            // Quick search (Cmd+O)
            tap_code16(LGUI(KC_O));
            return false;

        case D3L_OBS_GRAPH:
            // Graph view (Cmd+G)
            tap_code16(LGUI(KC_G));
            return false;

        case D3L_OBS_CMD:
            // Command palette (Cmd+P)
            tap_code16(LGUI(KC_P));
            return false;

        // === GOOGLE DOCS ===
        case D3L_GDOC_H1:
            // Google Docs Header 1 (Cmd+Alt+1)
            tap_code16(LGUI(LALT(KC_1)));
            return false;

        case D3L_GDOC_H2:
            // Google Docs Header 2 (Cmd+Alt+2)
            tap_code16(LGUI(LALT(KC_2)));
            return false;

        case D3L_GDOC_H3:
            // Google Docs Header 3 (Cmd+Alt+3)
            tap_code16(LGUI(LALT(KC_3)));
            return false;

        case D3L_GDOC_NORM:
            // Google Docs Normal text (Cmd+Alt+0)
            tap_code16(LGUI(LALT(KC_0)));
            return false;

        // === LOGIC PRO ===
        case D3L_LGC_SPLIT:
            // Split regions at playhead (Cmd+T)
            tap_code16(LGUI(KC_T));
            return false;

        case D3L_LGC_JOIN:
            // Join regions (Cmd+J)
            tap_code16(LGUI(KC_J));
            return false;

        case D3L_LGC_FADE:
            // Crossfade (X)
            tap_code(KC_X);
            return false;

        case D3L_LGC_COLOR:
            // Color regions (Alt+C)
            tap_code16(LALT(KC_C));
            return false;

        case D3L_LGC_BOUNCE:
            // Bounce in place (Ctrl+B)
            tap_code16(LCTL(KC_B));
            return false;

        case D3L_LGC_MARKER:
            // Create marker (Alt+')
            tap_code16(LALT(KC_QUOTE));
            return false;

        default:
            return true;
    }
    return true;
}