#include <stdint.h>

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif

#include "thebengeu.h"

#include "features/achordion.h"
#include "features/layer_lock.h"
#include "features/sentence_case.h"

enum layers { _BASE, _MS, _NUM, _SYM, _FUN, _MEH, _HYPR, _MEH_NUM, _HYPR_NUM };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x5_3(
    LT(_NUM,KC_Q),  KC_W,        KC_E,           KC_R,             KC_T,          KC_Y,           KC_U,             KC_I,           KC_O,          LT(_SYM,KC_P),
    GUI_T(KC_A),    ALT_T(KC_S), CTL_T(KC_D),    SFT_T(KC_F),      RCTL_T(KC_G),  KC_H,           SFT_T(KC_J),      CTL_T(KC_K),    ALT_T(KC_L),   GUI_T(KC_QUOT),
    LT(_MS,KC_Z),   KC_X,        KC_C,           KC_V,             KC_B,          KC_N,           KC_M,             LT(0,KC_COMM),  LT(0,KC_DOT),  LT(_FUN,KC_SLSH),
                                 QK_REP,         LT(_SYM,KC_BSPC), SFT_T(KC_ENT), LT(_MS,KC_TAB), LT(_NUM,KC_SPC),  LT(_MEH,KC_ESC)
  ),
  [_MS] = LAYOUT_split_3x5_3(
    KC_WH_U,        KC_WH_L,     KC_MS_U,        KC_WH_R,          QK_BOOT,       KC_MUTE,        G(KC_1),          G(KC_2),        G(KC_3),        KC_MPLY,
    KC_WH_D,        KC_MS_L,     KC_MS_D,        KC_MS_R,          KC_RCTL,       KC_VOLD,        SFT_T(GUI_4),     CTL_T(GUI_5),   ALT_T(GUI_6),   GUI_T(KC_VOLU),
    U_UND,          U_CUT,       U_CPY,          U_PST,            U_RDO,         KC_MPRV,        G(KC_7),          G(KC_8),        G(KC_9),        KC_MNXT,
                                 KC_BTN3,        KC_BTN1,          KC_BTN2,       LLOCK,          KC_NO,            KC_NO
  ),
  [_NUM] = LAYOUT_split_3x5_3(
    KC_PGUP,        KC_HOME,     KC_UP,          KC_END,           NW_COLN,       NW_DLR,         KC_1,             KC_2,           KC_3,           KC_PERC,
    KC_PGDN,        KC_LEFT,     KC_DOWN,        KC_RIGHT,         LT(1,KC_TILD), LT(1,KC_PLUS),  SFT_T(KC_4),      CTL_T(KC_5),    ALT_T(KC_6),    GUI_T(KC_0),
    LT(1,KC_LPRN),  KC_RPRN,     NW_TOGG,        KC_ASTR,          LT(0,KC_SLSH), LT(0,KC_COMM),  KC_7,             KC_8,           KC_9,           LT(0,KC_DOT),
                                 QK_AREP,        KC_BSPC,          KC_DEL,        KC_TAB,         LT(_SYM,KC_SPC),  KC_ESC
  ),
  [_SYM] = LAYOUT_split_3x5_3(
    LT(0,KC_BSLS),  G(KC_W),     LSG(KC_LBRC),   LSG(KC_RBRC),     G(KC_LBRC),    G(KC_RBRC),     LT(0,KC_EXLM),    LT(0,KC_AT),    LT(0,KC_HASH),  LT(1,KC_PIPE),
    GUI_T(KC_LCBR), ALT_T(RCBR), CTL_T(KC_LBRC), SFT_T(KC_RBRC),   KC_SCLN,       LT(0,KC_EQL),   SFT_T(KC_LPRN),   CTL_T(KC_RPRN), ALT_T(KC_GRV),  GUI_T(KC_COLN),
    SHIFT_GUI_TAB,  GUI_TAB,     CW_TOGG,        KC_CIRC,          G(KC_GRV),     KC_CAPS,        LT(0,KC_DLR),     LSA(KC_X),      LSA(KC_MINS),   LSA(KC_BSLS),
                                 KC_NO,          LLOCK,            KC_NO,         LT(0,KC_MINS),  LT(_FUN,KC_UNDS), LT(_MEH_NUM,KC_AMPR)
  ),
  [_FUN] = LAYOUT_split_3x5_3(
    KC_NO,          KC_F10,      KC_F11,         KC_F12,           KC_NO,         KC_NO,          KC_F1,            KC_F2,          KC_F3,          KC_NO,
    KC_LGUI,        KC_LALT,     KC_LCTL,        KC_LSFT,          KC_RCTL,       KC_NO,          KC_F4,            KC_F5,          KC_F6,          KC_NO,
    KC_NO,          DT_PRNT,     DT_UP,          DT_DOWN,          KC_NO,         KC_NO,          KC_F7,            KC_F8,          KC_F9,          KC_NO,
                                 KC_NO,          KC_NO,            LLOCK,         KC_NO,          KC_NO,            KC_NO
  ),
  [_MEH] = LAYOUT_split_3x5_3(
    MEH(KC_Q),      MEH(KC_W),   MEH(KC_E),      MEH(KC_R),        MEH(KC_T),     MEH(KC_Y),      MEH(KC_U),        MEH(KC_I),      MEH(KC_O),      MEH(KC_P),
    MEH(KC_A),      MEH(KC_S),   MEH(KC_D),      MEH(KC_F),        MEH(KC_G),     MEH(KC_H),      MEH(KC_J),        MEH(KC_K),      MEH(KC_L),      MEH(KC_QUOT),
    MEH(KC_Z),      MEH(KC_X),   MEH(KC_C),      MEH(KC_V),        MEH(KC_B),     MEH(KC_N),      MEH(KC_M),        MEH(KC_COMM),   MEH(KC_DOT),    MEH(KC_SLSH),
                                 KC_NO,          OSL(_MEH_NUM),    KC_NO,         KC_NO,          KC_NO,            KC_NO
  ),
  [_HYPR] = LAYOUT_split_3x5_3(
    HYPR(KC_Q),     HYPR(KC_W),  HYPR(KC_E),     HYPR(KC_R),       HYPR(KC_T),    HYPR(KC_Y),     HYPR(KC_U),       HYPR(KC_I),     HYPR(KC_O),     HYPR(KC_P),
    HYPR(KC_A),     HYPR(KC_S),  HYPR(KC_D),     HYPR(KC_F),       HYPR(KC_G),    HYPR(KC_H),     HYPR(KC_J),       HYPR(KC_K),     HYPR(KC_L),     HYPR(KC_QUOT),
    HYPR(KC_Z),     HYPR(KC_X),  HYPR(KC_C),     HYPR(KC_V),       HYPR(KC_B),    HYPR(KC_N),     HYPR(KC_M),       HYPR(KC_COMM),  HYPR(KC_DOT),   HYPR(KC_SLSH),
                                 KC_NO,          OSL(_HYPR_NUM),   KC_NO,         KC_NO,          KC_NO,            KC_NO
  ),
  [_MEH_NUM] = LAYOUT_split_3x5_3(
    KC_NO,          KC_NO,       KC_NO,          KC_NO,            KC_NO,         KC_NO,          MEH(KC_1),        MEH(KC_2),      MEH(KC_3),      KC_NO,
    KC_NO,          KC_NO,       KC_NO,          KC_NO,            KC_NO,         KC_NO,          MEH(KC_4),        MEH(KC_5),      MEH(KC_6),      KC_NO,
    KC_NO,          KC_NO,       KC_NO,          KC_NO,            KC_NO,         KC_NO,          MEH(KC_7),        MEH(KC_8),      MEH(KC_9),      KC_NO,
                                 KC_NO,          KC_NO,            KC_NO,         KC_NO,          KC_NO,            KC_NO
  ),
  [_HYPR_NUM] = LAYOUT_split_3x5_3(
    KC_NO,          KC_NO,       KC_NO,          KC_NO,            KC_NO,         KC_NO,          HYPR(KC_1),       HYPR(KC_2),     HYPR(KC_3),     KC_NO,
    KC_NO,          KC_NO,       KC_NO,          KC_NO,            KC_NO,         KC_NO,          HYPR(KC_4),       HYPR(KC_5),     HYPR(KC_6),     KC_NO,
    KC_NO,          KC_NO,       KC_NO,          KC_NO,            KC_NO,         KC_NO,          HYPR(KC_7),       HYPR(KC_8),     HYPR(KC_9),     KC_NO,
                                 KC_NO,          KC_NO,            KC_NO,         KC_NO,          KC_NO,            KC_NO
  )
};
// clang-format on

