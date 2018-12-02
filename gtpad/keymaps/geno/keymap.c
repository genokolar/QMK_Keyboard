#include QMK_KEYBOARD_H

enum my_layers {
  _Number,
  _Game,
  _RGB
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_Number] = KEYMAP(
    KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,
    KC_P7, KC_P8, KC_P9,
    KC_P4, KC_P5, KC_P6, KC_PPLS,
    KC_P1, KC_P2, KC_P3,
    DF(1), KC_P0, KC_PDOT, KC_PENT),

 [_Game] = KEYMAP(
    KC_4,  KC_R,  KC_F,  KC_B,
    KC_3,  KC_E,  KC_D,  
    KC_2,  KC_W,  KC_S,  KC_SPC,
    KC_1,  KC_Q,  KC_A,
    DF(2), KC_ESC,  KC_GRV,  KC_P),

 [_RGB] = KEYMAP(
    RGB_TOG,  RGB_SAI,  RGB_SAD,  RGB_HUI,
    RGB_M_P,  RGB_M_B,  RGB_M_R,
    RGB_M_SW, RGB_M_SN, RGB_M_K,  RGB_HUD,
    RGB_M_X,  RGB_M_G,  RGB_M_T,
    DF(0),    RGB_MOD,  RGB_VAI,  RGB_VAD),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  return MACRO_NONE ;
}

void matrix_scan_user(void) {
}

static int is_numberlock = 1;// 底灯仅运行一次
void led_set_user(uint8_t usb_led) {

  if (usb_led & (1 << USB_LED_NUM_LOCK)) { //以背光改变提示numlock
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
/* 层指示灯功能实现 */

/* 我们没有瞬时开启层的设定
   屏蔽这部分代码

*/

/*static int is_molayer = 1;// 跳过第二次默认层闪灯
uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
   case _Number:
        if(is_molayer != 1){
        rgblight_mode_noeeprom(1);
        rgblight_sethsv_noeeprom_blue();//第二层闪光
        _delay_ms(350);
        rgblight_init();
        }
        if(is_molayer == 1){ 
        is_molayer = 0;
        }else{
        is_molayer = 1;
        }
        break;
   case _Game:
        rgblight_mode_noeeprom(1);
        rgblight_sethsv_noeeprom_green();//第三层闪光
        _delay_ms(350);
        rgblight_init();
        is_molayer = 1;
        break;
    case _RGB: 
        rgblight_mode_noeeprom(1);
        rgblight_sethsv_noeeprom_red();//第一层闪光
        _delay_ms(350);
        rgblight_init();
        is_molayer = 1;
        break;
    default:
        break;
    } 
    return state;
}

*/
static int is_deflayer = 1;// 跳过第二次默认层闪灯
uint32_t default_layer_state_set_user(uint32_t state) {
  switch (biton32(default_layer_state)) {
   case _Number:
        if(is_deflayer != 1){
        rgblight_enable_noeeprom();
        rgblight_mode_noeeprom(1);
        rgblight_sethsv_noeeprom_blue();//第二层闪光
        _delay_ms(200);
        rgblight_disable_noeeprom();
        _delay_ms(100);
        rgblight_enable_noeeprom();
        _delay_ms(200);
        rgblight_disable_noeeprom();
        rgblight_init();
        }
        if(is_deflayer == 1){ 
        is_deflayer = 0;
        }else{
        is_deflayer = 1;
        }
        break;
   case _Game:
        rgblight_enable_noeeprom();
        rgblight_mode_noeeprom(1);
        rgblight_sethsv_noeeprom_green();//第三层闪光
        _delay_ms(200);
        rgblight_disable_noeeprom();
        _delay_ms(100);
        rgblight_enable_noeeprom();
        _delay_ms(200);
        rgblight_disable_noeeprom();
        rgblight_init();
        is_deflayer = 1;
        break;
    case _RGB: 
        rgblight_enable_noeeprom();
        rgblight_mode_noeeprom(1);
        rgblight_sethsv_noeeprom_red();//第一层闪光
        _delay_ms(200);
        rgblight_disable_noeeprom();
        _delay_ms(100);
        rgblight_enable_noeeprom();
        _delay_ms(200);
        rgblight_disable_noeeprom();
        rgblight_init();
        is_deflayer = 1;
        break;
    default:
        break;
    } 
  return state;
}
