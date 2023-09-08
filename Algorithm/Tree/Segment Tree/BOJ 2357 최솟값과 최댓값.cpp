#include<iostream>
#include<algorithm>
using namespace std;
int a[100000],b[400000][2];//a=수 저장,b= 구간마다 최대, 최소 저장
int find1(int n,int start, int end, int s, int e)//작은거
{
    if(e<start||s>end)
        return 1000000000;
    if(start>=s&&end<=e)
        return b[n][0];
    int mid=(start+end)/2;
    return min(find1(2*n,start,mid,s,e),find1(2*n+1,mid+1,end,s,e));
}
int find2(int n,int start, int end, int s, int e)//큰거
{
    if(e<start||s>end)
        return 0;
    if(start>=s&&end<=e)
        return b[n][1];
    int mid=(start+end)/2;
    return max(find2(2*n,start,mid,s,e),find2(2*n+1,mid+1,end,s,e));
}
void made1(int n, int start, int end)
{
    if(start==end)
    {
        b[n][0]=a[start];
        return;
    }
    int mid=(start+end)/2;
    made1(2*n,start,mid);
    made1(2*n+1,mid+1,end);
    b[n][0]=min(b[2*n][0],b[2*n+1][0]);
    return;
}
void made2(int n, int start, int end)
{
    if(start==end)
    {
        b[n][1]=a[start];
        return;
    }
    int mid=(start+end)/2;
    made2(2*n,start,mid);
    made2(2*n+1,mid+1,end);
    b[n][1]=max(b[2*n][1],b[2*n+1][1]);
    return;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
        cin>>a[i];
    made1(1,0,n-1);
    made2(1,0,n-1);
    for(int i=0; i<m; i++)
    {
        int s,e;
        cin>>s>>e;
        cout<<find1(1,0,n-1,s-1,e-1)<<' '<<find2(1,0,n-1,s-1,e-1)<<'\n';
    }
}
/*
큰 거 구하는 것과 작은 거 구하는 거 두가지로 나눔
*/
