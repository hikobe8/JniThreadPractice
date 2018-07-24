package com.ray.jnithread;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    ThreadDemo mThreadDemo;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mThreadDemo = new ThreadDemo();
    }

    public void createNormalThread(View view) {
        mThreadDemo.createNormalThread();
    }

    boolean started;

    public void produceCustomerClick(View view) {
        if (started) {
            ((TextView)view).setText("生产者消费者");
            mThreadDemo.stopProduceCustomDemo();
            started = false;
        } else {
            mThreadDemo.produceCustomDemo();
            ((TextView)view).setText("停止生产者消费者");
            started = true;
        }
    }
}
