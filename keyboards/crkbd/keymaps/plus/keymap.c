#include QMK_KEYBOARD_H

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    // clang-format off
    [0] = {ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(S(C(KC_TAB)), C(KC_TAB))},
    [1] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_U, C(KC_R))},
    [2] = {ENCODER_CCW_CW(KC_PGDN, KC_PGUP), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [3] = {ENCODER_CCW_CW(KC_WH_L, KC_WH_R), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [4] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [5] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_UP, KC_DOWN)},
    [6] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(G(KC_EQL), G(KC_MINS))},
    [7] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_F2, KC_F1)},
    // clang-format on
};
#endif

void caps_word_set_user(bool active) {
    pimoroni_trackball_set_rgbw(active ? 0xff : 0, 0, 0, 0);
}

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);
}
#endif
