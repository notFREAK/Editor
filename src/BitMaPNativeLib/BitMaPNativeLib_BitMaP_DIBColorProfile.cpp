#define _CRT_SECURE_NO_WARNINGS
#include "BitMaPNativeLib_BitMaP_DIBColorProfile.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

JNIEXPORT jint JNICALL Java_BitMaPNativeLib_BitMaP_00024DIBColorProfile_readFromFile(JNIEnv *env, jobject this_obj, jstring jfilename) {
    jclass class_BitMaPDIBColorProfile = env->GetObjectClass(this_obj);
    jfieldID id_redmask= env->GetFieldID(class_BitMaPDIBColorProfile, "redmask", "I");
    jfieldID id_greenmask = env->GetFieldID(class_BitMaPDIBColorProfile, "greenmask", "I");
    jfieldID id_bluemask = env->GetFieldID(class_BitMaPDIBColorProfile, "bluemask", "I");
    jfieldID id_alphamask = env->GetFieldID(class_BitMaPDIBColorProfile, "alphamask", "I");
    jfieldID id_colourspace = env->GetFieldID(class_BitMaPDIBColorProfile, "colourspace", "I");
    jfieldID id_gammared= env->GetFieldID(class_BitMaPDIBColorProfile, "gammared", "I");
    jfieldID id_gammagreen = env->GetFieldID(class_BitMaPDIBColorProfile, "gammagreen", "I");
    jfieldID id_gammablue = env->GetFieldID(class_BitMaPDIBColorProfile, "gammablue", "I");
    jfieldID id_intent= env->GetFieldID(class_BitMaPDIBColorProfile, "intent", "I");
    jfieldID id_profileData = env->GetFieldID(class_BitMaPDIBColorProfile, "profileData", "I");
    jfieldID id_profileSize = env->GetFieldID(class_BitMaPDIBColorProfile, "profileSize", "I");
    jfieldID id_nothing= env->GetFieldID(class_BitMaPDIBColorProfile, "nothing", "I");
    jfieldID id_redendpointX= env->GetFieldID(class_BitMaPDIBColorProfile, "redendpointX", "I");
    jfieldID id_redendpointY= env->GetFieldID(class_BitMaPDIBColorProfile, "redendpointY", "I");
    jfieldID id_redendpointZ= env->GetFieldID(class_BitMaPDIBColorProfile, "redendpointZ", "I");
    jfieldID id_greenendpointX= env->GetFieldID(class_BitMaPDIBColorProfile, "greenendpointX", "I");
    jfieldID id_greenendpointY= env->GetFieldID(class_BitMaPDIBColorProfile, "greenendpointY", "I");
    jfieldID id_greenendpointZ= env->GetFieldID(class_BitMaPDIBColorProfile, "greenendpointZ", "I");
    jfieldID id_blueendpointX =env->GetFieldID(class_BitMaPDIBColorProfile, "blueendpointX", "I");
    jfieldID id_blueendpointY =env->GetFieldID(class_BitMaPDIBColorProfile, "blueendpointY", "I");
    jfieldID id_blueendpointZ =env->GetFieldID(class_BitMaPDIBColorProfile, "blueendpointZ", "I");
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
    fseek(file, 54, SEEK_SET);
    int temp;
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_redmask, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_greenmask, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_bluemask, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_alphamask, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_colourspace, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_redendpointX, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_redendpointY, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_redendpointZ, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_greenendpointX, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_greenendpointY, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_greenendpointZ, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_blueendpointX, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_blueendpointY, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_blueendpointZ, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_gammared, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_gammagreen, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_gammablue, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_intent, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_profileData, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_profileSize, temp);
    fread(&temp, sizeof(int), 1, file);
    env->SetIntField(this_obj, id_nothing, temp);
    env->ReleaseStringUTFChars(jfilename, cfilename);
    fclose(file);
    return 0;
}

