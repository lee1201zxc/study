#include <iostream>
using namespace std;
int main()
{
    int n,m,k=0,d=0;
    cin>>n>>m;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    int i=0,j=0;
    while(j<n)
    {
        if(k+a[j]<=m)
        {
            k+=a[j];
            if(k==m)
                d++;
            j++;
        }
        else
        {
            k-=a[i];
            if(k==m)
                d++;
            i++;
        }
    }
    cout<<d;
}
