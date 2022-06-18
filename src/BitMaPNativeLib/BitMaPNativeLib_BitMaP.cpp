#include "BitMaPNativeLib_BitMaP.h"
#include <stdio.h>
#include <stdlib.h>

JNIEXPORT void JNICALL Java_BitMaPNativeLib_BitMaP_setContrast(JNIEnv * env, jobject this_obj, jdouble contrast) {
    printf("go on");
}

JNIEXPORT void JNICALL Java_BitMaPNativeLib_BitMaP_setBrightness(JNIEnv *, jobject, jdouble) {
    printf("go on br");
}