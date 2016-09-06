#include<cstdio>
#include<cstring>
using namespace std;
struct{
    int m,f;
    char c;
}d[10010],tmp;
int n,m,l,r;
bool h[10010],k[10];
void out(int x){
    if(x==-1)return;
    out(d[x].f);
    putchar(d[x].c);
}
int main()
{
    int C=0;
    while (~scanf("%d%d",&n,&m)){
        printf("Case %d: ",++C);
        memset(h,true,sizeof(h));
        memset(k,true,sizeof(k));
        l=r=0;
        for(int i=0;i<m;i++){
            int x;
            scanf("%d",&x);
            k[x]=0;
        }
        int ans=-1;
        for(int i=1;i<10;i++)if(k[i]){
            tmp.c=i+'0';
            h[tmp.m=i%n]=false;
            tmp.f=-1;
            d[r++]=tmp;
            if(tmp.m==0){
                ans=r-1;
                break;
            }
        }
        while(l<r && ans==-1){
            for(int i=0;i<10;i++)if(k[i]){
                tmp.c=i+'0';
                tmp.m=(d[l].m*10 + i)%n;
                if(h[tmp.m]){
                    h[tmp.m]=false;
                    tmp.f=l;
                    d[r++]=tmp;
                    if(tmp.m==0){
                        ans=r-1;
                        break;
                    }
                }
            }
            l++;
        }
        if(ans==-1) puts("-1");
        else{
            out(ans);
            putchar('\n');
        }
    }
    return 0;
}
