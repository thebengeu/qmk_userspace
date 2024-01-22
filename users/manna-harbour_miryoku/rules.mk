# Copyright 2019 Manna Harbour
# https://github.com/manna-harbour/miryoku

AUTO_SHIFT_ENABLE = no
BOOTMAGIC_ENABLE = no
CAPS_WORD_ENABLE = yes
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
DYNAMIC_TAPPING_TERM_ENABLE = yes
EXTRAKEY_ENABLE = yes
GRAVE_ESC_ENABLE = no
INTROSPECTION_KEYMAP_C = manna-harbour_miryoku.c
KEY_OVERRIDE_ENABLE = yes
MAGIC_ENABLE = no
MIRYOKU_ALPHAS=QWERTY
MIRYOKU_CLIPBOARD=MAC
MIRYOKU_KLUDGE_THUMBCOMBOS=yes
MIRYOKU_LAYERS=FLIP
MIRYOKU_NAV=INVERTEDT
MIRYOKU_TAP=QWERTY
MOUSEKEY_ENABLE = yes
REPEAT_KEY_ENABLE = yes
SPACE_CADET_ENABLE = no
SRC += features/achordion.c
TAP_DANCE_ENABLE = yes
UNICODE_ENABLE = no

# alternative layout options

ifneq ($(strip $(MIRYOKU_ALPHAS)),)
  OPT_DEFS += -DMIRYOKU_ALPHAS_$(MIRYOKU_ALPHAS)
endif

ifneq ($(strip $(MIRYOKU_EXTRA)),)
  OPT_DEFS += -DMIRYOKU_EXTRA_$(MIRYOKU_EXTRA)
endif

ifneq ($(strip $(MIRYOKU_TAP)),)
  OPT_DEFS += -DMIRYOKU_TAP_$(MIRYOKU_TAP)
endif

ifneq ($(strip $(MIRYOKU_NAV)),)
  OPT_DEFS += -DMIRYOKU_NAV_$(MIRYOKU_NAV)
endif

ifneq ($(strip $(MIRYOKU_CLIPBOARD)),)
  OPT_DEFS += -DMIRYOKU_CLIPBOARD_$(MIRYOKU_CLIPBOARD)
endif

ifneq ($(strip $(MIRYOKU_LAYERS)),)
  OPT_DEFS += -DMIRYOKU_LAYERS_$(MIRYOKU_LAYERS)
endif

# subset mappings

ifneq ($(strip $(MIRYOKU_MAPPING)),)
  OPT_DEFS += -DMIRYOKU_MAPPING_$(MIRYOKU_MAPPING)
endif

# kludges

# thumb combos
ifeq ($(strip $(MIRYOKU_KLUDGE_THUMBCOMBOS)),yes)
  COMBO_ENABLE = yes
  OPT_DEFS += -DMIRYOKU_KLUDGE_THUMBCOMBOS
endif
