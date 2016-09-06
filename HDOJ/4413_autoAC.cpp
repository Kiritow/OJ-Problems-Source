#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
typedef pair<string, int> node;
vector<node> ans;
bool vis[50];
int V[50];
bool cmp(string s1,string s2){
    return s1+s2<s2+s1;
}
bool cmp2(string s1,string s2){
    return s1+"+"+s2<s2+"+"+s1;
}
bool hmr(node a, node b) {
    if (a.second==b.second) {
        if (a.first.length()==b.first.length()) return a.first<b.first;
        return a.first.length()<b.first.length();
    }
    return a.second<b.second;
}
bool operator==(node a, node b) {
    return a.first==b.first && a.second==b.second;
}
string StInS(int s,int n,int ors){
    int i;
    vector<string> tmpAns;
    for (i=0;i<(1<<n);i++){
        if ((i&s)==(ors&s))
            if (V[i]==0) return "";
    }
    if (s==0) return "1";
    string tmp;
    for (i=0;i<n;i++) if (s&(1<<i)){
        tmp="";
        if (!(ors&(1<<i)))
            tmp+='-';
        tmp+=(char)(i+'A');
        tmpAns.push_back(tmp);
    }
    sort(tmpAns.begin(),tmpAns.end(),cmp);
    tmp="";
    for (i=0;i<tmpAns.size();i++)
        tmp+=tmpAns[i];
    return tmp;
}
void getans(int s, int n) {
    int i,j;
    int minsize = 0x3fff;
    vector<node> tmp;
    for (i=0;i<(1<<n);i++) {
        int ctrl=__builtin_popcount(i);
        if (ctrl>minsize) continue;
        string tans2=StInS(i,n,s);
        if (tans2.empty()) continue;
        if (ctrl<minsize) {
            minsize = ctrl;
            tmp.clear();
        }
        int res = 0;
        for (j = 0; j < 1<<n; ++j)
            if ((j&i)==(s&i)) res |= 1<<j;
        tmp.push_back(make_pair(tans2, res));
    }
    for (i = 0; i < tmp.size(); ++i)
        ans.push_back(tmp[i]);
}
int N, M;
int all;
int best;
bool use[64], ause[64];
void dfs(int i, int len, int cover) {
    if (len >= best) return;
    if (cover==all) {
        memcpy(ause, use, sizeof(use));
        best = len;
        return;
    }
    if (i==M) return;
    use[i] = 1;
    dfs(i+1, len+ans[i].first.length()+1, cover|ans[i].second);
    use[i] = 0;
    dfs(i+1, len, cover);
}
int main(){
    int i,s,j,v;
    int cas=0;
    for (;;){
        scanf("%d",&N);
        if (N==0) break;
        for (i=0;i<(1<<N);i++){
            s=0;
            vis[i] = 0;
            for (j=0;j<N;j++){
                scanf("%d",&v);
                s^=(v<<j);
            }
            scanf("%d",&V[s]);
        }
        ans.clear();
        memset(vis, 0, sizeof vis);
        all = 0;
        for (s = 0; s < 1<<N; ++s)
            if (V[s]){
                all |= 1<<s;
                getans(s, N);
            }
        if (ans.size()==0) {
            puts("-AA");
            continue;
        }
        if (ans[0].first[0]=='1') {
            puts("-A+A");
            continue;
        }
        sort(ans.begin(), ans.end(), hmr);
        M = unique(ans.begin(), ans.end())-ans.begin();
        sort(ans.begin(), ans.begin()+M);
        best = 0x3fffffff;
        memset(use, 0, sizeof use);
        memset(ause, 0, sizeof ause);
        dfs(0, 0, 0);
        vector<string> astr;
        for (i = 0; i < M; ++i)
            if (ause[i]) astr.push_back(ans[i].first);
        sort(astr.begin(), astr.end(), cmp2);
        string fin = astr[0];
        for (i = 1; i < astr.size(); ++i)
            fin += "+"+astr[i];
        cout << fin << '\n';
    }
    return 0;
}
