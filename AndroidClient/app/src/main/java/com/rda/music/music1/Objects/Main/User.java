package com.rda.music.music1.Objects.Main;

import android.content.Context;
import android.database.Cursor;

import com.rda.music.music1.Objects.Cache.MainObjectCache;
import com.rda.music.music1.Objects.ObjUser;

/**
 * Created by DENIS on 04.12.2016.
 */

public class User {
    private static User instance;

    private ObjUser user;

    public User() {
        user = new ObjUser();
    }

    public void setUserFromCache(Context context) {
        MainObjectCache mainObjectsCache = new MainObjectCache(context);
        mainObjectsCache.open();

        Cursor cursor = mainObjectsCache.getUser();
        if (cursor != null) {
            if (cursor.moveToFirst()) {
                int idColumnIndex = cursor.getColumnIndex("id");
                int loginColumnIndex = cursor.getColumnIndex("login");
                int passwordColumnIndex = cursor.getColumnIndex("password");
                int nicknameColumnIndex = cursor.getColumnIndex("nickname");
                int emailColumnIndex = cursor.getColumnIndex("email");

                user.setId(cursor.getInt(idColumnIndex));
                user.setLogin(cursor.getString(loginColumnIndex));
                user.setPassword(cursor.getString(passwordColumnIndex));
                user.setNickname(cursor.getString(nicknameColumnIndex));
                user.setEmail(cursor.getString(emailColumnIndex));
            }
        }
        mainObjectsCache.close();
    }

    public User(ObjUser objUser) {
        user = objUser;
    }

    public void SetUser(ObjUser objUser) {
        user = objUser;
    }

    public ObjUser GetUser() {
        return user;
    }

    public static synchronized User getInstance() {
        if (instance == null) {
            instance = new User();
        }
        return instance;
    }

    public void clear(){
        instance = null;
    }
}
