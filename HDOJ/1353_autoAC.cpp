#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[700];
int pr[700];
int main()
{
    int a,b[5],c[5]={25,10,5,1},op[50];
    char s[100];
    op[25]=0;op[10]=1;op[5]=2;op[1]=3;
    while(scanf(" %s %d %d %d %d",s,&b[0],&b[1],&b[2],&b[3])!=EOF)
    {
        memset(dp,-1,sizeof(dp));
        dp[0]=0;
        bool flag=false;
        int pos;
        for(int i=0;s[i]!='\0';i++)
            if(s[i]=='.')
            {
                pos=i;
                flag=true;
                break;
            }
        if(flag)
        {
            int x,y;
            sscanf(s,"%d.%d",&x,&y);
            if(y<10&&s[pos+1]!='0')
                y*=10;
            a=x*100+y;
        }
        else
            sscanf(s,"%d",&a);
        for(int i=0;i<4;i++)
        {
            int v=c[i],n=b[i];
            if(n*v>=a)
                for(int i=0;i+v<=a;i++)
                {
                    if(dp[i]!=-1&&(dp[i+v]==-1||dp[i+v]>dp[i]+1))
                        dp[i+v]=dp[i]+1,pr[i+v]=i;
                }
            else
            {
                while(n--)
                for(int i=a;i-v>=0;i--)
                    if(dp[i-v]!=-1&&(dp[i]==-1||dp[i]>dp[i-v]+1))
                        dp[i]=dp[i-v]+1,pr[i]=i-v;
            }
        }
        if(dp[a]==-1)
            puts("NO EXACT CHANGE");
        else
        {
            int tot[4];
            memset(tot,0,sizeof(tot));
            for(int i=a;i!=0;tot[op[i-pr[i]]]++,i=pr[i]);
            printf("%d %d %d %d\n",tot[0],tot[1],tot[2],tot[3]);
        }
    }
    return 0;
}
