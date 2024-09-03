#include QMK_KEYBOARD_H

#ifdef DIP_SWITCH_ENABLE
bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                register_code(KC_BTN1);
            } else {
                unregister_code(KC_BTN1);
            }
            break;
        case 1:
            if (active) {
                register_code(KC_DOWN);
            } else {
                unregister_code(KC_DOWN);
            }
            break;
        case 2:
            if (active) {
                register_code(KC_RGHT);
            } else {
                unregister_code(KC_RGHT);
            }
            break;
        case 3:
            if (active) {
                register_code(KC_UP);
            } else {
                unregister_code(KC_UP);
            }
            break;
        case 4:
            if (active) {
                register_code(KC_LEFT);
            } else {
                unregister_code(KC_LEFT);
            }
            break;
    }
    return true;
}
#endif

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    // clang-format off
    [0] = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(S(C(KC_TAB)), C(KC_TAB))},
    [1] = {ENCODER_CCW_CW(QK_AREP, QK_REP), ENCODER_CCW_CW(KC_WH_L, KC_WH_R)},
    [2] = {ENCODER_CCW_CW(G(KC_MINS), G(KC_EQL)), ENCODER_CCW_CW(KC_U, C(KC_R))},
    [3] = {ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [4] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_F1, KC_F2)},
    [5] = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(S(C(KC_TAB)), C(KC_TAB))},
    [6] = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(S(C(KC_TAB)), C(KC_TAB))},
    [7] = {ENCODER_CCW_CW(G(KC_MINS), G(KC_EQL)), ENCODER_CCW_CW(KC_U, C(KC_R))},
    [8] = {ENCODER_CCW_CW(G(KC_MINS), G(KC_EQL)), ENCODER_CCW_CW(KC_U, C(KC_R))},
    // clang-format on
};
#endif
