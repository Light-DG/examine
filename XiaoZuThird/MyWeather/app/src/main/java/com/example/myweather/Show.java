package com.example.myweather;

import androidx.appcompat.app.AppCompatActivity;

import android.content.ContentValues;
import android.content.Intent;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.example.myweather.db.City;
import com.example.myweather.db.dbHelper;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.SimpleTimeZone;

public class Show extends AppCompatActivity {

    private static final String TAG = "Show";
    City city =null;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.show);
        Date date = new Date(System.currentTimeMillis());
        SimpleDateFormat formatter = new SimpleDateFormat("yyyy-MM-dd HH:mm");
        TextView cityName = (TextView) findViewById(R.id.text_city_name);
        TextView nowTemp = (TextView)findViewById(R.id.text_temp_now);
        TextView maxAndMinTemp = (TextView) findViewById(R.id.text_max_and_min_temp);
        TextView weaAndAir = (TextView)findViewById(R.id.wea_and_air);
        TextView windAndSpeed = (TextView)findViewById(R.id.text_win_and_speed);
        Intent intent = getIntent();
        city = (City) intent.getSerializableExtra("city");
        city.setSearchtime(formatter.format(date));
        cityName.setText(city.getCity());
        nowTemp.setText(city.getTem());
        maxAndMinTemp.setText(city.getTem_day()+" / "+city.getTem_night());
        weaAndAir.setText(city.getWea()+" "+city.getAir());
        windAndSpeed.setText(city.getWin()+"   "+city.getWin_speed());
    }

    @Override
    protected void onDestroy() {
        new Thread(new Runnable() {

            dbHelper helper =null;
            SQLiteDatabase db = null;
            public void run() {
                helper = new dbHelper(Show.this,"CityWeather.db",null,3);
                db = helper.getWritableDatabase();
                ContentValues values = new ContentValues();
                values.put("city",city.getCity());
                values.put("tem",city.getTem());
                values.put("tem_day",city.getTem_day());
                values.put("tem_night",city.getTem_night());
                values.put("wea",city.getWea());
                values.put("air",city.getAir());
                values.put("win",city.getWin());
                values.put("win_speed",city.getWin_speed());
                values.put("search_time",city.getSearchtime());
                db.insert("City",null,values);
                values.clear();
            }
        }).start();
        super.onDestroy();
    }
}
