/* Copyright 2015-2021 Jack Humbert
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

#define _QW 0
#define _LS 1
#define _RS 2
#define _WM 3


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* _QW
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | App  | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QW] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,   KC_W,    KC_E,    KC_R,       KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,   KC_S,    KC_D,    LT(3,KC_F), KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,       KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL, KC_APP, KC_LALT, KC_LGUI, MO(1),      KC_SPC, KC_SPC, MO(2), KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_LS] = LAYOUT_planck_grid(
    KC_ESC, KC_NLCK, BL_TOGG, BL_STEP, KC_CALC, KC_NO, KC_P0, KC_P1, KC_P2, KC_P3, KC_INS, KC_BSPC,
    KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_P4, KC_P5, KC_P6, KC_PGUP, KC_HOME,
    KC_LSFT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_P7, KC_P8, KC_P9, KC_PGDN, KC_END,
    KC_LCTL, KC_DEL, KC_LALT, KC_LGUI, KC_TRNS, KC_SPC, KC_TRNS, KC_NO, KC_PSCR, KC_BRID, KC_BRIU
),

[_RS] = LAYOUT_planck_grid(
    KC_ESC, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_NO, KC_TRNS,
    KC_BSPC, KC_GRV, KC_LPRN, KC_RPRN, KC_PLUS, KC_UNDS, KC_LCBR, KC_RCBR, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS,
    KC_LSFT, KC_LBRC, KC_RBRC, KC_EQL, KC_MINS, LSFT(KC_BSLS), KC_BSLS, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS,
    KC_LCTL, KC_DEL, KC_LALT, KC_LGUI, KC_TRNS, KC_SPC, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
),

[_WM] = LAYOUT_planck_grid(
    KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
    KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_LCTL, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO
)

};
