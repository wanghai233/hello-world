#include "key.h"

sbit k0=P3^0;
sbit k1=P3^1;
sbit k2=P3^2;
sbit k3=P3^3;
sbit k4=P3^4;
sbit k5=P3^5;
sbit k6=P4^2;
sbit k7=P4^4;

void Keycheck(void)
{
	P3=0xff;
	key=0;
	k7=0;
	if(k3==0) key=4;
	if(k2==0) key=5;	
	if(k1==0) key=6;
	if(k0==0) key=7;
	k7=1;
	k6=0;
	if(k3==0) key=8;
	if(k2==0) key=9;	
	if(k1==0) key=10;
	if(k0==0) key=11;
	k6=1;
	k5=0;
	if(k3==0) key=12;
	if(k2==0) key=13;	
	if(k1==0) key=14;
	if(k0==0) key=15;
	k5=1;
	k4=0;
	if(k3==0) key=19;
	if(k2==0) key=18;	
	if(k1==0) key=17;
	if(k0==0) key=16;
	k4=1;
}