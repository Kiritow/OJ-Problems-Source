#include <cstdio>
#include <algorithm>
using namespace std;
const int N=20010;
struct line{int l,r;}s[N];
int n,head,tail;
long long ans;
bool cmp(line a,line b){return a.l==b.l? a.r<b.r:a.l<b.l;}
int main(){
    //freopen("1165.in","r",stdin);freopen("1165.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&s[i].l,&s[i].r);
    sort(s+1,s+n+1,cmp);
    for(int i=1;i<n;i++){
        if(s[i].r>=s[i+1].l)  s[i+1].l=s[i].l,s[i+1].r=max(s[i].r,s[i+1].r);
        else ans+=s[i].r-s[i].l;
    }
    ans+=s[n].r-s[n].l;
    printf("%lld",ans);
    return 0;
}
