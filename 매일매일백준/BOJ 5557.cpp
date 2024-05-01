#include <iostream>
using namespace std;
int main()
{
    long long n,k;
    cin>>n;
    long long a[n][21],b[n];
    fill(a[0],a[0]+n*21,0);
    for(int i=0; i<n; i++)
        cin>>b[i];
    a[0][b[0]]=1;
    for(int i=1; i<n-1; i++)
    {
        for(int z=0; z<21; z++)
        {
            if(a[i-1][z]!=0)
            {
                if(z+b[i]<21)
                    a[i][z+b[i]]+=a[i-1][z];
                if(z-b[i]>=0)
                    a[i][z-b[i]]+=a[i-1][z];
            }
        }
    }

    cout<<a[n-2][b[n-1]];
}
/*
다이나믹 프로그래밍을 이용 i번째 숫자까지를 이용해서 만들 수 있는 숫자의 경우의 수를 구한다. 1번째 ~ n번째까지 차근차근
*/
