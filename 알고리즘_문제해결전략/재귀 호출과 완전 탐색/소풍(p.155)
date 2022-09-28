#include <iostream>
using namespace std;
int k=0;
int h(int a[][2],int b[],int n, int z, int m)
{
    b[a[z][0]]=b[a[z][1]]=1;
    if(n==0)
    {
        k++;
        return 1;
    }
    for(int i=z+1; i<m; i++)
    {
        if(b[a[i][0]]==0&&b[a[i][1]]==0)
            h(a,b,n-1,i,m);
    }
    return 0;
}
int main()
{
    int c,n,m;
    cin>>c;
    for(int i=0;i<c;i++)
    {
        k=0;
        cin>>n>>m;
        int a[m][2],b[n]={0,};
        for(int z=0; z<m; z++)
            cin>>a[z][0]>>a[z][1];
        for(int z=0; z<m; z++)
            h(a,b,n/2,z,m);
        cout<<k<<"\n";
    }
}
