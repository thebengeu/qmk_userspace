#include QMK_KEYBOARD_H

// void caps_word_set_user(bool active) {
//     pimoroni_trackball_set_rgbw(active ? 0xff : 0, 0, 0, 0);
// }

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);
}
#endif
