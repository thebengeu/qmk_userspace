#include <stdint.h>

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif

#include "thebengeu.h"

enum layers {
    _BASE,
    _S,
    _MS,
    _NO,
    _SYM,
    _FUN,
    _MEH,
    _HYPR,
    _LCSG,
    _LSAG,
    _MNO,
    _HNO,
};

enum {
    DOT_TD,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x5_3_custom(
    LT(_SYM,KC_Q),  KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,              KC_U,            KC_I,           KC_O,           LT(_NO,KC_P),
    GUI_T(KC_A),    ALT_T(KC_S),    CTL_T(KC_D),    SFT_T(KC_F),    RCTL_T(KC_G),   RCTL_T(KC_H),      SFT_T(KC_J),     CTL_T(KC_K),    ALT_T(KC_L),    GUI_T(KC_QUOT),
    LT(_MS,KC_Z),   KC_X,           KC_C,           KC_V,           KC_B,           KC_N,              KC_M,            LT(0,KC_COMM),  TD(DOT_TD),     LT(_FUN,KC_SLSH),
                                    LT(_MS,KC_ESC), LT(_S,KC_BSPC), LT(_NO,KC_ENT), LT(_MEH,KC_TAB),   LT(_SYM,KC_SPC), KC_NO
  ),
  [_S] = LAYOUT_split_3x5_3_custom(
    S(KC_Q),        S(KC_W),        S(KC_E),        S(KC_R),        S(KC_T),        S(KC_Y),           S(KC_U),         S(KC_I),        S(KC_O),        S(KC_P),
    S(KC_A),        S(KC_S),        S(KC_D),        S(KC_F),        S(KC_G),        S(KC_H),           S(KC_J),         S(KC_K),        S(KC_L),        S(KC_QUOT),
    S(KC_Z),        S(KC_X),        S(KC_C),        S(KC_V),        S(KC_B),        S(KC_N),           S(KC_M),         S(KC_COMM),     S(KC_DOT),      S(KC_SLSH),
                                    KC_NO,          KC_NO,          KC_NO,          LT(_LCSG,KC_UNDS), QK_REP,          KC_NO
  ),
  [_MS] = LAYOUT_split_3x5_3_custom(
    KC_WH_U,        KC_WH_L,        KC_MS_U,        KC_WH_R,        KC_NO,          KC_MUTE,           G(KC_1),         G(KC_2),        G(KC_3),        KC_MPLY,
    KC_WH_D,        KC_MS_L,        KC_MS_D,        KC_MS_R,        KC_RCTL,        RCTL_T(KC_VOLD),   SFT_T(GUI_4),    CTL_T(GUI_5),   ALT_T(GUI_6),   GUI_T(KC_VOLU),
    U_UND,          U_CUT,          U_CPY,          U_PST,          U_RDO,          KC_MPRV,           G(KC_7),         G(KC_8),        G(KC_9),        KC_MNXT,
                                    KC_BTN3,        KC_BTN1,        KC_BTN2,        KC_BTN2,           KC_BTN1,         KC_NO
  ),
  [_NO] = LAYOUT_split_3x5_3_custom(
    LT(2,KC_EQL),   G(KC_W),        LSG(KC_LBRC),   LSG(KC_RBRC),   NW_DLR,         KC_ASTR,           KC_1,            KC_2,           KC_3,           LT(1,KC_PLUS),
    GUI_T(KC_TILD), ALT_T(KC_CIRC), CTL_T(KC_PERC), SFT_T(KC_UNDS), LT(0,KC_DLR),   LT(0,KC_EQL),      KC_4,            KC_5,           KC_6,           KC_COLN,
    G(KC_GRV),      SHIFT_GUI_TAB,  GUI_TAB,        G(KC_LBRC),     G(KC_RBRC),     LT(0,KC_COMM),     KC_7,            KC_8,           KC_9,           LT(0,KC_SLSH),
                                    KC_ESC,         KC_BSPC,        KC_ENT,         LT(_MNO,KC_MINS),  LT(_SYM,KC_0),   KC_NO
  ),
  [_SYM] = LAYOUT_split_3x5_3_custom(
    KC_NO,          LT(0,KC_AMPR),  KC_UP,          LT(1,KC_PIPE),  NW_COLN,        KC_NO,             LT(0,KC_EXLM),   LT(0,KC_AT),    LT(0,KC_HASH),  KC_NO,
    LT(0,KC_GRV),   KC_LEFT,        KC_DOWN,        KC_RIGHT,       LT(0,KC_BSLS),  RCTL_T(KC_ASTR),   SFT_T(KC_LPRN),  CTL_T(KC_LCBR), ALT_T(KC_LBRC), GUI_T(KC_SCLN),
    LSA(KC_X),      LSA(KC_MINS),   LSA(KC_BSLS),   KC_PGDN,        KC_PGUP,        KC_HOME,           KC_RPRN,         KC_RCBR,        KC_RBRC,        KC_END,
                                    KC_DEL,         KC_BSPC,        KC_ENT,         KC_NO,             KC_NO,           KC_NO
  ),
  [_FUN] = LAYOUT_split_3x5_3_custom(
    LT(0,CW_TOGG),  KC_F10,         KC_F11,         KC_F12,         KC_PAUS,        RGB_HUD,           KC_F1,           KC_F2,          KC_F3,          RGB_TOG,
    OSM(MOD_LGUI),  OSM(MOD_LALT),  OSM(MOD_LCTL),  OSM(MOD_LSFT),  OSM(MOD_RCTL),  RGB_SAD,           KC_F4,           KC_F5,          KC_F6,          RGB_MOD,
    KC_CAPS,        DT_PRNT,        DT_DOWN,        DT_UP,          KC_PSCR,        RGB_VAD,           KC_F7,           KC_F8,          KC_F9,          BL_STEP,
                                    KC_NO,          QK_BOOT,        KC_P1,          QK_REP,            QK_AREP,         KC_NO
  ),
  [_MEH] = LAYOUT_split_3x5_3_custom(
    MEH(KC_Q),      MEH(KC_W),      MEH(KC_E),      MEH(KC_R),      MEH(KC_T),      MEH(KC_Y),         MEH(KC_U),       MEH(KC_I),      MEH(KC_O),      MEH(KC_P),
    MEH(KC_A),      MEH(KC_S),      MEH(KC_D),      MEH(KC_F),      MEH(KC_G),      MEH(KC_H),         MEH(KC_J),       MEH(KC_K),      MEH(KC_L),      MEH(KC_QUOT),
    MEH(KC_Z),      MEH(KC_X),      MEH(KC_C),      MEH(KC_V),      MEH(KC_B),      MEH(KC_N),         MEH(KC_M),       MEH(KC_COMM),   MEH(KC_DOT),    MEH(KC_SLSH),
                                    KC_NO,          OSL(_LCSG),     OSL(_MNO),      KC_NO,             KC_NO,           KC_NO
  ),
  [_HYPR] = LAYOUT_split_3x5_3_custom(
    HYPR(KC_Q),     HYPR(KC_W),     HYPR(KC_E),     HYPR(KC_R),     HYPR(KC_T),     HYPR(KC_Y),        HYPR(KC_U),      HYPR(KC_I),     HYPR(KC_O),     HYPR(KC_P),
    HYPR(KC_A),     HYPR(KC_S),     HYPR(KC_D),     HYPR(KC_F),     HYPR(KC_G),     HYPR(KC_H),        HYPR(KC_J),      HYPR(KC_K),     HYPR(KC_L),     HYPR(KC_QUOT),
    HYPR(KC_Z),     HYPR(KC_X),     HYPR(KC_C),     HYPR(KC_V),     HYPR(KC_B),     HYPR(KC_N),        HYPR(KC_M),      HYPR(KC_COMM),  HYPR(KC_DOT),   HYPR(KC_SLSH),
                                    KC_NO,          OSL(_LSAG),     OSL(_HNO),      KC_NO,             KC_NO,           KC_NO
  ),
  [_LCSG] = LAYOUT_split_3x5_3_custom(
    LCSG(KC_Q),     LCSG(KC_W),     LCSG(KC_E),     LCSG(KC_R),     LCSG(KC_T),     LCSG(KC_Y),        LCSG(KC_U),      LCSG(KC_I),     LCSG(KC_O),     LCSG(KC_P),
    LCSG(KC_A),     LCSG(KC_S),     LCSG(KC_D),     LCSG(KC_F),     LCSG(KC_G),     LCSG(KC_H),        LCSG(KC_J),      LCSG(KC_K),     LCSG(KC_L),     LCSG(KC_QUOT),
    LCSG(KC_Z),     LCSG(KC_X),     LCSG(KC_C),     LCSG(KC_V),     LCSG(KC_B),     LCSG(KC_N),        LCSG(KC_M),      LCSG(KC_COMM),  LCSG(KC_DOT),   LCSG(KC_SLSH),
                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,             KC_NO,           KC_NO
  ),
  [_LSAG] = LAYOUT_split_3x5_3_custom(
    LSAG(KC_Q),     LSAG(KC_W),     LSAG(KC_E),     LSAG(KC_R),     LSAG(KC_T),     LSAG(KC_Y),        LSAG(KC_U),      LSAG(KC_I),     LSAG(KC_O),     LSAG(KC_P),
    LSAG(KC_A),     LSAG(KC_S),     LSAG(KC_D),     LSAG(KC_F),     LSAG(KC_G),     LSAG(KC_H),        LSAG(KC_J),      LSAG(KC_K),     LSAG(KC_L),     LSAG(KC_QUOT),
    LSAG(KC_Z),     LSAG(KC_X),     LSAG(KC_C),     LSAG(KC_V),     LSAG(KC_B),     LSAG(KC_N),        LSAG(KC_M),      LSAG(KC_COMM),  LSAG(KC_DOT),   LSAG(KC_SLSH),
                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,             KC_NO,           KC_NO
  ),
  [_MNO] = LAYOUT_split_3x5_3_custom(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,             MEH(KC_1),       MEH(KC_2),      MEH(KC_3),      KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,             MEH(KC_4),       MEH(KC_5),      MEH(KC_6),      KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,             MEH(KC_7),       MEH(KC_8),      MEH(KC_9),      KC_NO,
                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,             KC_NO,           KC_NO
  ),
  [_HNO] = LAYOUT_split_3x5_3_custom(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,             HYPR(KC_1),      HYPR(KC_2),     HYPR(KC_3),     KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,             HYPR(KC_4),      HYPR(KC_5),     HYPR(KC_6),     KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,             HYPR(KC_7),      HYPR(KC_8),     HYPR(KC_9),     KC_NO,
                                    KC_NO,          KC_NO,          KC_NO,          KC_NO,             KC_NO,           KC_NO
  )
};
// clang-format on

