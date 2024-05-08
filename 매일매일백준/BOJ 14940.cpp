#include<iostream>
#include<queue>
#include<utility>
using namespace std;
int y[4]={0,0,-1,1};
int x[4]={1,-1,0,0};
int main(void)
{
    int n,m;
    cin>>n>>m;
    int a[n][m],b[n][m];
    fill(b[0],b[0]+n*m,0);
    queue<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        for(int z=0; z<m; z++)
        {
            cin>>a[i][z];
            if(a[i][z]==2)
                v.push(make_pair(i,z));
        }
    }
    b[v.front().first][v.front().second]=0;
    while(!v.empty())
    {
        pair<int,int> vv=make_pair(v.front().first,v.front().second);
        v.pop();
        for(int i=0;i<4;i++)
        {
            int yy=y[i]+vv.first;
            int xx=x[i]+vv.second;
            if(yy<0||yy>=n||xx<0||xx>=m)
                continue;
            else if(a[yy][xx]==0||b[yy][xx]!=0)
                continue;
            else
            {
                v.push(make_pair(yy,xx));
                b[yy][xx]=b[vv.first][vv.second]+1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int z=0;z<m;z++)
        {
            if(a[i][z]==2||a[i][z]==0)
                cout<<0;
            else if(a[i][z]!=0&&b[i][z]==0)
                cout<<-1;
            else
                cout<<b[i][z];
            cout<<' ';
        }
        cout<<'\n';
    }
}
/*
BFS기초 문제, 각 지점마다 최단 거리를 각각 구하는 것이 아닌 목표지점(2)에서 BFS를 시작하여 특정지점까지 얼마나 걸리는지 확인하면 된다.
특정지점에서 목표지점까지의 거리를 구하는 것이 아닌 반대로 목표지점에서 특정지점까지의 거리를 구한다.
BFS는 큐를 이용하여 구한다. 가장 먼저 탐색할 지점을 큐에 넣어주고 큐에서 front()부분을 꺼내주고 이 지점에서 이동할 수 있는 다음 지점을 모두 확인한 후 큐에 넣어준다.
넣어주기전에는 방문했다는 표시를 하고 넣어준다. 이를 큐가 빌때까지 반복해주면 결국에 탐색할 수 있는 곳은 모두 탐색하게 된다.
큐를 구현할 때에는 pair를 이용하여 2개씩 저장할 수 있게 한다. 2차원이기 때문에 x,y를 저장할 공간이 필요하다.
*/
