package com.itheima.newactivity;

import android.app.Activity;
import android.os.Bundle;

public class TestActivity extends Activity{
	
	//当Activity启动
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		// TODO Auto-generated method stub
		super.onCreate(savedInstanceState);
		
		//1.加载布局
		setContentView(R.layout.activity_test);
		
		
	}

}
