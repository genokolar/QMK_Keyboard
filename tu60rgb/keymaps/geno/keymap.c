#include QMK_KEYBOARD_H

// 引入RGB参数，以便直接操作RGB
rgblight_config_t rgblight_config; 

#define _______ KC_TRNS

enum my_layers {
  _Default,
  _Normal,
  _FL,
  _Func
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_Default] = LAYOUT_60_ansi(
		KC_ESC,  KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, 
		KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, 
		KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, 
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP), 
		KC_LCTL, LGUI_T(KC_GRV), KC_LALT, 	LT(2, KC_SPACE),		LT(2, KC_DEL), RALT_T(KC_LEFT), LT(3, KC_DOWN), RCTL_T(KC_RGHT)
    ),
	
    [_Normal] = LAYOUT_60_ansi(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  
		KC_TRNS, KC_LGUI, KC_TRNS, 	KC_SPACE,	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

    [_FL] = LAYOUT_60_ansi(
		KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PGUP, KC_PGDN, KC_INS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_END, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, 	KC_TRNS, 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

    [_Func] = LAYOUT_60_ansi(
		KC_0   , KC_MYCM, KC_MAIL, KC_CALC, KC_MSEL,  RGB_TOG,  RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, 
		KC_PAUS, RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, RGB_M_X, RGB_M_G, RGB_M_T, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, BL_STEP, BL_TOGG,  BL_BRTG,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_TRNS, KC_TRNS, 	KC_TRNS,	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	)

};

/* 层指示灯功能实现 */

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case _FL:
        if(rgblight_config.enable == 1) {
          rgblight_config.mode =1; rgblight_sethsv_noeeprom_green(); _delay_ms(300);
          rgblight_init();
        }
        break;
    case _Func:
        if(rgblight_config.enable == 1) {
          rgblight_config.mode =1; rgblight_sethsv_noeeprom_blue(); _delay_ms(300);
          rgblight_init();
        }
        break;
    default:
        break;
    }
  return state;
}
uint32_t default_layer_state_set_user(uint32_t state) {
     if(rgblight_config.enable == 1) {
        rgblight_config.mode =1;
        rgblight_sethsv_noeeprom_red();//默认层改变闪红光
        rgblight_disable_noeeprom();
        _delay_ms(100);
        rgblight_enable_noeeprom();
        _delay_ms(200);
        rgblight_disable_noeeprom();
        _delay_ms(100);
        rgblight_enable_noeeprom();
        _delay_ms(200);
        rgblight_init();
     }
  return state;
}

//电脑休眠时关闭caps灯
void suspend_power_down_user(void)
{
    gh60_caps_led_off();
}

void suspend_wakeup_init_user(void)
{

}
