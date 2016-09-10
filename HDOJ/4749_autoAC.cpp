#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 1000000000
#define MAXN 100005
int vis[30];
int ne[MAXN];
int s[MAXN],p[MAXN];
int c1[30][MAXN],c2[30][MAXN];
int cal_s(int pos,int k)
{
    if(pos<0) return 0;
    int s=0;
    for(int i=1;i<k;i++) s+=c1[i][pos];
    return s;
}
int cal_p(int pos,int k)
{
    if(pos<0) return 0;
    int s=0;
    for(int i=1;i<k;i++) s+=c2[i][pos];
    return s;
}
bool isok(int i,int j)
{
    if(!j) return true;
    if (c2[p[j]][j]!=c1[s[i]][i]-c1[s[i]][i-j-1]) return false;
    int cnt1=cal_s(i,s[i]);
    int cnt2=cal_s(i-j-1,s[i]);
    int cnt3=cal_p(j,p[j]);
    return cnt1-cnt2==cnt3;
}
bool ok(int i,int j)
{
    if(!j) return true;
    if (c2[p[j]][j]!=c2[p[i]][i]-c2[p[i]][i-j-1]) return false;
    int cnt1=cal_p(i,p[i]);
    int cnt2=cal_p(i-j-1,p[i]);
    int cnt3=cal_p(j,p[j]);
    return cnt1-cnt2==cnt3;
}
void getnext(int n)
{
    bool flag;
    for(int i=1;i<n;i++)
    {
        int j=ne[i];
        flag=ok(i,j);
        while(j&&!flag)
        {
            j=ne[j];
        }
        if(flag)
        {
            ne[i+1]=j+1;
        }
        else
        {
            ne[i+1]=0;
        }
    }
}
int ans;
int kmp(int n,int m)
{
    getnext(m);
    bool flag;
    int j=0;
    for(int i=0;i<n;i++)
    {
        flag=isok(i,j);
        while(j&&!flag) {j=ne[j];flag=isok(i,j);}
        if(flag) j++;
        if(j==m)
        {
            ans++;
            j=0;
        }
    }
    return -1;
}
inline int ReadInt()
{
    int flag=0;
    char ch = getchar();
    int data = 0;
    while (ch < '0' || ch > '9')
    {
        if(ch=='-') flag=1;
        ch = getchar();
    }
    do
    {
        data = data*10 + ch-'0';
        ch = getchar();
    }while (ch >= '0' && ch <= '9');
        if(flag) data=-data;
        return data;
}
int main()
{
    int n,m,kk;
    while(~scanf("%d%d%d",&n,&m,&kk))
    {
        ans=0;
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(int i=0;i<n;i++)
        {
            s[i]=ReadInt();
            if(i){
            for(int j=1;j<=kk;j++){
                c1[j][i]=c1[j][i-1];}
            }
            c1[s[i]][i]++;
        }
        for(int i=0;i<m;i++)
        {
            p[i]=ReadInt();
            if(i)
            for(int j=1;j<=kk;j++)
                c2[j][i]=c2[j][i-1];
            c2[p[i]][i]++;
        }
        getnext(m);
        kmp(n,m);
        cout<<ans<<endl;
    }
    return 0;
}
