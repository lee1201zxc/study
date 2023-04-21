#include<iostream>
#include<string>
using namespace std;
int n,k,ans=0,word[50]={0,},slt=0;
void find(int num,int st)
{
    if(num==0)
    {
        int answer=0;
        for(int i=0; i<n; i++)
        {
            if((word[i]&slt)==word[i])
                answer++;
        }
        if(answer>ans)
            ans=answer;
        return;
    }
    else
    {
        for(int i=st; i<26 ;i++)
        {
            if((slt&(1<<i))==0)
            {
                slt|=(1<<i);
                find(num-1,i);
                slt&=~(1<<i);
            }
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        for(int z=0; z<(int)s.size(); z++)
            word[i]|=1<<(s[z]-'a');
    }
    if(k<5)
    {
        cout<<0;
    }
    else if(k==26)
        cout<<n;
    else
    {
        slt|=1<<('a'-'a');
        slt|=1<<('n'-'a');
        slt|=1<<('t'-'a');
        slt|=1<<('c'-'a');
        slt|=1<<('i'-'a');
        find(k-5,0);
        cout<<ans;        
    }
}
//비트마스크 활용 방법 익히기
