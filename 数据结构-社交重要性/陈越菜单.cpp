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
	printf("������1)���������� 2)�������� 3)��ѯ����4)˭������Ҫ������5)˭����Ҫ����\n\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			{
				printf("����������Ҫ����Ķ�����Ŀ��"); 
		    	scanf("%d", &K);
		        printf("����������Ҫ�����K�����㣺"); 
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
         		printf("��������Ҫ��������ѣ�");
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
				printf("������Ҫ��ѯ�����ѵ����ѣ�\n");
				scanf("%d",&f1);
				research(Gra,f1);
				break;
			}
		case 4:
			{
				printf("����Ҫ�������ǣ�%d", most_important(Gra));
				break;
			}
		case 5:
			{
				printf("����Ҫ�����������ǣ�%d", need_help(Gra));
				break;				
			} 
			
			
	}
}

void Visit( Vertex f1 )
{
printf("���ڷ�����������%d\n", f1);
}

research(MGraph Gra, Vertex f1)
{
	int Visited[1000]; 
	Vertex W;
	Visit( f1 ); /* ���ȷ��ʵ�ǰ����*/
	Visited[f1] = true;
	for( W=0; W<Gra->Nv || W==f1; W++ )
	/* ��W��δ����������V�ұ�����*/
		if ( !Visited[W] && (Gra->G[f1][W]<INFINITY) )
			research( Gra, W);
}

int main(void)
{
    int N, M;
    printf("**�밴Ҫ�����룬�����һ����Ȩ����ͼ�Լ�ָ�����Ľ������Ķ�**\n");
    printf("������һ��������N(N<=10)��ʾͼ�н������");
    scanf("%d", &N);
    printf("������һ��������M��ʾͼ�б�����");
    scanf("%d",&M);
    MGraph Gra = CreateGraph(N);
    Gra->Ne = M;
    Edge E = (Edge)malloc(sizeof(struct ENode));
    printf("�밴��������ı��������ÿ�����ӵĽ�㣬�ո����\n");
    for (int i = 0; i < Gra->Ne; i++)
    {
        scanf("%d%d", &(E->V1), &(E->V2));
        Insert(Gra, E);
    }
    Floyd(Gra);
    menu(Gra);
    
    
    return 0;
}

