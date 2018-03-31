#include<iostream>

void preCompute(vector<int> &arr,string &pat)
{
	int i=1,j=0;
	while(i<pat.length())
	{
		if(pat[i]==pat[j])
		{
			arr[i]=++j;
		}
		else
		{
			if(j>0)
			{
				j=arr[j-1];
				continue;
			}
			else
			{
				arr[i]=0;
			}
		}
		i++;
	}
	for(i=0;i<arr.size();i++)
	{
		printf("%d  ",arr[i]);
	}
	printf("\n");
}


void KMP(string &txt,string &pat)
{
	int found=0;
	int i,j,m=txt.length(),pat_len=pat.length();
	vector<int> arr(pat_len);
	arr[0]=0;
	preCompute(arr,pat);
	j=0;
	for(i=0;i<m;i++)
	{
		if(j==pat_len)
		{
			printf("String Found at %d\n",i-j);
			j=arr[j-1];
			i--;
			found++;
		}
		if(txt[i]==pat[j])
		{
			j++;
		}
		else if(j!=0)
		{
			j=arr[j-1];
			i--;
		}
	}
	if(found==0)
	{
		printf("Oops :( String not found\n");
	}
}

main()
{
	string a,b;
	cin>>a>>b;
	KMP(txt,pat);
}