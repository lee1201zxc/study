#include <iostream>
using namespace std;
int c[500000],ans=0,t=1;
int getparents(int q)
{
    if(c[q]==q)
        return q;
    return c[q]=getparents(c[q]);
}
void unions(int q, int w)
{
    int qq=getparents(q);
    int ww=getparents(w);
    if(qq==ww&&ans==0)
        ans=t;
    else if(qq<ww)
        c[ww]=qq;
    else 
        c[qq]=ww;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
        c[i]=i;
    for(int i=0; i<m; i++)
    {
        int q,w;
        cin>>q>>w;
        unions(q,w);
        t++;
    }
    cout<<ans;
}
