#include<iostream>
#include<vector>>
#include<algorithm>
using namespace std;
int main(void)
{
	int n;
	cin>>n;
	vector<int>a,b;
	for(int i=n; i>=3; i-=3)
	{
		a.push_back(i);
		b.push_back(i-1);
		b.push_back(i-2);
	}
	if(n%3==2)
	{
		a.push_back(1);
		b.push_back(2);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	cout<<a.size()<<'\n';
	for(int i=0; i<a.size(); i++)
		cout<<a[i]<<' ';
	cout<<'\n';
	cout<<b.size()<<'\n';
	for(int i=0; i<b.size(); i++)
		cout<<b[i]<<' ';	
}
/*
피보나치 수열 원리를 이용하면 쉬운 문제이다.
피보나치 수열에서 a(n)=a(n-1)+a(n-2)이다
즉 기념품을 세림, 성주한테 배분할 때 합이 같게 하려면 한 사람에게 a(n)을 주고 다른 한 사람에게 a(n-1),a(n-2)를 주면 된다.
이게 끝이다!
한가지 예외처리해야 할게 있는데 만약 이렇게 나눠주고 나서 1이 2개 남는다면?(f(1), f(2)) 두 사람에게 각각 하나씩 나눠주면 된다.

*/
