/* Copyright 2024 d3lilah
 * Text editing and manipulation macros
 */

#include "../d3lilah_qmk.h"

bool process_text_editing_macros(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;  // Only process on key press
    }

    switch (keycode) {
        // === LINE OPERATIONS ===
        case D3L_CUT_LINE_S:
            // Select to start of line and cut
            tap_code16(LSFT(KC_HOME));
            tap_code16(LGUI(KC_X));
            return false;

        case D3L_CUT_LINE_E:
            // Select to end of line and cut
            tap_code16(LSFT(KC_END));
            tap_code16(LGUI(KC_X));
            return false;

        // === WORD OPERATIONS ===
        case D3L_CUT_WORD_P:
            // Select previous word and cut (macOS: Alt+Shift+Left)
            tap_code16(LALT(LSFT(KC_LEFT)));
            tap_code16(LGUI(KC_X));
            return false;

        case D3L_CUT_WORD_N:
            // Select next word and cut (macOS: Alt+Shift+Right)
            tap_code16(LALT(LSFT(KC_RIGHT)));
            tap_code16(LGUI(KC_X));
            return false;

        // === PARAGRAPH OPERATIONS ===
        case D3L_CUT_PARA:
            // Select current paragraph and cut
            tap_code16(LALT(KC_UP));           // Move to paragraph start
            tap_code16(LALT(LSFT(KC_DOWN)));   // Select to paragraph end
            tap_code16(LGUI(KC_X));
            return false;

        // === WRAP OPERATIONS ===
        case D3L_WRAP_QUOTE:
            // Cut selection and wrap in quotes
            tap_code16(LGUI(KC_X));
            wait_ms(100);
            SEND_STRING("\"");
            wait_ms(100);
            tap_code16(LGUI(KC_V));
            wait_ms(100);
            SEND_STRING("\"");
            return false;

        case D3L_WRAP_PAREN:
            // Cut selection and wrap in parentheses
            tap_code16(LGUI(KC_X));
            wait_ms(100);
            SEND_STRING("(");
            wait_ms(100);
            tap_code16(LGUI(KC_V));
            wait_ms(100);
            SEND_STRING(")");
            return false;

        case D3L_WRAP_BRACK:
            // Cut selection and wrap in brackets
            tap_code16(LGUI(KC_X));
            wait_ms(100);
            SEND_STRING("[");
            wait_ms(100);
            tap_code16(LGUI(KC_V));
            wait_ms(100);
            SEND_STRING("]");
            return false;

        default:
            return true;
    }
    return true;
}