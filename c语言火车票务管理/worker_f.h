#ifndef WORKER_F_H
#define WORKER_F_H
#include "globalvariable_f.h"  

a_cs1 A_C1[SIZE]={{"����","w1111","1111"},
				  {"С��","w2222","2222"},
				  {"�ƻ�","w3333","3333"}};
a_cs1 *p1_A_C;
trains TRAIN[N];
int status1; 
int status2;
int status3;

void w_sign_menu(void);				//������Ա��¼--���˵� 
void sign_worker(void);				//������Ա��¼--������ 
void sign_in1(void);				//������Ա--�˺���������������
void sign_account_in1(void);		//������Ա�˺�����
void sign_password_in1(void);		//������Ա��������

void menu1();                		// ���ι������--���˵� 
void worker_man(void);          	// ���ι���--������
void w_read(trains *,int * );    	// ���ļ�--train_inf.txt
void w_save(trains *,int * );    	// ���ļ�--train_inf.txt
void train_add(trains *,int * );	// ��ӳ�����Ϣ
void train_del(trains *,int * );	// ɾ��������Ϣ 
void train_mod(trains *,int * );	// �޸ĳ�����Ϣ 
void train_search(trains *,int * );	// ��ѯ������Ϣ
int search(char *,trains *,int);	// ����������Ϣ 

int w_to_p_read(void);              //��ȡ�˿Ͷ�Ʊ��Ϣ 
void w_to_p_statistic(void);        //ͳ�ƶ�Ʊ�˴� 
#endif 
