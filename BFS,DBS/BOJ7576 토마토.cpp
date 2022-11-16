//문제 링크 : https://www.acmicpc.net/problem/7576
//여러 지점에서 동시에 BFS를 진행하는 문제

#include <iostream>
#include<utility>
#include<queue>
using namespace std;
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};
int main()
{
    int n,m,c=0,cc=0,d=1;
    cin>>m>>n;
    int a[n][m];
    for(int i=0; i<n; i++)
    {
        for(int z=0; z<m; z++)
        {
            cin>>a[i][z];
            if(a[i][z]==0)
                c++;
        }
    }
    queue<pair<int,int>> v;
    for(int i=0; i<n; i++)
    {
        for(int z=0; z<m; z++)
        {
            if(a[i][z]==1)
            {
                v.push(make_pair(i,z));
            }
        }
    }
    while(!v.empty())
    {
        pair<int,int> p=make_pair(v.front().first,v.front().second);
        v.pop();
        for(int s=0; s<4; s++)
        {
            int xx=x[s]+p.second,yy=y[s]+p.first;
            if(xx<0||yy<0||xx>=m||yy>=n)
                continue;
            else if(a[yy][xx]!=0)
                continue;
            else
            {
                cc++;
                a[yy][xx]=a[p.first][p.second]+1;
                if(a[yy][xx]>=d)
                    d=a[yy][xx];
                v.push(make_pair(yy,xx));
            }
        }
    }
    if(cc==c)
        cout<<d-1;
    else
        cout<<-1;
}
