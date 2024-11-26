/* Copyright 2022 splitkb.com <support@splitkb.com>
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

#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

#define GPU_RESET LCTL(LSFT(LGUI(KC_B)))

enum layers {
	_DEFAULT = 0,
	_LOWER = 1,
	_RAISE = 2,
	_ADJUST = 3
};

enum my_keycodes{
    LOG_IN = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case LOG_IN:
        if (record->event.pressed) {
            SEND_STRING("35383538\n");
			return false;
        }
        break;
	}
    return true;
}
//KC_ESC KC_SYSTEM_SLEEP
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_DEFAULT] = LAYOUT(GPU_RESET, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_GRV, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LALT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LBRC, KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_HOME, KC_LGUI, MO(_LOWER), KC_LSFT, KC_SPC, KC_ENT, KC_BSPC, MO(_RAISE), KC_DEL),
    [_LOWER] = LAYOUT(KC_X, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, _______, _______, _______, _______, _______, MO(_ADJUST), _______, _______),
	[_RAISE] = LAYOUT(_______, KC_X, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______, KC_PLUS, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS, _______, _______, MO(_ADJUST), _______, _______, _______, _______, _______),
	[_ADJUST] = LAYOUT(QK_REBOOT, QK_BOOT, KC_X, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_X, KC_Y, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______),
};


x1x222


// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// 	[_DEFAULT] = LAYOUT(
//             KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_GRV ,
//             KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                       KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
//             KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                       KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
//             KC_LALT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_LBRC,       KC_RBRC, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_HOME,
//                                              KC_LGUI, MO(_LOWER), KC_LSFT, KC_SPC, KC_ENT, KC_BSPC, MO(_RAISE), KC_DEL)
//  ),
// 	[_LOWER] = LAYOUT(
//             _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
//             KC_F1  ,   KC_F2,   KC_F3, KC_F4  , KC_F5  , KC_F6  ,                       KC_F7  , KC_F8  ,KC_F9   , KC_F10 , KC_F11 , KC_F12 ,
//             KC_GRV , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TILD,
//             _______, _______, _______, _______, _______, _______, _______,       _______, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
//                                              _______, _______, _______, _______, _______, MO(3)  , _______, _______
//  ),
// 	[_RAISE] = LAYOUT(
//             _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
//             KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                       KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
//             KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                       XXXXXXX, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, XXXXXXX,
//             KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,       _______, KC_PLUS, KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, KC_BSLS,
//                                              _______, _______, MO(3)  , _______, _______, _______, _______, _______
//  ,
// 	[_ADJUST] = LAYOUT(
//             QK_REBOOT, QK_BOOT, KC_SYSTEM_SLEEP, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GPU_RESET,                       LOG_IN, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,
//             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,
//                                              _______, _______, _______, _______, _______, _______, _______, _______
//  )
// };
