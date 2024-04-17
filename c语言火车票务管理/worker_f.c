#include "worker_f.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//工作人员登录--主函数
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
		default:printf("请输入正确的指令！\n");
				system("cls");
				fflush(stdin); 	
	}
 } 

//工作人员登录--主菜单
void  w_sign_menu(void)
{
	printf("\t            ");
    space(10);star(50);
	printf("\n\t\t\t\t\t您好，欢迎使用工作人员端!\n\n");
	printf("\t            ");	
	space(10);star(50);
	printf("\t            ");	
	line(70);
    printf("\t\t\t请选择：\n\n");
	printf("\t\t\t[1] 登录 \t\t[2] 返回 \t\t[3] 退出\n");
	printf("\t            ");	
	line(70);
	printf("\n\t\t\t您的选择是："); 
}

//工作人员--账号密码输入主函数 
void sign_in1(void)
{
	printf("\n\t\t\t请输入账号密码：");
	sign_account_in1();
	sign_password_in1();
	worker_man( );
}

//工作人员账号输入 
void sign_account_in1(void)
{
	int i,j,sum2;
	char account[SIZE];
	p1_A_C=&A_C1[0];
	
	printf("\n\t\t\t账号：");
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
				printf("\n\t\t    账号错误!\n");
				printf("\t\t    请重新输入!\n");
				sign_account_in1();
			 }
			else continue;
		}
	}
} 

//工作人员密码输入 
void sign_password_in1(void)
{
	int count1=0;
	count1++;
	char password[SIZE];
	
	printf("\n\t\t\t密码：");
	scanf("%s",&password);
	if((strcmp(password,(p1_A_C-1)->PASSWORD1))!=0)
	{ 
		   printf("\n\t\t    密码错误！\n");
		   printf("\t\t    请重新输入!\n");
		   	if(count1<3)
			 {
			   sign_password_in1();
			 }
			else if(count1==3)
			 {
				printf("三次密码错误，退出登录\n");
				exit(EXIT_FAILURE); 
			 }				
	} 
	else 
	{
		system("cls");
		space(30);star(42); 
	    printf("\n\t\t\t\t\t  欢迎您,%s！\n\n",(p1_A_C-1)->NAME1);
	    space(30);star(42); 
	}
}


//车次管理--主函数 
void worker_man(void)
{
	int n,choice;
	w_read(TRAIN,&n);
	while(1)
	{ 
	  menu1();// 显示车次信息管理主菜单 
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
					printf("\t\t文件保存中…"); 
                    system("cls");
				    system("pause");
				    break;
		
			case 7: printf("\n\t\t\t\t注销成功\n");
					system("pause"); 
					system("cls");
    				fflush(stdin);
					main_man( );
		
			case 8:	system("cls");
					bye( );
					exit(1);
					return;

			default:printf("\t\t请输入正确的指令！\n");
					system("cls");
					fflush(stdin); 
					continue;
		}
	}	
}

//车次管理--主菜单 
void menu1()
{
    space(20);line(70);
	printf("\t\t\t\t\t\t   车次信息管理服务  \n");
    space(20);line(70);
	printf("\t\t\t\t\t  [1]  添加车次\t\t [2]  删除车次 \n\n");
	printf("\t\t\t\t\t  [3]  修改车次\t\t [4]  查询车次 \n\n");
	printf("\t\t\t\t\t  [5]  统计分析\t\t [6]  保    存 \n\n");
	printf("\t\t\t\t\t  [7]  注销登录\t\t [8]  退    出 \n");
	space(20);line(70);
	printf("\n\t\t\t\t您的选择是："); 
}

//读文件--train_inf.txt 
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

//存文件--train_inf.txt
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

//添加车次信息 
void train_add(trains *TRAIN ,int *n)
{
	int i,m;
	system("cls");
	printf("\t            ");	
	line(70);
	printf("\n\t\t\t请输入要添加的车次数量:");
	scanf("%d",&m);
	for( i=*n ; i<m+(*n) ; i++ )
	{ 
	  system("cls");
	  printf("\t            ");
	  line(70);
	  
	  // 1 输入车次号  
	  printf("\n\t\t\t输入第%d个车次号\n\t\t（形如“G\\T\\K1301”）：",i+1);status1=scanf("%9s",(TRAIN+i)->NUM);
	        {
	        	while ((status1==0) || (((TRAIN+i)->NUM[0])!='G') && ((TRAIN+i)->NUM[0])!='T' && ((TRAIN+i)->NUM[0])!='K')
                    {
                      printf("请输入正确的车次号！");
                      fflush(stdin);
				      status1=scanf("%9s",(TRAIN+i)->NUM);
					}
			}
			
	  // 2 输入月份 	
	  printf("\t\t\t输入月份：");status2=scanf("%s",(TRAIN+i)->MONTH);
	        {
	        	while((status2==0) || ((atoi((TRAIN+i)->MONTH)) >12) || ((atoi((TRAIN+i)->MONTH)) <1))
	        	    {
                      printf("请输入正确月份！");
                      fflush(stdin);
				      status2=scanf("%9s",(TRAIN+i)->MONTH);	        	    	
				    }
	        }
	        
	  // 3 输入日期 
	  printf("\t\t\t输入日：");status3=scanf("%s",(TRAIN+i)->DAY);
	        {
	        	while((status3==0) || ((atoi((TRAIN+i)->DAY)) >31) || ((atoi((TRAIN+i)->DAY)) <1))
	        	    {
                      printf("请输入正确日期！");
                      fflush(stdin);
				      status3=scanf("%9s",(TRAIN+i)->DAY);	        	    	
				    }
	        }
			
	  // 4 输入出发时间与到达时间 	  
	  printf("\t\t\t输入出发时间：");scanf("%s",(TRAIN+i)->START);
	  printf("\t\t\t输入到达时间：");scanf("%s",(TRAIN+i)->END);
	       	while((atoi((TRAIN+i)->END))<(atoi((TRAIN+i)->START)))
	       	{
			   
                      printf("请输入正确到达时间（到达时间应大于出发时间）！");
                      fflush(stdin);
					  scanf("%s",(TRAIN+i)->END);	       	
		    }
		
	  // 5 输入始发站与终点站 
	  printf("\t\t\t输入始发站：");scanf("%s",(TRAIN+i)->STA_START);
	  printf("\t\t\t输入终点站：");scanf("%s",(TRAIN+i)->STA_END);
	 } 
	 system("cls");
	 *n=*n+m;
}

