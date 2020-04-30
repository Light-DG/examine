package com.example.myweather;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.example.myweather.db.City;

import java.util.ArrayList;
import java.util.List;

public class WeatherAdapter extends RecyclerView.Adapter <WeatherAdapter.ViewHolder> {

    List<City> mcityilst;

    class ViewHolder extends RecyclerView.ViewHolder{
        TextView cityname;
        TextView temp;
        TextView temp_minandmax;
        TextView wea;
        TextView wind;
        TextView searchtime;

        public ViewHolder(View v){
            super(v);
            cityname = (TextView) v.findViewById(R.id.text_history_cityname);
            temp = (TextView) v.findViewById(R.id.text_history_temp);
            temp_minandmax = (TextView) v.findViewById(R.id.text_history_minandmax);
            wea = (TextView)v.findViewById(R.id.text_history_wea);
            wind = (TextView) v.findViewById(R.id.text_history_wind);
            searchtime = (TextView)v.findViewById(R.id.text_history_searchtime);
        }

    }

    public WeatherAdapter(List<City> list){
        mcityilst = list;
    }

    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.every_city,parent,false);
        ViewHolder holder = new ViewHolder(view);
        return holder;
    }

    @Override
    public void onBindViewHolder(@NonNull WeatherAdapter.ViewHolder holder, int position) {
        City city = mcityilst.get(position);
        holder.cityname.setText(city.getCity());
        holder.temp.setText(city.getTem());
        holder.temp_minandmax.setText(city.getTem_day()+"~"+city.getTem_night());
        holder.wea.setText(city.getWea());
        holder.wind.setText(city.getWin()+city.getWin_speed());
        holder.searchtime.setText(city.getSearchtime());
    }

    @Override
    public int getItemCount() {
        return mcityilst.size();
    }
}
