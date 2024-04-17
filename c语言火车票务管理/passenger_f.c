#include "passenger_f.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//乘客登录--主函数
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
			default:printf("请输入正确的指令！\n");
					fflush(stdin); 	
					continue;
		}
	 } 
 } 
 
//乘客登录--主菜单 
void sign_menu(void)
{
	printf("\t            ");
    space(10);star(50);
	printf("\n\t\t\t\t\t您好，欢迎使用乘客端!\n\n");
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

//乘客--信息输入
void sign_in2(void)
{
	printf("\n\t\t\t请输入账号密码：");
	sign_account_in2();
	sign_password_in2();
	passenger_man( );
}

//乘客--账号输入
void sign_account_in2(void) 
{
	int i,j;
	char account[SIZE];
	p2_A_C=&A_C2[0];
	printf("\n\t\t\t账号：");
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
				printf("\n\t\t    账号错误!\n");
				printf("\t\t    请重新输入!\n");
				    sign_account_in2();
			 }
			else continue;
		}
	}
} 

//乘客--密码输入 
int count2=0;
void sign_password_in2(void)
{
	count2++;
	char password[SIZE];
	printf("\n\t\t\t密码：");	
	scanf("%s",&password);
	if((strcmp(password,(p2_A_C-1)->PASSWORD2))!=0)
	{ 
		   printf("\n\t\t    密码错误！\n");
		   printf("\t\t    请重新输入!\n");
		   	if(count2<3)
			 {
			   sign_password_in2();
			 }
			else if(count2==3)
			 {
				printf("三次密码错误，退出登录\n");
				exit(EXIT_FAILURE); 
			 }				
	} 
	else 
	{
		system("cls");
		space(30);star(42);
		printf("\n\t\t\t\t\t  欢迎您,%s！\n\n",(p2_A_C-1)->NAME2);
		space(30);star(42); 
	}
}


//乘客退订票--主函数
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
			case 4: printf("\t\t\t\t注销成功\n"); 
					system("pause"); 
					system("cls");
    				fflush(stdin);
					main_man( );	
					break;
			case 5: system("pause");
			        bye();
			        exit(1);
			        return;
			default:printf("\t\t请输入正确的指令！\n");
					system("cls");
					fflush(stdin); 
					continue;
		}
	}
} 

//乘客退订票--菜单 
void welcome_passenger_menu(void)  
{
	space(12);line(70);
	printf("\t\t\t\t\t    乘客订退票服务  \n");
	space(12);line(70);
	printf("\t\t\t\t  [1] 订  票 \t\t [2] 退    票 \n\n");
	printf("\t\t\t\t  [3] 查  询 \t\t [4] 注销登录 \n\n");
	printf("\t\t\t\t  [5] 退  出 \n");
	space(12);line(70);
	printf("\n\t\t\t您的选择是："); 
}

//读取文件--passenger_b
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

//保存文件--passenger_b 
void p_save(trains *TRAIN ,int k)
{
	int i;
	FILE *fp_p;
	if((fp_p=fopen("passenger_b.txt","a+"))==NULL)
	{ return;}
	fwrite(&TRAIN[k],sizeof(trains),1,fp_p);
	fclose(fp_p); 
 } 

 
//乘客订票系统 
//订票--主函数 
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
					printf("请输入正确指令！");
					continue;
				}
		 }
		passenger_man( );
	 }
} 

//订票--菜单 
void passenger_menu(void)
{
	space(20);line(70);
	printf("\t\t\t\t\t\t乘客订票服务  \n");	
    space(20);line(70);
	printf("\t\t\t\t  [1] 查询车次信息 \t\t [2] 直接订票 \n");
	space(20);line(70);
	printf("\n\t\t\t\t您的选择是："); 
 } 

