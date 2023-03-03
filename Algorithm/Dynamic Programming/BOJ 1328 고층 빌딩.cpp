#include <iostream>
#define X 1000000007
using namespace std;
int main()
{
    unsigned long long k[101][101],c[101][101]={0,},q=0;
    k[1][1]=k[2][1]=k[2][2]=1;
    for(int i=3; i<=100; i++)
    {
        for(int z=1; z<=100; z++)
        {
            if(z==1)
                k[i][z]=k[i-1][z]*(i-1)%X;
            else if(i==0||i==z)
                k[i][z]=1;
            else
            {
                k[i][z]=(k[i-1][z]*(i-1)%X+k[i-1][z-1])%X;
            }
        }
    }
    for(int i=0; i<=100; i++)
        c[i][0]=1;
    for(int i=1; i<=100; i++)
    {
        for(int z=1; z<=100; z++)
        {
            if(z==i)
                c[i][z]=1;
            else
                c[i][z]=(c[i-1][z]+c[i-1][z-1])%X;
        }
    }
    int n,l,r;
    cin>>n>>l>>r;
    if(n==1&&l==1&&r==1)
        q=1;
    else if(l==1&&r==1)
        q=0;
    else if(l==1)
    {
        q=k[n-1][r-1];
    }
    else if(r==1)
    {
        q=k[n-1][l-1];
    }
    else
    {
        for(int R=r-1; R<=n-1-(l-1); R++)
        {
            int L=n-1-(R);
            q+=(c[n-1][L]*k[L][l-1]%X*k[R][r-1])%X;
        }        
    }
    cout<<q%X;
}
/*
  C[a][b] -> 이항계수 aCb (a개중 b개 선택하는 경우의 수)
  K[a][b] -> a개를 일렬로 배치하여 한쪽에서 바라봤을 때 b개가 보이는 경우의 수
  ex) C를 이용해 이용할 빌딩 정하고 K로 경우의 수를 구함


다른 풀이

#include <iostream>
 
#define MOD 1000000007
using namespace std;
 
int N, L, R;
long long dp[101][101][101];
 
void solve(){
    dp[1][1][1] = 1;
    
    for(int n = 2; n <= N; n++){
        for(int l = 1; l <= N; l++){
            for(int r = 1; r <= N; r++){
                dp[n][l][r] = (dp[n-1][l-1][r] + dp[n-1][l][r-1] + dp[n-1][l][r] * (n-2)) % MOD;
            }
        }
    }
    cout << dp[N][L][R];
}
 
int main(){
    cin >> N >> L >> R;
    solve();
    return 0;
}
높이가 1인 빌딩을 가장 왼쪽에 놓을 때 : 왼쪽에서 보이는 빌딩의 수가 1 늘어난다.
높이가 1인 빌딩을 가장 오른쪽에 놓을 때 : 오른쪽에서 보이는 빌딩의 수가 1 늘어난다.
높이가 1인 빌딩을 가장자리가 아닌 곳에 놓을 때 : 왼쪽, 오른쪽에서 보이는 빌딩의 수에 전혀 영향을 미치지 못한다.
빌딩을 가장자리가 아닌 곳에 놓는 경우의 수는 n-2 가 됨을 알 수 있다.

 위 설명을 점화식으로 나타내면

dp[n][l][r] = dp[n-1][l-1][r] + dp[n-1][l][r-1] + dp[n-1][l][r] * (n-2)
출처 : https://hyeo-noo.tistory.com/94
*/
