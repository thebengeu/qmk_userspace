#pragma once

#define KB1 KC_BTN1
#define KB2 KC_BTN2
#define XXX KC_NO

// clang-format off
#define LAYOUT_split_3x5_3_custom( \
K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09, \
K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19, \
K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29, \
               K30, K31, K32,      K33, K34, K35                 \
) \
LAYOUT( \
KB2, K00, K01, K02, K03, K04,            K05, K06, K07, K08, K09, KB2, \
K00, K10, K11, K12, K13, K14,            K15, K16, K17, K18, K19, K09, \
KB1, K20, K21, K22, K23, K24,            K25, K26, K27, K28, K29, KB1, \
          KB2, KB1, K30, K31, K32,  K33, K34,                K35       \
)

#define AUTO_MOUSE_DEFAULT_LAYER 1
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_EFFECT_ALTERNATING
#    define RGBLIGHT_EFFECT_BREATHING
#    define RGBLIGHT_EFFECT_CHRISTMAS
#    define RGBLIGHT_EFFECT_KNIGHT
#    define RGBLIGHT_EFFECT_RAINBOW_MOOD
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_EFFECT_RGB_TEST
#    define RGBLIGHT_EFFECT_SNAKE
#    define RGBLIGHT_EFFECT_STATIC_GRADIENT
#    define RGBLIGHT_EFFECT_TWINKLE
#endif

#undef LAYER_STATE_8BIT
