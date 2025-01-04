#pragma once

// clang-format off
enum custom_keycodes {
  ALT_TAB = SAFE_RANGE,
  CTL_4,
  CTL_5,
  CTL_6,
  GUI_4,
  GUI_5,
  GUI_6,
  GUI_TAB,
  LLOCK,
  NW_COLN,
  NW_DLR,
  NW_TOGG,
  RCBR,
  SHIFT_ALT_TAB,
  SHIFT_GUI_TAB,
  UNDS
};
// clang-format on

#define LCSG(kc) (QK_LCTL | QK_LSFT | QK_LGUI | (kc))
#define LSAG(kc) (QK_LSFT | QK_LALT | QK_LGUI | (kc))
