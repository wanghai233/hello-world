package com.example.click2;

import com.example.click2.R;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends Activity {

	private EditText et_number;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		//����һ������
		setContentView(R.layout.activity_main);
		et_number = (EditText) findViewById(R.id.editText1);
		
		//2.�ҵ���ť
		Button btn_call  = (Button) findViewById(R.id.button1);
		
		//3.���������õ���¼�
		//������ť�ĵڶ��ֵ���¼�   �����ڲ���
		btn_call.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				//ʵ�ֲ���绰���߼�
				callPhone();
			}
		});
		
		//Toast.makeText(this, text, duration);
	}
	
	private void callPhone() {
		//4.��ȡedittext�ı�����
		String number = et_number.getText().toString().trim();
		if("".equals(number)){
			/*
			 * context ������
			 */
			Toast.makeText(MainActivity.this, "number����Ϊ��", Toast.LENGTH_LONG).show();
			return;
		}
		
		//System.out.println("��ť�������"+number);
		//[5]���в���绰 ��ͼIntent
		Intent intent = new Intent();//����һ����ͼ���� �� è�� ���� �绰
		//[5.1]���ö���
		intent.setAction(Intent.ACTION_CALL);
		//[5.2]����Ҫ��������� uri
		/**
		 * uri:ͳһ��Դ��ʶ�� ��ʲô�ʹ���ʲô�����·�� �����˵��
		 * url:ͳһ��Դ��λ�� www.baidu.com
		 */
		intent.setData(Uri.parse("tel:"+number));

		//6.������ͼ
		startActivity(intent);
	}
	
/*	//����һ����ȥʵ�ְ�ť��Ҫ�Ľӿ�����
	private class MyClickListener implements OnClickListener{
		
		public void onClick(View v){
			callPhone();
		}

		
		
	}*/

//	@Override
//	public boolean onCreateOptionsMenu(Menu menu) {
//		// Inflate the menu; this adds items to the action bar if it is present.
//		getMenuInflater().inflate(R.menu.main, menu);
//		return true;
//	}
//
//	@Override
//	public boolean onOptionsItemSelected(MenuItem item) {
//		// Handle action bar item clicks here. The action bar will
//		// automatically handle clicks on the Home/Up button, so long
//		// as you specify a parent activity in AndroidManifest.xml.
//		int id = item.getItemId();
//		if (id == R.id.action_settings) {
//			return true;
//		}
//		return super.onOptionsItemSelected(item);
//	}
}
