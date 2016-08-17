#include<stdio.h>
int main()
{    int p,e,i,d,n,T;
    int j,k;
    scanf("%d",&T);
    while(T--)
    {    j=1;
        getchar();    
        while(scanf("%d%d%d%d",&p,&e,&i,&d)!=EOF)
        { 
            if(p==-1&&e==-1&&i==-1&&d==-1)
                break;
            else
            {    n=(    5544*p+14421*e+1288*i-d+21252)%21252;
                if(n==0)
                    n=21252;
                printf("Case %d: the next triple peak occurs in %d days.\n",j++,n);
            }
        }
        if(T!=0)
            printf("\n");
    }
    return 0;
}
