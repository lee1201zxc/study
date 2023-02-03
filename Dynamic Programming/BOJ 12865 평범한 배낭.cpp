#include<iostream>
using namespace std;
int main(void)
{
    long long n,k,h=0;
    cin>>n>>k;
    int a[n][2],b[n][k+1];
    fill(b[0],b[0]+n*(k+1),0);
    for(int i=0; i<n; i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    if(a[0][0]<=k)
    {
        b[0][a[0][0]]=a[0][1];
        h=a[0][1];
    }
    for(int i=1; i<n; i++)
    {
        if(a[i][0]>k)
            continue;
        for(int z=1; z<=k; z++)
        {
            b[i][z]=b[i-1][z];
            if(z==a[i][0]&&a[i][1]>b[i][z])
            {
                if(a[i][1]>b[i][z])
                    b[i][z]=a[i][1];
                if(b[i][z]>h)
                    h=b[i][z];
            }
                        if(z-a[i][0]<=0)
                continue;
            else if(b[i-1][z-a[i][0]]!=0&&b[i-1][z-a[i][0]]+a[i][1]>b[i][z])
            {
                if(b[i-1][z-a[i][0]]+a[i][1]>b[i][z])
                    b[i][z]=b[i-1][z-a[i][0]]+a[i][1];
            }
            if(b[i][z]>h)
                h=b[i][z];
        }
    }
    cout<<h;
}

/*
   knapsack 알고리즘,
   예제가 
   4 7
   6 13
   4 8
   3 6
   5 12
   일때
          각 가방의 무게
   무게6 -> 0 0 0 0 0 13 13
   무게4 -> 0 0 0 8 8 13 13
   무게3 -> 0 0 6 8 8 13 14
   무게5 -> 0 0 6 8 12 13 14
   
   ●물건을 하나씩 추가해가며 최대 가치를 찾음
*/
