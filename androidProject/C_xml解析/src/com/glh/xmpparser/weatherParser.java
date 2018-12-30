package com.glh.xmpparser;

import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

import org.xmlpull.v1.XmlPullParser;

import android.util.Xml;

public class weatherParser {
	public static List<Channel> parserXml(InputStream in) throws Exception{
		List<Channel> weatherLists =null;
		Channel channel = null;
		XmlPullParser parser = Xml.newPullParser();
		
		parser.setInput(in, "utf-8");
		
		int type = parser.getEventType();
		while(type!=XmlPullParser.END_DOCUMENT){
			switch (type) {
			case XmlPullParser.START_TAG:
				if ("weather".equals(parser.getName())){
					weatherLists = new ArrayList<Channel>();
				}
				else if("channel".equals(parser.getName())){
					channel = new Channel();
					String id = parser.getAttributeValue(0);
					channel.setId(id);
				}else if("city".equals(parser.getName())){
					String city = parser.nextText();
					channel.setCity(city);
				}else if("temp".equals(parser.getName())){
					String temp = parser.nextText();
					channel.setTemp(temp);
				}else if("wind".equals(parser.getName())){
					String wind = parser.nextText();
					channel.setWind(wind);
				}else if("pm250".equals(parser.getName())){
					String pm250 = parser.nextText();
					channel.setPm250(pm250);
				}
				break;
				
			case XmlPullParser.END_TAG:
				
				if("channel".equals(parser.getName())){
					weatherLists.add(channel);
				}
				break;
			}
			
			
			
			type = parser.next();
		}
		return weatherLists;
		
	}

}

