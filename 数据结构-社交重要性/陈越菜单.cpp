#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define INFINITY 10000
typedef struct ENode* Edge;
typedef int Vertex; 
struct ENode
{
    Vertex V1, V2;
};
typedef struct GNode* MGraph;
struct  GNode
{
    int G[10000][10000];
    int Nv;
    int Ne;
};

int IsEdge(MGraph Gra, Vertex V1, Vertex V2)
{
    return Gra->G[V1][V2]!=INFINITY;
}

void Insert(MGraph Gra, Edge E)
{
    Gra->G[E->V1][E->V2] = 1;
    Gra->G[E->V2][E->V1] = 1;
}

MGraph CreateGraph(int Nv)
{
    MGraph Gra = (MGraph)malloc(sizeof(struct GNode));
    Gra->Nv = Nv;
    Gra->Ne = 0;
    for (int i = 1; i <=Gra->Nv; i++)
        for (int j = 1; j <= Gra->Nv; j++)
        {
            Gra->G[i][j] = INFINITY;
            if (i == j)
                Gra->G[i][j] = 0;
        }
    return Gra;
}

int Dist[10000][10000];
int Flag=1;
void Floyd(MGraph Gra)
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
                Flag = 0;
                break;
            }
}

Vertex most_important (MGraph Gra)
{
	int i,j;
	int Cc[Gra->Ne];
	int most_important_man;
	Floyd(Gra);
	while (Gra->Ne--)
	{
    	int num = 0;
		for (j = 1; j <= Gra->Nv; j++)
        {
        	if (Flag)
        	{
        		for (i = 1; i <= Gra->Nv; i++)
	            	num += Dist[j][i];            		
				Cc[j-1] = (Gra->Nv - 1) / (num/2);
			}
			else
        		Cc[j-1] = 0;
		} 
		
        most_important_man=Cc[0];
        for (i = 0;i < Gra->Ne; i++)
        {
        	if (Cc[i+1] >= Cc[i])
        		most_important_man = i+1;
		}
    }
	return most_important_man;	
}

Vertex need_help (MGraph Gra)
{
	int i,j;
	int Cc[Gra->Ne];
	int need_help_man;
	Floyd(Gra);
	while (Gra->Ne--)
	{
    	int num = 0;
		for (j = 1; j <= Gra->Nv; j++)
        {
        	if (Flag)
        	{
        		for (i = 1; i <= Gra->Nv; i++)
	            	num += Dist[j][i];            		
				Cc[j-1] = (Gra->Nv - 1) / (num/2);
			}
			else
        		Cc[j-1] = 0;
		} 
		
        need_help_man=Cc[0];
        for (i = 0;i < Gra->Ne; i++)
        {
        	if (Cc[i+1] <= Cc[i])
        		need_help_man = i;
		}
    }
	return i+1;	
}

void menu(MGraph Gra)
{
	int research(MGraph Gra,int v);
	int choice;
	int i,n,m,K;
	Vertex f1,f2;
	float num=0;
	int Cc[10000];
	printf("请输入1)计算中心性 2)加入朋友 3)查询朋友4)谁是最重要的朋友5)谁最需要帮助\n\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			{
				printf("请输入你想要计算的顶点数目："); 
		    	scanf("%d", &K);
		        printf("请输入你想要计算的K个顶点："); 
		    	while (K--)
		    	{
		        	num = 0;
		        	int n;
			        scanf("%d", &n);
			        if (Flag)
			        {
			            for (int i = 1; i <= Gra->Nv; i++)
			                num += Dist[n][i];
			            
			            printf("Cc(%d)=%.2f\n", n, (Gra->Nv - 1) / num);
			        }
			        else
			            printf("Cc(%d)=0.00\n", n);
			    }
			    break;
			}
        case 2:
         	{
         		printf("请输入你要加入的朋友：");
         		Edge E=(Edge)malloc(sizeof(struct ENode));
         		while(1)
			    {
			        scanf("%d %d",&(E->V1),&(E->V2));
			        if (1)
			        	Insert(Gra,E);
			        else break;
    			}
				break;		
			 }
		case 3:
			{
				printf("请输入要查询的朋友的朋友：\n");
				scanf("%d",&f1);
				research(Gra,f1);
				break;
			}
		case 4:
			{
				printf("最重要的朋友是：%d", most_important(Gra));
				break;
			}
		case 5:
			{
				printf("最需要帮助的朋友是：%d", need_help(Gra));
				break;				
			} 
			
			
	}
}

void Visit( Vertex f1 )
{
printf("正在访问它的朋友%d\n", f1);
}

research(MGraph Gra, Vertex f1)
{
	int Visited[1000]; 
	Vertex W;
	Visit( f1 ); /* 首先访问当前顶点*/
	Visited[f1] = true;
	for( W=0; W<Gra->Nv || W==f1; W++ )
	/* 当W尚未被访问且与V右边相连*/
		if ( !Visited[W] && (Gra->G[f1][W]<INFINITY) )
			research( Gra, W);
}

int main(void)
{
    int N, M;
    printf("**请按要求输入，会输出一个无权无向图以及指定结点的紧密中心度**\n");
    printf("请输入一个正整数N(N<=10)表示图中结点数：");
    scanf("%d", &N);
    printf("请输入一个正整数M表示图中边数：");
    scanf("%d",&M);
    MGraph Gra = CreateGraph(N);
    Gra->Ne = M;
    Edge E = (Edge)malloc(sizeof(struct ENode));
    printf("请按照所输入的边数，输出每边连接的结点，空格隔开\n");
    for (int i = 0; i < Gra->Ne; i++)
    {
        scanf("%d%d", &(E->V1), &(E->V2));
        Insert(Gra, E);
    }
    Floyd(Gra);
    menu(Gra);
    
    
    return 0;
}

