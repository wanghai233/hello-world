package com.hai.rpcalc;

import java.util.jar.Attributes.Name;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.EditText;
import android.widget.RadioGroup;
import android.widget.Toast;
import com.hai.rpcalc.R;

public class MainActivity extends Activity {

	private EditText et_name;
	private RadioGroup rg_group;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	
	
	   et_name = (EditText) findViewById(R.id.et_name);
	   rg_group = (RadioGroup) findViewById(R.id.radioGroup1);
	   
	   
	   
	}

	public void  click(View v) {
		
		String name = et_name.getText().toString().trim();
		if (TextUtils.isEmpty(name)) {
		Toast.makeText(getApplicationContext(), "����������", 1).show();
		return;
		
		}
		int radioButtonId = rg_group.getCheckedRadioButtonId();
		int sex = 0;
		
		
		
		switch (radioButtonId) {
		case R.id.rb_male:
			sex = 1;
			break;
	    case R.id.rb_female:
			sex = 2;
			break;
	   case R.id.rb_other:
			sex = 3;
			break;
		default:
			break;
		}
		if(sex==0){
			
			
		Toast.makeText(getApplicationContext(), "��ѡ���Ա�", 1).show();
		return;	
			
			
		}
		
		
		
		Intent intent = new Intent(this,ResultActivityt.class);
		
		intent.putExtra("name", name);
		
		intent.putExtra("sex", sex);
		
		startActivity(intent);
		
		
		
		
		
		
		
	}
}
