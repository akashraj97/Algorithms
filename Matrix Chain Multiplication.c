#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>
typedef struct matrix
{
	int row,col;
	int **arr;
}matrix;
int count=0;
matrix multiply(matrix a,matrix b)
{
	int i,j,k;
	matrix nm;
	nm.row=a.row;
	nm.col=b.col;
	nm.arr=(int**)malloc(sizeof(int*)*nm.row);
	for(i=0;i<nm.row;i++)
		nm.arr[i]=(int*)malloc(sizeof(int)*nm.col);
	for(i=0;i<a.row;i++)
	{
		for(j=0;j<b.col;j++)
		{
			int temp=0,cnt=0;
			for(k=0;k<a.col;k++)
			{
				count++;
				int p=a.arr[i][k]*b.arr[k][j];
				temp+=p;
			}
			nm.arr[i][j]=temp;
		}
	}
	return nm;
}

matrix printparenthesis(int *parenthesis,int i,int j,int n,matrix mtx[])
{
	if(i==j)
	{
		printf(" %d ",i);
		return mtx[i];
	}
	printf("(");
	matrix a=printparenthesis(parenthesis,i,*(parenthesis+(i*n)+j),n,mtx);
	matrix b=printparenthesis(parenthesis,*(parenthesis+(i*n)+j)+1,j,n,mtx);
	printf(")");
	return multiply(a,b);
}

void getScalar(int dimen[][2],int *parenthesis,int n)
{
	int i,j,costt,l,k;
	int cost[n][n];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cost[i][j]=INT_MAX;
			if(i==j)
			{
				cost[i][j]=0;
			}
		}
	}
	
	for(l=1;l<n;l++)
	{
		for(i=0;i+l<n;i++)
		{
			int k=i+l;
			for(j=i;j<i+l;j++)
			{
				costt=dimen[i][0]*dimen[j][1]*dimen[i+l][1];
				costt+=(cost[i][j]+cost[j+1][i+l]);
				if(costt<cost[i][i+l])
				{
					cost[i][i+l]=costt;
					*(parenthesis+(i*n)+i+l)=j;
				}
			}
		}
	}
	printf("Upper Traingular Matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d  ",cost[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");
	printf("Total Number of Scalar Multiplications : %d\n",cost[0][n-1]);
}

int main()
{
	srand(time(NULL));
	int *parenthesis,n,i,j,k;
	printf("Enter number of Matrices:");
	scanf("%d",&n);
	int arr[n+1],dimen[n][2],temp;
	parenthesis=(int*)malloc(sizeof(int)*(n*n));
	matrix mtx[n];
	for(i=0;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		if(i)
		{
			mtx[i-1].row=dimen[i-1][0]=arr[i-1];
			mtx[i-1].col=dimen[i-1][1]=arr[i];
		}
	}
	for(i=0;i<n;i++)
	{
		mtx[i].arr=(int**)malloc(sizeof(int*)*mtx[i].row);
		for(j=0;j<mtx[i].row;j++)
		{
			mtx[i].arr[j]=(int*)malloc(sizeof(int)*mtx[i].col);
		}
		printf("Enter the contents of Matrix %d [ %d  x  %d  ]\n",i,mtx[i].row,mtx[i].col);
		for(j=0;j<mtx[i].row;j++)
		{
			for(k=0;k<mtx[i].col;k++)
			{
				//scanf("%d",&temp);
				mtx[i].arr[j][k]=rand()%2;
			}
		}
	}
	getScalar(dimen,parenthesis,n);
	matrix res=printparenthesis(parenthesis,0,n-1,n,mtx);
	printf("\nResultant Matrix\n");
	for(i=0;i<res.row;i++)
	{
		for(j=0;j<res.col;j++)
		{
			printf("%d ",res.arr[i][j]);
		}
		printf("\n");
	}
	printf("Number of Scalar Multiplications While Multiplying is %d\n",count);
	return 0;
}