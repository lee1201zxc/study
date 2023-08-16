#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
#define inf 1000000000
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,a1,a2;
    cin>>n>>m;
    vector<pair<int,int>> v[n];
    int cost[n];
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    for(int i=0; i<n; i++)
        cost[i]=inf;
    for(int i=0; i<m; i++)
    {
        int q,w,e;
        cin>>q>>w>>e;
        if(q==w)
            continue;
        v[q-1].push_back(make_pair(w-1,e));
    }
    for(int i=0; i<n; i++)
    {
        sort(v[i].begin(),v[i].end());
    }
    cin>>a1>>a2;
    cost[a1-1]=0;
    q.push(make_pair(a1-1,0));
    while(!q.empty())
    {
        int node=q.top().first;
        int costs=q.top().second;
        q.pop();
        for(int i=0; i<(int)v[node].size(); i++)
        {
            int V=v[node][i].first;
            int W=v[node][i].second;
            if(cost[node]<costs)
                continue;
			if(costs+W<cost[V])
			{
				cost[V] = costs+W;
				q.push(make_pair(V,costs+W));
			}            
        }
    }
    cout<<cost[a2-1];
}
/*
1일 때 예외 처리,  종료 조건 파악
*/
