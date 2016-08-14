#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<iostream>
#include<algorithm>
#define maxn 555
#define clr(x)memset(x,0,sizeof(x))
using namespace std;
int tot;
int n;
int b[maxn][maxn];
int g[maxn][maxn];
int by[maxn],gl[maxn];
int r[maxn];
char s[100];
string bo[maxn],gi[maxn];
int main()
{
    int bn,gn,t,flag,i,j,f;
    while(scanf("%d",&n)!=EOF)
    {
        f=0;
        getchar(); 
        gn=1;
        clr(b);
        clr(g);
        for(i=1;i<=n;i++)r[i]=1;
        map<string,int>boy,girl;
          boy.clear(),girl.clear();
        tot=1;
        for(i=1;i<=n;i++)
        {
            scanf("%s",s);
            boy[s]=i;
            bo[i]=s;
            for(j=1;j<=n;j++)
            {
                scanf("%s",s);
                if(!girl[s])
                {
                    girl[s]=j;
                    gi[j]=s;
                    b[i][j]=j;
                }
                else b[i][j]=girl[s];
            }
        }
        for(i=1;i<=n;i++)
        {
            scanf("%s",s);
            t=girl[s];
            for(j=1;j<=n;j++)
            {
                scanf("%s",s);
                g[t][boy[s]]=n-j;
            }
        }
        clr(by);  clr(gl);
        while(1)
        {
            flag=1;
            for(i=1;i<=n;i++)
                if(!by[i])
                {
                    t=b[i][r[i]++];
                    if(!gl[t])
                    {
                        by[i]=t;
                        gl[t]=i;
                    }
                    else if(g[t][gl[t]]<g[t][i])
                    {
                        by[gl[t]]=0;
                        gl[t]=i;
                        by[i]=t;
                    }
                    flag=0;
                }
            if(flag)
                break;
        }
        for(i=1;i<=n;i++)
            cout<<bo[i]<<' '<<gi[by[i]]<<endl;
        printf("\n");
    }
    return 0;
}
