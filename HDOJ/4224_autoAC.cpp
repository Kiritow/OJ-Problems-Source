#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        int u1,d1,u2,d2,u3,d3;
        scanf("%d %d %d %d %d %d",&u1,&d1,&u2,&d2,&u3,&d3);
        int a=0,b=0,c=0;
        if(u1<d1)
            a=-1;
        else  if(u1>d1)
            a=1;
        if(u2<d2)
            b=-1;
        else  if(u2>d2)
            b=1;
        if(u3<d3)
            c=-1;
        else  if(u3>d3)
            c=1;
        if( ((a+b+c)==3)||((a+b+c)==-3)||((a*b*c==0)&&((a+b+c==1)||(a+b+c==-1)))||(a+b+c==2)||(a+b+c)==-2)
            printf("Case %d: No\n",k);
        else
            printf("Case %d: Yes\n",k);
    }
    return 0;
}
