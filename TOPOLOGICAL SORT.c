#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int hasCycle=0;
void traverse(int i,int visited[],int stack[],int *tp,int* adjlist[],int adjacentedges[],int n)
{
	int j,top;
	visited[i]=1;
	for(j=0;j<adjacentedges[i];j++)
	{
		if(!visited[adjlist[i][j]])
		{
			traverse(adjlist[i][j],visited,stack,tp,adjlist,adjacentedges,n);
		}
		else if(visited[adjlist[i][j]]==1)
		{
			hasCycle=1;
			return;
		}
		if(hasCycle==1)
		{
			return;
		}
	}
	top=*tp;
	stack[++top]=i;
	*tp=top;
	visited[i]=2;
}

void topological(int *adjlist[],int adjacentedges[],int n)
{
	int visited[n];
	int x,i,stack[n],top=-1;
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	for(x=0;x<n;x++)
	{
		if(visited[x]==0)
		traverse(x,visited,stack,&top,adjlist,adjacentedges,n);
	}
	if(hasCycle)
	{
		printf("DAG present in Graph\n");
		return;
	}
	while(top>=0)
	{
		printf("%d ",stack[top--]+1);
	}
	printf("\n");
}

main()
{
	int n,e,i,j;
	printf("Enter The Number of Vertices & Edges\n");
	scanf("%d %d",&n,&e);
	int adjacentedges[n],*adjlist[n];
	for(i=0;i<n;i++)
	{
		adjacentedges[i]=0;
		adjlist[i]=NULL;
	}

	printf("Enter the vertices and Edges in format [Vertex 1] [Vertex 2]\n");
	while(e--)
	{
		scanf("%d %d",&i,&j);
		i--,j--;
		if(adjlist[i]==NULL || adjacentedges[i]==0)
		{
			adjlist[i]=(int*)malloc(sizeof(int)*(adjacentedges[i]+1));
			adjlist[i][adjacentedges[i]]=j;
		}
		else
		{
			adjlist[i]=(int*)realloc(adjlist[i],sizeof(int)*(adjacentedges[i]+1));
			adjlist[i][adjacentedges[i]]=j;
		}
		adjacentedges[i]++;
	}
	topological(adjlist,adjacentedges,n);
}
