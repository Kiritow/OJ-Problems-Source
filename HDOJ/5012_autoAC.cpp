#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct node
{
    int s1,s2,s3,s4,s5,s6;
    int sum;
} q[800000];
int a[7],b[7];
int c[7][7][7][7][7][7];
void bfs()
{
    memset(c,0,sizeof(c));
    struct node t,r;
    t.s1=b[1];
    t.s2=b[2];
    t.s3=b[3];
    t.s4=b[4];
    t.s5=b[5];
    t.s6=b[6];
    t.sum=0;
    int k=0,l=0;
    q[l++]=t;
    while(k<l)
    {
        t=q[k++];
        if(t.s1==a[1] && t.s2==a[2] && t.s3==a[3] && t.s4==a[4] && t.s5==a[5] && t.s6==a[6])
        {
            printf("%d\n",t.sum);
            return ;
        }
        for(int i=0; i<4; i++)
        {
            if(i==0)
            {
                r.s1=t.s4;
                r.s2=t.s3;
                r.s3=t.s1;
                r.s4=t.s2;
                r.s5=t.s5;
                r.s6=t.s6;
            }
            else if(i==1)
            {
                r.s1=t.s3;
                r.s2=t.s4;
                r.s3=t.s2;
                r.s4=t.s1;
                r.s5=t.s5;
                r.s6=t.s6;
            }
            else if(i==2)
            {
                r.s1=t.s5;
                r.s2=t.s6;
                r.s3=t.s3;
                r.s4=t.s4;
                r.s5=t.s2;
                r.s6=t.s1;
            }
            else
            {
                r.s1=t.s6;
                r.s2=t.s5;
                r.s3=t.s3;
                r.s4=t.s4;
                r.s5=t.s1;
                r.s6=t.s2;
            }
            if(!c[r.s1][r.s2][r.s3][r.s4][r.s5][r.s6])
            {
                c[r.s1][r.s2][r.s3][r.s4][r.s5][r.s6]=1;
                r.sum=t.sum+1;
                q[l++]=r;
            }
        }
    }
    printf("-1\n");
}
int main()
{
    while(~scanf("%d",&a[1]))
    {
        for(int i=2; i<=6; i++)
            scanf("%d",&a[i]);
        for(int i=1; i<=6; i++)
        scanf("%d",&b[i]);
          bfs();
    }
    return 0;
}
