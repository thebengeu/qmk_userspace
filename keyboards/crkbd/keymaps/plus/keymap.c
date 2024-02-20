#include QMK_KEYBOARD_H

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    // clang-format off
    [0] = {ENCODER_CCW_CW(QK_REP, QK_AREP), ENCODER_CCW_CW(S(C(KC_TAB)), C(KC_TAB))},
    [1] = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_WH_R, KC_WH_L)},
    [2] = {ENCODER_CCW_CW(G(KC_MINS), G(KC_EQL)), ENCODER_CCW_CW(KC_U, C(KC_R))},
    [3] = {ENCODER_CCW_CW(KC_DOWN, KC_UP), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [4] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_F2, KC_F1)},
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
