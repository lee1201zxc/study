#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a[n+1],b[m+1];
    a[n]=1000000001,b[m]=1000000001;
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<m; i++)
        cin>>b[i];
    int q=0,w=0;
    while(q!=n||w!=m)
    {
        if(a[q]<b[w])
        {
            cout<<a[q]<<' ';
            q++;
        }
        else
        {
            cout<<b[w]<<' ';
            w++;
        }
    }
}
/*
  두개의 배열에 각각 커서를 두고 작은 것부터 출력하고 커서를 이동
*/
