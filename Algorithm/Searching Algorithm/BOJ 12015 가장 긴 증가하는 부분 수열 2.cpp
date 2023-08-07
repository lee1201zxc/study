#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    vector<int> v;
    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<n; i++)
    {
        if(i==0||v.back()<a[i])
            v.push_back(a[i]);
        else
        {
            int idx=lower_bound(v.begin(),v.end(),a[i])-v.begin();
            v[idx]=a[i];
        }
    }
    cout<<v.size();
}
//DP가 아닌 이분 탐색을 이용, 중요한 개념
