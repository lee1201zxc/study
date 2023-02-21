#include <iostream>
using namespace std;
int n,a[15]={0,},k=0;
void btr(int g)
{
    if(g==n)
    {
        k++;
        return;
    }
    for(int i=0; i<n; i++)
    {
        int j=0;
        for(int z=0; z<g; z++)
        {
            if(a[z]-z==i-g||a[z]+z==i+g||a[z]==i)
            {
                j=1;
                break;
            }
        }
        if(j==0)
        {
            a[g]=i;
            btr(g+1);
        }
    }
}
int main(void)
{
    cin>>n;
    btr(0);
    cout<<k;
}
/*
    btr(g)->g번째행에 놓을차례
    g번째행의 1열부터n열까지 놓을 수 있는지 검사,
    놓을 수 있다면 놓고 btr(g+1), 못놓으면 되돌아감
    만약 마지막행까지 놓았다면 k++하고 뒤로 돌아감
*/
