#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
    int n,k=2000000000;
    cin>>n;
    int a[n],b[2];
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    int i=0,j=n-1;
    while(i<j)
    {
        int kk=a[i]+a[j],kkk;
        kkk=kk>0?kk:kk*-1;
        if(kkk<k)
        {
            k=kkk;
            b[0]=a[i],b[1]=a[j];
        }
        if(kk<0)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    cout<<b[0]<<' '<<b[1];
}
