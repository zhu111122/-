#include "passenger_f.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�˿͵�¼--������
void sign_passenger(void)
{
	system("cls");
	int i;
	sign_menu( );
	while(1)
	{
		scanf("%d",&i);
		switch(i)
		{
			case 1:	sign_in2( );
					break;
			case 2: system("cls");
    				fflush(stdin);
					main_man(  );	
					break;
			case 3: system("pause");
				    bye();
				    exit(1);
					break;
			default:printf("��������ȷ��ָ�\n");
					fflush(stdin); 	
					continue;
		}
	 } 
 } 
 
//�˿͵�¼--���˵� 
void sign_menu(void)
{
	printf("\t            ");
    space(10);star(50);
	printf("\n\t\t\t\t\t���ã���ӭʹ�ó˿Ͷ�!\n\n");
	printf("\t            ");	
	space(10);star(50);
	printf("\t            ");	
	line(70);
    printf("\t\t\t��ѡ��\n\n");
	printf("\t\t\t[1] ��¼ \t\t[2] ���� \t\t[3] �˳�\n");
	printf("\t            ");	
	line(70);
	printf("\n\t\t\t����ѡ���ǣ�"); 
}

//�˿�--��Ϣ����
void sign_in2(void)
{
	printf("\n\t\t\t�������˺����룺");
	sign_account_in2();
	sign_password_in2();
	passenger_man( );
}

//�˿�--�˺�����
void sign_account_in2(void) 
{
	int i,j;
	char account[SIZE];
	p2_A_C=&A_C2[0];
	printf("\n\t\t\t�˺ţ�");
	scanf("%s",&account);
	for(i=0;i<SIZE;i++) 
	{
	    int s=strcmp(account,p2_A_C->ACCOUNT2);
		p2_A_C++;
		if(s==0)  break;
		else 
		{
            if(i==SIZE-1)	
			 {
				printf("\n\t\t    �˺Ŵ���!\n");
				printf("\t\t    ����������!\n");
				    sign_account_in2();
			 }
			else continue;
		}
	}
} 

//�˿�--�������� 
int count2=0;
void sign_password_in2(void)
{
	count2++;
	char password[SIZE];
	printf("\n\t\t\t���룺");	
	scanf("%s",&password);
	if((strcmp(password,(p2_A_C-1)->PASSWORD2))!=0)
	{ 
		   printf("\n\t\t    �������\n");
		   printf("\t\t    ����������!\n");
		   	if(count2<3)
			 {
			   sign_password_in2();
			 }
			else if(count2==3)
			 {
				printf("������������˳���¼\n");
				exit(EXIT_FAILURE); 
			 }				
	} 
	else 
	{
		system("cls");
		space(30);star(42);
		printf("\n\t\t\t\t\t  ��ӭ��,%s��\n\n",(p2_A_C-1)->NAME2);
		space(30);star(42); 
	}
}


//�˿��˶�Ʊ--������
void passenger_man(void)
{
	int i,n;
	trains TRAIN2[N];
	trains TRAIN5[N];
	p_read(TRAIN2,&n);
	while(1)
	{
		welcome_passenger_menu(); 
		scanf("%d",&i);
		switch(i)
		{
			case 1:	passenger_order( );
					break;
			case 2: passenger_return(TRAIN5,&n);	
					break;
			case 3: passenger_search( );
					system("pause");
					system("cls");
					break;
			case 4: printf("\t\t\t\tע���ɹ�\n"); 
					system("pause"); 
					system("cls");
    				fflush(stdin);
					main_man( );	
					break;
			case 5: system("pause");
			        bye();
			        exit(1);
			        return;
			default:printf("\t\t��������ȷ��ָ�\n");
					system("cls");
					fflush(stdin); 
					continue;
		}
	}
} 

//�˿��˶�Ʊ--�˵� 
void welcome_passenger_menu(void)  
{
	space(12);line(70);
	printf("\t\t\t\t\t    �˿Ͷ���Ʊ����  \n");
	space(12);line(70);
	printf("\t\t\t\t  [1] ��  Ʊ \t\t [2] ��    Ʊ \n\n");
	printf("\t\t\t\t  [3] ��  ѯ \t\t [4] ע����¼ \n\n");
	printf("\t\t\t\t  [5] ��  �� \n");
	space(12);line(70);
	printf("\n\t\t\t����ѡ���ǣ�"); 
}

