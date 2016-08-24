#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std;
struct P{
    int l;
    int i;
    P(){}
}p[1000000],q[1000000];
bool cmp(P a,P b){
    return a.l<b.l;
}
int in(){
    int r=0;
    char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    do{
        r=r*10+c-'0';
        c=getchar();
    }while(c>='0'&&c<='9');
    return r;
}
int res[1000000];
bool fl[1000000];
int main(){
    int ca;
    scanf("%d",&ca);
    while(ca-->0){
        int n,d;
        scanf("%d%d",&n,&d);
        for(int i=0;i<n;i++){
            p[i].l=in();
            p[i].i=i;
        }
        for(int i=0;i<d;i++){
            q[i].l=in();
            q[i].i=i;
        }
        sort(p,p+n,cmp);
        sort(q,q+d,cmp);
        memset(fl,false,sizeof(fl));
        int cnt=0;
        for(int i=d-1,j=n-1;i>=0;i--){
            while(j>=0&&p[j].l>q[i].l){
                int fr=p[j].i;
                fl[fr]=true;
                if(fr>0&&fr<n-1&&fl[fr-1]&&fl[fr+1])cnt--;
                else if(fr>0&&fl[fr-1]);
                else if(fr<n-1&&fl[fr+1]);
                else cnt++;
                j--;
            }
            res[q[i].i]=cnt;
        }
        for(int i=0;i<d;i++){
            printf("%d ",res[i]);
        }
        printf("\n");
    }
}
