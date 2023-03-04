#include<iostream>
#include<vector>
using namespace std;
int ans=0;
vector<int> v[50];
void dfs(int w)
{
    if(v[w].size()==0)
    {
        ans++;
        return;
    }
    for(int i=0; i<v[w].size(); i++)
    {
        dfs(v[w][i]);
    }
}
int main()
{
    int n,mom,k;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]==-1)
            mom=i;
        else
            v[a[i]].push_back(i);
    }
    cin>>k;
    if(k==mom)
    {
        cout<<0;
        return 0;
    }
    for(int i=0; i<v[a[k]].size(); i++)
    {
        if(v[a[k]][i]==k)
            v[a[k]].erase(v[a[k]].begin()+i);
    }
    dfs(mom);
    cout<<ans;
}
/*
  vector를 이용해 구현(이진트리가 아닐수도 있어서 map은 안씀)
*/