//��ȡ�ļ�--passenger_b
void p_read(trains *TRAIN2 ,int *n) 
{	
	int i;
	FILE *fp_b;
	if((fp_b=fopen("passenger_b.txt","r"))==NULL)
	{ * n=0;return;}
	for(i=0;!feof(fp_b);i++)
	    if(fread(&TRAIN2[i],sizeof(trains),1,fp_b) !=1) break;
	*n=i;
	fclose(fp_b);  
 } 	

//�����ļ�--passenger_b 
void p_save(trains *TRAIN ,int k)
{
	int i;
	FILE *fp_p;
	if((fp_p=fopen("passenger_b.txt","a+"))==NULL)
	{ return;}
	fwrite(&TRAIN[k],sizeof(trains),1,fp_p);
	fclose(fp_p); 
 } 

 
//�˿Ͷ�Ʊϵͳ 
//��Ʊ--������ 
void passenger_order(void)
 {
 	int choice;
 	trains *TRAIN2[N];
 	int *n;
 	passenger_menu();
 	while(1)
 	{
 		scanf("%d",&choice);
 		switch(choice)
 		{
 			case 1:
 				{
 					p_search_main( );
 					p_order(TRAIN2,n); 
 					break;
				 }
			case 2:
				{
					p_order(TRAIN2,n);
					break;
				}
			default:
				{
					printf("��������ȷָ�");
					continue;
				}
		 }
		passenger_man( );
	 }
} 

//��Ʊ--�˵� 
void passenger_menu(void)
{
	space(20);line(70);
	printf("\t\t\t\t\t\t�˿Ͷ�Ʊ����  \n");	
    space(20);line(70);
	printf("\t\t\t\t  [1] ��ѯ������Ϣ \t\t [2] ֱ�Ӷ�Ʊ \n");
	space(20);line(70);
	printf("\n\t\t\t\t����ѡ���ǣ�"); 
 } 

//��֧--ֱ�Ӷ�Ʊ 
void p_order(trains *TRAIN2 ,int *n) 
{
	//�Ȱ��ļ��еĳ�����Ϣ���´���ṹ������TRAIN1;
	int i,trainnum; 
	trains TRAIN1[N]; 
	FILE *fp_a;
	
	if((fp_a=fopen("train_inf.txt","r"))==NULL)
	{ trainnum=0;return;}
	for(i=0;!feof(fp_a);i++)
	    if(fread(&TRAIN1[i],sizeof(trains),1,fp_a) !=1) break;
	trainnum=i;
	fclose(fp_a); 
				     
    //���ݳ˿�����ĳ�����Űѽṹ���е���Ӧһ�����ݴ��뵽���ļ��� 
	int j,k,h,ret;
	char NUM[10]; 	
	
	printf("\n\t���������붩�ĳ�����ţ�");
	scanf("%s",NUM);
	system("cls");
	k=search1(NUM,TRAIN1,trainnum); 
	if(k==-1) 
	{
		printf("\t\t�ó��β�����\n");
		system("pause");
	}
	else
	{		
		printf("\n\t������Ϣ���£�\n"); 
		line(80);
		printf("\t���κ�\t�·�\t��\t����ʱ��\t����ʱ��\tʼ��վ\t�յ�վ\n");
		printf("\t%s\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN1+k)->NUM,(TRAIN1+k)->MONTH,(TRAIN1+k)->DAY,
		      (TRAIN1+k)->START,(TRAIN1+k)->END,(TRAIN1+k)->STA_START,(TRAIN1+k)->STA_END);
		line(80);
		printf("\t��ȷ��������\n\n");
		printf("\t[1] �� \t[2] ��\n"); 
		line(50); 
		printf("\n\t����ѡ���ǣ�");
		scanf("%d",&h);
		if(h==1)
		{   
		    TRAIN2[k]=TRAIN1[k];
			p_save(TRAIN2,k);
			fflush(stdin);
			printf("\n\t�����ɹ���\n");
			system("pause");
			system("cls");	
		}  
	} 
}

