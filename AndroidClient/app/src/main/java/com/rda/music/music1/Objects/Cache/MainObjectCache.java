package com.rda.music.music1.Objects.Cache;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

/**
 * Created by DENIS on 04.12.2016.
 */

public class MainObjectCache {
    private static final String DB_NAME = "MainObjectCache";
    private static final int DB_VERSION = 1;

    private static final String DB_TABLE_USER = "DB_USER";


    private static final String DB_CREATE_TABLE_USER = "create table " + DB_TABLE_USER + "(cacheId integer, id integer, " +
            "login text, password text, nickname text, email text);";

    private final Context context;

    private DBHelper dbHelper;
    private SQLiteDatabase db;
    private Cursor cursor;

    public MainObjectCache(Context context) {
        this.context = context;
    }

    public void open() {
        dbHelper = new DBHelper(context, DB_NAME, null, DB_VERSION);
        db = dbHelper.getWritableDatabase();
    }

    public void close() {
        if (dbHelper != null) dbHelper.close();
    }

    public void addUser(Integer id, String login, String password, String nickname,
                        String email){
        ContentValues cv = new ContentValues();
        cv.put("cacheId", 1);
        cv.put("id", id);
        cv.put("login", login);
        cv.put("password", password);
        cv.put("email", email);
        db.insert(DB_TABLE_USER, null, cv);
    }

    public Cursor getUser(){
       return db.query(DB_TABLE_USER, null, null, null, null, null, null);
    }


    public void updateUser(String login, String password, String nickname){
        ContentValues cv = new ContentValues();
        cv.put("password", password);
        cv.put("login", login);
        db.update(DB_TABLE_USER, cv, "cacheId = ?", new String[]{"1"});
    }


    public void deleteUser(){
        db.delete(DB_TABLE_USER, "cacheId = 1", null);
    }



    private class DBHelper extends SQLiteOpenHelper {
        public DBHelper(Context context, String name, SQLiteDatabase.CursorFactory factory, int version) {
            super(context, name, factory, version);
        }

        @Override
        public void onCreate(SQLiteDatabase db) {
            db.execSQL(DB_CREATE_TABLE_USER);
        }

        @Override
        public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {

        }
    }
}
