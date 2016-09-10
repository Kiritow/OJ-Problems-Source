#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <assert.h>
#include<iostream>
using namespace std;
#define MAXN 10050
#define LL __int64
int dp[2][10][110];
int num[110];
void dos(char str[],int leap)
{
    int n=strlen(str);
    for(int i=0;i<n;i++)
    {
        num[i+1]=str[i]-'0';
    }
    if(leap==0)
    {
        if(n==1&&num[1]==0)return;
        num[n]--;
        int x=n;
        while(num[x]<0)
        {
            num[x]+=10;
            num[x-1]--;
            x--;
        }
        if(num[1]==0)
        {
            n--;
            for(int i=1;i<=n;i++)
            {
                num[i]=num[i+1];
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=9;j++)
        {
            int x=n-i;
            if(i!=1)
            {
                dp[leap][j][x]++;
            }
            for(int k=1;k+x+1<n;k++)
            {
                if(k%2)dp[leap][j][x+k-1]-=9;
                else dp[leap][j][x+k-1]+=9;
            }
            for(int k=1;k<i;k++)
            {
                if(i%2==0)dp[leap][j][n-k-1]-=(num[k]);
                else dp[leap][j][n-k-1]+=(num[k]);
                if(k==1)
                {
                    if(i%2==0)dp[leap][j][n-k-1]-=(-1);
                    else dp[leap][j][n-k-1]+=(-1);
                }
            }
            if(j>num[i])continue;
            if(j<num[i])
            {
                if(i%2==0)dp[leap][j][x]-=1;
                else dp[leap][j][x]+=1;
                continue;
            }
            for(int k=i+1;k<=n;k++)
            {
                if(i%2==0)dp[leap][j][n-k]-=num[k];
                else dp[leap][j][n-k]+=num[k];
                if(k==n)
                {
                    if(i%2==0)dp[leap][j][n-k]-=1;
                    else dp[leap][j][n-k]+=1;
                }
            }
            if(i==n)
            {
                if(i%2==0)dp[leap][j][0]-=1;
                else dp[leap][j][0]+=1;
            }
        }
    }
}
void hebing()
{
    for(int i=0;i<=100;i++)
    {
        for(int j=1;j<=9;j++)
        {
            dp[0][j][i]=dp[1][j][i]-dp[0][j][i];
        }
    }
}
int ans[220];
int fuhao;
int qian()
{
    int len=0;
    for(int i=0;i<=100;i++)
    {
        int x=0;
        for(int j=1;j<=9;j++)
        {
            x+=dp[0][j][i]*j;
        }
        ans[i]=x;
    }
    int x=0;
    for(int i=0;i<=100;i++)
    {
        x=ans[i];
        if(x!=0)len=i;
        else continue;
        if(x<0)
        {
            x=-x;
            ans[i]=x%10;
            ans[i]=-ans[i];
            x=-x;
        }
        else ans[i]=x%10;
        ans[i+1]+=x/10;
    }
    while(x!=0)
    {
        len++;
        if(x<0)
        {
            x=-x;
            ans[len]=x%10;
            ans[len]=-ans[len];
            x=-x;
        }
        else ans[len]=x%10;
        x=x/10;
    }
    while(ans[len]==0)len--;
    if(ans[len]<0)fuhao=0;
    else fuhao=1;
    if(fuhao==0)
    {
        for(int i=0;i<=len;i++)ans[i]=-ans[i];
    }
    for(int i=0;i<=len;i++)
    {
        if(ans[i]<0)
        {
            while(ans[i]<0)
            {
                ans[i]+=10;
                ans[i+1]--;
            }
        }
    }
    if(fuhao==0)
    {
        for(int i=0;i<=len;i++)ans[i]=-ans[i];
    }
    return len;
}
int getf(int len)
{
    int x=0;
    int y=0;
    for(int i=0;i<=len;i++)
    {
        x+=ans[i];
        y=y*10-ans[i];
        y=y%9;
    }
    if(fuhao==0)
    {
        y=-y;
        while(y<=0)y+=9;
        return y;
    }
    while(x>=10)
    {
        int y=0;
        while(x)
        {
            y+=x%10;
            x=x/10;
        }
        x=y;
    }
    return x;
}
void out(int f,int len)
{
    int aa=0;
    int y=0;
    for(int i=len;i>=0;i--)
    {
        aa=aa*10+ans[i];
        aa=aa%f;
        y=y*10-ans[i];
        y=y%f;
    }
    if(fuhao==0)
    {
        y=-y;
        cout<<(y%f+f)%f<<endl;
        return;
    }
    aa=(aa+f)%f;
    cout<<aa<<endl;
}
char stl[110];
char str[110];
int main()
{
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        memset(dp,0,sizeof(dp));
        memset(ans,0,sizeof(ans));
        scanf("%s%s",stl,str);
        dos(stl,0);
        dos(str,1);
        hebing();
        int len=qian();
        LL f=getf(len);
        if(f==0)
        {
            cout<<"Error!"<<endl;
        }
        else
        {
            out(f,len);
        }
    }
    return 0;
}
