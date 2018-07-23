package com.ray.jnithread;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

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

    public void produceCustomerClick(View view) {

    }
}
