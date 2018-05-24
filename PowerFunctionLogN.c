#include<stdio.h>
#define lli long long int

lli mypow(lli a,lli b,lli *calls)
{
	lli temp;
	if(a==1 || b==0)
	{
		return 1;
	}
	if(a==0)
	{
		return 0;
	}
	else if(b==1)
	{
		return a;
	}
	else
	{
		*calls+=1;
		temp= mypow(a,b-1,calls);
		if(temp<a*temp)
		{
			return -1;
		}
	}
}

lli mypowef(lli a,lli b,lli *calls)
{
	lli temp;
	if(a==1 || b==0)
	{
		return 1;
	}
	if(a==0)
	{
		return 0;
	}
	if(b==1)
	{
		return a;
	}
	else if(b%2)
	{
		*calls+=1;
		temp=mypowef(a,b/2,calls);
		if(a*temp*temp<temp)
		{
			return -1;
		}
		return a*temp*temp;
	}
	else if(b%2==0)
	{
		*calls+=1;
		temp=mypowef(a,b/2,calls);
		if(temp*temp<temp)
		{
			return -1;
		}
		return temp*temp;
	}
}

int main()
{
	lli ch=10,res,num,expo,calls=1;
	while(ch)
	{
		calls=1;
		printf("Enter Your Choice:\n1. O(n) Method  \n2.O(logn)\n");
		scanf("%lld",&ch);\
		if(ch)
		{
			printf("Enter Number And Exponent:");
			scanf("%lld %lld",&num,&expo);
			//printf("NUM IS ",num);
		}
		switch(ch)
		{
			case 1:		res=mypow(num,expo,&calls);
					if(res<=0)
					{
						printf("Overflow\n");
						break;
					}
					printf("Result is :%lld",res);
					printf("Number of Calls: %lld\n",calls);
					break;

			case 2:		res=mypowef(num,expo,&calls);					
					if(res<=0)
					{
						printf("Overflow\n");
						break;
					}
					printf("Result is :%lld",res);
					printf("Number of Calls: %lld\n",calls);
					break;
			default:	printf("Terminating Program\n");
		}
	}
}
