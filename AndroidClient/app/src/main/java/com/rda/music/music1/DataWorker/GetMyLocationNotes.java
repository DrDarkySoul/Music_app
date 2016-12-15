package com.rda.music.music1.DataWorker;

import android.content.Context;

import com.rda.music.music1.Objects.ObjLocation;
import com.rda.music.music1.ServerAdapters.SAdapter;

import org.json.JSONObject;

import java.util.ArrayList;
import java.util.HashMap;

/**
 * Created by DENIS on 12.12.2016.
 */

public class GetMyLocationNotes {

    private Context context;
    Callback callback;

    public GetMyLocationNotes(Context context) {
        this.context = context;
    }

    public interface Callback {
        void onSuccess();

        void onError();
    }

    public void GetData() {
        SAdapter sAdapter = new SAdapter(context);
        HashMap<String, String> hashMap = new HashMap<>();
        hashMap.put("login", "");
        sAdapter.start(hashMap, new String(), new SAdapter.VolleyCallback() {
            @Override
            public void onGet(JSONObject jsonObject) {
                AnalyseJSON(jsonObject);
            }

            @Override
            public void onError() {
                callback.onError();
            }
        });
    }

    private ArrayList<ObjLocation> AnalyseJSON(JSONObject jsonObject) {
        return new ArrayList<>();
    }
}
