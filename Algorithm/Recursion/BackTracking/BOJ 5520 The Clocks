#include<iostream>
#include<vector>
using namespace std;
int v[9];//각시계몇변 돌리는지
int ans[9]={0,},high=100000000;
int clocks[9],k=0;//clocks=시계 방향 저장 배열
char dials[9][9]={
    {'x','x','.','x','x','.','.','.','.'},
    {'x','x','x','.','.','.','.','.','.'},
    {'.','x','x','.','x','x','.','.','.'},
    {'x','.','.','x','.','.','x','.','.'},
    {'.','x','.','x','x','x','.','x','.'},
    {'.','.','x','.','.','x','.','.','x'},
    {'.','.','.','x','x','.','x','x','.'},
    {'.','.','.','.','.','.','x','x','x'},
    {'.','.','.','.','x','x','.','x','x'}
};
int move(int num)//num=몇번dial 돌리는지
{
    if(num==9)
    {
        int h=0,w=0;
        for(int i=0; i<9; i++)
            h+=clocks[i];
        if(h!=0)
            return 0;
        for(int i=0; i<9; i++)
        {
            w+=v[i];
        }
        if(w<high)
        {
            for(int i=0; i<9; i++)
                ans[i]=v[i];
        }
        return 0;
    }
    for(int i=0; i<4; i++)//0~3번 돌리는 경우
    {
        for(int z=0; z<9; z++)//돌렸을 때 반응하는 시계들
        {
            if(dials[num][z]=='x')
            {
                clocks[z]+=i;
                clocks[z]%=4;
            }
        }
        v[num]=i;
        move(num+1);
        for(int z=0; z<9; z++)//원복시켜야지
        {
            if(dials[num][z]=='x')
            {
                clocks[z]-=i;
                clocks[z]+=4;
                clocks[z]%=4;
            }
        }        
        v[num]=0;//원복시켜야지
    }
    return 0;
}
int main()
{
    for(int i=0; i<9; i++)
        cin>>clocks[i];
    move(0);
    for(int i=0; i<9; i++)
    {
        for(int z=0; z<ans[i]; z++)
            cout<<i+1<<' ';
    }
}
