// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free Software
// Foundation, either version 2 of the License, or (at your option) any later
// version. This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
// details. You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

#include QMK_KEYBOARD_H

#include "manna-harbour_miryoku.h"

#include "features/achordion.h"

// Additional Features double tap guard

enum {
    U_TD_BOOT,
#define MIRYOKU_X(LAYER, STRING) U_TD_U_##LAYER,
    MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

void u_td_fn_boot(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        reset_keyboard();
    }
}

#define MIRYOKU_X(LAYER, STRING)                                        \
    void u_td_fn_U_##LAYER(tap_dance_state_t *state, void *user_data) { \
        if (state->count == 2) {                                        \
            default_layer_set((layer_state_t)1 << U_##LAYER);           \
        }                                                               \
    }
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X

tap_dance_action_t tap_dance_actions[] = {[U_TD_BOOT] = ACTION_TAP_DANCE_FN(u_td_fn_boot),
#define MIRYOKU_X(LAYER, STRING) [U_TD_U_##LAYER] = ACTION_TAP_DANCE_FN(u_td_fn_U_##LAYER),
                                          MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

// keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
#define MIRYOKU_X(LAYER, STRING) [U_##LAYER] = U_MACRO_VA_ARGS(MIRYOKU_LAYERMAPPING_##LAYER, MIRYOKU_LAYER_##LAYER),
    MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

// shift functions

const key_override_t capsword_key_override = ko_make_basic(MOD_MASK_SHIFT, CW_TOGG, KC_CAPS);

const key_override_t **key_overrides = (const key_override_t *[]){&capsword_key_override, NULL};

const uint16_t PROGMEM thumbcombos_base_right[] = {LT(U_SYM, KC_ENT), LT(U_NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_left[]  = {LT(U_NAV, KC_SPC), LT(U_MOUSE, KC_TAB), COMBO_END};
const uint16_t PROGMEM thumbcombos_nav[]        = {KC_ENT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM thumbcombos_mouse[]      = {KC_BTN2, KC_BTN1, COMBO_END};
const uint16_t PROGMEM thumbcombos_media[]      = {KC_MSTP, KC_MPLY, COMBO_END};
const uint16_t PROGMEM thumbcombos_num[]        = {KC_0, KC_MINS, COMBO_END};
const uint16_t PROGMEM thumbcombos_sym[]        = {KC_UNDS, KC_LPRN, COMBO_END};
const uint16_t PROGMEM thumbcombos_fun[]        = {KC_SPC, KC_TAB, COMBO_END};
const uint16_t PROGMEM combos_cut[]             = {LT(U_BUTTON, KC_Z), KC_X, COMBO_END};
const uint16_t PROGMEM combos_copy[]            = {LT(U_BUTTON, KC_Z), KC_C, COMBO_END};
const uint16_t PROGMEM combos_paste[]           = {LT(U_BUTTON, KC_Z), KC_V, COMBO_END};
const uint16_t PROGMEM combos_qw[]              = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combos_we[]              = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combos_er[]              = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combos_rt[]              = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM combos_yu[]              = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM combos_ui[]              = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combos_io[]              = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combos_op[]              = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combos_aq[]              = {LGUI_T(KC_A), KC_Q, COMBO_END};
const uint16_t PROGMEM combos_sw[]              = {LALT_T(KC_S), KC_W, COMBO_END};
const uint16_t PROGMEM combos_de[]              = {LCTL_T(KC_D), KC_E, COMBO_END};
const uint16_t PROGMEM combos_fr[]              = {LSFT_T(KC_F), KC_R, COMBO_END};
const uint16_t PROGMEM combos_gt[]              = {RCTL_T(KC_G), KC_T, COMBO_END};
const uint16_t PROGMEM combos_hy[]              = {KC_H, KC_Y, COMBO_END};
const uint16_t PROGMEM combos_ju[]              = {LSFT_T(KC_J), KC_U, COMBO_END};
const uint16_t PROGMEM combos_ki[]              = {LCTL_T(KC_K), KC_I, COMBO_END};
const uint16_t PROGMEM combos_lo[]              = {LALT_T(KC_L), KC_O, COMBO_END};
const uint16_t PROGMEM combos_quotp[]           = {LGUI_T(KC_QUOT), KC_P, COMBO_END};
const uint16_t PROGMEM combos_fg[]              = {LSFT_T(KC_F), RCTL_T(KC_G), COMBO_END};
const uint16_t PROGMEM combos_hj[]              = {KC_H, LSFT_T(KC_J), COMBO_END};
const uint16_t PROGMEM combos_az[]              = {LGUI_T(KC_A), LT(U_BUTTON, KC_Z), COMBO_END};
const uint16_t PROGMEM combos_sx[]              = {LALT_T(KC_S), KC_X, COMBO_END};
const uint16_t PROGMEM combos_dc[]              = {LCTL_T(KC_D), KC_C, COMBO_END};
const uint16_t PROGMEM combos_fv[]              = {LSFT_T(KC_F), KC_V, COMBO_END};
const uint16_t PROGMEM combos_gb[]              = {RCTL_T(KC_G), KC_B, COMBO_END};
const uint16_t PROGMEM combos_hn[]              = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM combos_jm[]              = {LSFT_T(KC_J), KC_M, COMBO_END};
const uint16_t PROGMEM combos_kcomm[]           = {LCTL_T(KC_K), KC_COMM, COMBO_END};
const uint16_t PROGMEM combos_ldot[]            = {LALT_T(KC_L), KC_DOT, COMBO_END};
const uint16_t PROGMEM combos_quotslsh[]        = {LGUI_T(KC_QUOT), LT(U_BUTTON, KC_SLSH), COMBO_END};
const uint16_t PROGMEM combos_nm[]              = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM combos_mcomm[]           = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combos_commdot[]         = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combos_dotslsh[]         = {KC_DOT, LT(U_BUTTON, KC_SLSH), COMBO_END};

// clang-format off
combo_t                key_combos[]      = {COMBO(thumbcombos_base_right, LT(U_FUN, KC_DEL)),
                                            COMBO(thumbcombos_base_left, LT(U_MEDIA, KC_ESC)),
                                            COMBO(thumbcombos_nav, KC_DEL),
                                            COMBO(thumbcombos_mouse, KC_BTN3),
                                            COMBO(thumbcombos_media, KC_MUTE),
                                            COMBO(thumbcombos_num, MEH_T(KC_DOT)),
                                            COMBO(thumbcombos_sym, KC_RPRN),
                                            COMBO(thumbcombos_fun, KC_APP),
                                            COMBO(combos_cut, U_CUT),
                                            COMBO(combos_copy, U_CPY),
                                            COMBO(combos_paste, U_PST),
                                            COMBO(combos_qw, KC_WH_L),
                                            COMBO(combos_we, KC_WH_U),
                                            COMBO(combos_er, KC_WH_D),
                                            COMBO(combos_rt, KC_WH_R),
                                            COMBO(combos_yu, KC_LEFT),
                                            COMBO(combos_ui, KC_DOWN),
                                            COMBO(combos_io, KC_UP),
                                            COMBO(combos_op, KC_RGHT),
                                            COMBO(combos_aq, KC_EXLM),
                                            COMBO(combos_sw, KC_AT),
                                            COMBO(combos_de, KC_HASH),
                                            COMBO(combos_fr, KC_DLR),
                                            COMBO(combos_gt, KC_PERC),
                                            COMBO(combos_hy, KC_CIRC),
                                            COMBO(combos_ju, KC_AMPR),
                                            COMBO(combos_ki, KC_ASTR),
                                            COMBO(combos_lo, KC_LPRN),
                                            COMBO(combos_quotp, KC_RPRN),
                                            COMBO(combos_fg, KC_UNDS),
                                            COMBO(combos_hj, KC_MINS),
                                            COMBO(combos_az, KC_1),
                                            COMBO(combos_sx, KC_2),
                                            COMBO(combos_dc, KC_3),
                                            COMBO(combos_fv, KC_4),
                                            COMBO(combos_gb, KC_5),
                                            COMBO(combos_hn, KC_6),
                                            COMBO(combos_jm, KC_7),
                                            COMBO(combos_kcomm, KC_8),
                                            COMBO(combos_ldot, KC_9),
                                            COMBO(combos_quotslsh, KC_0),
                                            COMBO(combos_nm, KC_HOME),
                                            COMBO(combos_mcomm, KC_PGDN),
                                            COMBO(combos_commdot, KC_PGUP),
                                            COMBO(combos_dotslsh, KC_END)};
// clang-format on

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }

    return true;
}

void matrix_scan_user(void) {
    achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    switch (tap_hold_keycode) {
        case LGUI_T(KC_A):
        case LT(U_BUTTON, KC_Z):
            switch (other_keycode) {
                case KC_C:
                case KC_V:
                case KC_X:
                    return true;
            }
            break;
        case LGUI_T(KC_QUOT):
            switch (other_keycode) {
                case LALT_T(KC_L):
                case LT(U_NAV, KC_SPC):
                    return true;
            }
            break;
        case LT(U_FUN, KC_DEL):
        case LT(U_NUM, KC_BSPC):
        case LT(U_SYM, KC_ENT):
            switch (other_keycode) {
                case KC_Q:
                case LALT_T(KC_S):
                case LCTL_T(KC_D):
                case LGUI_T(KC_A):
                case LSFT_T(KC_F):
                    return true;
            }
            break;
        case LT(U_NAV, KC_SPACE):
            switch (other_keycode) {
                case KC_H:
                    return true;
            }
        case LT(U_MOUSE, KC_TAB):
            switch (other_keycode) {
                case KC_P:
                case LALT_T(KC_L):
                case LCTL_T(KC_K):
                case LGUI_T(KC_QUOT):
                case LSFT_T(KC_J):
                    return true;
            }
            break;
        case MEH_T(KC_ESC):
            return true;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    return TAPPING_TERM;
}

bool achordion_eager_mod(uint8_t mod) {
    switch (mod) {
        case MOD_LCTL:
        case MOD_LSFT:
            return true;
    }

    return false;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LALT_T(KC_L):
        case LCTL_T(KC_K):
        case LSFT_T(KC_J):
            return QUICK_TAP_TERM;
    }

    return 0;
}
