#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n;
    int a[n],b[n][n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        b[0][i]=1;
    }
    for(int i=0; i<n-1; i++)
    {
        if(a[i]==a[i+1])
            b[1][i]=1;
        else
            b[1][i]=0;
    }
    for(int i=2; i<n; i++)
    {
        for(int z=0; z<n-i; z++)
        {
            if(b[i-2][z+1]==1&&a[z]==a[z+i])
                b[i][z]=1;
            else
                b[i][z]=0;
        }
    }
    cin>>k;
    for(int i=0; i<k; i++)
    {
        int q,w;
        cin>>q>>w;
        cout<<b[w-q][q-1]<<'\n';
    }
}
