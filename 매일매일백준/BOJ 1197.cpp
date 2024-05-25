#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,pair<int,int>>> a;//간선의 정보와 가중치의 정보
int mom[100001];//각 정점에서 연결된 최소값
bool cmp(pair<int,pair<int,int>> aa,pair<int,pair<int,int>> bb)
{
    return aa.second.second<bb.second.second;
}
int getm(int s)
{
    if(mom[s]==s)
        return s;
    return mom[s]=getm(mom[s]);
}
void unions(int a,int b)
{
    a=getm(a);
    b=getm(b);
    if(a>b)
        mom[a]=b;
    else
        mom[b]=a;   
}
int main()
{
    int v,e,ans=0;
    cin>>v>>e;
    for(int i=1; i<=e; i++)
        mom[i]=i;
    for(int i=0; i<e; i++)
    {
        int b,c,d;
        cin>>b>>c>>d;
        a.push_back(make_pair(b,make_pair(c,d)));
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=0; i<e; i++)
    {
        int q1=getm(a[i].first);
        int q2=getm(a[i].second.first);
        if(q1==q2)
            continue;
        else
        {
            unions(a[i].first,a[i].second.first);
            ans+=a[i].second.second;
        }
    }
    cout<<ans;
}
/*
최소스패닝트리 기본문제
입력으로 주어진 a,b,c(정점,정점,가중치)를 가중치를 오름차순으로 정렬한 기준으로 정렬한 후
가중치가 낮은 간선부터 넣어본다. 만약 간선을 추가했을 때 사이클을 이루지 않았다면 이 간선을
추가하는 것이 옳으므로 ans(최소스패닝트리 가중치)에 이 간선의 가중치 값을 더해준다.
만약 사이클을 이루면 더이상 트리가 아니므로 넘어간다.
이를 모든 간선을 탐색할때까지 반복하면 된다.
*/
