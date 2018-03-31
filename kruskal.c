#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

typedef struct Edge
{
	int v1,v2,cost;
}edge;

int getParent(int i,int parent[])
{
	return parent[i]=(i==parent[i]?i:getParent(parent[i],parent));
}

int un_ion(int i,int p,int par[])
{
	par[getParent(i,par)]=getParent(p,par);
}

void sort(edge arr[],int size)
{
	int i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(arr[j].cost>arr[j+1].cost)
			{
				edge temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

int kruskal(edge edges[],int parent[],int size)
{
	int tc=0,i;
	for(i=0;i<size;i++)
	{
		if(getParent(edges[i].v1,parent)!=getParent(edges[i].v2,parent))
		{
			printf("%d-->%d\n",edges[i].v1+1,edges[i].v2+1);
			un_ion(edges[i].v1,edges[i].v2,parent);
			tc+=edges[i].cost;
		}
	}
	return tc;
}

int main()
{
	int n,e,i,j,c,x,y;
	printf("Enter The Number of Nodes & Edges\n");
	scanf("%d %d",&n,&e);
	c=e;
	int parent[n];
	for(i=0;i<n;i++)
	{
		parent[i]=i;
	}
	edge *edges=(edge*)malloc(sizeof(edge)*e);
	printf("Enter the Edges in format [Vertex 1] [Vertex 2] [Cost]\n");
	while(e--)
	{
		scanf("%d %d %d",&edges[e].v1,&edges[e].v2,&edges[e].cost);
		edges[e].v1--;
		edges[e].v2--;
	}
	sort(edges,c);
	printf("Minimum Spanning Cost %d\n",kruskal(edges,parent,c));
}