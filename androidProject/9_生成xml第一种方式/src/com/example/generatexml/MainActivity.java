package com.example.generatexml;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.ArrayList;
import java.util.List;

import android.app.Activity;
import android.os.Bundle;
import android.os.Environment;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

public class MainActivity extends Activity {

	private List<Sms> smsLists;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		
		smsLists = new ArrayList<Sms>();
		for(int i = 0;i <10; i++){
			
			Sms sms = new Sms();
			sms.setAddress("10086"+i);
			sms.setBody("hello"+i);
			sms.setData("201"+i);
			//2.��sms������뼯����
			smsLists.add(sms);
		}
	}

	//�����ť��ͨ��StringBuffer�ķ�ʽ����һ��xml�ļ�
	public void click(View v){
		
		//1.����sb����
		StringBuffer sb = new StringBuffer();
		
		//2.��ƴxml�ļ�ͷ
		sb.append("<?xml version=\"1.0\" encoding=\"utf-8\"?>");
		
		//3.��ƴxml���ڵ�
		sb.append("<smss>");
		
		//4.��ƴsms�ڵ�
		for (Sms sms : smsLists) {
			
			sb.append("<sms>");
			
			//5.��ƴaddress�ڵ�
			sb.append("<address>");
			sb.append(sms.getAddress());
			sb.append("</address>");
			
			//6.��ƴboby�ڵ�
			sb.append("<body>");
			sb.append(sms.getBody());
			sb.append("</body>");
			
			//7.��ƴdate�ڵ�
			sb.append("<data>");
			sb.append(sms.getData());
			sb.append("</data>");
			
			sb.append("</sms>");
			
		}
		sb.append("</sms>");
		
		//8.�����ݷŵ�SD����
		try {
			File file = new File(Environment.getExternalStorageDirectory().getPath(),"smsbackup.xml");
			FileOutputStream fos = new FileOutputStream(file);
			fos.write(sb.toString().getBytes());
			fos.close();//�ر���
			
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
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
}