//分支--直接定票 
void p_order(trains *TRAIN2 ,int *n) 
{
	//先把文件中的车次信息重新存入结构体数组TRAIN1;
	int i,trainnum; 
	trains TRAIN1[N]; 
	FILE *fp_a;
	
	if((fp_a=fopen("train_inf.txt","r"))==NULL)
	{ trainnum=0;return;}
	for(i=0;!feof(fp_a);i++)
	    if(fread(&TRAIN1[i],sizeof(trains),1,fp_a) !=1) break;
	trainnum=i;
	fclose(fp_a); 
				     
    //根据乘客输入的车次序号把结构体中的相应一条数据存入到新文件中 
	int j,k,h,ret;
	char NUM[10]; 	
	
	printf("\n\t请输入您想订的车次序号：");
	scanf("%s",NUM);
	system("cls");
	k=search1(NUM,TRAIN1,trainnum); 
	if(k==-1) 
	{
		printf("\t\t该车次不存在\n");
		system("pause");
	}
	else
	{		
		printf("\n\t车次信息如下：\n"); 
		line(80);
		printf("\t车次号\t月份\t日\t出发时间\t到达时间\t始发站\t终点站\n");
		printf("\t%s\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN1+k)->NUM,(TRAIN1+k)->MONTH,(TRAIN1+k)->DAY,
		      (TRAIN1+k)->START,(TRAIN1+k)->END,(TRAIN1+k)->STA_START,(TRAIN1+k)->STA_END);
		line(80);
		printf("\t您确定购买吗？\n\n");
		printf("\t[1] 是 \t[2] 否\n"); 
		line(50); 
		printf("\n\t您的选择是：");
		scanf("%d",&h);
		if(h==1)
		{   
		    TRAIN2[k]=TRAIN1[k];
			p_save(TRAIN2,k);
			fflush(stdin);
			printf("\n\t订购成功！\n");
			system("pause");
			system("cls");	
		}  
	} 
}

//订票--搜索车次号 
int search1(char *NUM,trains *TRAIN,int n)
{
	int i;
	for(i=0;i<n;i++)
		if(strcmp((TRAIN+i)->NUM,NUM)==0) 
		 	return i;
	return -1;
}


//乘客退票系统 
void passenger_return(trains *TRAIN5 ,int *n)
{
	//先把文件中的车次信息重新存入结构体数组TRAIN1;
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
    printf("\t\t\t\t\t\t已订购车次信息：\n");
	printf("\t            ");	
    line(80);
	printf("\t\t\t 车次号\t月份\t日\t出发时间\t到达时间\t始发站\t终点站\n");
	for(i=0;i<ordernum;i++)
	   printf("\t\t\t %s\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN4+i)->NUM,(TRAIN4+i)->MONTH,(TRAIN4+i)->DAY,
		      (TRAIN4+i)->START,(TRAIN4+i)->END,(TRAIN4+i)->STA_START,(TRAIN4+i)->STA_END);
	printf("\t            ");	
	line(80);
	
    //根据乘客输入的车次序号把结构体中的相应一条数据存入到新文件中 
	int j,k,h,ret;
	char NUM[10]; 	

	printf("\n\t请输入您想退订的车次序号：");
	scanf("%s",NUM);
	k=search2(NUM,TRAIN4,ordernum);
	
	if(k==-1) 
	{
		printf("\t\t该车次不存在\n");
		system("pause");
	}
	else
	{
		printf("\t\t\t\t\t\t车次信息如下：\n");
	    printf("\t            ");
		line(80);
		printf("\t\t\t 车次号\t月份\t日\t出发时间\t到达时间\t始发站\t终点站\n");
		printf("\t\t\t\t    %s\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN4+k)->NUM,(TRAIN4+k)->MONTH,(TRAIN4+k)->DAY,
		      (TRAIN4+k)->START,(TRAIN4+k)->END,(TRAIN4+k)->STA_START,(TRAIN4+k)->STA_END);
	    printf("\t            ");
		line(80);
		printf("\t\t\t  您确定退订吗？\n\n");
		printf("\t\t\t  [1] 是 \t[2] 否\n"); 
		printf("\t            ");	
		line(70); 
		printf("\n\t您的选择是：");
		scanf("%d",&h);
		if(h==1)
		{   
		    TRAIN5=TRAIN4; 
			FILE *fp_b=fopen("passenger_b.txt","w+");
			passenger_ret_del(TRAIN5,ordernum,k);
			p1_save(TRAIN5,ordernum);
			fflush(stdin); 
			printf("\n\t退订成功!\n");
			system("pause");
		}  
	} 
} 

