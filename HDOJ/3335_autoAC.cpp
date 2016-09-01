#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
typedef __int64 ll;
struct node{
    int s,t,nxt ; 
}e[100005] ;
int k,m,n,head[505],cnt,match[505],vis[505] ;
int find(int s)
{
    for(int i=head[s] ;i!=-1 ;i=e[i].nxt)
    {
        int tt=e[i].t ;
        if(!vis[tt])
        {
            vis[tt]=1 ;
            if(match[tt]==-1 || find(match[tt]))
            {
                match[tt]=s ;
                return 1 ;
            }
        }
    }
    return 0 ;
}
int max_match()
{
    int ans=0 ;
    memset(match,-1,sizeof(match)) ;
    for(int i=1 ;i<=n ;i++)
    {
        memset(vis,0,sizeof(vis)) ;
        ans+=find(i);
    }
    return ans;
}
void add(int s,int t) {e[cnt].s=s ;e[cnt].t=t ;e[cnt].nxt=head[s] ;head[s]=cnt++ ;}
ll a[1005],b[1005];
void read_graph()
{
    memset(head,-1,sizeof(head)) ;
    cnt=0 ;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            if(b[i]%b[j]==0)
                add(i,j);
        }
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
        }
        int st=0;
        sort(a+1,a+1+n);
        b[++st]=a[1];
        for(int i=2;i<=n;i++){
            if(a[i]!=a[i-1])b[++st]=a[i];
        }
        n=st;
        read_graph();
        printf("%d\n",n-max_match());
    }
    return 0;
}
