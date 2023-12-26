#include QMK_KEYBOARD_H
#include <stdio.h>

enum crkbd_layers {
    _QWERTY,
    _SYMBOLS,
    _NAVIGATION,
    _EXTRAS,
    _F,
    _TOGGLE,
};

enum custom_keycodes {
    LANG = SAFE_RANGE,
    HIDE,
    ZOOM_P,
    ZOOM_M,
    ZOOM_0,
    PASTE,
    COPY,
    SCREENSHOT,
    MOVE_SCREEN_LEFT,
    MOVE_SCREEN_RIGHT
};

#define KC_OPT_ESC LOPT_T(KC_ESC)
#define KC_SYM_SPC LT(_SYMBOLS, KC_SPC)
#define KC_RSFT_DEL RSFT_T(KC_DEL)
#define KC_NAV_BSPS LT(_NAVIGATION, KC_BSPC)
#define KC_ENT_ENT LT(_EXTRAS, KC_ENT)

// const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM vb_combo[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM cv_combo[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM df_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM asf_combo[] = {KC_A, KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM hj_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM jkl_combo[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM sdf_combo[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM rt_combo[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM dotcom_combo[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
  COMBO(vb_combo, LCMD(KC_V)),
  COMBO(cv_combo, LCMD(KC_C)),
  COMBO(zx_combo, LCMD(KC_Z)),
  COMBO(asf_combo, SCREENSHOT),
  COMBO(hj_combo, LCTL(KC_ENT)),
  COMBO(jkl_combo, MOVE_SCREEN_RIGHT),
  COMBO(sdf_combo, MOVE_SCREEN_LEFT),
  COMBO(dotcom_combo, KC_UNDS),
};



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

  [_SYMBOLS] = LAYOUT_split_3x6_3(
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

  [_NAVIGATION] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, ZOOM_0,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_OPT_ESC, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, ZOOM_M,                       KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_HOME, KC_END,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT, XXXXXXX, XXXXXXX, KC_BTN2, KC_BTN1, ZOOM_P,                     XXXXXXX, XXXXXXX, KC_COMM, KC_DOT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LCMD, KC_LCTL, XXXXXXX,     XXXXXXX,  _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),
  [_EXTRAS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SCREENSHOT,                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, ZOOM_0, ZOOM_M, ZOOM_P,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,  XXXXXXX,     _______,  XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

  [_F] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, TG(_TOGGLE),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                      XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, HIDE, KC_F16,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,                     XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, KC_F13, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
  [_TOGGLE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_TOGGLE),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,  XXXXXXX,     _______,  XXXXXXX, XXXXXXX
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
        case ZOOM_0:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD("0"));
            }
            return false;
        case PASTE:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD("v"));
            }
            return false;
        case COPY:
            if (record->event.pressed) {
                SEND_STRING(SS_LCMD("c"));
            }
            return false;
        case SCREENSHOT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LSFT("s")));
            }
            return false;
        case MOVE_SCREEN_LEFT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_LEFT))));
            }
            return false;
        case MOVE_SCREEN_RIGHT:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_RIGHT))));
            }
            return false;
    }
    return true;
}
