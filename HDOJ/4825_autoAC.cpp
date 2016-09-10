#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define LL __int64
using namespace std;
struct Node {
    int num;
    Node *next[2];
    Node() {
        num = 0;
        for(int i=0; i<2; i++) {
            next[i] = NULL;
        }
    }
};
char ans[123];
int n,m;
void tstrrev(char s[]) {
    int l=strlen(s);
    for(int i=0,j=l-1; i<l; i++,j--) {
        if(i<j) {
            s[i]^=s[j];
            s[j]^=s[i];
            s[i]^=s[j];
        }
    }
}
void insert(Node *root,char *s) {
    Node *p;
    p = root;
    for(int i=0; s[i]; i++) {
        int x = s[i] - '0';
        if(p->next[x] == NULL)
            p->next[x] = new Node;
        p = p->next[x];
        p->num ++;
    }
}
void search(Node *root,char *s) {
    memset(ans,0,sizeof(ans));
    Node *p;
    p = root;
    for(int i=0; i<32; i++) {
        int x = s[i] - '0';
        if(p->next[x] != NULL) {
            p = p->next[x];
            ans[i] = s[i];
        } else {
            if(x == 1) x = 0;
            else x = 1;
            p = p->next[x];
            ans[i] = x + '0';
        }
    }
}
int main() {
    int _;
    scanf("%d",&_);
    for(int cas=1; cas<=_; cas++) {
        scanf("%d%d",&n,&m);
        LL tmp;
        Node *root = new Node;
        while(n--) {
            scanf("%I64d",&tmp);
            char str[40];
            for(int i=0; i<32; i++) {
                str[i] = tmp % 2 + '0';
                tmp /= 2;
            }
            str[32] = '\0';
            tstrrev(str);
            insert(root,str);
        }
        printf("Case #%d:\n",cas);
        while(m--) {
            scanf("%I64d",&tmp);
            char str[40];
            for(int i=0; i<32; i++) {
                str[i] = tmp % 2 + '0';
                tmp /= 2;
            }
            str[32] = '\0';
            tstrrev(str);
            for(int i=0; i<32; i++) {
                if(str[i] == '1') {
                    str[i] = '0';
                } else {
                    str[i] = '1';
                }
            }
            search(root,str);
            tstrrev(ans);
            LL hehe = 0;
            LL mul = 1;
            for(int i=0; i<32; i++) {
                hehe += mul * (ans[i] - '0');
                mul *= 2;
            }
            printf("%I64d\n",hehe);
        }
    }
    return 0;
}
