#pragma once

#define XXX KC_NO

// clang-format off
#define LAYOUT_split_3x5_3( \
K00, K01, K02, K03, K04,                         K05, K06, K07, K08, K09, \
K10, K11, K12, K13, K14,                         K15, K16, K17, K18, K19, \
K20, K21, K22, K23, K24,                         K25, K26, K27, K28, K29, \
               K30, K31, K32,               K33, K34, K35                 \
) \
LAYOUT( \
XXX, KC_1, KC_2, KC_3, KC_4, KC_5,          KC_6, KC_7, KC_8, KC_9, KC_0, XXX, \
XXX, K00,  K01,  K02,  K03,  K04,           K05,  K06,  K07,  K08,  K09,  XXX, \
K00, K10,  K11,  K12,  K13,  K14,           K15,  K16,  K17,  K18,  K19,  K09, \
XXX, K20,  K21,  K22,  K23,  K24, XXX, XXX, K25,  K26,  K27,  K28,  K29,  XXX, \
     XXX,  XXX,  K30,  K31,  K32,           K33,  K34,  K35,  XXX,  XXX        \
)
// clang-format on

#define AZOTEQ_IQS5XX_HOLD_TIME 500
#define AZOTEQ_IQS5XX_PRESS_AND_HOLD_ENABLE true
#define AZOTEQ_IQS5XX_ROTATION_180
#define AZOTEQ_IQS5XX_SCROLL_INITIAL_DISTANCE 10
#define AZOTEQ_IQS5XX_TPS43
#define I2C1_SCL_PIN GP3
#define I2C1_SDA_PIN GP2
#define I2C_DRIVER I2CD1
#define SPLIT_WATCHDOG_ENABLE
