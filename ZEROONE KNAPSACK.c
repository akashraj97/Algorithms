#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct item
{
	int weight,val;
}item;

int max(int a,int b)
{
	return a>b?a:b;
}

item* knapsack(item arr[],int n,int w,int *cw,int *ec,int *tv)
{
	item *taken=NULL;
	int pf[n+1][w+1],i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=w;j++)
		{
			pf[i][j]=0;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=w;j++)
		{
			if(arr[i-1].weight<=j)
			{
				pf[i][j]=max( pf[i-1][j] , (pf[i-1][j-arr[i-1].weight] + arr[i-1].val));
			}
			else
			{
				pf[i][j]=pf[i-1][j];
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=w;j++)
		{
			printf("%d ",pf[i][j]);
		}
		printf("\n");
	}
	i=n;j=w;
	printf("Total Profit :%d\n\n",pf[n][w]);
	int mSize=0;
	while(i>0 && j>0)
	{
		if(pf[i-1][j]!=pf[i][j])
		{
			printf("OKK\n");
			if(taken==NULL)
			{
				taken=(item*)malloc(sizeof(item)*(++mSize));
			}
			else
			{
				taken=(item*)realloc(taken,sizeof(item)*(++mSize));
			}
			taken[mSize-1]=arr[i-1];
			j-=arr[i-1].weight;
			i--;
		}
		else
		{
			i--;
		}
	}
	*ec=mSize;
	return taken;
}

int main()
{
	int i,j,n,m,mw,ec=0,cw=0,tv=0;
	printf("Enter The Maximum Capacity\n");
	scanf("%d",&mw);
	printf("Enter the numbers of Elements\n");
	scanf("%d",&n);
	item arr[n];
	printf("Enter the Weight & Value of %d Items\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&arr[i].weight,&arr[i].val);
	}
	item *taken=knapsack(arr,n,mw,&cw,&ec,&tv);
	printf("Elements in Bag %d\n",ec);
	for(i=0;i<ec;i++)
	{
		printf("( %d , %d )  ",taken[i].weight,taken[i].val);
	}
}
