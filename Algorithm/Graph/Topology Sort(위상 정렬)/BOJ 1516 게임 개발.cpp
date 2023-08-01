#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int time[n],enter[n],answer[n];
    fill(enter,enter+n,0);
    fill(answer,answer+n,0);
    vector<int> v[n];
    queue<int> q;
    for(int i=0; i<n; i++)
    {
        cin>>time[i];
        int k=1;
        while(1)
        {
            cin>>k;
            if(k==-1)
                break;
            enter[i]++;
            v[k-1].push_back(i);
        }
    }
    for(int i=0; i<n; i++)
    {
        if(enter[i]==0)
        {
            q.push(i);
            answer[i]=time[i];
        }
    }
    while(!q.empty())
    {
        int qq=q.front();
        q.pop();
        for(int i=0; i<v[qq].size(); i++)
        {
            enter[v[qq][i]]--;
            if(enter[v[qq][i]]==0)
            {
                q.push(v[qq][i]);
            }
            if(answer[v[qq][i]]<time[v[qq][i]]+answer[qq])
                answer[v[qq][i]]=time[v[qq][i]]+answer[qq]; 
        }
    }
    for(int i=0; i<n; i++)
        cout<<answer[i]<<'\n';
}
