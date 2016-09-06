#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
char real[105][30];
int n,w=0,mm[105][105],st,et;
char temp1[208][30];
int record[105],vis[105],vis1[105];
int yes[105],root[105];
int Find(int r)
{
    if(r==root[r]) return r;
    else return root[r]=Find(root[r]);
}
int add(char *a)
{
    int i;
    for(i=0;i<w;i++){
        if(strcmp(a,real[i])==0)
         return i;
    }
    strcpy(real[w++],a);
}
void init()
{
    int i,num=0,j;
    char s1[30],s2[30];
    for(i=0;i<n;i++){
        scanf("%s %s",s1,s2);
        add(s1);
        add(s2);
        strcpy(temp1[num++],s1);
        strcpy(temp1[num++],s2);
    }
    for(i=0;i<w-1;i++)
        for(j=i+1;j<w;j++){
            if(strcmp(real[i],real[j])>0){
                char temp[30];
                strcpy(temp,real[j]);
                strcpy(real[j],real[i]);
                strcpy(real[i],temp);
            }
        }
        for(i=0;i<w;i++) root[i]=i;
    for(i=0;i<num;i+=2){
        int nowx=add(temp1[i]),nowy=add(temp1[i+1]);
        mm[nowx][nowy]=mm[nowy][nowx]=1;
        int ra=Find(nowx),rb=Find(nowy);
        if(ra!=rb) root[rb]=ra;
    }
}
int ansl=0;
int dfs(int now,int tt)
{
    if(tt>=w) return 0;
    int i;
    vis[now]=1;
    record[tt]=now;
    if(now==et){
        if(ansl<tt) {
            ansl=tt;
            for(i=0;i<=ansl;i++) yes[i]=record[i];
        }
            if(tt==w-1) return 1;
    }
    for(i=0;i<w;i++){
        if(vis[i]==0&&mm[now][i]==1){
            vis[i]=1;
            if(dfs(i,tt+1)) return 1;
            vis[i]=0;
        }
    }
    return 0;
}
int dfs1(int ttt,int ending)
{
    int i;
    if(ttt==ending) return 1;
    for(i=0;i<w;i++){
        if(!vis1[i]&&mm[ttt][i]&&(!vis[i])){
            vis1[i]=1;
            if(dfs1(i,ending)) return 1;
            //vis1[i]=0;
        }
    }
    return 0;
}
int main()
{
    int i,cc,Case=0;
    scanf("%d",&cc);
    while(cc--){
        Case++;
        scanf("%d",&n);
        memset(vis,0,sizeof(vis));
        memset(mm,0,sizeof(mm));
        w=0;
        init();
        st=-1;et=-1;
        for(i=0;i<w;i++){
            if(strcmp(real[i],"sea")==0) st=i;
            if(strcmp(real[i],"sky")==0) et=i;
        }
        printf("Case %d:",Case);
        if(st==-1||et==-1){
            printf(" what a pity\n");
            continue;
        }
        if(Find(st)!=Find(et)) {
            printf(" what a pity\n");
            continue;
        }
        for(i=0;i<w;i++){
            memset(vis1,0,sizeof(vis1));
            vis1[st]=1;
            if(!dfs1(i,et)) vis[i]=1;
        }
        for(i=0;i<w;i++){
            memset(vis1,0,sizeof(vis1));
            vis1[et]=1;
            if(!dfs1(i,st)) vis[i]=1;
        }
        ansl=0;
        dfs(st,0);
        for(i=0;i<=ansl;i++){
            printf(" %s",real[yes[i]]);
        }
        printf("\n");
    }
}
