#include QMK_KEYBOARD_H


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

KEYMAP(
    KC_NLCK,     KC_PSLS, KC_PAST, KC_PMNS,
    KC_P7,       KC_P8,   KC_P9,
    KC_P4,       KC_P5,   KC_P6,   KC_PPLS,
    KC_P1,       KC_P2,   KC_P3,
    LT(1,KC_P0), LT(2,KC_P0),   KC_PDOT, KC_ENT),

KEYMAP(
    RGB_TOG,      RGB_SAI,  RGB_SAD,  RGB_HUI,
    RGB_M_P,      RGB_M_B,  RGB_M_R,
    RGB_M_SW,     RGB_M_SN, RGB_M_K,  RGB_HUD,
    RGB_M_X,      RGB_M_G,  RGB_M_T,
    LT(1,KC_P0),  LT(2,KC_P0),  RGB_VAI,  RGB_VAD),

KEYMAP(
    KC_CALC,     KC_MYCM,   KC_MAIL,   KC_MSEL,
    KC_WBAK,     KC_VOLU,   KC_WFWD,
    KC_MPRV,     KC_MPLY,   KC_MNXT,   KC_MSTP,
    KC_NO,       KC_VOLD,   KC_NO,
    LT(1,KC_P0), LT(2,KC_P0),   OSL(3),     KC_MUTE),

KEYMAP(
    RESET,      KC_NO,   KC_NO,   KC_NO,
    KC_NO,      KC_NO,   KC_NO,
    KC_NO,      KC_NO,   KC_NO,   KC_NO,
    KC_NO,      KC_NO,   KC_NO,
    KC_NO,      KC_NO,   OSL(3),  KC_NO),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  return MACRO_NONE ;
}

void matrix_scan_user(void) {
}

static int is_numberlock = 1;// 底灯仅运行一次
void led_set_user(uint8_t usb_led) {

  if (usb_led & (1 << USB_LED_NUM_LOCK)) {//以背光改变提示numlock
        if(is_numberlock == 1){
        rgblight_enable_noeeprom();
        rgblight_mode_noeeprom(1);
        rgblight_sethsv_noeeprom_green(); //绿光
        _delay_ms(450);
        rgblight_disable_noeeprom();
        rgblight_init();
        is_numberlock = 0;
        }
  } else {
        if(is_numberlock == 0){
        rgblight_enable_noeeprom();
        rgblight_mode_noeeprom(1);
        rgblight_sethsv_noeeprom_white();//白光
        _delay_ms(450);
        rgblight_disable_noeeprom();
        rgblight_init();
        is_numberlock = 1;
        }
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

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case 1:
       rgblight_enable_noeeprom(); rgblight_mode_noeeprom(1); rgblight_sethsv_noeeprom_blue(); rgblight_enable_noeeprom(); _delay_ms(450); rgblight_disable_noeeprom(); rgblight_init();
        break;
    case 2:
       rgblight_enable_noeeprom(); rgblight_mode_noeeprom(1); rgblight_sethsv_noeeprom_red(); rgblight_enable_noeeprom(); _delay_ms(450); rgblight_disable_noeeprom(); rgblight_init();
        break;
    default:
        break;
    }
  return state;
}

