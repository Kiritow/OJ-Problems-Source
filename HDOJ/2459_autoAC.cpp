#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
#define N 100005
int ws1[N],wv[N],wa[N],wb[N];
int ran[N],height[N],sa[N],len;
char str[N],xiao;
int dp[N][25];
int min(int x,int y)
{
    return x<y?x:y;
}
int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b] && r[a+l]==r[b+l];
}
void da(char *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++)
        ws1[i]=0;
    for(i=0;i<n;i++)
        ws1[x[i]=r[i]]++;
    for(i=1;i<m;i++)
        ws1[i]+=ws1[i-1];
    for(i=n-1;i>=0;i--)
        sa[--ws1[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++)
            y[p++]=i;
        for(i=0;i<n;i++)
            if(sa[i]>=j)
                y[p++]=sa[i]-j;
        for(i=0;i<n;i++)
            wv[i]=x[y[i]];
        for(i=0;i<m;i++)
            ws1[i]=0;
        for(i=0;i<n;i++)
            ws1[wv[i]]++;
        for(i=1;i<m;i++)
            ws1[i]+=ws1[i-1];
        for(i=n-1;i>=0;i--)
            sa[--ws1[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}
void calheight(char *r,int *sa,int n)
{
     int i,j,k=0;
     for(i=1;i<=n;i++)
         ran[sa[i]]=i;
     for(i=0;i<n;height[ran[i++]]=k)
         for(k?k--:0,j=sa[ran[i]-1];r[i+k]==r[j+k];k++) ;
}
void RMQ()
{
    int i,j,m;
    m=(int)(log((double)len)/log(2.00));
    for(i=1;i<=len;i++)
       dp[i][0]=height[i];
    for(j=1;j<=m;j++)
        for(i=1;i+(1<<j)-1<=len;i++)
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int lcp(int x,int y)
{
    int t;
    x=ran[x];y=ran[y];
    if(x>y)
        swap(x,y);
    x++;
    t=(int)(log(double(y-x+1))/log(2.00));
    return min(dp[x][t],dp[y-(1<<t)+1][t]);
}
void solve()
{
    int i,j,max=1,f=0,l1,num=0,t,node=1,k,cnt,p;
    for(i=1;i<=len/2;i++)
    {
        for(j=0;j+i<len;j+=i)
        {
           if(str[j]!=str[j+i])
               continue;
           l1=lcp(j,j+i);
           num=l1/i+1;
           p=j;
           t=i-l1%i;
           cnt=0;
           for(k=j-1;k>=0&&k+i>j&&str[k]==str[k+i];k--)
           {
               cnt++;
               if(cnt==t)
               {
                   num++;
                   p=k;
               }
               else if(ran[k]<ran[p])
                   p=k;
           }
           if(max<num)
           {
               f=p;
               max=num;
               node=i;
           }
           else if(max==num&&ran[f]>ran[p])
           {
               f=p;
               node=i;
           }
        }
    }
    if(max==1)
    {
        printf("%c\n",xiao);
        return ;
    }
    for(i=f;i<=f+max*node-1;i++)
        printf("%c",str[i]);
    printf("\n");
} 
int main()
{
    int T=0,i;
    while(scanf("%s",str)!=EOF&&str[0]!='#')
    {
        T++;
        len=strlen(str);
        xiao='z'+1;
        for(i=0;i<len;i++)
           if(str[i]<xiao)
               xiao=str[i];
        str[len]='0';
        da(str,sa,len+1,'z'+1);
        calheight(str,sa,len);
        RMQ();
        printf("Case %d: ",T);
        solve();
    }
    return 0;
}
