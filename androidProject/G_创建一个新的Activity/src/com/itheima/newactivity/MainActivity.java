package com.itheima.newactivity;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	}

	//实现拨打电话的功能
	public void click1(View v){
		
		Intent intent = new Intent();
		
		intent.setAction(Intent.ACTION_CALL);
		
		intent.setData(Uri.parse("tel:"+119));
		
		startActivity(intent);
	}
}
