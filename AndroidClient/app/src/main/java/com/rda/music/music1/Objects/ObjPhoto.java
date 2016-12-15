package com.rda.music.music1.Objects;

/**
 * Created by DENIS on 05.11.2016.
 */

public class ObjPhoto {
    private int id;
    private String link;

    public ObjPhoto(){

    }

    public ObjPhoto(int id, String link) {
        this.id = id;
        this.link = link;
    }

    public void Set(int id, String link) {
        this.id = id;
        this.link = link;
    }

    public ObjPhoto Get() {
        return this;
    }

    public String getLink() {
        return link;
    }

    public int getId() {
        return id;
    }

    public void setLink(String link) {
        this.link = link;
    }

    public void setId(int id) {
        this.id = id;
    }
}
