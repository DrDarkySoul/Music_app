package com.rda.music.music1.RecyclerView;

import android.app.Activity;
import android.content.Context;
import android.support.v4.widget.SwipeRefreshLayout;
import android.support.v7.widget.LinearLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.ProgressBar;

import com.rda.music.music1.R;
import com.rda.music.music1.SupportLibraries.ItemClickSupport;

import java.util.ArrayList;

/**
 * Created by DENIS on 05.11.2016.
 */

public class UniversalList {

    private Context context;
    private SwipeRefreshLayout swipeRefresh;
    private RecyclerView rv;
    private RecyclerView.Adapter rvAdapter;
    private RecyclerView.LayoutManager rvLayoutManager;

    private int FROM = 1, PAGE = 1, COUNT;

    private ImageView ivEmptyList;
    private ProgressBar progressBar;

    public interface Callback {
        void onRefresh();

        void onItemClick(int position);

        boolean onUpdate(int from, int count, int page);

        void onReady(int from, int count, int page);
    }
    public UniversalList(){

    }

    public void Init(Context context, RecyclerView.Adapter adapter, Callback callback) {
        this.context = context;
        COUNT = context.getResources().getInteger(R.integer.count_per_page);
        init(adapter, callback);
    }

    private void init(RecyclerView.Adapter adapter, final Callback callback) {
        ivEmptyList = (ImageView) ((Activity) context).findViewById(R.id.ivEmptyList);
        progressBar = (ProgressBar) ((Activity) context).findViewById(R.id.progressBar);

        swipeRefresh = (SwipeRefreshLayout) ((Activity) context).findViewById(R.id.swipeRefresh);
        swipeRefresh.setOnRefreshListener(new SwipeRefreshLayout.OnRefreshListener() {
            @Override
            public void onRefresh() {
                callback.onRefresh();
            }
        });
        swipeRefresh.setColorSchemeResources(R.color.colorAccent);

        rv = (RecyclerView) ((Activity) context).findViewById(R.id.rvList);

        rvLayoutManager = new LinearLayoutManager(context, LinearLayoutManager.VERTICAL, false);
        rv.setLayoutManager(rvLayoutManager);

        rvAdapter = adapter;
        rv.setAdapter(rvAdapter);

        ItemClickSupport.addTo(rv).setOnItemClickListener(new ItemClickSupport.OnItemClickListener() {
            @Override
            public void onItemClicked(RecyclerView recyclerView, int position, View v) {
                callback.onItemClick(position);
            }
        });

        rv.addOnScrollListener(new RecyclerView.OnScrollListener() {
            @Override
            public void onScrollStateChanged(RecyclerView recyclerView, int newState) {
                super.onScrollStateChanged(recyclerView, newState);
            }

            @Override
            public void onScrolled(RecyclerView recyclerView, int dx, int dy) {
                super.onScrolled(recyclerView, dx, dy);

                int totalItemCount = rvLayoutManager.getItemCount();
                LinearLayoutManager layoutManager = ((LinearLayoutManager) rv.getLayoutManager());
                int firstVisiblePosition = layoutManager.findFirstVisibleItemPosition();

                if (dy > 0) {
                    if ((firstVisiblePosition == totalItemCount / 2 + 1) && (totalItemCount == COUNT * PAGE)) {
                        RollForward();
                        Log.d("myLogs", "adssfd = " + FROM + " " + COUNT + " " + PAGE);
                        if(!callback.onUpdate(FROM, COUNT, PAGE)){
                            RollBack();
                        }
                    }
                }
            }
        });

        callback.onReady(FROM, COUNT, PAGE);
    }

    private void RollForward() {
        FROM += COUNT;
        PAGE += 1;
    }

    private void RollBack() {
        if (PAGE > 1) {
            FROM -= COUNT;
            PAGE -= 1;
        }
    }

    public void RecyclerViewNotifyDataSetChanged() {
        rvAdapter.notifyDataSetChanged();
    }

    public void SetRefreshing(boolean set) {
        swipeRefresh.setRefreshing(set);
    }

    public void CheckEmpty(ArrayList list){
        if(list.isEmpty()){
            ivEmptyList.setVisibility(View.VISIBLE);
        } else {
            ivEmptyList.setVisibility(View.GONE);
        }
    }

    public void StartProgress(){
        progressBar.setVisibility(View.VISIBLE);
    }

    public void FinishProgress(){
        progressBar.setVisibility(View.GONE);
    }
}
