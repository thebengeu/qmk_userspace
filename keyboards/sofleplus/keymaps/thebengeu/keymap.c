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
