#include<iostream>
#include<stack>
#include<utility>
using namespace std;
int main()
{
    stack<pair<int,int>> v;
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<n; i++)
        b[i]=-1;
    for(int i=0; i<n; i++)
    {
        if(v.empty())
            v.push(make_pair(i,a[i]));
        else
        {
            while(!v.empty()&&v.top().second<a[i])
            {
                b[v.top().first]=a[i];
                v.pop();
            }
            v.push(make_pair(i,a[i]));
        }
    }
    for(int i=0; i<n; i++)
        cout<<b[i]<<' ';
}
/*
하나하나 비교하는 방법은 n^2으로 최대 1000000*1000000으로 시간초과가 난다.
더 빠른 방법으로 계산해야 하는데 방법은 바로 스택을 이용하는 것이다.
스택에 숫자들을 넣어주는데 만약 새롭게 넣을 숫자가 스택의 top보다 크다면 -> 새롭게 넣을 숫자는 스택 top에 들어있는 숫자의 오큰수이다.
이럴경우 스택을 pop해주고 다시 비교한다.(top이 더 작을 동안) 이 방법이면 O(n)으로 구할 수 있다.
참고로 이 방법을 Monotone stack(모노톤 스택)이라고 한다.

*/
