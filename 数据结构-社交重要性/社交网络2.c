#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdbool.h>
#define INFINITY 65535
#define MaxVertexNum 1000
typedef int Vertex;
typedef int WeightType;

//�ߵĶ���
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1,V2;
}; 
typedef PtrToENode Edge;

//ͼ���Ķ��� 
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv,Ne;
	WeightType G[MaxVertexNum][MaxVertexNum]; 
};
typedef PtrToGNode MGraph;

bool IsEdge(MGraph Gra, int V1, int V2)
{
    return Gra->G[V1][V2]!=INFINITY;
}

void Insert(MGraph Gra, Edge E)
{
    Gra->G[E->V1][E->V2] = 1;
    Gra->G[E->V2][E->V1] = 1;
}

//����ͼ 
MGraph CreateGraph(int VertexNum)
{
	Vertex V,W;
	MGraph Graph;
	
	Graph = (MGraph)malloc (sizeof(struct GNode));
	Graph->Nv=VertexNum;
	Graph->Ne=0;
	//��ʼ���ڽӾ���
	for (V=0;V<Graph->Nv;V++)
	{
		for(W=0;W<Graph->Nv;W++)
		{
			if(V==W)
				Graph->G[V][W]=0;
			else 
				Graph->G[V][W]=INFINITY;
		}
	 } 
	return Graph;
}

int Dist[MaxVertexNum][MaxVertexNum];
int Flag=1;
void Floyd(MGraph Gra)
{
    Vertex V1, V2, V3;
    for (V1 = 1; V1 <= Gra->Nv; V1++)
        for (V2 = 1; V2 <= Gra->Nv; V2++)
            Dist[V1][V2] = Gra->G[V1][V2];
    for(V3=1;V3<=Gra->Nv;V3++)
        for(V1=1;V2<=Gra->Nv;V3++)
            for (V2 = 1; V2 <= Gra->Nv; V2++)
            {
                if (Dist[V1][V3] + Dist[V1][V2] < Dist[V1][V2])
                    Dist[V1][V2] = Dist[V1][V3] + Dist[V3][V2];
            }
    for (V1= 1; V1<= Gra->Nv; V1++)
        for (V2 = 1; V2<= Gra->Nv; V2++)
            if (Dist[V1][V2] == INFINITY)
            {
                Flag = 0;
                break;
            }
}

int main()
{
    int n, m;
    int i;
    float num=0;
    int K;
    
    printf("**�밴Ҫ�����룬�����һ����Ȩ����ͼ�Լ�ָ�����Ľ������Ķ�**\n");
    printf("������һ��������n(n<=10)��ʾͼ�н������");
    scanf("%d",&n);
    printf("������һ��������m��ʾͼ�н������");
    scanf("%d",&m);
    MGraph Gra = CreateGraph(n);
    Gra->Ne = m;
    Edge E = (Edge)malloc(sizeof(struct ENode));
    printf("�밴��������ı��������ÿ�����ӵĽ�㣬�ո����\n");
    for (i=0;i<Gra->Ne;i++)
    {
        scanf("%d%d",&(E->V1),&(E->V2));
        Insert(Gra,E);
    }
    Floyd(Gra);
    printf("����������Ҫ����Ķ�����Ŀ��");
    scanf("%d", &K);
    printf("����������Ҫ����Ķ��㣺"); 
      while (K--)
    {
        num = 0;
        int N;
        Vertex v;
        scanf("%d", &N);
        if (Flag)
        {
            for (i = 1; i <= Gra->Nv; i++)
                num += Dist[N][i];
            printf("Cc(%d)=%.2f\n", N, (Gra->Nv - 1) / num);
        }
        else
            printf("Cc(%d)=0.00\n", N);
    }
    return 0;
}
