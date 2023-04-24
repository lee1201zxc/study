#include <iostream>
using namespace std;
int n,m,c[200];
int getparent(int x)
{
    if(c[x]==x)
        return x;
    return c[x]=getparent(c[x]);
}
void unions(int a, int b)
{
    a=getparent(a);
    b=getparent(b);
    if(a<b)
        c[b]=a;
    else
        c[a]=b;
}
int main()
{
    int k,d,dd;
    cin>>n;
    cin>>m;
    for(int i=0; i<n; i++)
        c[i]=i;
    for(int i=0; i<n; i++)
    {
        for(int z=0; z<n; z++)
        {
            int a;
            cin>>a;
            if(a==1)
            {
                unions(i,z);
            }
        }
    }
    cin>>k;
    d=getparent(k-1);
    for(int i=1; i<m; i++)
    {
        cin>>k;
        dd=getparent(k-1);
        if(dd!=d)
        {
            cout<<"NO";
            return 0;
        }
        d=dd;
    }
    cout<<"YES";
}
