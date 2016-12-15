package com.rda.music.music1.Objects;

import java.util.ArrayList;

/**
 * Created by DENIS on 05.11.2016.
 */

public class ObjUser {
    private int id;
    private String login, password, email, nickname, photo;
    private ArrayList<Integer> arrMusic, arrLocation, arrFriends;

    public ObjUser(){

    }

    public ObjUser(int id, String login, String password, String email, String nickname, String photo,
                   ArrayList<Integer> arrMusic, ArrayList<Integer> arrLocation, ArrayList<Integer> arrFriends) {
        this.id = id;
        this.login = login;
        this.nickname = nickname;
        this.photo = photo;
        this.password = password;
        this.email = email;
        this.arrMusic = arrMusic;
        this.arrLocation = arrLocation;
        this.arrFriends = arrFriends;
    }

    public void SetUser(int id, String login, String password, String email, String nickname, String photo,
                   ArrayList<Integer> arrMusic, ArrayList<Integer> arrLocation, ArrayList<Integer> arrFriends){
        this.id = id;
        this.login = login;
        this.nickname = nickname;
        this.photo = photo;
        this.password = password;
        this.email = email;
        this.arrMusic = arrMusic;
        this.arrLocation = arrLocation;
        this.arrFriends = arrFriends;
    }

    public ObjUser GetUser(){
        return this;
    }

    public String getPhoto() {
        return photo;
    }

    public int getId() {
        return id;
    }

    public ArrayList<Integer> getArrFriends() {
        return arrFriends;
    }

    public ArrayList<Integer> getArrLocation() {
        return arrLocation;
    }

    public ArrayList<Integer> getArrMusic() {
        return arrMusic;
    }

    public String getEmail() {
        return email;
    }

    public String getLogin() {
        return login;
    }

    public String getNickname() {
        return nickname;
    }

    public String getPassword() {
        return password;
    }

    public void setPhoto(String photo) {
        this.photo = photo;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setArrFriends(ArrayList<Integer> arrFriends) {
        this.arrFriends = arrFriends;
    }

    public void setArrLocation(ArrayList<Integer> arrLocation) {
        this.arrLocation = arrLocation;
    }

    public void setArrMusic(ArrayList<Integer> arrMusic) {
        this.arrMusic = arrMusic;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public void setLogin(String login) {
        this.login = login;
    }

    public void setNickname(String nickname) {
        this.nickname = nickname;
    }

    public void setPassword(String password) {
        this.password = password;
    }
}
