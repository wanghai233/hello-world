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

//		// �򿪻��ߴ������ݿ⣬����ǵ�һ�ξ��Ǵ���
//		SQLiteDatabase sqLiteDatabase = myOpenHelper.getWritableDatabase();
//
//		// �򿪻��ߴ������ݿ⣬����ǵ�һ�ξ��Ǵ���������������ˣ�����ֻ����
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

	//�������
	public void click1(View v) {
		//��ȡ���ݿ����
		SQLiteDatabase db = myOpenHelper.getWritableDatabase();
		//ִ��һ��sql���
		db.execSQL("inser into info(name phone) value(?,?);", new Object[]{"����","1388"});

	}

	public void click2(View v) {

	}

	public void click3(View v) {

	}

	public void click4(View v) {

	}
}
