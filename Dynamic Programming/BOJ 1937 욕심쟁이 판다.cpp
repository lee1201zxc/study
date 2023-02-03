```
#include <iostream>
int n,w=0;
int a[501][501]={0,};
int b[501][501]={0,};
int y[4]={0,1,0,-1},x[4]={1,0,-1,0};
using namespace std;
int max(int a, int b)
{
    return a>b?a:b;
}
int dfs(int i,int z)
{
    if(b[i][z]!=0)
        return b[i][z];
    b[i][z]=1;
    for(int c=0; c<4; c++)
    {
        int Y=i+y[c], X=z+x[c];
        if(X<0||Y<0||X>=n||Y>=n)
            continue;
        else if(a[i][z]>a[Y][X])
            b[i][z]=max(b[i][z],dfs(Y,X)+1);
    }
    if(b[i][z]>w)
        w=b[i][z];
    return b[i][z];
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int z=0; z<n; z++)
        {
            cin>>a[i][z];
        }
    }    
    for(int i=0; i<n; i++)
    {
        for(int z=0; z<n; z++)
        {
            dfs(i,z);
        }
    }
    cout<<w;
}
```
'''
/*
    Top Bottom방식의 DP
    재귀를 이용 : 어떤 지점의 최댓값을 구하려면 주위 4지점중 어떤 지점의 대나무크기보다 작은곳중, 그 지점에서 방문할 수 있는 최댓값중 가장 큰 값에 1을 더해주면된다.
*/
'''
