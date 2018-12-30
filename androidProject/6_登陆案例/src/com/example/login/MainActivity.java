package com.example.login;

import org.w3c.dom.Text;

import android.R.string;
import android.app.Activity;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.CheckBox;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity {

	private EditText et_name;
	private EditText et_userpassword;
	private CheckBox cb_iCheckBox;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		//1.找到我们关心的控件
		et_name = (EditText) findViewById(R.id.et_username);
		et_userpassword = (EditText) findViewById(R.id.et_userpassword);
		cb_iCheckBox = (CheckBox) findViewById(R.id.cb_ischeck);
	}

	
	//2.写按钮事件
	public void login(View v){
		
		//获取用户名和密码
		String name = et_name.getText().toString().trim();
		String pwd = et_userpassword.getText().toString().trim();
		//判断name和pwd是否为空
		if(TextUtils.isEmpty(name)||TextUtils.isEmpty(pwd)){
			Toast.makeText(MainActivity.this, "用户名或密码不能为空", 1).show();
		}
		else{
			System.out.println("连接服务器 进行登陆 等到网络编程再做");
			
			if(cb_iCheckBox.isChecked()){
				//把用户名和密码的数据存起来
				boolean result = UserInfoUtils.saveInfo(name, pwd);
				if(result){
					Toast.makeText(MainActivity.this, "保存成功", 1).show();
				}
				else{
					Toast.makeText(MainActivity.this, "保存失败", 1).show();
				}
			}
			else{
				Toast.makeText(MainActivity.this, "请勾选cb", 1).show();
			}
		}
		
	}
	
	
	
	
	
	
	
	
	
	private boolean cb_iCheckBox() {
		// TODO Auto-generated method stub
		return false;
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
}
