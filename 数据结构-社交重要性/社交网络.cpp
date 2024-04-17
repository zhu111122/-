#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<malloc.h>
#define INFINITY 10000

bool Visited[100];//����ý�㱻���ʣ������ӦֵΪ1����δ��������Ϊ0
int Dist[10000][10000];
int Flag=1;//���Ʊ�־�����ã���ͨ��Ϊ1������ͨ��Ϊ0 

typedef int Vertex; //�ö����±��ʾ���㣬Ϊ����
//�ߵĶ���
typedef struct ENode* Edge;
struct ENode
{
    Vertex V1, V2;
};

//ͼ���Ķ��� 
typedef struct GNode* MGraph;
struct  GNode
{
	int vertex[INFINITY];//Ϊ�˺���������֪����˭����һ������ 
    int G[10000][10000];//�ڽӾ��� 
    int Nv;//������ 
    int Ne;//����
};

int IsEdge(MGraph Gra, Vertex V1, Vertex V2)
{
    return Gra->G[V1][V2]!=INFINITY;//�жϱ��Ƿ���� 
}

void Insert(MGraph Gra, Edge E)//����� 
{
    Gra->G[E->V1][E->V2] = 1;
    Gra->G[E->V2][E->V1] = 1;
}

MGraph CreateGraph(int Nv)//����ͼ 
{
    MGraph Gra = (MGraph)malloc(sizeof(struct GNode));
    Gra->Nv = Nv;
    Gra->Ne = 0;
    for (int i = 1; i <=Gra->Nv; i++)
        for (int j = 1; j <= Gra->Nv; j++)
        {
            Gra->G[i][j] = INFINITY;//��ʼ�� 
            if (i == j)
                Gra->G[i][j] = 0;
        }
    return Gra;
}

void Floyd(MGraph Gra)//���������㷨�����· 
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
                Flag = 0;//����ֱͨ����Ϊ0 
                break;
            }
}

bool matrix_insert_vertex(MGraph Gra, Vertex v)//�����µ����� 
{
	Gra->vertex[Gra->Nv] = v;
    int row,col;//�ڽӾ�������½�㣬������һ��һ�� 
    for(row=0;row<=Gra->Nv;row++)
       Gra->G[row][Gra->Nv]=INFINITY;
    for(col=0;col<=Gra->Nv;col++)
       Gra->G[Gra->Nv][col]=INFINITY; //��ʼ��  
     Gra->Nv++;
return true;
}

void insert_bian(MGraph Gra,Edge E )//�������������������Ѽ�Ĺ�ϵ 
{
	int i;
	int a,b;
	
	printf("\t\t��������˭�й�ϵ��\n");
	scanf("%d",&a);
	E->V1=a;
	E->V2=Gra->Nv;
	Insert(Gra,E);//���ߵ�Ȩ���ɷ���ͨ����Ϊ��ͨ״̬ 
	printf("\t\t%d��%d��֮���Ȩ����:",a,Gra->Nv);
	printf("%d\n\n",Gra->G[E->V1][E->V2]);

}

void Visit(int V)//�ж����ڷ��ʵ�ǰ���ѵ�״̬ 
{
	printf("\t\t���ڷ�������%d\n",V);
}

void research(MGraph Gra,int v)//�������ѵ����� 
{
	int i;
	Visit(v);
	Visited[v]=true;
	for (i=1;i<=Gra->Nv;i++)
	
		if (!Visited[i] && (Gra->G[v][i] < INFINITY))
			
			  {
			   printf("\t\t%d��������%d\n ",v,i);
			   research(Gra,i);//������ȱ����ݹ� 
			   } 
			
}

Vertex most_important (MGraph Gra)//��������Ҫ������ 
{
	int i,j;
	float Cc[Gra->Nv];
	int most_important_man;
	float num;
	Floyd(Gra); 
	int n = Gra->Nv;
	while (n--)		//����ÿһ�����ѵ���Ҫ�� 
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
    for (i = Gra->Nv;i-1 > 0; i--)		//�Ƚ�ÿһ�����ѵ���Ҫ���ҳ�����Ҫ������ ������̨�㷨�� 
    {
    	if (Cc[i-1] >= Cc[i])
    		most_important_man = i;
	}
	return most_important_man;	
}


