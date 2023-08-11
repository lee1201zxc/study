#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long n,m,ans=0;
    cin>>n>>m;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    int start=0,end=a[n-1];
    while(start<=end)
    {
        long mid=(start+end)/2,max=0;
        for(int i=0; i<n; i++)
        {
            if(a[i]>mid)
                max+=a[i]-mid;
        }
        if(max>=m)
        {
            start=mid+1;
            if(mid>ans)
                ans=mid;
        }
        else
            end=mid-1;
    }
    cout<<ans;
}
/*
매개변수 탐색 문제이다.
*/
