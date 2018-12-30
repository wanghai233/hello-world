package com.example.click4;

import com.example.click4.R;

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

public class MainActivity extends Activity implements OnClickListener {

	private EditText et_number;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		// ����һ������
		setContentView(R.layout.activity_main);
		Button btn_call2 = (Button) findViewById(R.id.button2);
		Button btn_call3 = (Button) findViewById(R.id.button3);
		Button btn_call4 = (Button) findViewById(R.id.button4);

		// �ҵ����ǹ��ĵĿؼ�
		et_number = (EditText) findViewById(R.id.editText1);

		// 2.�ҵ���ť
		Button btn_call = (Button) findViewById(R.id.button1);

		// 3.���������õ���¼�
		// ������ť�ĵ����ֵ���¼�
		btn_call.setOnClickListener(this);
		btn_call2.setOnClickListener(this);
		btn_call3.setOnClickListener(this);
		btn_call4.setOnClickListener(this);

	}
	
	//������ť�ĵ����ֵ���¼� ����һ������ ��������Ҫ����������ť�ڲ�����������onclick����һ��
	
	public void click(View v){
		
		//����绰
		callPhone();
	}

	private void callPhone() {
		// 4.��ȡedittext�ı�����
		String number = et_number.getText().toString().trim();
		if ("".equals(number)) {
			/*
			 * context ������
			 */
			Toast.makeText(MainActivity.this, "number����Ϊ��", Toast.LENGTH_LONG)
					.show();
			return;
		}

		// System.out.println("��ť�������"+number);
		// [5]���в���绰 ��ͼIntent
		Intent intent = new Intent();// ����һ����ͼ���� �� è�� ���� �绰
		// [5.1]���ö���
		intent.setAction(Intent.ACTION_CALL);
		// [5.2]����Ҫ��������� uri
		/**
		 * uri:ͳһ��Դ��ʶ�� ��ʲô�ʹ���ʲô�����·�� �����˵�� url:ͳһ��Դ��λ�� www.baidu.com
		 */
		intent.setData(Uri.parse("tel:" + number));

		// 6.������ͼ
		startActivity(intent);
	}

	// �����c�����o�r����
	@Override
	public void onClick(View v) {
		// TODO Auto-generated method stub
		// �жϵ�������ĸ���ť
		switch (v.getId()) {
		case R.id.button1:// �������˵�һ����ť

			callPhone();
			break;

		case R.id.button2:// �������˵�һ����ť

			callPhone();
			break;
		case R.id.button3:// �������˵�һ����ť

			callPhone();
			break;
		case R.id.button4:// �������˵�һ����ť

			callPhone();
			break;

		default:
			break;
		}

	}

}
