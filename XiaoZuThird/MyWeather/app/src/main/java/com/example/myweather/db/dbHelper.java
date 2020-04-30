package com.example.myweather.db;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.widget.Toast;

public class dbHelper extends SQLiteOpenHelper {

    public static final String CREATE_BOOK ="create table City("
            + "cityid text primary key ,"
            +"city text,"
            +"wea text,"
            +"wea_img text,"
            +"tem text,"
            +"tem_day text,"
            +"tem_night text,"
            +"win text,"
            +"win_speed text,"
            +"search_time text,"
            +"air text)";

    private Context mContext;

    public dbHelper(Context context,String name,SQLiteDatabase.CursorFactory factory,int version){
        super(context,name,factory,version);
        mContext=context;
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL(CREATE_BOOK);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {

    }
}
