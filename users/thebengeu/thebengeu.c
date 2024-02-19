#include <stdint.h>

#include "thebengeu.h"

#include "features/achordion.h"
#include "features/layer_lock.h"
#include "features/sentence_case.h"

enum layers { _BASE, _FUN, _NUM, _SYM, _ADJ };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x5_3(
    LT(_SYM,KC_Q),  KC_W,           KC_E,           KC_R,           KC_T,             KC_Y,          KC_U,            KC_I,            KC_O,          LT(_NUM,KC_P),
    GUI_T(KC_A),    ALT_T(KC_S),    CTL_T(KC_D),    SFT_T(KC_F),    RCTL_T(KC_G),     KC_H,          SFT_T(KC_J),     CTL_T(KC_K),     ALT_T(KC_L),   GUI_T(KC_QUOT),
    LT(_FUN,KC_Z),  KC_X,           KC_C,           KC_V,           KC_B,             KC_N,          KC_M,            KC_COMM,         KC_DOT,        LT(_ADJ,KC_SLSH),
                                                    QK_REP,         LT(_NUM,KC_BSPC), SFT_T(KC_ENT), LT(_FUN,KC_TAB), LT(_SYM,KC_SPC), MEH_T(KC_ESC)
  ),
  [_FUN] = LAYOUT_split_3x5_3(
    KC_WH_U,        KC_WH_L,        KC_MS_U,        KC_WH_R,        QK_BOOT,          KC_MUTE,       G(KC_1),         G(KC_2),         G(KC_3),        KC_MPLY,
    KC_WH_D,        KC_MS_L,        KC_MS_D,        KC_MS_R,        KC_RCTL,          KC_VOLD,       SFT_T(G(KC_4)),  CTL_T(G(KC_5)),  ALT_T(G(KC_6)), GUI_T(KC_VOLU),
    U_UND,          U_CUT,          U_CPY,          U_PST,          U_RDO,            KC_MPRV,       G(KC_7),         G(KC_8),         G(KC_9),        KC_MNXT,
                                                    KC_BTN3,        KC_BTN1,          KC_BTN2,       LLOCK,           KC_NO,           KC_NO
  ),
  [_NUM] = LAYOUT_split_3x5_3(
    KC_TILD,        G(KC_W),        S(C(KC_TAB)),   C(KC_TAB),      KC_GRV,           KC_LBRC,       KC_1,            KC_2,            KC_3,           KC_RBRC,
    GUI_T(KC_LCBR), ALT_T(KC_RCBR), CTL_T(KC_LPRN), SFT_T(KC_RPRN), KC_COLN,          KC_PLUS,       KC_4,            KC_5,            KC_6,           LT(0, KC_EQL),
    KC_HASH,        KC_ASTR,        KC_CIRC,        LT(0,KC_DLR),   KC_PERC,          KC_COMM,       KC_7,            KC_8,            KC_9,           KC_DOT,
                                                    KC_NO,          LLOCK,            KC_NO,         KC_MINS,         LT(_ADJ,KC_SPC), MEH_T(KC_0)
  ),
  [_SYM] = LAYOUT_split_3x5_3(
    KC_PGUP,        KC_HOME,        KC_UP,          KC_END,         KC_CAPS,          KC_F1,         KC_F2,           KC_F3,           KC_F4,          KC_F5,
    KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       LT(0,CW_TOGG),    LT(0,KC_AT),   SFT_T(KC_UNDS),  CTL_T(KC_PIPE),  ALT_T(KC_AMPR), GUI_T(KC_EXLM),
    KC_F11,         KC_F12,         KC_BSLS,        KC_SCLN,        KC_NO,            KC_F6,         KC_F7,           KC_F8,           KC_F9,          KC_F10,
                                                    QK_AREP,        KC_BSPC,          KC_DEL,        KC_NO,           LLOCK,           KC_NO
  ),
  [_ADJ] = LAYOUT_split_3x5_3(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,            KC_NO,         KC_NO,           KC_NO,           KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,            KC_NO,         KC_NO,           KC_NO,           KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,            KC_NO,         KC_NO,           KC_NO,           KC_NO,          KC_NO,
                                                    KC_NO,          KC_NO,            KC_NO,         KC_NO,           KC_NO,           KC_NO
  )
};
// clang-format on

