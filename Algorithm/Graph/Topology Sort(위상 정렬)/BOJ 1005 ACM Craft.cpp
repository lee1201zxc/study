#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(void)
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		int n,k;
		cin>>n>>k;
		//time -> 그 건물 짓는데 걸리는 시간
		int time[n];
		// 이 건물 직전에 건설해야하는 건물 수
		int enter[n];
		//건물 건설하는데 걸리는 최종 시간
		int answer[n];
		//이 건물 건설해야 건설 가능한 건물들 리스트가  있음
		vector<int> bd[n];
		//큐임, 바로 건설 가능한 건물들, enter값이 0인거들어감
		queue<int> q;
		fill(enter,enter+n,0);
		fill(answer,answer+n,0);
		for(int z=0; z<n; z++)
		{
			cin>>time[z];
		}
		for(int z=0; z<k; z++)
		{
			int x,y;
			cin>>x>>y;
			bd[x-1].push_back(y-1);
			enter[y-1]++;
		}
		int w;
		cin>>w;
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
			for(int z=0; z<bd[qq].size(); z++)
			{
				if(answer[bd[qq][z]]<time[bd[qq][z]]+answer[qq])
					answer[bd[qq][z]]=time[bd[qq][z]]+answer[qq];
				enter[bd[qq][z]]--;
				if(enter[bd[qq][z]]==0)
					q.push(bd[qq][z]);
			}
		}
		cout<<answer[w-1]<<'\n';
	}
}
