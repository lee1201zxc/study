#include<iostream>
using namespace std;
int max(int a, int b)
{
    if(a<b)
        return b;
    else
        return a;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n;
        cin>>n;
        int a[2][n],b[2][n];
        fill(b[0],b[0]+2*n,0);
        for(int z=0; z<n; z++)
            cin>>a[0][z];
        for(int z=0; z<n; z++)
            cin>>a[1][z];
        b[0][0]=a[0][0];
        b[1][0]=a[1][0];
        for(int z=1; z<n; z++)
        {
            b[0][z]=max(b[0][z-1],b[1][z-1]+a[0][z]);
            b[1][z]=max(b[1][z-1],b[0][z-1]+a[1][z]);
        }
        cout<<max(b[0][n-1],b[1][n-1])<<'\n';
    }
}
/*
전형적인 dp문제이다.
앞에서부터 시작해서 최댓값을 저장해야 한다.
스티커를 선택할 때 만약 위쪽 스티커를 선택한다면 이전에도 위쪽스티커를 선택하면 안된다.
b[0][z]=max(b[0][z-1],b[1][z-1]+a[0][z]);
b[1][z]=max(b[1][z-1],b[0][z-1]+a[1][z]);
이와 같다.
b[][]의 각인덱스는 그 스티커를 선택했을때 최댓값이다.
b[0][z]를 선택하면 바로 옆이였던 b[0][z-1]는 선택할 수 없다.
b[1][z]도 마찬가지이다.
*/
