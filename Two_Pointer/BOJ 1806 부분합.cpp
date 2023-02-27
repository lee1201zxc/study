#include <iostream>
using namespace std;
int main()
{
    int n,s,d=100000001,dd=0,k=0; //dd=잠시길이,d=최종최소길이,k=수열합
    cin>>n>>s;
    int a[n+1];
    a[n]=0;
    for(int i=0; i<n; i++)
        cin>>a[i];
    int i=0,j=0;
    while(j<=n)
    {
        if(k<s)
        {
            k+=a[j];
            dd++;
            if(k>=s)
            {
                if(dd<d)
                    d=dd;
            }
            j++;
        }
        else
        {
            k-=a[i];
            dd--;
            if(k>=s)
            {
                if(dd<d)
                    d=dd;
            }
            i++;
        }
    }
    if(d==100000001)
        cout<<0;
    else
        cout<<d;
}
/*
  수열의 합이 S이상이면 된다는 것을 확인
*/
