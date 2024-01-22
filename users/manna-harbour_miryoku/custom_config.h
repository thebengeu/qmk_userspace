// Copyright 2019 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#define MIRYOKU_LAYER_LIST \
MIRYOKU_X(BASE,   "Base") \
MIRYOKU_X(BUTTON, "Button") \
MIRYOKU_X(NAV,    "Nav") \
MIRYOKU_X(MOUSE,  "Mouse") \
MIRYOKU_X(MEDIA,  "Media") \
MIRYOKU_X(NUM,    "Num") \
MIRYOKU_X(SYM,    "Sym") \
MIRYOKU_X(FUN,    "Fun")

#define MIRYOKU_LAYER_BASE \
KC_Q,              KC_W,              KC_E,              KC_R,              KC_T,              KC_Y,              KC_U,              KC_I,              KC_O,              KC_P,              \
LGUI_T(KC_A),      LALT_T(KC_S),      LCTL_T(KC_D),      LSFT_T(KC_F),      RCTL_T(KC_G),      KC_H,              LSFT_T(KC_J),      LCTL_T(KC_K),      LALT_T(KC_L),      LGUI_T(KC_QUOT),   \
LT(U_BUTTON,KC_Z), KC_X,              KC_C,              KC_V,              KC_B,              KC_N,              KC_M,              KC_COMM,           KC_DOT,            LT(U_BUTTON,KC_SLSH),\
U_NP,              U_NP,              QK_REP,            LT(U_NUM,KC_BSPC), LT(U_SYM,KC_ENT),  LT(U_MOUSE,KC_TAB),LT(U_NAV,KC_SPC),  MEH_T(KC_ESC),     U_NP,              U_NP

#define MIRYOKU_LAYER_BUTTON \
KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           \
OSM(MOD_LGUI),     OSM(MOD_LALT),     OSM(MOD_LCTL),     OSM(MOD_LSFT),     KC_RCTL,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           \
KC_TRNS,           U_CUT,             U_CPY,             U_PST,             KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           \
KC_TRNS,           KC_TRNS,           KC_BTN3,           KC_BTN1,           KC_BTN2,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS,           KC_TRNS

#define MIRYOKU_LAYER_NAV \
KC_PGUP,           KC_HOME,           KC_UP,             KC_END,            KC_INS,            U_NA,              U_NA,              U_NA,              U_NA,              QK_BOOT,           \
KC_PGDN,           KC_LEFT,           KC_DOWN,           KC_RGHT,           CW_TOGG,           KC_CAPS,           OSM(MOD_LSFT),     OSM(MOD_LCTL),     OSM(MOD_LALT),     OSM(MOD_LGUI),     \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             KC_BSLS,           U_NA,              U_NA,              U_NA,              U_NA,              \
U_NP,              U_NP,              QK_AREP,           KC_BSPC,           KC_ENT,            U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_LAYER_MOUSE \
KC_WH_U,           KC_WH_L,           KC_MS_U,           KC_WH_R,           U_NU,              U_NA,              U_NA,              U_NA,              U_NA,              QK_BOOT,           \
KC_WH_D,           KC_MS_L,           KC_MS_D,           KC_MS_R,           KC_RCTL,           U_NA,              OSM(MOD_LSFT),     OSM(MOD_LCTL),     OSM(MOD_LALT),     OSM(MOD_LGUI),     \
U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              \
U_NP,              U_NP,              KC_BTN3,           KC_BTN1,           KC_BTN2,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_LAYER_MEDIA \
U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              \
KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,           U_NU,              U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
U_NU,              U_NU,              U_NU,              U_NU,              OU_AUTO,           U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              \
U_NP,              U_NP,              KC_MUTE,           KC_MPLY,           KC_MSTP,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP

#define MIRYOKU_LAYER_NUM \
QK_BOOT,           U_NA,              U_NA,              U_NA,              U_NA,              KC_LBRC,           KC_1,              KC_2,              KC_3,              KC_RBRC,           \
OSM(MOD_LGUI),     OSM(MOD_LALT),     OSM(MOD_LCTL),     OSM(MOD_LSFT),     KC_RCTL,           KC_EQL,            KC_4,              KC_5,              KC_6,              KC_SCLN,           \
U_NA,              U_NA,              U_NA,              U_NA,              KC_PIPE,           KC_BSLS,           KC_7,              KC_8,              KC_9,              KC_GRV,            \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_MINS,           KC_0,              MEH_T(KC_DOT),     U_NP,              U_NP

#define MIRYOKU_LAYER_SYM \
QK_BOOT,           U_NA,              U_NA,              U_NA,              U_NA,              KC_LCBR,           KC_EXLM,           KC_AT,             KC_HASH,           KC_RCBR,           \
OSM(MOD_LGUI),     OSM(MOD_LALT),     OSM(MOD_LCTL),     OSM(MOD_LSFT),     U_NA,              KC_PLUS,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_COLN,           \
U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              KC_PIPE,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_TILD,           \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_UNDS,           KC_LPRN,           KC_RPRN,           U_NP,              U_NP

#define MIRYOKU_LAYER_FUN \
QK_BOOT,           U_NA,              U_NA,              U_NA,              DT_UP,             KC_PSCR,           KC_F1,             KC_F2,             KC_F3,             KC_F10,            \
OSM(MOD_LGUI),     OSM(MOD_LALT),     OSM(MOD_LCTL),     OSM(MOD_LSFT),     DT_PRNT,           KC_SCRL,           KC_F4,             KC_F5,             KC_F6,             KC_F11,            \
U_NA,              U_NA,              U_NA,              U_NA,              DT_DOWN,           KC_PAUS,           KC_F7,             KC_F8,             KC_F9,             KC_F12,            \
U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_TAB,            KC_SPC,            KC_APP,            U_NP,              U_NP
