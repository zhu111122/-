#ifndef GLOBALVARIABLE_H
#define GLOBALVARIABLE_H
#define SIZE 10
#define STARS "************************"
#define N 1000

//����һ��������Ա�˺�����Ľṹ��   
typedef struct a_c1
{
	char NAME1[SIZE];		//���� 
	char ACCOUNT1[SIZE];	//�˺� 
	char PASSWORD1[SIZE];	//���� 
}a_cs1;
		
//����һ�����˿��˺�����Ľṹ��
typedef struct a_c2
{
	char NAME2[SIZE];		//���� 
	char ACCOUNT2[SIZE];	//�˻� 
	char PASSWORD2[SIZE];	//���� 
}a_cs2;

//����һ��������Ϣ�Ľṹ�� 
typedef struct train
{           
	char NUM[10];			//���κ� 
	char MONTH[10];			//�·� 
	char DAY[10];			//�� 
	char START[10];			//����ʱ�� 
	char END[10];			//����ʱ�� 
	char STA_START[30];		//ʼ��վ 
	char STA_END[30]; 		//�յ�վ 
}trains;

#endif
