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
			//2.把sms对象加入集合中
			smsLists.add(sms);
		}
	}

	//点击按钮，通过StringBuffer的方式生成一个xml文件
	public void click(View v){
		
		//1.创建sb对象
		StringBuffer sb = new StringBuffer();
		
		//2.组拼xml文件头
		sb.append("<?xml version=\"1.0\" encoding=\"utf-8\"?>");
		
		//3.组拼xml根节点
		sb.append("<smss>");
		
		//4.组拼sms节点
		for (Sms sms : smsLists) {
			
			sb.append("<sms>");
			
			//5.组拼address节点
			sb.append("<address>");
			sb.append(sms.getAddress());
			sb.append("</address>");
			
			//6.组拼boby节点
			sb.append("<body>");
			sb.append(sms.getBody());
			sb.append("</body>");
			
			//7.组拼date节点
			sb.append("<data>");
			sb.append(sms.getData());
			sb.append("</data>");
			
			sb.append("</sms>");
			
		}
		sb.append("</sms>");
		
		//8.把数据放到SD卡中
		try {
			File file = new File(Environment.getExternalStorageDirectory().getPath(),"smsbackup.xml");
			FileOutputStream fos = new FileOutputStream(file);
			fos.write(sb.toString().getBytes());
			fos.close();//关闭流
			
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
