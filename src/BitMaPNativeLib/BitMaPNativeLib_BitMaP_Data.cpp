#define _CRT_SECURE_NO_WARNINGS
#include "BitMaPNativeLib_BitMaP_Data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

JNIEXPORT jobjectArray JNICALL Java_BitMaPNativeLib_BitMaP_00024Data_readFromFile(JNIEnv * env, jobject this_obj, jstring jfilename, jint h, jint w) {
    jclass class_BitMaPData = env->GetObjectClass(this_obj);
    jclass Pixel = env->FindClass("[LBitMaPNativeLib/Pixel;");
    jclass pixel = env->FindClass("LBitMaPNativeLib/Pixel;");
    jmethodID scInfo_constructor = env->GetMethodID(pixel, "<init>", "()V");
    jmethodID setRed = env->GetMethodID(pixel, "setRed", "(B)V"); //LBitMaPNativeLib/Pixel;
    jmethodID setGreen = env->GetMethodID(pixel, "setGreen", "(B)V");
    jmethodID setBlue = env->GetMethodID(pixel, "setBlue", "(B)V");
    jmethodID getBlue = env->GetMethodID(pixel, "getBlue", "()B");
    const char *cfilename = env->GetStringUTFChars(jfilename, NULL);
    if (cfilename == NULL)
        env->ThrowNew(env->FindClass("java/lang/Exception"), "No filename in class");
    FILE* file = fopen(cfilename,"rb");
    if (file == NULL) {
            printf("%s\n", cfilename);
            printf("can't open %s: %s\n", cfilename, strerror(errno));
            fflush(stdout);
            env->ThrowNew(env->FindClass("java/lang/Exception"), "No file in directory");
    }
    fseek(file, 138 , SEEK_SET);
    jbyte temp[3];
    jobjectArray Arr = env->NewObjectArray(h, Pixel, env->NewObjectArray(w, pixel, env->NewObject(pixel, scInfo_constructor)));
    for (int i = 0; i < h;i++)  {
        jobjectArray PixelArr = env->NewObjectArray(w, pixel, env->NewObject(pixel, scInfo_constructor));//(jobject*) env->GetObjectArrayElement(Arr, (jsize)i);
        for (int j = 0; j < w;j++) {
            jobject tpixel = env->NewObject(pixel, scInfo_constructor);
            fread(temp, sizeof(char)*3, 1, file);
            env->CallVoidMethod(tpixel, setRed, temp[0]);
            env->CallVoidMethod(tpixel, setGreen, temp[1]);
            env->CallVoidMethod(tpixel, setBlue, temp[2]);
            env->SetObjectArrayElement(PixelArr, (jsize)j, tpixel);
        }
        env->SetObjectArrayElement(Arr, (jsize)i, PixelArr);
    }
    env->ReleaseStringUTFChars(jfilename, cfilename);
    fclose(file);
    return Arr;
}

JNIEXPORT void JNICALL Java_BitMaPNativeLib_BitMaP_00024Data_saveInFile(JNIEnv * env, jobject this_obj, jstring jfilename,jobjectArray Pixels, jint h, jint w) {
    jclass class_BitMaPData = env->GetObjectClass(this_obj);
    jclass Pixel = env->FindClass("[LBitMaPNativeLib/Pixel;");
    jclass pixel = env->FindClass("LBitMaPNativeLib/Pixel;");
    jmethodID scInfo_constructor = env->GetMethodID(pixel, "<init>", "()V");
    jmethodID setRed = env->GetMethodID(pixel, "setRed", "(B)V"); //LBitMaPNativeLib/Pixel;
    jmethodID setGreen = env->GetMethodID(pixel, "setGreen", "(B)V");
    jmethodID setBlue = env->GetMethodID(pixel, "setBlue", "(B)V");
    jmethodID getBlue = env->GetMethodID(pixel, "getBlue", "()B");
    jmethodID getGreen = env->GetMethodID(pixel, "getGreen", "()B");
    jmethodID getRed = env->GetMethodID(pixel, "getRed", "()B");
    const char *cfilename = env->GetStringUTFChars(jfilename, NULL);
    if (cfilename == NULL)
        env->ThrowNew(env->FindClass("java/lang/Exception"), "No filename in class");
    FILE* file = fopen(cfilename,"ab");
    if (file == NULL) {
            printf("%s\n", cfilename);
            printf("can't open %s: %s\n", cfilename, strerror(errno));
            fflush(stdout);
            env->ThrowNew(env->FindClass("java/lang/Exception"), "No file in directory");
    }
    fseek(file, 138 , SEEK_SET);
    jbyte temp[3];
    for (int i = 0; i < h;i++)  {
        jobjectArray PixelArr = (jobjectArray) env->GetObjectArrayElement(Pixels, (jsize)i);//(jobject*) env->GetObjectArrayElement(Arr, (jsize)i);
        for (int j = 0; j < w;j++) {
            jobject tpixel = env->GetObjectArrayElement(PixelArr, (jsize)j);
            temp[0] = env->CallByteMethod(tpixel, getRed);
            temp[1] = env->CallByteMethod(tpixel, getGreen);
            temp[2] = env->CallByteMethod(tpixel, getBlue);
            fwrite(temp, sizeof(char), 3, file);
        }
    }
    env->ReleaseStringUTFChars(jfilename, cfilename);
    fclose(file);
}