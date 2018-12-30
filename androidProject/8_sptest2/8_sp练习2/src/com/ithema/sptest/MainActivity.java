
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
		
		
		//0�ȳ�ʼ��sp��ʵ��
		/*
		 * name�������������һ��xml�ļ�
		 * modeģʽ
		 */
		sp = getSharedPreferences("config", 0);
		
		//1.�ҵ����ǹ��ĵĿؼ�
		et_name = (EditText) findViewById(R.id.et_username);
		et_userpassword = (EditText) findViewById(R.id.et_userpassword);
		cb_ischeck = (CheckBox) findViewById(R.id.cb_ischeck);
		
		//2.��config.xml�а����ǹ��ĵ�����ȡ��������ʾ��edittext�ؼ���
		String name = sp.getString("name", "");
		String pwd = sp.getString("pwd", "");
		
		//3.��name��pwd���õ�edittext��
		et_name.setText(name);
		et_userpassword.setText(pwd);
		
		
		//TODO С��ҵ
		//��checkbox״̬�߼�д��
	
	}


	
	public void Login(View v) {
		String name = et_name.getText().toString().trim();
		String pwd = et_userpassword.getText().toString().trim();
		//2.2�ж�name��pwd�Ƿ�Ϊ��
		if (TextUtils.isEmpty(name) || TextUtils.isEmpty(pwd)) {
			Toast.makeText(MainActivity.this, "�û��������벻��Ϊ��", 1).show();
		} else {
			//2.3���е�½���߼�
			java.lang.System.out.println("���ӷ����� ���е�½ ������ ����");
			
			if(cb_ischeck.isChecked()){
				//2.4ʹ��sharedpreferenceȥ��������
				
				
				//2.5��ȡ�༭��
				Editor edit = sp.edit();
				edit.putString("name", name);
				edit.putString("pwd", pwd);
				
				//2.6�ύedit
				edit.commit();

			}
			else{
				Toast.makeText(MainActivity.this, "û�м�ס�û���������", 1).show();
			}
		}
	}
}
