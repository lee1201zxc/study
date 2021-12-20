#include<stdio.h>
int main(void)
{
	int s=0,n,a[31]={0,};
	scanf("%d",&n);
    a[2]=3;
	for(int i=4; i<=n; i+=2)
	{
		if(i>=8)
			s+=a[i-6];
		a[i]=a[i-2]*3+a[i-4]*2+2*s+2;
	}
	if(n==0)
		printf("1");
	else
		printf("%d",a[n]);
}
