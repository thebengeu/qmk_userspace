#include <stdint.h>

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif

#include "thebengeu.h"

#include "features/achordion.h"
#include "features/sentence_case.h"

enum layers { _BASE, _MS, _NUM, _SYM, _FUN, _MEH, _HYPR, _MEH_NUM, _HYPR_NUM };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x5_3_custom(
    LT(_SYM,KC_Q),  KC_W,           KC_E,           KC_R,             KC_T,          KC_Y,                KC_U,             KC_I,           KC_O,          LT(_NUM,KC_P),
    GUI_T(KC_A),    ALT_T(KC_S),    CTL_T(KC_D),    SFT_T(KC_F),      RCTL_T(KC_G),  RCTL_T(KC_H),        SFT_T(KC_J),      CTL_T(KC_K),    ALT_T(KC_L),   GUI_T(KC_QUOT),
    LT(_MS,KC_Z),   KC_X,           KC_C,           KC_V,             KC_B,          KC_N,                KC_M,             LT(0,KC_COMM),  LT(0,KC_DOT),  LT(_FUN,KC_SLSH),
                                    LT(_FUN,KC_ESC),LT(_NUM,KC_BSPC), LT(_MS,KC_ENT),LT(_MEH,KC_TAB),     LT(_SYM,KC_SPC),  KC_NO
  ),
  [_MS] = LAYOUT_split_3x5_3_custom(
    KC_WH_U,        KC_WH_L,        KC_MS_U,        KC_WH_R,          QK_BOOT,       KC_MUTE,             G(KC_1),          G(KC_2),        G(KC_3),        KC_MPLY,
    KC_WH_D,        KC_MS_L,        KC_MS_D,        KC_MS_R,          KC_RCTL,       RCTL_T(KC_VOLD),     SFT_T(GUI_4),     CTL_T(GUI_5),   ALT_T(GUI_6),   GUI_T(KC_VOLU),
    U_UND,          U_CUT,          U_CPY,          U_PST,            U_RDO,         KC_MPRV,             G(KC_7),          G(KC_8),        G(KC_9),        KC_MNXT,
                                    KC_BTN3,        KC_BTN1,          KC_BTN2,       KC_BTN2,             KC_BTN1,          KC_NO
  ),
  [_NUM] = LAYOUT_split_3x5_3_custom(
    G(KC_GRV),      G(KC_W),        LSG(KC_LBRC),   LSG(KC_RBRC),     G(KC_T),       KC_ASTR,             KC_1,             KC_2,           KC_3,           LT(1,KC_PLUS),
    GUI_T(KC_LCBR), ALT_T(RCBR),    CTL_T(KC_LPRN), SFT_T(KC_RPRN),   LT(0,KC_DLR),  LT(0,KC_EQL),        KC_4,             KC_5,           KC_6,           KC_COLN,
    KC_PERC,        SHIFT_GUI_TAB,  GUI_TAB,        NW_TOGG,          NW_DLR,        LT(0,KC_COMM),       KC_7,             KC_8,           KC_9,           LT(0,KC_SLSH),
                                    KC_ESC,         KC_BSPC,          KC_ENT,        LT(_MEH_NUM,KC_MINS),LT(_SYM,KC_0),    KC_NO
  ),
  [_SYM] = LAYOUT_split_3x5_3_custom(
    LT(1,KC_TILD),  KC_CIRC,        KC_UP,          LT(0,KC_DLR),     G(KC_LBRC),    G(KC_RBRC),          LT(0,KC_EXLM),    LT(0,KC_AT),    LT(0,KC_HASH),  LT(2,KC_EQL),
    LT(0,KC_GRV),   KC_LEFT,        KC_DOWN,        KC_RIGHT,         LT(0,KC_BSLS), RCTL_T(KC_ASTR),     SFT_T(KC_UNDS),   CTL_T(KC_LBRC), ALT_T(KC_RBRC), GUI_T(KC_SCLN),
    LT(0,KC_AMPR),  LSA(KC_X),      LSA(KC_MINS),   LSA(KC_BSLS),     NW_COLN,       KC_HOME,             KC_PGDN,          KC_PGUP,        KC_END,         LT(1,KC_PIPE),
                                    KC_DEL,         KC_BSPC,          KC_ENT,        KC_NO,               KC_NO,            KC_NO
  ),
  [_FUN] = LAYOUT_split_3x5_3_custom(
    LT(0,CW_TOGG),  KC_F10,         KC_F11,         KC_F12,           KC_NO,         RGB_HUD,             KC_F1,            KC_F2,          KC_F3,          RGB_TOG,
    OSM(MOD_LGUI),  OSM(MOD_LALT),  OSM(MOD_LCTL),  OSM(MOD_LSFT),    OSM(MOD_RCTL), RGB_SAD,             KC_F4,            KC_F5,          KC_F6,          RGB_MOD,
    KC_CAPS,        DT_PRNT,        DT_UP,          DT_DOWN,          KC_NO,         RGB_VAD,             KC_F7,            KC_F8,          KC_F9,          BL_STEP,
                                    KC_NO,          KC_NO,            KC_NO,         QK_AREP,             QK_REP,           KC_NO
  ),
  [_MEH] = LAYOUT_split_3x5_3_custom(
    MEH(KC_Q),      MEH(KC_W),      MEH(KC_E),      MEH(KC_R),        MEH(KC_T),     MEH(KC_Y),           MEH(KC_U),        MEH(KC_I),      MEH(KC_O),      MEH(KC_P),
    MEH(KC_A),      MEH(KC_S),      MEH(KC_D),      MEH(KC_F),        MEH(KC_G),     MEH(KC_H),           MEH(KC_J),        MEH(KC_K),      MEH(KC_L),      MEH(KC_QUOT),
    MEH(KC_Z),      MEH(KC_X),      MEH(KC_C),      MEH(KC_V),        MEH(KC_B),     MEH(KC_N),           MEH(KC_M),        MEH(KC_COMM),   MEH(KC_DOT),    MEH(KC_SLSH),
                                    KC_NO,          OSL(_MEH_NUM),    KC_NO,         KC_NO,               KC_NO,            KC_NO
  ),
  [_HYPR] = LAYOUT_split_3x5_3_custom(
    HYPR(KC_Q),     HYPR(KC_W),     HYPR(KC_E),     HYPR(KC_R),       HYPR(KC_T),    HYPR(KC_Y),          HYPR(KC_U),       HYPR(KC_I),     HYPR(KC_O),     HYPR(KC_P),
    HYPR(KC_A),     HYPR(KC_S),     HYPR(KC_D),     HYPR(KC_F),       HYPR(KC_G),    HYPR(KC_H),          HYPR(KC_J),       HYPR(KC_K),     HYPR(KC_L),     HYPR(KC_QUOT),
    HYPR(KC_Z),     HYPR(KC_X),     HYPR(KC_C),     HYPR(KC_V),       HYPR(KC_B),    HYPR(KC_N),          HYPR(KC_M),       HYPR(KC_COMM),  HYPR(KC_DOT),   HYPR(KC_SLSH),
                                    KC_NO,          OSL(_HYPR_NUM),   KC_NO,         KC_NO,               KC_NO,            KC_NO
  ),
  [_MEH_NUM] = LAYOUT_split_3x5_3_custom(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,            KC_NO,         KC_NO,               MEH(KC_1),        MEH(KC_2),      MEH(KC_3),      KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,            KC_NO,         KC_NO,               MEH(KC_4),        MEH(KC_5),      MEH(KC_6),      KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,            KC_NO,         KC_NO,               MEH(KC_7),        MEH(KC_8),      MEH(KC_9),      KC_NO,
                                    KC_NO,          KC_NO,            KC_NO,         KC_NO,               KC_NO,            KC_NO
  ),
  [_HYPR_NUM] = LAYOUT_split_3x5_3_custom(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,            KC_NO,         KC_NO,               HYPR(KC_1),       HYPR(KC_2),     HYPR(KC_3),     KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,            KC_NO,         KC_NO,               HYPR(KC_4),       HYPR(KC_5),     HYPR(KC_6),     KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_NO,            KC_NO,         KC_NO,               HYPR(KC_7),       HYPR(KC_8),     HYPR(KC_9),     KC_NO,
                                    KC_NO,          KC_NO,            KC_NO,         KC_NO,               KC_NO,            KC_NO
  )
};
// clang-format on

