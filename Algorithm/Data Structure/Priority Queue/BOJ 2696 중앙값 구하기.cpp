#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int m;
        cin>>m;
        int a[m];//값 저장
        vector<int> b;//중앙값 저장
        priority_queue<int> small;//큰 값이 나옴
        priority_queue<int,vector<int>, greater<int>> big;//작은 값이 나옴
        for(int z=0; z<m; z++)
        {
            cin>>a[z];
            if(z==0)
            {
                b.push_back(a[z]);
                continue;
            }
            else if(z==1)
            {
                if(a[0]<a[1])
                {
                    big.push(a[1]);
                    small.push(a[0]);
                }
                else
                {
                    big.push(a[0]);
                    small.push(a[1]);
                }
            }
            else if(z%2==0)//홀수번째
            {
                if(small.top()<a[z])
                {
                    big.push(a[z]);
                    b.push_back(big.top());
                }
                else
                {
                    small.push(a[z]);
                    b.push_back(small.top());
                }
            }
            else//짝수번째
            {
                if(small.top()<a[z])
                {
                    if(small.size()>big.size())
                    {
                        big.push(a[z]);
                    }
                    else
                    {
                        big.push(a[z]);
                        int k=big.top();
                        big.pop();
                        small.push(k);
                    }
                }
                else
                {
                    if(small.size()<big.size())
                    {
                        small.push(a[z]);
                    }
                    else
                    {
                        small.push(a[z]);
                        int k=small.top();
                        small.pop();
                        big.push(k);
                    }                    
                }
            }
        }
        cout<<(int)b.size()<<'\n';
        for(int z=0; z<(int)b.size(); z++)
        {
            if((z+1)%10==0)
                cout<<b[z]<<'\n';
            else
                cout<<b[z]<<' ';
        }
        if((int)b.size()%10!=0)
            cout<<'\n';
    }
}
/*
우선 순위 큐를 두개를 이용해서 푸는 특이한 문제
*/
