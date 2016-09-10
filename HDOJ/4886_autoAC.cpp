#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;
const int maxn=1e6+10;
char a[maxn];
bool f[6][maxn];
int g[10],p[10];
void init()
{
    int i,j,k;
    p[0]=1;
    for(i=1;i<=6;i++)
        p[i]=p[i-1]*8;
}
void print(int a,int b)
{
    int i,j,k,ans[10];
    for(i=0;i<a;i++)
    {
        ans[i]=b%8;
        b=b/8;
    }
    for(i=a-1;i>=0;i--)
        printf("%c",ans[i]+'A');
    printf("\n");
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int i,j,k,n;
        memset(f,false,sizeof(f));
        memset(g,0,sizeof(g));
        scanf("%s",a);
        n=strlen(a);
        for(i=0;i<n;i++)
        {
            for(j=1;j<=6;j++)
            {
                g[j]=g[j]*8+(a[i]-'A');
                if(i>=j)
                {
                    g[j]-=(a[i-j]-'A')*p[j];
                    f[j-1][g[j]]=true;
                }
                else if(i==j-1)
                {
                    f[j-1][g[j]]=true;
                }
            }
        }
        for(i=0;i<6;i++)
        {
            for(j=0;j<p[i+1];j++)
                if(!f[i][j])break;
            if(j<p[i+1])break;
        }
        print(i+1,j);
    }
    return 0;
}