//��Ʊ--�������κ� 
int search1(char *NUM,trains *TRAIN,int n)
{
	int i;
	for(i=0;i<n;i++)
		if(strcmp((TRAIN+i)->NUM,NUM)==0) 
		 	return i;
	return -1;
}


//�˿���Ʊϵͳ 
void passenger_return(trains *TRAIN5 ,int *n)
{
	//�Ȱ��ļ��еĳ�����Ϣ���´���ṹ������TRAIN1;
	int i,ordernum;
	trains TRAIN4[N]; 
	FILE *fp_b;
	
	if((fp_b=fopen("passenger_b.txt","r"))==NULL)
	{ ordernum=0;return;}
	for(i=0;!feof(fp_b);i++)
    if(fread(&TRAIN4[i],sizeof(trains),1,fp_b) !=1) break;
	ordernum=i;
	fclose(fp_b); 
 						
    printf("\t\t\t   ");
    space(5);star(50);
    printf("\t\t\t\t\t\t�Ѷ���������Ϣ��\n");
	printf("\t            ");	
    line(80);
	printf("\t\t\t ���κ�\t�·�\t��\t����ʱ��\t����ʱ��\tʼ��վ\t�յ�վ\n");
	for(i=0;i<ordernum;i++)
	   printf("\t\t\t %s\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN4+i)->NUM,(TRAIN4+i)->MONTH,(TRAIN4+i)->DAY,
		      (TRAIN4+i)->START,(TRAIN4+i)->END,(TRAIN4+i)->STA_START,(TRAIN4+i)->STA_END);
	printf("\t            ");	
	line(80);
	
    //���ݳ˿�����ĳ�����Űѽṹ���е���Ӧһ�����ݴ��뵽���ļ��� 
	int j,k,h,ret;
	char NUM[10]; 	

	printf("\n\t�����������˶��ĳ�����ţ�");
	scanf("%s",NUM);
	k=search2(NUM,TRAIN4,ordernum);
	
	if(k==-1) 
	{
		printf("\t\t�ó��β�����\n");
		system("pause");
	}
	else
	{
		printf("\t\t\t\t\t\t������Ϣ���£�\n");
	    printf("\t            ");
		line(80);
		printf("\t\t\t ���κ�\t�·�\t��\t����ʱ��\t����ʱ��\tʼ��վ\t�յ�վ\n");
		printf("\t\t\t\t    %s\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN4+k)->NUM,(TRAIN4+k)->MONTH,(TRAIN4+k)->DAY,
		      (TRAIN4+k)->START,(TRAIN4+k)->END,(TRAIN4+k)->STA_START,(TRAIN4+k)->STA_END);
	    printf("\t            ");
		line(80);
		printf("\t\t\t  ��ȷ���˶���\n\n");
		printf("\t\t\t  [1] �� \t[2] ��\n"); 
		printf("\t            ");	
		line(70); 
		printf("\n\t����ѡ���ǣ�");
		scanf("%d",&h);
		if(h==1)
		{   
		    TRAIN5=TRAIN4; 
			FILE *fp_b=fopen("passenger_b.txt","w+");
			passenger_ret_del(TRAIN5,ordernum,k);
			p1_save(TRAIN5,ordernum);
			fflush(stdin); 
			printf("\n\t�˶��ɹ�!\n");
			system("pause");
		}  
	} 
} 

//��Ʊ--�����ļ� 
void p1_save(trains *TRAIN ,int n)
{
	int i;
	FILE *fp;
	if((fp=fopen("passenger_b.txt","w"))==NULL)
	{ 	
		printf("������Ϣ����ʧ�ܡ���\n");
		return;
	}
	rewind(fp);
	for(i=0;i<n;i++)
		{
			if(fwrite(&TRAIN[i],sizeof(trains),1,fp) ==1) 
			{
				fflush(fp);
			}
			else
			{break;} 
		}
	fclose(fp); 
 }

//��Ʊ--ɾ������ 
void passenger_ret_del(trains* TRAIN2,int ordernum,int k)
{
	int i;
	for(i=k;i<ordernum;i++)
	{
		TRAIN2[i]=TRAIN2[i+1];
	}
	ordernum--;
	//save_p(TRAIN2,n); 
}

