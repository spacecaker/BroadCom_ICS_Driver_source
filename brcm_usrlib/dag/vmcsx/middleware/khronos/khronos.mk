LIB_NAME := khronos

LIB_LIBS := \
   middleware/khronos/khronos_dispatch \
   middleware/khronos/khronos_main

LIB_VPATH += ext
LIB_SRC += egl_brcm_global_image_id.c

LIB_CFLAGS := $(WARNINGS_ARE_ERRORS)
LIB_AFLAGS := $(ASM_WARNINGS_ARE_ERRORS)
