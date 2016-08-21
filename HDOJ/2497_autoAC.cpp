#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define len 1000005
int ans[len],head[len],next[len],val[len],degree[len],n,m;
bool toposort(){
         int i,front,rear,u;
         for(i=rear=1;i<=n;i++)
                   if(degree[i]==0)
                            ans[rear++]=i;
         for(front=1;front<rear;front++){
                   for(u=head[ans[front]];u;u=next[u])
                            if(--degree[val[u]]==0)
                                     ans[rear++]=val[u];
         }
         if(rear==n+1)  return true;
         else           return false;
}
int main(void){
         int i,x,y,k;
         while(scanf("%d%d",&n,&m)==2&&m+n){
                   memset(head,0,sizeof(head));
                   memset(degree,0,sizeof(degree));
                   for(i=k=1;i<=m;i++){
                            scanf("%d%d",&x,&y);
                            degree[y]++;
                            val[k]=y;
                            next[k]=head[x];    head[x]=k++;
                   }
                   if(toposort())
                            for(i=1;i<=n;i++)
                                     printf("%d\n",ans[i]);
                   else
                            puts("IMPOSSIBLE");
         }
         return 0;
}
