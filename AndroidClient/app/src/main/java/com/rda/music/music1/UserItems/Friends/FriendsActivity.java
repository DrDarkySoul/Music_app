package com.rda.music.music1.UserItems.Friends;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.MenuItem;
import android.widget.Toast;

import com.rda.music.music1.Objects.ObjUser;
import com.rda.music.music1.R;
import com.rda.music.music1.RecyclerView.UniversalList;
import com.rda.music.music1.UserItems.Friends.Adapters.RVUserFriendsAdapter;

import java.util.ArrayList;

public class FriendsActivity extends AppCompatActivity {

    public static ArrayList<ObjUser> friends;
    UniversalList universalList;

    android.support.v7.app.ActionBar actionBar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_friends);

        init();
        initRecyclerView();
    }

    private void init(){
        friends = new ArrayList<>();

        actionBar = getSupportActionBar();
        actionBar.setDisplayHomeAsUpEnabled(true);
        actionBar.setDisplayShowCustomEnabled(true);
        actionBar.setDisplayShowTitleEnabled(true);
    }

    protected void initRecyclerView() {
        universalList = new UniversalList();
        universalList.Init(this, new RVUserFriendsAdapter(this), new UniversalList.Callback() {
            @Override
            public void onRefresh() {
                refreshFriends(friends.size());
            }

            @Override
            public void onItemClick(int position) {
                Toast.makeText(FriendsActivity.this, friends.get(position).getNickname(), Toast.LENGTH_SHORT).show();
            }

            @Override
            public boolean onUpdate(int from, int count, int page) {
                Log.d("myLogs", from + " " + count + " " + page);
                return getFriends(from, count, page);
            }

            @Override
            public void onReady(int from, int count, int page) {
                getFriends(from, count, page);
            }
        });
    }

    private void refreshFriends(int Size) {
        //если получил то удаляю
        if (true) {
            friends.clear();
            for (int i = 0; i < Size; ++i) {
                ObjUser objUser = new ObjUser();
                objUser.setNickname("Nickname " + i);
                friends.add(objUser);
            }
            universalList.RecyclerViewNotifyDataSetChanged();
        }
        universalList.SetRefreshing(false);
    }

    private boolean getFriends(int FROM, int COUNT, int PAGE) {
        for (int i = FROM - 1; i < COUNT * PAGE; ++i) {
            ObjUser objUser = new ObjUser();
            objUser.setNickname("Nickname " + i);
            friends.add(objUser);
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
