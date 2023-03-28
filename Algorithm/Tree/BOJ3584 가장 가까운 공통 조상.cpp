#include <iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0; i<t; i++)
    {
        int n,p=0;
        cin>>n;
        int b[n+1];
        fill(b,b+n+1,0);
        vector<int> v[n+1];
        for(int z=1; z<n; z++)
        {
            int a,b;
            cin>>a>>b;
            v[b].push_back(a);
        }
        int a[2];
        cin>>a[0]>>a[1];
        b[a[0]]=b[a[1]]=1;
        for(int z=0; z<2; z++)
        {
            int k=a[z];
            while(!empty(v[k]))
            {
                if(b[v[k][0]]==1)
                {
                    cout<<v[k][0]<<'\n';
                    p=1;
                    break;
                }
                if(p==1)
                    break;
                k=v[k][0];
                b[k]=1;
            }
        }
    }
}
/*
아래 노드부터 루트노드쪽으로 나아가면서 방문을 기록, 이렇게 두번 반복하면서 처음으로 방문했던 곳 또 방문하면 그곳이 공통 조상
*/
