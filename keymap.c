/*
    Autor: JorgeSidgo
    Keyboard: Lily58 Pro
    QMK Command: make lily58/rev1:sidgo:dfu
*/

#include QMK_KEYBOARD_H
#include "./globals.c"
#include "./tap_dancing.c"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
* ,-----------------------------------------.                    ,-----------------------------------------.
* | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  BS  |
* |------+------+------+------+------+------|                    |------+------+------+------+------+------|
* | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  [   |
* |------+------+------+------+------+------|                    |------+------+------+------+------+------|
* |LCTrl |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
* |------+------+------+------+------+------|   -   |    |   =   |------+------+------+------+------+------|
* |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |ENTER |
* `-----------------------------------------/       /     \      \-----------------------------------------'
*                   | LAlt | LGUI |LOWER | /Space  /       \Space \  |RAISE | HOME | END  |
*                   |      |      |      |/       /         \      \ |      |      |      |
*                   `----------------------------'           '------''--------------------'
*/
[_QWERTY] = LAYOUT(
    KC_ESC,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,                        KC_6,   KC_7,   KC_8,    KC_9,   KC_0,    KC_BSPC,\
    KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                        KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,    KC_LBRC,\
    KC_LCTRL, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                        KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN, KC_QUOT,\
    KC_LSFT,  KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_MINS,   KC_EQL,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, MT(MOD_RSFT, KC_ENT),\
                TD(TT_ALT_MEDIA), KC_LGUI, TD(TT_LAYER_LOWER), KC_SPC, KC_SPC, TD(TT_LAYER_RAISE), KC_HOME, KC_END\
),

/* LOWER
* ,-----------------------------------------.                    ,-----------------------------------------.
* |      |      |      |      |      |      |                    |      |      |      |      |      |      |
* |------+------+------+------+------+------|                    |------+------+------+------+------+------|
* |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
* |------+------+------+------+------+------|                    |------+------+------+------+------+------|
* |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
* |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
* |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
* `-----------------------------------------/       /     \      \-----------------------------------------'
*                   | LAlt | LGUI |LOWER | /Space  /       \Space \  |RAISE | HOME | END  |
*                   |      |      |      |/       /         \      \ |      |      |      |
*                   `----------------------------'           '------''--------------------'
*/
[_LOWER] = LAYOUT(
    KC_BSLS, _______, _______, _______, _______, _______,       _______, _______, _______, KC_MINS, KC_EQL, KC_DEL,\
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                   KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,\
    KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,           KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,\
    _______, _______, _______, _______, _______, _______,      _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR,\
            KC_RCBR, KC_PIPE, _______, _______, _______, _______, _______, _______, _______, _______
),

/* RAISE
* ,-----------------------------------------.                    ,-----------------------------------------.
* |      |      |      |      |      |      |                    |      |      |      |   -  |   =  |      |
* |------+------+------+------+------+------|                    |------+------+------+------+------+------|
* |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |  Up  |   9  |   0  |   ]  |
* |------+------+------+------+------+------|                    |------+------+------+------+------+------|
* |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |Right |      |      |
* |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
* |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
* `-----------------------------------------/       /     \      \-----------------------------------------'
*                   | LAlt | LGUI |LOWER | /Space  /       \Space \  |RAISE | HOME | END  |
*                   |      |      |      |/       /         \      \ |      |      |      |
*                   `----------------------------'           '------''--------------------'
*/
[_RAISE] = LAYOUT(
    KC_GRV, _______, _______, _______, _______, _______,       _______, _______, _______, KC_MINS, KC_EQL, KC_INS,
    KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,                      KC_6, KC_7, KC_UP, KC_9, KC_0, KC_RBRC,
    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,                  XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, 
    KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______, KC_PLUS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,
                    _______, _______, _______, _______, _______, _______, _______, _______
),

/* MEDIA
* ,-----------------------------------------.                    ,-----------------------------------------.
* |      |      |      |      |      |      |                    |      |      |      |      |      |      |
* |------+------+------+------+------+------|                    |------+------+------+------+------+------|
* |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
* |------+------+------+------+------+------|                    |------+------+------+------+------+------|
* |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
* |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
* |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
* `-----------------------------------------/       /     \      \-----------------------------------------'
*                   | LAlt | LGUI |LOWER | /Space  /       \Space \  |RAISE | HOME | END  |
*                   |      |      |      |/       /         \      \ |      |      |      |
*                   `----------------------------'           '------''--------------------'
*/
[_MEDIA] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, 
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, 
    KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
                            _______, _______, _______, _______, _______, _______, _______, _______
),
/* ADJUST
* ,-----------------------------------------.                    ,-----------------------------------------.
* |      |      |      |      |      |      |                    |      |      |      |      |      |      |
* |------+------+------+------+------+------|                    |------+------+------+------+------+------|
* |      |      |      |      |      |      |                    |      |      |      |      |      |      |
* |------+------+------+------+------+------|                    |------+------+------+------+------+------|
* |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
* |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
* |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
* `-----------------------------------------/       /     \      \-----------------------------------------'
*                   | LAlt | LGUI |LOWER | /Space  /       \Space \  |RAISE | HOME | END  |
*                   |      |      |      |/       /         \      \ |      |      |      |
*                   `----------------------------'           '------''--------------------'
*/
[_ADJUST] = LAYOUT(XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______)};

layer_state_t layer_state_set_user(layer_state_t state) { 
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); 
}

