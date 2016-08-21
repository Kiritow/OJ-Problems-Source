#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 100005
#define MOD 100000
#define inf 1<<29
#define LL long long
using namespace std;
struct Trie{
    Trie *next[4];
    Trie *fail;
    int kind,isword;
};
Trie *que[N],s[N];
int idx;
int id(char ch){
    if(ch=='A') return 0;
    else if(ch=='T') return 1;
    else if(ch=='C') return 2;
    return 3;
}
Trie *NewNode(){
    Trie *tmp=&s[idx];
    for(int i=0;i<4;i++) tmp->next[i]=NULL;
    tmp->isword=0;
    tmp->kind=idx++;
    tmp->fail=NULL;
    return tmp;
}
void Insert(Trie *root,char *s,int len){
    Trie *p=root;
    for(int i=0;i<len;i++){
        if(p->next[id(s[i])]==NULL)
            p->next[id(s[i])]=NewNode();
        p=p->next[id(s[i])];
    }
    p->isword=1;
}
void Bulid_Fail(Trie *root){
    int head=0,tail=0;
    que[tail++]=root;
    root->fail=NULL;
    while(head<tail){
        Trie *tmp=que[head++];
        for(int i=0;i<4;i++){
            if(tmp->next[i]){
                if(tmp==root) tmp->next[i]->fail=root;
                else{
                    Trie *p=tmp->fail;
                    while(p!=NULL){
                        if(p->next[i]){
                           tmp->next[i]->fail=p->next[i];
                           break;
                        }
                        p=p->fail;
                    }
                    if(p==NULL) tmp->next[i]->fail=root;
                }
                if(tmp->next[i]->fail->isword) tmp->next[i]->isword=1;
                que[tail++]=tmp->next[i];
            }
            else if(tmp==root) tmp->next[i]=root;
            else tmp->next[i]=tmp->fail->next[i];
        }
    }
}
int dp[1005][2005];
int slove(char *str,int len){
    for(int i=0;i<=len;i++) for(int j=0;j<idx;j++) dp[i][j]=inf;
    dp[0][0]=0;
    for(int i=1;i<=len;i++){
        for(int j=0;j<idx;j++){
            if(s[j].isword) continue;
            if(dp[i-1][j]==inf) continue;
            for(int k=0;k<4;k++){
                int r=s[j].next[k]->kind;
                if(s[r].isword) continue;
                dp[i][r]=min(dp[i][r],dp[i-1][j]+(id(str[i-1])!=k));
            }
        }
    }
    int ans=inf;
    for(int i=0;i<idx;i++) ans=min(ans,dp[len][i]);
    return ans==inf?-1:ans;
}
char str[1005];
int main(){
    int n,cas=0;
    while(scanf("%d",&n)!=EOF&&n){
        idx=0;
        Trie *root=NewNode();
        for(int i=0;i<n;i++){
            scanf("%s",str);
            Insert(root,str,strlen(str));
        }
        Bulid_Fail(root);
        scanf("%s",str);
        printf("Case %d: %d\n",++cas,slove(str,strlen(str)));
    }
    return 0;
}
