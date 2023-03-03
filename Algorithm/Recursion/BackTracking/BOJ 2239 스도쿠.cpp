#include <iostream>
using namespace std;
int a[9][9],c=0;
void sdk(int y,int x)
{
    if(c==1)
        return;
    if(y==9)
    {
        for(int i=0; i<9; i++)
        {
            for(int z=0; z<9; z++)
                cout<<a[i][z];
            cout<<'\n';
        }
        c=1;
        return;
    }
    if(a[y][x])
    {
        if(x==8)
            sdk(y+1,0);
        else
            sdk(y,x+1);        
    }
    int b[10]={0,};
    for(int i=0; i<9; i++)
    {
        if(a[y][i]!=0)//행
            b[a[y][i]]=1;
        if(a[i][x]!=0)//열
            b[a[i][x]]=1;
        for(int z=0; z<9; z++)//주위칸
        {
            if(i/3==y/3&&z/3==x/3&&a[i][z]!=0)
                b[a[i][z]]=1;
        }
    }
    int k=0;
    for(int i=1;i<=9; i++)
        k+=b[i];
    if(k==9)
        return;
    for(int i=1; i<=9; i++)
    {
        if(b[i]==0&&a[y][x]==0)
        {
            a[y][x]=i;
            if(x==8)
                sdk(y+1,0);
            else
                sdk(y,x+1);
            a[y][x]=0;
        }
    }
}
int main()
{
    
    for(int i=0; i<9; i++)
    {
        for(int z=0; z<9; z++)
        {
            char s;
            cin>>s;
            a[i][z]=s-48;
        }
    }
    sdk(0,0);
}
/*
  (0,0)칸 부터 시작해서 (8,8)칸 까지 차례대로 넣을 수 있는 수를 작은 수부터 넣어준다.
  만약 이미 중복되서 넣을 수 있는 숫자가 없다면 return(종료)
*/
