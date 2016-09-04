#include <cstdio>
#include <cstring>
#include <algorithm>
#define LEN 25
#define N 10
using namespace std;
bool g[N][N];
char name[N][LEN];
int n;
int p1[N],p2[N];
void change(int *ans)
{
    int x,y,OK=0;
    for(int i=0; i<n; i++)
    {
        x=ans[i];
        y=p1[i];
        if(strcmp(name[x],name[y]) < 0) 
            break;
        else if(strcmp(name[y],name[x]) < 0)
        {
            OK=1;
            break;
        }
    }
    if(OK)
        for(int i=0; i<n; i++)
            ans[i]=p1[i];
}
bool fight()
{
    int i=0,j=0,x,y;
    while(i<n && j<n)
    {
        x=p1[i];
        y=p2[j];
        if(g[y][x]) i++;
        else        j++;
    }
    return i<n;
}
void solve(int Case)
{
    for(int i=0; i<n; i++) p1[i]=p2[i]=i;
    int ans[N],FIND,OK;
    FIND=0;
    do
    {
        sort(p2,p2+n);
        OK=1;
        do
        {
            if(!fight())
            {
                OK=0;
                break;
            }
        }
        while(next_permutation(p2,p2+n)); 
        if(OK)
        {
            if(!FIND)
            {
                FIND=1;
                for(int i=0; i<n; i++) 
                    ans[i]=p1[i];
            }
            else 
                change(ans);
        }
    }
    while(next_permutation(p1,p1+n)); 
    if(!FIND)
        printf("Case %d: No\n",Case);
    else
    {
        printf("Case %d: Yes\n",Case);
        for(int i=0; i<n; i++)
        {
            if(i) printf(" ");
            printf("%s",name[ans[i]]);
        }
        printf("\n");
    }
}
void input()
{
    scanf("%d",&n);
    for(int i=0; i<n; i++) 
        scanf("%s",name[i]);
    memset(g,0,sizeof(g));
    for(int i=0; i<n; i++)
    {
        int m;
        char tmp[LEN];
        scanf("%d",&m);
        for(int j=0; j<m; j++)
        {
            scanf("%s",tmp);
            for(int k=0; k<n; k++) if(!strcmp(name[k],tmp))
            {
                g[i][k]=1;
                break;
            }
        }
    }
}
int main()
{
    int T,t;
    scanf("%d",&T);
    for(t=1; t<=T; t++)
    {
        input();
        solve(t);
    }
    return 0;
}
