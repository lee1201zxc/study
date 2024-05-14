#include<iostream>
using namespace std;
int main()
{
    int n,m,ans=0;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1; i<(int)s.size()-1; i++)
    {
        if(s[i]=='O'&&s[i-1]=='I'&&s[i+1]=='I')
        {
            int q=0;
            while(s[i]=='O'&&s[i-1]=='I'&&s[i+1]=='I')
            {
                i+=2;
                q++;
            }
            /*
            ioi가 몇개 연속으로 나오는지 확인
            연속으로 나온 개수 - n + 1이 Pn의 개수이다.
            */
            if(q-n+1>0)
                ans+=q-n+1;
        }
    }
    cout<<ans;
}
/*
Pn -> IOI가 연속으로 n개 나와야함.
M은 최대 10000으로 P(n^2)으로는 풀 수 없다.

문자열을 탐색하다 IOI를 만나면 뒤에 IOI가 연속을 몇개 나오는지 확인.
만약 k가나왔다면 이 문자열안에 Pn은 k-n+1개가 존재한다.
이 방법으로 푼다면 O(n)으로 풀 수 있다.

*/
