package com.rda.music.music1.ServerAdapters;

import android.content.Context;
import android.os.AsyncTask;

import com.android.volley.AuthFailureError;
import com.android.volley.DefaultRetryPolicy;
import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONException;
import org.json.JSONObject;

import java.util.HashMap;
import java.util.Map;

/**
 * Created by DENIS on 24.08.2016.
 */
public class SAdapter {
    private RequestQueue requestQueue;

    private Context context;
    private JSONObject result;

    private VolleyCallback callback;
    private HashMap<String, String> hashMap;
    private String url;

    private AsyncTask0 task;

    public SAdapter(Context context) {
        this.context = context;
        uploadData();
        task = new AsyncTask0();
    }

    public interface VolleyCallback {
        void onGet(JSONObject jsonObject);

        void onError();
    }

    public void uploadData() {
        if (requestQueue == null) {
            requestQueue = Volley.newRequestQueue(context);
        }
    }

    public void start(final HashMap<String, String> hashMap, final String url, final VolleyCallback callback) {
        this.hashMap = hashMap;
        this.url = url;
        this.callback = callback;
        task.execute();
    }

    private class AsyncTask0 extends AsyncTask<Void, Void, Void> {

        @Override
        protected void onPreExecute() {
            super.onPreExecute();
        }

        @Override
        protected Void doInBackground(Void... params) {
            request();
            return null;
        }

        @Override
        protected void onPostExecute(Void result) {
            super.onPostExecute(result);
        }

        @Override
        protected void onProgressUpdate(Void... values) {
            super.onProgressUpdate(values);
        }

        @Override
        protected void onCancelled() {
            super.onCancelled();
        }
    }

    private void request(){
        StringRequest request = new StringRequest(Request.Method.POST, url, new Response.Listener<String>() {

            @Override
            public void onResponse(String response) {
                try {
                    result = new JSONObject(response);
                } catch (JSONException e) {
                    e.printStackTrace();
                }
                callback.onGet(result);
            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                callback.onError();
            }
        }) {
            @Override
            protected Map<String, String> getParams() throws AuthFailureError {
                return hashMap;
            }
        };

        request.setRetryPolicy(new DefaultRetryPolicy(20000,
                DefaultRetryPolicy.DEFAULT_MAX_RETRIES,
                DefaultRetryPolicy.DEFAULT_BACKOFF_MULT));
        requestQueue.add(request);
    }

    public void cancel(){
        task.cancel(true);
    }
}
