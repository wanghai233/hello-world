package com.example.sqlite;

import java.sql.ResultSet;

import android.content.Context;
import android.database.DatabaseErrorHandler;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteDatabase.CursorFactory;
import android.database.sqlite.SQLiteOpenHelper;

public class MyOpenHelper extends SQLiteOpenHelper {

	/*
	 * context ������
	 * name ���ݿ������
	 * factory Ŀ�Ĵ���cursor����
	 * version ���ݿ�İ汾
	 */
	public MyOpenHelper(Context context) {
		super(context, "itheima.db", null, 3);
		// TODO Auto-generated constructor stub
	}

	/*
	 * (non-Javadoc)
	 * @see android.database.sqlite.SQLiteOpenHelper#onCreate(android.database.sqlite.SQLiteDatabase)
	 * �����ݿ��һ�α�����ʱ����
	 * ��������ر��ʺ�����ṹ�ĳ�ʼ�������������дsql���
	 * 
	 */
	@Override
	public void onCreate(SQLiteDatabase db) {
		// TODO Auto-generated method stub
		//idһ�����»��߿�ͷ _id
		db.execSQL("create table info(_id integer primary key autoincrement,name varchar(20))");
		
		

	}

	/*
	 * (non-Javadoc)
	 * @see android.database.sqlite.SQLiteOpenHelper#onUpgrade(android.database.sqlite.SQLiteDatabase, int, int)
	 * �����ݿ�������ʱ�����
	 * ��������ʺ��� ��ṹ�ĸ���
	 */
	@Override
	public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
		// TODO Auto-generated method stub
		//System.out.println("������������");
		db.execSQL("alter table info add phone varchar(20)");
		

	}

}
