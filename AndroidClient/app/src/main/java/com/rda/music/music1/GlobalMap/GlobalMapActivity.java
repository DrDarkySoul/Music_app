package com.rda.music.music1.GlobalMap;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.MenuItem;
import android.view.View;

import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.CameraPosition;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.LatLngBounds;
import com.google.android.gms.maps.model.Marker;
import com.google.android.gms.maps.model.MarkerOptions;
import com.rda.music.music1.R;

import java.util.ArrayList;

public class GlobalMapActivity extends AppCompatActivity implements OnMapReadyCallback, GoogleMap.OnMarkerClickListener, GoogleMap.OnCameraChangeListener, GoogleMap.OnMapClickListener, View.OnClickListener, GoogleMap.OnMarkerDragListener {

    android.support.v7.app.ActionBar actionBar;

    private GoogleMap mMap;
    Marker marker;
    ArrayList<MarkerOptions> markersOptions;
    boolean markerClick = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_global_map);

        init();
        initMap();
    }

    private void init() {
        actionBar = getSupportActionBar();
        actionBar.setDisplayHomeAsUpEnabled(true);
        actionBar.setDisplayShowCustomEnabled(true);
        actionBar.setDisplayShowTitleEnabled(true);

        markersOptions = new ArrayList<>();
    }

    private void initMap() {
        SupportMapFragment mapFragment = (SupportMapFragment) getSupportFragmentManager()
                .findFragmentById(R.id.map);
        mapFragment.getMapAsync(this);
    }

    @Override
    public void onClick(View v) {

    }

    @Override
    public void onMapClick(LatLng latLng) {
        if (marker == null) {
            marker = mMap.addMarker(new MarkerOptions()
                    .draggable(true)
                    .position(latLng));
        } else {
            marker.remove();
            marker = mMap.addMarker(new MarkerOptions()
                    .draggable(true)
                    .position(latLng));
        }
    }

    @Override
    public void onMarkerDragStart(Marker marker) {

    }

    @Override
    public void onMarkerDrag(Marker marker) {

    }

    @Override
    public void onMarkerDragEnd(Marker marker) {
        this.marker = marker;
    }

    @Override
    public void onMapReady(GoogleMap googleMap) {
        mMap = googleMap;

        mMap.getUiSettings().setZoomControlsEnabled(true);
        mMap.getUiSettings().setCompassEnabled(true);
        mMap.getUiSettings().setMapToolbarEnabled(true);

        mMap.setOnMapClickListener(this);
        mMap.setOnMarkerDragListener(this);

        mMap.setOnCameraChangeListener(this);
        mMap.setOnMarkerClickListener(this);
    }


    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {

            case android.R.id.home:
                onBackPressed();
                return true;

        }
        return super.onOptionsItemSelected(item);
    }

    @Override
    public void onCameraChange(CameraPosition cameraPosition) {
        if (!markerClick) {
            markersOptions.clear();
            mMap.clear();
            LatLngBounds bounds = mMap.getProjection().getVisibleRegion().latLngBounds;
            for (int i = 0; i < 10; ++i) {
                MarkerOptions markerOptions = new MarkerOptions();
                markerOptions.draggable(false);
                double minLat = bounds.southwest.latitude, maxLat = bounds.northeast.latitude,
                        minLng = bounds.southwest.longitude, maxLng = bounds.northeast.longitude;
                LatLng latLng = new LatLng(minLat + (Math.random() * (maxLat - minLat) + 1), minLng + (Math.random() * (maxLng - minLng) + 1));
                markerOptions.position(latLng);
                markerOptions.title(String.valueOf(i));
                markerOptions.snippet(String.valueOf(latLng));
                markersOptions.add(markerOptions);
            }
            for (int i = 0; i < 10; ++i) {
                mMap.addMarker(markersOptions.get(i));
            }
        } else {
            markerClick = false;
        }
    }

    @Override
    public boolean onMarkerClick(Marker marker) {
        markerClick = true;
        return false;
    }
}