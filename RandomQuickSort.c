#include<time.h>
#include<stdlib.h>
#include<stdio.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void quick_sort(int arr[],int low,int high,int *calls)
{
	if(high<=low)
	{
		return;
	}
	int i=low,j=high,pivot;
	pivot=rand()%(high-low+1);
	pivot+=low;
	if(i<j)
	{
		while(i<j)
		{
			while(arr[i]<=arr[pivot] && i<j)
			{
				i++;
			}
			while(arr[j]>=arr[pivot] && i<j)
			{
				j--;
			}
			if(i<j)
			{
				swap(&arr[i],&arr[j]);
			}
		}
		if(arr[pivot]>arr[j])
		{
			swap(&arr[pivot],&arr[j]);
		}
		*calls+=2;
		quick_sort(arr,j,high,calls);
		quick_sort(arr,low,j-1,calls);
	}
}
main()
{
	srand(time(NULL));
	int size,i,j,high,low,n,calls=1;
	printf("Enter the array size:");
	scanf("%d",&size);
	n=size;
	int arr[n];
	for(i=0;i<size;i++)
	{
		arr[i]=i+1;
	}
	for(i=0;i<n;i++)
	{
		j=(rand())%size;
		swap(&arr[0],&arr[j]);
	}
	quick_sort(arr,0,n-1,&calls);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\nNumber of Calls %d\n",calls);	
}