const uint16_t PROGMEM thumbcombos_base_left_left[]   = {QK_REP, LT(_NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_left_right[]  = {LT(_NUM, KC_BSPC), SFT_T(KC_ENT), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_right_left[]  = {LT(_FUN, KC_TAB), LT(_SYM, KC_SPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_right_right[] = {LT(_SYM, KC_SPC), MEH_T(KC_ESC), COMBO_END};
const uint16_t PROGMEM thumbcombos_fun_left[]         = {KC_BTN1, KC_BTN2, COMBO_END};
const uint16_t PROGMEM thumbcombos_sym_left[]         = {KC_BSPC, KC_DEL, COMBO_END};
const uint16_t PROGMEM thumbcombos_num_right[]        = {KC_MINS, LT(_ADJ, KC_SPC), COMBO_END};
const uint16_t PROGMEM combos_qw[]                    = {LT(_SYM, KC_Q), KC_W, COMBO_END};
const uint16_t PROGMEM combos_we[]                    = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combos_er[]                    = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combos_et[]                    = {KC_E, KC_T, COMBO_END};
const uint16_t PROGMEM combos_rt[]                    = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM combos_yu[]                    = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM combos_yi[]                    = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM combos_ui[]                    = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combos_io[]                    = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combos_op[]                    = {KC_O, LT(_NUM, KC_P), COMBO_END};
const uint16_t PROGMEM combos_aq[]                    = {GUI_T(KC_A), LT(_SYM, KC_Q), COMBO_END};
const uint16_t PROGMEM combos_sw[]                    = {ALT_T(KC_S), KC_W, COMBO_END};
const uint16_t PROGMEM combos_de[]                    = {CTL_T(KC_D), KC_E, COMBO_END};
const uint16_t PROGMEM combos_fr[]                    = {SFT_T(KC_F), KC_R, COMBO_END};
const uint16_t PROGMEM combos_gt[]                    = {RCTL_T(KC_G), KC_T, COMBO_END};
const uint16_t PROGMEM combos_hy[]                    = {KC_H, KC_Y, COMBO_END};
const uint16_t PROGMEM combos_ju[]                    = {SFT_T(KC_J), KC_U, COMBO_END};
const uint16_t PROGMEM combos_ki[]                    = {CTL_T(KC_K), KC_I, COMBO_END};
const uint16_t PROGMEM combos_lo[]                    = {ALT_T(KC_L), KC_O, COMBO_END};
const uint16_t PROGMEM combos_quotp[]                 = {GUI_T(KC_QUOT), LT(_NUM, KC_P), COMBO_END};
const uint16_t PROGMEM combos_dg[]                    = {CTL_T(KC_D), RCTL_T(KC_G), COMBO_END};
const uint16_t PROGMEM combos_fg[]                    = {SFT_T(KC_F), RCTL_T(KC_G), COMBO_END};
const uint16_t PROGMEM combos_hj[]                    = {KC_H, SFT_T(KC_J), COMBO_END};
const uint16_t PROGMEM combos_hk[]                    = {KC_H, CTL_T(KC_K), COMBO_END};
const uint16_t PROGMEM combos_az[]                    = {GUI_T(KC_A), LT(_FUN, KC_Z), COMBO_END};
const uint16_t PROGMEM combos_sx[]                    = {ALT_T(KC_S), KC_X, COMBO_END};
const uint16_t PROGMEM combos_dc[]                    = {CTL_T(KC_D), KC_C, COMBO_END};
const uint16_t PROGMEM combos_fv[]                    = {SFT_T(KC_F), KC_V, COMBO_END};
const uint16_t PROGMEM combos_gb[]                    = {RCTL_T(KC_G), KC_B, COMBO_END};
const uint16_t PROGMEM combos_hn[]                    = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM combos_jm[]                    = {SFT_T(KC_J), KC_M, COMBO_END};
const uint16_t PROGMEM combos_kcomm[]                 = {CTL_T(KC_K), KC_COMM, COMBO_END};
const uint16_t PROGMEM combos_ldot[]                  = {ALT_T(KC_L), KC_DOT, COMBO_END};
const uint16_t PROGMEM combos_quotslsh[]              = {GUI_T(KC_QUOT), LT(_ADJ, KC_SLSH), COMBO_END};
const uint16_t PROGMEM combos_zx[]                    = {LT(_FUN, KC_Z), KC_X, COMBO_END};
const uint16_t PROGMEM combos_xc[]                    = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combos_xv[]                    = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM combos_cv[]                    = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combos_cb[]                    = {KC_C, KC_B, COMBO_END};
const uint16_t PROGMEM combos_vb[]                    = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM combos_nm[]                    = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM combos_ncomm[]                 = {KC_N, KC_COMM, COMBO_END};
const uint16_t PROGMEM combos_mcomm[]                 = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combos_commdot[]               = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combos_dotslsh[]               = {KC_DOT, LT(_ADJ, KC_SLSH), COMBO_END};
const uint16_t PROGMEM combos_bbspc[]                 = {KC_B, LT(_NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM combos_nspc[]                  = {KC_N, LT(_SYM, KC_SPC), COMBO_END};

// clang-format off
combo_t                key_combos[]      = {COMBO(thumbcombos_base_left_left, QK_AREP),
                                            COMBO(thumbcombos_base_left_right, QK_REP),
                                            COMBO(thumbcombos_base_right_left, MEH_T(KC_ESC)),
                                            COMBO(thumbcombos_base_right_right, LT(0, CW_TOGG)),
                                            COMBO(thumbcombos_sym_left, QK_AREP),
                                            COMBO(thumbcombos_num_right, MEH_T(KC_0)),
                                            COMBO(thumbcombos_fun_left, KC_BTN3),
                                            COMBO(combos_qw, KC_TILD),
                                            COMBO(combos_we, KC_GRV),
                                            COMBO(combos_er, KC_HOME),
                                            COMBO(combos_et, KC_PGDN),
                                            COMBO(combos_rt, KC_PGUP),
                                            COMBO(combos_yu, KC_PGDN),
                                            COMBO(combos_yi, KC_PGDN),
                                            COMBO(combos_ui, KC_END),
                                            COMBO(combos_io, S(C(KC_TAB))),
                                            COMBO(combos_op, C(KC_TAB)),
                                            COMBO(combos_aq, KC_LCBR),
                                            COMBO(combos_sw, KC_LBRC),
                                            COMBO(combos_de, KC_LPRN),
                                            COMBO(combos_fr, KC_LEFT),
                                            COMBO(combos_gt, KC_COLN),
                                            COMBO(combos_hy, LT(0, KC_EQL)),
                                            COMBO(combos_ju, KC_RIGHT),
                                            COMBO(combos_ki, KC_RPRN),
                                            COMBO(combos_lo, KC_RBRC),
                                            COMBO(combos_quotp, KC_RCBR),
                                            COMBO(combos_dg, KC_DOWN),
                                            COMBO(combos_fg, KC_UP),
                                            COMBO(combos_hj, KC_DOWN),
                                            COMBO(combos_hk, KC_UP),
                                            COMBO(combos_az, KC_HASH),
                                            COMBO(combos_sx, KC_ASTR),
                                            COMBO(combos_dc, KC_CIRC),
                                            COMBO(combos_fv, LT(0, KC_DLR)),
                                            COMBO(combos_gb, KC_PERC),
                                            COMBO(combos_hn, LT(0,KC_AT)),
                                            COMBO(combos_jm, KC_UNDS),
                                            COMBO(combos_kcomm, KC_PIPE),
                                            COMBO(combos_ldot, KC_AMPR),
                                            COMBO(combos_quotslsh, KC_EXLM),
                                            COMBO(combos_zx, U_CUT),
                                            COMBO(combos_xc, U_CPY),
                                            COMBO(combos_xv, U_PST),
                                            COMBO(combos_cv, KC_WH_L),
                                            COMBO(combos_cb, KC_WH_D),
                                            COMBO(combos_vb, KC_WH_U),
                                            COMBO(combos_nm, KC_WH_D),
                                            COMBO(combos_ncomm, KC_WH_U),
                                            COMBO(combos_mcomm, KC_WH_R),
                                            COMBO(combos_commdot, KC_BSLS),
                                            COMBO(combos_dotslsh, KC_SCLN),
                                            COMBO(combos_bbspc, KC_PLUS),
                                            COMBO(combos_nspc, KC_MINS)};
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

static bool process_tap_or_long_press_key(keyrecord_t *record, const char *string) {
    if (record->tap.count == 0) {
        if (record->event.pressed) {
            SEND_STRING(string);
        }
        return false;
    }
    return true;
}

bool is_gui_tab_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_layer_lock(keycode, record, LLOCK)) {
        return false;
    }

    switch (keycode) {
        case GUI_TAB:
        case SHIFT_GUI_TAB: {
            uint16_t tab_or_shift_tab = keycode == GUI_TAB ? KC_TAB : S(KC_TAB);

            if (record->event.pressed) {
                if (!is_gui_tab_active) {
                    is_gui_tab_active = true;
                    register_code(KC_LGUI);
                }
                register_code16(tab_or_shift_tab);
            } else {
                unregister_code16(tab_or_shift_tab);
            }
        } break;
        case LT(_ADJ, CW_TOGG):
            if (record->tap.count && record->event.pressed) {
                caps_word_toggle();
                return false;
            }
            break;
        case GUI_T(KC_LCBR):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LCBR);
                return false;
            }
            break;
        case ALT_T(KC_RCBR):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RCBR);
                return false;
            }
            break;
        case CTL_T(KC_LPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LPRN);
                return false;
            }
            break;
        case SFT_T(KC_RPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RPRN);
                return false;
            }
            break;
        case SFT_T(KC_UNDS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_UNDS);
                return false;
            }
            break;
        case CTL_T(KC_PIPE):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PIPE);
                return false;
            }
            break;
        case ALT_T(KC_AMPR):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_AMPR);
                return false;
            }
            break;
        case GUI_T(KC_EXLM):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_EXLM);
                return false;
            }
            break;
        case SFT_T(G(KC_4)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(G(KC_4));
                return false;
            }
            break;
        case CTL_T(G(KC_5)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(G(KC_5));
                return false;
            }
            break;
        case ALT_T(G(KC_6)):
            if (record->tap.count && record->event.pressed) {
                tap_code16(G(KC_6));
                return false;
            }
            break;
        case SFT_T(KC_ENT):
            if (is_caps_word_on() && record->tap.count && record->event.pressed) {
                tap_code16(KC_UNDS);
                return false;
            }
            break;
        case LT(_FUN, KC_TAB):
            if (is_caps_word_on() && record->tap.count && record->event.pressed) {
                tap_code(KC_MINS);
                return false;
            }
            break;
        case LT(0, CW_TOGG):
            if (record->tap.count) {
                if (record->event.pressed) {
                    caps_word_toggle();
                    return false;
                }
            } else {
                if (record->event.pressed) {
                    tap_code(KC_CAPS);
                }
                return false;
            }
            return true;
        case LT(0, KC_DLR):
            if (record->tap.count) {
                if (record->event.pressed) {
                    tap_code16(KC_DLR);
                    return false;
                }
            } else {
                if (record->event.pressed) {
                    SEND_STRING("${}");
                    tap_code(KC_LEFT);
                }
                return false;
            }
            return true;
        case LT(0, KC_AT):
            if (record->tap.count) {
                if (record->event.pressed) {
                    tap_code16(KC_AT);
                    return false;
                }
            } else {
                if (record->event.pressed) {
                    SEND_STRING("beng@bengeu.com");
                }
                return false;
            }
            return true;
        case LT(0, KC_EQL):
            return process_tap_or_long_press_key(record, "=> ");
    }

    return process_achordion(keycode, record) && process_sentence_case(keycode, record);
}

