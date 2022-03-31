#include<stdio.h>
void linear(int a[], int len, int n)
{
	int x=0;
	for(int i=0; i<len; i++)
	{
		if(a[i]==n)
		{
			printf("%d\n",i);
			x=1;
			break;
		}
	}
	if(x==0)
		printf("Fail To Search\n");
}
int main(void)
{
	int a[7]={3,8,1,10,7,6,2};
	for(int i=0; i<10; i++)
		linear(a,sizeof(a)/4,i);
	return 0;
}
