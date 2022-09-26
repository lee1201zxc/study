#include<iostream>
using namespace std;
const char board[5][5]={{'U','R','L','P','M'},{'X','P','R','E','T'},{'G','I','A','E','T'},{'X','T','N','Z','Y'},{'X','O','Q','R','S'}}; //보드판
const int dx[8]={1,1,1,0,0,-1,-1,-1}; //x좌표 방향
const int dy[8]={-1,0,1,-1,1,-1,0,1}; //y좌표 방향
const string word="GIRL"; //찾을 단어
const int Y=2,X=0; //찾을 단어의 첫 위치(좌표)
int k=0;
int hasWord(int y,int x, char s,int len)
{
    if(board[y][x]==s)
    {
        if(len==1)
        {
            k=1;
            return 1;
        }
        //cout<<len<<'\n';
        for(int direction=0; direction<8; direction++)
        {
            hasWord(y+dy[direction],x+dx[direction],word[word.size()-len+1],len-1);
        }
    }
    return 0;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    hasWord(Y,X,word[0],word.size());
    if(k==1)
        cout<<word<<"는 존재\n";
    else
        cout<<word<<"는 존재X\n";
}
