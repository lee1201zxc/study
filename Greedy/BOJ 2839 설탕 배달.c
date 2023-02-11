#include <stdio.h>
int main()
{
    int n,k=0;
    scanf("%d",&n);
    while(1)
    {
        if(n%5==0)
        {
            k+=n/5;
            printf("%d",k);
            break;
        }
        else
        {
            k++;
            n-=3;
        }
        if(n<0)
        {
            printf("-1");
            break;
        }
    }
}

/*
  5kg을 많이 써야 최소 개수가 나오므로 5kg으로만 못 만들때 3kg짜리를 하나씩 추가해가며 구한다.
*/
