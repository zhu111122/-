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
    printf("**�밴Ҫ�����룬�����һ����Ȩ����ͼ�Լ�ָ�����Ľ������Ķ�**\n");
    printf("������һ��������N(N<=10)��ʾͼ�н������");
    scanf("%d", &N);
    printf("������һ��������M��ʾͼ�н������");
    scanf("%d",&M);
    Graph Gra = CreateGraph(N);
    Gra->Ne = M;
    Edge E = (Edge)malloc(sizeof(struct ENode));
    printf("�밴��������ı��������ÿ�����ӵĽ�㣬�ո����\n");
    for (int i = 0; i < Gra->Ne; i++)
    {
        scanf("%d%d", &(E->V1), &(E->V2));
        Insert(Gra, E);
    }
    Floyd(Gra);
    float num=0;
    int K;
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
    return 0;
}
