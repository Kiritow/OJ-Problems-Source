#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define MAX 1005
int cnt;
struct node
{
    int flag;
    int next[26],fail;
} head[MAX];
queue<int> q;
double pt[30],dp[MAX][30];
void build(char *s,int idx)
{
    int len=strlen(s),k;
    for(int i=0; i<len; ++i)
    {
        k=s[i]-'a';
        if(head[idx].next[k]==0)
            head[idx].next[k]=(cnt++);
        idx=head[idx].next[k];
    }
    head[idx].flag=1;
}
void build_fail(int idx)
{
    int now;
    queue<int> q;
    head[idx].fail=0;
    q.push(idx);
    for(; !q.empty();)
    {
        now=q.front();
        q.pop();
        for(int i=0; i<26; ++i)
            if(head[now].next[i])
            {
                if(now==0) head[head[now].next[i]].fail=0;
                else       head[head[now].next[i]].fail=head[head[now].fail].next[i];
                q.push(head[now].next[i]);
            }
            else
            {
                if(now==0) head[now].next[i]=0;
                else       head[now].next[i]=head[head[now].fail].next[i];
            }
    }
}
int main()
{
    int n,m,v;
    double t;
    char s[1005];
    for(; scanf("%d%d",&n,&m);)
    {
        if(n+m==0) break;
        memset(pt,0,sizeof(pt));
        memset(dp,0,sizeof(dp));
        memset(head,0,sizeof(head));
        cnt=1;
        for(int i=1; i<=n; ++i)
        {
            scanf("%s%lf",s,&t);
            pt[s[0]-'a']=t;
        }
        scanf("%s",s);
        build(s,0);
        build_fail(0);
        dp[0][0]=1;
        for(int i=0; i<m; ++i)
            for(int j=0; j<cnt-1; ++j)
                if(i>=j)
                {
                    for(int k=0; k<26; ++k)
                    {
                        v=head[j].next[k];
                        dp[i+1][v]+=(dp[i][j]*pt[k]);
                    }
                }
        double ans=0;
        for(int i=0; i<=m; i++)
            ans+=dp[i][cnt-1];
        printf("%.2f%%\n",ans*100);
    }
    return 0;
}
