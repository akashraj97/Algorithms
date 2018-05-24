#include<stdio.h>
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
typedef struct res
{
	int min,max;
}res;

res getAns(int arr[],int low,int high)
{
	if(low==high)
	{
		res temp;
		temp.min=temp.max=arr[low];
		return temp;
	}
	res z=getAns(arr,low,(low+high)/2);
	res y=getAns(arr,((low+high)/2)+1,high);
	res temp;
	temp.max=max(z.max,y.max);
	temp.min=min(z.min,y.min);
	return temp;
}

main()
{
	int n,i;
	printf("Enter Array Size:");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	res result=getAns(arr,0,n-1);
	printf("Max %d Min %d\n",result.max,result.min);
}