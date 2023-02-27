#include<iostream>
#include<queue>
using namespace std;
int n,a[20][20],k=0;
void move(int w)
{
    if(w==0)//위
    {
        for(int i=0; i<n; i++)//열
        {
            queue<int> q;
            for(int z=0; z<n; z++)
            {
                if(a[z][i]!=0)
                    q.push(a[z][i]);
                a[z][i]=0;
            }
            int z=0,c[n];
            fill_n(c,n,0);
            while(!q.empty())
            {
                a[z][i]=q.front();
                q.pop();
                if(z>0&&a[z][i]==a[z-1][i]&&c[z-1]==0)
                {
                    a[z-1][i]*=2;
                    if(a[z-1][i]>k)
                        k=a[z-1][i];
                    a[z][i]=0;
                    c[z-1]=1;
                    z--;
                }
                z++;
            }
        }
    }
    else if(w==1)//오른쪽
    {
        for(int i=0; i<n; i++)//행
        {
            queue<int> q;
            for(int z=0; z<n; z++)
            {
                if(a[i][z]!=0)
                    q.push(a[i][z]);
                a[i][z]=0;
            }
            int z=0,c[n];
            fill_n(c,n,0);
            while(!q.empty())
            {
                a[i][z]=q.front();
                q.pop();
                if(z>0&&a[i][z]==a[i][z-1]&&c[z-1]==0)
                {
                    a[i][z-1]*=2;
                    if(a[i][z-1]>k)
                        k=a[i][z-1];
                    a[i][z]=0;
                    c[z-1]=1;
                    z--;
                }
                z++;
            }
        }        
    }
    else if(w==2)//아래
    {
        for(int i=0; i<n; i++)//열
        {
            queue<int> q;
            for(int z=n-1; z>=0; z--)
            {
                if(a[z][i]!=0)
                    q.push(a[z][i]);
                a[z][i]=0;
            }
            int z=n-1,c[n];
            fill_n(c,n,0);
            while(!q.empty())
            {
                a[z][i]=q.front();
                q.pop();
                if(z<n-1&&a[z][i]==a[z+1][i]&&c[z+1]==0)
                {
                    a[z+1][i]*=2;
                    if(a[z+1][i]>k)
                        k=a[z+1][i];
                    a[z][i]=0;
                    c[z+1]=1;
                    z++;
                }
                z--;
            }
        }        
    }
    else if(w==3)//왼쪽
    {
        for(int i=0; i<n; i++)//행
        {
            queue<int> q;
            for(int z=n-1; z>=0; z--)
            {
                if(a[i][z]!=0)
                    q.push(a[i][z]);
                a[i][z]=0;
            }
            int z=n-1,c[n];
            fill_n(c,n,0);
            while(!q.empty())
            {
                a[i][z]=q.front();
                q.pop();
                if(z<n-1&&a[i][z]==a[i][z+1]&&c[z+1]==0)
                {
                    a[i][z+1]*=2;
                    if(a[i][z+1]>k)
                        k=a[i][z+1];
                    a[i][z]=0;
                    c[z+1]=1;
                    z++;
                }
                z--;
            }
        }          
    }
}
void mv(int s)
{
    if(s==5)
    {
        return;
    }
    int b[20][20];
    copy(&a[0][0],&a[0][0]+20*20,&b[0][0]);
    for(int i=0; i<4; i++)
    {
        move(i);
        mv(s+1);
        copy(&b[0][0],&b[0][0]+20*20,&a[0][0]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int z=0; z<n; z++)
        {
            cin>>a[i][z];
            if(k<a[i][z])
                k=a[i][z];
        }
    }
    mv(0);
    cout<<k;
}
/*
  ●같은 숫자가 여러개 있는 경우 어디 부터 합쳐야 할지 생각해 주어야 한다.
  ●한번의 이동에서 한번 합쳐진 블럭은 다시 합쳐질 수 없다.
*/
