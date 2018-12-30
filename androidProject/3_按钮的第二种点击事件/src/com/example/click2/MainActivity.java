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
		//加载一个布局
		setContentView(R.layout.activity_main);
		et_number = (EditText) findViewById(R.id.editText1);
		
		//2.找到按钮
		Button btn_call  = (Button) findViewById(R.id.button1);
		
		//3.给按键设置点击事件
		//☆☆☆☆☆☆按钮的第二种点击事件   匿名内部类
		btn_call.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				//实现拨打电话的逻辑
				callPhone();
			}
		});
		
		//Toast.makeText(this, text, duration);
	}
	
	private void callPhone() {
		//4.获取edittext文本内容
		String number = et_number.getText().toString().trim();
		if("".equals(number)){
			/*
			 * context 上下文
			 */
			Toast.makeText(MainActivity.this, "number不能为空", Toast.LENGTH_LONG).show();
			return;
		}
		
		//System.out.println("按钮被点击了"+number);
		//[5]进行拨打电话 意图Intent
		Intent intent = new Intent();//创建一个意图对象 打 猫狗 代码 电话
		//[5.1]设置动作
		intent.setAction(Intent.ACTION_CALL);
		//[5.2]设置要拨打的数据 uri
		/**
		 * uri:统一资源标识符 自什么就代表什么定义的路径 想代表说明
		 * url:统一资源定位符 www.baidu.com
		 */
		intent.setData(Uri.parse("tel:"+number));

		//6.开启意图
		startActivity(intent);
	}
	
/*	//定义一个类去实现按钮需要的接口类型
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
