/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include <stdio.h>

enum crkbd_layers {
    _QWERTY,
    _SYM,
    _NAV,
    _F,
    _TOGGLE,
};

enum custom_keycodes {
    LANG = SAFE_RANGE,
    HIDE,
    ZOOM_P,
    ZOOM_M,
};


#define KC_OPT_ESC LOPT_T(KC_ESC)
#define KC_SYM_SPC LT(_SYM, KC_SPC)
// #define KC_CTL_SC CTL_T(KC_SCLN)
#define KC_RSFT_DEL RSFT_T(KC_DEL)
#define KC_NAV_BSPS LT(_NAV, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,----------------------------------------------------------------|                    |---------------------------------------------------------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,    KC_GRAVE,
  //|--------+--------+--------+--------+--------+-------------------|                    |---------------------------------------------------------|
       KC_OPT_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                KC_H,    KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+-------------------|                    |---------------------------------------------------------|
       KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH,  LT(_F, KC_LOPT),
  //|--------+--------+--------+--------+--------+--------+----------|                    |---------------------------------------------------------|
                           KC_LCMD,  KC_LCTL, KC_SYM_SPC,                            KC_ENT, KC_NAV_BSPS, KC_RSFT_DEL
                           //`--------------------------'                           --------------------------'

  ),

  [_SYM] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------|                    |-----------------------------------------------------|
      KC_TAB,    KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                     KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_ASTR, KC_PIPE,
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
      KC_OPT_ESC, KC_1,   KC_2,    KC_3,  KC_4,   KC_5,                          KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_COLN, KC_DQT,
  //|--------+--------+--------+--------+--------+--------|                    |----------------------------------------=====--------|
      KC_LSFT,   KC_6,   KC_7,    KC_8,  KC_9,   KC_0,                          KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_BSLS, KC_LOPT,
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
                                        KC_LCMD,  KC_LCTL, _______,     KC_ENT, _______, LANG
     // modify kc_lsft                //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,  KC_9,     KC_0,   KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_OPT_ESC, KC_NO, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R,                    KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_HOME, KC_END,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, KC_BTN2, KC_BTN1, KC_NO,                       XXXXXXX, XXXXXXX, KC_COMM, KC_DOT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCMD, KC_LCTL,  KC_SPC,     _______,  _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_F] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, TG(_TOGGLE),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                      ZOOM_P, KC_MPRV, KC_MPLY, KC_MNXT, HIDE, KC_F16,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,                     ZOOM_M, KC_MUTE, KC_VOLD, KC_VOLU, KC_F13, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
  [_TOGGLE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,                             KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, TG(_TOGGLE),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_SLEP, XXXXXXX, XXXXXXX, XXXXXXX,                     KC_MCTL, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_L,                     XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_RSFT_DEL:
            return 130;
        case LT(_F, KC_ESC):
            return TAPPING_TERM + 200;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_EXLM:
            if (record->event.pressed) {
                SEND_STRING("!");
            }
            return false;

        case KC_COLN:
            if (record->event.pressed) {
                SEND_STRING(":");
            }
            return false;
        case LANG:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD(SS_LOPT("\n")));
            }
            return false;
        case HIDE:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD("h"));
            }
            return false;
        case ZOOM_P:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD("+"));
            }
            return false;
        case ZOOM_M:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD("-"));
            }
            return false;
    }
    return true;
}
