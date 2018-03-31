#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
	int stage,from,to,aux,n;
}data;

data stack[100000];
int top=0;

data fill(int stage,char from,char to,char aux,int n)
{
	data temp;
	temp.stage=stage;
	temp.from=from;
	temp.to=to;
	temp.aux=aux;
	temp.n=n;
	return temp;
}

void hanoi_stack(int n,char from,char to,char aux)
{
	int stage;
	stack[top++]=fill(1,from,to,aux,n);
	while(top)
	{
		n=stack[top-1].n;
		stage=stack[top-1].stage;
		from=stack[top-1].from;
		to=stack[top-1].to;
		aux=stack[--top].aux;
		if(stage==1)
		{
			if(n==1)
			{
				printf("Moving Discs from %c to %c\n",from,to);
				continue;
			}
			stack[top++]=fill(2,from,to,aux,n);
			stack[top++]=fill(1,from,aux,to,n-1);
			continue;
		}
		if(stage==2)
		{
			printf("Moving discs from %c to %c\n",from,to);
			stack[top++]=fill(1,aux,to,from,n-1);
		}
	}
}

main()
{
	int n;
	printf("Enter the number of Discs:");
	scanf("%d",&n);
	hanoi_stack(n,'F','T','A');
}