#include QMK_KEYBOARD_H

void pointing_device_init_user(void) {
    pointing_device_set_cpi(800);
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    set_auto_mouse_enable(true);
#endif
}
