#include<iostream>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>
#include<queue>
#include<list>
#include<set>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
#include<ctype.h>
#include<iomanip>
#include<limits.h>
using namespace std;
#define LL long long
#define pi acos(-1)
#define MAX INT_MAX
#define MIN INT_MIN
#define eps 1e-6
#define N 55
struct point{
    int x,y;
}p[N];
int n;
int ans[10010][3];
int tot;
void gao(int y){
    int i,j;
    double m[5];
    int cnt=0;
    for(i=1;i<=n;i++){
        if(p[i].y==y && p[i-1].y==y)return ;
        if(p[i].y==y)m[cnt++]=(double)p[i].x;
        if(p[i-1].y==y)m[cnt++]=(double)p[i-1].x;
        if((p[i-1].y<y && p[i].y>y) || (p[i-1].y>y && p[i].y<y))
        m[cnt++]=1.0*(y-p[i].y)*(p[i].x-p[i-1].x)/(p[i].y-p[i-1].y)+p[i].x;
    }
    int s,t;
    if(!cnt)return ;
    double minm=MAX;
    double maxm=MIN;
    for(i=0;i<cnt;i++)
    {
        minm=min(minm,m[i]);
        maxm=max(maxm,m[i]);
    }
    s=floor(minm)+1;
    t=ceil(maxm)-1;
    if(s>t)return ;
    ans[tot][0]=y;
    ans[tot][1]=s;
    ans[tot][2]=t;
    tot++;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int ca;
        scanf("%d%d",&ca,&n);
        int i,j;
        int minm=MAX;
        int maxm=MIN;
        for(i=1;i<=n;i++){
            scanf("%d%d",&p[i].x,&p[i].y);
            minm=min(minm,p[i].y);
            maxm=max(maxm,p[i].y);
        }
        p[0].x=p[n].x;
        p[0].y=p[n].y;
        tot=0;
        for(i=maxm-1;i>=minm+1;i--){
            gao(i);
        }
        printf("%d %d\n",ca,tot);
        for(i=0;i<tot;i++)
        printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
    }
    return 0;
}
