//문제 링크 : https://www.acmicpc.net/problem/2178
//2차원 배열에서의 BFS를 이용한 문제

#include <iostream>
#include<queue>
#include<utility>
using namespace std;
int x[4]={0,0,-1,1};
int y[4]={1,-1,0,0};
int main()
{
    int n,m,h=1,j=0;
    char k;
    cin>>n>>m;
    int a[n][m],b[n][m];
    fill(b[0],b[0]+n*m,0);
    for(int i=0; i<n; i++)
    {
        for(int z=0; z<m; z++)
        {
            cin>>k;
            a[i][z]=(int)k-48;
        }
    }
    queue<pair<int,int>> v;
    v.push(make_pair(0,0));
    b[0][0]=1;
    while(!v.empty())
    {
        pair<int,int> q=v.front();
        v.pop();
        for(int i=0; i<4; i++)
        {
            int X=x[i]+q.second,Y=y[i]+q.first;
            if(X<0||Y<0||X>=m||Y>=n)
                continue;
            else if(a[Y][X]==0)
            {
                continue;
            }
            else if(b[Y][X]==0)
            {
                b[Y][X]=b[q.first][q.second]+1;
                v.push(make_pair(Y,X));
            }
            if(X==m-1&&Y==n-1)
            {
                cout<<b[Y][X]<<'\n';
                j=1;
                break;
            }
        }
        if(j==1)
            break;
    }
}