const uint16_t PROGMEM thumbcombos_base_left_left[]  = {LT(_MS, KC_ESC), LT(_S, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_left_right[] = {LT(_S, KC_BSPC), LT(_NO, KC_ENT), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_right_left[] = {LT(_MEH, KC_TAB), LT(_SYM, KC_SPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_s_right[]         = {LT(_LCSG, KC_UNDS), QK_REP, COMBO_END};
const uint16_t PROGMEM thumbcombos_ms_right[]        = {KC_BTN1, KC_BTN2, COMBO_END};
const uint16_t PROGMEM thumbcombos_num_left_left[]   = {KC_ESC, KC_BSPC, COMBO_END};
const uint16_t PROGMEM thumbcombos_num_left_right[]  = {KC_BSPC, KC_ENT, COMBO_END};
const uint16_t PROGMEM thumbcombos_num_right[]       = {LT(_MNO, KC_MINS), LT(_SYM, KC_0), COMBO_END};
const uint16_t PROGMEM thumbcombos_sym_left_left[]   = {KC_DEL, KC_BSPC, COMBO_END};
const uint16_t PROGMEM combos_fg[]                   = {SFT_T(KC_F), RCTL_T(KC_G), COMBO_END};
const uint16_t PROGMEM combos_hj[]                   = {RCTL_T(KC_H), SFT_T(KC_J), COMBO_END};
const uint16_t PROGMEM combos_rf[]                   = {KC_R, SFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM combos_uj[]                   = {KC_U, SFT_T(KC_J), COMBO_END};

// clang-format off
combo_t key_combos[] = {
    COMBO(thumbcombos_base_left_left, GUI_T(CW_TOGG)),
    COMBO(thumbcombos_base_left_right, LT(_FUN, KC_LBRC)),
    COMBO(thumbcombos_base_right_left, LT(_HYPR,KC_RBRC)),
    COMBO(thumbcombos_s_right, LT(_LSAG,KC_SPC)),
    COMBO(thumbcombos_ms_right, KC_BTN3),
    COMBO(thumbcombos_num_left_left, KC_TAB),
    COMBO(thumbcombos_num_left_right, KC_SPC),
    COMBO(thumbcombos_num_right, LT(_HNO, KC_DOT)),
    COMBO(thumbcombos_sym_left_left, NW_TOGG),
    COMBO(combos_rf, KC_UNDS),
    COMBO(combos_uj, KC_MINS),
    COMBO(combos_fg, QK_AREP),
    COMBO(combos_hj, QK_REP),
};
// clang-format on

static bool is_num_word_on = false;

void caps_word_set_user(bool active) {
    if (!is_num_word_on) {
        return;
    }

    if (active) {
        default_layer_set(1UL << _NO);
    } else {
        is_num_word_on = false;

        default_layer_set(1UL << _BASE);
        set_oneshot_layer(_NO, ONESHOT_START);
        clear_oneshot_layer_state(ONESHOT_PRESSED);
    }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_LEFT:
        case KC_MINS:
        case KC_RIGHT:
        case KC_UNDS:
            return true;
    }

    if (is_num_word_on) {
        switch (keycode) {
            case KC_ASTR:
            case KC_COLN:
            case KC_COMM:
            case KC_DLR:
            case KC_DOT:
            case KC_LPRN:
            case KC_PERC:
            case KC_PLUS:
            case KC_RPRN:
            case KC_SLSH:
            case KC_TILD:
                return true;
        }
    } else {
        switch (keycode) {
            case KC_A ... KC_Z:
                add_weak_mods(MOD_BIT(KC_LSFT));
                return true;
        }
    }

    return false;
}

void tap_code16_caps_word(uint16_t keycode) {
    if (is_caps_word_on() && !caps_word_press_user(keycode)) {
        caps_word_off();
    }

    tap_code16(keycode);
}

static bool process_tap_or_long_press_key(keyrecord_t *record, const char *string, const char *shifted_string) {
    const uint8_t mods         = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();

    if (record->tap.count == 0) {
        if (record->event.pressed) {
            if (shifted_string && (mods | oneshot_mods) & MOD_MASK_SHIFT) {
                del_oneshot_mods(MOD_MASK_SHIFT);
                unregister_mods(MOD_MASK_SHIFT);
                send_string(shifted_string);
                register_mods(mods);
            } else {
                send_string(string);
            }
        }
        return false;
    }
    return true;
}

static bool process_tap_or_long_press_shifted_key(keyrecord_t *record, const char *string, uint16_t keycode) {
    if (record->tap.count && record->event.pressed) {
        tap_code16_caps_word(keycode);
        return false;
    }

    return process_tap_or_long_press_key(record, string, NULL);
}

uint16_t last_brc               = 0;
uint16_t last_keycode_after_brc = 0;

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (mods) {
        case 0:
            if (keycode == last_keycode_after_brc) {
                return keycode;
            }

            switch (keycode) {
                case KC_U:
                    return C(KC_R);
                case G(KC_W):
                    return S(G(KC_T));
                case LT(_SYM, KC_SPC):
                    return S(KC_SPC);
            }
            break;
        case MOD_BIT(KC_LALT):
            switch (keycode) {
                case KC_H:
                    return A(KC_L);
                case SFT_T(KC_J):
                    return A(KC_K);
                case CTL_T(KC_K):
                    return A(KC_J);
                case ALT_T(KC_L):
                    return A(KC_H);
            }
            break;
        case MOD_BIT(KC_LCTL):
            switch (keycode) {
                case KC_R:
                    return KC_U;
                case LT(_MEH, KC_TAB):
                    return S(C(KC_TAB));
            }
            break;
        case MOD_BIT(KC_LGUI):
            switch (keycode) {
                case KC_W:
                    return S(G(KC_T));
            }
            break;
        case MOD_BIT(KC_LSFT):
            switch (keycode) {
                case LT(_SYM, KC_SPC):
                    return KC_SPC;
            }
            break;
        case MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT):
            switch (keycode) {
                case LT(_MEH, KC_TAB):
                    return C(KC_TAB);
            }
            break;
        case MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT):
            switch (keycode) {
                case KC_T:
                    return G(KC_W);
            }
            break;
    }

    return KC_TRNS;
}

bool is_gui_tab_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    const bool is_combo = record->event.type == COMBO_EVENT;
    uprintf("0x%04X,%u,%u,%u,%u,0x%02X,0x%02X,%u\n", keycode, is_combo ? 254 : record->event.key.row, is_combo ? 254 : record->event.key.col, get_highest_layer(layer_state), record->event.pressed, get_mods(), get_oneshot_mods(), record->tap.count);
#endif

    if (is_caps_word_on() && get_repeat_key_count() > 0 && record->event.pressed) {
        tap_code16_caps_word(KC_UNDS);
        return false;
    }

    if (keycode == last_keycode_after_brc && get_repeat_key_count() != 0) {
        if (record->event.pressed) {
            tap_code16_caps_word(get_repeat_key_count() > 0 ? last_brc : last_brc == KC_LBRC ? KC_RBRC : KC_LBRC);
            tap_code16_caps_word(last_keycode_after_brc);
        }
        return false;
    }

    if (((!IS_QK_MOD_TAP(keycode) && !IS_QK_LAYER_TAP(keycode)) || record->tap.count) && record->event.pressed) {
        if (last_keycode_after_brc) {
            last_brc               = 0;
            last_keycode_after_brc = 0;
        }

        if (keycode == ALT_T(KC_LBRC) || keycode == LT(_FUN, KC_LBRC)) {
            last_brc = KC_LBRC;
        } else if (keycode == LT(_HYPR, KC_RBRC) || keycode == KC_RBRC) {
            last_brc = KC_RBRC;
        } else if (last_brc) {
            last_keycode_after_brc = keycode;
        }

        switch (keycode) {
            case NW_TOGG:
                is_num_word_on = true;
                caps_word_toggle();
                return false;
            case GUI_T(KC_TILD):
                tap_code16_caps_word(KC_TILD);
                return false;
            case ALT_T(KC_CIRC):
                tap_code16_caps_word(KC_CIRC);
                return false;
            case CTL_T(KC_PERC):
                tap_code16_caps_word(KC_PERC);
                return false;
            case RCTL_T(KC_ASTR):
                tap_code16_caps_word(KC_ASTR);
                return false;
            case SFT_T(KC_LPRN):
                tap_code16_caps_word(KC_LPRN);
                return false;
            case CTL_T(KC_LCBR):
                tap_code16_caps_word(KC_LCBR);
                return false;
            case ALT_T(KC_LBRC):
                tap_code16_caps_word(KC_LBRC);
                return false;
            case SFT_T(KC_UNDS):
                tap_code16_caps_word(KC_UNDS);
                return false;
            case SFT_T(GUI_4):
                tap_code16_caps_word(G(KC_4));
                return false;
            case CTL_T(GUI_5):
                tap_code16_caps_word(G(KC_5));
                return false;
            case ALT_T(GUI_6):
                tap_code16_caps_word(G(KC_6));
                return false;
            case GUI_T(CW_TOGG):
                caps_word_toggle();
                return false;
            case LT(_LCSG, KC_UNDS):
                tap_code16_caps_word(KC_UNDS);
                return false;
            case LT(_FUN, KC_LBRC):
                tap_code16_caps_word(KC_LBRC);
                return false;
            case LT(_MEH, KC_TAB):
                if (is_caps_word_on()) {
                    tap_code16_caps_word(KC_UNDS);
                    return false;
                }
                break;
            case G(KC_GRV):
                if (is_num_word_on) {
                    tap_code16_caps_word(KC_TILD);
                    return false;
                }
                break;
            case NW_COLN:
                is_num_word_on = true;
                caps_word_on();
                tap_code16_caps_word(KC_COLN);
                return false;
            case NW_DLR:
                is_num_word_on = true;
                caps_word_on();
                tap_code16_caps_word(KC_DLR);
                return false;
        }
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
        case LT(0, KC_HASH):
            if (record->tap.count) {
                if (record->event.pressed) {
                    tap_code16_caps_word(KC_HASH);
                    return false;
                }
            } else {
                if (record->event.pressed) {
                    SEND_STRING("# ");
                    set_oneshot_mods(MOD_BIT(KC_LSFT));
                }
                return false;
            }
            return true;
        case LT(0, KC_AMPR):
            return process_tap_or_long_press_shifted_key(record, "&& ", KC_AMPR);
        case LT(0, KC_AT):
            return process_tap_or_long_press_shifted_key(record, "beng@bengeu.com", KC_AT);
        case LT(0, KC_BSLS):
            return process_tap_or_long_press_shifted_key(record, "\\\\", KC_BSLS);
        case LT(0, KC_COMM):
            return process_tap_or_long_press_key(record, ", ", "<= ");
        case LT(0, KC_DLR):
            return process_tap_or_long_press_shifted_key(record, "${}" SS_TAP(X_LEFT), KC_DLR);
        case LT(0, KC_DOT):
            return process_tap_or_long_press_key(record, "../", ">= ");
        case LT(0, KC_EQL):
            return process_tap_or_long_press_key(record, "=> ", "++ ");
        case LT(2, KC_EQL):
            if (record->tap.count) {
                if (record->event.pressed) {
                    SEND_STRING("=>");
                    return false;
                }
            } else {
                if (record->event.pressed) {
                    SEND_STRING("=> {}" SS_TAP(X_LEFT));
                }
                return false;
            }
            return true;
        case LT(0, KC_EXLM):
            return process_tap_or_long_press_shifted_key(record, "!== ", KC_EXLM);
        case LT(0, KC_GRV):
            return process_tap_or_long_press_key(record, "```", "~/");
        case LT(0, KC_LBRC):
            return process_tap_or_long_press_key(record, "[]" SS_TAP(X_LEFT), "{}" SS_TAP(X_LEFT));
        case LT(1, KC_LCBR):
            return process_tap_or_long_press_shifted_key(record, "{}" SS_TAP(X_LEFT), KC_LCBR);
        case LT(0, KC_LPRN):
            return process_tap_or_long_press_shifted_key(record, "()" SS_TAP(X_LEFT), KC_LPRN);
        case LT(0, KC_MINS):
            return process_tap_or_long_press_key(record, "--", "__");
        case LT(1, KC_PIPE):
            return process_tap_or_long_press_shifted_key(record, "|| ", KC_PIPE);
        case LT(1, KC_PLUS):
            return process_tap_or_long_press_shifted_key(record, "++ ", KC_PLUS);
        case LT(0, KC_SLSH):
            return process_tap_or_long_press_key(record, "// ", "?? ");
        case LT(1, KC_TILD):
            return process_tap_or_long_press_shifted_key(record, "~/", KC_TILD);
        case LT(1, KC_UNDS):
            return process_tap_or_long_press_shifted_key(record, "__", KC_UNDS);
    }

    return true;
}

void matrix_scan_user(void) {
    if (is_gui_tab_active && !layer_state_is(_NO)) {
        unregister_code(KC_LGUI);
        is_gui_tab_active = false;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_SYM, KC_Q):
        case LT(_NO, KC_P):
        case GUI_T(KC_A):
        case ALT_T(KC_S):
        case CTL_T(KC_D):
        case SFT_T(KC_F):
        case RCTL_T(KC_G):
        case RCTL_T(KC_H):
        case SFT_T(KC_J):
        case CTL_T(KC_K):
        case ALT_T(KC_L):
        case LT(_MS, KC_Z):
        case LT(_SYM, KC_SPC):
            return false;
        default:
            return true;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RCTL_T(KC_H):
        case SFT_T(KC_J):
        case CTL_T(KC_K):
        case ALT_T(KC_L):
        case RCTL_T(KC_VOLD):
        case GUI_T(KC_VOLU):
            return QUICK_TAP_TERM;
    }

    return 0;
}

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP,
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD,
} td_state_t;

