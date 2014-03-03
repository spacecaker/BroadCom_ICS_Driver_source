This package contains the Broadcom Android ICS Graphics stack for arm v5


==================================================================
Package contents:

a new folder that contains the Graphics stack source codes:
-----------------------------------------------------------------

brcm_usrlib/dag


Required file changes in existing AOSP repos to build this Graphics stack
-----------------------------------------------------------------
AOSP repo name: repo_aosp/platform/bionic

libc/private/bionic_tls.h


AOSP repo name: repo_aosp/platform/build

core/legacy_prebuilts.mk
target/board/generic/device.mk


AOSP repo name: repo_aosp/platform/external/webrtc

src/common_audio/resampler/main/source/Android.mk
src/common_audio/signal_processing_library/main/source/Android.mk
src/common_audio/vad/main/source/Android.mk
src/modules/audio_processing/aec/main/source/Android.mk
src/modules/audio_processing/aecm/main/source/Android.mk
src/modules/audio_processing/agc/main/source/Android.mk
src/modules/audio_processing/main/source/Android.mk
src/modules/audio_processing/main/test/process_test/Android.mk
src/modules/audio_processing/main/test/process_test/process_test.cc
src/modules/audio_processing/main/test/unit_test/Android.mk
src/modules/audio_processing/ns/main/source/Android.mk
src/modules/audio_processing/utility/Android.mk
src/system_wrappers/source/Android.mk


AOSP repo name: repo_aosp/platform/frameworks/base

opengl/include/EGL/eglext.h
opengl/libagl/egl.cpp
opengl/libs/EGL/egl.cpp
opengl/libs/EGL/eglApi.cpp
opengl/libs/EGL/egl_entries.in
opengl/libs/EGL/getProcAddress.cpp
opengl/libs/GLES2/gl2.cpp
opengl/libs/GLES_CM/gl.cpp
services/input/InputReader.cpp
services/surfaceflinger/Android.mk
services/surfaceflinger/DisplayHardware/DisplayHardware.cpp


AOSP repo name: repo_aosp/platform/hardware/libhardware

Gralloc changes:

include/hardware/fb.h
modules/gralloc/Android.mk
modules/gralloc/framebuffer.cpp
modules/gralloc/gr.h
modules/gralloc/gralloc.cpp
modules/gralloc/gralloc_priv.h
modules/gralloc/mapper.cpp

Hwcomposer changes:

modules/gralloc/Android.mk
modules/hwcomposer/Android.mk
modules/hwcomposer/hwcomposer.cpp


AOSP repo name: repo_aosp/platform/system/core

include/system/graphics.h

 
==================================================================
These sources where modifed by SpaceCaker@XDA-Developers.com
Special thanks to Team BroadcomCM






