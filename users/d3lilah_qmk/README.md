# D3lilah's QMK/VIA Macro Implementation

A reference implementation for porting Vial macros to QMK with full VIA support, featuring 32 custom keycodes organized into modular categories.

## Overview

This user directory demonstrates how to:
- Port macros from Vial to QMK using VIA-compatible custom keycodes
- Organize macros into modular, reusable components
- Create descriptive VIA interfaces for custom macros
- Maintain cross-keyboard compatibility

## Features

### 32 Custom Macros Organized by Category

#### Markdown/Writing (8 macros)
- `D3L_MD_H1` - Markdown Header 1
- `D3L_MD_H2` - Markdown Header 2
- `D3L_MD_H3` - Markdown Header 3
- `D3L_BOLD` - Bold text (Cmd+B)
- `D3L_ITALIC` - Italic text (Cmd+I)
- `D3L_CLR_FMT` - Clear formatting
- `D3L_EM_DASH` - Em dash with spaces
- `D3L_TODO` - Todo checkbox `- [ ] `

#### Text Editing (8 macros)
- `D3L_CUT_LINE_S` - Cut to line start
- `D3L_CUT_LINE_E` - Cut to line end
- `D3L_CUT_WORD_P` - Cut previous word
- `D3L_CUT_WORD_N` - Cut next word
- `D3L_CUT_PARA` - Cut paragraph
- `D3L_WRAP_QUOTE` - Wrap selection in quotes
- `D3L_WRAP_PAREN` - Wrap selection in parentheses
- `D3L_WRAP_BRACK` - Wrap selection in brackets

#### Application Shortcuts (14 macros)
**Obsidian:**
- `D3L_OBS_DAILY` - Daily note
- `D3L_OBS_SEARCH` - Quick search
- `D3L_OBS_GRAPH` - Graph view
- `D3L_OBS_CMD` - Command palette

**Google Docs:**
- `D3L_GDOC_H1` - Header 1
- `D3L_GDOC_H2` - Header 2
- `D3L_GDOC_H3` - Header 3
- `D3L_GDOC_NORM` - Normal text

**Logic Pro:**
- `D3L_LGC_SPLIT` - Split region
- `D3L_LGC_JOIN` - Join regions
- `D3L_LGC_FADE` - Crossfade
- `D3L_LGC_COLOR` - Color regions
- `D3L_LGC_BOUNCE` - Bounce in place
- `D3L_LGC_MARKER` - Add marker

#### Utility (2 macros)
- `D3L_DATE` - Insert current date
- `D3L_TIME` - Insert current time

## Architecture

```
users/d3lilah_qmk/
├── d3lilah_qmk.h          # Keycode definitions using QK_KB range
├── d3lilah_qmk.c          # Main routing logic
├── config.h               # User configuration
├── rules.mk               # Build rules
├── macros/
│   ├── markdown.c         # Markdown/writing macros
│   ├── text_editing.c     # Text manipulation macros
│   ├── apps.c            # Application-specific macros
│   └── utility.c         # Utility macros
└── README.md             # This file
```

## Technical Details

### VIA Compatibility
- Uses `QK_KB_0` through `QK_KB_31` keycode range for VIA compatibility
- All 32 slots utilized for maximum functionality
- Custom keycodes appear in VIA's "CUSTOM" tab with descriptive names

### Modular Design
- Separate handler functions for each macro category
- Easy to extend or modify specific categories
- Clean separation of concerns

### Cross-Platform
- Primary support for macOS shortcuts
- Can be adapted for Windows/Linux with conditional compilation

## Integration Guide

### 1. Add to Your Keymap

In your keymap's `rules.mk`:
```make
USER_NAME := d3lilah_qmk
```

In your keymap's `keymap.c`:
```c
#include "d3lilah_qmk.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return process_record_d3lilah(keycode, record);
}
```

### 2. Configure VIA Support

Your keymap's `config.h`:
```c
#undef DYNAMIC_KEYMAP_LAYER_COUNT
#define DYNAMIC_KEYMAP_LAYER_COUNT 8

#undef DYNAMIC_KEYMAP_MACRO_COUNT
#define DYNAMIC_KEYMAP_MACRO_COUNT 32
```

### 3. Load VIA Definition

Create a VIA JSON with custom keycode definitions:
```json
{
  "customKeycodes": [
    {"name": "MD H1", "title": "Markdown Header 1", "shortName": "MD H1"},
    // ... additional keycodes
  ]
}
```

See example implementation in:
`keyboards/keychron/q15_max/ansi_encoder/keymaps/delilah/via_custom_keycodes.json`

## Example Implementation

The Keychron Q15 Max implementation in this repository demonstrates:
- Full integration with 8 layers
- 32 macro support via VIA
- All RGB Matrix effects enabled
- Custom encoder mappings per layer

## Compilation

From QMK root directory:
```bash
qmk compile -kb your_keyboard -km your_keymap
```

Example:
```bash
qmk compile -kb keychron/q15_max/ansi_encoder -km delilah
```

## VIA Usage

1. Flash compiled firmware to keyboard
2. Open VIA (web or desktop)
3. Load custom JSON definition
4. Access macros in CUSTOM tab
5. Drag and drop to any key position

## Customization

### Adding New Macros
1. Add keycode enum in `d3lilah_qmk.h`
2. Implement handler in appropriate macro file
3. Update VIA JSON with new keycode definition

### Modifying Existing Macros
1. Locate macro in appropriate `.c` file under `macros/`
2. Modify implementation
3. Recompile and flash

## Migration from Vial

This implementation demonstrates migration from Vial's dynamic macro system to QMK's compiled approach with VIA configuration support. Key differences:

**Vial:**
- Dynamic macros configured through GUI
- Limited to basic key sequences
- No code organization

**QMK/VIA:**
- Compiled macros with full C programming capability
- Organized modular structure
- VIA provides GUI configuration of keycode placement

## License

GPL v2 or later - See individual file headers for details

## Author

d3lilah (2024)

## Acknowledgments

- Based on QMK firmware
- VIA integration for GUI configuration
- Inspired by Vial's ease of use