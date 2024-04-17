#include "worker_f.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//������Ա��¼--������
void sign_worker(void)
{
	system("cls");
	int i;
	w_sign_menu( );
	scanf("%d",&i);
	switch(i)
	{
		case 1:	sign_in1( );
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
				system("cls");
				fflush(stdin); 	
	}
 } 

//������Ա��¼--���˵�
void  w_sign_menu(void)
{
	printf("\t            ");
    space(10);star(50);
	printf("\n\t\t\t\t\t���ã���ӭʹ�ù�����Ա��!\n\n");
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

//������Ա--�˺��������������� 
void sign_in1(void)
{
	printf("\n\t\t\t�������˺����룺");
	sign_account_in1();
	sign_password_in1();
	worker_man( );
}

//������Ա�˺����� 
void sign_account_in1(void)
{
	int i,j,sum2;
	char account[SIZE];
	p1_A_C=&A_C1[0];
	
	printf("\n\t\t\t�˺ţ�");
	scanf("%s",&account);
	for(i=0;i<SIZE;i++) 
	{
	    int s=strcmp(account,p1_A_C->ACCOUNT1);
		p1_A_C++;
		if(s==0)  break;
		else 
		{
            if(i==SIZE-1)	
			 {
				printf("\n\t\t    �˺Ŵ���!\n");
				printf("\t\t    ����������!\n");
				sign_account_in1();
			 }
			else continue;
		}
	}
} 

//������Ա�������� 
void sign_password_in1(void)
{
	int count1=0;
	count1++;
	char password[SIZE];
	
	printf("\n\t\t\t���룺");
	scanf("%s",&password);
	if((strcmp(password,(p1_A_C-1)->PASSWORD1))!=0)
	{ 
		   printf("\n\t\t    �������\n");
		   printf("\t\t    ����������!\n");
		   	if(count1<3)
			 {
			   sign_password_in1();
			 }
			else if(count1==3)
			 {
				printf("������������˳���¼\n");
				exit(EXIT_FAILURE); 
			 }				
	} 
	else 
	{
		system("cls");
		space(30);star(42); 
	    printf("\n\t\t\t\t\t  ��ӭ��,%s��\n\n",(p1_A_C-1)->NAME1);
	    space(30);star(42); 
	}
}


//���ι���--������ 
void worker_man(void)
{
	int n,choice;
	w_read(TRAIN,&n);
	while(1)
	{ 
	  menu1();// ��ʾ������Ϣ�������˵� 
	  scanf("%d",&choice);
	  switch(choice)
		{
			case 1:	train_add(TRAIN,&n);
			    	system("cls");					
					fflush(stdin);
					break;
				
			case 2:train_del(TRAIN,&n);
					system("cls");                   
					fflush(stdin);                   
					break;
			
			case 3:	train_mod(TRAIN,&n);
			    	system("cls");					
					fflush(stdin);					
					break;
			
			case 4: train_search(TRAIN,&n);					
					fflush(stdin);					
					break; 

			case 5: w_to_p_statistic( ); 
					break;	
					
			case 6: w_save(TRAIN,&n);
					printf("\t\t�ļ������С�"); 
                    system("cls");
				    system("pause");
				    break;
		
			case 7: printf("\n\t\t\t\tע���ɹ�\n");
					system("pause"); 
					system("cls");
    				fflush(stdin);
					main_man( );
		
			case 8:	system("cls");
					bye( );
					exit(1);
					return;

			default:printf("\t\t��������ȷ��ָ�\n");
					system("cls");
					fflush(stdin); 
					continue;
		}
	}	
}

//���ι���--���˵� 
void menu1()
{
    space(20);line(70);
	printf("\t\t\t\t\t\t   ������Ϣ�������  \n");
    space(20);line(70);
	printf("\t\t\t\t\t  [1]  ��ӳ���\t\t [2]  ɾ������ \n\n");
	printf("\t\t\t\t\t  [3]  �޸ĳ���\t\t [4]  ��ѯ���� \n\n");
	printf("\t\t\t\t\t  [5]  ͳ�Ʒ���\t\t [6]  ��    �� \n\n");
	printf("\t\t\t\t\t  [7]  ע����¼\t\t [8]  ��    �� \n");
	space(20);line(70);
	printf("\n\t\t\t\t����ѡ���ǣ�"); 
}

//���ļ�--train_inf.txt 
void w_read(trains *TRAIN ,int *n)
{
	int i;
	FILE *fp;
	if((fp=fopen("train_inf.txt","r"))==NULL)
	{ * n=0;return;}
	for(i=0;!feof(fp);i++)
	    if(fread(&TRAIN[i],sizeof(trains),1,fp) !=1) break;
	*n=i;
	fclose(fp); 
 } 

//���ļ�--train_inf.txt
void w_save(trains *TRAIN ,int *n)
{
	int i;
	FILE *fp;
	if((fp=fopen("train_inf.txt","w"))==NULL)
	{ return;}
	for(i=0;i< *n;i++)
	    if(fwrite(&TRAIN[i],sizeof(trains),1,fp) !=1) break;
	fclose(fp); 
 } 

//��ӳ�����Ϣ 
void train_add(trains *TRAIN ,int *n)
{
	int i,m;
	system("cls");
	printf("\t            ");	
	line(70);
	printf("\n\t\t\t������Ҫ��ӵĳ�������:");
	scanf("%d",&m);
	for( i=*n ; i<m+(*n) ; i++ )
	{ 
	  system("cls");
	  printf("\t            ");
	  line(70);
	  
	  // 1 ���복�κ�  
	  printf("\n\t\t\t�����%d�����κ�\n\t\t�����硰G\\T\\K1301������",i+1);status1=scanf("%9s",(TRAIN+i)->NUM);
	        {
	        	while ((status1==0) || (((TRAIN+i)->NUM[0])!='G') && ((TRAIN+i)->NUM[0])!='T' && ((TRAIN+i)->NUM[0])!='K')
                    {
                      printf("��������ȷ�ĳ��κţ�");
                      fflush(stdin);
				      status1=scanf("%9s",(TRAIN+i)->NUM);
					}
			}
			
	  // 2 �����·� 	
	  printf("\t\t\t�����·ݣ�");status2=scanf("%s",(TRAIN+i)->MONTH);
	        {
	        	while((status2==0) || ((atoi((TRAIN+i)->MONTH)) >12) || ((atoi((TRAIN+i)->MONTH)) <1))
	        	    {
                      printf("��������ȷ�·ݣ�");
                      fflush(stdin);
				      status2=scanf("%9s",(TRAIN+i)->MONTH);	        	    	
				    }
	        }
	        
	  // 3 �������� 
	  printf("\t\t\t�����գ�");status3=scanf("%s",(TRAIN+i)->DAY);
	        {
	        	while((status3==0) || ((atoi((TRAIN+i)->DAY)) >31) || ((atoi((TRAIN+i)->DAY)) <1))
	        	    {
                      printf("��������ȷ���ڣ�");
                      fflush(stdin);
				      status3=scanf("%9s",(TRAIN+i)->DAY);	        	    	
				    }
	        }
			
	  // 4 �������ʱ���뵽��ʱ�� 	  
	  printf("\t\t\t�������ʱ�䣺");scanf("%s",(TRAIN+i)->START);
	  printf("\t\t\t���뵽��ʱ�䣺");scanf("%s",(TRAIN+i)->END);
	       	while((atoi((TRAIN+i)->END))<(atoi((TRAIN+i)->START)))
	       	{
			   
                      printf("��������ȷ����ʱ�䣨����ʱ��Ӧ���ڳ���ʱ�䣩��");
                      fflush(stdin);
					  scanf("%s",(TRAIN+i)->END);	       	
		    }
		
	  // 5 ����ʼ��վ���յ�վ 
	  printf("\t\t\t����ʼ��վ��");scanf("%s",(TRAIN+i)->STA_START);
	  printf("\t\t\t�����յ�վ��");scanf("%s",(TRAIN+i)->STA_END);
	 } 
	 system("cls");
	 *n=*n+m;
}

//ɾ��������Ϣ 
void train_del(trains *TRAIN,int *n )
{
	int i,k,h;
	char NUM[10];
	
	system("cls");
	train_search(TRAIN,n);
	printf("\n\t\t\t������Ҫɾ���ĳ��κţ�");
	scanf("%s",NUM);
	
	k=search(NUM,TRAIN,*n) ;
	if(k==-1) 
	  {
	  	printf("\t\t�ó��β�����\n");
	  	system("pause");
	  }
	else
	{ 
		
		printf("\n\t�ó��εĻ�����Ϣ:\n\n");
		printf("\t            ");
		line(80);
		printf("\t���κ�\t�·�\t��\t����ʱ��\t����ʱ��\tʼ��վ\t�յ�վ\n");
		printf("\t%s\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN+k)->NUM,(TRAIN+k)->MONTH,(TRAIN+k)->DAY,
		      (TRAIN+k)->START,(TRAIN+k)->END,(TRAIN+k)->STA_START,(TRAIN+k)->STA_END);
		printf("\t            ");
		line(80);
		printf("\t  ��ȷ��ɾ����\n\n");
		printf("\t  [1] �� \t[2] ��\n"); 
		printf("\t            ");
		line(70); 
		printf("\t����ѡ���ǣ�"); 
		scanf("%d",&h);
		if(h==1)
		{
			for(i=k+1;i<*n;i++)
			   TRAIN[i-1]=TRAIN[i];
			(*n)--;
		 } 
	}
}

//�޸ĳ�����Ϣ
void train_mod(trains *TRAIN,int *n ) 
{
	int i,k,h;
	char NUM[10];
	
	train_search(TRAIN,n);
	
	printf("\n\t������Ҫ�޸ĵĳ��κţ�");
	scanf("%s",NUM);
	
	k=search(NUM,TRAIN,*n) ;
	if(k==-1) 
	  {
	  	printf("\n\t�ó��β�����\n");
	  	system("pause");
	  }
	else
	{
		i=k;
		printf("\n\t\t\t\t\t\�ó��εĻ�����Ϣ��\n");
	    printf("\t            ");
		line(80);
		printf("\t���κ�\t�·�\t��\t����ʱ��\t����ʱ��\tʼ��վ\t�յ�վ\n");
		printf("\t%s\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN+i)->NUM,(TRAIN+i)->MONTH,(TRAIN+i)->DAY,
		      (TRAIN+i)->START,(TRAIN+i)->END,(TRAIN+i)->STA_START,(TRAIN+i)->STA_END);
	    printf("\t            ");
		line(80);
		printf("\t  ���Ƿ�����޸ģ�\n\n");
		printf("\t  [1] �� \t[2] ��\n\n"); 
	    printf("\t            ");
		line(80);
		printf("\t����ѡ���ǣ�");
		scanf("%d",&h);		
	    if(h==1) 
	    {
           printf("\t\t\t���κţ�");scanf("%s",TRAIN[k].NUM);
           printf("\t\t\t�·ݣ�");scanf("%s",TRAIN[k].MONTH);
           printf("\t\t\t�գ�");scanf("%s",(TRAIN[k]).DAY);
           printf("\t\t\t����ʱ�䣺");scanf("%s",(TRAIN[k]).START);
           printf("\t\t\t����ʱ�䣺");scanf("%s",(TRAIN[k]).END); 
           printf("\t\t\tʼ��վ��");scanf("%s",(TRAIN[k]).STA_START);
           printf("\t\t�յ�վ��");scanf("%s",(TRAIN[k]).STA_END);		   		             
	 	}
    } 
}	

//��ѯ������Ϣ 
void train_search(trains *TRAIN,int *n )
{
	int i;
	system("cls");
	line(110);
	if(*n==0)
	  printf("\n\t\tû�пɲ�ѯ�ĳ�����Ϣ\n\n");
	else
	{
		printf("\t\t\t\t\t\t������Ϣ�ܱ�\n");
		line(110);
		printf("\t���κţ�\t�·ݣ�\t\t�գ�\t\t����ʱ�䣺\t����ʱ�䣺\tʼ��վ��\t�յ�վ��\n");
	    for(i=0;i<*n;i++)
	       {
				printf("\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",(TRAIN+i)->NUM,(TRAIN+i)->MONTH,(TRAIN+i)->DAY,
		       (TRAIN+i)->START,(TRAIN+i)->END,(TRAIN+i)->STA_START,(TRAIN+i)->STA_END);
	       }
	    line(110);
	}
}

//����������Ϣ 
int search(char *NUM,trains *TRAIN,int n)
{
	int i;
	for(i=0;i<n;i++)
	   if(strcmp((TRAIN+i)->NUM,NUM)==0)
	     return i;
	return -1;
} 

//��ȡ�˿Ͷ�Ʊ��Ϣ
int w_to_p_read(void)
{
	trains TRAIN[N];
	FILE *fp;
	int *ordernum;
	if((fp=fopen("passenger_b.txt","r"))==NULL)
		*ordernum=0;
	else
	{
		int i;
		printf("\n\t\tĿǰ�˿Ͷ�Ʊ������£�\n\n");
		for(i=0;!feof(fp);i++)
		{
			if(fread(&TRAIN[i],sizeof(trains),1,fp) !=1) 
			{
				break;
			}		
			printf("\t\t%s\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN+i)->NUM,(TRAIN+i)->MONTH,(TRAIN+i)->DAY,
	      	(TRAIN+i)->START,(TRAIN+i)->END,(TRAIN+i)->STA_START,(TRAIN+i)->STA_END);
		}
		*ordernum=i;
	}
	fclose(fp);
	return *ordernum;
 } 
 //ͳ�ƶ�Ʊ�˴�
  void w_to_p_statistic(void)
 {
 	int n;	
	line(100);
 	n=w_to_p_read();
 	printf("\n\t\tĿǰ��Ʊ�˴�Ϊ %d ��\n\n",n);
 	if(n>=3)
 	{
 		printf("\t\t��ǰʱ�δ��ڳ��и߷��ڣ���ע�⳵վ����ά�֣�\n\n");
	}
	line(100);
 } 
