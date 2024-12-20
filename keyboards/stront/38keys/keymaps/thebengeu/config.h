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
          K01, K02, K03, K04,      K05, K06, K07, K08,           \
K00, K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, K09, \
K20, K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, K29, \
               K30, K31, K32,      K33, K34, K35                 \
)
// clang-format on

#define CIRQUE_PINNACLE_TAP_ENABLE
#define MOUSE_EXTENDED_REPORT
#define POINTING_DEVICE_GESTURES_CURSOR_GLIDE_ENABLE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE
#undef RGB_DISABLE_WHEN_USB_SUSPENDED
