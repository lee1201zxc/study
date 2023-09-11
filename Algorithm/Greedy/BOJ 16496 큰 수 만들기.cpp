#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,j=0;
    cin>>n;
    int a[n],b[n];
    fill(b,b+n,0);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]==0)
            j++;
    }
    if(j==n)
    {
        cout<<0;
        return 0;
    }
    for(int i=0; i<n-1; i++)
    {
        for(int z=i+1; z<n; z++)
        {
            string str1=to_string(a[i]);
            string str2=to_string(a[z]);
            str1.append(str2);
            str2.append(str1);
            if(str1.compare(str2)>0)
            {
                b[i]++;
            }
            else
                b[z]++;
        }
    }
    for(int i=0; i<=n; i++)
    {
        for(int z=0; z<n; z++)
        {
            if(b[z]==n-i)
                cout<<a[z];
        }
    }
}
/*
아이디어가 어려운 문제
왜 비교를 하는지 생각해보자

처음에는 맨 앞자리가 같은 숫자들끼리 길이를 맨 앞자리수로 뒤를 채워서 맞춘다음 비교했었는데 반례가 존재했다.

*/
