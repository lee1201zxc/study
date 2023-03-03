#include<stdio.h>
int min(int a,int b)
{
	if(a==-1&&b==-1)
		return -1;
	else if(a==-1&&b!=-1)
		return b+1;
	else if(a!=-1&&b==-1)
		return a+1;
	else 
	{
		if(a>b)
			return b+1;
		else
			return a+1;
	}
}
int b[5000];
int main(void)
{
	int n;
	scanf("%d",&n);
	b[1]=-1,b[2]=-1,b[3]=1,b[4]=-1,b[5]=1;
	for(int i=6; i<=n; i++)
	{
		b[i]=min(b[i-3],b[i-5]);
	}
	if(b[n]==0)
		b[n]-=1;
	printf("%d",b[n]);
}
