#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
int *stack,top=0;

void dfs(int i,int *adjlist[],int adjacentedges[],bool visited[],bool first)
{
	int j;
	visited[i]=true;
	for(j=0;j<adjacentedges[i];j++)
	{
		if(!visited[adjlist[i][j]])
		{
			dfs(adjlist[i][j],adjlist,adjacentedges,visited,first);
		}
	}
	if(first)
	{
		stack[top++]=i;
	}
	else
	{
		printf("%d  ",i+1);
	}
}

main()
{
	int n,e,i,j;
	printf("Enter The Number of Vertices & Edges\n");
	scanf("%d %d",&n,&e);
	stack=(int*)malloc(sizeof(int)*n);
	bool visited[n];
	int adjacentedges[n],*adjlist[n],adjacentedges2[n],*adjlist2[n];
	for(i=0;i<n;i++)
	{
		visited[n]=false;
		adjacentedges[i]=adjacentedges2[i]=0;
		adjlist[i]=adjlist2[i]=NULL;
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
		if(adjlist2[j]==NULL || adjacentedges2[j]==0)
		{
			adjlist2[j]=(int*)malloc(sizeof(int)*(adjacentedges2[j]+1));
			adjlist2[j][adjacentedges2[j]]=i;
		}
		else
		{
			adjlist2[j]=(int*)realloc(adjlist2[j],sizeof(int)*(adjacentedges2[j]+1));
			adjlist2[j][adjacentedges2[j]]=i;
		}
		adjacentedges2[j]++;
	}
	for(i=0;i<n;i++)
	{
		visited[i]=false;
	}
	for(i=0;i<n;i++)
	{
		if(!visited[i])
			dfs(i,adjlist,adjacentedges,visited,true);
	}
	for(i=0;i<n;i++)
	{
		visited[i]=false;
	}
	int count=0;
	while(top--)
	{
		if(!visited[stack[top]])
		{
			printf("Scc %d\n",++count);
			dfs(stack[top],adjlist2,adjacentedges2,visited,false);
			printf("\n");
		}
	}
}
