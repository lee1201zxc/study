#include<iostream>
#include<algorithm>
using namespace std;
int a[100000],b[400000];
void made(int n, int start, int end)
{
    if(start==end)
    {
        b[n]=a[start];
        return;
    }
    int mid=(start+end)/2;
    made(2*n,start,mid);
    made(2*n+1,mid+1,end);
    b[n]=min(b[2*n],b[2*n+1]);
}
int change(int n, int start, int end, int w, int e)
{
    if(start==end)
    {
        a[w]=e;
        b[n]=e;
        return e;
    }
    int mid=(start+end)/2;
    if(mid>=w&&start<=w)
        b[n]=min(change(2*n,start,mid,w,e),b[2*n+1]);
    else
        b[n]=min(change(2*n+1,mid+1,end,w,e),b[2*n]);
    return b[n];
}
int prints(int n, int start, int end, int w, int e)
{
    if(start>e||end<w)
        return 1000000000;
    if(start>=w&&end<=e)
        return b[n];
    int mid=(start+end)/2;
    return min(prints(2*n,start,mid,w,e),prints(2*n+1,mid+1,end,w,e));
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i];
    made(1,0,n-1);
    cin>>k;
    for(int i=0; i<k; i++)
    {
        int q,w,e;
        cin>>q>>w>>e;
        if(q==1)
        {
            change(1,0,n-1,w-1,e);
        }
        else
        {
            cout<<prints(1,0,n-1,w-1,e-1)<<'\n';
        }
    }
}
/*
change부분이 좀 다르다. 재귀로 이루어져 있음.

*/
