#include<iostream>
#include<queue>
#include<utility>
using namespace std;
int x[4]={0,0,-1,1};
int y[4]={1,-1,0,0};
int main(void)
{
    int n,m,d1=0,k=0;
    cin>>n>>m;
    int a[n][m],b[n][m];
    fill(a[0],a[0]+n*m,0);
    fill(b[0],b[0]+n*m,0);
    for(int i=0;i<n;i++)
    {
        for(int z=0;z<m;z++)
            cin>>a[i][z];
    }
    queue<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        for(int z=0;z<m;z++)
        {
            int d2=0;
            if(a[i][z]==1)
            {
                v.push(make_pair(i,z));
                b[i][z]=1;
                d1++;
                d2++;
                if(d2>k)
                    k=d2;
            }
            while(!v.empty())
            {
                pair<int,int>p=make_pair(v.front().first,v.front().second);
                v.pop();
                for(int s=0;s<4;s++)
                {
                    int yy=y[s]+p.first,xx=x[s]+p.second;
                    if(yy<0||xx<0||yy>=n||xx>=m)
                        continue;
                    else if(a[yy][xx]==1&&b[yy][xx]==0)
                    {
                        a[yy][xx]=a[p.first][p.second]+1;
                        b[yy][xx]=1;
                        v.push(make_pair(yy,xx));
                        d2++;
                        if(k<d2)
                            k=d2;
                    }
                }
            }
        }
    }
    cout<<d1<<'\n'<<k;
}
/*
BFS문제이다.
일반적인 BFS문제이지만 가장 넓은 그림, 그림의 개수 두가지를 신경써야 한다.
가장 넓은 그림은 각각의 BFS를 끝냈을 때 가장 넓은 것을 저장하면 되고
그림의 개수는 while문을 반복할 때마다 개수를 추가해주면 된다.
*/
