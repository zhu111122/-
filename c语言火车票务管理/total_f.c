#include "total_f.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���˵� 
void main_man(void)
{
	int ch;	
	menu( ); 
	printf("\t\t\t  ����ѡ���ǣ�");
	scanf("%c",&ch);
	switch(ch)
	{
		case 'A':
		case 'a':sign_worker();
				 break;
		case 'B':
		case 'b':sign_passenger();
				 break; 
		case 'Q':
		case 'q':fflush(stdin);
				 bye( );
				 exit(1);
				 
		default:printf("\t����������������룡\n\n");
                fflush(stdin);
                main_man( );
				break;
			
	}
	
}

//����ʼ���� 
void menu(void)
{
	printf("\t            ");
	line(70);
	printf("\n\t\t\t\t\t\t������ʵ��������Ϊ\n");
	printf("\n\t\t\t\t\t��ӭʹ�����ӡ�С��ͻƻƵĻ𳵹���ϵͳ��  \n\n");
	printf("\t            ");
	line(70);
	printf("\t\t\t  ��ѡ��������ݣ�\n\n");
	printf("\t\t\t  [A] ������Ա \t\t[B] �˿� \t\t[Q] �˳�\n");
	printf("\t            ");
	line(70);
 } 

//�������ҳ�� 
void bye(void)
{
	system("cls");
	printf("\t            ");
	space(5);star(50);
	printf("\n\t\t\t\t\t��л��ʹ�û�Ʊ����ϵͳ!\n\n");
	printf("\t\t\t\t\tby ���ӣ��ƻƣ�С��\n\n");
	printf("\n\t\t\t\t\t�ر���л��ʮ�����Ĳ���ʦ\n");
	printf("\n\t\t\t\t\t�������������\n");
	printf("\n\t\t\t\t\t���Ŀ���С�ϸ�\n");
	printf("\n\t\t\t\t\t���ĳ��ԭ������\n");
	printf("\n\t\t\t\t\t����С����\n");
	printf("\n\t\t\t\t\t20�Źܰ�Ϊ�����ṩ��������ͬѧ��\n\n");
	printf("\t            ");
	space(5);star(50);
	exit(0); 
}

//��ʽ--�ո� 
void space(int n)
{
	int i;
	for(i=1;i<n;i++)
	   printf(" ");
}

//��ʽ--С���� 
void line(int n)
{
	int i;
	for(i=1;i<=n;i++)
	   printf("-"); 
	printf("\n");
}

//��ʽ--���� 
void star(int n)
{
	int i;
	for(i=1;i<=n;i++)
	   printf("*"); 
	printf("\n");
}
