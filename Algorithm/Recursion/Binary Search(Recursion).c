#include<stdio.h>
int binary(int a[], int first, int last, int n)
{
	int middle=(first+last)/2;
	if(first>last)
		return -1;
	if(a[middle]==n)
	{
		return middle;
	}
	else if(a[middle]>n)
	{
		return binary(a, first, middle-1, n);
	}
	else if(a[middle]<n)
	{
		return binary(a, middle+1, last, n);
	}
}
int main(void)
{
	int a[7]={1,2,3,6,7,8,10},k;
	
	for(int i=1; i<=10; i++)
	{
		k=binary(a, 0, sizeof(a)/4-1, i);
		if(k==-1)
			printf("Fail To Search\n");
		else
			printf("%d\n",k);
	}
}
