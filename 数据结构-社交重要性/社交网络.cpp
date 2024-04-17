#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<malloc.h>
#define INFINITY 10000

bool Visited[100];//如果该结点被访问，数组对应值为1；若未被访问则为0
int Dist[10000][10000];
int Flag=1;//类似标志的作用，连通记为1，非连通记为0 

typedef int Vertex; //用顶点下标表示顶点，为整型
//边的定义
typedef struct ENode* Edge;
struct ENode
{
    Vertex V1, V2;
};

//图结点的定义 
typedef struct GNode* MGraph;
struct  GNode
{
	int vertex[INFINITY];//为了后续插入结点知道是谁设置一个向量 
    int G[10000][10000];//邻接矩阵 
    int Nv;//顶点数 
    int Ne;//边数
};

int IsEdge(MGraph Gra, Vertex V1, Vertex V2)
{
    return Gra->G[V1][V2]!=INFINITY;//判断边是否存在 
}

void Insert(MGraph Gra, Edge E)//插入边 
{
    Gra->G[E->V1][E->V2] = 1;
    Gra->G[E->V2][E->V1] = 1;
}

MGraph CreateGraph(int Nv)//创建图 
{
    MGraph Gra = (MGraph)malloc(sizeof(struct GNode));
    Gra->Nv = Nv;
    Gra->Ne = 0;
    for (int i = 1; i <=Gra->Nv; i++)
        for (int j = 1; j <= Gra->Nv; j++)
        {
            Gra->G[i][j] = INFINITY;//初始化 
            if (i == j)
                Gra->G[i][j] = 0;
        }
    return Gra;
}

void Floyd(MGraph Gra)//弗洛伊德算法求最短路 
{
    int i, j, k;
    for (i = 1; i <= Gra->Nv; i++)
        for (j = 1; j <= Gra->Nv; j++)
            Dist[i][j] = Gra->G[i][j];
    for(k=1;k<=Gra->Nv;k++)
        for( i=1;i<=Gra->Nv;i++)
            for ( j = 1; j <= Gra->Nv; j++)
            {
                if (Dist[i][k] + Dist[k][j] < Dist[i][j])
                    Dist[i][j] = Dist[i][k] + Dist[k][j];
            }
    for (i = 1; i <= Gra->Nv; i++)
        for (j = 1; j <= Gra->Nv; j++)
            if (Dist[i][j] == INFINITY)
            {
                Flag = 0;//不连通直接设为0 
                break;
            }
}

bool matrix_insert_vertex(MGraph Gra, Vertex v)//插入新的朋友 
{
	Gra->vertex[Gra->Nv] = v;
    int row,col;//邻接矩阵插入新结点，即增加一行一列 
    for(row=0;row<=Gra->Nv;row++)
       Gra->G[row][Gra->Nv]=INFINITY;
    for(col=0;col<=Gra->Nv;col++)
       Gra->G[Gra->Nv][col]=INFINITY; //初始化  
     Gra->Nv++;
return true;
}

void insert_bian(MGraph Gra,Edge E )//定义新朋友与其他朋友间的关系 
{
	int i;
	int a,b;
	
	printf("\t\t想让它和谁有关系？\n");
	scanf("%d",&a);
	E->V1=a;
	E->V2=Gra->Nv;
	Insert(Gra,E);//将边的权重由非连通更改为连通状态 
	printf("\t\t%d和%d的之间的权重是:",a,Gra->Nv);
	printf("%d\n\n",Gra->G[E->V1][E->V2]);

}

void Visit(int V)//判断正在访问当前朋友的状态 
{
	printf("\t\t正在访问朋友%d\n",V);
}

void research(MGraph Gra,int v)//访问朋友的朋友 
{
	int i;
	Visit(v);
	Visited[v]=true;
	for (i=1;i<=Gra->Nv;i++)
	
		if (!Visited[i] && (Gra->G[v][i] < INFINITY))
			
			  {
			   printf("\t\t%d的朋友是%d\n ",v,i);
			   research(Gra,i);//深度优先遍历递归 
			   } 
			
}

Vertex most_important (MGraph Gra)//计算最重要的朋友 
{
	int i,j;
	float Cc[Gra->Nv];
	int most_important_man;
	float num;
	Floyd(Gra); 
	int n = Gra->Nv;
	while (n--)		//计算每一个朋友的重要性 
	{
    	num = 0;
            for (i = 1; i <= Gra->Nv; i++)
            {
            	if(Dist[n+1][i] != INFINITY)
            	{
            		num += Dist[n+1][i];  
				 } 
				else
					num += 0;	
			}
		if (num==0)
			Cc[n] = 0;
		else
			Cc[n] = (Gra->Nv - 1) / num;
        } 
    most_important_man = Gra->Nv;
    for (i = Gra->Nv;i-1 > 0; i--)		//比较每一个朋友的重要性找出最重要的朋友 （打擂台算法） 
    {
    	if (Cc[i-1] >= Cc[i])
    		most_important_man = i;
	}
	return most_important_man;	
}


