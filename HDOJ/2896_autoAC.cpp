#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=130;
int n,m,tag[520];
struct Trie{
    int count;      
    Trie *fail;     
    Trie *next[N];
    Trie(){     
        count=0;
        fail=NULL;
        memset(next,NULL,sizeof(next));
    }
}*q[5000010];      
char word[520];    
char str[1000010];  
int head,tail;      
void Insert(char *str,Trie *Root,int id){
    Trie *loc=Root;
    int i=0;
    while(str[i]!='\0'){
        int id=str[i]-31;
        if(loc->next[id]==NULL)
            loc->next[id]=new Trie();
        loc=loc->next[id];
        i++;
    }
    loc->count=id;      
}
void AC_automation(Trie *Root){
    Root->fail=NULL;
    q[head++]=Root;
    Trie *cur,*tmp;
    while(head!=tail){
        cur=q[tail++];      
        tmp=NULL;
        for(int i=0;i<N;i++){
            if(cur->next[i]!=NULL){     
                if(cur==Root)   
                    cur->next[i]->fail=Root;
                else{   
                    tmp=cur->fail;  
                    while(tmp!=NULL){
                        if(tmp->next[i]!=NULL){     
                            cur->next[i]->fail=tmp->next[i];    
                            break;
                        }
                        tmp=tmp->fail;  
                    }
                    if(tmp==NULL)       
                        cur->next[i]->fail=Root;    
                }
                q[head++]=cur->next[i]; 
            }
        }
    }
}
int query(Trie *Root){
    int i=0,cnt=0;
    Trie *loc=Root,*tmp;
    while(str[i]!='\0'){
        int id=str[i]-31;   
        while(loc->next[id]==NULL && loc!=Root){
            loc=loc->fail;  
        }
        loc=loc->next[id];      
        loc=(loc==NULL)?Root:loc;
        tmp=loc;
        while(tmp!=Root && tmp->count!=0){
            if(tmp->count!=0 && !tag[tmp->count]){  
                cnt++;
                tag[tmp->count]=1;
            }
            tmp=tmp->fail;
        }
        i++;
    }
    return cnt;
}
int main(){
    while(scanf("%d",&n)!=EOF){
        head=tail=0;
        Trie *Root=new Trie();
        getchar();
        for(int i=1;i<=n;i++){
            gets(word);
            Insert(word,Root,i);
        }
        AC_automation(Root);
        scanf("%d",&m);
        int total=0;
        for(int i=1;i<=m;i++){
            memset(tag,0,sizeof(tag));
            scanf("%s",str);
            int flag=query(Root);
            if(flag){
                printf("web %d:",i);
                for(int j=1;j<=n;j++)
                    if(tag[j])
                        printf(" %d",j);
                printf("\n");
                total++;
            }
        }
        printf("total: %d\n",total);
    }
    return 0;
}
