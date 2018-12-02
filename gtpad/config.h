#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xE536
#define PRODUCT_ID      0x7803
#define DEVICE_VER      0x0001
#define MANUFACTURER    GT Custom Keyborad
#define PRODUCT         GT Pad Keyboard
#define DESCRIPTION     Geno QMK Keyboard

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 4

/* key matrix pins */
#define MATRIX_ROW_PINS { D7, D6, D2, F5, F4 }
#define MATRIX_COL_PINS { E6, F1, F0, B1 }
#define UNUSED_PINS

/* Pins for custom per-row LEDs. Should be changed to use named pins.
#define LED_ROW_PINS { 8, 9, 10, 11 }*/

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

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

#ifdef RGBLIGHT_ENABLE
#define RGB_DI_PIN B3
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 4
#define RGBLIGHT_HUE_STEP 4
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 16
#endif

#endif