typedef struct {
    bool       is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(tap_dance_state_t *state) {
    switch (state->count) {
        case 1:
            return state->interrupted || !state->pressed ? TD_SINGLE_TAP : TD_SINGLE_HOLD;
        case 2:
            return state->interrupted ? TD_DOUBLE_SINGLE_TAP : state->pressed ? TD_DOUBLE_HOLD : TD_DOUBLE_TAP;
        case 3:
            return state->interrupted || !state->pressed ? TD_TRIPLE_TAP : TD_TRIPLE_HOLD;
        default:
            return TD_UNKNOWN;
    }
}

static td_tap_t dot_tap_state = {.is_press_action = true, .state = TD_NONE};

void dot_finished(tap_dance_state_t *state, void *user_data) {
    const uint8_t mods         = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();
    const uint8_t weak_mods    = get_weak_mods();
    const bool    is_shifted   = (mods | oneshot_mods | weak_mods) & MOD_MASK_SHIFT;

    dot_tap_state.state = cur_dance(state);

    switch (dot_tap_state.state) {
        case TD_SINGLE_TAP:
            register_code(KC_DOT);
            break;
        case TD_SINGLE_HOLD:
            if (is_shifted) {
                del_weak_mods(MOD_MASK_SHIFT);
                del_oneshot_mods(MOD_MASK_SHIFT);
                unregister_mods(MOD_MASK_SHIFT);
                send_string(">= ");
                register_mods(mods);
                set_weak_mods(weak_mods);
            } else {
                send_string("../");
            }
            break;
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_SINGLE_TAP:
            tap_code(KC_DOT);

            if (is_shifted) {
                register_code(KC_DOT);
            } else {
                tap_code(KC_SPC);
                add_oneshot_mods(MOD_BIT(KC_LSFT));
            }
            break;
        case TD_DOUBLE_HOLD:
            tap_code(KC_DOT);
            register_code(KC_DOT);
            break;
        case TD_TRIPLE_TAP:
        case TD_TRIPLE_HOLD:
            tap_code(KC_DOT);
            tap_code(KC_DOT);
            register_code(KC_DOT);
        default:
            break;
    }
}

void dot_reset(tap_dance_state_t *state, void *user_data) {
    switch (dot_tap_state.state) {
        case TD_SINGLE_TAP:
        case TD_DOUBLE_TAP:
        case TD_DOUBLE_HOLD:
        case TD_DOUBLE_SINGLE_TAP:
        case TD_TRIPLE_TAP:
        case TD_TRIPLE_HOLD:
            unregister_code(KC_DOT);
            break;
        default:
            break;
    }

    dot_tap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [DOT_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dot_finished, dot_reset),
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return is_keyboard_left() ? OLED_ROTATION_0 : rotation;
}

bool oled_task_user(void) {
    if (is_oled_on() && last_input_activity_elapsed() > OLED_TIMEOUT) {
        oled_off();
    }

    return false;
}

void suspend_power_down_user(void) {
    oled_off();
}
#endif
