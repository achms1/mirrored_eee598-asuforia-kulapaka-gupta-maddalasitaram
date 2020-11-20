#include <jni.h>
#include <string>

#include <opencv2/core/core.hpp>

extern "C" JNIEXPORT jstring JNICALL
Java_com_eee598_asuforia_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
