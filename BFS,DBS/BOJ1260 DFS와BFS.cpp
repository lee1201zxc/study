#include <iostream>
#include<stack>
#include<queue>
using namespace std;
int main()
{
    int n,m,v; //n=정점개수,m=간선개수,v=탐색시작할 노드 번호
    cin>>n>>m>>v;
    int a[n][n],b[n]; //a=그래프구현,b=방문여부
    int bb[n]; //BFS에 쓸 배열
    fill(a[0],a[0]+n*n,0);  //a=1->간선있음
    fill_n(b,n,0);
    fill_n(bb,n,0);
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        a[x-1][y-1]=a[y-1][x-1]=1;
    }
    b[v-1]=1;   //1=방문함,0=방문안함
    {//DFS
        stack<int> s;
        s.push(v);
        cout<<v<<' ';
        while(!s.empty())
        {
            int q=s.top();
            s.pop();
            b[q-1]=1;
            for(int z=0; z<n; z++) //선택된 노드가 어디랑 연결됬는지 간선 확인
            {
                if(q==z+1) //자기자신
                    continue;
                else if(b[z]==1)    //방문했다면
                    continue;
                else if(b[z]==0&&a[q-1][z]==1)
                {
                    cout<<z+1<<' ';
                    s.push(q);
                    s.push(z+1);
                    b[z]=1;
                    break;
                }
            }
        }
    }
    cout<<'\n';
    bb[v-1]=1;
    {//BFS
       queue<int> s;
       s.push(v);
        while(!s.empty())
        {
            int q=s.front();
            s.pop();
            cout<<q<<' ';
            for(int z=0; z<n; z++) //선택된 노드가 어디랑 연결됬는지 간선 확인
            {
                if(q==z+1) //자기자신
                    continue;
                else if(bb[z]==1)    //방문했다면
                    continue;
                else if(bb[z]==0&&a[q-1][z]==1)
                {
                    bb[z]=1;
                    s.push(z+1);
                }
            }
        }       
    }
}
