package com.example.myweather;

import androidx.appcompat.app.ActionBar;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.Toast;

import com.example.myweather.db.City;
import com.example.myweather.db.dbHelper;

import java.util.ArrayList;
import java.util.List;

public class History extends AppCompatActivity implements View.OnClickListener {

    List<City> cityList = new ArrayList<>();
    private static final String TAG = "History";
    WeatherAdapter weatherAdapter = null;
    RecyclerView recyclerView = null;
    LinearLayoutManager manager = null;
    Button clearButton = null;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_history);
        clearButton = (Button)findViewById(R.id.button_clear);

        ActionBar actionBar = getSupportActionBar();
        if(actionBar!=null)
        {
            actionBar.hide();
        }

        loadDB();
        weatherAdapter = new WeatherAdapter(cityList);
        recyclerView = (RecyclerView) findViewById(R.id.recycle_view);
        manager = new LinearLayoutManager(this);
        recyclerView.setLayoutManager(manager);
        recyclerView.setAdapter(weatherAdapter);
        clearButton.setOnClickListener(this);
    }

    public void loadDB(){
        //                Log.d(TAG, "调试：进入history的监听器");
        dbHelper helper = new dbHelper(History.this,"CityWeather.db",null,3);
        SQLiteDatabase db = helper.getReadableDatabase();
        Cursor cursor = db.query("City",null,null,null,null,null,null);
//                Log.d(TAG, "调试：获得cursor");
        if (cursor.moveToFirst()){
//                    Log.d(TAG, "调试：进入if");
            do{
                City city = new City();
                city.setCity(cursor.getString(cursor.getColumnIndex("city")));
                city.setTem(cursor.getString(cursor.getColumnIndex("tem")));
                city.setTem_day(cursor.getString(cursor.getColumnIndex("tem_day")));
                city.setTem_night(cursor.getString(cursor.getColumnIndex("tem_night")));
                city.setWea(cursor.getString(cursor.getColumnIndex("wea")));
                city.setAir(cursor.getString(cursor.getColumnIndex("air")));
                city.setWin(cursor.getString(cursor.getColumnIndex("win")));
                city.setWin_speed(cursor.getString(cursor.getColumnIndex("win_speed")));
                city.setSearchtime(cursor.getString(cursor.getColumnIndex("search_time")));
                cityList.add(city);
                Log.d(TAG, "调试： 城市："+city.getCity());
                Log.d(TAG, "调试：温度："+city.getTem());
                Log.d(TAG, "调试：查询时间"+city.getSearchtime());
            } while(cursor.moveToNext());

        }
        cursor.close();
    }


    @Override
    public void onClick(View v) {
        switch (v.getId()){
            case R.id.button_clear:
                if(!cityList.isEmpty()){
                    cityList.clear();
                    weatherAdapter.notifyDataSetChanged();
                    dbHelper helper = new dbHelper(History.this,"CityWeather.db",null,3);
                    SQLiteDatabase db = helper.getWritableDatabase();
                    db.delete("City",null,null);
                    Toast.makeText(History.this,"清空成功",Toast.LENGTH_SHORT).show();
                }

                break;

            default:
                break;
        }
    }
}
