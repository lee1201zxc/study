#include<stdio.h>
int main(void)
{
	long long n,a[90][2]={0,};
	a[0][1]=1;
	scanf("%d",&n);
	for(int i=1; i<90; i++)
	{
		a[i][0]+=a[i-1][0]+a[i-1][1];
		a[i][1]+=a[i-1][0];
	}
	printf("%lld",a[n-1][0]+a[n-1][1]);
}
