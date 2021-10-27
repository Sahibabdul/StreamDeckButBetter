#include "kb.h"

#define _BASE 0
#define _RGB 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_BASE] = KEYMAP(
		KC_MUTE, TO(_RGB), TO(_RGB), LCTL(KC_0), 
		KC_F13,  KC_F14,  KC_F15,  KC_F16, 
		LCTL(KC_C),    LCTL(KC_V), KC_F19,  KC_F20),

	[_RGB] = KEYMAP(
		RGB_VAI, TO(_BASE), TO(_BASE),  RGB_VAD, 
		RGB_TOG, RGB_MOD,   RGB_RMOD, KC_TRNS , 
		RGB_M_P, RGB_M_G,   RGB_M_B,  RGB_M_R ),

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	switch (id) {

	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {
	if (usb_led & (1 << USB_LED_NUM_LOCK)) {		
	} else {		
	}
	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {		
	} else {		
	}
	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {		
	} else {		
	}
	if (usb_led & (1 << USB_LED_COMPOSE)) {		
	} else {		
	}
	if (usb_led & (1 << USB_LED_KANA)) {		
	} else {		
	}
}



bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (get_highest_layer(layer_state)) {
        case _BASE:          
            if (index == 0) { /* First encoder */
                if (clockwise) {
                    tap_code16(KC_VOLD);
                } else {
                    tap_code16(KC_VOLU);
                }
            } else if (index == 1) { /* Second encoder */
                if (clockwise) {
                    tap_code16(LCTL(KC_MS_WH_UP));
                } else {
                    tap_code16(LCTL(KC_MS_WH_DOWN));
                }
            }
            break;
            
        case _RGB:          
            if (index == 0) { /* First encoder */
                if (clockwise) {
                    tap_code16(RGB_HUI);
                } else {
                    tap_code16(RGB_HUD);
                }
            } else if (index == 1) { /* Second encoder */
                if (clockwise) {
                    tap_code16(RGB_SAI);
                } else {
                    tap_code16(RGB_SAD);
                }
            }
            break;
        
        default:
            break;
    }  
    return true;
    
}

#ifdef OLED_ENABLE
void oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer:\n"), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Function Layer\n"), false);
            oled_write_P(PSTR("B========D\n\n"), false);
            break;
        case _RGB:
            oled_write_P(PSTR("RGB config\n"), false);
            oled_write_P(PSTR("RGB Mode enabled\nAdded 25% more Power\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined\n"), false);
    }
}
#endif