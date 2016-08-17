#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

const int maxn=500000;
int tree[maxn][2];
int val[maxn],cnt;
int n,ans;

void insert(string st){
    int s=0;
    for(int i=0;i<st.length();i++){
        if( tree[s][st[i]-'0']==0 ) tree[s][st[i]-'0']=++cnt;
        s=tree[s][st[i]-'0'];
        val[s]++;
        if((i+1)*val[s]>ans) ans=(i+1)*val[s];
    }
}

void initial(){
    cnt=ans=0;
    memset(val,0,sizeof(val));
    memset(tree,0,sizeof(tree));
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        string st;
        cin>>st;
        insert(st);
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t-- >0){
        initial();
        solve();
    }
    return 0;
}
