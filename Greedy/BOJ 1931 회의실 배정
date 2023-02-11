#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(pair<int,int>a,pair<int,int>b)
{
    if(a.second==b.second)
        return a.first<b.first;
    else
        return a.second<b.second;
}
int main(void)
{
    int n,k=0;
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end(),cmp);
    k++;
    int j=v[0].second;
    for(int i=1; i<n; i++)
    {
        if(v[i].first>=j)
        {
            j=v[i].second;
            k++;
        }
    }
    cout<<k;
}
/*
  어떤 회의가 끝나면 다음으로는 그 이후의 회의중 가장 먼저 끝나는 회의를 골라야 가장 많이 회의를 진행할 수 있음.
  회의끝나는 순서대로 오름차순 정렬후 최적의 회의를 고름
*/
