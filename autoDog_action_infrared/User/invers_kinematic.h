/*
 * INVERS_KINEMATIC.h
 * ��е���˶�ѧ��⺯��
 * ����: 2018.11.25
 * ����: ������
 */

#ifndef _INVERS_KINEMATIC_H
#define _INVERS_KINEMATIC_H


void initial_traj_plan(int i);
void first_traj_plan(int i);
void second_traj_plan(int i);
void test_Three(int i);
void UpPlan(int i);
char ikine(float px,float py, float pz, float* theta);
	
#endif
