#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long n,m,ans=0;
    cin>>n>>m;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);
    int start=0,end=a[n-1];
    while(start<=end)
    {
        long long mid=(start+end)/2,max=0;
        //모든 나무를 높이만큼 자르기
        for(int i=0; i<n; i++)
        {
            if(a[i]>mid)
            {
                max+=a[i]-mid;
            }
        }
        //만약 자른 모든 길이가 m보다 크다면 자르는 높이를 줄이기(절반)
        if(max>=m)
        {
            start=mid+1;
            if(mid>ans)
            {
                ans=mid;
            }
        }
        else//더 크다면 높이 줄이기
            end=mid-1;
    }
    cout<<ans;
}
/*
매개변수 탐색을 이용하는 문제이다.
이분 탐색과 매개변수 탐색 모두 찾는 구간을 절반으로 나누어 재귀적으로 빠르게 찾는 방식인데
차이점은 이분 탐색은 특정 값을 찾는다면 매개변수 탐색은 특정 조건을 만족하는 최대값 혹은 최소값을 찾을 때까지 탐색을 계속한다.
구현은 처음에는 처음~끝까지 탐색을 하고 그 중간인 mid에서 조건을 만족한다면 탐색구간을 절반으로 줄인다.(mid뒤쪽) 만족하지 않는다면(mid앞쪽으로)
이를 계속반복한다.(start<=end)까지
*/