//删除车次信息 
void train_del(trains *TRAIN,int *n )
{
	int i,k,h;
	char NUM[10];
	
	system("cls");
	train_search(TRAIN,n);
	printf("\n\t\t\t请输入要删除的车次号：");
	scanf("%s",NUM);
	
	k=search(NUM,TRAIN,*n) ;
	if(k==-1) 
	  {
	  	printf("\t\t该车次不存在\n");
	  	system("pause");
	  }
	else
	{ 
		
		printf("\n\t该车次的基本信息:\n\n");
		printf("\t            ");
		line(80);
		printf("\t车次号\t月份\t日\t出发时间\t到达时间\t始发站\t终点站\n");
		printf("\t%s\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN+k)->NUM,(TRAIN+k)->MONTH,(TRAIN+k)->DAY,
		      (TRAIN+k)->START,(TRAIN+k)->END,(TRAIN+k)->STA_START,(TRAIN+k)->STA_END);
		printf("\t            ");
		line(80);
		printf("\t  您确定删除吗？\n\n");
		printf("\t  [1] 是 \t[2] 否\n"); 
		printf("\t            ");
		line(70); 
		printf("\t您的选择是："); 
		scanf("%d",&h);
		if(h==1)
		{
			for(i=k+1;i<*n;i++)
			   TRAIN[i-1]=TRAIN[i];
			(*n)--;
		 } 
	}
}

//修改车次信息
void train_mod(trains *TRAIN,int *n ) 
{
	int i,k,h;
	char NUM[10];
	
	train_search(TRAIN,n);
	
	printf("\n\t请输入要修改的车次号：");
	scanf("%s",NUM);
	
	k=search(NUM,TRAIN,*n) ;
	if(k==-1) 
	  {
	  	printf("\n\t该车次不存在\n");
	  	system("pause");
	  }
	else
	{
		i=k;
		printf("\n\t\t\t\t\t\该车次的基本信息：\n");
	    printf("\t            ");
		line(80);
		printf("\t车次号\t月份\t日\t出发时间\t到达时间\t始发站\t终点站\n");
		printf("\t%s\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN+i)->NUM,(TRAIN+i)->MONTH,(TRAIN+i)->DAY,
		      (TRAIN+i)->START,(TRAIN+i)->END,(TRAIN+i)->STA_START,(TRAIN+i)->STA_END);
	    printf("\t            ");
		line(80);
		printf("\t  您是否进行修改？\n\n");
		printf("\t  [1] 是 \t[2] 否\n\n"); 
	    printf("\t            ");
		line(80);
		printf("\t您的选择是：");
		scanf("%d",&h);		
	    if(h==1) 
	    {
           printf("\t\t\t车次号：");scanf("%s",TRAIN[k].NUM);
           printf("\t\t\t月份：");scanf("%s",TRAIN[k].MONTH);
           printf("\t\t\t日：");scanf("%s",(TRAIN[k]).DAY);
           printf("\t\t\t出发时间：");scanf("%s",(TRAIN[k]).START);
           printf("\t\t\t到达时间：");scanf("%s",(TRAIN[k]).END); 
           printf("\t\t\t始发站：");scanf("%s",(TRAIN[k]).STA_START);
           printf("\t\t终点站：");scanf("%s",(TRAIN[k]).STA_END);		   		             
	 	}
    } 
}	

//查询车次信息 
void train_search(trains *TRAIN,int *n )
{
	int i;
	system("cls");
	line(110);
	if(*n==0)
	  printf("\n\t\t没有可查询的车次信息\n\n");
	else
	{
		printf("\t\t\t\t\t\t车次信息总表\n");
		line(110);
		printf("\t车次号：\t月份：\t\t日：\t\t出发时间：\t到达时间：\t始发站：\t终点站：\n");
	    for(i=0;i<*n;i++)
	       {
				printf("\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\n",(TRAIN+i)->NUM,(TRAIN+i)->MONTH,(TRAIN+i)->DAY,
		       (TRAIN+i)->START,(TRAIN+i)->END,(TRAIN+i)->STA_START,(TRAIN+i)->STA_END);
	       }
	    line(110);
	}
}

//搜索车次信息 
int search(char *NUM,trains *TRAIN,int n)
{
	int i;
	for(i=0;i<n;i++)
	   if(strcmp((TRAIN+i)->NUM,NUM)==0)
	     return i;
	return -1;
} 

//读取乘客订票信息
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
		printf("\n\t\t目前乘客订票情况如下：\n\n");
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
 //统计订票人次
  void w_to_p_statistic(void)
 {
 	int n;	
	line(100);
 	n=w_to_p_read();
 	printf("\n\t\t目前订票人次为 %d 次\n\n",n);
 	if(n>=3)
 	{
 		printf("\t\t当前时段处于出行高峰期，请注意车站秩序维持！\n\n");
	}
	line(100);
 } 
