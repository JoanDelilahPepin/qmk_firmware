/* Copyright 2024 d3lilah
 * User-wide configuration
 */

#pragma once

// Tapping configuration
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
// IGNORE_MOD_TAP_INTERRUPT is now default behavior, removed

// VIA configuration maximums
#ifdef VIA_ENABLE
    // Already defined in keyboard config, but good to have here for reference
    // #define DYNAMIC_KEYMAP_LAYER_COUNT 8
    // #define DYNAMIC_KEYMAP_MACRO_COUNT 32
#endif

// RGB configuration (if using RGB keyboards)
#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_KEYPRESSES
    #define RGB_DISABLE_WHEN_USB_SUSPENDED
#endif

// Macro timing adjustments
#define MACRO_TIMER 5