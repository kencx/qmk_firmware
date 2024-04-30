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


// Current Features
// 1. Tap dance L-shift and caps lock
// 2. Triple tap dance brackets (,[,{
// 3. Hold: Raise, lower; Press: Enter, backspace
// 4. Ctrl and Alt keys moved one key right
// 5. Multiple mod taps for Ctrl

// TODO:
// more tap dance keys for shifted pairs
// hyper key for rarely used bindings - create the bindings
// super key layer -> LM(super) switches to _WM layer -> tap dance/mod tap for shifted keys
//      - how to handle numbers though? move to layer _LS?
// ctrl key layer -> LM(ctrl) switches to _VIM layer -> mod tap for shifted keys

// TG(layer) or TT(layer) to handle modes?
//      - replace left ctrl with TG or use with mod tap?

// Tap Dance
enum {
    ESC_CL = 0,
    TD_BRC_L,
    TD_BRC_R,
};

void triple_tap_L(tap_dance_state_t *state, void *user_data);
void triple_tap_R(tap_dance_state_t *state, void *user_data);

tap_dance_action_t tap_dance_actions[] = {
    [ESC_CL] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS_LOCK),
    [TD_BRC_L] = ACTION_TAP_DANCE_FN(triple_tap_L),
    [TD_BRC_R] = ACTION_TAP_DANCE_FN(triple_tap_R),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* _QW
 * ,-----------------------------------------------------------------------------------.
 * |Esc/CL|   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |Ctrl/F|   G  |   H  |Ctrl/J|   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Hyper| Ctrl | Alt  | GUI  |Lower |    Space    |Raise |C/Left| Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QW] = LAYOUT_planck_grid(
    TD(ESC_CL), KC_Q,    KC_W,    KC_E,    KC_R,         KC_T,   KC_Y,   KC_U,          KC_I,           KC_O,    KC_P,    KC_BSPC,
    KC_TAB,     KC_A,    KC_S,    KC_D,    CTL_T(KC_F),  KC_G,   KC_H,   CTL_T(KC_J),  KC_K,           KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,         KC_B,   KC_N,   KC_M,          KC_COMM,        KC_DOT,  KC_SLSH, KC_ENT,
    HYPR(KC_NO),KC_LCTL, KC_LALT, KC_LGUI, MO(1), KC_SPC, KC_SPC, MO(2), CTL_T(KC_LEFT), KC_DOWN, KC_UP,   KC_RGHT
),

/* _LS
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  |,\ |   0  |   1  |   2  |   3  | INS  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ~  |  F5  |  F6  |  F7  |  F8  |(,[,{ | ),],}|   4  |   5  |   6  | PGUP | Home |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|  F9  |  F10 |  F11 |  F12 | +,=  |  -,_ |   7  |   8  |   9  | PGDN | End  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |Lower |    Space    |Raise |   0  |      |  B-  |  B+  |
 * `-----------------------------------------------------------------------------------'
 */
[_LS] = LAYOUT_planck_grid(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_NO,        KC_0,         KC_1,    KC_2, KC_3,  KC_INS,  KC_BSPC,
    KC_GRV,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   TD(TD_BRC_L), TD(TD_BRC_R), KC_4,    KC_5, KC_6,  KC_PGUP, KC_HOME,
    KC_LSFT, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO ,       KC_NO,        KC_7,    KC_8, KC_9,  KC_PGDN, KC_END,
    KC_NO,   KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS, KC_SPC,       KC_SPC,       KC_TRNS, KC_0, KC_NO, KC_BRID, KC_BRIU
),

/* _RS
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |  *   |      |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   (  |   )  |   +  |   _  |   {  |   }  |      |      |      | PGUP | Home |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   [  |   ]  |   =  |   -  |   |  |   \  |      |      |      | PGDN | End  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Mute | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RS] = LAYOUT_planck_grid(
    KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_NO,   KC_TRNS, KC_BSPC,
    KC_GRV,  KC_LPRN, KC_RPRN, KC_PLUS, KC_UNDS, KC_LCBR,       KC_RCBR, KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS,
    KC_LSFT, KC_LBRC, KC_RBRC, KC_EQL,  KC_MINS, LSFT(KC_BSLS), KC_BSLS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_TRNS,
    KC_NO,   KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS, KC_SPC,        KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY
),

/* _WM
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |  *   |      |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   (  |   )  |   +  |   _  |   {  |   }  |      |      |      | PGUP | Home |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   [  |   ]  |   =  |   -  |   |  |   \  |      |      |      | PGDN | End  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Alt  | Del  | Ctrl | GUI  |Lower |    Space    |Raise | Mute | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_WM] = LAYOUT_planck_grid(
    KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
    KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_LCTL, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO
)

};


// tap dance

void triple_tap_L (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(KC_LPRN);
    } else if (state->count == 2) {
        tap_code16 (KC_LBRC);
    } else if (state->count == 3) {
        tap_code16(KC_LCBR);
    } else {
        reset_tap_dance(state);
    }
}

void triple_tap_R (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(KC_RPRN);
    } else if (state->count == 2) {
        tap_code16 (KC_RBRC);
    } else if (state->count == 3) {
        tap_code16(KC_RCBR);
    } else {
        reset_tap_dance(state);
    }
}

// SHIFT + BACKSPACE -> DELETE
// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {

    case KC_BSPC:
        {
        static bool delkey_registered;
        if (record->event.pressed) {

            if (mod_state & MOD_MASK_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
                register_code(KC_DEL);
                delkey_registered = true;
                set_mods(mod_state);
                return false;
            }
        } else { // on release of KC_BSPC
            if (delkey_registered) {
                unregister_code(KC_DEL);
                delkey_registered = false;
                return false;
            }
        }
        return true;
        }
    }
    return true;
};