//退票--保存文件 
void p1_save(trains *TRAIN ,int n)
{
	int i;
	FILE *fp;
	if((fp=fopen("passenger_b.txt","w"))==NULL)
	{ 	
		printf("车次信息保存失败……\n");
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

//退票--删除车次 
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

//退票--搜索车次号
int search2(char *NUM,trains *TRAIN,int n) 
{
	int i;
	for(i=0;i<n;i++)
		if(strcmp((TRAIN+i)->NUM,NUM)==0)
		 	return i;
	return -1;    
}


//乘客查询系统 
void passenger_search(void)
{
	int ordernum;
	trains TRAIN1[N];
	FILE *fp_b;
	if((fp_b=fopen("passenger_b.txt","r"))==NULL)
	{ 	
		star(70);
		printf("\n\n\t--目前暂无已订车票--\n");
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
		printf("\t\t\t\t\t\t目前已定车票：\n");
		space(20);line(80);
		printf("\t\t\t车次号\t月份\t日\t出发时间\t到达时间\t始发站\t终点站\n");
		for(i=0;i<ordernum;i++)
		   printf("\t\t\t%s\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN1+i)->NUM,(TRAIN1+i)->MONTH,(TRAIN1+i)->DAY,
		      (TRAIN1+i)->START,(TRAIN1+i)->END,(TRAIN1+i)->STA_START,(TRAIN1+i)->STA_END);
	    space(20);line(80);
	}
}

//读文件--查询已订车票
void read_p(trains *TRAIN2 ,int *ordernum) 
{
	int i;
	FILE *fp_b;
	if((fp_b=fopen("passenger_b.txt","rb+"))==NULL)
	{ 	*ordernum=0;
		printf("\t--目前暂无已订车票！--\n"); 
		return;}
	for(i=0;!feof(fp_b);i++)
	{
	    if(fread(&TRAIN2[i],sizeof(trains),1,fp_b) ==1) 
	    {
			printf("\n\t目前已订购%d张车票：\n"); 
			line(80);
			printf("\t车次号\t月份\t日\t出发时间\t到达时间\t始发站\t终点站\n");
			printf("\t%s\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN2+i)->NUM,(TRAIN2+i)->MONTH,(TRAIN2+i)->DAY,
		      	(TRAIN2+i)->START,(TRAIN2+i)->END,(TRAIN2+i)->STA_START,(TRAIN2+i)->STA_END);
			line(80);
		} 
		else continue;
	}
	*ordernum=i;
	fclose(fp_b); 
 } 


//分支--查询车次(菜单) 
void p_search_menu(void)
{
	printf("\n");
	space(32);star(50);
	printf("\n\t\t\t\t\t\t    车次查询  \n");
	space(20);line(80);
	printf("\t\t\t\t   [1] 车次序号 \t\t [2] 发车日期 \n\n");
	printf("\t\t\t\t   [3] 发车时间 \t\t [4] 到达时间 \n\n");
	printf("\t\t\t\t   [5] 起 始 站 \t\t [6] 进入订票 \n\n");
	printf("\t\t\t\t   [7] 返    回 \n");
	space(20);line(80);
	printf("\n\t\t\t请选择您需要查询的项目序号："); 
}

//分支--查询车次(主函数) 
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
					strcpy(TRAIN2.NUM,p_search_num());//把查询条件赋给train1.num 
					n1=search_num(TRAIN2.NUM,TRAIN3,trainnum);
					if(n1==-1)
					{
						printf("\n\t\t目前暂无符合该查询条件的车次！请重新查询！\n");
						fflush(stdin);
						continue;
					}
					else
					{
					
						printf("\n\t\t\t\t\t\t    车次信息如下：\n");
						printf("\t            ");
						line(80);
						printf("\t\t\t  车次号\t月份\t日\t出发时间\t到达时间\t始发站\t终点站\n\n");
						printf("\t\t\t  %s\t\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN3+n1)->NUM,(TRAIN3+n1)->MONTH,(TRAIN3+n1)->DAY,
		      				  (TRAIN3+n1)->START,(TRAIN3+n1)->END,(TRAIN3+n1)->STA_START,(TRAIN3+n1)->STA_END);
						printf("\t            ");
						line(80);
					}
					break;
				}
			case 2://查询月份与日期 
				{
					strcpy(TRAIN2.MONTH,p_search_month());//把查询条件赋给TRAIN1.MONTH 
					strcpy(TRAIN2.DAY,p_search_day());//赋查询条件 
					n2=search_monthday(TRAIN2.MONTH,TRAIN2.DAY,TRAIN3,trainnum);
					if(n2==-1)
					{
						printf("\n\t\t目前暂无符合该查询条件的车次！请重新查询！\n");
						fflush(stdin);
						continue;
					}
					else
					{
						printf("\n\t\t\t\t\t\t    车次信息如下：\n");
						printf("\t            ");
						line(80);
						printf("\t\t\t  车次号\t月份\t日\t出发时间\t到达时间\t始发站\t终点站\n\n");
						printf("\t\t\t  %s\t\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN3+n2)->NUM,(TRAIN3+n2)->MONTH,(TRAIN3+n2)->DAY,
		      				  (TRAIN3+n2)->START,(TRAIN3+n2)->END,(TRAIN3+n2)->STA_START,(TRAIN3+n2)->STA_END);
						printf("\t            ");
						line(80);
					}
					break;
				}
			case 3: 
				{
					strcpy(TRAIN2.START,p_search_startime());//赋查询条件 
					n3=search_startime(TRAIN2.START,TRAIN3,trainnum);
					if(n3==-1)
					{
						printf("\n\t\t目前暂无符合该查询条件的车次！请重新查询！\n");
						fflush(stdin);
						continue;
					}
					else
					{
						printf("\n\t\t\t\t\t\t    车次信息如下：\n");
						printf("\t            ");
						line(80);
						printf("\t\t\t  车次号\t月份\t日\t出发时间\t到达时间\t始发站\t终点站\n\n");
						printf("\t\t\t  %s\t\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN3+n3)->NUM,(TRAIN3+n3)->MONTH,(TRAIN3+n3)->DAY,
		      				  (TRAIN3+n3)->START,(TRAIN3+n3)->END,(TRAIN3+n3)->STA_START,(TRAIN3+n3)->STA_END);
						printf("\t            ");
						line(80);
					}
					break;
				}
			case 4:
				{
					strcpy(TRAIN2.END,p_search_endtime());//赋查询条件 
					n4=search_endtime(TRAIN2.END,TRAIN3,trainnum);
					if(n4==-1)
					{
						printf("\n\t\t目前暂无符合该查询条件的车次！请重新查询！\n");
						fflush(stdin);
						continue;
					}
					else
					{
						printf("\n\t\t\t\t\t\t    车次信息如下：\n");
						printf("\t            ");
						line(80);
						printf("\t\t\t  车次号\t月份\t日\t出发时间\t到达时间\t始发站\t终点站\n\n");
						printf("\t\t\t  %s\t\t%s\t%s\t%s\t\t%s\t\t%s\t%s\n",(TRAIN3+n4)->NUM,(TRAIN3+n4)->MONTH,(TRAIN3+n4)->DAY,
		      				  (TRAIN3+n4)->START,(TRAIN3+n4)->END,(TRAIN3+n4)->STA_START,(TRAIN3+n4)->STA_END);
						printf("\t            ");
						line(80);
					}
					break;
				}
			case 5:
				{
					strcpy(TRAIN2.STA_START,p_search_strsta());//赋查询条件 
					strcpy(TRAIN2.STA_END,p_search_endsta());//赋查询条件 
					n5=search_strendsta(TRAIN2.STA_START,TRAIN2.STA_END,TRAIN3,trainnum);
					if(n5==-1)
					{
						printf("\n\t\t目前暂无符合该查询条件的车次！请重新查询！\n");
						fflush(stdin);
						continue;
					}
					else
					{
						printf("\n\t\t\t\t\t\t    车次信息如下：\n");
						printf("\t            ");
						line(80);
						printf("\t\t\t  车次号\t月份\t日\t出发时间\t到达时间\t始发站\t终点站\n\n");
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
					printf("请输入正确指令！\n");
					fflush(stdin);
					continue;
				}
		break;
		}
	}

}

 
//读文件--train_inf 
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