Vertex need_help (MGraph Gra)//计算最需要帮助的朋友 
{
	int i,j;
	float Cc[Gra->Nv];
	int need_help_man;
	float num;
	Floyd(Gra); 
	int n = Gra->Nv;
	while (n--)		//计算每一个朋友的重要性 
	{
    	num = 0;
            for (i = 1; i <= Gra->Nv; i++)
            {
            	if(Dist[n+1][i] != INFINITY)
            	{
            		num += Dist[n+1][i];  
				 } 
				else
					num += 0;	
			}
		if (num==0)
			Cc[n] = 0;
		else
			Cc[n] = (Gra->Nv - 1) / num;
        }
    need_help_man = Gra->Nv;
    for (i = Gra->Nv;i > 0; i--)		//比较每一个朋友的重要性找出最需要帮助的朋友 （打擂台算法） 
    {
    	if (Cc[i-1] <= Cc[i])
    		need_help_man = i;
	}
	return need_help_man;	
}



void menu(MGraph Gra,Edge E)//菜单 ，不同选择代表不同功能 
{
	int research(MGraph Gra,int v);
	int choice;
	int i,n,m,K;
	Vertex f1,f2;
	float num=0;
	int Cc[10000];
	system("cls"); 
	printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
	printf("\t\t\t     * 欢 迎 来 到 朋 友 圈 ！*\n\n\n\t\t  1)计算中心性 \t\t\t2)加入朋友 \n\n\t\t  3)查询朋友的朋友\t\t4)谁是最重要的朋友\n\n\t\t  5)谁最需要帮助\t\t6)退出\n\n");
	printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			{//计算重要性 
				printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
				printf("\t\t\t请输入你想要计算的顶点数目："); 
		    	scanf("%d", &K);
		        printf("\n\t\t\t请输入你想要计算的K个顶点："); 
		    	while (K--)
		    	{
		        	num = 0;//存储边的数量 
		        	int n;
			        scanf("%d", &n);
			        if (Flag)
			        {
			            for (int i = 1; i <= Gra->Nv; i++)
			                num += Dist[n][i];	//计算各个顶点到其他顶点的距离 
			            
			            printf("\t\t\t\tCc(%d)=%.2f\n", n, (Gra->Nv - 1) / num);//计算重要性
						 
			        }
			        else
			            printf("\t\t\t\tCc(%d)=0.00\n", n);
			    }
			    printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
			    system("pause");
			    menu(Gra,E);
			    break;
			}
        case 2:
         	{//添加朋友 
         		printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
         		printf("\t\t请输入你要加入的朋友：");
         		int v;
         		
         		scanf("%d",&v);
         		matrix_insert_vertex(Gra, v);
         		insert_bian(Gra,E );
         		printf("\t\t关系构建成功，你们已经是朋友了！\n"); 
    			printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
    			system("pause");
    			menu(Gra,E);
				break;		
			 }
		case 3:
			{//查询朋友的朋友 
				printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
				printf("\t\t请输入要查询的朋友：\n");
				scanf("%d",&f1);
				research(Gra,f1);
				printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
				system("pause");
				menu(Gra,E);
				break;
			}
		case 4:
			{//查询最重要的朋友 
				printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
				printf("\t\t\t\t最重要的朋友是：%d\n\n", most_important(Gra));
				printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
				system("pause");
				menu(Gra,E);
				break;
			}
		case 5:
			{//查询最需要帮助的朋友 
				printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
				printf("\t\t\t\t最需要帮助的朋友是：%d\n\n",need_help(Gra));
				printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
				system("pause");
				menu(Gra,E);
				break;				
			} 
		case 6:
			{//退出系统 
				printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
				printf("\t\t\t\t\t再见！\n\n");
				printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
				system("pause");
				break;
			}

			
	}
}

int main(void)//主函数 
{
    int N, M;//分别代表结点数和边数 
    printf("\t\t**   请按要求输入，会输出一个无权无向图以及指定结点的紧密中心度   **\n\n");
    printf("\t\t\t    请输入一个正整数N(N<=10)表示图中结点数：");
    scanf("%d", &N);
    printf("\n\t\t\t    请输入一个正整数M表示图中边数：");
    scanf("%d",&M);
    MGraph Gra = CreateGraph(N);//图的初始化操作 
    Gra->Ne = M;
    Edge E = (Edge)malloc(sizeof(struct ENode));
    printf("\n\t\t\t请按照所输入的边数，输出每边连接的结点，空格隔开: ");
    for (int i = 0; i < Gra->Ne; i++)	//构建朋友圈网络
    {
        scanf("%d%d", &(E->V1), &(E->V2));
        Insert(Gra, E);
    }
    Floyd(Gra);
    menu(Gra,E);//菜单选择 
    
    
    return 0;
}

