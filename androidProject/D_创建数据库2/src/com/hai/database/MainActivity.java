package com.hai.database;

import android.app.Activity;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import com.hai.database.R;

public class MainActivity extends Activity {

	private MyopenHelper myopenHelper;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	
	
	   myopenHelper = new MyopenHelper(getApplicationContext());
	   
	   //SQLiteDatabase sqLiteDatabase = myopenHelper.getWritableDatabase();
	
	   //SQLiteDatabase readableDatabase = myopenHelper.getReadableDatabase();
	
	}
     public void click1(View v){
     SQLiteDatabase db = myopenHelper.getWritableDatabase();
     db.execSQL("insert into glh(name,phone) values(?,?)", new Object[]{"hai","1345188"});	 
     db.close();	 
     }
	
     public void click2(View v){
    SQLiteDatabase db = myopenHelper.getWritableDatabase();	 
     db.execSQL("delete from glh where name=?", new Object[]{"hai"});
     db.close();
     
     }
     public void click3(View v){
 	 SQLiteDatabase db = myopenHelper.getWritableDatabase();
     db.execSQL("update glh set phone=? where name=?", new Object[]{"15454511","hai"} );	 
     db.close();	 
    	 
  }
     public void click4(View v){
     SQLiteDatabase db = myopenHelper.getReadableDatabase();
    Cursor cursor = db.rawQuery("select * from glh", null);	 
    if (cursor!= null&&cursor.getCount()>0) {
		while(cursor.moveToNext()){
		String name = cursor.getString(1);
		String phone = cursor.getString(1);
		System.out.println("name:"+name+"---"+phone);
		}
	}	 
    	 
    	 
  }
}
