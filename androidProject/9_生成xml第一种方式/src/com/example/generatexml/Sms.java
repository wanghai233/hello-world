package com.example.generatexml;

public class Sms {
	
	private String address;
	
	private String body;
	
	private String data;

	public String getAddress() {
		return address;
	}

	public void setAddress(String address) {
		this.address = address;
	}

	public String getBody() {
		return body;
	}

	public void setBody(String body) {
		this.body = body;
	}

	public String getData() {
		return data;
	}

	public void setData(String data) {
		this.data = data;
	}

	@Override
	public String toString() {
		return "Sms [address=" + address + ", body=" + body + ", data=" + data
				+ "]";
	}

//	public void setAddress(String address2) {
//		// TODO Auto-generated method stub
//		
//	}	
}
