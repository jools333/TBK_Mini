/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <sys/types.h>
#include QMK_KEYBOARD_H
// #include "raw_hid.h"

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_SYMBOLS,
    LAYER_DIGITS,
    LAYER_CALC,
    LAYER_MOUSE,
    LAYER_GAME,
};

/*#define CHARYBDIS_AUTO_SNIPING_ON_LAYER LAYER_MOUSE_TEMP*/
/*#define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE*/

#define CHARYBDIS_MINIMUM_SNIPING_DPI 200
#define LEADER_TIMEOUT 200
#define CHARYBDIS_DRAGSCROLL_REVERSE_Y
#define CHARYBDIS_DRAGSCROLL_REVERSE_X
// #define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// #define AUTO_MOUSE_DEFAULT_LAYER LAYER_MOUSE
// #define AUTO_MOUSE_TIME 1500


#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1500
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 1
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
// #endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE


#define LOWER MO(LAYER_SYMBOLS)
#define RAISE MO(LAYER_DIGITS)

#define CTRL_EXEC LCTL_T(KC_EXEC)
#define CTRL_F LCTL_T(KC_F)
#define SHIFT_R SFT_T(KC_R)
#define ALT_G ALT_T(KC_G)
#define CTRL_QUOTE LCTL_T(KC_QUOT)
#define ALT_ESC ALT_T(KC_ESC)
#define WIN_DEL LGUI_T(KC_DEL)
#define SYM_DEL LT(LAYER_SYMBOLS, KC_DEL)
#define DIG_BACK LT(LAYER_DIGITS, KC_BSPC)
#define SHIFT_SPACE SFT_T(KC_SPC)
#define SHIFT_ENTER SFT_T(KC_ENT)
#define RKEY_MOUSE LT(LAYER_MOUSE, KC_R)

