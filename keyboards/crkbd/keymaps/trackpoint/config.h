#pragma once

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
