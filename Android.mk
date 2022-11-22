LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := apexdumper

LOCAL_CPPFLAGS += -pie -fPIE -ffunction-sections -fdata-sections -fvisibility=hidden
LOCAL_LDFLAGS += -pie -fPIE -Wl,--gc-sections
LOCAL_CFLAGS := -Wno-error=format-security -fpermissive
LOCAL_CFLAGS += -ffunction-sections -fdata-sections -fvisibility=hidden
LOCAL_CFLAGS += -fno-rtti -fno-exceptions

LOCAL_C_INCLUDES += $(LOCAL_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/app/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/cli/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/logger/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/sdk/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/syscall/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/parser/include

LOCAL_SRC_FILES := 	entry_point.cpp \
					app/application.cpp \
					cli/cli.cpp \
					logger/logger.cpp \
					parser/parser.cpp \
					syscall/syscall.cpp \
					sdk/sdk.cpp



LOCAL_LDLIBS += -llog -lz

include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)





