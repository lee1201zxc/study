#include<stdio.h>
#define N 10
int main(void)
{
	int a[N]={5,10,2,9,3,8,4,7,1,6};
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

/*Bubble Sort : 1, 2번째 원소를 비교하여 큰 것을
뒤로 보냄, 그리고 2, 3...n-1, n번째 원소까지 
비교하여 가장 큰 원소를 뒤에 정렬, 이를 반복하여 
큰 원소를 하나씩 뒤에 정렬하는 방법 */
 