//��Ʊ--�������κ�
int search2(char *NUM,trains *TRAIN,int n) 
{
	int i;
	for(i=0;i<n;i++)
		if(strcmp((TRAIN+i)->NUM,NUM)==0)
		 	return i;
	return -1;    
}


//�˿Ͳ�ѯϵͳ 
void passenger_search(void)
{
	int ordernum;
	trains TRAIN1[N];
	FILE *fp_b;
	if((fp_b=fopen("passenger_b.txt","r"))==NULL)
	{ 	
		star(70);
		printf("\n\n\t--Ŀǰ�����Ѷ���Ʊ--\n");
		ordernum=0;
	}
	else
	{
		int i;
		for(i=0;!feof(fp_b);i++)
	    	if(fread(&TRAIN1[i],sizeof(trains),1,fp_b) !=1) break;
		ordernum=i;
		fclose(fp_b);
		 
		printf("\t\t\t   ");
	    space(5);star(50);
		printf("\t\t\t\t\t\tĿǰ�Ѷ���Ʊ��\n");
		space(20);line(80);
		printf("\t\t\t���κ�\t�·�\t��\t����ʱ��\t����ʱ��\tʼ��վ\t�յ�վ\n");
		for(i=0;i<ordernum;i++)
		   printf("\t\t\t%s\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN1+i)->NUM,(TRAIN1+i)->MONTH,(TRAIN1+i)->DAY,
		      (TRAIN1+i)->START,(TRAIN1+i)->END,(TRAIN1+i)->STA_START,(TRAIN1+i)->STA_END);
	    space(20);line(80);
	}
}

//���ļ�--��ѯ�Ѷ���Ʊ
void read_p(trains *TRAIN2 ,int *ordernum) 
{
	int i;
	FILE *fp_b;
	if((fp_b=fopen("passenger_b.txt","rb+"))==NULL)
	{ 	*ordernum=0;
		printf("\t--Ŀǰ�����Ѷ���Ʊ��--\n"); 
		return;}
	for(i=0;!feof(fp_b);i++)
	{
	    if(fread(&TRAIN2[i],sizeof(trains),1,fp_b) ==1) 
	    {
			printf("\n\tĿǰ�Ѷ���%d�ų�Ʊ��\n"); 
			line(80);
			printf("\t���κ�\t�·�\t��\t����ʱ��\t����ʱ��\tʼ��վ\t�յ�վ\n");
			printf("\t%s\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN2+i)->NUM,(TRAIN2+i)->MONTH,(TRAIN2+i)->DAY,
		      	(TRAIN2+i)->START,(TRAIN2+i)->END,(TRAIN2+i)->STA_START,(TRAIN2+i)->STA_END);
			line(80);
		} 
		else continue;
	}
	*ordernum=i;
	fclose(fp_b); 
 } 


//��֧--��ѯ����(�˵�) 
void p_search_menu(void)
{
	printf("\n");
	space(32);star(50);
	printf("\n\t\t\t\t\t\t    ���β�ѯ  \n");
	space(20);line(80);
	printf("\t\t\t\t   [1] ������� \t\t [2] �������� \n\n");
	printf("\t\t\t\t   [3] ����ʱ�� \t\t [4] ����ʱ�� \n\n");
	printf("\t\t\t\t   [5] �� ʼ վ \t\t [6] ���붩Ʊ \n\n");
	printf("\t\t\t\t   [7] ��    �� \n");
	space(20);line(80);
	printf("\n\t\t\t��ѡ������Ҫ��ѯ����Ŀ��ţ�"); 
}

