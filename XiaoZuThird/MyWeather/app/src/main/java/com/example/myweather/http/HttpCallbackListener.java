package com.example.myweather.http;

import com.example.myweather.db.City;

public interface HttpCallbackListener {
    void onFinish(String response);
    void onError(Exception e);
}
