#include<iostream>
using namespace std;
int main(void)
{
    int i=0,n,ans=0,a[7]={0,};
    cin>>n;
    while(n!=0)
    {
        a[i]=n%2;
        n/=2;
        i++;
    }
    for(int i=0; i<7; i++)
        ans+=a[i];
    cout<<ans;
}
//2^6막대기를 절반씩 나누는 것이므로 이진수로 풀 수 있다.
