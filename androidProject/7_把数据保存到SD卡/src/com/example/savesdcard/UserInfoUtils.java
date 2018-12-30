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
	
	//�����û����������ҵ�񷽷�
	public static boolean saveInfo(String username,String pwd){
		
		try {
			String result = username + "##"+pwd;
			//1.����file�ָ࣬������Ҫ�����ݴ洢��λ��
			File file = new File("/mnt/sdcard/info.txt");
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

	//��ȡ�û���Ϣ
	public static Map<String, String> readInfo() {
		// TODO Auto-generated method stub
		//����map
		try {
			Map<String, String> maps = new HashMap<String, String>();
			File file = new File("/data/data/com.example.login/info.txt");
			FileInputStream fis = new FileInputStream(file);
			BufferedReader bufr = new BufferedReader(new InputStreamReader(fis));
			String content = bufr.readLine();//��ȡ����
			
			//�и��ַ��� ��װ��map������
			String[] splits = content.split("##");
			String name = splits[0];
			String pwd = splits[1];
			//��name��pwd����map��
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
