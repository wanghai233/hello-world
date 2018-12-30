
package com.ithema.sptest;

import java.util.Map;

import android.app.Activity;
import android.content.SharedPreferences;
import android.content.SharedPreferences.Editor;
import android.os.Bundle;
import android.provider.Settings.System;
import android.text.TextUtils;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.Toast;
import com.ithema.sptest.R;

public class MainActivity extends Activity {

	private EditText et_name;
	private EditText et_userpassword;
	private CheckBox cb_ischeck;
	private SharedPreferences sp;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		setContentView(R.layout.activity_main);
		
		
		//0先初始化sp的实例
		/*
		 * name会帮助我们生成一个xml文件
		 * mode模式
		 */
		sp = getSharedPreferences("config", 0);
		
		//1.找到我们关心的控件
		et_name = (EditText) findViewById(R.id.et_username);
		et_userpassword = (EditText) findViewById(R.id.et_userpassword);
		cb_ischeck = (CheckBox) findViewById(R.id.cb_ischeck);
		
		//2.在config.xml中把我们关心的数据取出来，显示到edittext控件上
		String name = sp.getString("name", "");
		String pwd = sp.getString("pwd", "");
		
		//3.把name和pwd设置到edittext上
		et_name.setText(name);
		et_userpassword.setText(pwd);
		
		
		//TODO 小作业
		//把checkbox状态逻辑写好
	
	}


	
	public void Login(View v) {
		String name = et_name.getText().toString().trim();
		String pwd = et_userpassword.getText().toString().trim();
		//2.2判断name和pwd是否为空
		if (TextUtils.isEmpty(name) || TextUtils.isEmpty(pwd)) {
			Toast.makeText(MainActivity.this, "用户名和密码不能为空", 1).show();
		} else {
			//2.3进行登陆的逻辑
			java.lang.System.out.println("连接服务器 进行登陆 第四天 网络");
			
			if(cb_ischeck.isChecked()){
				//2.4使用sharedpreference去保存数据
				
				
				//2.5获取编辑器
				Editor edit = sp.edit();
				edit.putString("name", name);
				edit.putString("pwd", pwd);
				
				//2.6提交edit
				edit.commit();

			}
			else{
				Toast.makeText(MainActivity.this, "没有记住用户名和密码", 1).show();
			}
		}
	}
}