const uint16_t PROGMEM thumbcombos_base_left_left[]  = {LT(_FUN, KC_ESC), LT(_NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_left_right[] = {LT(_NUM, KC_BSPC), LT(_MS, KC_ENT), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_right_left[] = {LT(_MEH, KC_TAB), LT(_SYM, KC_SPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_ms_right[]        = {KC_BTN1, KC_BTN2, COMBO_END};
const uint16_t PROGMEM thumbcombos_num_left_left[]   = {KC_ESC, KC_BSPC, COMBO_END};
const uint16_t PROGMEM thumbcombos_num_left_right[]  = {KC_BSPC, KC_ENT, COMBO_END};
const uint16_t PROGMEM thumbcombos_num_right[]       = {LT(_MEH_NUM, KC_MINS), LT(_SYM, KC_0), COMBO_END};
const uint16_t PROGMEM combos_fg[]                   = {SFT_T(KC_F), RCTL_T(KC_G), COMBO_END};
const uint16_t PROGMEM combos_hj[]                   = {RCTL_T(KC_H), SFT_T(KC_J), COMBO_END};
const uint16_t PROGMEM combos_bbspc[]                = {KC_B, LT(_NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM combos_nspc[]                 = {KC_N, LT(_SYM, KC_SPC), COMBO_END};

// clang-format off
combo_t key_combos[] = {COMBO(thumbcombos_base_left_left, GUI_T(UNDS)),
                        COMBO(thumbcombos_base_left_right, SFT_T(CW_TOGG)),
                        COMBO(thumbcombos_base_right_left, LT(_HYPR,NW_TOGG)),
                        COMBO(thumbcombos_ms_right, KC_BTN3),
                        COMBO(thumbcombos_num_left_left, KC_TAB),
                        COMBO(thumbcombos_num_left_right, KC_SPC),
                        COMBO(thumbcombos_num_right, LT(_HYPR_NUM, KC_DOT)),
                        COMBO(combos_fg, QK_AREP),
                        COMBO(combos_hj, QK_REP),
                        COMBO(combos_bbspc, LT(0, KC_LBRC)),
                        COMBO(combos_nspc, LT(0, KC_RBRC))};
// clang-format on

static bool is_num_word_on = false;

void caps_word_set_user(bool active) {
    if (!is_num_word_on) {
        return;
    }

    if (active) {
        default_layer_set(1UL << _NUM);
    } else {
        is_num_word_on = false;

        default_layer_set(1UL << _BASE);
        set_oneshot_layer(_NUM, ONESHOT_START);
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

        if (keycode == CTL_T(KC_LBRC) || keycode == LT(0, KC_LBRC)) {
            last_brc = KC_LBRC;
        } else if (keycode == SFT_T(KC_RBRC) || keycode == KC_RBRC) {
            last_brc = KC_RBRC;
        } else if (last_brc) {
            last_keycode_after_brc = keycode;
        }

        switch (keycode) {
            case NW_TOGG:
            case LT(_HYPR, NW_TOGG):
                is_num_word_on = true;
                caps_word_toggle();
                return false;
            case GUI_T(KC_LCBR):
                tap_code16_caps_word(KC_LCBR);
                return false;
            case ALT_T(RCBR):
                tap_code16_caps_word(KC_RCBR);
                return false;
            case CTL_T(KC_LPRN):
                tap_code16_caps_word(KC_LPRN);
                return false;
            case SFT_T(KC_RPRN):
                tap_code16_caps_word(KC_RPRN);
                return false;
            case RCTL_T(KC_ASTR):
                tap_code16_caps_word(KC_ASTR);
                return false;
            case SFT_T(KC_UNDS):
                tap_code16_caps_word(KC_UNDS);
                return false;
            case ALT_T(KC_RBRC):
                tap_code16_caps_word(KC_RBRC);
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
            case SFT_T(CW_TOGG):
                caps_word_toggle();
                return false;
            case GUI_T(UNDS):
                tap_code16_caps_word(KC_UNDS);
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
        case LT(_MS, KC_Z):
            switch (other_keycode) {
                case KC_C:
                case KC_V:
                case KC_X:
                    return true;
            }
            break;
        case CTL_T(KC_K):
            switch (other_keycode) {
                case LT(_SYM, KC_SPC):
                    return true;
            }
        case SFT_T(KC_J):
            switch (other_keycode) {
                case LT(_MEH, KC_TAB):
                    return true;
            }
            break;
        case ALT_T(KC_L):
            switch (other_keycode) {
                case LT(_MEH, KC_TAB):
                case LT(_SYM, KC_SPC):
                    return true;
            }
            break;
        case GUI_T(KC_QUOT):
            switch (other_keycode) {
                case KC_H:
                case ALT_T(KC_L):
                case LT(_MEH, KC_TAB):
                case LT(_SYM, KC_SPC):
                    return true;
            }
            break;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case LT(_FUN, KC_ESC):
        case LT(_NUM, KC_BSPC):
        case LT(_MS, KC_ENT):
        case LT(_MEH, KC_TAB):
        case LT(_SYM, KC_SPC):
            return 0;
    }

    return TAPPING_TERM;
}

bool achordion_eager_mod(uint8_t mod) {
    return false;
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