// static uint16_t auto_pointer_layer_timer = 0;
layer_state_t currentState = LAYER_BASE;
enum custom_keycodes {
    SLIM_ARROW = SAFE_RANGE,
    FAT_ARROW,
    COPY,
    PASTE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SLIM_ARROW:
        if (record->event.pressed) {
            SEND_STRING("->");
        } else {
        }
        break;
    case FAT_ARROW:
        if (record->event.pressed) {
            SEND_STRING("=>");
        } else {
        }
        break;
    case COPY:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("c"));
        } else {
        }
        break;

    case PASTE:
        if (record->event.pressed) {
            SEND_STRING(SS_LCTL("v"));
        } else {
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM vpn_cmb[] = {KC_Q, KC_P, COMBO_END};
const uint16_t PROGMEM web_cmb[] = {KC_LGUI, CTRL_QUOTE, COMBO_END};
const uint16_t PROGMEM lang_cmb[] = {CTRL_F, KC_J, COMBO_END};
const uint16_t PROGMEM close_cmb[] = {KC_Z, KC_SLSH, COMBO_END};
const uint16_t PROGMEM editor_cmb[] = {KC_V, KC_M, COMBO_END};
const uint16_t PROGMEM save_cmb[] = {CTRL_F, KC_SCLN, COMBO_END};
const uint16_t PROGMEM msg_cmb[] = {RKEY_MOUSE, KC_U, COMBO_END};
const uint16_t PROGMEM cmd_cmb[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM ctrlp_cmb[] = {KC_A, KC_SCLN, COMBO_END};
const uint16_t PROGMEM win_cmb[] = {KC_C, KC_COMM, COMBO_END};
const uint16_t PROGMEM arrow_cmb[] = {KC_W, KC_O, COMBO_END};
const uint16_t PROGMEM fat_arrow_cmb[] = {KC_X, KC_DOT, COMBO_END};
const uint16_t PROGMEM search_cmb[] = {SYM_DEL, DIG_BACK, COMBO_END};
const uint16_t PROGMEM expand_cmb[] = {SHIFT_SPACE, SHIFT_ENTER, COMBO_END};
combo_t key_combos[] = {
    COMBO(vpn_cmb, LSFT(LGUI(KC_P))),
    COMBO(web_cmb, RGUI(KC_S)),
    COMBO(lang_cmb, RGUI(KC_SPC)),
    COMBO(close_cmb, LSFT(LGUI(KC_Q))),
    COMBO(editor_cmb, RGUI(KC_Z)),
    COMBO(save_cmb, C(KC_S)),
    COMBO(msg_cmb, RGUI(KC_A)),
    COMBO(cmd_cmb, RGUI(KC_X)),
    COMBO(ctrlp_cmb, C(KC_P)),
    COMBO(win_cmb, LALT(KC_TAB)),
    COMBO(search_cmb, C(KC_F12)),
    COMBO(expand_cmb, LGUI(KC_Y)),
    COMBO(arrow_cmb, SLIM_ARROW),
    COMBO(fat_arrow_cmb, FAT_ARROW),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TAB,    KC_Q,    KC_W,   KC_E,  RKEY_MOUSE, KC_T,      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_LBRC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LGUI,  KC_A,    KC_S,    KC_D,  CTRL_F,    ALT_G,      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, CTRL_QUOTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       TG(LAYER_GAME),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, ALT_ESC,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                            QK_LEAD,  SYM_DEL,   SHIFT_SPACE,   SHIFT_ENTER,  DIG_BACK
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_DIGITS] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       C(KC_C), KC_1, KC_2, KC_3, KC_4, KC_5,                   KC_6,       KC_7,    KC_8,    KC_9, KC_0, KC_SCLN,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
     C(KC_V), C(S(KC_I)), KC_HOME, KC_END, KC_BSPC, C(KC_F12),  KC_LEFT,    KC_DOWN, KC_UP,   KC_RIGHT, KC_MINUS, MT(KC_LCTL, KC_F12),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       C(KC_X), KC_F1, KC_F2, KC_F3, KC_F4,  KC_F5,             KC_F6,      KC_F7,   KC_F8,   KC_F9, KC_F10, KC_F11,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                     C(KC_F3), KC_LALT, MT(KC_LCTL, KC_TAB),    KC_TRNS, KC_TRNS
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_SYMBOLS] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       S(KC_INS), KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
KC_LCTL, TG(LAYER_CALC), KC_NO, KC_RGUI, KC_BSPC, TG(LAYER_MOUSE), KC_MINUS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LALT, KC_NO, C(KC_X), KC_NO,  DPI_RMOD, DPI_MOD,       KC_UNDS, KC_PLUS,  KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_LGUI, KC_TRNS, KC_SPC,    PASTE,COPY
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_CALC] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_NO, KC_TRNS, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0,      KC_NO, KC_NO, KC_NO, KC_NO, KC_MNXT, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
   KC_NO, S(LGUI(KC_Q)), KC_KP_4, KC_KP_5, KC_KP_6, KC_BSPC,    KC_MINUS, KC_PLUS, KC_ASTR, KC_SLSH, KC_MPLY, KC_MSTP,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_NO, KC_NO, KC_KP_1, KC_KP_2,  KC_KP_3, KC_CALC,       KC_NO, KC_DOT,  KC_NO, KC_NO, KC_KB_VOLUME_UP, KC_KB_VOLUME_DOWN,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                             KC_LGUI, TO(LAYER_BASE), KC_SPC,    KC_ENT, TO(LAYER_BASE)
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_MOUSE] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TAB, KC_ENT, DRGSCRL, SNIPING, SNIPING, KC_HOME,        KC_END, S(LGUI(KC_U)), S(LGUI(KC_I)), S(LGUI(KC_O)), KC_NO, TO(LAYER_BASE),
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT, KC_LCTL,  KC_WH_L, KC_WH_R, KC_WH_U, KC_PGUP,     KC_SPC, KC_DEL, KC_LALT, KC_MS_R, KC_LCTL, KC_LSFT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LALT, KC_NO, DPI_RMOD, DPI_MOD,  KC_WH_D, TG(LAYER_GAME),    KC_KP_7, C(KC_KP_7), KC_KP_1, C(KC_KP_1), KC_KP_3, KC_ESC,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BTN2, KC_BTN3, KC_BTN1,    SHIFT_ENTER, TO(LAYER_BASE)
  //                            ╰──────────────k────────────╯ ╰──────────────────╯
  ),

  [LAYER_GAME] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_TAB, KC_ENT, DRGSCRL, KC_W, SNIPING, KC_E,         KC_END, KC_BTN2, S(LGUI(KC_I)), S(LGUI(KC_O)), KC_NO, QK_BOOT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LSFT, KC_LCTL,  KC_A, KC_S, KC_D, KC_WH_D,              KC_BTN2, KC_BTN1, KC_BTN3, KC_MS_R, KC_LCTL, KC_LSFT,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       KC_LALT, KC_NO, KC_NO, KC_NO,  KC_WH_D, TO(LAYER_MOUSE),            KC_KP_7, KC_BTN3, KC_KP_1, C(KC_KP_1), KC_KP_3, KC_ESC,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_BTN2, KC_BTN3, KC_SPC,    KC_ENT, TO(LAYER_BASE)
  //                            ╰──────────────k────────────╯ ╰──────────────────╯
  ),
};

