#include<stdio.h>
#define N 10
int main(void)
{
	int a[N]={5,10,2,9,3,8,4,7,1,6};
	for(int i=0; i<N; i++)
	{
		int x=a[i],c;
		for(int j=i; j<N; j++)
		{
			if(a[j]<x)
			{
				x=a[j];
				c=j;
			}
		}
		a[c]=a[i];
		a[i]=x;
	}
	for(int i=0; i<N; i++)
		printf("%d ",a[i]);
}
/* Selection Sort : 1~n번째까지 원소중 최소값 찾아 
맨앞 원소와 교체, 그리고 2~n번쨰까지 원소중 최소값
 찾아 맨앞에서 2번째 원소와 교체, 이를 반복 */ 
