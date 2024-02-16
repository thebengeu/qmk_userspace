#include <stdint.h>

#include "thebengeu.h"

#include "features/achordion.h"
#include "features/sentence_case.h"

enum layers { _BASE, _BUTTON, _NAV, _MOUSE, _MEDIA, _NUM, _SYM, _FUN };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_3x5_3(
    KC_Q,             KC_W,          KC_E,          KC_R,             KC_T,            KC_Y,              KC_U,            KC_I,         KC_O,          KC_P,
    LGUI_T(KC_A),     LALT_T(KC_S),  LCTL_T(KC_D),  LSFT_T(KC_F),     RCTL_T(KC_G),    KC_H,              LSFT_T(KC_J),    LCTL_T(KC_K), LALT_T(KC_L),  LGUI_T(KC_QUOT),
    LT(_BUTTON,KC_Z), KC_X,          KC_C,          KC_V,             KC_B,            KC_N,              KC_M,            KC_COMM,      KC_DOT,        LT(_BUTTON,KC_SLSH),
                                     QK_REP,        LT(_NUM,KC_BSPC), LT(_SYM,KC_ENT), LT(_MOUSE,KC_TAB), LT(_NAV,KC_SPC), MEH_T(KC_ESC)
  ),
  [_BUTTON] = LAYOUT_split_3x5_3(
    KC_TRNS,          KC_TRNS,       KC_TRNS,       KC_TRNS,          KC_TRNS,         KC_TRNS,           KC_TRNS,         KC_TRNS,      KC_TRNS,       KC_TRNS,
    OSM(MOD_LGUI),    OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT),    KC_RCTL,         KC_TRNS,           KC_TRNS,         KC_TRNS,      KC_TRNS,       KC_TRNS,
    KC_TRNS,          U_CUT,         U_CPY,         U_PST,            KC_TRNS,         KC_TRNS,           KC_TRNS,         KC_TRNS,      KC_TRNS,       KC_TRNS,
                                     KC_BTN3,       KC_BTN1,          KC_BTN2,         KC_TRNS,           KC_TRNS,         KC_TRNS
  ),
  [_NAV] = LAYOUT_split_3x5_3(
    KC_PGUP,          KC_HOME,       KC_UP,         KC_END,           KC_INS,          KC_NO,             KC_NO,           KC_NO,        KC_NO,         QK_BOOT,
    KC_PGDN,          KC_LEFT,       KC_DOWN,       KC_RGHT,          CW_TOGG,         KC_CAPS,           OSM(MOD_LSFT),   OSM(MOD_LCTL),OSM(MOD_LALT), OSM(MOD_LGUI),
    U_UND,            U_CUT,         U_CPY,         U_PST,            U_RDO,           KC_BSLS,           KC_NO,           KC_NO,        KC_NO,         KC_NO,
                                     QK_AREP,       KC_BSPC,          KC_ENT,          KC_NO,             KC_NO,           KC_NO
  ),
  [_MOUSE] = LAYOUT_split_3x5_3(
    KC_WH_U,          KC_WH_L,       KC_MS_U,       KC_WH_R,          KC_NO,           KC_NO,             KC_NO,           KC_NO,        KC_NO,         QK_BOOT,
    KC_WH_D,          KC_MS_L,       KC_MS_D,       KC_MS_R,          KC_RCTL,         KC_NO,             OSM(MOD_LSFT),   OSM(MOD_LCTL),OSM(MOD_LALT), OSM(MOD_LGUI),
    U_UND,            U_CUT,         U_CPY,         U_PST,            U_RDO,           KC_NO,             KC_NO,           KC_NO,        KC_NO,         KC_NO,
                                     KC_BTN3,       KC_BTN1,          KC_BTN2,         KC_NO,             KC_NO,           KC_NO
  ),
  [_MEDIA] = LAYOUT_split_3x5_3(
    KC_NO,            KC_NO,         KC_VOLU,       KC_NO,            KC_NO,           KC_NO,             KC_NO,           KC_NO,        KC_NO,         QK_BOOT,
    KC_NO,            KC_MPRV,       KC_VOLD,       KC_MNXT,          KC_NO,           KC_NO,             OSM(MOD_LSFT),   OSM(MOD_LCTL),OSM(MOD_LALT), OSM(MOD_LGUI),
    KC_NO,            KC_NO,         KC_NO,         KC_NO,            KC_NO,           KC_NO,             KC_NO,           KC_NO,        KC_NO,         KC_NO,
                                     KC_MUTE,       KC_MPLY,          KC_MSTP,         KC_NO,             KC_NO,           KC_NO
  ),
  [_NUM] = LAYOUT_split_3x5_3(
    G(KC_Q),          G(KC_W),       G(KC_GRV),     SHIFT_GUI_TAB,    GUI_TAB,         KC_LBRC,           KC_1,            KC_2,         KC_3,          KC_RBRC,
    OSM(MOD_LGUI),    OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT),    KC_RCTL,         KC_EQL,            KC_4,            KC_5,         KC_6,          KC_SCLN,
    U_UND,            U_CUT,         U_CPY,         U_PST,            KC_PIPE,         KC_BSLS,           KC_7,            KC_8,         KC_9,          KC_GRV,
                                     KC_NO,         KC_NO,            KC_NO,           KC_MINS,           KC_0,            MEH_T(KC_DOT)
  ),
  [_SYM] = LAYOUT_split_3x5_3(
    QK_BOOT,          G(KC_MINS),    G(KC_EQL),     S(C(KC_TAB)),     C(KC_TAB),       KC_LCBR,           KC_EXLM,         KC_AT,        KC_HASH,       KC_RCBR,
    OSM(MOD_LGUI),    OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT),    KC_NO,           KC_PLUS,           KC_DLR,          KC_PERC,      KC_CIRC,       KC_COLN,
    KC_NO,            KC_NO,         KC_NO,         KC_NO,            KC_NO,           KC_PIPE,           KC_AMPR,         KC_ASTR,      KC_LPRN,       KC_TILD,
                                     KC_NO,         KC_NO,            KC_NO,           KC_UNDS,           KC_LPRN,         KC_RPRN
  ),
  [_FUN] = LAYOUT_split_3x5_3(
    QK_BOOT,          KC_NO,         KC_NO,         KC_NO,            DT_UP,           KC_PSCR,           KC_F1,           KC_F2,        KC_F3,         KC_F10,
    OSM(MOD_LGUI),    OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT),    DT_PRNT,         KC_SCRL,           KC_F4,           KC_F5,        KC_F6,         KC_F11,
    KC_NO,            KC_NO,         KC_NO,         KC_NO,            DT_DOWN,         KC_PAUS,           KC_F7,           KC_F8,        KC_F9,         KC_F12,
                                     KC_NO,         KC_NO,            KC_NO,           KC_TAB,            KC_SPC,          KC_APP
  )
};
// clang-format on

