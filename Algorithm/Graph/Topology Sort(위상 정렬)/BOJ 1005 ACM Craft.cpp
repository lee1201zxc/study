#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n,k;
        cin>>n>>k;
        int time[n],enter[n],answer[n];
        fill(enter,enter+n,0);
        fill(answer,answer+n,0);
        vector<int> bd[n];
        queue<int> q;
        for(int z=0; z<n; z++)
            cin>>time[z];
        for(int z=0; z<k; z++)
        {
            int w,e;
            cin>>w>>e;
            bd[w-1].push_back(e-1);
            enter[e-1]++;
        }
        for(int z=0; z<n; z++)
        {
            if(enter[z]==0)
            {
                q.push(z);
                answer[z]=time[z];
            }
        }
        while(!q.empty())
        {
            int qq=q.front();
            q.pop();
            for(int z=0; z<(int)bd[qq].size(); z++)
            {
                if(answer[bd[qq][z]]<time[bd[qq][z]]+answer[qq])
                {
                    answer[bd[qq][z]]=time[bd[qq][z]]+answer[qq];
                }
                enter[bd[qq][z]]--;
                if(enter[bd[qq][z]]==0)
                    q.push(bd[qq][z]);
            }
        }
        int w;
        cin>>w;
        cout<<answer[w-1]<<'\n';
    }
}
