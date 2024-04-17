#ifndef PASSENGER_F_H
#define PASSENGER_F_H
#include "globalvariable_f.h" 

a_cs2 A_C2[SIZE]={{"向菜","p1111","1111"},
				  {"冯菜菜","p2222","2222"},
				  {"黄菜菜菜","p3333","3333"}}; 
a_cs2 *p2_A_C;
 
void sign_passenger(void);			//乘客登录--主函数
void sign_menu(void);				//乘客登录--菜单 
void sign_in2(void);				//乘客--信息输入
void sign_account_in2(void);		//乘客--账号输入
void sign_password_in2(void);		//乘客--密码输入


void passenger_man(void);					// 乘客退订票--主函数 
void welcome_passenger_menu(void);			// 乘客退定票--菜单 
void p_read(trains * ,int *);				// 读文件--passenger_b 
void p_save(trains * ,int );				// 保文件--passenger_b 

void passenger_order(void);					// 乘客订票系统--主函数
void passenger_menu(void);					// 乘客订票系统--菜单 
void p_order(trains * ,int *);				// 分支--直接订票
int search1(char * , trains * , int );		// 订票--搜索车次


void passenger_return(trains*,int*);		// 乘客退票系统
void passenger_ret_del(trains* ,int ,int);	// 退票--删除车次 
void p1_save(trains *,int );				// 退票--保存文件 
int search2(char * , trains * , int );		// 退票--搜索车次号

							
void passenger_search(void);				// 乘客查询系统
void read_p(trains* ,int * );				// 读文件--查询已订车票 


void p_search_main(void);					// 分支--查询车次(主函数) 
void p_search_menu(void);					// 分支--查询车次(菜单)
void read_w(trains * ,int * ); 				// 读文件--train_inf 
char* p_search_num(void);					// 查询--车次 
char* p_search_month(void);					// 查询--月份 
char* p_search_day(void);					// 查询--天数 
char* p_search_startime(void);				// 查询--出发时间 
char* p_search_endtime(void);				// 查询--结束时间 
char* p_search_strsta(void);				// 查询--始发站 
char* p_search_endsta(void);				// 查询--终点站 
int search_num(char *,trains *,int );		// 查询--车次搜索
int search_monthday(char *,char *,trains *,int );	// 查询--月份日期搜索 
int search_startime(char *,trains *,int );			// 查询--出发时间搜索
int search_endtime(char *,trains *,int );			// 查询--到达时间搜索
int search_strendsta(char *,char *,trains *,int );	// 查询--起始站搜索

#endif
