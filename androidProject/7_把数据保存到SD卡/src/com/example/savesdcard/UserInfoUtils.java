package com.example.savesdcard;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class UserInfoUtils {
	
	//保存用户名和密码的业务方法
	public static boolean saveInfo(String username,String pwd){
		
		try {
			String result = username + "##"+pwd;
			//1.创建file类，指定我们要把数据存储的位置
			File file = new File("/mnt/sdcard/info.txt");
			//2.创建一个文件输出流
			FileOutputStream fos = new FileOutputStream(file);		
			fos.write(result.getBytes());
			fos.close();
			return true;
			
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return false;
		}
		
		

	}

	//读取用户信息
	public static Map<String, String> readInfo() {
		// TODO Auto-generated method stub
		//定义map
		try {
			Map<String, String> maps = new HashMap<String, String>();
			File file = new File("/data/data/com.example.login/info.txt");
			FileInputStream fis = new FileInputStream(file);
			BufferedReader bufr = new BufferedReader(new InputStreamReader(fis));
			String content = bufr.readLine();//读取数据
			
			//切割字符串 封装到map集合中
			String[] splits = content.split("##");
			String name = splits[0];
			String pwd = splits[1];
			//把name和pwd放入map中
			maps.put("name",name);
			maps.put("pwd",pwd);
			fis.close();
			return maps;
			
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return null;
		}		
	}
}
