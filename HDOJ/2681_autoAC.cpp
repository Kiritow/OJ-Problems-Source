#include<iostream>
#include<cmath>
#include<algorithm>
#define maxn 200+10
using namespace std;
class Girl
{
public:
    int s,t;
    bool operator <(const class Girl g)
    {
        if(s==g.s)
            return t<g.t;
        return s<g.s;
    }
};
Girl girl[maxn];
int tmp[maxn];
bool cmp(const int & a,const int & b)
{
    return a>b;
}
int main()
{
    int n,k,MAXK;
    int sum,ans;
    int i,j,cnt;
    while(scanf("%d%d%d",&n,&k,&MAXK)!=EOF)
    {
        ans=0;
        for(i=0;i<n;i++)
            scanf("%d%d",&girl[i].s,&girl[i].t);
        sort(girl,girl+n);
        for(i=0;i<n;i++)
        {
            tmp[0]=girl[i].t;
            for(j=i+1,cnt=1;j<n;j++)
                if(girl[j].s-girl[i].s<=MAXK)
                    tmp[cnt++]=girl[j].t;
            if(cnt<k)
                continue;
            sort(tmp,tmp+cnt,cmp);
            for(sum=j=0;j<cnt&&j<k;j++)
                sum+=tmp[j];
            if(j==k && sum>ans)
                ans=sum;
        }
        printf("%d\n",ans==0?-1:ans);
    }
}
