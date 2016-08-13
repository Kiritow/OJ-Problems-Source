#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
const int MAX=10010;
int DP[MAX];
int rem[MAX];
using namespace std;
typedef struct Mouse
{
    int weight;
    int speed;
    int num;
}mice;
mice s[MAX];
bool cmp(mice x,mice y)
{
    if(x.weight==y.weight)
    return x.speed<y.speed;
    else
    return x.weight>y.weight;
}
int main()
{
    int n,m,maxn,i,j,k,t,mark;
    for(i=1;i<MAX;i++)
    rem[i]=i;
    k=1;
    while(scanf("%d%d",&s[k].weight,&s[k].speed)!=EOF)
    {
        s[k].num=k;
        k+=1;
    }
    sort(s+1,s+k,cmp);
    memset(DP,0,sizeof(DP));
    for(i=1,m=0;i<k;i++)
    {
        maxn=0;
        for(j=1;j<i;j++)
        {
            if(s[i].weight<s[j].weight&&s[i].speed>s[j].speed)
            {
                if(maxn<DP[j])
                {
                    maxn=DP[j];
                    mark=s[j].num;
                }
            }
            if(maxn)
            rem[s[i].num]=mark;
            DP[i]=maxn+1;
            if(m<DP[i])
            {
                m=DP[i];
                t=s[i].num;
            }
        }
    }
    if(m==1)
    {
        cout<<1<<endl<<1<<endl;
    }
    else
    {
        cout<<m<<endl;
        while(rem[t]!=t)
        {
            cout<<t<<endl;
            t=rem[t];
        }
        cout<<t<<endl;
    }
    return 0;
}
