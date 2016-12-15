package com.rda.music.music1.UserItems.Locations;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.MenuItem;
import android.widget.Toast;

import com.rda.music.music1.MainActivity.Adapters.RVGlobalLocationAdapter;
import com.rda.music.music1.Objects.ObjLocation;
import com.rda.music.music1.R;
import com.rda.music.music1.RecyclerView.UniversalList;

import java.util.ArrayList;

public class UserLocations extends AppCompatActivity {

    UniversalList universalList;

    public static ArrayList<ObjLocation> locations;

    android.support.v7.app.ActionBar actionBar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_user_locations);

        init();
        initRecyclerView();
    }

    protected void init() {
        locations = new ArrayList<>();

        actionBar = getSupportActionBar();
        actionBar.setDisplayHomeAsUpEnabled(true);
        actionBar.setDisplayShowCustomEnabled(true);
        actionBar.setDisplayShowTitleEnabled(true);
    }

    protected void initRecyclerView() {
        universalList = new UniversalList();
        universalList.Init(this, new RVGlobalLocationAdapter(this), new UniversalList.Callback() {
            @Override
            public void onRefresh() {
                refreshLocations(locations.size());
            }

            @Override
            public void onItemClick(int position) {
                Toast.makeText(UserLocations.this, locations.get(position).getTitle(), Toast.LENGTH_SHORT).show();
            }

            @Override
            public boolean onUpdate(int from, int count, int page) {
                return getLocations(from, count, page);
            }

            @Override
            public void onReady(int from, int count, int page) {
                getLocations(from, count, page);
            }
        });
    }

    private void refreshLocations(int Size) {
        if (true) {
            locations.clear();
            for (int i = 0; i < Size; ++i) {
                ObjLocation objLocation = new ObjLocation();
                objLocation.setTitle("TITLE " + i);
                locations.add(objLocation);
            }
            universalList.RecyclerViewNotifyDataSetChanged();
        }
        universalList.SetRefreshing(false);
    }

    private boolean getLocations(int FROM, int COUNT, int PAGE) {

        for (int i = FROM - 1; i < COUNT * PAGE; ++i) {
            ObjLocation objLocation = new ObjLocation();
            objLocation.setTitle("TITLE " + i);
            locations.add(objLocation);
        }

        universalList.RecyclerViewNotifyDataSetChanged();
        universalList.SetRefreshing(false);

        return true;
    }

    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {

            case android.R.id.home:
                onBackPressed();
                return true;

        }
        return super.onOptionsItemSelected(item);
    }
}