// void sendLayerHid(uint8_t layer) {
//     uint8_t msg[32] = { 0 };
//     sprintf((char *)msg, "%u", layer);
//     raw_hid_send(msg, 32);
// }

// clang-format on
//
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {

        if (get_highest_layer(currentState) != LAYER_MOUSE) {
            /*layer_on(LAYER_MOUSE);*/
        }
        // auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}
//
//
// void matrix_scan_user(void) {
//     if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
//         auto_pointer_layer_timer = 0;
//         layer_off(LAYER_MOUSE);
//     }
// }
//
// layer_state_t layer_state_set_user(layer_state_t state) {
//     charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
//     return state;
// }


void leader_end_user(void) {
    if (leader_sequence_one_key(KC_H)) {
        tap_code16(C(KC_S));
    }
    else if (leader_sequence_one_key(KC_ENT)) {
        tap_code16(C(KC_F12));
    }
    else if (leader_sequence_one_key(QK_LEAD)) {
        layer_on(LAYER_MOUSE);
    }
    else if (leader_sequence_one_key(KC_B)) {
        layer_on(LAYER_GAME);
    }
    else if (leader_sequence_one_key(KC_J)) {
        tap_code16(G(KC_F));
    }
    else if (leader_sequence_one_key(KC_K)) {
        tap_code16(G(KC_I));
    }
    else if (leader_sequence_one_key(SHIFT_SPACE)) {
        tap_code16(C(KC_O));
    }
}


#ifdef RGBLIGHT_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
    switch(biton32(state)) {
        case LAYER_MOUSE:
            // rgblight_enable_noeeprom();
            rgblight_sethsv_noeeprom(HSV_GREEN);
        break;
        case LAYER_GAME:
            // rgblight_enable_noeeprom();
            rgblight_sethsv_noeeprom(HSV_PURPLE);
        break;
        default:
            // rgblight_disable_noeeprom();
            // rgblight_enable_noeeprom();
            rgblight_sethsv_noeeprom(HSV_BLACK);
    }
    return state;
}

void keyboard_post_init_user(void) {
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    // rgblight_disable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_BLACK);
    rgblight_enable_noeeprom();
}
#endif

void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  /*setPinOutput(24);*/
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  /*writePinHigh(24);*/
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // sendLayerHid(get_highest_layer(state));
    /*charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));*/
    return state;
}


// void pointing_device_init_user(void) {
//     set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
// }
