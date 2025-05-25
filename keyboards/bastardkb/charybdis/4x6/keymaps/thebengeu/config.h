#pragma once

#define ALT KC_RALT
#define CTL KC_RCTL
#define GUI KC_RGUI
#define SFT KC_RSFT
#define KB1 KC_BTN1
#define KB2 KC_BTN2
#define KC0 KC_0
#define KC1 KC_1
#define KC2 KC_2
#define KC3 KC_3
#define KC4 KC_4
#define KC5 KC_5
#define KC6 KC_6
#define KC7 KC_7
#define KC8 KC_8
#define KC9 KC_9
#define XXX KC_NO

// clang-format off
#define LAYOUT_split_3x5_3_custom( \
K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09, \
K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19, \
K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29, \
               K30, K31, K32,      K33, K34, K35                 \
) \
LAYOUT( \
K00, KC1, KC2, KC3, KC4, KC5,            KC6, KC7, KC8, KC9, KC0, K09, \
ALT, K00, K01, K02, K03, K04,            K05, K06, K07, K08, K09, GUI, \
K00, K10, K11, K12, K13, K14,            K15, K16, K17, K18, K19, K09, \
CTL, K20, K21, K22, K23, K24,            K25, K26, K27, K28, K29, SFT, \
                    K30, K31, K32,  K33, K34,                          \
                         KB1, KB2,  K35                                \
)
// clang-format on

#define RGBLIGHT_LED_COUNT 58
