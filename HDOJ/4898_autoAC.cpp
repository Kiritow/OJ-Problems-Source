#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define NN 4100
char s[NN];
int n,k;
int tsub;
int lcp[NN][NN];
struct Sub{
    int l,r;
    void init(int _l,int _r){l=_l;r=_r;}
    int size() {return r-l+1;}
    char charat(int x) {
        if (x>r-l)  return 0;
        else return s[l+x];
    }
}sub[NN*NN];
int Lcp(Sub a,Sub b){
    return min(lcp[a.l][b.l],min(a.size(),b.size()));
}
bool operator < (Sub a,Sub b){
    int m=Lcp(a,b);
    return a.charat(m)<b.charat(m);
}
int step[NN];
bool check(Sub M) {
    vector<int> nxt(n);
    for (int i = 0; i < n; ++i) {
        Sub tmp;
        tmp.init(i,i+n-1);
        int L = Lcp(tmp, M);
        if (s[(i + L) % n] < M.charat(L))
            nxt[i] = n;
        else
            nxt[i] = L;
    }
    for (;;) {
        bool done = true;
        for (int i = 0; i < nxt.size(); ++i) {
            if (nxt[i] == 0) {
                for (int j = 0; j < nxt.size(); ++j)
                    if (j != i) {
                        if (j < i && j + nxt[j] >= i)
                            --nxt[j];
                        else if (j > i && j + nxt[j] >= i + nxt.size())
                            --nxt[j];
                    }
                nxt.erase(nxt.begin() + i);
                done = false;
                break;
            }
        }
        if (done)
            break;
    }
    if (k > nxt.size())
        return false;
    for (int i = 0; i < nxt.size() * 2; ++i) {
        step[i] = i + nxt[i % nxt.size()];
    }
    for (int i = 0; i < nxt.size(); ++i) {
        int need = 0, at = i;
        while (at < i + nxt.size()) {
            at = step[at];
            ++need;
        }
        if (need <= k)
            return true;
    }
    return false;
}
Sub work(){
    int l=1,r=tsub,m,ans=r;
    int i,j,tot;
    while(l<r){
        m=l+r>>1;
        Sub a=sub[m];
        if (check(a)) {
            if (ans>m) ans=m;
            r=m-1;
        }
        else l=m+1;
    }
    return sub[ans];
}
void output(Sub a){
    int i,r=a.r;
    for(i=a.l;i<=a.r;++i){
        printf("%c",s[i]);
    }
    printf("\n");
}
int main(){
    int cas;
    scanf("%d",&cas);
    int i,j;
    while(cas--){
        scanf("%d%d",&n,&k);
        scanf("%s",s);
        for(i=0;i<n;++i){
            s[n+i]=s[i];
        }
        memset(lcp,0,sizeof(lcp));
        for(i=n+n-1;i>=0;--i){
            for(j=n+n-1;j>=0;--j){
                if (s[i]==s[j]) lcp[i][j]=lcp[i+1][j+1]+1;
                else lcp[i][j]=0;
            }
        }
        tsub=0;
        Sub tmp;
        for(i=0;i<n+n;++i){
            for(j=i;j<n+n;++j){
                if (j-i+1>n) break;
                tmp.init(i,j);
                sub[++tsub]=tmp;
            }
        }
        sort(sub+1,sub+tsub+1);
        tmp=work();
        output(tmp);
    }
    return 0;
}
