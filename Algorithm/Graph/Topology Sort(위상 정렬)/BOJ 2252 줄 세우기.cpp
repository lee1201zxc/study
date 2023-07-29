#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int enter[n],answer[n],k=0;
    fill(enter,enter+n,0);
    queue<int> q;
    vector<int> v[n];
    for(int i=0; i<m; i++)
    {
        int w,e;
        cin>>w>>e;
        v[w-1].push_back(e-1);
        enter[e-1]++;
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
        answer[k++]=qq;
        for(int i=0; i<(int)v[qq].size(); i++)
        {
            enter[v[qq][i]]--;
            if(enter[v[qq][i]]==0)
            {
                q.push(v[qq][i]);
            }
        }
    }
    for(int i=0; i<k; i++)
        cout<<answer[i]+1<<' ';
}
/*
위상 정렬 기본 문제
*/