//��֧--��ѯ����(������) 
void p_search_main(void)
{
	trains TRAIN4[N]; 
	int trainnum;
	int n1,n2,n3,n4,n5,i;
	while(1) 
	{
		int choice=0;
		trains TRAIN3[N],TRAIN2;
		read_w(TRAIN3,&trainnum); 
		p_search_menu( );
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				{
					strcpy(TRAIN2.NUM,p_search_num());//�Ѳ�ѯ��������train1.num 
					n1=search_num(TRAIN2.NUM,TRAIN3,trainnum);
					if(n1==-1)
					{
						printf("\n\t\tĿǰ���޷��ϸò�ѯ�����ĳ��Σ������²�ѯ��\n");
						fflush(stdin);
						continue;
					}
					else
					{
					
						printf("\n\t\t\t\t\t\t    ������Ϣ���£�\n");
						printf("\t            ");
						line(80);
						printf("\t\t\t  ���κ�\t�·�\t��\t����ʱ��\t����ʱ��\tʼ��վ\t�յ�վ\n\n");
						printf("\t\t\t  %s\t\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN3+n1)->NUM,(TRAIN3+n1)->MONTH,(TRAIN3+n1)->DAY,
		      				  (TRAIN3+n1)->START,(TRAIN3+n1)->END,(TRAIN3+n1)->STA_START,(TRAIN3+n1)->STA_END);
						printf("\t            ");
						line(80);
					}
					break;
				}
			case 2://��ѯ�·������� 
				{
					strcpy(TRAIN2.MONTH,p_search_month());//�Ѳ�ѯ��������TRAIN1.MONTH 
					strcpy(TRAIN2.DAY,p_search_day());//����ѯ���� 
					n2=search_monthday(TRAIN2.MONTH,TRAIN2.DAY,TRAIN3,trainnum);
					if(n2==-1)
					{
						printf("\n\t\tĿǰ���޷��ϸò�ѯ�����ĳ��Σ������²�ѯ��\n");
						fflush(stdin);
						continue;
					}
					else
					{
						printf("\n\t\t\t\t\t\t    ������Ϣ���£�\n");
						printf("\t            ");
						line(80);
						printf("\t\t\t  ���κ�\t�·�\t��\t����ʱ��\t����ʱ��\tʼ��վ\t�յ�վ\n\n");
						printf("\t\t\t  %s\t\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN3+n2)->NUM,(TRAIN3+n2)->MONTH,(TRAIN3+n2)->DAY,
		      				  (TRAIN3+n2)->START,(TRAIN3+n2)->END,(TRAIN3+n2)->STA_START,(TRAIN3+n2)->STA_END);
						printf("\t            ");
						line(80);
					}
					break;
				}
			case 3: 
				{
					strcpy(TRAIN2.START,p_search_startime());//����ѯ���� 
					n3=search_startime(TRAIN2.START,TRAIN3,trainnum);
					if(n3==-1)
					{
						printf("\n\t\tĿǰ���޷��ϸò�ѯ�����ĳ��Σ������²�ѯ��\n");
						fflush(stdin);
						continue;
					}
					else
					{
						printf("\n\t\t\t\t\t\t    ������Ϣ���£�\n");
						printf("\t            ");
						line(80);
						printf("\t\t\t  ���κ�\t�·�\t��\t����ʱ��\t����ʱ��\tʼ��վ\t�յ�վ\n\n");
						printf("\t\t\t  %s\t\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN3+n3)->NUM,(TRAIN3+n3)->MONTH,(TRAIN3+n3)->DAY,
		      				  (TRAIN3+n3)->START,(TRAIN3+n3)->END,(TRAIN3+n3)->STA_START,(TRAIN3+n3)->STA_END);
						printf("\t            ");
						line(80);
					}
					break;
				}
			case 4:
				{
					strcpy(TRAIN2.END,p_search_endtime());//����ѯ���� 
					n4=search_endtime(TRAIN2.END,TRAIN3,trainnum);
					if(n4==-1)
					{
						printf("\n\t\tĿǰ���޷��ϸò�ѯ�����ĳ��Σ������²�ѯ��\n");
						fflush(stdin);
						continue;
					}
					else
					{
						printf("\n\t\t\t\t\t\t    ������Ϣ���£�\n");
						printf("\t            ");
						line(80);
						printf("\t\t\t  ���κ�\t�·�\t��\t����ʱ��\t����ʱ��\tʼ��վ\t�յ�վ\n\n");
						printf("\t\t\t  %s\t\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN3+n4)->NUM,(TRAIN3+n4)->MONTH,(TRAIN3+n4)->DAY,
		      				  (TRAIN3+n4)->START,(TRAIN3+n4)->END,(TRAIN3+n4)->STA_START,(TRAIN3+n4)->STA_END);
						printf("\t            ");
						line(80);
					}
					break;
				}
			case 5:
				{
					strcpy(TRAIN2.STA_START,p_search_strsta());//����ѯ���� 
					strcpy(TRAIN2.STA_END,p_search_endsta());//����ѯ���� 
					n5=search_strendsta(TRAIN2.STA_START,TRAIN2.STA_END,TRAIN3,trainnum);
					if(n5==-1)
					{
						printf("\n\t\tĿǰ���޷��ϸò�ѯ�����ĳ��Σ������²�ѯ��\n");
						fflush(stdin);
						continue;
					}
					else
					{
						printf("\n\t\t\t\t\t\t    ������Ϣ���£�\n");
						printf("\t            ");
						line(80);
						printf("\t\t\t  ���κ�\t�·�\t��\t����ʱ��\t����ʱ��\tʼ��վ\t�յ�վ\n\n");
						printf("\t\t\t  %s\t\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN3+n5)->NUM,(TRAIN3+n5)->MONTH,(TRAIN3+n5)->DAY,
		      				  (TRAIN3+n5)->START,(TRAIN3+n5)->END,(TRAIN3+n5)->STA_START,(TRAIN3+n5)->STA_END);
						printf("\t            ");
						line(80);
					}
					break;
				}
			case 6: return;
			case 7: passenger_man();
					break;
			default:
				{
					printf("��������ȷָ�\n");
					fflush(stdin);
					continue;
				}
		break;
		}
	}

}

 
//���ļ�--train_inf 
void read_w(trains *TRAIN ,int *trainnum) 
{
	int i;
	FILE *fp_b;
	if((fp_b=fopen("train_inf.txt","r"))==NULL)
	{ *trainnum=0;return;}
	for(i=0;!feof(fp_b);i++)
	    if(fread(&TRAIN[i],sizeof(trains),1,fp_b) !=1) break;
	*trainnum=i;
	fclose(fp_b); 
 }	 