void matrix_scan_user(void) {
    if (is_gui_tab_active && !layer_state_is(_NUM)) {
        unregister_code(KC_LGUI);
        is_gui_tab_active = false;
    }

    achordion_task();
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    switch (tap_hold_keycode) {
        case GUI_T(KC_A):
        case LT(_FUN, KC_Z):
            switch (other_keycode) {
                case KC_C:
                case KC_V:
                case KC_X:
                    return true;
            }
            break;
        case GUI_T(KC_QUOT):
            switch (other_keycode) {
                case KC_H:
                case ALT_T(KC_L):
                case LT(_SYM, KC_SPC):
                    return true;
            }
            break;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case LT(_NUM, KC_BSPC):
        case SFT_T(KC_ENT):
        case LT(_FUN, KC_TAB):
        case LT(_SYM, KC_SPC):
        case MEH_T(KC_ESC):
            return 0;
    }

    return TAPPING_TERM;
}

bool achordion_eager_mod(uint8_t mod) {
    return false;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_T(KC_L):
        case CTL_T(KC_K):
        case SFT_T(KC_J):
            return QUICK_TAP_TERM;
    }

    return 0;
}

// https://github.com/JBaguley/qmk_firmware/tree/crkbd-retrograde-keymap/keyboards/crkbd/keymaps/retrograde
#ifdef OLED_ENABLE
unsigned int state = 0;

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return is_keyboard_left() ? OLED_ROTATION_0 : rotation;
}

bool oled_task_user(void) {
    if (is_oled_on()) {
        if (last_input_activity_elapsed() > OLED_TIMEOUT) {
            oled_off();
        } else {
        }
    }

    return false;
}

void suspend_power_down_user(void) {
    oled_off();
}
#endif
