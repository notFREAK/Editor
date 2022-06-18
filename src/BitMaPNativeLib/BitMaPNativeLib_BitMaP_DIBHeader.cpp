#define _CRT_SECURE_NO_WARNINGS
#include "BitMaPNativeLib_BitMaP_DIBHeader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

JNIEXPORT jint JNICALL Java_BitMaPNativeLib_BitMaP_00024DIBHeader_readFromFile(JNIEnv *env, jobject this_obj, jstring jfilename) {
    jclass class_BitMaPDIBHeader = env->GetObjectClass(this_obj);
    jfieldID id_sizeofdibheader= env->GetFieldID(class_BitMaPDIBHeader, "SizeOfDIBHeader", "I");
    jfieldID id_pixelWidth = env->GetFieldID(class_BitMaPDIBHeader, "pixelWidth", "I");
    jfieldID id_pixelHeight = env->GetFieldID(class_BitMaPDIBHeader, "pixelHeight", "I");
    jfieldID id_colourPlanes = env->GetFieldID(class_BitMaPDIBHeader, "colourPlanes", "S");
    jfieldID id_bitsPerPixel = env->GetFieldID(class_BitMaPDIBHeader, "bitsPerPixel", "S");
    jfieldID id_compressionType= env->GetFieldID(class_BitMaPDIBHeader, "compressionType", "I");
    jfieldID id_imageSize = env->GetFieldID(class_BitMaPDIBHeader, "imageSize", "I");
    jfieldID id_horizontalResolution= env->GetFieldID(class_BitMaPDIBHeader, "horizontalResolution", "I");
    jfieldID id_verticalResolution = env->GetFieldID(class_BitMaPDIBHeader, "verticalResolution", "I");
    jfieldID id_numberOfColours = env->GetFieldID(class_BitMaPDIBHeader, "numberOfColours", "I");
    jfieldID id_NumberOfImportantColours= env->GetFieldID(class_BitMaPDIBHeader, "NumberOfImportantColours", "I");
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
    fseek(file, 14, SEEK_SET);
    short temps;
    int temp;
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_sizeofdibheader, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_pixelWidth, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_pixelHeight, temp);
    fread(&temps, sizeof(short), 1, file);
    env->SetShortField(this_obj, id_colourPlanes, temps);
    fread(&temps, sizeof(short), 1, file);
    env->SetShortField(this_obj, id_bitsPerPixel, temps);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_compressionType, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_imageSize, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_horizontalResolution, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_verticalResolution, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_numberOfColours, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_NumberOfImportantColours, temp);
    env->ReleaseStringUTFChars(jfilename, cfilename);
    fclose(file);
    return 0;
}

JNIEXPORT jint JNICALL Java_BitMaPNativeLib_BitMaP_00024DIBHeader_saveInFile(JNIEnv *env, jobject this_obj, jstring jfilename) {
    jclass class_BitMaPDIBHeader = env->GetObjectClass(this_obj);
    jfieldID id_sizeofdibheader= env->GetFieldID(class_BitMaPDIBHeader, "SizeOfDIBHeader", "I");
    jfieldID id_pixelWidth = env->GetFieldID(class_BitMaPDIBHeader, "pixelWidth", "I");
    jfieldID id_pixelHeight = env->GetFieldID(class_BitMaPDIBHeader, "pixelHeight", "I");
    jfieldID id_colourPlanes = env->GetFieldID(class_BitMaPDIBHeader, "colourPlanes", "S");
    jfieldID id_bitsPerPixel = env->GetFieldID(class_BitMaPDIBHeader, "bitsPerPixel", "S");
    jfieldID id_compressionType= env->GetFieldID(class_BitMaPDIBHeader, "compressionType", "I");
    jfieldID id_imageSize = env->GetFieldID(class_BitMaPDIBHeader, "imageSize", "I");
    jfieldID id_horizontalResolution= env->GetFieldID(class_BitMaPDIBHeader, "horizontalResolution", "I");
    jfieldID id_verticalResolution = env->GetFieldID(class_BitMaPDIBHeader, "verticalResolution", "I");
    jfieldID id_numberOfColours = env->GetFieldID(class_BitMaPDIBHeader, "numberOfColours", "I");
    jfieldID id_NumberOfImportantColours= env->GetFieldID(class_BitMaPDIBHeader, "NumberOfImportantColours", "I");
    const char *cfilename = env->GetStringUTFChars(jfilename, NULL);
    if (cfilename == NULL)
        return env->ThrowNew(env->FindClass("java/lang/Exception"), "No filename in class");
    FILE* file = fopen(cfilename,"ab");
    if (file == NULL) {
            printf("%s\n", cfilename);
            printf("can't open %s: %s\n", cfilename, strerror(errno));
            fflush(stdout);
            return env->ThrowNew(env->FindClass("java/lang/Exception"), "No file in directory");
    }
    fseek(file, 14, SEEK_SET);
    int temp[1];
    temp[0] = (int)env->GetIntField(this_obj, id_sizeofdibheader);
    fwrite(temp, sizeof(int), 1, file);
    temp[0] = (int)env->GetIntField(this_obj, id_pixelWidth);
    fwrite(temp, sizeof(int), 1, file);
    temp[0] = (int)env->GetIntField(this_obj, id_pixelHeight);
    fwrite(temp, sizeof(int), 1, file);
    short temps;
    temps = (short)env->GetShortField(this_obj, id_colourPlanes);
    fwrite(&temps, sizeof(short), 1, file);
    temps = (short)env->GetShortField(this_obj, id_bitsPerPixel);
    fwrite(&temps, sizeof(short), 1, file);
    temp[0] = (int)env->GetIntField(this_obj, id_compressionType);
    fwrite(temp, sizeof(int), 1, file);
    temp[0] = (int)env->GetIntField(this_obj, id_imageSize);
    fwrite(temp, sizeof(int), 1, file);
    temp[0] = (int)env->GetIntField(this_obj, id_horizontalResolution);
    fwrite(temp, sizeof(int), 1, file);
    temp[0] = (int)env->GetIntField(this_obj, id_verticalResolution);
    fwrite(temp, sizeof(int), 1, file);
    temp[0] = (int)env->GetIntField(this_obj, id_numberOfColours);
    fwrite(temp, sizeof(int), 1, file);
    temp[0] = (int)env->GetIntField(this_obj, id_NumberOfImportantColours);
    fwrite(temp, sizeof(int), 1, file);
    env->ReleaseStringUTFChars(jfilename, cfilename);
    fclose(file);
    return 0;
}