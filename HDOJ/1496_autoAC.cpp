#include<stdio.h>
#include<algorithm>
using namespace std;
int f1[1000001];
int f2[1000001];
int A,B,C,D;
int i,j,ans,s;
int main()
{
    while(~scanf("%d%d%d%d",&A,&B,&C,&D))
    {
        ans = 0;
        if(A>0 && B>0 && C>0 && D>0 || A<0 && B<0 && C<0 && D < 0)
        {
            printf("0\n");
            continue;
        }
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        for(i=1;i<=100;i++)
        {
            for(j=1;j<=100;j++)
            {
                s = A*i*i + B*j*j;
                if(s>=0) f1[s]++;
                else f2[-s]++;
            }
        }
        for(i=1;i<=100;i++)
        {
            for(j=1;j<=100;j++)
            {
                s = C*i*i + D*j*j;
                if(s>0) ans += f2[s];
                else ans += f1[-s];
             }
        }
        printf("%d\n",ans*16);
    }
}
