#include<stdio.h>
int d[100];
int fb(int x)
{
	if(x==1)
		return 1;
	if(x==2)
		return 1;
	if(d[x]!=0)
		return d[x];
	return d[x]=fb(x-1)+fb(x-2);
}
int main(void)
{
	int n;
	scanf("%d",&n);
	printf("%d",fb(n));
}
