#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Work
{
    int deadline;
    int score;
}x[1002];
bool cmp(Work a,Work b)
{
    if(a.score==b.score)
        return a.deadline<b.deadline;
    return a.score>b.score;
}
int main()
{
    int t,n,i,j,sum;
    bool a[10002];
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>n;
        for(i=0;i<n;++i)
            scanf("%d",&x[i].deadline);
        for(i=0;i<n;++i)
            scanf("%d",&x[i].score);
        sort(x,x+n,cmp);
        memset(a,0,sizeof(a));
        for(i=0;i<n;++i)
            if(!a[x[i].deadline])
            {
                a[x[i].deadline]=true;
                continue;
            }
            else
            {
                for(j=x[i].deadline-1;j>=1;--j)
                    if(!a[j])
                    {
                        a[j]=true;
                        break;
                    }
                if(j==0)
                    sum+=x[i].score;
            }
        printf("%d\n",sum);
    }
    return 0;
}
