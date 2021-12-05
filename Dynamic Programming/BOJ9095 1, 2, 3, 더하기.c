#include<stdio.h>
int main(void)
{
	int n,k,a[12];
	scanf("%d",&k);
	for(int z=0; z<k; z++)
	{
		scanf("%d",&n);
		a[1]=1,a[2]=2,a[3]=4;
		for(int i=4; i<=n; i++)
			a[i]=a[i-3]+a[i-2]+a[i-1];
		printf("%d\n",a[n]);
	}
}
