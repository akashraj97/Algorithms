#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void  bellman(int i,int adjacentedges[],int *adjlist[],int cost[],int par[])
{
	int j;
	static int depth=0;
	depth++;
	if(depth==1)
	{
		cost[i]=0;
	}

	for(j=0;j<adjacentedges[i];j++)
	{
		int k=adjlist[i][j];
		
	}

	depth--;
}

main()
{
	int n,e,i,j;
	printf("Enter The Number of Vertices & Edges\n");
	scanf("%d %d",&n,&e);
	int adjacentedges[n],*adjlist[n],cost[n],par[n];
	for(i=0;i<n;i++)
	{
		adjacentedges[i]=0;
		adjlist[i]=NULL;
		cost[i]=INT_MAX;
		par[i]=-1;
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
	bellman(s,adjlist,adjacentedges,cost,par);
}