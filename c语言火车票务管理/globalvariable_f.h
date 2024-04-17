#ifndef GLOBALVARIABLE_H
#define GLOBALVARIABLE_H
#define SIZE 10
#define STARS "************************"
#define N 1000

//定义一个工作人员账号密码的结构体   
typedef struct a_c1
{
	char NAME1[SIZE];		//姓名 
	char ACCOUNT1[SIZE];	//账号 
	char PASSWORD1[SIZE];	//密码 
}a_cs1;
		
//定义一个工乘客账号密码的结构体
typedef struct a_c2
{
	char NAME2[SIZE];		//姓名 
	char ACCOUNT2[SIZE];	//账户 
	char PASSWORD2[SIZE];	//密码 
}a_cs2;

//定义一个车次信息的结构体 
typedef struct train
{           
	char NUM[10];			//车次号 
	char MONTH[10];			//月份 
	char DAY[10];			//日 
	char START[10];			//出发时间 
	char END[10];			//到达时间 
	char STA_START[30];		//始发站 
	char STA_END[30]; 		//终点站 
}trains;

#endif