//查询--车次 
char* p_search_num(void)
{
	int status;
	char NUM[10];
	printf("\n\t\t\t车次：");//键入查询信息 
	while(1)
	{
		status=scanf("%s",NUM);
		if(status==0)
		{
			system("cls"); 
			printf("\n\t\t请输入正确的车次！");
			fflush(stdin);
			continue;
		}
		else break;
	}	
	return NUM;
}

//查询--月份 
char* p_search_month(void)
{
	int status;
	char MONTH[10];
	printf("\n\t\t\t月份/月（请输入1-12月份数字）：");  // 一定要有事先提醒预防 ，加上（请输入1-12月份数字）这样的提示 
	while(1)
	{
		status=scanf("%s",MONTH);
		
		int i=0,month_to_digi=0,flag=1;
		while(MONTH[i]!='\0')
		   {
		   	if  (!isdigit(MONTH[i]))  
		    	{
			    printf("\n\t\t请不要输入其他符号！请重新输入1-12月份数字:");
				flag=0; 
		        break;
		    	}
		    month_to_digi = month_to_digi*10+ ( MONTH[i]-48);    //将MONTH转换成数字    //"0"的 ASCII码是48,从字符串的第一个数字开始一个一个判断 
		    i++;
		   }
		if (flag==0) continue; 
		else if ( month_to_digi>12 )
		       { printf("\n\t\t你输入的%d月份>12！" ,month_to_digi); 
			     printf("\n\t\t请重新输入1-12月份数字:");
		         continue;
	           }
		     else break;
	}
	return MONTH;
}

