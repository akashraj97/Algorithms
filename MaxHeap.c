#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<stdbool.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int maxheapify(int arr[],int i,int size)
{
	int comp=0;
	int lc=(2*i)+1,rc=(2*i)+2,largest=i;
	if(lc<size && arr[lc]>arr[largest])
	{
		comp++;
		largest=lc;
	}
	if(rc<size && arr[rc]>arr[largest])
	{
		comp++;
		largest=rc;
	}
	if(largest!=i)
	{
		swap(&arr[largest],&arr[i]);
		comp+=maxheapify(arr,largest,size);
	}
	return comp;
}
void inckey(int arr[],int i)
{
	int p=(i-1)/2;
	while(i && arr[p]<arr[i])
	{
		swap(&arr[p],&arr[i]);
		i=p;
		p=(i-1)/2;
	}
}
void display(int arr[],int n)
{
	if(arr==NULL)
	{
		printf("Empty Queue\n");
	}
	int i;
	printf("Array is :");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
void top(int arr[],int size)
{
	if((size)==0 || arr==NULL)
	{
		printf("Empty Queue\n");
	}
	else
	{
		printf("Top Element is : %d\n",arr[0]);
	}
}
int dequeue(int arr[],int *size)
{
	if((*size)==0 || arr==NULL)
	{
		printf("Empty Queue\n");
		return -300;
	}
	else
	{
		int temp=arr[0];
		arr[0]=arr[(*size)-1];
		maxheapify(arr,0,(*size)-1);
		*size-=1;
		arr=(int*)realloc(arr,sizeof(int)*(*size));
		return temp;
	}
}
int* enqueue(int *arr,int *size,int n)
{
	if(arr==NULL || (*size)==0)
	{
		*size+=1;
		arr=(int*)malloc(sizeof(int)*(*size));
		arr[(*size)-1]=n;
		inckey(arr,(*size)-1);
		return arr;
	}
	(*size)+=1;
	arr=(int*)realloc(arr,sizeof(int)*(*size));
	arr[(*size)-1]=n;
	inckey(arr,(*size)-1);
	return arr;
}

int* fileenqueue(int *arr,int *size,FILE *fp)
{
	int n;
	fscanf(fp,"%d",&n);
	if(arr==NULL)
	{
		*size+=1;
		arr=(int*)malloc(sizeof(int)*(*size));
		arr[(*size)-1]=n;
		inckey(arr,(*size)-1);
		return arr;
	}
	(*size)+=1;
	arr=(int*)realloc(arr,sizeof(int)*(*size));
	arr[(*size)-1]=n;
	inckey(arr,(*size)-1);
	return arr;
}

void change_priority(int arr[],int size)
{
	int ok,nk,i;
	if(size==0)
	{
		printf("Empty Queue\n");
		return;
	}
	printf("Enter Old And New Key\n");
	scanf("%d %d",&ok,&nk);
	for(i=0;i<size;i++)
	{
		if(arr[i]==ok)
		{
			arr[i]=nk;
			break;
		}
	}
	if(i==size)
	{
		printf("Key Not Found\n");
		return;
	}
	if(nk>ok)
	{
		inckey(arr,i);
	}
	else
	{
		maxheapify(arr,i,size);
	}
}
int sort(int arr[],int size)
{
	int cost=0;
	int i;
	for(i=size;i>0;i--)
	{
		cost++;
		swap(&arr[0],&arr[i-1]);
		cost+=maxheapify(arr,0,i-1);
	}
	return cost;
}
bool check(int arr[],int size,bool *isheap)
{
	int i,ch;
	if(!(*isheap))
	{
		printf("Not a Heap........Press 1 to Create Heap and Any Other Key to Abort Operation\n");
		int x;
		scanf("%d",&x);
		if(x==1)
		{
			*isheap=true;
			for(i=(size-2)/2;i>=0;i--)
			{
				maxheapify(arr,i,size);
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	return true;
}


void build_heap(int arr[],int size)
{
	build_heap(arr,size);
	int i,comp=0;
	for(i=(size-2)/2;i>=0;i--)
	{
		comp=maxheapify(arr,i,size);
	}
//	return comp;
}
main()
{
	int mode=1,t,*arr=NULL,size=0,x,ch=1;
	bool isheap=true;
	printf("1. Testing 2.Large Data Input\n");
	scanf("%d",&mode);
	if(mode==1)
	{
		while(ch)
		{
			printf("1. Enqueue   2.Dequeue  3.Front  4.Change Priority  5.Display  6.Sort  0.Exit\n"); 
			scanf("%d",&ch);
			if(ch==1)
			{
				int dat;
				if(!isheap && !check(arr,size,&isheap))
				{
					continue;
				}
				printf("eenter Data:");
				scanf("%d",&dat);
				arr=enqueue(arr,&size,dat);
				display(arr,size);
			}
			else if(ch==2)
			{
				if(!isheap && !check(arr,size,&isheap))
				{
					continue;
				}
				int temp=dequeue(arr,&size);
				if(temp!=-300)
				{
					printf("Deleting %d\n",temp);
				}
				display(arr,size);
			}
			else if(ch==3)
			{
				if(!isheap && !check(arr,size,&isheap))
				{
					continue;
				}
				top(arr,size);
			}
			else if(ch==4)
			{
				if(!isheap && !check(arr,size,&isheap))
				{
					continue;
				}
				change_priority(arr,size);
			}
			else if(ch==5)
			{
				display(arr,size);
			}
			else if(ch==6)
			{
				if(size==0)
				{
					printf("Empty Queue\n");
				}
				else
				{
					isheap=false;
					sort(arr,size);
				}
			}
			else if(ch)
			{
				printf("Wrong Input\n");
			}
		}
	}
	else
	{
		int temp;
		FILE *fp=fopen("input.txt","r");
		FILE *out=fopen("output.txt","w");
		for(;fscanf(fp,"%d",&temp)!=EOF;)
		{
			if(arr==NULL)
			{
				size++;
				arr=(int*)malloc(sizeof(int));
				arr[size-1]=temp;
			}
			else
			{
				size++;
				arr=(int*)realloc(arr,sizeof(int)*size);
				arr[size-1]=temp;
			}
		}
		display(arr,size);
		printf("\n");
		int comp=sort(arr,size);
		display(arr,size);
		printf("\n");
		fprintf(out," Comparisons %d   Constant  %lf\n",comp,(double)comp/(size*log2(size)));
		size=0;
	}
}
