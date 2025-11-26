/* Copyright 2024 d3lilah
 * Markdown and writing-related macros
 */

#include "../d3lilah_qmk.h"

bool process_markdown_macros(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;  // Only process on key press
    }

    switch (keycode) {
        case D3L_MD_H1:
            tap_code(KC_HOME);
            SEND_STRING("# ");
            return false;

        case D3L_MD_H2:
            tap_code(KC_HOME);
            SEND_STRING("## ");
            return false;

        case D3L_MD_H3:
            tap_code(KC_HOME);
            SEND_STRING("### ");
            return false;

        case D3L_BOLD:
            tap_code16(LGUI(KC_B));
            return false;

        case D3L_ITALIC:
            tap_code16(LGUI(KC_I));
            return false;

        case D3L_CLR_FMT:
            // Clear formatting (Obsidian: Cmd+Shift+Ctrl+K)
            tap_code16(LGUI(LSFT(LCTL(KC_K))));
            return false;

        case D3L_EM_DASH:
            // Em dash with spaces on macOS
            SEND_STRING(" ");
            tap_code16(LALT(LSFT(KC_MINUS)));
            SEND_STRING(" ");
            return false;

        case D3L_TODO:
            // Insert todo checkbox for Obsidian/Markdown
            SEND_STRING("- [ ] ");
            return false;

        default:
            return true;
    }
    return true;
}