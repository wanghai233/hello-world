package com.example.sqlite;

import android.app.Activity;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

public class MainActivity extends Activity {

	private MyOpenHelper myOpenHelper;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		myOpenHelper = new MyOpenHelper(getApplicationContext());

//		// 打开或者创建数据库，如果是第一次就是创建
//		SQLiteDatabase sqLiteDatabase = myOpenHelper.getWritableDatabase();
//
//		// 打开或者创建数据库，如果是第一次就是创建，如果磁盘满了，返回只读的
//		SQLiteDatabase readableDatabase = myOpenHelper.getReadableDatabase();
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		// Handle action bar item clicks here. The action bar will
		// automatically handle clicks on the Home/Up button, so long
		// as you specify a parent activity in AndroidManifest.xml.
		int id = item.getItemId();
		if (id == R.id.action_settings) {
			return true;
		}
		return super.onOptionsItemSelected(item);
	}

	//添加数据
	public void click1(View v) {
		//获取数据库对象
		SQLiteDatabase db = myOpenHelper.getWritableDatabase();
		//执行一条sql语句
		db.execSQL("inser into info(name phone) value(?,?);", new Object[]{"张三","1388"});

	}

	public void click2(View v) {

	}

	public void click3(View v) {

	}

	public void click4(View v) {

	}
}
