#include<iostream>
#define Max 1000000001
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n][n];
    for(int i=0; i<n; i++)//모든 값 최댓값으로
    {
        for(int z=0; z<n; z++)
            a[i][z]=Max;
    }
    for(int i=0; i<n; i++)//본인 0으로 만들기
        a[i][i]=0;
    for(int i=0; i<m; i++)//그래프 정보 입력 
    {
        int q,w,e;
        cin>>q>>w>>e;
        if(a[q-1][w-1]>e)//조심
            a[q-1][w-1]=e;
    }
    for(int k=0; k<n; k++)//무조건 이거 먼저
    {
        for(int i=0; i<n; i++)
        {
            for(int z=0; z<n; z++)
            {
                if(a[i][z]>a[i][k]+a[k][z])
                    a[i][z]=a[i][k]+a[k][z];
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int z=0; z<n; z++)
        {
            if(a[i][z]!=Max)
                cout<<a[i][z]<<' ';
            else
                cout<<0<<' ';
        }
        cout<<'\n';
    }
}
