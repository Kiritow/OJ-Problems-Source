#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int top=100100;
struct Num
{
    int val,pos;
}num[top];
bool operator<(Num nl,Num nr)
{
    return nl.val<nr.val;
}
int order[top],tree[top];
int n,i,leftLess,leftMuch,rightLess,rightMuch;
int lowbit(int x)
{
    return x&(-x);
}
void update(int i,int x)
{
    while(i<=n)
    {
        tree[i]+=x;
        i+=lowbit(i);
    }
}
int query(int i)
{
    int ans;
    for(ans=0;i>0;i-=lowbit(i))
    {
        ans+=tree[i];
    }
    return ans;
}
int main()
{
    int t;
    __int64 ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&num[i].val);
            num[i].pos=i;
        }
        sort(num+1,num+n+1);
        order[num[1].pos]=1;
        for(i=2;i<=n;i++)
        {
            if(num[i].val==num[i-1].val)
                order[num[i].pos]=order[num[i-1].pos];
            else
                order[num[i].pos]=i;
        }
        memset(tree,0,sizeof(tree));
        ans=0;
        for(i=1;i<=n;i++)
        {
            update(order[i],1);
            leftLess=query(order[i])-1;                        
            leftMuch=i-leftLess-1;                            
            rightLess=order[i]-leftLess-1;                    
            rightMuch=n-order[i]-leftMuch;                    
            ans+=leftLess*rightMuch+leftMuch*rightLess;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
