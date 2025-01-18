#pragma once

enum custom_keycodes {
    ALT_TAB = SAFE_RANGE,
    CTL_4,
    CTL_5,
    CTL_6,
    GUI_4,
    GUI_5,
    GUI_6,
    GUI_TAB,
    NW_TOGG,
    SHIFT_ALT_TAB,
    SHIFT_GUI_TAB,
    SSNP_TOGG,
};

enum layers {
    _MAC,
    _WIN,
    _S,
    _MM,
    _MW,
    _NM,
    _NW,
    _SYM,
    _FUN,
    _MEH,
    _HYPR,
    _LCSG,
    _MNO,
    _HNO,
};

#define LCSG(kc) (QK_LCTL | QK_LSFT | QK_LGUI | (kc))
#define LSAG(kc) (QK_LSFT | QK_LALT | QK_LGUI | (kc))