//��ѯ--���� 
char* p_search_num(void)
{
	int status;
	char NUM[10];
	printf("\n\t\t\t���Σ�");//�����ѯ��Ϣ 
	while(1)
	{
		status=scanf("%s",NUM);
		if(status==0)
		{
			system("cls"); 
			printf("\n\t\t��������ȷ�ĳ��Σ�");
			fflush(stdin);
			continue;
		}
		else break;
	}	
	return NUM;
}

//��ѯ--�·� 
char* p_search_month(void)
{
	int status;
	char MONTH[10];
	printf("\n\t\t\t�·�/�£�������1-12�·����֣���");  // һ��Ҫ����������Ԥ�� �����ϣ�������1-12�·����֣���������ʾ 
	while(1)
	{
		status=scanf("%s",MONTH);
		
		int i=0,month_to_digi=0,flag=1;
		while(MONTH[i]!='\0')
		   {
		   	if  (!isdigit(MONTH[i]))  
		    	{
			    printf("\n\t\t�벻Ҫ�����������ţ�����������1-12�·�����:");
				flag=0; 
		        break;
		    	}
		    month_to_digi = month_to_digi*10+ ( MONTH[i]-48);    //��MONTHת��������    //"0"�� ASCII����48,���ַ����ĵ�һ�����ֿ�ʼһ��һ���ж� 
		    i++;
		   }
		if (flag==0) continue; 
		else if ( month_to_digi>12 )
		       { printf("\n\t\t�������%d�·�>12��" ,month_to_digi); 
			     printf("\n\t\t����������1-12�·�����:");
		         continue;
	           }
		     else break;
	}
	return MONTH;
}

