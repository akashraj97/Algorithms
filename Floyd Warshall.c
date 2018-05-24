#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void print_path(int n,int path[][n],int i,int j)
{
	if(path[i][j]==-1)
	{
		printf("%d ",i+1);
		return;
	}
	if(path[i][j]==i || path[i][j]==j)
	{
		printf("%d ",i+1);
	}
	else{
		print_path(n,path,i,path[i][j]);
		print_path(n,path,path[i][j],j);
	}
}

void floyd(int n,int cost[][n],int *adjlist[],int adjacentedges[],int path[][n])
{
	int i,j,l,z=1;
	while(z)
	{
		z=0;
		for(l=0;l<n;l++)
		{
			for(j=0;j<n;j++)
			{
				for(i=0;i<n;i++)
				{
					if(cost[i][j]>cost[i][l]+cost[l][j] && cost[i][l]!=INT_MAX && cost[l][j]!=INT_MAX)
					{
						cost[i][j]=cost[i][l]+cost[l][j];
						path[i][j]=l;
						z=0;
					}
				}
			}
		}
	}

	printf("Printing Cost Matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d   ",cost[i][j] );
		}
		printf("\n");
	}

	printf("\n\n\n");

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d   ",path[i][j] );
		}
		printf("\n");
	}


	print_path(n,path,0,3);
	printf("4\n" );
}

int main()
{
	int n,i,j,k,e;
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	printf("Enter the number of edges\n");
	scanf("%d",&e);
	int path[n][n],cost[n][n],adjacentedges[n],*adjlist[n];
	for(i=0;i<n;i++)
	{
		adjacentedges[i]=0;
		for(j=0;j<n;j++)
		{
			cost[i][j]=INT_MAX;
			path[i][j]=-1;
			if(i==j)
			{
				cost[i][j]=0;
			}
		}
	}
	while(e--)
	{
		scanf("%d %d %d",&i,&j,&k);
		i--,j--;
		if(adjacentedges[i]==0)
		{
			adjlist[i]=(int*)malloc(sizeof(int*));
		}
		else
		{
			adjlist[i]=(int*)realloc(adjlist[i],sizeof(int*)*(adjacentedges[i]+1));
		}
		adjlist[i][adjacentedges[i]++]=j;
		cost[i][j]=k;
		path[j][i]=i;
	}
	floyd(n,cost,adjlist,adjacentedges,path);
	return 0;
}