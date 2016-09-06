#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        int id,n,tot=0;
        scanf("%d %d",&id,&n);
        if(n%3==0) tot++;
        int top=(int)ceil(n*1.0/3);
        for(int i=n/2;i>=top;i--)
        {
            if(n-i==i) continue;
            if((n-i)&1) {tot+=(i-(n-i+1)/2+1)*2;tot--;}
            else {tot+=(i-(n-i)/2+1)*2;tot-=2;}
        }
        printf("%d %d\n",id,tot);
    }
    return 0;
}
