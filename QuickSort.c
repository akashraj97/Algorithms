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
	int i,j=high,pivot=low;
	i=low;
	if(i<j)
	{
		while(i<j)
		{
			while(arr[i]<=arr[pivot] && i<j)
			{
				*calls+=1;
				i++;
			}
			while(arr[j]>=arr[pivot] && i<j)
			{
				*calls+=1;
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
		quick_sort(arr,j,high,calls);
		quick_sort(arr,low,j-1,calls);
	}
}

void random_quick_sort(int arr[],int low,int high,int *calls)
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
		random_quick_sort(arr,j,high,calls);
		random_quick_sort(arr,low,j-1,calls);
	}
}

main()
{
	srand(time(NULL));
	time_t start,stop;
	int size,i,j,high,low,n,calls=1;
	printf("Enter the array size:");
	scanf("%d",&n);
	int *arr=(int*)malloc(sizeof(int)*n);
	int *brr=(int*)malloc(sizeof(int)*n);
	int *crr=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		brr[i]=crr[i]=arr[i]=i+1;
	}
	/*for(i=0;i<n;i++)
	{
		j=rand()%(size-i);
		swap(&arr[0],&arr[j]);
		swap(&brr[0],&brr[j]);
		swap(&crr[0],&crr[j]);
	}*/
	/*for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");*/
	start=clock();
	printf("Entered Quick SOrt");
	quick_sort(arr,0,n-1,&calls);
	stop=clock();
	/*for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}*/
	printf("\nQuick Sort :: Number of Calls %d\n",calls);
	printf("Quick Sort :: Time Taken:  %lf\n",((double)(stop-start))/CLOCKS_PER_SEC);
	start=clock();
	random_quick_sort(arr,0,n-1,&calls);
	stop=clock();
	/*for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}*/
	printf("\nRandom Quick Sort :: Number of Calls %d\n",calls);
	printf("Random Quick Sort ::  Time Taken:  %lf\n",((double)(stop-start))/CLOCKS_PER_SEC);
	start=clock();
	quick_sort(arr,0,n-1,&calls);
	stop=clock();
	/*for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}*/
	printf("\nNumber of Calls %d\n",calls);
	printf("Time Taken:  %lf\n",((double)(stop-start))/CLOCKS_PER_SEC);
}
