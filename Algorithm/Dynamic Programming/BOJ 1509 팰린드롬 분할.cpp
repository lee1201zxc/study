#include<iostream>
using namespace std;
int main(void)
{
    string s;
    cin>>s;
    int a[s.size()][s.size()];
    fill(a[0],a[0]+s.size()*s.size(),0);
    for(int i=0; i<s.size(); i++)
        a[0][i]=1;
    for(int i=0; i<s.size()-1; i++)
    {
        if(s[i]==s[i+1])
            a[1][i]=1;
    }
    for(int i=2; i<s.size(); i++)
    {
        for(int z=0; z<s.size()-i; z++)
        {
            if(s[z]==s[z+i]&&a[i-2][z+1]==1)
                a[i][z]=1;
        }
    }
    int dp[s.size()];
    dp[0]=1;
    for(int i=1; i<s.size(); i++)//0~i에서 분할개수 최솟값
    {
        dp[i]=dp[i-1]+1;
        for(int z=i; z>0; z--)
        {
            if(a[z][i-z]==1)
            {
                if(i==z)
                {
                    dp[i]=1;
                    break;
                }
                else if(dp[i-z-1]+1<dp[i])
                    dp[i]=dp[i-z-1]+1;
            }
        }
    }
    cout<<dp[s.size()-1];
}
//모든 부분문자열마다 팰린드롬인지 DP를 통해 구하고
//dp[s.size()]를 통해 1~i번문자 사이의 문자열에서의 최소 분할 개수를 구해준다.
