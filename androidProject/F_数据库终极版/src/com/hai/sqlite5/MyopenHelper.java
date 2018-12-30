package com.hai.sqlite5;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class MyopenHelper extends SQLiteOpenHelper {

	public MyopenHelper(Context context) {
		super(context, "hai.db", null,3);

	}

	@Override
	public void onCreate(SQLiteDatabase db) {


	db.execSQL("create table glh(_id integer primary key autoincrement,name varchar(20),phone varchar(20))");	
		
		
	}

	@Override
	public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {

    db.execSQL("alter table glh add phone varchar(20)");	
	}

}
