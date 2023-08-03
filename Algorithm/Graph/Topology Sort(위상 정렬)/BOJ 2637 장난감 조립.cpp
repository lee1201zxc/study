#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int enter[n],an[n][n];
    fill(enter,enter+n,0);
    fill(an[0],an[0]+n*n,0);
    vector<pair<int,int>> v[n];
    queue<int> q;
    for(int i=0; i<m; i++)
    {
        int q,w,e;
        cin>>q>>w>>e;
        enter[q-1]++;
        v[w-1].push_back(make_pair(q,e));
    }
    for(int i=0; i<n; i++)
    {
        if(enter[i]==0)
        {
            q.push(i);
            an[i][i]=1;
        }
    }
    while(!q.empty())
    {
        int qq=q.front();
        q.pop();
        for(int i=0; i<v[qq].size(); i++)
        {
            enter[v[qq][i].first-1]--;
            for(int z=0; z<n; z++)
            {
                an[v[qq][i].first-1][z]+=an[qq][z]*v[qq][i].second; //이부분 수정
            }
            if(enter[v[qq][i].first-1]==0)
                q.push(v[qq][i].first-1);
        }
    }
    for(int i=0; i<n; i++)
    {
        if(an[n-1][i]!=0)
            cout<<i+1<<' '<<an[n-1][i]<<'\n';
    }
}
