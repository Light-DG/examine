package com.example.myweather.http;

import android.util.Log;

import com.example.myweather.db.City;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;

public class HttpUtil {

    private static final String TAG = "HttpUtil";

    public static void sendHttpRequest(final String address,final HttpCallbackListener listener){
        new Thread(new Runnable() {
            HttpURLConnection connection = null;
            InputStream is = null;
            BufferedReader br = null;
            StringBuilder response = new StringBuilder();
            public void run() {
                try {
                    URL url = new URL(address);
                    connection = (HttpURLConnection) url.openConnection();
                    connection.setRequestMethod("GET");
                    connection.setReadTimeout(8000);
                    connection.setReadTimeout(8000);
                    is = connection.getInputStream();
                    br = new BufferedReader(new InputStreamReader(is));
                    String line;
                    while ((line=br.readLine())!=null)
                    {
                        response.append(line);
                    }
                    Log.d(TAG,"调试：response01: "+response);
                    if(listener!=null)
                    {
                        listener.onFinish(response.toString());
                    }
                } catch (MalformedURLException e) {
                    if (listener!=null)
                    {
                        listener.onError(e);
                    }
                    e.printStackTrace();
                } catch (IOException e) {
                    e.printStackTrace();
                } finally {
                    try {
                        if(br!=null)
                        {
                            br.close();
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                    }

                    try {
                        if(is!=null)
                        {
                            is.close();
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                    }

                    if (connection!=null)
                    {
                        connection.disconnect();
                    }
                }
            }
        }).start();
    }

    public static City PaseJSON(String jsonData){
//        Log.d(TAG, "调试：进入PaseJSON");
         Log.d(TAG, "调试：response: "+jsonData);
        City city = new City();
        char[] temp = jsonData.toCharArray();
        if(temp[0] == '[')
        {
            try {
//                Log.d(TAG, "调试：获得数组前");
                JSONArray jsonArray = new JSONArray(jsonData);
//                Log.d(TAG, "调试：数组长度： "+jsonArray.length());
                for(int i = 0;i<jsonArray.length();i++)
                {
                    JSONObject jsonObject = jsonArray.getJSONObject(i);
                    String cityname = jsonObject.getString("city");
                    city.setCity(cityname);
                    city.setTem(jsonObject.getString("tem")+"℃");
                    city.setTem_day(jsonObject.getString("tem_day")+"℃");
                    city.setTem_night(jsonObject.getString("tem_night")+"℃");
                    city.setWea(jsonObject.getString("wea"));
                    if(jsonObject.getString("air").equals(""))
                    {
                        city.setAir("");
                    }else {
                        city.setAir("空气指数"+jsonObject.getString("air"));
                    }
                    if(jsonObject.getString("win").equals(""))
                    {
                        city.setWin("");
                    }else{
                        city.setWin(jsonObject.getString("win"));
                    }
                    if(jsonObject.getString("win_speed").equals(""))
                    {
                        city.setWin_speed("");
                    }else{
                        city.setWin_speed(jsonObject.getString("win_speed"));
                    }

                    city.setWea_img(jsonObject.getString("wea_img"));
                    Log.d(TAG, "调试：城市名： "+cityname);
                }
            } catch (JSONException e) {
                e.printStackTrace();
            }
        }else if(temp[0]=='{')
        {
            try {
                JSONObject jsonObject = new JSONObject(jsonData);
                String cityname = jsonObject.getString("city");
                city.setCity(cityname);
                city.setTem(jsonObject.getString("tem")+"℃");
                city.setTem_day(jsonObject.getString("tem_day")+"℃");
                city.setTem_night(jsonObject.getString("tem_night")+"℃");
                city.setWea(jsonObject.getString("wea"));
                if(jsonObject.getString("air").equals(""))
                {
                    city.setAir("");
                }else {
                    city.setAir("空气指数"+jsonObject.getString("air"));
                }
                if(jsonObject.getString("win").equals(""))
                {
                    city.setWin("");
                }else{
                    city.setWin(jsonObject.getString("win"));
                }
                if(jsonObject.getString("win_speed").equals(""))
                {
                    city.setWin_speed("");
                }else{
                    city.setWin_speed(jsonObject.getString("win_speed"));
                }
                city.setWea_img(jsonObject.getString("wea_img"));
                Log.d(TAG, "调试：城市名： "+cityname);
            } catch (JSONException e) {
                e.printStackTrace();
            }
        }
        return city;

    }

    public static String PasetoName(String JsonData)
    {
        String city =null;
        try {
            JSONObject object = new JSONObject(JsonData);
            city = object.getString("city");
        } catch (JSONException e) {
            e.printStackTrace();
        }
        return city;
    }


}
