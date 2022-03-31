#include<stdio.h>
void binary(int a[], int len, int n)
{
	int first=0, last=len-1,k=0;
	while(first<=last)
	{
		int middle=(first+last)/2;
		if(a[middle]==n)
		{
			printf("%d\n",middle);
			k=1;
			break;
		}
		else if(a[middle]>n)
		{
			last=middle-1;
		}
		else
		{
			first=middle+1;
		}
	}
	if(k==0)
		printf("Fail To Search\n");
}
int main(void)
{
	int a[7]={1,2,3,6,7,8,10};
	for(int i=1; i<=10; i++)
		binary(a, sizeof(a)/4, i);
}
