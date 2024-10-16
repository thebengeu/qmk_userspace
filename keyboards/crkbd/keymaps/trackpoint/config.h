#pragma once

#define XXX KC_NO

// clang-format off
#define LAYOUT_split_3x5_3_custom( \
K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09, \
K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19, \
K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29, \
               K30, K31, K32,      K33, K34, K35                 \
) \
LAYOUT( \
XXX, K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, XXX, \
K00, K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, K09, \
XXX, K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, XXX, \
               K30, K31, K32,      K33, K34, K35                 \
)

#define EE_HANDS
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define PS2_CLOCK_PIN D3
#define PS2_DATA_PIN B4
#define PS2_INT_INIT() do { EICRA |= ((1<<ISC31) | (0<<ISC30)); } while (0)
#define PS2_INT_OFF() do { EIMSK &= ~(1<<INT3); } while (0)
#define PS2_INT_ON() do { EIMSK |= (1<<INT3); } while (0)
#define PS2_INT_VECT INT3_vect
#define PS2_MOUSE_INVERT_X
#define PS2_MOUSE_INVERT_Y
#define PS2_MOUSE_SCROLL_BTN_MASK 0
#define PS2_MOUSE_USE_REMOTE_MODE
// clang-format on
