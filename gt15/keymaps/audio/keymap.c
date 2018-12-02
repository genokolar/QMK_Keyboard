#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* _BL: Base Layer(Default) - For ISO enter use ANSI \
  * |-----------------------------|
  * | Q|  W|  E|  R|  BACKSPACE|
  * |-----------------------------|
  * | A|  S|  D|  F|  ENTER |
  * |-----------------------------|
  * | Z|  X|  C|  V|  FN|
  * |-----------------------------|
 
  */
  //normal key
  [0] = LAYOUT_15(
    KC_Q,    KC_W,    KC_E,   KC_R,    MU_ON,\
    KC_A,    KC_S,    KC_D,   KC_F,    LT(4,AU_ON),\
    KC_Z,    KC_X,    KC_C,   KC_V,    LT(3,KC_SPC) \
  ),
  // LOL game key
  [1] = LAYOUT_15(
    KC_1,    KC_2,    KC_3,   KC_4,    KC_TRNS,\
    KC_Q,    KC_W,    KC_E,   KC_R,    LT(4,KC_ENT),\
    KC_A,    KC_S,    KC_D,   KC_F,    LT(3,KC_SPC) \
  ),
  // RGB light control & Punctuation
  [2] = LAYOUT_15(
    RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD,    KC_TRNS,\
    RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD,    KC_TRNS,\
    KC_SCLN, KC_COMM, KC_DOT,  KC_SLSH,    KC_TRNS \
  ),
  // Direction key control & number key
  [3] = LAYOUT_15(
    KC_0   ,    KC_UP,    KC_TRNS,    KC_1,       KC_RSFT,\
    KC_LEFT,    KC_DOWN,  KC_RGHT,    KC_TRNS,    KC_TRNS,\
    KC_5,       KC_6,     KC_7,       KC_8,       KC_LSFT \
  ),
};


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
