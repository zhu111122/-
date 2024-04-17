#ifndef WORKER_F_H
#define WORKER_F_H
#include "globalvariable_f.h"  

a_cs1 A_C1[SIZE]={{"竹子","w1111","1111"},
				  {"小冯","w2222","2222"},
				  {"黄黄","w3333","3333"}};
a_cs1 *p1_A_C;
trains TRAIN[N];
int status1; 
int status2;
int status3;

void w_sign_menu(void);				//工作人员登录--主菜单 
void sign_worker(void);				//工作人员登录--主函数 
void sign_in1(void);				//工作人员--账号密码输入主函数
void sign_account_in1(void);		//工作人员账号输入
void sign_password_in1(void);		//工作人员密码输入

void menu1();                		// 车次管理界面--主菜单 
void worker_man(void);          	// 车次管理--主函数
void w_read(trains *,int * );    	// 读文件--train_inf.txt
void w_save(trains *,int * );    	// 存文件--train_inf.txt
void train_add(trains *,int * );	// 添加车次信息
void train_del(trains *,int * );	// 删除车次信息 
void train_mod(trains *,int * );	// 修改车次信息 
void train_search(trains *,int * );	// 查询车次信息
int search(char *,trains *,int);	// 搜索车次信息 

int w_to_p_read(void);              //读取乘客订票信息 
void w_to_p_statistic(void);        //统计订票人次 
#endif 
