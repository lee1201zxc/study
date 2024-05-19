#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n,ans=0;
        cin>>n;
        vector<pair<int,int>> a;
        for(int z=0; z<n; z++)
        {
            int q,w;
            cin>>q>>w;
            a.push_back(make_pair(q,w));
        }
        sort(a.begin(),a.end());
        int s=a[0].second;
        for(int z=1; z<n; z++)
        {
            if(s<a[z].second)
                ans++;
            else
                s=a[z].second;
        }
        cout<<n-ans<<'\n';
    }
}
/*
그리디 알고리즘을 활용하는 문제이다.
지원자를 서류심사 성적을 기준으로 오름차순 정렬하면
앞에 있는 지원자의 서류심사 성적은 뒤에 있는 지원자보다 성적이 무조건 더 높으므로(순위가 높음)
면접 성적만 비교하면 된다.
정렬이후 배열을 앞에서부터 탐색하면서 뒤 지원자의 면접성적이 지금까지 앞 지원자들의 면접성적보다 더 낮다면 뒤 지원자는 선발할 수 없다. 
만약 더 높다면 앞에서 부터 지금까지 지원자들의 면접성적중 가장 높은 것이 되므로 비교값을 이것으로 바꿔준다.
*/
