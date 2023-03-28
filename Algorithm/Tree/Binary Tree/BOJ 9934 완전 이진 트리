#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
vector<int> a[10];
vector<int> b;
void trc(int d, int s, int e)
{
    if(s==e)
        return;
    int m=(s+e)/2;
    a[d].push_back(b[m]);
    trc(d+1,s,m);
    trc(d+1,m+1,e);
}
int main(void)
{
    int n;
    cin>>n;
    for(int i=0; i<pow(2,n); i++)
    {
        int k;
        cin>>k;
        b.push_back(k);
    }
    trc(0,0,b.size()-1);
    for(int i=0; i<n; i++)
    {
        for(int z=0; z<a[i].size(); z++)
            cout<<a[i][z]<<' ';
        cout<<'\n';
    }
}
/*
  완전 이진 트리의 특징 -> 부모 노드를 기준으로 왼쪽, 오른쪽 노드의 모양이 완전히 같다(재귀이용하기 용이)
*/
