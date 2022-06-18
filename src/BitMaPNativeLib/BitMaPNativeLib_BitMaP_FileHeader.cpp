#define _CRT_SECURE_NO_WARNINGS
#include "BitMaPNativeLib_BitMaP_FileHeader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

JNIEXPORT jint JNICALL Java_BitMaPNativeLib_BitMaP_00024FileHeader_readFromFile(JNIEnv *env, jobject this_obj, jstring jfilename) {
    jclass class_BitMaPFileHeader = env->GetObjectClass(this_obj);
    jfieldID id_format1 = env->GetFieldID(class_BitMaPFileHeader, "format1", "C");
    jfieldID id_format2 = env->GetFieldID(class_BitMaPFileHeader, "format2", "C");
    jfieldID id_sizeoffile = env->GetFieldID(class_BitMaPFileHeader, "SizeOfFile", "I");
    jfieldID id_reserved = env->GetFieldID(class_BitMaPFileHeader, "reserved", "I");
    jfieldID id_locationOfData = env->GetFieldID(class_BitMaPFileHeader, "locationOfData", "I");
    const char *cfilename = env->GetStringUTFChars(jfilename, NULL);
    if (cfilename == NULL)
        return env->ThrowNew(env->FindClass("java/lang/Exception"), "No filename in class");
    FILE* file = fopen(cfilename,"rb");
    if (file == NULL) {
            printf("%s\n", cfilename);
            printf("can't open %s: %s\n", cfilename, strerror(errno));
            fflush(stdout);
            return env->ThrowNew(env->FindClass("java/lang/Exception"), "No file in directory");
    }
    char bmpHeader[2];
    fread(bmpHeader, sizeof(char)*2, 1, file);
    if (bmpHeader[0] != 'B' || bmpHeader[1] != 'M')
        return env->ThrowNew(env->FindClass("java/lang/Exception"), "File is not BMP");
    env->SetCharField(this_obj, id_format1, bmpHeader[0]);
    env->SetCharField(this_obj, id_format2, bmpHeader[1]);
    int temp;
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_sizeoffile, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_reserved, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_locationOfData, temp);
    env->ReleaseStringUTFChars(jfilename, cfilename);
    fclose(file);
    return 0;
}

JNIEXPORT jint JNICALL Java_BitMaPNativeLib_BitMaP_00024FileHeader_saveInFile(JNIEnv *env, jobject this_obj, jstring jfilename) {
    jclass class_BitMaPFileHeader = env->GetObjectClass(this_obj);
    jfieldID id_format1 = env->GetFieldID(class_BitMaPFileHeader, "format1", "C");
    jfieldID id_format2 = env->GetFieldID(class_BitMaPFileHeader, "format2", "C");
    jfieldID id_sizeoffile = env->GetFieldID(class_BitMaPFileHeader, "SizeOfFile", "I");
    jfieldID id_reserved = env->GetFieldID(class_BitMaPFileHeader, "reserved", "I");
    jfieldID id_locationOfData = env->GetFieldID(class_BitMaPFileHeader, "locationOfData", "I");
    const char *cfilename = env->GetStringUTFChars(jfilename, NULL);
    if (cfilename == NULL)
        return env->ThrowNew(env->FindClass("java/lang/Exception"), "No filename in class");
    FILE* file = fopen(cfilename,"wb");
    if (file == NULL) {
            printf("%s\n", cfilename);
            printf("can't open %s: %s\n", cfilename, strerror(errno));
            fflush(stdout);
            return env->ThrowNew(env->FindClass("java/lang/Exception"), "No file in directory");
    }
    fseek(file, 0, SEEK_SET);
    char bmpc[1];
    bmpc[0]=(char) env->GetCharField(this_obj, id_format1);
    fwrite(bmpc, sizeof(char), 1, file);
    bmpc[0]=(char) env->GetCharField(this_obj, id_format2);
    fwrite(bmpc, sizeof(char), 1, file);
    int temp[1];
    temp[0] = (int)env->GetIntField(this_obj, id_sizeoffile);
    fwrite(temp, sizeof(int), 1, file);
    temp[0] = (int)env->GetIntField(this_obj, id_reserved);
    fwrite(temp, sizeof(int), 1, file);
    temp[0] = (int)env->GetIntField(this_obj, id_locationOfData);
    fwrite(temp, sizeof(int), 1, file);
    env->ReleaseStringUTFChars(jfilename, cfilename);
    fclose(file);
    return 0;
}