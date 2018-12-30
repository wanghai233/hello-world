package com.hai.sqlite5;

import java.util.ArrayList;
import java.util.List;

import android.app.Activity;
import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.provider.Contacts.Intents.Insert;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import com.hai.sqlite5.R;

public class MainActivity extends Activity {

	private MyopenHelper myopenHelper;
	private List<Person> lists;
	private ListView lv;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	    lv = (ListView) findViewById(R.id.lv);
	 
	   myopenHelper = new MyopenHelper(getApplicationContext());	   
	
	   lists = new ArrayList<Person>();
	
	
	}
     public void click1(View v){
     SQLiteDatabase db = myopenHelper.getWritableDatabase();
     ContentValues values = new ContentValues();
     values.put("name","王五");
     values.put("phone", "110");
     long insert = db.insert("glh", null, values);
     db.close();
     if (insert>0) {
		Toast.makeText(getApplicationContext(), "添加成功", 1).show();	
	}else {
		Toast.makeText(getApplicationContext(), "添加失败", 1).show();
	}
     
     	 
    }
	
     public void click2(View v){
    SQLiteDatabase db = myopenHelper.getWritableDatabase();	 
    int delete = db.delete("glh", "name=?", new String[]{"王五"});
    db.close();
    Toast.makeText(getApplicationContext(), "删除了"+delete+"行", 0).show();
     }
    
     
     public void click3(View v){
 	 SQLiteDatabase db = myopenHelper.getWritableDatabase();
 	 ContentValues values = new ContentValues();
 	 values.put("phone", "114");
 	 int update = db.update("glh", values, "name=?", new String[]{"王五"});	 
     db.close();  
     Toast.makeText(getApplicationContext(), "更新了"+update, 0).show();
     
     }
     
     
     
     public void click4(View v){
     SQLiteDatabase db = myopenHelper.getReadableDatabase();
    
     Cursor cursor = db.query("glh", null, null, null, null, null, null);
     if (cursor!= null&&cursor.getCount()>0) 
     {
     while(cursor.moveToNext()){
     String name = cursor.getString(1);
     String phone = cursor.getString(2);
     
	 Person person = new Person();	 
	 person.setName(name);	
	 person.setPhone(phone);	
		
     lists.add(person);
     
     }
	
     lv.setAdapter(new MyAdapter());
     
     
     }	 
    	 
    	 
  }
     
    private class MyAdapter extends BaseAdapter{

		@Override
		public int getCount() {
			// TODO Auto-generated method stub
			return lists.size();
		}

		@Override
		public Object getItem(int position) {
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public long getItemId(int position) {
			// TODO Auto-generated method stub
			return 0;
		}

		@Override
		public View getView(int position, View convertView, ViewGroup parent) {
			// TODO Auto-generated method stub
			View view;
			
			if (convertView ==null) {
			
				view = View.inflate(getApplicationContext(), R.layout.item, null);	
				
			}else{
				view = convertView;
			}
			
			TextView tv_name = (TextView) view.findViewById(R.id.tv_name);
			TextView tv_phone = (TextView) view.findViewById(R.id.tv_phone);
			
			Person person = lists.get(position);
			tv_name.setText(person.getName());
			tv_phone.setText(person.getPhone());
			
			return view;
		}
    	
    }
     
     
}