//查询--日期 
char* p_search_day(void)
{
	int status;
	char DAY[10];
	printf("\n\t\t\t日期/日（请输入1-31日期数字）：");  // 一定要有事先提醒预防 ，加上（请输入1-12月份数字）这样的提示 
	while(1)
	{
		status=scanf("%s",DAY);
		int i=0,day_to_digi=0,flag=1;
		while(DAY[i]!='\0')
		   {
		   	if(!isdigit(DAY[i]))   //这个函数需要将ctype.h加入进来 
		      { printf("\n\t\t请不要输入其他符号！请重新输入1-31日期数字:");
				flag=0; 
		        break; }
		    day_to_digi = day_to_digi*10+ ( DAY[i]-48);    //将MONTH转换成数字    //"0"的 ASCII码是48,从字符串的第一个数字开始一个一个判断 
		    i++;
		   }
		if (flag==0) continue; 
		else if(day_to_digi>31 )
		       { printf("\n\t\t你输入的%d天数>31！" ,day_to_digi); 
			     printf("\n\t\t请重新输入1-31日期数字:");
		         continue; }
		else break;
	}
	return DAY;
 } 

//查询--发车时间  
char* p_search_startime(void)
{
	int status;
	char START[10];
	char *s1="24:00";
	char *s2="00:00";
	printf("\n\t\t\t出发时间（如08：00，18：00等）:"); 
	while(1)
	{
		fflush(stdin);
		status=scanf("%s",START);
		if((status==0)||(strcmp(START,s1)>0)||(strcmp(START,s2)<0))
		{
			printf("\n\t\t请输入正确的出发时间！");
			fflush(stdin);
			continue;
		}
		else break;
	}
	return START;
}

//查询--到站时间 
char* p_search_endtime(void)
{
	int status;
	char END[10];
	char *s1="24:00";
	char *s2="00:00";
	printf("\n\t\t\t到达时间：（如08：00，18：00等）");
	while(1)
	{
		fflush(stdin);
		status=scanf("%s",END);
		if((status==0)||(strcmp(END,s1)>0)||(strcmp(END,s2)<0))
		{
			printf("\n\t\t请输入正确的到达日期！");
			fflush(stdin);
			continue;
		}
		else break;
	}
	return END;
}

//查询--始发站 
char* p_search_strsta(void)
{
	int status;
	char STA_START[30];
	printf("\n\t\t\t始发站：");
	while(1)
	{
		fflush(stdin);
		status=scanf("%s",STA_START);
		if(status==0)
		{	
			printf("\n\t\t请输入正确的始发站！");
			continue;
		}
		else break;
	}
	return STA_START;
}

//查询--终点站 
char* p_search_endsta(void)
{
	int status;
	char STA_END[30]; 
	printf("\n\t\t\t到达站：");
	while(1)
	{
		fflush(stdin);
		status=scanf("%s",STA_END);
		if(status==0)
		{
			printf("\n\t\t请输入正确的到达站！");
			continue;
		}
		else break;
	}
	return STA_END;
}

//查询--车次搜索 
int search_num(char *NUM,trains *TRAIN,int n)
{
	int i;
	for(i=0;i<n;i++)
		if(strcmp((TRAIN+i)->NUM,NUM)==0)
		 	return i;
	return -1;    
}

//查询--月份&日期搜索
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

//查询--出发时间搜索
int search_startime(char *START,trains *TRAIN,int n)
{
	int i;
	for(i=0;i<n;i++)
		if(strcmp((TRAIN+i)->START,START)==0)
		 	return i;
	return -1;    
}

//查询--到达时间搜索
int search_endtime(char *END,trains *TRAIN,int n)
{
	int i;
	for(i=0;i<n;i++)
		if(strcmp((TRAIN+i)->END,END)==0)
		 	return i;
	return -1;    
}

//查询--始发站&终点站搜索
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
