#include QMK_KEYBOARD_H
#include "thebengeu.h"

// clang-format off
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
LAYOUT( \
'L', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', 'R', \
'L', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', 'R', \
'L', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', 'R', \
          '*', '*', '*', '*', '*',  '*', '*',                '*'       \
);
// clang-format on

static uint8_t previous_cpi = 0;

layer_state_t layer_state_set_user(layer_state_t state) {
    int highest_layer = get_highest_layer(state);

    keyball_set_scrollsnap_mode(highest_layer == _LCSG ? KEYBALL_SCROLLSNAP_MODE_FREE : highest_layer == _MEH ? KEYBALL_SCROLLSNAP_MODE_HORIZONTAL : KEYBALL_SCROLLSNAP_MODE_VERTICAL);

    keyball_set_scroll_mode(highest_layer == _LCSG || highest_layer == _MEH || highest_layer == _NM || highest_layer == _NW);

    if (highest_layer == _FUN) {
        previous_cpi = keyball_get_cpi();
        keyball_set_cpi(2);
    } else if (highest_layer == _SYM) {
        previous_cpi = keyball_get_cpi();
        keyball_set_cpi(120);
    } else if (previous_cpi) {
        keyball_set_cpi(previous_cpi);
        previous_cpi = 0;
    }

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
