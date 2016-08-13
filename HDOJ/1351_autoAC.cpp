#include <iostream>
using namespace std;
int num[10],ans,C;
void cal(int p, int s) 
{
    if(p==32) return;
    int sum=s,i;
    for(i=0;i<8;i++) sum+=(num[i]>>p)&1;
    if((sum&1)!=((num[8]>>p)&1)) 
    {
        ans|=1<<p;
        sum=s;
        for(i=0;i<8;i++) sum+=((num[i]>>p)&1)^1;
    }
    cal(p+1,sum/2);
}
int main()
{
    for(scanf("%d",&C);C--;)
    {
        for(int i=0;i<9;i++) scanf("%x",&num[i]);
        ans=0;
        cal(0,0);
        printf("%x\n",ans);
    }
    return 0;
}
