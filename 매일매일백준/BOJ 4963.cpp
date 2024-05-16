#include<iostream>
#include<utility>
#include<queue>
int x[8]={0,0,-1,1,-1,-1,1,1};
int y[8]={1,-1,0,0,1,-1,1,-1};
using namespace std;
int main()
{
    while(1)
    {
        int w,h,d=0;
        cin>>w>>h;
        if(w==0&&h==0)
            break;
        int a[h][w];
        for(int i=0;i<h;i++)
        {
            for(int z=0;z<w;z++)
            {
                cin>>a[i][z];
            }
        }
        for(int i=0;i<h;i++)
        {
            for(int z=0;z<w;z++)
            {
                queue<pair<int,int>>v;
                if(a[i][z]==1)
                {
                    d++;
                    v.push(make_pair(i,z));
                    while(!v.empty())
                    {
                        pair<int,int> p=make_pair(v.front().first,v.front().second);
                        v.pop();
                        for(int s=0; s<8; s++)
                        {
                            int xx=x[s]+p.second,yy=y[s]+p.first;
                            if(xx<0||yy<0||xx>=w||yy>=h)
                                continue;
                            else if(a[yy][xx]==0)
                                continue;
                            else
                            {
                                a[yy][xx]=0;
                                v.push(make_pair(yy,xx));
                            }
                        }
                    }
                }
            }
        }
        cout<<d<<'\n';
    }
}
/*
가장 기본적인 BFS문제이다.
분리된 땅이 몇개인지 세는 문제이다.
BFS는 큐를 이용하여 구현한다. 모든 지점을 탐색하다 땅을 만나면 이 구역을 큐에 넣는다. 그리고 큐가 빌때까지 반복한다. 
-> 큐에서 하나꺼내고 그 구역의 주변을 탐색한다. 구역이 땅이라면 방문표시를하고 큐에 넣는다. -> 이를 반복한다.

*/
