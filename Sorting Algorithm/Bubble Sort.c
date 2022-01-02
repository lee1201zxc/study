#include<stdio.h>
#define N 10
int main(void)
{
	int a[N]={1,10,2,9,3,8,4,7,5,6};
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N-1-i; j++)
		{
			if(a[j]>a[j+1])
			{
				int s=a[j];
				a[j]=a[j+1];
				a[j+1]=s;
			}
		}
	}
	for(int i=0; i<N; i++)
		printf("%d ",a[i]);
}
