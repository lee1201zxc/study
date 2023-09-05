#include<iostream>
using namespace std;
long long a[1000000],b[4000000];//b의 크기 = a크기 보다 큰 가장 가까운 제곱수 구한뒤 2배,대력 a*4
//b를선언하면 총 초기화되는 부분은  2*a이지만 인덱스느 4*a까지 필요함
void node(long long n, long long start, long long end)
{
    if(start==end)
    {
        b[n]=a[start];
        return;
    }
    long long mid=(start+end)/2;
    node(2*n,start,mid);
    node(2*n+1,mid+1,end);
    b[n]=b[2*n]+b[2*n+1];
    return;
}
void change(long long n, long long start, long long end, long long w, long long e)//n=b[]에서 현재 탐색 구간,w를e로 바꿀거
{
    if(start==end)
    {
        b[n]=e;
        a[w]=e;
        return;
    }
    b[n]+=e-a[w];
    long long mid=(start+end)/2;
    if(start<=w&&mid>=w)
        change(2*n,start,mid,w,e);
    else
        change(2*n+1,mid+1,end,w,e);
}
long long prints(long long n, long long start, long long end, long long w, long long e)
{
    if (w>end||e<start)
        return 0;
    if(w<=start&&end<=e)
        return b[n];
    long long mid=(start+end)/2;
    return prints(n*2,start,mid,w,e)+prints(n*2+1,mid+1,end,w,e);
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m,k;
    cin>>n>>m>>k;
    for(int i=0; i<n; i++)
        cin>>a[i];
    node(1,0,n-1);
    for(int i=0; i<m+k; i++)
    {
        long long q,w,e;
        cin>>q>>w>>e;
        if(q==1)
        {
            change(1,0,n-1,w-1,e);
            // for(int z=1; z<=2*n-1; z++)
            //     cout<<b[z]<<' ';
            // cout<<'\n';
        }
        else
        {
            cout<<prints(1,0,n-1,w-1,e-1)<<'\n';
        }
    }
}
/*
기본 문제이므로 잘 익혀두자
*/
