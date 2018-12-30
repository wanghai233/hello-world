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
		// 加载一个布局
		setContentView(R.layout.activity_main);
		Button btn_call2 = (Button) findViewById(R.id.button2);
		Button btn_call3 = (Button) findViewById(R.id.button3);
		Button btn_call4 = (Button) findViewById(R.id.button4);

		// 找到我们关心的控件
		et_number = (EditText) findViewById(R.id.editText1);

		// 2.找到按钮
		Button btn_call = (Button) findViewById(R.id.button1);

		// 3.给按键设置点击事件
		// ☆☆☆☆☆☆按钮的第三种点击事件
		btn_call.setOnClickListener(this);
		btn_call2.setOnClickListener(this);
		btn_call3.setOnClickListener(this);
		btn_call4.setOnClickListener(this);

	}
	
	//☆☆☆☆☆☆按钮的第四种点击事件 声明一个方法 方法名和要点击的这个按钮在布局中声明的onclick属性一样
	
	public void click(View v){
		
		//拨打电话
		callPhone();
	}

	private void callPhone() {
		// 4.获取edittext文本内容
		String number = et_number.getText().toString().trim();
		if ("".equals(number)) {
			/*
			 * context 上下文
			 */
			Toast.makeText(MainActivity.this, "number不能为空", Toast.LENGTH_LONG)
					.show();
			return;
		}

		// System.out.println("按钮被点击了"+number);
		// [5]进行拨打电话 意图Intent
		Intent intent = new Intent();// 创建一个意图对象 打 猫狗 代码 电话
		// [5.1]设置动作
		intent.setAction(Intent.ACTION_CALL);
		// [5.2]设置要拨打的数据 uri
		/**
		 * uri:统一资源标识符 自什么就代表什么定义的路径 想代表说明 url:统一资源定位符 www.baidu.com
		 */
		intent.setData(Uri.parse("tel:" + number));

		// 6.开启意图
		startActivity(intent);
	}

	// 當我點擊按鈕時執行
	@Override
	public void onClick(View v) {
		// TODO Auto-generated method stub
		// 判断点击的是哪个按钮
		switch (v.getId()) {
		case R.id.button1:// 代表点击了第一个按钮

			callPhone();
			break;

		case R.id.button2:// 代表点击了第一个按钮

			callPhone();
			break;
		case R.id.button3:// 代表点击了第一个按钮

			callPhone();
			break;
		case R.id.button4:// 代表点击了第一个按钮

			callPhone();
			break;

		default:
			break;
		}

	}

}
