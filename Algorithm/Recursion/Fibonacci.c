#include<stdio.h>
int fibonacci(int a)
{
	if(a==1)
		return 0;
	else if(a==2)
		return 1;
	else
		return fibonacci(a-2)+fibonacci(a-1);
}
int main(void)
{
	int n;
	for(n=1; n<=15 ; n++)
		printf("%d\n", fibonacci(n));
	return 0;
}
//f(1)=0,f(2)=1,f(n)=f(n-2)+f(n-1) ;(n>=3)