const uint16_t PROGMEM thumbcombos_base_left[]  = {LT(_SYM, KC_ENT), LT(_NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_right[] = {LT(_NAV, KC_SPC), LT(_MOUSE, KC_TAB), COMBO_END};
const uint16_t PROGMEM thumbcombos_nav[]        = {KC_ENT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM thumbcombos_mouse[]      = {KC_BTN2, KC_BTN1, COMBO_END};
const uint16_t PROGMEM thumbcombos_media[]      = {KC_MSTP, KC_MPLY, COMBO_END};
const uint16_t PROGMEM thumbcombos_num[]        = {KC_0, KC_MINS, COMBO_END};
const uint16_t PROGMEM thumbcombos_sym[]        = {KC_UNDS, KC_LPRN, COMBO_END};
const uint16_t PROGMEM thumbcombos_fun[]        = {KC_SPC, KC_TAB, COMBO_END};
const uint16_t PROGMEM combos_cut[]             = {LT(_BUTTON, KC_Z), KC_X, COMBO_END};
const uint16_t PROGMEM combos_copy[]            = {LT(_BUTTON, KC_Z), KC_C, COMBO_END};
const uint16_t PROGMEM combos_paste[]           = {LT(_BUTTON, KC_Z), KC_V, COMBO_END};
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
const uint16_t PROGMEM combos_az[]              = {LGUI_T(KC_A), LT(_BUTTON, KC_Z), COMBO_END};
const uint16_t PROGMEM combos_sx[]              = {LALT_T(KC_S), KC_X, COMBO_END};
const uint16_t PROGMEM combos_dc[]              = {LCTL_T(KC_D), KC_C, COMBO_END};
const uint16_t PROGMEM combos_fv[]              = {LSFT_T(KC_F), KC_V, COMBO_END};
const uint16_t PROGMEM combos_gb[]              = {RCTL_T(KC_G), KC_B, COMBO_END};
const uint16_t PROGMEM combos_hn[]              = {KC_H, KC_N, COMBO_END};
const uint16_t PROGMEM combos_jm[]              = {LSFT_T(KC_J), KC_M, COMBO_END};
const uint16_t PROGMEM combos_kcomm[]           = {LCTL_T(KC_K), KC_COMM, COMBO_END};
const uint16_t PROGMEM combos_ldot[]            = {LALT_T(KC_L), KC_DOT, COMBO_END};
const uint16_t PROGMEM combos_quotslsh[]        = {LGUI_T(KC_QUOT), LT(_BUTTON, KC_SLSH), COMBO_END};
const uint16_t PROGMEM combos_nm[]              = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM combos_mcomm[]           = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combos_commdot[]         = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combos_dotslsh[]         = {KC_DOT, LT(_BUTTON, KC_SLSH), COMBO_END};
const uint16_t PROGMEM combos_bbspc[]           = {KC_B, LT(_NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM combos_nspc[]            = {KC_N, LT(_NAV, KC_SPC), COMBO_END};

// clang-format off
combo_t                key_combos[]      = {COMBO(thumbcombos_base_left, LT(_FUN, KC_DEL)),
                                            COMBO(thumbcombos_base_right, LT(_MEDIA, KC_ESC)),
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
                                            COMBO(combos_we, KC_WH_D),
                                            COMBO(combos_er, KC_WH_U),
                                            COMBO(combos_rt, KC_WH_R),
                                            COMBO(combos_yu, KC_LEFT),
                                            COMBO(combos_ui, KC_DOWN),
                                            COMBO(combos_io, KC_UP),
                                            COMBO(combos_op, KC_RGHT),
                                            COMBO(combos_aq, KC_PLUS),
                                            COMBO(combos_sw, KC_EQL),
                                            COMBO(combos_de, KC_LCBR),
                                            COMBO(combos_fr, KC_LBRC),
                                            COMBO(combos_gt, KC_LPRN),
                                            COMBO(combos_hy, KC_RPRN),
                                            COMBO(combos_ju, KC_RBRC),
                                            COMBO(combos_ki, KC_RCBR),
                                            COMBO(combos_lo, KC_SCLN),
                                            COMBO(combos_quotp, KC_COLN),
                                            COMBO(combos_fg, KC_UNDS),
                                            COMBO(combos_hj, KC_MINS),
                                            COMBO(combos_az, KC_EXLM),
                                            COMBO(combos_sx, KC_AT),
                                            COMBO(combos_dc, KC_HASH),
                                            COMBO(combos_fv, KC_DLR),
                                            COMBO(combos_gb, KC_PERC),
                                            COMBO(combos_hn, KC_CIRC),
                                            COMBO(combos_jm, KC_AMPR),
                                            COMBO(combos_kcomm, KC_ASTR),
                                            COMBO(combos_ldot, KC_GRV),
                                            COMBO(combos_quotslsh, KC_TILD),
                                            COMBO(combos_nm, KC_HOME),
                                            COMBO(combos_mcomm, KC_PGDN),
                                            COMBO(combos_commdot, KC_PGUP),
                                            COMBO(combos_dotslsh, KC_END),
                                            COMBO(combos_bbspc, KC_PIPE),
                                            COMBO(combos_nspc, KC_BSLS)};
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

bool is_gui_tab_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
        case LGUI_T(KC_A):
        case LT(_BUTTON, KC_Z):
            switch (other_keycode) {
                case KC_C:
                case KC_V:
                case KC_X:
                    return true;
            }
            break;
        case LGUI_T(KC_QUOT):
            switch (other_keycode) {
                case KC_H:
                case LALT_T(KC_L):
                case LT(_NAV, KC_SPC):
                    return true;
            }
            break;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case LT(_FUN, KC_DEL):
        case LT(_MEDIA, KC_ESC):
        case LT(_MOUSE, KC_TAB):
        case LT(_NAV, KC_SPACE):
        case LT(_NUM, KC_BSPC):
        case LT(_SYM, KC_ENT):
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
        case LALT_T(KC_L):
        case LCTL_T(KC_K):
        case LSFT_T(KC_J):
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
