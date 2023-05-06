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
//크루스칼 알고리즘을 이용한 풀이다.
