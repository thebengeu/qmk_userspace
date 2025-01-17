#include QMK_KEYBOARD_H
#include "thebengeu.h"

layer_state_t layer_state_set_user(layer_state_t state) {
    int highest_layer = get_highest_layer(state);
    keyball_set_scroll_mode(highest_layer == _NM || highest_layer == _NW);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
