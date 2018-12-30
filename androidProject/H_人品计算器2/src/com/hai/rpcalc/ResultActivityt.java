package com.hai.rpcalc;

import java.io.UnsupportedEncodingException;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import com.hai.rpcalc.R;

public class ResultActivityt extends Activity {

	
	@Override
	protected void onCreate(Bundle savedInstanceState) {

		super.onCreate(savedInstanceState);
		
		setContentView(R.layout.activity_result);
		
		TextView tv_name = (TextView) findViewById(R.id.tv_name);
		TextView tv_sex = (TextView) findViewById(R.id.tv_sex);
		TextView tv_result = (TextView) findViewById(R.id.tv_result);
		
		Intent intent = getIntent();
		
		 String name = intent.getStringExtra("name");
		 int sex = intent.getIntExtra("sex", 0);
		 
		tv_name.setText(name);
		byte[]bytes = null;
		try {
			switch (sex) {
			case 1:
				
				tv_sex.setText("男");
				 bytes = name.getBytes("gbk");
				break;
			case 2:
				tv_sex.setText("女");
				 bytes = name.getBytes("utf-8");
				break;
			case 3:
				tv_sex.setText("人妖");
				 bytes = name.getBytes("iso-8859-1");
			    break;

			default:
				break;
			}
		} catch (UnsupportedEncodingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	
	int total = 0;	
	for (byte b : bytes) {
		
	int number =	b&0xff;
	total+=number;	
		
	}
	int score = Math.abs(total)%100;
	if (score>90) {
		tv_result.setText("您的人品非常好");
	} else if (score > 80) {
		tv_result.setText("您的人品还可以");
		
	}else if (score>60) {
		tv_result.setText("您的人品刚及格");
		
	}else{
		tv_result.setText("您的人品太次了 ");
	}
		
	}
	
	
	
	
}
