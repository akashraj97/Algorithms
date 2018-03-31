#include<stdio.h>
#define lli long long int

void hanoi(lli n,char from,char to,char inter,lli *calls)
{
	if(n==1)
	{
		printf("Moving disc 1 from rod %c to %c\n",from,to);
		return;
	}
	*calls+=1;
	hanoi(n-1,from,inter,to,calls);
	printf("Moving Disc %lld from rod %c to %c\n",n,from,to);
	*calls+=1;
	hanoi(n-1,inter,to,from,calls);
}

main()
{
	lli calls=1,n;
	printf("Enter the number of Discs:\n");
	scanf("%lld",&n);
	hanoi(n,'S','D','I',&calls);
	printf("NUmber of calls: %lld\n",calls);
}
