/*
Copyright 2017 Ruari Armstrong <ukkeyboards@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x554B /* Ascii */
#define PRODUCT_ID      0x004E
#define DEVICE_VER      0x0002
#define MANUFACTURER    Geno 15 Key
#define PRODUCT         GT15 Keyboard
#define DESCRIPTION     QMK keyboard firmware for GT15

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 5

/* key matrix pins */
#define MATRIX_ROW_PINS { F0, F1, F2 }
#define MATRIX_COL_PINS { E0, E1, C0, C1, C2 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* number of backlight levels */
#define BACKLIGHT_PIN B4
#define BACKLIGHT_LEVELS 5

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* ws2812b options */
#define RGB_DI_PIN F6
#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 8
#define RGBLIGHT_HUE_STEP 4
#define RGBLIGHT_SAT_STEP 4
#define RGBLIGHT_VAL_STEP 4
#endif

#define RETRO_TAPPING

#define AUDIO_VOICES
#define C6_AUDIO
#define B6_AUDIO
#define AUDIO_CLICKY
#define AUDIO_CLICKY_ON

#endif
