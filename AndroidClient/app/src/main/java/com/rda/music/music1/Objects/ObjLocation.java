package com.rda.music.music1.Objects;

import java.util.ArrayList;

/**
 * Created by DENIS on 05.11.2016.
 */

public class ObjLocation {
    private int id, user_id;
    private String title;
    private double latitude, longitude;
    private String photo;
    private ArrayList<ObjMusic> arrMusic;


    public ObjLocation() {

    }

    public ObjLocation(int id, int user_id, String title, double latitude, double longitude, String photo, ArrayList<ObjMusic> arr_music) {
        this.id = id;
        this.user_id = user_id;
        this.title = title;
        this.latitude = latitude;
        this.longitude = longitude;
        this.photo = photo;
        this.arrMusic = arr_music;
    }

    public void Set(int id, int user_id, String title, double latitude, double longitude, String photo, ArrayList<ObjMusic> arr_music) {
        this.id = id;
        this.user_id = user_id;
        this.title = title;
        this.latitude = latitude;
        this.longitude = longitude;
        this.photo = photo;
        this.arrMusic = arr_music;
    }

    public ObjLocation Get() {
        return this;
    }

    public int getUser_id() {
        return user_id;
    }

    public ArrayList<ObjMusic> getArrMusic() {
        return arrMusic;
    }

    public String getPhoto() {
        return photo;
    }

    public double getLatitude() {
        return latitude;
    }

    public double getLongitude() {
        return longitude;
    }

    public int getId() {
        return id;
    }

    public void setArrMusic(ArrayList<ObjMusic> arrMusic) {
        this.arrMusic = arrMusic;
    }

    public void setPhoto(String photo) {
        this.photo = photo;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setLatitude(double latitude) {
        this.latitude = latitude;
    }

    public void setLongitude(double longitude) {
        this.longitude = longitude;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void setUser_id(int user_id) {
        this.user_id = user_id;
    }
}