//��ѯ--���� 
char* p_search_day(void)
{
	int status;
	char DAY[10];
	printf("\n\t\t\t����/�գ�������1-31�������֣���");  // һ��Ҫ����������Ԥ�� �����ϣ�������1-12�·����֣���������ʾ 
	while(1)
	{
		status=scanf("%s",DAY);
		int i=0,day_to_digi=0,flag=1;
		while(DAY[i]!='\0')
		   {
		   	if(!isdigit(DAY[i]))   //���������Ҫ��ctype.h������� 
		      { printf("\n\t\t�벻Ҫ�����������ţ�����������1-31��������:");
				flag=0; 
		        break; }
		    day_to_digi = day_to_digi*10+ ( DAY[i]-48);    //��MONTHת��������    //"0"�� ASCII����48,���ַ����ĵ�һ�����ֿ�ʼһ��һ���ж� 
		    i++;
		   }
		if (flag==0) continue; 
		else if(day_to_digi>31 )
		       { printf("\n\t\t�������%d����>31��" ,day_to_digi); 
			     printf("\n\t\t����������1-31��������:");
		         continue; }
		else break;
	}
	return DAY;
 } 

//��ѯ--����ʱ��  
char* p_search_startime(void)
{
	int status;
	char START[10];
	char *s1="24:00";
	char *s2="00:00";
	printf("\n\t\t\t����ʱ�䣨��08��00��18��00�ȣ�:"); 
	while(1)
	{
		fflush(stdin);
		status=scanf("%s",START);
		if((status==0)||(strcmp(START,s1)>0)||(strcmp(START,s2)<0))
		{
			printf("\n\t\t��������ȷ�ĳ���ʱ�䣡");
			fflush(stdin);
			continue;
		}
		else break;
	}
	return START;
}

//��ѯ--��վʱ�� 
char* p_search_endtime(void)
{
	int status;
	char END[10];
	char *s1="24:00";
	char *s2="00:00";
	printf("\n\t\t\t����ʱ�䣺����08��00��18��00�ȣ�");
	while(1)
	{
		fflush(stdin);
		status=scanf("%s",END);
		if((status==0)||(strcmp(END,s1)>0)||(strcmp(END,s2)<0))
		{
			printf("\n\t\t��������ȷ�ĵ������ڣ�");
			fflush(stdin);
			continue;
		}
		else break;
	}
	return END;
}

//��ѯ--ʼ��վ 
char* p_search_strsta(void)
{
	int status;
	char STA_START[30];
	printf("\n\t\t\tʼ��վ��");
	while(1)
	{
		fflush(stdin);
		status=scanf("%s",STA_START);
		if(status==0)
		{	
			printf("\n\t\t��������ȷ��ʼ��վ��");
			continue;
		}
		else break;
	}
	return STA_START;
}

//��ѯ--�յ�վ 
char* p_search_endsta(void)
{
	int status;
	char STA_END[30]; 
	printf("\n\t\t\t����վ��");
	while(1)
	{
		fflush(stdin);
		status=scanf("%s",STA_END);
		if(status==0)
		{
			printf("\n\t\t��������ȷ�ĵ���վ��");
			continue;
		}
		else break;
	}
	return STA_END;
}

//��ѯ--�������� 
int search_num(char *NUM,trains *TRAIN,int n)
{
	int i;
	for(i=0;i<n;i++)
		if(strcmp((TRAIN+i)->NUM,NUM)==0)
		 	return i;
	return -1;    
}

//��ѯ--�·�&��������
int search_monthday(char *MONTH,char *DAY,trains *TRAIN,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(strcmp((TRAIN+i)->MONTH,MONTH)==0)
		{
			if(strcmp((TRAIN+i)->DAY,DAY)==0)    
				return i;
			else break;
		}
	}
	return -1;    
}

//��ѯ--����ʱ������
int search_startime(char *START,trains *TRAIN,int n)
{
	int i;
	for(i=0;i<n;i++)
		if(strcmp((TRAIN+i)->START,START)==0)
		 	return i;
	return -1;    
}

//��ѯ--����ʱ������
int search_endtime(char *END,trains *TRAIN,int n)
{
	int i;
	for(i=0;i<n;i++)
		if(strcmp((TRAIN+i)->END,END)==0)
		 	return i;
	return -1;    
}

//��ѯ--ʼ��վ&�յ�վ����
int search_strendsta(char *STA_START,char *STA_END,trains *TRAIN,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(strcmp((TRAIN+i)->STA_START,STA_START)==0)
		{
			if(strcmp((TRAIN+i)->STA_END,STA_END)==0)
				return i;
			else break;
		}		
	}
	return -1;    
}
