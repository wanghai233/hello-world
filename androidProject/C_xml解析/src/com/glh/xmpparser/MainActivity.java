package com.glh.xmpparser;

import java.io.IOException;
import java.io.InputStream;
import java.util.List;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends Activity {



	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		try {
			TextView tv_weather = (TextView) findViewById(R.id.tv_weather);
			InputStream inputStream = getAssets().open("weather.xml");
			List<Channel> weatherLists = weatherParser.parserXml(inputStream);
			StringBuffer sb = new StringBuffer();
			for (Channel channel : weatherLists){
				sb.append(channel.toString());
			}
			tv_weather.setText(sb.toString());
			
		} catch (Exception e) {
			e.printStackTrace();
		} 
	}

}
