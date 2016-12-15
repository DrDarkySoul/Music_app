package com.rda.music.music1.Objects;

/**
 * Created by DENIS on 05.11.2016.
 */

public class ObjMusic {
    private int id;
    private String title, artist, album;
    private int duration;
    private String photo;

    public ObjMusic(){

    }

    public ObjMusic(int id, String title, String artist, String album, int duration, String photo) {
        this.id = id;
        this.title = title;
        this.artist = artist;
        this.album = album;
        this.duration = duration;
        this.photo = photo;
    }

    public void Set(int id, String title, String artist, String album, int duration, String photo) {
        this.id = id;
        this.title = title;
        this.artist = artist;
        this.album = album;
        this.duration = duration;
        this.photo = photo;
    }

    public ObjMusic Get(){
        return this;
    }

    public int getId() {
        return id;
    }

    public int getDuration() {
        return duration;
    }

    public String getAlbum() {
        return album;
    }

    public String getArtist() {
        return artist;
    }

    public String getPhoto() {
        return photo;
    }

    public String getTitle() {
        return title;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setAlbum(String album) {
        this.album = album;
    }

    public void setArtist(String artist) {
        this.artist = artist;
    }

    public void setDuration(int duration) {
        this.duration = duration;
    }

    public void setPhoto(String photo) {
        this.photo = photo;
    }

    public void setTitle(String title) {
        this.title = title;
    }
}
