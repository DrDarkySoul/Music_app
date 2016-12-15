package com.rda.music.music1.MainActivity;

import android.content.Intent;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.NavigationView;
import android.support.v4.view.GravityCompat;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.ActionBarDrawerToggle;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.AppCompatTextView;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ImageView;
import android.widget.Toast;

import com.rda.music.music1.GlobalMap.GlobalMapActivity;
import com.rda.music.music1.MainActivity.Adapters.RVGlobalLocationAdapter;
import com.rda.music.music1.Objects.ObjLocation;
import com.rda.music.music1.R;
import com.rda.music.music1.RecyclerView.UniversalList;
import com.rda.music.music1.Registration.EnterActivity;
import com.rda.music.music1.ServerAdapters.SAdapter;
import com.rda.music.music1.UserItems.Friends.FriendsActivity;
import com.rda.music.music1.UserItems.Locations.UserLocations;

import org.json.JSONObject;

import java.util.ArrayList;
import java.util.HashMap;

public class MainActivity extends AppCompatActivity
        implements NavigationView.OnNavigationItemSelectedListener,
        View.OnClickListener {

    Toolbar toolbar;

    UniversalList universalList;

    FloatingActionButton fabAddLocation;
    NavigationView navigationView;
    ImageView ivAvatar;
    AppCompatTextView tvFullName, tvLogin;

    public static ArrayList<ObjLocation> locations;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        init();
        initRecyclerView();
    }

    protected void init() {
        locations = new ArrayList<>();

        toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        fabAddLocation = (FloatingActionButton) findViewById(R.id.fabAddLocation);
        fabAddLocation.setOnClickListener(this);

        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        ActionBarDrawerToggle toggle = new ActionBarDrawerToggle(
                this, drawer, toolbar, R.string.navigation_drawer_open, R.string.navigation_drawer_close);
        drawer.setDrawerListener(toggle);
        toggle.syncState();

        navigationView = (NavigationView) findViewById(R.id.nav_view);
        navigationView.setNavigationItemSelectedListener(this);

        ivAvatar = (ImageView) navigationView.getHeaderView(0).findViewById(R.id.ivAvatar);
        tvFullName = (AppCompatTextView) navigationView.getHeaderView(0).findViewById(R.id.tvFullName);
        tvLogin = (AppCompatTextView) navigationView.getHeaderView(0).findViewById(R.id.tvLogin);
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
                Toast.makeText(MainActivity.this, locations.get(position).getTitle(), Toast.LENGTH_SHORT).show();
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
        //если получил то удаляю
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

    @Override
    public void onBackPressed() {
        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        if (drawer.isDrawerOpen(GravityCompat.START)) {
            drawer.closeDrawer(GravityCompat.START);
        } else {
            super.onBackPressed();
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        int id = item.getItemId();

        /*if (id == R.id.action_settings) {
            return true;
        }*/

        return super.onOptionsItemSelected(item);
    }

    @SuppressWarnings("StatementWithEmptyBody")
    @Override
    public boolean onNavigationItemSelected(MenuItem item) {
        int id = item.getItemId();

        if (id == R.id.profile) {

        } else if (id == R.id.music) {

        } else if (id == R.id.friends) {
            Intent intent = new Intent(MainActivity.this, FriendsActivity.class);
            startActivity(intent);
        } else if (id == R.id.locations) {
            Intent intent = new Intent(MainActivity.this, UserLocations.class);
            startActivity(intent);
        } else if (id == R.id.about) {

        } else if (id == R.id.map) {
            Intent intent = new Intent(MainActivity.this, GlobalMapActivity.class);
            startActivity(intent);
        } else if (id == R.id.exit) {
            Intent intent = new Intent(MainActivity.this, EnterActivity.class);
            intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_ACTIVITY_CLEAR_TASK);
            startActivity(intent);
        }

        DrawerLayout drawer = (DrawerLayout) findViewById(R.id.drawer_layout);
        drawer.closeDrawer(GravityCompat.START);
        return true;
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()){
            case R.id.fabAddLocation:
                SAdapter sAdapter = new SAdapter(this);
                HashMap<String, String> hashMap = new HashMap<>();
                hashMap.put("login","");
                sAdapter.start(hashMap, new String(), new SAdapter.VolleyCallback() {
                    @Override
                    public void onGet(JSONObject jsonObject) {

                    }

                    @Override
                    public void onError() {

                    }
                });
                break;
        }
    }
}
