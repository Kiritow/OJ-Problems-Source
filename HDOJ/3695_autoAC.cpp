#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN = 5200005;
const int MAX_NODE = 3000005;
const int SIGMA_SIZE = 26;
char str[MAXN];
char buf[MAXN];
struct node{
    node* fail;
    node* next[SIGMA_SIZE];
    bool isword;
    int  id;
    void init(){
        id=0;
        isword=false;
        memset(next, 0, sizeof(next));
    }
};
class AC_Automation{
public:
    void init();
    void insert(char*,int);
    void getFail();
    int  find(char*);
private:
    node* new_node();
    int ID(char ch){return ch-'A';}
private:
    node Heap[MAX_NODE];
    node* root;
    int size;
};
node* AC_Automation::new_node(){
    Heap[size].init();
    return &Heap[size++];
}
void AC_Automation::init(){
    size=0;
    root=new_node();
}
void AC_Automation::insert(char* str,int id){
    node* p=root;
    for( ; *str; ++str){
        int ch=ID(*str);
        if(p->next[ch] == NULL)
            p->next[ch] = new_node();
        p = p->next[ch];
    }
    p->isword=true;
    p->id=id;
}
void AC_Automation::getFail(){
    queue<node*>Q;
    Q.push(root);
    while(!Q.empty()){
        node* tmp=Q.front(); Q.pop();
        for(int i=0; i<SIGMA_SIZE; ++i){
            node*& now = tmp->next[i];
            if(now != NULL){
                Q.push(now);
                if(tmp==root) now->fail=root;
                else{
                    node* p=tmp->fail;
                    while(p != NULL){
                        if(p->next[i] != NULL){
                            now->fail = p->next[i];
                            break;
                        }
                        p = p->fail;
                    }
                    if(p==NULL) now->fail=root;
                }
            }
            else{
                if(tmp==root) now = root;
                else now=tmp->fail->next[i];
            }
        }
    }
}
int AC_Automation::find(char* str){
    node* p=root;
    int cnt=0;
    for( ; *str; ++str){
        int ch=ID(*str);
        p = p->next[ch];
        if(p==NULL) p=root;
        node* tmp=p;
        while(tmp!=root && tmp->isword){
            ++cnt;
            tmp->isword=false;
            tmp = tmp->fail;
        }
    }
    return cnt;
}
inline void rev(char* str, int len){
    char ch;
    for(int i=0, k=len-1; i<len/2; ++i,--k){
        ch=str[i]; str[i]=str[k]; str[k]=ch;
    }
}
inline void change(char* str,char* now){
    memset(now, 0, sizeof(now));
    int len=strlen(str);
    int i;
    for(i=0; i<len; ++i){
        if(str[i]=='['){
            ++i;
            int num=0;
            while(str[i]>='0' && str[i]<='9'){
                num = num*10 + str[i] - '0';
                ++i;
            }
            while(num--){
                *now = str[i];
                ++now;
            }
            ++i; 
        }
       else{
            *now=str[i];
            ++now;
        }
    }
}
AC_Automation ac;
int main(){
    int n,nCase;
    char pat[1005];
    scanf("%d",&nCase);
    while(nCase--){
        ac.init();
        scanf("%d%*c",&n);
        for(int i=1; i<=n; ++i){
            gets(pat);
            ac.insert(pat, i);
        }
        ac.getFail();
        memset(buf, 0, sizeof(buf));
        memset(str, 0, sizeof(str));
        gets(buf);
        change(buf,str);
        int ans=ac.find(str);
        rev(str,strlen(str));
        printf("%d\n", ans+ac.find(str));
    }
    return 0;
}
