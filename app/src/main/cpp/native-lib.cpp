#include <jni.h>
#include "pthread.h"
#include "AndroidLog.h"
#include "queue"
#include "unistd.h"

pthread_t pThread;

pthread_t produceThread;
pthread_t customThread;
pthread_cond_t pthreadCond;
pthread_mutex_t pthreadMutex;
std::queue<int> products;
bool quit = false;

void *produceCallback(void *data) {
    while (!quit) {
        pthread_mutex_lock(&pthreadMutex);
        products.push(1);
        LOGD("生产者生产一个产品，通知消费者消费， 产品数量为 %d", products.size());
        pthread_cond_signal(&pthreadCond);
        pthread_mutex_unlock(&pthreadMutex);
        sleep(2);
    }
    LOGD("结束生产者线程");
    pthread_cond_signal(&pthreadCond);
    pthread_mutex_unlock(&pthreadMutex);
    pthread_mutex_destroy(&pthreadMutex);
    pthread_cond_destroy(&pthreadCond);
    pthread_exit(&produceThread);
}

void *customCallback(void *data) {
    while (!quit) {
        pthread_mutex_lock(&pthreadMutex);
        if (products.size() > 0) {
            products.pop();
            LOGD("消费者消费产品，产品数量还剩余 %d ", products.size());
        } else {
            LOGD("没有产品可以消费， 等待中...");
            pthread_cond_wait(&pthreadCond, &pthreadMutex);
        }
        pthread_mutex_unlock(&pthreadMutex);
        usleep(500 * 1000);
    }
    LOGD("结束消费者线程");
    pthread_mutex_unlock(&pthreadMutex);
    pthread_mutex_destroy(&pthreadMutex);
    pthread_cond_destroy(&pthreadCond);
    pthread_exit(&customThread);
}

void *normalThreadCallback(void *) {
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
    quit = false;
    for (int i = 0; i < 10; ++i) {
        products.push(1);
    }
    pthread_mutex_init(&pthreadMutex, NULL);
    pthread_cond_init(&pthreadCond, NULL);
    pthread_create(&produceThread, NULL, produceCallback, NULL);
    pthread_create(&customThread, NULL, customCallback, NULL);

}extern "C"
JNIEXPORT void JNICALL
Java_com_ray_jnithread_ThreadDemo_stopProduceCustomDemo(JNIEnv *env, jobject instance) {

    quit = true;

}