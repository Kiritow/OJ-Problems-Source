#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define INF 0x3f3f3f3f
const int maxn=5010;
using namespace std;
vector <string> ans;
int a[110];//目标串
int b[110];//符合条件的某个
char tem[110];
int num=0;
int n,c;

void num1()
{
    for(int i=1; i<=n; ++i)
    {
        b[i]=!b[i];
    }
}

void num2()
{
    for(int i=1; i<=n; i+=2)
    {
        b[i]=!b[i];
    }
}

void num3()
{
    for(int i=2; i<=n; i+=2)
    {
        b[i]=!b[i];
    }
}

void num4()
{
    for(int i=1; i<=n; i+=3)
    {
        b[i]=!b[i];
    }
}
//
void dfs(int icount)
{
    //if(icount > c) return ;
    if(icount ==c)
    {
        int f=1;
        for(int i=1; i<=n; ++i)
        {
            if(a[i]==-1) continue ;
            if(a[i]!=b[i])
            {
                f=0;
                break;
            }
        }
        if(f==1)
        {
            num++;
            for(int i=0; i<n; ++i)
                tem[i]=b[i+1]+'0';
            tem[n] = '\0';

            ///ans.push_back(tem);
            ans.push_back((string)tem);
        }
        return ;
    }

    num1();
    dfs(icount+1);
    num1();

    num2();
    dfs(icount+1);
    num2();

    num3();
    dfs(icount+1);
    num3();


    num4();
    dfs(icount+1);
    num4();
}



int main()
{
    scanf("%d%d",&n,&c);
    memset(a,-1,sizeof(a));
    int x;

    /**??*/
    //if(c>4) c=4-c%2;

    while(scanf("%d",&x) && x!=-1)
        a[x]=1;
    while(scanf("%d",&x) && x!=-1)
        a[x]=0;
    for(int i=1; i<=n; ++i)
    {
        b[i]=1;
    }

    dfs(0);
    sort(ans.begin(),ans.end());
    ///for(int i=0; i<num; ++i)
    puts(ans.at(0).c_str());
    int last=0;
    for(size_t i=1;i<ans.size();i++)
    {
        if(ans.at(i)!=ans.at(last))
        {
            last=i;
            puts(ans.at(i).c_str());
        }
    }
    return 0;
}
