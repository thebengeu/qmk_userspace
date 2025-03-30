#include QMK_KEYBOARD_H
#include "thebengeu.h"

// clang-format off
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
LAYOUT( \
'L', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', 'R', \
'L', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', 'R', \
'L', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', 'R', \
'L', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', '*', 'R', \
                    '*', '*', '*',  '*', '*',                          \
                         '*', '*',  '*'                                \
);
// clang-format on
