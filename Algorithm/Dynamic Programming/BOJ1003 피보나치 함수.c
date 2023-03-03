#include<stdio.h>
int main(void)
{
	int n[41][2]={0,},t;
	scanf("%d",&t);;
	n[0][0]=1,n[1][1]=1;
	for(int i=2;i<=40;i++)
	{
		n[i][0]=n[i-1][0]+n[i-2][0];
		n[i][1]=n[i-1][1]+n[i-2][1];
	}
	for(int i=0;i<t;i++)
	{
		int z;
		scanf("%d",&z);
		printf("%d %d\n", n[z][0],n[z][1]);
	}
}
