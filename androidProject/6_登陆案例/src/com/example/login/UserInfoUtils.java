package com.example.login;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

public class UserInfoUtils {
	
	//�����û����������ҵ�񷽷�
	public static boolean saveInfo(String username,String pwd){
		
		try {
			String result = username + "##"+pwd;
			//1.����file�ָ࣬������Ҫ�����ݴ洢��λ��
			File file = new File("/data/data/com.example.login/info.txt");
			//2.����һ���ļ������
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
