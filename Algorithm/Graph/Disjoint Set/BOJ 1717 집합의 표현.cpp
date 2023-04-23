#include <iostream>
using namespace std;
int c[1000001];
int getparent(int x)
{
    if(c[x]==x)
        return x;
    return c[x]=getparent(c[x]);
}
void unions(int a,int b)
{
    a=getparent(a);
    b=getparent(b);
    if(a>b)
        c[a]=b;
    else
        c[b]=a;
}
void find(int a, int b)
{
    a=getparent(a);
    b=getparent(b);
    if(a==b)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n+1; i++)
    {
        c[i]=i;
    }
    for(int i=0; i<m; i++)
    {
        int s,a,b;
        cin>>s>>a>>b;
        if(s==0)
        {
            unions(a,b);
        }
        else
        {
            find(a,b);
        }
    }
}
//기본 문제이므로 잘 기억해두기
