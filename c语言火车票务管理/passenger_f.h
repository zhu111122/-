#ifndef PASSENGER_F_H
#define PASSENGER_F_H
#include "globalvariable_f.h" 

a_cs2 A_C2[SIZE]={{"���","p1111","1111"},
				  {"��˲�","p2222","2222"},
				  {"�Ʋ˲˲�","p3333","3333"}}; 
a_cs2 *p2_A_C;
 
void sign_passenger(void);			//�˿͵�¼--������
void sign_menu(void);				//�˿͵�¼--�˵� 
void sign_in2(void);				//�˿�--��Ϣ����
void sign_account_in2(void);		//�˿�--�˺�����
void sign_password_in2(void);		//�˿�--��������


void passenger_man(void);					// �˿��˶�Ʊ--������ 
void welcome_passenger_menu(void);			// �˿��˶�Ʊ--�˵� 
void p_read(trains * ,int *);				// ���ļ�--passenger_b 
void p_save(trains * ,int );				// ���ļ�--passenger_b 

void passenger_order(void);					// �˿Ͷ�Ʊϵͳ--������
void passenger_menu(void);					// �˿Ͷ�Ʊϵͳ--�˵� 
void p_order(trains * ,int *);				// ��֧--ֱ�Ӷ�Ʊ
int search1(char * , trains * , int );		// ��Ʊ--��������


void passenger_return(trains*,int*);		// �˿���Ʊϵͳ
void passenger_ret_del(trains* ,int ,int);	// ��Ʊ--ɾ������ 
void p1_save(trains *,int );				// ��Ʊ--�����ļ� 
int search2(char * , trains * , int );		// ��Ʊ--�������κ�

							
void passenger_search(void);				// �˿Ͳ�ѯϵͳ
void read_p(trains* ,int * );				// ���ļ�--��ѯ�Ѷ���Ʊ 


void p_search_main(void);					// ��֧--��ѯ����(������) 
void p_search_menu(void);					// ��֧--��ѯ����(�˵�)
void read_w(trains * ,int * ); 				// ���ļ�--train_inf 
char* p_search_num(void);					// ��ѯ--���� 
char* p_search_month(void);					// ��ѯ--�·� 
char* p_search_day(void);					// ��ѯ--���� 
char* p_search_startime(void);				// ��ѯ--����ʱ�� 
char* p_search_endtime(void);				// ��ѯ--����ʱ�� 
char* p_search_strsta(void);				// ��ѯ--ʼ��վ 
char* p_search_endsta(void);				// ��ѯ--�յ�վ 
int search_num(char *,trains *,int );		// ��ѯ--��������
int search_monthday(char *,char *,trains *,int );	// ��ѯ--�·��������� 
int search_startime(char *,trains *,int );			// ��ѯ--����ʱ������
int search_endtime(char *,trains *,int );			// ��ѯ--����ʱ������
int search_strendsta(char *,char *,trains *,int );	// ��ѯ--��ʼվ����

#endif
