#include<stdio.h>
#include<stdlib.h>
#define minimum(a,b) a<b?a:b
int V=6;
int **tcoe;

int noLoop(int par[],int curr,int i)
{
	while(par[curr]!=-1)
	{
		if(par[curr]==i)
			return 0;
		curr=par[curr];
	}
	return 1;
}

int bfs(int adjmtx[][6],int source,int sink,int par[],int cost[])
{
	int queue[36],top=0,front=0;
	queue[top++]=source;
	while(front!=top)
	{
		int i,curr=queue[front++];
		if(curr==sink)
		{
			return 1;
		}
		for(i=0;i<V;i++)
		{
			if(adjmtx[curr][i]>0 && noLoop(par,curr,i))
			{
				par[i]=curr;
				queue[top++]=i;
				cost[i]=adjmtx[curr][i];
			}
		}
	}
	return 0;
}

void forda(int adjmtx[][6],int source,int sink)
{
	int j,i,par[6]={-1},cost[6]={-1},tc=0;
	while(bfs(adjmtx,source,sink,par,cost))
	{
		int temp=sink,min=100000;
		while(temp!=source)
		{
			min=minimum(min,cost[temp]);
			temp=par[temp];
		}
		tc+=min;
		temp=sink;
		while(temp!=source)
		{
			adjmtx[par[temp]][temp]-=min;
			adjmtx[temp][par[temp]]+=min;
			int ti=temp,tj=par[temp];
			if(ti>tj)
			{
				ti=tj;
				tj=temp;
			}
			tcoe[ti][tj]+=min;
			temp=par[temp];
		}
		for(i=0;i<V;i++)
		{
			cost[i]=par[i]=-1;
		}
		for(i=0;i<V;i++)
		{
			for(j=0;j<V;j++)
			{
				printf("%d ",tcoe[i][j]);
			}
			printf("\n");
		}
		printf("Total Flow %d\n",tc);
	}
}

int main()
{
	int e,i,j,k;
	scanf("%d%d",&V,&e);
	int adjmtx[V][V];
	tcoe=(int**)malloc(sizeof(int*)*V);
	for(i=0;i<V;i++)
	{
		tcoe[i]=(int*)malloc(sizeof(int)*V);
		for(j=0;j<V;j++)
		{
			tcoe[i][j]=adjmtx[i][j]=0;
		}
	}
	while(e--)
	{
		scanf("%d%d%d",&i,&j,&k);
		i--,j--;
		adjmtx[i][j]=k;
	}
	int source,sink;
	scanf("%d%d",&source,&sink);
	forda(adjmtx,source,sink);
}