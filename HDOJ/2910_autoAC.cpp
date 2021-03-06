#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
int st[20][50000];
int a[20][5];
int s[20];
int ans,ans1,ans2;
void work(int h,int m,int s,int x)
{
    int i,j,k,l;
    if(!(m>=(h%5)*12&&m<(h%5+1)*12)) return;
    st[x][h/5*3600+m*60+s]=1;
}
int main()
{
    int n,i,j,k,l,m,q,w,e,r,t,num;
    while (scanf("%d",&n)!=EOF)
    {
        memset(st,0,sizeof(st));
        if (n==0) break;
        for (i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            for (j=1;j<=60;j++)
            {
                work(a[i][1],a[i][2],a[i][3],i);
                work(a[i][1],a[i][3],a[i][2],i);
                work(a[i][2],a[i][1],a[i][3],i);
                work(a[i][2],a[i][3],a[i][1],i);
                work(a[i][3],a[i][2],a[i][1],i);
                work(a[i][3],a[i][1],a[i][2],i);
                a[i][1]=(a[i][1]+1)%60;
                a[i][2]=(a[i][2]+1)%60;
                a[i][3]=(a[i][3]+1)%60;
            }
        }
        num=0;
        j=0;
        i=0;
        memset(s,0,sizeof(s));
        while (1)
        {
            for (j=1;j<=n;j++)
            {
                if (st[j][i]==1)
                {
                    if (s[j]==0) num++;
                    s[j]++;
                }
            }
            i++;
            if (num==n) break;
        }
        i--;j=0;  
        int flag=0;
        while (1)
        {
            for (k=1;k<=n;k++)
            {
                if (st[k][j]==1)
                {
                    if (s[k]==1)
                    {
                        flag=1;
                        num--;
                    }
                    s[k]--;
                }
            }
            if (flag) break;
            j++;
        }
        for (k=1;k<=n;k++)
        {
            if (st[k][j]==1)
            {
                if (s[k]==0)
                {
                    num++;
                }
                s[k]++;
            }
        }
        ans=i-j+1;
        ans1=j;
        ans2=i;
        while (1)
        {
            while (1)
            {
                for (k=1;k<=n;k++)
                {
                    if (st[k][j]==1)
                    {
                        if (s[k]==1)
                        {
                            num--;
                        }
                        s[k]--;
                    }
                }
                j++;
                if (num<n) break;
            }
            if (i-j+2<ans)
            {
                ans=i-j+2;
                ans1=j-1;
                ans2=i;
            }
            while (1)
            {
                i++;
                if (i>45000)break;
                for (k=1;k<=n;k++)
                {
                    if (st[k][i]==1)
                    {
                        if (s[k]==0)
                        {
                            num++;
                        }
                        s[k]++;
                    }
                }
                if (num==n)break;
            }
            if (i>45000)break;
        }
        int h1,m1,s1,h2,m2,s2;
        h1=ans1/3600;
        m1=ans1-h1*3600;
        m1=m1/60;
        s1=ans1-h1*3600-m1*60;
        h2=ans2/3600;
        m2=ans2-h2*3600;
        m2=m2/60;
        s2=ans2-h2*3600-m2*60;
        printf("%02d:%02d:%02d %02d:%02d:%02d\n",h1,m1,s1,h2,m2,s2);
    }
    return 0;
}
