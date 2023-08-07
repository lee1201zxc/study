#include<stdio.h>
int main(void)
{
	int n,j=1;
	scanf("%d",&n);
	int a[n],b[n];
	for(int i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
		b[i]=1;
	}	
	for(int i=1; i<n; i++)
	{
		int k=1;
		for(int z=i-1; z>=0; z--)
		{
			if(a[z]<a[i])
			{
				if(b[i]<=b[z])
					b[i]=b[z]+1;
				if(j<b[i])
					j=b[i];
			}
		}
	}
	printf("%d",j);
}
//매우 중요한 문제