JNIEXPORT jint JNICALL Java_BitMaPNativeLib_BitMaP_00024DIBColorProfile_saveInFile(JNIEnv *env, jobject this_obj, jstring jfilename) {
    jclass class_BitMaPDIBColorProfile = env->GetObjectClass(this_obj);
    jfieldID id_redmask= env->GetFieldID(class_BitMaPDIBColorProfile, "redmask", "I");
    jfieldID id_greenmask = env->GetFieldID(class_BitMaPDIBColorProfile, "greenmask", "I");
    jfieldID id_bluemask = env->GetFieldID(class_BitMaPDIBColorProfile, "bluemask", "I");
    jfieldID id_alphamask = env->GetFieldID(class_BitMaPDIBColorProfile, "alphamask", "I");
    jfieldID id_colourspace = env->GetFieldID(class_BitMaPDIBColorProfile, "colourspace", "I");
    jfieldID id_gammared= env->GetFieldID(class_BitMaPDIBColorProfile, "gammared", "I");
    jfieldID id_gammagreen = env->GetFieldID(class_BitMaPDIBColorProfile, "gammagreen", "I");
    jfieldID id_gammablue = env->GetFieldID(class_BitMaPDIBColorProfile, "gammablue", "I");
    jfieldID id_intent= env->GetFieldID(class_BitMaPDIBColorProfile, "intent", "I");
    jfieldID id_profileData = env->GetFieldID(class_BitMaPDIBColorProfile, "profileData", "I");
    jfieldID id_profileSize = env->GetFieldID(class_BitMaPDIBColorProfile, "profileSize", "I");
    jfieldID id_nothing= env->GetFieldID(class_BitMaPDIBColorProfile, "nothing", "I");
    jfieldID id_redendpointX= env->GetFieldID(class_BitMaPDIBColorProfile, "redendpointX", "I");
    jfieldID id_redendpointY= env->GetFieldID(class_BitMaPDIBColorProfile, "redendpointY", "I");
    jfieldID id_redendpointZ= env->GetFieldID(class_BitMaPDIBColorProfile, "redendpointZ", "I");
    jfieldID id_greenendpointX= env->GetFieldID(class_BitMaPDIBColorProfile, "greenendpointX", "I");
    jfieldID id_greenendpointY= env->GetFieldID(class_BitMaPDIBColorProfile, "greenendpointY", "I");
    jfieldID id_greenendpointZ= env->GetFieldID(class_BitMaPDIBColorProfile, "greenendpointZ", "I");
    jfieldID id_blueendpointX =env->GetFieldID(class_BitMaPDIBColorProfile, "blueendpointX", "I");
    jfieldID id_blueendpointY =env->GetFieldID(class_BitMaPDIBColorProfile, "blueendpointY", "I");
    jfieldID id_blueendpointZ =env->GetFieldID(class_BitMaPDIBColorProfile, "blueendpointZ", "I");
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
    fseek(file, 54, SEEK_SET);
    int temp;
    temp = (int)env->GetIntField(this_obj, id_redmask);
    fwrite(&temp, sizeof(int), 1, file);
    temp = (int)env->GetIntField(this_obj, id_greenmask);
    fwrite(&temp, sizeof(int), 1, file);
    temp = (int)env->GetIntField(this_obj, id_bluemask);
    fwrite(&temp, sizeof(int), 1, file);
    temp = (int)env->GetIntField(this_obj, id_alphamask);
        fwrite(&temp, sizeof(int), 1, file);
        temp = (int)env->GetIntField(this_obj, id_colourspace);
        fwrite(&temp, sizeof(int), 1, file);
        temp = (int)env->GetIntField(this_obj, id_redendpointX);
        fwrite(&temp, sizeof(int), 1, file);
        temp = (int)env->GetIntField(this_obj, id_redendpointY);
            fwrite(&temp, sizeof(int), 1, file);
            temp = (int)env->GetIntField(this_obj, id_redendpointZ);
            fwrite(&temp, sizeof(int), 1, file);
            temp = (int)env->GetIntField(this_obj, id_greenendpointX);
            fwrite(&temp, sizeof(int), 1, file);
    temp = (int)env->GetIntField(this_obj, id_greenendpointY);
        fwrite(&temp, sizeof(int), 1, file);
        temp = (int)env->GetIntField(this_obj, id_greenendpointZ);
        fwrite(&temp, sizeof(int), 1, file);
        temp = (int)env->GetIntField(this_obj, id_blueendpointX);
        fwrite(&temp, sizeof(int), 1, file);
    temp = (int)env->GetIntField(this_obj, id_blueendpointY);
        fwrite(&temp, sizeof(int), 1, file);
        temp = (int)env->GetIntField(this_obj, id_blueendpointZ);
        fwrite(&temp, sizeof(int), 1, file);
        temp = (int)env->GetIntField(this_obj, id_gammared);
        fwrite(&temp, sizeof(int), 1, file);
    temp = (int)env->GetIntField(this_obj, id_gammagreen);
        fwrite(&temp, sizeof(int), 1, file);
        temp = (int)env->GetIntField(this_obj, id_gammablue);
        fwrite(&temp, sizeof(int), 1, file);
        temp = (int)env->GetIntField(this_obj, id_intent);
        fwrite(&temp, sizeof(int), 1, file);
    temp = (int)env->GetIntField(this_obj, id_profileData);
            fwrite(&temp, sizeof(int), 1, file);
            temp = (int)env->GetIntField(this_obj, id_profileSize);
            fwrite(&temp, sizeof(int), 1, file);
            temp = (int)env->GetIntField(this_obj, id_nothing);
            fwrite(&temp, sizeof(int), 1, file);
    env->ReleaseStringUTFChars(jfilename, cfilename);
    fclose(file);
    return 0;
}