package com.example.myweather;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.os.Message;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.example.myweather.db.City;
import com.example.myweather.db.dbHelper;
import com.example.myweather.http.HttpCallbackListener;
import com.example.myweather.http.HttpUtil;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.List;
import java.util.regex.Pattern;

public class MainActivity extends AppCompatActivity implements View.OnClickListener{

    private static final String TAG = "MainActivity";
    Button mycityButton = null;
    Button searchButton = null;
    Button historyButton = null;
    EditText editText = null;

    TextView mainCity = null;
    TextView mainTemp = null;
    TextView mainWea = null;
    TextView mainWind = null;
    TextView mainMinAndMax = null;
    ImageView mainImage = null;

    private Handler handler = new Handler(){

        public void handleMessage(Message msg)
      {
          City city = (City) msg.obj;
          setMainWeather(city);
      }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
//        Log.d(TAG, "调试：进入MainActivity中的onCreate");
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mycityButton = (Button)findViewById(R.id.button_my_city);
        searchButton = (Button)findViewById(R.id.button_search);
        historyButton = (Button)findViewById(R.id.button_history);
        editText = (EditText)findViewById(R.id.edit_text);

        mainImage = (ImageView)findViewById(R.id.image_main_wea);
        mainCity = (TextView)findViewById(R.id.text_main_cityname);
        mainTemp = (TextView)findViewById(R.id.text_main_temp);
        mainWea = (TextView)findViewById(R.id.text_main_wea);
        mainWind = (TextView)findViewById(R.id.text_main_wind);
        mainMinAndMax = (TextView)findViewById(R.id.text_main_minandmaxtemp);

        mycityButton.setOnClickListener(this);
        searchButton.setOnClickListener(this);
        historyButton.setOnClickListener(this);

        StringBuilder baseAddress = new StringBuilder();
        baseAddress.append( "https://www.tianqiapi.com/free/day?appid=55617213&appsecret=1zJIKUQU");
        HttpUtil.sendHttpRequest(baseAddress.toString(), new HttpCallbackListener() {
            @Override
            public void onFinish(String response) {
                City city = null;
                city = HttpUtil.PaseJSON(response);
                Message message = new Message();
                message.obj = city;
                handler.sendMessage(message);
            }
            @Override
            public void onError(Exception e) {

            }
        });


    }



    public void setMainWeather(City city){

        mainCity.setText(city.getCity());
        mainTemp.setText(city.getTem());
        mainWea.setText(city.getWea());
        mainWind.setText(city.getWin()+city.getWin_speed()+" |");
        mainMinAndMax.setText(city.getTem_day()+"~"+city.getTem_night());
        if(city.getWea_img().equals("bingbao"))
        {
            mainImage.setImageResource(R.drawable.bingbao);
        }else if(city.getWea_img().equals("lei"))
        {
            mainImage.setImageResource(R.drawable.lei);
        }else if(city.getWea_img().equals("qing"))
        {
            mainImage.setImageResource(R.drawable.qing);
        }else if(city.getWea_img().equals("shachen"))
        {
            mainImage.setImageResource(R.drawable.shachen);
        }else if(city.getWea_img().equals("wu"))
        {
            mainImage.setImageResource(R.drawable.wu);
        }else if(city.getWea_img().equals("xue"))
        {
            mainImage.setImageResource(R.drawable.xue);
        }else if(city.getWea_img().equals("yin"))
        {
            mainImage.setImageResource(R.drawable.yin);
        }else if(city.getWea_img().equals("yu"))
        {
            mainImage.setImageResource(R.drawable.yu);
        }else if(city.getWea_img().equals("yun"))
        {
            mainImage.setImageResource(R.drawable.yun);
        }
    }



    @Override
    public void onClick(View v) {
        final Toast toast1 = Toast.makeText(MainActivity.this,"未找到该地点",Toast.LENGTH_SHORT);
        Toast toast2 = Toast.makeText(MainActivity.this,"请输入中文字符",Toast.LENGTH_SHORT);
        StringBuilder baseAddress = new StringBuilder();
        baseAddress.append( "https://www.tianqiapi.com/free/day?appid=55617213&appsecret=1zJIKUQU");
        switch (v.getId()){
            case R.id.button_my_city:
                HttpUtil.sendHttpRequest(baseAddress.toString(), new HttpCallbackListener() {
                    @Override
                    public void onFinish(String response) {
                        City city = null;
                        city =HttpUtil.PaseJSON(response);
                        Intent intent = new Intent(MainActivity.this,Show.class);
                        intent.putExtra("city", city);
                        startActivity(intent);
                    }
                    @Override
                    public void onError(Exception e) {

                    }
                });

                break;

            case R.id.button_search:
                final String add = editText.getText().toString();
                if(!(add.equals("")))
                {
                    if(!isChineseWord(add))
                    {
                        toast2.show();
                        editText.setText("");
                        break;
                    }
                    if(add!=null&&add.length()!=0)
                    {
                        baseAddress.append("&&city="+add);
                    }
                    editText.setText("");

                    HttpUtil.sendHttpRequest(baseAddress.toString(), new HttpCallbackListener() {
                        @Override
                        public void onFinish(String response) {
                            String cityname = HttpUtil.PasetoName(response);
                            if(response.equals("{\"errcode\":100,\"errmsg\":\"city\\u4e0d\\u5b58\\u5728!\"}"))
                            {
                                toast1.show();
                            }else if(!cityname.equals(add)){
                                toast1.show();
                            }else{
                                City city = null;
                                city = HttpUtil.PaseJSON(response);
                                Intent intent = new Intent(MainActivity.this,Show.class);
                                intent.putExtra("city", city);
                                startActivity(intent);
                            }

                        }
                        @Override
                        public void onError(Exception e) {

                        }
                    });

                }

                break;
            case R.id.button_history:
                Intent intent = new Intent(MainActivity.this,History.class);
                startActivity(intent);
                break;
            default:
                break;
        }
    }

    public static boolean isChineseWord(String str){
        String pattern  = "[\u4e00-\u9fa5]+";
        boolean isMatch = Pattern.matches(pattern,str);
        return isMatch;
    }




}
