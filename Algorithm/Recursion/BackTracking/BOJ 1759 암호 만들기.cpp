#include<iostream>
#include<algorithm>
using namespace std;
char b[15]={0,};//출력할 암호 저장공간
int l,c,vst[15]={0,};//vst=이미 골랐는지 여부
char a[15];
void src(int n, int q, int w,int s)//n->현재까지 고른 문자 갯수 q,w->모음,자음갯수
{
    if(n==l&&q>0&&w>1)
    {
        for(int i=0; i<l; i++)
            cout<<b[i];
        cout<<'\n';
        return;
    }
    for(int i=s; i<c; i++)
    {
        if(vst[i]==0)
        {
            vst[i]=1;
            b[n]=a[i];
            if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
                src(n+1,q+1,w,i);
            else
                src(n+1,q,w+1,i);
            vst[i]=0;
        }
    }
}
int main()
{
    cin>>l>>c;
    for(int i=0; i<c; i++)
        cin>>a[i];
    sort(a,a+c);
    src(0,0,0,0);
}
/*
  N과 M문제들과 유사, 
*/
