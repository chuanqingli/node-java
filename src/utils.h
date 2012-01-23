
#ifndef _utils_h_
#define _utils_h_

#define BUILDING_NODE_EXTENSION 1
#include <v8.h>
#include <jni.h>
#include <list>
#include <string>

class Java;

typedef enum _jvalueType {
  TYPE_VOID          = 0x001,
  TYPE_INT           = 0x002,
  TYPE_ARRAY_INT     = 0x102,
  TYPE_LONG          = 0x003,
  TYPE_ARRAY_LONG    = 0x103,
  TYPE_OBJECT        = 0x004,
  TYPE_ARRAY_OBJECT  = 0x104,
  TYPE_STRING        = 0x005,
  TYPE_ARRAY_STRING  = 0x105,
  TYPE_BOOLEAN       = 0x006,
  TYPE_ARRAY_BOOLEAN = 0x106,
  TYPE_BYTE          = 0x007,
  TYPE_ARRAY_BYTE    = 0x107
} jvalueType;

#define VALUE_TYPE_ARRAY 0x100

std::list<jobject> javaReflectionGetMethods(JNIEnv *env, jclass clazz);
std::list<jobject> javaReflectionGetConstructors(JNIEnv *env, jclass clazz);
std::list<jobject> javaReflectionGetStaticMethods(JNIEnv *env, jclass clazz);
std::string javaToString(JNIEnv *env, jstring str);
std::string javaObjectToString(JNIEnv *env, jobject obj);
jobject javaFindBestMatchingMethod(
  JNIEnv *env,
  std::list<jobject>& methods,
  const char *methodName,
  std::list<jvalueType>& argTypes);
jobject javaFindBestMatchingConstructor(
  JNIEnv *env,
  std::list<jobject>& constructors,
  std::list<jvalueType>& argTypes);
JNIEnv* javaAttachCurrentThread(JavaVM* jvm);
void javaDetachCurrentThread(JavaVM* jvm);
jvalueType javaGetType(JNIEnv *env, jclass type);
jclass javaFindClass(JNIEnv* env, std::string className);
jobject javaFindField(JNIEnv* env, jclass clazz, std::string fieldName);
jarray v8ToJava(JNIEnv* env, const v8::Arguments& args, int start, int end, std::list<jvalueType> *methodArgTypes);
jobject v8ToJava(JNIEnv* env, v8::Local<v8::Value> arg, jvalueType *methodArgType);
v8::Handle<v8::Value> javaExceptionToV8(JNIEnv* env, const std::string& alternateMessage);
v8::Handle<v8::Value> javaExceptionToV8(JNIEnv* env, jthrowable ex, const std::string& alternateMessage);
v8::Handle<v8::Value> javaArrayToV8(Java* java, JNIEnv* env, jvalueType itemType, jobjectArray objArray);
v8::Handle<v8::Value> javaToV8(Java* java, JNIEnv* env, jvalueType resultType, jobject obj);

#endif
