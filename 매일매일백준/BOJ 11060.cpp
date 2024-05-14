#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n][2];
    fill(a[0],a[0]+n*2,0);
    for(int i=0; i<n; i++)
        cin>>a[i][0];
    for(int i=n-2; i>=0; i--)
    {
        int k=1000;
        for(int z=a[i][0]; z>=1 ;z--)
        {
            if(i+z<n)
            {
                if(a[i+z][1]<k)
                    k=a[i+z][1];
            }
        }
        a[i][1]=k+1;
    }
    if(a[0][1]!=1001)
        cout<<a[0][1];
    else
        cout<<-1;
}
/*
전형적인 dp문제이다.
뒤에서 부터 탐색하면서 특정 지점 i에서 도달할 수 있는 모든 곳을 찾고 최소로 도달할 수 있다면 값을 계속 바꿔주는 것이다.
i까지 탐색을 마친다면 i에서 n까지 가는 횟수는 완전히 정해진다.
그렇게 0번재 인덱스 까지 탐색을 마친다면 b[0][1]에는 1~n까지가는 최소 경우가 들어간다.

*/
