#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,d=0,k=0;   //d->마감일 가장 큰거
    cin>>n;
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++)
    {
        int a,b;
        cin>>b>>a;
        v.push_back(make_pair(a,b));
        if(a>d)
            d=a;
    }
    sort(v.begin(),v.end());
    for(int i=d; i>=1; i--)
    {
        int x=-1;
        for(int z=0; z<n; z++)
        {
            if(v[z].first>=i&&v[z].second!=0)
            {
                if(x==-1)
                    x=z;
                else if(v[x].second<v[z].second)
                {
                    x=z;
                }
            }
        }
        k+=v[x].second;
        v[x].second=0;
    }
    cout<<k;
}
/*
  마지막날 가능한 강연중 강연료가 가장 높은 강연 선택하고 그 다음에는
  그전날 가능한 강연중 강연료가 가장 높은 강연 선택....첫째날까지 간다.
*/
