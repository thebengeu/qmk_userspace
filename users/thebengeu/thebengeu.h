#pragma once

// clang-format off
enum custom_keycodes {
  GUI_4 = SAFE_RANGE,
  GUI_5,
  GUI_6,
  GUI_TAB,
  LLOCK,
  NW_COLN,
  NW_DLR,
  NW_TOGG,
  RCBR,
  SHIFT_GUI_TAB,
  UNDS
};
// clang-format on

#define LCSG(kc) (QK_LCTL | QK_LSFT | QK_LGUI | (kc))
#define LSAG(kc) (QK_LSFT | QK_LALT | QK_LGUI | (kc))

#define U_RDO SCMD(KC_Z)
#define U_PST LCMD(KC_V)
#define U_CPY LCMD(KC_C)
#define U_CUT LCMD(KC_X)
#define U_UND LCMD(KC_Z)
