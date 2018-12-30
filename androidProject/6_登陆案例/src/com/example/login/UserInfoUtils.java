package com.example.login;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

public class UserInfoUtils {
	
	//保存用户名和密码的业务方法
	public static boolean saveInfo(String username,String pwd){
		
		try {
			String result = username + "##"+pwd;
			//1.创建file类，指定我们要把数据存储的位置
			File file = new File("/data/data/com.example.login/info.txt");
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

}
