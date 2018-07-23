//
// Created by Administrator on 2018/7/23.
//
#include "android/log.h"

#ifndef JNITHREAD_ANDROIDLOG_H
#define JNITHREAD_ANDROIDLOG_H

#endif //JNITHREAD_ANDROIDLOG_H

#define LOGI(FORMAT,...) __android_log_print(ANDROID_LOG_INFO,"RayMusic_native",FORMAT,##__VA_ARGS__);
#define LOGD(FORMAT,...) __android_log_print(ANDROID_LOG_DEBUG,"RayMusic_native",FORMAT,##__VA_ARGS__);
#define LOGE(FORMAT,...) __android_log_print(ANDROID_LOG_ERROR,"RayMusic_native",FORMAT,##__VA_ARGS__);