#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define INIFITY 10000
typedef struct ENode* Edge;
struct ENode
{
    int V1, V2;
};
typedef struct GNode* Graph;
struct  GNode
{
    int G[10000][10000];
    float Nv;
    int Ne;
};

int IsEdge(Graph Gra, int V1, int V2)
{
    return Gra->G[V1][V2]!=INIFITY;
}

void Insert(Graph Gra, Edge E)
{
    Gra->G[E->V1][E->V2] = 1;
    Gra->G[E->V2][E->V1] = 1;
}

Graph CreateGraph(int Nv)
{
    Graph Gra = (Graph)malloc(sizeof(struct GNode));
    Gra->Nv = Nv;
    Gra->Ne = 0;
    for (int i = 1; i <=Gra->Nv; i++)
        for (int j = 1; j <= Gra->Nv; j++)
        {
            Gra->G[i][j] = INIFITY;
            if (i == j)
                Gra->G[i][j] = 0;
        }
    return Gra;
}

int Dist[10000][10000];
int Flag=1;
void Floyd(Graph Gra)
{
    int i, j, k;
    for (i = 1; i <= Gra->Nv; i++)
        for (j = 1; j <= Gra->Nv; j++)
            Dist[i][j] = Gra->G[i][j];
    for(int k=1;k<=Gra->Nv;k++)
        for(int i=1;i<=Gra->Nv;i++)
            for (int j = 1; j <= Gra->Nv; j++)
            {
                if (Dist[i][k] + Dist[k][j] < Dist[i][j])
                    Dist[i][j] = Dist[i][k] + Dist[k][j];
            }
    for (i = 1; i <= Gra->Nv; i++)
        for (j = 1; j <= Gra->Nv; j++)
            if (Dist[i][j] == INIFITY)
            {
                Flag = 0;
                break;
            }
}

int main()
{
    int N, M;
    printf("**请按要求输入，会输出一个无权无向图以及指定结点的紧密中心度**\n");
    printf("请输入一个正整数N(N<=10)表示图中结点数：");
    scanf("%d", &N);
    printf("请输入一个正整数M表示图中结点数：");
    scanf("%d",&M);
    Graph Gra = CreateGraph(N);
    Gra->Ne = M;
    Edge E = (Edge)malloc(sizeof(struct ENode));
    printf("请按照所输入的边数，输出每边连接的结点，空格隔开\n");
    for (int i = 0; i < Gra->Ne; i++)
    {
        scanf("%d%d", &(E->V1), &(E->V2));
        Insert(Gra, E);
    }
    Floyd(Gra);
    float num=0;
    int K;
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
    return 0;
}
