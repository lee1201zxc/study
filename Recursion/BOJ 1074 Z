#include <iostream>
#include<math.h>
using namespace std;
int k=0;
void rec(int n, int r, int c)
{
    int a;
    if(n==0)
        return;
    if(pow(2,n)/2>r&&pow(2,n)/2>c)//1사분면
        a=1;
    else if(pow(2,n)/2>r&&pow(2,n)/2<=c)//2사분면
        a=2;
    else if(pow(2,n)/2<=r&&pow(2,n)/2>c)//3사분면
        a=3;
    else if(pow(2,n)/2<=r&&pow(2,n)/2<=c)//4사분면
        a=4;
    k+=pow(2,n)*pow(2,n)/4*(a-1);
    rec(n-1,r-(a-1)/2*pow(2,n)/2,c-(a+1)%2*pow(2,n)/2);
}
int main(void)
{
    int n,r,c;
    cin>>n>>r>>c;
    rec(n,r,c);
    cout<<k;
}
/*
    처음에 2^n/2과r,c비교 2^n/2<=r면 하측, 2^n/2<=c면 우측, 이걸로 몇사분면인지 구함
    a사분면 이라면 k+=2^(n)*2^(n)/4*(a-1) 함
    그리도 재귀 다음엔 2^(n-1), r-(a-1)/2)*2^n/2, c-(a+1)%2)*2^n/2 로 두고
    어디까지? -> n이0일때 까지
*/
