/* Copyright 2024 d3lilah
 * Utility macros (date, time, etc.)
 */

#include "../d3lilah_qmk.h"

bool process_utility_macros(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;  // Only process on key press
    }

    switch (keycode) {
        case D3L_DATE:
            // Insert current date in YYYY-MM-DD format
            // Note: This is a template - actual date would need RTC or system integration
            SEND_STRING("2024-11-26");
            return false;

        case D3L_TIME:
            // Insert current time in HH:MM format
            // Note: This is a template - actual time would need RTC or system integration
            SEND_STRING("14:30");
            return false;

        default:
            return true;
    }
    return true;
}