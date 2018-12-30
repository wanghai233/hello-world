package com.example.sqlite;

import java.sql.ResultSet;

import android.content.Context;
import android.database.DatabaseErrorHandler;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteDatabase.CursorFactory;
import android.database.sqlite.SQLiteOpenHelper;

public class MyOpenHelper extends SQLiteOpenHelper {

	/*
	 * context 上下文
	 * name 数据库的名字
	 * factory 目的创建cursor对象
	 * version 数据库的版本
	 */
	public MyOpenHelper(Context context) {
		super(context, "itheima.db", null, 3);
		// TODO Auto-generated constructor stub
	}

	/*
	 * (non-Javadoc)
	 * @see android.database.sqlite.SQLiteOpenHelper#onCreate(android.database.sqlite.SQLiteDatabase)
	 * 当数据库第一次被创建时调用
	 * 这个方法特别适合做表结构的初始化，创建表就是写sql语句
	 * 
	 */
	@Override
	public void onCreate(SQLiteDatabase db) {
		// TODO Auto-generated method stub
		//id一般以下划线开头 _id
		db.execSQL("create table info(_id integer primary key autoincrement,name varchar(20))");
		
		

	}

	/*
	 * (non-Javadoc)
	 * @see android.database.sqlite.SQLiteOpenHelper#onUpgrade(android.database.sqlite.SQLiteDatabase, int, int)
	 * 当数据库升级的时候调用
	 * 这个方法适合做 表结构的更新
	 */
	@Override
	public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
		// TODO Auto-generated method stub
		//System.out.println("啊哈哈哈哈哈");
		db.execSQL("alter table info add phone varchar(20)");
		

	}

}
