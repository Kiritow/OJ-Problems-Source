#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int F[1000];
    int A,B,C,T,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&A,&B,&C);
        F[0]=A,F[1]=B;
        int flag=0;
        for(i=2;;i++)
        {
            F[i]=F[i-1]+F[i-2];
            if(F[i]==C)
            {
                flag=1;
                break;
            }
            if(F[i]>C)
            {
                break;
            }
        }
        if(F[0]==C||F[1]==C) flag=1;
        if(flag==1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
