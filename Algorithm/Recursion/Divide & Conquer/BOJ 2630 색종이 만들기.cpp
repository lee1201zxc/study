#include <iostream>
using namespace std;
int w=0,b=0,a[128][128];
void rec(int y, int x, int k)
{
    int c[4][2]={0,};//각 사분면 w,b개수
    for(int i=y; i<y+k; i++)
    {
        for(int z=x; z<x+k; z++)
        {
            if(i<(2*y+k)/2&&z<(2*x+k)/2)//2
                c[1][a[i][z]]++;
            else if(i<(2*y+k)/2&&z>=(2*x+k)/2)//1
                c[0][a[i][z]]++;
            else if(i>=(2*y+k)/2&&z<(2*x+k)/2)//3
                c[2][a[i][z]]++;
            else if(i>=(2*y+k)/2&&z>=(2*x+k)/2)//4
                c[3][a[i][z]]++;
        }
    }
    if(c[0][0]+c[1][0]+c[2][0]+c[3][0]==k*k)
    {
        w++;
        return;
    }
    else if(c[0][1]+c[1][1]+c[2][1]+c[3][1]==k*k)
    {
        b++;
        return;
    }
    else
    {
        for(int i=0; i<4; i++)
        {
            if(c[i][0]==k*k/4)
            {
                w++;
                continue;
            }
            else if(c[i][1]==k*k/4)
            {
                b++;
                continue;
            }
            else
            {
                if(i==0)
                    rec(y,x+k/2,k/2);
                else if(i==1)
                    rec(y,x,k/2);
                else if(i==2)
                    rec(y+k/2,x,k/2);
                else
                    rec(y+k/2,x+k/2,k/2);
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int z=0; z<n; z++)
            cin>>a[i][z];
    }
    rec(0,0,n);
    cout<<w<<' '<<b;
}
//4군데 비교후 모두 같은색이면 +1, 아니면 아닌곳 재귀,같은색인곳은+1
