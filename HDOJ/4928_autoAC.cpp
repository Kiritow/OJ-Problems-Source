#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int SIZEN=100005;
LL a[SIZEN];
LL t_a[SIZEN];
int val_h,val_t;
int check(int cnt){
    int flag=1;
    for(int i=0;i<cnt-1;i++)
        if(a[i]>a[i+1]) flag=0;
    if(flag) return 1;
    flag=1;
    for(int i=0;i<cnt-1;i++)
        if(a[i]<a[i+1]) flag=0;
    if(flag) return -1;
        else return 0;
}
void solve(){
    int n,cnt;
    scanf("%d",&n);
    cnt=n;
    val_h=val_t=0;
    for(int i=0;i<n;i++)
        scanf("%I64d",&a[i]);
    for(int i=0;i<=n-1;i++){
        if(i==n-1||cnt==1){
            printf("nice series\n");
            return;
        }
        int flag=check(cnt);
        if(flag==0){
            if(i==0) printf("ugly series\n");
                else printf("%d\n",i-1);
            return;
        }
        else if(flag==-1){
            for(int i=0;i<cnt/2;i++)
                swap(a[i],a[cnt-1-i]);
            swap(val_h,val_t);
        }
        int ncnt=0;
        if(val_h) {t_a[ncnt++]=0;val_h--;}
        for(int i=0;i+1<cnt;i++)
            t_a[ncnt++]=a[i+1]-a[i];
        if(val_t) {t_a[ncnt++]=0;val_t--;}
        int j=1;
        cnt=0;
        a[cnt++]=t_a[0];
        if(a[0]==0) while(t_a[j]==0&&j<ncnt) {val_h++;j++;}
        for(;j<ncnt;j++) a[cnt++]=t_a[j];
        if(a[cnt-1]==0) while(a[cnt-2]==0&&cnt-2>=0) {cnt--;val_t++;}
    }
}
int main()
{
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
