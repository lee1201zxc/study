#include <iostream>
using namespace std;
int r[8],vst[8]={0,},n,m;
void a(int k)
{
    if(k==m)
    {
        for(int i=0; i<m; i++)
            cout<<r[i]+1<<' ';
        cout<<'\n';
        return;
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            if(!vst[i])
            {
                vst[i]=1;
                r[k]=i;
                a(k+1);
                vst[i]=0;
            }
        }
    }
}
using namespace std;
int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  a(0);
}
