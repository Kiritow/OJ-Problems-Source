#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct stu{
    string na;
    double sco;
}s[1010];
bool cmp(stu a,stu b){
    if(a.sco==b.sco)
        return a.na<b.na;
    return a.sco>b.sco;
}
int main(){
    int n,i,j,m,x,ans;
    double g,a[20];
    while(scanf("%d",&n),n){
        scanf("%d%lf",&m,&g);
        for(i=1;i<=m;i++)
            scanf("%lf",&a[i]);
        ans=0;
        for(i=0;i<n;i++){
            cin>>s[i].na;
            scanf("%d",&m);
            s[i].sco=0;
            for(j=0;j<m;j++){
                scanf("%d",&x);
                s[i].sco+=a[x];
            }
            if(s[i].sco>=g)
                ans++;
        }
        printf("%d\n",ans);
        sort(s,s+n,cmp);
        for(i=0;i<ans;i++){
            cout<<s[i].na;
            printf(" %.lf\n",s[i].sco);
        }
    }
}