Vertex need_help (MGraph Gra)//��������Ҫ���������� 
{
	int i,j;
	float Cc[Gra->Nv];
	int need_help_man;
	float num;
	Floyd(Gra); 
	int n = Gra->Nv;
	while (n--)		//����ÿһ�����ѵ���Ҫ�� 
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
    for (i = Gra->Nv;i > 0; i--)		//�Ƚ�ÿһ�����ѵ���Ҫ���ҳ�����Ҫ���������� ������̨�㷨�� 
    {
    	if (Cc[i-1] <= Cc[i])
    		need_help_man = i;
	}
	return need_help_man;	
}



void menu(MGraph Gra,Edge E)//�˵� ����ͬѡ�����ͬ���� 
{
	int research(MGraph Gra,int v);
	int choice;
	int i,n,m,K;
	Vertex f1,f2;
	float num=0;
	int Cc[10000];
	system("cls"); 
	printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
	printf("\t\t\t     * �� ӭ �� �� �� �� Ȧ ��*\n\n\n\t\t  1)���������� \t\t\t2)�������� \n\n\t\t  3)��ѯ���ѵ�����\t\t4)˭������Ҫ������\n\n\t\t  5)˭����Ҫ����\t\t6)�˳�\n\n");
	printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			{//������Ҫ�� 
				printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
				printf("\t\t\t����������Ҫ����Ķ�����Ŀ��"); 
		    	scanf("%d", &K);
		        printf("\n\t\t\t����������Ҫ�����K�����㣺"); 
		    	while (K--)
		    	{
		        	num = 0;//�洢�ߵ����� 
		        	int n;
			        scanf("%d", &n);
			        if (Flag)
			        {
			            for (int i = 1; i <= Gra->Nv; i++)
			                num += Dist[n][i];	//����������㵽��������ľ��� 
			            
			            printf("\t\t\t\tCc(%d)=%.2f\n", n, (Gra->Nv - 1) / num);//������Ҫ��
						 
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
         	{//������� 
         		printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
         		printf("\t\t��������Ҫ��������ѣ�");
         		int v;
         		
         		scanf("%d",&v);
         		matrix_insert_vertex(Gra, v);
         		insert_bian(Gra,E );
         		printf("\t\t��ϵ�����ɹ��������Ѿ��������ˣ�\n"); 
    			printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
    			system("pause");
    			menu(Gra,E);
				break;		
			 }
		case 3:
			{//��ѯ���ѵ����� 
				printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
				printf("\t\t������Ҫ��ѯ�����ѣ�\n");
				scanf("%d",&f1);
				research(Gra,f1);
				printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
				system("pause");
				menu(Gra,E);
				break;
			}
		case 4:
			{//��ѯ����Ҫ������ 
				printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
				printf("\t\t\t\t����Ҫ�������ǣ�%d\n\n", most_important(Gra));
				printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
				system("pause");
				menu(Gra,E);
				break;
			}
		case 5:
			{//��ѯ����Ҫ���������� 
				printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
				printf("\t\t\t\t����Ҫ�����������ǣ�%d\n\n",need_help(Gra));
				printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
				system("pause");
				menu(Gra,E);
				break;				
			} 
		case 6:
			{//�˳�ϵͳ 
				printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
				printf("\t\t\t\t\t�ټ���\n\n");
				printf("\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*\n\n");
				system("pause");
				break;
			}

			
	}
}

int main(void)//������ 
{
    int N, M;//�ֱ���������ͱ��� 
    printf("\t\t**   �밴Ҫ�����룬�����һ����Ȩ����ͼ�Լ�ָ�����Ľ������Ķ�   **\n\n");
    printf("\t\t\t    ������һ��������N(N<=10)��ʾͼ�н������");
    scanf("%d", &N);
    printf("\n\t\t\t    ������һ��������M��ʾͼ�б�����");
    scanf("%d",&M);
    MGraph Gra = CreateGraph(N);//ͼ�ĳ�ʼ������ 
    Gra->Ne = M;
    Edge E = (Edge)malloc(sizeof(struct ENode));
    printf("\n\t\t\t�밴��������ı��������ÿ�����ӵĽ�㣬�ո����: ");
    for (int i = 0; i < Gra->Ne; i++)	//��������Ȧ����
    {
        scanf("%d%d", &(E->V1), &(E->V2));
        Insert(Gra, E);
    }
    Floyd(Gra);
    menu(Gra,E);//�˵�ѡ�� 
    
    
    return 0;
}

