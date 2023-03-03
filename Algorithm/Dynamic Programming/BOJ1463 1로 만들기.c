#include<stdio.h>
int a[1000001];
int min(int i)
{
	int x;
	x=a[i-1];
	if(i%3==0)
	{
		x=x<a[i/3]?x:a[i/3];
	}
	if(i%2==0)
		x=a[i/2]<x?a[i/2]:x;
	return x+1;
}
int main(void)
{
	int n;
	scanf("%d",&n);
	a[1]=0,a[2]=1,a[3]=1;
	for(int i=4; i<=n; i++)
	{
		a[i]=min(i);
	}
	printf("%d",a[n]);
}
