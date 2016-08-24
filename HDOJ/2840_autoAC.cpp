#include<iostream>
#include<cstdio>
#include<list>
#include<algorithm>
#include<cstring>
#include<string>
#include<stack>
#include<map>
#include<vector>
#include<cmath>
#include<memory.h>
#include<set>
#include<cctype>
#define ll long long
#define LL __int64
#define eps 1e-8
#define inf 0xfffffff
using namespace std;
typedef struct Node {
    char s[2000 + 10];
};
Node sasd[2000 + 10];
int b,n;
int num[2000 + 10];
int tot;
void clear() {
    memset(num,0,sizeof(num));
    tot = 0;
}
void dfs(int pos,int e) {
    if(pos == n) {
        if(n != 1 && num[pos - 1] == 0)return;
        for(int i=pos - 1;i>=0;i--) {
            if(num[i] >= 10)
                sasd[tot].s[n - i - 1] = 'A' + num[i] - 10;
            else 
                sasd[tot].s[n - i - 1] = '0' + num[i];
        }
        sasd[tot++].s[n] = 0;
        return;
    }
    for(int i=0;i<b;i++) {
        num[pos] = i;
        int ans = 0;
        for(int j=0;j<=pos;j++)
            ans += num[j] * num[pos - j];
        if((ans + e)%b == i)
            dfs(pos + 1,(ans + e)/b);
    }
}
bool cmp(Node x,Node y) {
    return strcmp(x.s,y.s) < 0;
}
int main() {
    while(scanf("%d %d",&b,&n) == 2) {
        clear();
        dfs(0,0);
        sort(sasd,sasd + tot,cmp);
        printf("%d\n",tot);
        for(int i=0;i<tot;i++)
            printf("%s\n",sasd[i].s);
    }
    return 0;
}
