#include <iostream>
#include<vector>
using namespace std;
int c[100001]={0,};
vector<int> a[100001];
void dfs(int k)
{
    for(int i=0; i<a[k].size(); i++)
    {
        if(c[a[k][i]]==0)
        {
            c[a[k][i]]=1;
            dfs(a[k][i]);
        }
        else if(c[a[k][i]]!=0)
        {
            c[k]=a[k][i];
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        int q,w;
        cin>>q>>w;
        a[q].push_back(w);
        a[w].push_back(q);
    }
    c[1]=1;
    dfs(1);
    for(int i=2; i<100001; i++)
    {
        if(c[i]!=0)
            cout<<c[i]<<'\n';
    }
}
//이진트리가 아님!
