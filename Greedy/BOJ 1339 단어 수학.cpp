#include <iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
bool cmp(int a, int c)
{
    return a>c;
}
int main()
{
    int n,a[26][2]={0,},b[26]={0,},ans=0; //a0->0~9값, a1->우선값, b->a저장
    cin>>n;
    vector<string> str;
    for(int i=0; i<n; i++)
    {
        string ss;
        cin>>ss;
        str.push_back(ss);
    }
    for(int i=0; i<n; i++)
    {
        for(int z=0; z<(int)str[i].length(); z++)
        {
            a[str[i][z]-65][1]+=pow(10,str[i].length()-z-1);
            b[str[i][z]-65]+=pow(10,str[i].length()-z-1);
        }
    }
    sort(b,b+26,cmp);
    int k=9;
    for(int i=0; i<26; i++)
    {
        if(b[i]==0)
            break;
        int z=-1;
        while(1)
        {
            z++;
            if(a[z][1]==b[i]&&a[z][0]==0)
            {
                a[z][0]=k--;
                break;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int z=0; z<(int)str[i].length(); z++)
        {
            ans+=a[str[i][z]-65][0]*pow(10,str[i].length()-z-1);
        }
    }
    cout<<ans;
}
/*
  모든 단어들의 우선순위를 지정해 준다음 높은 우선순위를 가진 알파벳부터 높은 숫자를 지정해준다.
*/