const uint16_t PROGMEM thumbcombos_base_left_left[]   = {QK_REP, LT(_SYM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_left_right[]  = {LT(_SYM, KC_BSPC), SFT_T(KC_ENT), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_right_left[]  = {LT(_MS, KC_TAB), LT(_NUM, KC_SPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_right_right[] = {LT(_NUM, KC_SPC), LT(_MEH, KC_ESC), COMBO_END};
const uint16_t PROGMEM thumbcombos_ms_left[]          = {KC_BTN1, KC_BTN2, COMBO_END};
const uint16_t PROGMEM thumbcombos_sym_right[]        = {LT(0, KC_MINS), LT(_FUN, KC_UNDS), COMBO_END};
const uint16_t PROGMEM thumbcombos_num_left_right[]   = {KC_BSPC, KC_DEL, COMBO_END};
const uint16_t PROGMEM thumbcombos_num_right_left[]   = {KC_TAB, LT(_SYM, KC_SPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_num_right_right[]  = {LT(_SYM, KC_SPC), KC_ESC, COMBO_END};
const uint16_t PROGMEM combos_qw[]                    = {LT(_NUM, KC_Q), KC_W, COMBO_END};
const uint16_t PROGMEM combos_qe[]                    = {LT(_NUM, KC_Q), KC_E, COMBO_END};
const uint16_t PROGMEM combos_we[]                    = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combos_er[]                    = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combos_et[]                    = {KC_E, KC_T, COMBO_END};
const uint16_t PROGMEM combos_rt[]                    = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM combos_yu[]                    = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM combos_yi[]                    = {KC_Y, KC_I, COMBO_END};
const uint16_t PROGMEM combos_ui[]                    = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combos_uo[]                    = {KC_U, KC_O, COMBO_END};
const uint16_t PROGMEM combos_io[]                    = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM combos_ip[]                    = {KC_I, LT(_SYM, KC_P), COMBO_END};
const uint16_t PROGMEM combos_op[]                    = {KC_O, LT(_SYM, KC_P), COMBO_END};
const uint16_t PROGMEM combos_aq[]                    = {GUI_T(KC_A), LT(_NUM, KC_Q), COMBO_END};
const uint16_t PROGMEM combos_sw[]                    = {ALT_T(KC_S), KC_W, COMBO_END};
const uint16_t PROGMEM combos_de[]                    = {CTL_T(KC_D), KC_E, COMBO_END};
const uint16_t PROGMEM combos_fr[]                    = {SFT_T(KC_F), KC_R, COMBO_END};
const uint16_t PROGMEM combos_gt[]                    = {RCTL_T(KC_G), KC_T, COMBO_END};
const uint16_t PROGMEM combos_hy[]                    = {KC_H, KC_Y, COMBO_END};
const uint16_t PROGMEM combos_ju[]                    = {SFT_T(KC_J), KC_U, COMBO_END};
const uint16_t PROGMEM combos_ki[]                    = {CTL_T(KC_K), KC_I, COMBO_END};
const uint16_t PROGMEM combos_lo[]                    = {ALT_T(KC_L), KC_O, COMBO_END};
const uint16_t PROGMEM combos_quotp[]                 = {GUI_T(KC_QUOT), LT(_SYM, KC_P), COMBO_END};
const uint16_t PROGMEM combos_dg[]                    = {CTL_T(KC_D), RCTL_T(KC_G), COMBO_END};
const uint16_t PROGMEM combos_fg[]                    = {SFT_T(KC_F), RCTL_T(KC_G), COMBO_END};
const uint16_t PROGMEM combos_hj[]                    = {KC_H, SFT_T(KC_J), COMBO_END};
const uint16_t PROGMEM combos_hk[]                    = {KC_H, CTL_T(KC_K), COMBO_END};
const uint16_t PROGMEM combos_az[]                    = {GUI_T(KC_A), LT(_MS, KC_Z), COMBO_END};
const uint16_t PROGMEM combos_sx[]                    = {ALT_T(KC_S), KC_X, COMBO_END};
const uint16_t PROGMEM combos_dc[]                    = {CTL_T(KC_D), KC_C, COMBO_END};
const uint16_t PROGMEM combos_fv[]                    = {SFT_T(KC_F), KC_V, COMBO_END};
const uint16_t PROGMEM combos_gb[]                    = {RCTL_T(KC_G), KC_B, COMBO_END};
const uint16_t PROGMEM combos_hn[]                    = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM combos_jm[]                    = {SFT_T(KC_J), KC_M, COMBO_END};
const uint16_t PROGMEM combos_kcomm[]                 = {CTL_T(KC_K), LT(0, KC_COMM), COMBO_END};
const uint16_t PROGMEM combos_ldot[]                  = {ALT_T(KC_L), LT(0, KC_DOT), COMBO_END};
const uint16_t PROGMEM combos_quotslsh[]              = {GUI_T(KC_QUOT), LT(_FUN, KC_SLSH), COMBO_END};
const uint16_t PROGMEM combos_zx[]                    = {LT(_MS, KC_Z), KC_X, COMBO_END};
const uint16_t PROGMEM combos_zc[]                    = {LT(_MS, KC_Z), KC_C, COMBO_END};
const uint16_t PROGMEM combos_xc[]                    = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combos_xv[]                    = {KC_X, KC_V, COMBO_END};
const uint16_t PROGMEM combos_cv[]                    = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combos_cb[]                    = {KC_C, KC_B, COMBO_END};
const uint16_t PROGMEM combos_vb[]                    = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM combos_nm[]                    = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM combos_ncomm[]                 = {KC_N, LT(0, KC_COMM), COMBO_END};
const uint16_t PROGMEM combos_mcomm[]                 = {KC_M, LT(0, KC_COMM), COMBO_END};
const uint16_t PROGMEM combos_mdot[]                  = {KC_M, LT(0, KC_DOT), COMBO_END};
const uint16_t PROGMEM combos_commdot[]               = {LT(0, KC_COMM), LT(0, KC_DOT), COMBO_END};
const uint16_t PROGMEM combos_commslsh[]              = {LT(0, KC_COMM), LT(_FUN, KC_SLSH), COMBO_END};
const uint16_t PROGMEM combos_dotslsh[]               = {LT(0, KC_DOT), LT(_FUN, KC_SLSH), COMBO_END};
const uint16_t PROGMEM combos_gbspc[]                 = {RCTL_T(KC_G), LT(_SYM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM combos_vbspc[]                 = {KC_V, LT(_SYM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM combos_bbspc[]                 = {KC_B, LT(_SYM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM combos_hspc[]                  = {KC_H, LT(_NUM, KC_SPC), COMBO_END};
const uint16_t PROGMEM combos_nspc[]                  = {KC_N, LT(_NUM, KC_SPC), COMBO_END};
const uint16_t PROGMEM combos_mspc[]                  = {KC_M, LT(_NUM, KC_SPC), COMBO_END};
const uint16_t PROGMEM combos_undsampr[]              = {LT(_FUN, KC_UNDS), LT(_MEH_NUM, KC_AMPR), COMBO_END};

// clang-format off
combo_t                key_combos[]      = {COMBO(thumbcombos_base_left_left, QK_AREP),
                                            COMBO(thumbcombos_base_left_right, GUI_T(CW_TOGG)),
                                            COMBO(thumbcombos_base_right_left, LT(_FUN,KC_UNDS)),
                                            COMBO(thumbcombos_base_right_right, HYPR_T(KC_MINS)),
                                            COMBO(thumbcombos_num_left_right, KC_ENT),
                                            COMBO(thumbcombos_num_right_left, KC_UNDS),
                                            COMBO(thumbcombos_num_right_right, KC_MINS),
                                            COMBO(thumbcombos_sym_right, LT(_MEH_NUM, KC_AMPR)),
                                            COMBO(thumbcombos_ms_left, KC_BTN3),
                                            COMBO(combos_qw, LSG(KC_LBRC)),
                                            COMBO(combos_qe, G(KC_W)),
                                            COMBO(combos_we, LSG(KC_RBRC)),
                                            COMBO(combos_er, KC_HOME),
                                            COMBO(combos_et, KC_PGDN),
                                            COMBO(combos_rt, KC_PGUP),
                                            COMBO(combos_yu, KC_PGDN),
                                            COMBO(combos_yi, KC_PGUP),
                                            COMBO(combos_ui, KC_END),
                                            COMBO(combos_io, LT(0, KC_EXLM)),
                                            COMBO(combos_ip, LT(0, KC_AT)),
                                            COMBO(combos_op, LT(0, KC_HASH)),
                                            COMBO(combos_aq, LT(1, KC_LCBR)),
                                            COMBO(combos_sw, KC_RCBR),
                                            COMBO(combos_de, KC_LBRC),
                                            COMBO(combos_fr, KC_RBRC),
                                            COMBO(combos_gt, KC_SCLN),
                                            COMBO(combos_hy, LT(1, KC_PLUS)),
                                            COMBO(combos_ju, LT(0, KC_LPRN)),
                                            COMBO(combos_ki, KC_RPRN),
                                            COMBO(combos_lo, LT(0, KC_GRV)),
                                            COMBO(combos_quotp, KC_COLN),
                                            COMBO(combos_dg, KC_DOWN),
                                            COMBO(combos_fg, KC_UP),
                                            COMBO(combos_hj, KC_DOWN),
                                            COMBO(combos_hk, KC_UP),
                                            COMBO(combos_az, LT(0, KC_BSLS)),
                                            COMBO(combos_sx, KC_ASTR),
                                            COMBO(combos_dc, KC_CIRC),
                                            COMBO(combos_fv, KC_LEFT),
                                            COMBO(combos_gb, LT(1, KC_TILD)),
                                            COMBO(combos_hn, LT(1, KC_PLUS)),
                                            COMBO(combos_jm, KC_RIGHT),
                                            COMBO(combos_kcomm, LT(0, KC_DLR)),
                                            COMBO(combos_ldot, KC_PERC),
                                            COMBO(combos_quotslsh, LT(1, KC_PIPE)),
                                            COMBO(combos_zx, U_CUT),
                                            COMBO(combos_zc, G(KC_GRV)),
                                            COMBO(combos_xc, U_CPY),
                                            COMBO(combos_xv, U_PST),
                                            COMBO(combos_cv, KC_WH_L),
                                            COMBO(combos_cb, KC_WH_D),
                                            COMBO(combos_vb, KC_WH_U),
                                            COMBO(combos_nm, KC_WH_D),
                                            COMBO(combos_ncomm, KC_WH_U),
                                            COMBO(combos_mcomm, KC_WH_R),
                                            COMBO(combos_mdot, LSA(KC_X)),
                                            COMBO(combos_commdot, LT(0, KC_AMPR)),
                                            COMBO(combos_commslsh, NW_DLR),
                                            COMBO(combos_dotslsh, NW_COLN),
                                            COMBO(combos_gbspc, KC_DEL),
                                            COMBO(combos_vbspc, LSA(KC_MINS)),
                                            COMBO(combos_bbspc, LSG(KC_TAB)),
                                            COMBO(combos_hspc, NW_TOGG),
                                            COMBO(combos_nspc, G(KC_TAB)),
                                            COMBO(combos_mspc, LSA(KC_BSLS)),
                                            COMBO(combos_undsampr, LT(_HYPR_NUM, KC_SPC))};
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
    if (!caps_word_press_user(keycode)) {
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
                SEND_STRING(shifted_string);
                register_mods(mods);
            } else {
                SEND_STRING(string);
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

bool is_gui_tab_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    const bool is_combo = record->event.type == COMBO_EVENT;
    uprintf("0x%04X,%u,%u,%u,%u,0x%02X,0x%02X,%u\n", keycode, is_combo ? 254 : record->event.key.row, is_combo ? 254 : record->event.key.col, get_highest_layer(layer_state), record->event.pressed, get_mods(), get_oneshot_mods(), record->tap.count);
#endif

    if (!process_layer_lock(keycode, record, LLOCK)) {
        return false;
    }

    if (is_caps_word_on() && get_repeat_key_count() > 0 && record->event.pressed) {
        tap_code16_caps_word(KC_UNDS);
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
        case GUI_T(KC_LCBR):
            if (record->tap.count && record->event.pressed) {
                tap_code16_caps_word(KC_LCBR);
                return false;
            }
            break;
        case ALT_T(RCBR):
            if (record->tap.count && record->event.pressed) {
                tap_code16_caps_word(KC_RCBR);
                return false;
            }
            break;
        case SFT_T(KC_LPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16_caps_word(KC_LPRN);
                return false;
            }
            break;
        case CTL_T(KC_RPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16_caps_word(KC_RPRN);
                return false;
            }
            break;
        case GUI_T(KC_COLN):
            if (record->tap.count && record->event.pressed) {
                tap_code16_caps_word(KC_COLN);
                return false;
            }
            break;
        case SFT_T(GUI_4):
            if (record->tap.count && record->event.pressed) {
                tap_code16_caps_word(G(KC_4));
                return false;
            }
            break;
        case CTL_T(GUI_5):
            if (record->tap.count && record->event.pressed) {
                tap_code16_caps_word(G(KC_5));
                return false;
            }
            break;
        case ALT_T(GUI_6):
            if (record->tap.count && record->event.pressed) {
                tap_code16_caps_word(G(KC_6));
                return false;
            }
            break;
        case GUI_T(CW_TOGG):
            if (record->tap.count && record->event.pressed) {
                caps_word_toggle();
                return false;
            }
            break;
        case LT(_FUN, KC_UNDS):
            if (record->tap.count && record->event.pressed) {
                tap_code16_caps_word(KC_UNDS);
                return false;
            }
            break;
        case LT(_MEH_NUM, KC_AMPR):
            if (record->tap.count && record->event.pressed) {
                tap_code16_caps_word(KC_AMPR);
                return false;
            }
            break;
        case NW_COLN:
            if (record->event.pressed) {
                is_num_word_on = true;
                caps_word_on();
                tap_code16_caps_word(KC_COLN);
                return false;
            }
            break;
        case NW_DLR:
            if (record->event.pressed) {
                is_num_word_on = true;
                caps_word_on();
                tap_code16_caps_word(KC_DLR);
                return false;
            }
            break;
        case NW_TOGG:
            if (record->event.pressed) {
                is_num_word_on = true;
                caps_word_toggle();
                return false;
            }
            break;
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
    if (is_gui_tab_active && !layer_state_is(_SYM)) {
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
        case GUI_T(KC_QUOT):
            switch (other_keycode) {
                case KC_H:
                case ALT_T(KC_L):
                case LT(_MS, KC_TAB):
                case LT(_NUM, KC_SPC):
                    return true;
            }
            break;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case LT(_SYM, KC_BSPC):
        case SFT_T(KC_ENT):
        case LT(_MS, KC_TAB):
        case LT(_NUM, KC_SPC):
        case LT(_MEH, KC_ESC):
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
