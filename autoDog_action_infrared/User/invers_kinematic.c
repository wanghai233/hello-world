#include <math.h>
#include "invers_kinematic.h"
#define pi 3.1415926
#define number 4096
#define zz 350						//初始化z轴的参数
#define zu 250						//下蹲z轴的参数
#define y_y 0.5						//修改初始化y轴的参数
#define y_shift 10.0			//修改初始化y轴的参数
#define z_shif 2					//修改初始化z轴的参数，使其迈步变小
float a1=84.3;						//多足轴与轴之间的距离
float a2=162.3;
float a3=184.85;

int initial_pos[12]={1763,2245,976,773,2295,1261,1870,1810,3072,2509,2000,3146};
float initial_angle[12]={0,0,pi/2,0,0,pi/2,0,0,pi/2,0,0,pi/2};
int motor_flag[12]={1,1,1,1,-1,1,1,1,1,-1,-1,1};
int posi_now[12]={0,0,0,0,0,0,0,0,0,0,0,0};
unsigned int x[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
float y[12] = {5,10,15,20,25,30,35,40,45,50,55,60};
int z[12] = {6,12,18,24,30,30,30,24,18,12,6,0};

float yy[12] = {55,50,45,40,35,30,25,20,15,10,5,0};
float yy1[12] = {-5,-10,-15,-20,-25,-30,-35,-40,-45,-50,-55,-60};

//leftswing
float ysupport[24]={55,50,45,40,35,30,25,20,15,10,5,0,-5,-10,-15,-20,-25,-30,-35,-40,-45,-50,-55,-60};
float zleftswing[24] = {3,6,9,12,15,18,21,24,27,30,30,30,30,30,30,24,21,18,15,12,9,6,3,0};
float yleftswing[24]={-55,-50,-45,-40,-35,-30,-25,-20,-15,-10,-5,0,5,10,15,20,25,30,35,40,45,50,55,60};

//rightswing
float ysupport2[24]={55,50,45,40,35,30,25,20,15,10,5,0,-5,-10,-15,-20,-25,-30,-35,-40,-45,-50,-55,-60};
float zrightswing[24] = {3,6,9,12,15,18,21,24,27,30,30,30,30,30,30,24,21,18,15,12,9,6,3,0};
float yrightswing[24]={-55,-50,-45,-40,-35,-30,-25,-20,-15,-10,-5,0,5,10,15,20,25,30,35,40,45,50,55,60};


char fkine(float pos[3],float s1,float s2,float s3)
{
	pos[0]= - a3*(cos(s1)*sin(s2)*sin(s3) - cos(s1)*cos(s2)*cos(s3)) + a1*cos(s1) + a2*cos(s1)*cos(s2);
	pos[1]=a3*(cos(s2)*sin(s3) + cos(s3)*sin(s2)) + a2*sin(s2);
	pos[2]=a3*(sin(s1)*sin(s2)*sin(s3) - cos(s2)*cos(s3)*sin(s1)) - a1*sin(s1) - a2*cos(s2)*sin(s1);

	return 0;
}

void angle2posi(float theta,int i)
{
	  posi_now[i]=initial_pos[i]+motor_flag[i]*(theta-initial_angle[i])/(2*pi)*4096.0;
}//将x、y、z换算成对应的角度

char ikine(float px,float py, float pz, float* theta)
{
	   float n1,n2,theta21,theta22,posd[3];
	   float theta1=-atan2(pz,px);
	
	   float theta3=acos((pow(sqrt(px*px+pz*pz)-a1,2)+py*py-a3*a3-a2*a2)/(2*a3*a2)); 


        if (theta1<0)
		{
			 theta1=pi+theta1;
		     theta3=acos((pow(-sqrt(px*px+pz*pz)-a1,2)+py*py-a3*a3-a2*a2)/(2*a3*a2)); 
		}



		n1=a3*cos(theta3)+a2;
	  n2=a3*sin(theta3);

		theta21=asin(py/sqrt(n1*n1+n2*n2))-atan2(n2,n1);
		theta22=(pi-asin(py/sqrt(n1*n1+n2*n2))-atan2(n2,n1));

	

        fkine(posd,theta1, theta21, theta3);
 
	   if (( fabs(posd[0]-px)<0.0001 ) && ( fabs(posd[1]-py)<0.0001 )  &&(fabs(posd[2]-pz)<0.0001) )
		{
			theta[0]=theta1;
			theta[1]=theta21;
			theta[2]=theta3;
		}
		else
		{
			theta[0]=theta1;
			theta[1]=theta22;
			theta[2]=theta3;
		}
				
	return 1;
}

void initial_traj_plan(int i)
{

	float th_lf[3];
  float th_lb[3];
	float th_rf[3];
  float th_rb[3];
	
	ikine(x[i],y[i]*y_y-y_shift,z[i]*z_shif-zz,th_rf);
	angle2posi(th_rf[0],11);
	angle2posi(th_rf[1],10);
	angle2posi(th_rf[2],9);
	
	ikine(x[i],y[i]*y_y-y_shift,z[i]*z_shif-zz,th_lb);
	angle2posi(th_lb[0],5);
	angle2posi(th_lb[1],4);
	angle2posi(th_lb[2],3);
	
	ikine(x[i],yy1[i]*y_y-y_shift,z[0]*z_shif-zz,th_lf);//left forward leg don't move
	angle2posi(th_lf[0],2);
	angle2posi(th_lf[1],1);
	angle2posi(th_lf[2],0);
	
	ikine(x[i],yy1[i]*y_y-y_shift,z[0]*z_shif-zz,th_rb);//right backward leg don't move
	angle2posi(th_rb[0],8);
	angle2posi(th_rb[1],7);
	angle2posi(th_rb[2],6);
	
	
#if 0	
	//left forward leg
	ikine(posi[0],posi[1],posi[2],th_lf);

	angle2posi(th_lf[0],0);
	angle2posi(th_lf[1],1);
	angle2posi(th_lf[2],2);
	
	
		//left backward leg
	ikine(posi[0],posi[1],posi[2],th_lb);

	angle2posi(th_lb[0],3);
	angle2posi(th_lb[1],4);
	angle2posi(th_lb[2],5);
	
	
	//right forward leg
	ikine(posi[0],posi[1],posi[2],th_rf);

	angle2posi(th_rf[0],6);
	angle2posi(th_rf[1],7);
	angle2posi(th_rf[2],8);
	
	
	//right backward leg
	ikine(posi[0],posi[1],posi[2],th_rb);

	angle2posi(th_rb[0],9);
	angle2posi(th_rb[1],10);
	angle2posi(th_rb[2],11);
	while(1);
#endif
}

void UnderarmPosPlan(int i)
{

	float th_lf[3];
  float th_lb[3];
	float th_rf[3];
  float th_rb[3];
	
	ikine(x[i],y[i]*y_y-y_shift,z[i]-zu,th_rf);
	angle2posi(th_rf[0],11);
	angle2posi(th_rf[1],10);
	angle2posi(th_rf[2],9);
	
	ikine(x[i],y[i]*y_y-y_shift,z[i]-zu,th_lb);
	angle2posi(th_lb[0],5);
	angle2posi(th_lb[1],4);
	angle2posi(th_lb[2],3);
	
	ikine(x[i],yy1[i]*y_y-y_shift,z[0]-zu,th_lf);//left forward leg don't move
	angle2posi(th_lf[0],2);
	angle2posi(th_lf[1],1);
	angle2posi(th_lf[2],0);
	
	ikine(x[i],yy1[i]*y_y-y_shift,z[0]-zu,th_rb);//right backward leg don't move
	angle2posi(th_rb[0],8);
	angle2posi(th_rb[1],7);
	angle2posi(th_rb[2],6);
}

void UpPlan(int i)
{
	float th_lf[3];
  float th_lb[3];
	float th_rf[3];
  float th_rb[3];
	
	ikine(x[i],y[i]*y_y-y_shift,z[i]-zz,th_rf);
	angle2posi(th_rf[0],11);
	angle2posi(th_rf[1],10);
	angle2posi(th_rf[2],9);
	
	ikine(x[i],y[i]*y_y-y_shift,z[i]-zz,th_lb);
	angle2posi(th_lb[0],5);
	angle2posi(th_lb[1],4);
	angle2posi(th_lb[2],3);
	
	ikine(x[i],yy1[i]*y_y-y_shift,z[0]-zz,th_lf);//left forward leg don't move
	angle2posi(th_lf[0],2);
	angle2posi(th_lf[1],1);
	angle2posi(th_lf[2],0);
	
	ikine(x[i],yy1[i]*y_y-y_shift,z[0]-zz,th_rb);//right backward leg don't move
	angle2posi(th_rb[0],8);
	angle2posi(th_rb[1],7);
	angle2posi(th_rb[2],6);
}

void first_traj_plan(int i)
{

	float th_lf[3];
  float th_lb[3];
	float th_rf[3];
  float th_rb[3];
	
	
	//右前腿
	ikine(0,ysupport[i]*y_y-y_shift,-zz,th_rf);
	angle2posi(th_rf[0],11);
	angle2posi(th_rf[1],10);
	angle2posi(th_rf[2],9);
	//右后腿
	ikine(0,yleftswing[i]*y_y-y_shift,zleftswing[i]*z_shif-zz,th_rb);
	angle2posi(th_rb[0],8);
	angle2posi(th_rb[1],7);
	angle2posi(th_rb[2],6);
	//左后腿
	ikine(0,ysupport[i]*y_y-y_shift,-zz,th_lb);
	angle2posi(th_lb[0],5);
	angle2posi(th_lb[1],4);
	angle2posi(th_lb[2],3);
	//左前腿
	ikine(0,yleftswing[i]*y_y-y_shift,zleftswing[i]*z_shif-zz,th_lf);
	angle2posi(th_lf[0],2);
	angle2posi(th_lf[1],1);
	angle2posi(th_lf[2],0);
	

}

void second_traj_plan(int i)
{

	float th_lf[3];
  float th_lb[3];
	float th_rf[3];
  float th_rb[3];
	
	
	//右前腿
	ikine(0,yrightswing[i]*y_y-y_shift,zrightswing[i]*z_shif-zz,th_rf);
	angle2posi(th_rf[0],11);
	angle2posi(th_rf[1],10);
	angle2posi(th_rf[2],9);
	//右后腿
	ikine(0,ysupport[i]*y_y-y_shift,-zz,th_rb);
	angle2posi(th_rb[0],8);
	angle2posi(th_rb[1],7);
	angle2posi(th_rb[2],6);
	//左后腿
	ikine(0,yrightswing[i]*y_y-y_shift,zrightswing[i]*z_shif-zz,th_lb);
	angle2posi(th_lb[0],5);
	angle2posi(th_lb[1],4);
	angle2posi(th_lb[2],3);
	//左前腿
	ikine(0,ysupport[i]*y_y-y_shift,-zz,th_lf);
	angle2posi(th_lf[0],2);
	angle2posi(th_lf[1],1);
	angle2posi(th_lf[2],0);
	

}
/*
void test_Three(int i)
{

	float posi[]={0, 0,  -150};

	float th_lf[3];
  float th_lb[3];
	float th_rf[3];
  float th_rb[3];
	
	ikine(x[i],y[i]*y_y,z[i]-zz,th_rf);
	angle2posi(th_rf[0],11);
	angle2posi(th_rf[1],10);
	angle2posi(th_rf[2],9);
	
	ikine(x[i],y[i]*y_y,z[i]-zz,th_lb);
	angle2posi(th_lb[0],5);
	angle2posi(th_lb[1],4);
	angle2posi(th_lb[2],3);
	
	ikine(x[i],yy[i]*y_y,z[i]-zz,th_lf);
	angle2posi(th_lf[0],2);
	angle2posi(th_lf[1],1);
	angle2posi(th_lf[2],0);
	
	ikine(x[i],yy[i]*y_y,z[i]-zz,th_rb);
	angle2posi(th_rb[0],8);
	angle2posi(th_rb[1],7);
	angle2posi(th_rb[2],6);
}
*/