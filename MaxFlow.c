#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

typedef struct pipe
{
	int s,d,c,r;
}pipe;

int min(int a,int b)
{
	return a<b?a:b;
}

int dfs(int s,int d,bool visited[],int pipecount[],int *pipelist[],pipe pipes[],int ccost)
{
	int i,temp=0;
	visited[s]=true;
	if(s==d)
	{
		visited[s]=false;
		return ccost;
	}
	for(i=0;i<pipecount[s];i++)
	{
		if(pipes[pipelist[s][i]].s!=s && !visited[pipes[pipelist[s][i]].s] && pipes[pipelist[s][i]].r>0)
		{
			temp=dfs(pipes[pipelist[s][i]].s,d,visited,pipecount,pipelist,pipes,min(ccost,pipes[pipelist[s][i]].r));
			pipes[pipelist[s][i]].r-=temp;
		}
		else if(pipes[pipelist[s][i]].s==s && !visited[pipes[pipelist[s][i]].d] && (pipes[pipelist[s][i]].c-pipes[pipelist[s][i]].r)>0)
		{
			temp=dfs(pipes[pipelist[s][i]].d,d,visited,pipecount,pipelist,pipes,min(ccost,(pipes[pipelist[s][i]].c-pipes[pipelist[s][i]].r)));
			pipes[pipelist[s][i]].r+=temp;
		}
		if(temp)
		{
			visited[s]=false;
			return temp;
		}
	}
	visited[s]=false;
	return 0;
}

int ford_fulkerson(int s,int d,int n,int pipecount[],int *pipelist[],pipe pipes[])
{
	int totalflow=0,addflow=1,i;
	bool visited[n];
	for(i=0;i<n;i++)
	{
		visited[i]=false;
	}
	while(addflow)
	{
		addflow=dfs(s,d,visited,pipecount,pipelist,pipes,INT_MAX);
		totalflow+=addflow;
	}
	return totalflow;
}

int main()
{
	int n,e,i,j,k,c,s,d;
	printf("Enter the Number of Vertices & Pipes\n");
	scanf("%d %d",&n,&e);
	int *pipelist[n],pipecount[n];
	pipe pipes[e];
	for(i=0;i<n;i++)
	{
		pipecount[i]=0;
		pipelist[i]=NULL;
	}
	printf("Enter pipes in format [Vertex 1] [Vertex 2] [Capacity]\n");
	for(i=0;i<e;i++)
	{
		scanf("%d %d %d",&j,&k,&c);
		j--,k--;
		pipes[i].s=j;
		pipes[i].d=k;
		pipes[i].c=c;
		pipes[i].r=0;
		if(pipecount[j]==0)
		{
			pipelist[j]=(int*)malloc(sizeof(int)*(++pipecount[j]));
		}
		else
		{
			pipelist[j]=(int*)realloc(pipelist[j],sizeof(int)*(++pipecount[j]));
		}
		pipelist[j][pipecount[j]-1]=i;
		if(pipecount[k]==0)
		{
			pipelist[k]=(int*)malloc(sizeof(int)*(++pipecount[k]));
		}
		else
		{
			pipelist[k]=(int*)realloc(pipelist[k],sizeof(int)*(++pipecount[k]));
		}
		pipelist[k][pipecount[k]-1]=i;
	}
	printf("Enter Source & Destination\n");
	scanf("%d %d",&s,&d);
	printf("Source & Destination %d %d\n",s,d);
	printf("Maximum Flow In Channel is %d\n",ford_fulkerson(--s,--d,n,pipecount,pipelist,pipes));
}