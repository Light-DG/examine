package com.example.myweather.db;

import android.media.Image;
import android.widget.ImageView;

import java.io.Serializable;

public class City implements Serializable {
    private String wea_img;
    private String city;
    private String wea;
    private String tem;
    private String tem_day;
    private String tem_night;
    private String win;
    private String win_speed;
    private String air;
    private String searchtime;

    public String getWea_img() {
        return wea_img;
    }

    public void setWea_img(String wea_image) {
        this.wea_img = wea_image;
    }

    public City() {
    }

    public String getSearchtime() {
        return searchtime;
    }

    public void setSearchtime(String searchtime) {
        this.searchtime = searchtime;
    }

    public String getCity() {
        return city;
    }


    public String getWea() {
        return wea;
    }

    public String getTem() {
        return tem;
    }

    public String getTem_day() {
        return tem_day;
    }

    public String getTem_night() {
        return tem_night;
    }

    public String getWin() {
        return win;
    }

    public String getWin_speed() {
        return win_speed;
    }

    public String getAir() {
        return air;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public void setTem(String tem) {
        this.tem = tem;
    }

    public void setTem_day(String tem_day) {
        this.tem_day = tem_day;
    }

    public void setTem_night(String tem_night) {
        this.tem_night = tem_night;
    }

    public void setWin(String win) {
        this.win = win;
    }

    public void setWin_speed(String win_speed) {
        this.win_speed = win_speed;
    }

    public void setAir(String air) {
        this.air = air;
    }


    public void setWea(String wea) {
        this.wea = wea;
    }


}
