#include <jni.h>
#include "pthread.h"
#include "AndroidLog.h"

pthread_t pThread;

pthread_t produceThread;
pthread_t customThread;
pthread_cond_t pthreadCond;
pthread_mutex_t pthreadMutex;

void* produceCallback(void* data) {

}

void* customCallback(void* data) {

}

void* normalThreadCallback(void*){
    LOGD("Create normal thread", "create");
    pthread_exit(&pThread);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_ray_jnithread_ThreadDemo_createNormalThread(JNIEnv *env, jobject instance) {

    pthread_create(&pThread, NULL, normalThreadCallback, NULL);

}extern "C"
JNIEXPORT void JNICALL
Java_com_ray_jnithread_ThreadDemo_produceCustomDemo(JNIEnv *env, jobject instance) {

    pthread_create(&produceThread, NULL, produceCallback, NULL);
    pthread_create(&customThread, NULL, customCallback, NULL);

}