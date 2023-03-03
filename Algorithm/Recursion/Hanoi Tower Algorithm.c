#include<stdio.h>
void hanoi(int n,char from,char rest,char to)
{
	if(n==1)
	{
		printf("%d를 %c에서 %c로 이동\n",n,from,to);
	}
	else
	{
		hanoi(n-1,from,to,rest);
		printf("%d를 %c에서 %c로 이동\n",n,from,to);
		hanoi(n-1,rest,from,to);	
	}
}
int main(void)
{
	hanoi(3,'A','B','C');
	return 0;
}

