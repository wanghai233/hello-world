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
		
		//1.�ҵ����ǹ��ĵĿؼ�
		ListView lv = (ListView) findViewById(R.id.lv);
		
		//2.��ʾ���� ����������ͨ�ؼ���textview���е�����
		lv.setAdapter(new MyListAdapter());
		
		
		
	}

	//3.����listview����������
	private class MyListAdapter extends BaseAdapter{

		//һ���ж�����������Ҫչʾ
		@Override
		public int getCount() {
			// TODO Auto-generated method stub
			
			return 1000000;
		}

		//����ָ��positionλ�ö�Ӧ�Ķ���
		@Override
		public Object getItem(int position) {
			// TODO Auto-generated method stub
			return null;
		}

		//����positionλ�ö�Ӧ��id
		@Override
		public long getItemId(int position) {
			// TODO Auto-generated method stub
			return 0;
		}

		
		/*
		 * ��ȡһ��view��������ʾlistview�����ݣ���Ϊlistview��һ����Ŀ����
		 * converview��ʷ�������
		 * (non-Javadoc)
		 * @see android.widget.Adapter#getView(int, android.view.View, android.view.ViewGroup)
		 */
		@Override
		public View getView(int position, View convertView, ViewGroup parent) {
			// TODO Auto-generated method stub
			
			TextView tv;
			if (convertView ==null){
				tv = new TextView(MainActivity.this);
				System.out.println("�����µ�view����---"+position);
			}
			else{
				System.out.println("������ʷ�������---"+position);
				tv = (TextView) convertView;
				
			}
			
			//System.out.println("getView---"+position);
			
			tv.setText("��������������"+position);
			
			return tv;
		}

		
		
	}
}
