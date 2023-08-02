#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int enter[n],answer[n],k=0,u=n;
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
        sort(v[i].begin(),v[i].end());
    while(u!=0)
    {
        for(int i=0; i<n; i++)
        {
            if(enter[i]==0)
            {
                q.push(i);
                enter[i]=-1;
                break;
            }
        }
        while(!q.empty())
        {
            int qq=q.front();
            q.pop();
            u--;
            answer[k++]=qq;
            for(int i=0; i<(int)v[qq].size(); i++)
            {
                enter[v[qq][i]]--;
            }
            for(int i=0; i<n; i++)
            {
                if(enter[i]==0)
                {
                    enter[i]=-1;
                    q.push(i);
                    break;
                }
            }
        }
    }
    for(int i=0; i<k; i++)
        cout<<answer[i]+1<<' ';
}
/*
쉬운 문제부터 풀어야 하기 때문에 우선순위큐를 이용하여 우선순위가 높은거 부터 풀면됨.
but 나는 그냥 vector마다 정렬을 해줌. 이래도 시간초과안나서
*/
