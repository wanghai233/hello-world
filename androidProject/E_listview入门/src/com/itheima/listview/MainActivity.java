package com.itheima.listview;

import android.app.Activity;
import android.database.DataSetObserver;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.TextView;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		//1.找到我们关心的控件
		ListView lv = (ListView) findViewById(R.id.lv);
		
		//2.显示数据 和其他的普通控件（textview）有点区别
		lv.setAdapter(new MyListAdapter());
		
		
		
	}

	//3.定义listview数据适配器
	private class MyListAdapter extends BaseAdapter{

		//一共有多少条数据需要展示
		@Override
		public int getCount() {
			// TODO Auto-generated method stub
			
			return 1000000;
		}

		//返回指定position位置对应的对象
		@Override
		public Object getItem(int position) {
			// TODO Auto-generated method stub
			return null;
		}

		//返回position位置对应的id
		@Override
		public long getItemId(int position) {
			// TODO Auto-generated method stub
			return 0;
		}

		
		/*
		 * 获取一个view，用来显示listview的数据，作为listview的一个条目出现
		 * converview历史缓存对象
		 * (non-Javadoc)
		 * @see android.widget.Adapter#getView(int, android.view.View, android.view.ViewGroup)
		 */
		@Override
		public View getView(int position, View convertView, ViewGroup parent) {
			// TODO Auto-generated method stub
			
			TextView tv;
			if (convertView ==null){
				tv = new TextView(MainActivity.this);
				System.out.println("创建新的view对象---"+position);
			}
			else{
				System.out.println("复用历史缓存对象---"+position);
				tv = (TextView) convertView;
				
			}
			
			//System.out.println("getView---"+position);
			
			tv.setText("哈哈啊哈哈哈哈"+position);
			
			return tv;
		}

		
		
	}
}
