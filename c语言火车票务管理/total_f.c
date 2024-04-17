#include "total_f.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//主菜单 
void main_man(void)
{
	int ch;	
	menu( ); 
	printf("\t\t\t  您的选择是：");
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
				 
		default:printf("\t输入错误！请重新输入！\n\n");
                fflush(stdin);
                main_man( );
				break;
			
	}
	
}

//程序开始界面 
void menu(void)
{
	printf("\t            ");
	line(70);
	printf("\n\t\t\t\t\t\t求真求实，大气大为\n");
	printf("\n\t\t\t\t\t欢迎使用竹子、小冯和黄黄的火车管理系统！  \n\n");
	printf("\t            ");
	line(70);
	printf("\t\t\t  请选择您的身份：\n\n");
	printf("\t\t\t  [A] 工作人员 \t\t[B] 乘客 \t\t[Q] 退出\n");
	printf("\t            ");
	line(70);
 } 

//程序结束页面 
void bye(void)
{
	system("cls");
	printf("\t            ");
	space(5);star(50);
	printf("\n\t\t\t\t\t感谢您使用火车票管理系统!\n\n");
	printf("\t\t\t\t\tby 竹子，黄黄，小冯\n\n");
	printf("\n\t\t\t\t\t特别鸣谢：十分耐心蔡老师\n");
	printf("\n\t\t\t\t\t超级好妈妈豪哥\n");
	printf("\n\t\t\t\t\t热心靠谱小迪哥\n");
	printf("\n\t\t\t\t\t武大某马原爱好者\n");
	printf("\n\t\t\t\t\t福大小白马\n");
	printf("\n\t\t\t\t\t20信管班为我们提供过帮助的同学们\n\n");
	printf("\t            ");
	space(5);star(50);
	exit(0); 
}

//格式--空格 
void space(int n)
{
	int i;
	for(i=1;i<n;i++)
	   printf(" ");
}

//格式--小横线 
void line(int n)
{
	int i;
	for(i=1;i<=n;i++)
	   printf("-"); 
	printf("\n");
}

//格式--星星 
void star(int n)
{
	int i;
	for(i=1;i<=n;i++)
	   printf("*"); 
	printf("\n");
}
