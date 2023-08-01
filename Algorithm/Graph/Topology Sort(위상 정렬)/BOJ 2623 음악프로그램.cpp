#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int enter[n],answer[n],ans=0,t=n;
    fill(enter,enter+n,0);
    fill(answer,answer+n,0);
    vector<int> v[n];
    queue<int> q;
    for(int i=0; i<m; i++)
    {
        int k;
        cin>>k;
        int a[k];
        for(int z=0; z<k; z++)
        {
            cin>>a[z];
            if(z>0)
            {
                enter[a[z]-1]++;
                v[a[z-1]-1].push_back(a[z]-1);
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        if(enter[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int qq=q.front();
        q.pop();
        t--;
        answer[ans++]=qq;
        for(int i=0; i<(int)v[qq].size(); i++)
        {
            enter[v[qq][i]]--;
            if(enter[v[qq][i]]==0)
                q.push(v[qq][i]);
        }
    }
    if(t!=0)
    {
        cout<<0;
        return 0;
    }
    for(int i=0; i<n; i++)
        cout<<answer[i]+1<<'\n';
}
