#include<iostream>
#include<queue>
#include<utility>
using namespace std;
int x[4]={0,0,-1,1};
int y[4]={1,-1,0,0};
int main()
{
    int l,w,ans=0;
    cin>>l>>w;
    int a[l][w];
    for(int i=0; i<l; i++)
    {
        for(int z=0; z<w; z++)
        {
            char q;
            cin>>q;
            if(q=='L')
                a[i][z]=1;
            else
                a[i][z]=0;
        }
    }
    for(int i=0; i<l; i++)
    {
        for(int z=0; z<w; z++)
        {
            if(a[i][z]==1)
            {
                queue<pair<int,int>> v;
                v.push(make_pair(i,z));
                int b[l][w];
                fill(b[0],b[0]+l*w,0);
                b[i][z]=1;
                while(!v.empty())
                {
                    pair<int,int> vv=make_pair(v.front().first,v.front().second);
                    v.pop();
                    for(int c=0; c<4; c++)
                    {
                        int xx=x[c]+vv.second;
                        int yy=y[c]+vv.first;
                        if(yy<0||xx<0||yy>=l||xx>=w)
                            continue;
                        else if(a[yy][xx]==0||b[yy][xx]!=0)
                            continue;
                        else
                        {
                            v.push(make_pair(yy,xx));
                            b[yy][xx]=b[vv.first][vv.second]+1;
                            if(ans<b[yy][xx])
                                ans=b[yy][xx];
                        }
                        
                    }
                }
            }
        }
    }
    cout<<ans-1;
}
/*
BFS문제이다. 문제의 특징은 육지에서 가장 긴 시간이 걸리는 부분을 찾아야 하므로
모든 육지구간에서 BFS를 진행해야 한다. 50*50*50으로 시작복잡도를 충족하므로 충분히 가능하다.
모든 육지부분에서 BFS를 진행하고 나온 거리중 최댓값을 출력하면 된다.
*/
