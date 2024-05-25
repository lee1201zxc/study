#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(void)
{
	int n,m;
	cin>>n>>m;
	int ent[n],ans[n];
	fill_n(ent,n,0);
	fill_n(ans,n,0);
	vector<int> v[n];
	queue<int> q;
	for(int i=0; i<m; i++)
	{
		int q,w;
		cin>>q>>w;
		v[q-1].push_back(w-1);
		ent[w-1]++;
	}
	for(int i=0; i<n; i++)
	{
		if(ent[i]==0)
		{
			q.push(i);
			ans[i]=1;
		}
	}
	while(!q.empty())
	{
		int qq=q.front();
		q.pop();
		for(int i=0; i<v[qq].size(); i++)
		{
			ent[v[qq][i]]--;
			if(ent[v[qq][i]]==0)
			{
				q.push(v[qq][i]);
				if(ans[v[qq][i]]<ans[qq]+1)
					ans[v[qq][i]]=ans[qq]+1;
			}
		}
	}
	for(int i=0; i<n; i++)
		cout<<ans[i]<<' ';
}
/*
전형적인 위상정렬 문제이다.
일단 선수과목을 모두 정리한 다음에
선수과목이 없는 과목들먼저 큐에 넣어 탐색한다. 그리고 그 과목을 들어야 들을 수 있는 과목들을 찾아 그 과목의 선수과목수를 1줄인다.
만약 0이라면 더 이상 들을 선수과목이 없으므로 큐에 넣어 탐색한다. 이를 큐가 빌때까지 반복한다.
*/
