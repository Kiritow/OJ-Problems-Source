#include<iostream>
#include<algorithm>
using namespace std;
__int64 x[100001]={0};
void set(__int64 p1,__int64 p2,__int64 p3,__int64 n)
{
    __int64 a=1,b=1,c=1,k=2,s[3];
    x[1]=1;
    while(k<=n+1)
    {
        s[0]=x[a]*p1;s[1]=x[b]*p2;s[2]=x[c]*p3;
        sort(s,s+3);
        x[k]=s[0];
        if(n+1==k)printf("%I64d\n",x[k]);
        if(s[0]==x[a]*p1)
           a++;
        if(s[0]==x[b]*p2)
           b++;
        if(s[0]==x[c]*p3)
           c++;
        k++;
    }
}
int main()
{
    __int64 p1,p2,p3,i;
    while(scanf("%I64d%I64d%I64d%I64d",&p1,&p2,&p3,&i)!=EOF)
        set(p1,p2,p3,i);
    return 0;
}
