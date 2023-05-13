#include<stdio.h>
#define N 10
int main(void)
{
	int a[N]={5,10,2,9,3,8,4,7,1,6};
	for(int i=1; i<N; i++)
	{
		for(int j=0; j<i; j++)
		{
			if(a[j]>a[i])
			{
				int s=a[j];
				a[j]=a[i];
				a[i]=s;
			}
		}
	}
	for(int i=0; i<N; i++)
		printf("%d ",a[i]);
}
/* Insertion Sort : n번째 원소를 1~n-1번째 원소들과
비교하여 적절한 곳에 삽입, 이를 반복 */ 
