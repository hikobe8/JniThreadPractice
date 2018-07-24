package com.ray.jnithread;

/***
 *  Author : ryu18356@gmail.com
 *  Create at 2018-07-23 17:59
 *  description : 
 */
public class ThreadDemo {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    public native void createNormalThread();

    public native void produceCustomDemo();

    public native void stopProduceCustomDemo();
}


