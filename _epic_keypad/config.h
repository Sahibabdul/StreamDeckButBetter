#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0420
#define DEVICE_VER      0x0069
#define MANUFACTURER    Sahibabdul
#define PRODUCT         PC Destroyer Mark five
#define DESCRIPTION     Definitely not a virus and wont kill your PC

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 4

/* key matrix pins */
#define MATRIX_ROW_PINS { D7, C6, D4 }
#define MATRIX_COL_PINS { F7, F6, F5, F4 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* number of backlight levels */

#define ENCODERS_PAD_A { B2, B3 }
#define ENCODERS_PAD_B { B6, B1 }

#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 5
#endif

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

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS

#define RGB_DI_PIN E6

#ifdef RGB_DI_PIN
#define RGBLIGHT_ANIMATIONS
#define RGBLED_NUM 12
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

#define RGBLIGHT_DEFAULT_HUE 0 
#define RGBLIGHT_DEFAULT_SAT 255
#define RGBLIGHT_DEFAULT_VAL 255
#endif

#endif