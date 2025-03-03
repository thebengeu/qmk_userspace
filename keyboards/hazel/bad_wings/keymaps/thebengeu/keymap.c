#include QMK_KEYBOARD_H
#include "thebengeu.h"

// clang-format off
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
LAYOUT_split_3x5_3( \
'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', \
'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', \
'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', '*', \
               '*', '*', '*',  '*', '*', '*'                 \
);
// clang-format on

typedef enum {
    SCROLLSNAP_MODE_OFF        = 0,
    SCROLLSNAP_MODE_VERTICAL   = 1,
    SCROLLSNAP_MODE_HORIZONTAL = 2,
    SCROLLSNAP_MODE_FREE       = 3,
} scrollsnap_mode_t;

static scrollsnap_mode_t scrollsnap_mode = SCROLLSNAP_MODE_OFF;

layer_state_t layer_state_set_user(layer_state_t state) {
    int highest_layer = get_highest_layer(state);

    switch (highest_layer) {
        case _LCSG:
            scrollsnap_mode = SCROLLSNAP_MODE_FREE;
            break;
        case _MEH:
            scrollsnap_mode = SCROLLSNAP_MODE_HORIZONTAL;
            break;
        case _NM:
        case _NW:
            scrollsnap_mode = SCROLLSNAP_MODE_VERTICAL;
            break;
        default:
            scrollsnap_mode = SCROLLSNAP_MODE_OFF;
            break;
    }

    switch (highest_layer) {
        case _LCSG:
        case _MEH:
        case _NM:
        case _NW:
            pointing_device_set_cpi(25);
            break;
        case _FUN:
            pointing_device_set_cpi(500);
            break;
        case _SYM:
            pointing_device_set_cpi(4000);
            break;
        default:
            pointing_device_set_cpi(2000);
            break;
    }

    return state;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (scrollsnap_mode != SCROLLSNAP_MODE_OFF) {
        switch (scrollsnap_mode) {
            case SCROLLSNAP_MODE_VERTICAL:
                mouse_report.v = -mouse_report.y;
                break;
            case SCROLLSNAP_MODE_HORIZONTAL:
                mouse_report.h = mouse_report.x;
                break;
            case SCROLLSNAP_MODE_FREE:
                mouse_report.h = mouse_report.x;
                mouse_report.v = mouse_report.y;
                break;
            default:
                break;
        }

        mouse_report.x = 0;
        mouse_report.y = 0;
    }

    return mouse_report;
}
