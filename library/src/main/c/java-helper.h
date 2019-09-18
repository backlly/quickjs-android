#ifndef QUICKJS_ANDROID_JAVA_HELPER_H
#define QUICKJS_ANDROID_JAVA_HELPER_H

#include <jni.h>

#define CLASS_NAME_ILLEGAL_ARGUMENT_EXCEPTION "java/lang/IllegalArgumentException"
#define CLASS_NAME_ILLEGAL_STATE_EXCEPTION    "java/lang/IllegalStateException"
#define CLASS_NAME_OUT_OF_MEMORY_ERROR        "java/lang/OutOfMemoryError"
#define CLASS_NAME_JS_DATA_EXCEPTION          "com/hippo/quickjs/android/JSDataException"

#define THROW_EXCEPTION(ENV, EXCEPTION_NAME, ...)                               \
    do {                                                                        \
        throw_exception((ENV), (EXCEPTION_NAME), __VA_ARGS__);                  \
        return;                                                                 \
    } while (0)

#define THROW_EXCEPTION_RET(ENV, EXCEPTION_NAME, ...)                           \
    do {                                                                        \
        throw_exception((ENV), (EXCEPTION_NAME), __VA_ARGS__);                  \
        return 0;                                                               \
    } while (0)

#define THROW_ILLEGAL_ARGUMENT_EXCEPTION(ENV, ...)                              \
    THROW_EXCEPTION(ENV, CLASS_NAME_ILLEGAL_ARGUMENT_EXCEPTION, __VA_ARGS__)

#define THROW_ILLEGAL_ARGUMENT_EXCEPTION_RET(ENV, ...)                          \
    THROW_EXCEPTION_RET(ENV, CLASS_NAME_ILLEGAL_ARGUMENT_EXCEPTION, __VA_ARGS__)

#define THROW_ILLEGAL_STATE_EXCEPTION(ENV, ...)                                 \
    THROW_EXCEPTION(ENV, CLASS_NAME_ILLEGAL_STATE_EXCEPTION, __VA_ARGS__)

#define THROW_ILLEGAL_STATE_EXCEPTION_RET(ENV, ...)                             \
    THROW_EXCEPTION_RET(ENV, CLASS_NAME_ILLEGAL_STATE_EXCEPTION, __VA_ARGS__)

#define THROW_OUT_OF_MEMORY_ERROR(ENV, ...)                                     \
    THROW_EXCEPTION(ENV, CLASS_NAME_OUT_OF_MEMORY_ERROR, __VA_ARGS__)

#define THROW_OUT_OF_MEMORY_ERROR_RET(ENV, ...)                                 \
    THROW_EXCEPTION_RET(ENV, CLASS_NAME_OUT_OF_MEMORY_ERROR, __VA_ARGS__)

#define THROW_JS_DATA_EXCEPTION(ENV, ...)                                       \
    THROW_EXCEPTION(ENV, CLASS_NAME_JS_DATA_EXCEPTION, __VA_ARGS__)

#define THROW_JS_DATA_EXCEPTION_RET(ENV, ...)                                   \
    THROW_EXCEPTION_RET(ENV, CLASS_NAME_JS_DATA_EXCEPTION, __VA_ARGS__)

#define CHECK_NULL(ENV, POINTER, MESSAGE)                                       \
    if ((POINTER) == NULL) {                                                    \
        THROW_ILLEGAL_STATE_EXCEPTION((ENV), (MESSAGE));                        \
    }

#define CHECK_NULL_RET(ENV, POINTER, MESSAGE)                                   \
    if ((POINTER) == NULL) {                                                    \
        THROW_ILLEGAL_STATE_EXCEPTION_RET((ENV), (MESSAGE));                    \
    }

jint throw_exception(JNIEnv *env, const char *exception_name, const char *message, ...);

#define OBTAIN_ENV(VM)                                                                              \
    JNIEnv *env = NULL;                                                                             \
    int __require_detach__ = 0;                                                                     \
    (*(VM))->GetEnv((VM), (void **) &env, JNI_VERSION_1_6);                                         \
    if (env == NULL) __require_detach__ = (*(VM))->AttachCurrentThread((VM), &env, NULL) == JNI_OK;

#define RELEASE_ENV(VM)                                           \
    if (__require_detach__) (*(VM))->DetachCurrentThread((VM));

#endif //QUICKJS_ANDROID_JAVA_HELPER_H
