#include QMK_KEYBOARD_H

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    // clang-format off
    [0] = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(S(C(KC_TAB)), C(KC_TAB))},
    [1] = {ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(QK_AREP, QK_REP)},
    [2] = {ENCODER_CCW_CW(KC_WH_L, KC_WH_R), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [3] = {ENCODER_CCW_CW(G(KC_MINS), G(KC_EQL)), ENCODER_CCW_CW(KC_U, C(KC_R))},
    [4] = {ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [5] = {ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_F1, KC_F2)},
    [6] = {ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_NO, KC_NO)},
    [7] = {ENCODER_CCW_CW(S(KC_H), S(KC_L)), ENCODER_CCW_CW(KC_NO, KC_NO)},
    [8] = {ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO)},
    [9] = {ENCODER_CCW_CW(KC_NO, KC_NO), ENCODER_CCW_CW(KC_NO, KC_NO)},
    // clang-format on
};
#endif

// void caps_word_set_user(bool active) {
//     pimoroni_trackball_set_rgbw(active ? 0xff : 0, 0, 0, 0);
// }

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);
}
#endif
