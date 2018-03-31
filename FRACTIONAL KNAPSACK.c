
#include<stdio.h>
#include<stdlib.h>
typedef struct item
{
	int wt,val;
	double ratio;
}item;

void bubble(item arr[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j].ratio<arr[j+1].ratio)
			{
				item temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

item* fractional(item arr[],int n,int max,int *size,item *taken,float *f)
{
	int i,mSize=0;
	float cw=0,totalval=0;
	bubble(arr,n);
	for(i=0;i<n && cw<max;i++)
	{
		if(mSize)
			taken=(item*)realloc(taken,sizeof(item)*(++mSize));
		else
			taken=(item*)malloc(sizeof(item)*(++mSize));
		if((max-cw)>=arr[i].wt)
		{
			taken[mSize-1]=arr[i];
			cw+=arr[i].wt;
			totalval+=arr[i].val;
		}
		else
		{
			*f=((float)(max-cw))/arr[i].wt;
			taken[mSize-1]=arr[i];
			cw=max;
			totalval+=((*f)*arr[i].val);
			break;
		}
	}
	printf("Total Value %f\n",totalval);
	*size=mSize;
	return taken;
}

int main(void)
{
	int max,i,n,et=0;
	float f=0.0;
	printf("Enter the Max Capacity\n");
	scanf("%d",&max);
	printf("Enter The Number of Items\n");
	scanf("%d",&n);
	item arr[n],*taken;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&arr[i].wt,&arr[i].val);
		arr[i].ratio=((double)arr[i].val/arr[i].wt);
	}
	taken=fractional(arr,n,max,&et,taken,&f);
	printf("Items Picked: %d\n[ ",et);
	for(i=0;i<et;i++)
	{
		if(i==et-1 && f<1 && f!=0.0)
		{
			printf("%f*",f);
		}
		printf(" (%d,%d) ",taken[i].wt,taken[i].val);
	}
	printf(" ]\n");
}

