#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define inf 0x3fffffff
#define N 1100
struct node {
int l,r;
}f[N];
int ff[N];
double d;
int Min(int aa,int bb) {
return aa>bb?bb:aa;
}
int Max(int aa,int bb) {
return aa>bb?aa:bb;
}
int cmp(const void *a,const void *b)
{
    return (*(struct node *)a).r-(*(struct node *)b).r;
}
int main() {
     int n,i,j;
     int minn,maxx,tot,kk,k,ss,endd;
     while(scanf("%d",&n),n) {
            minn=inf;
            maxx=-1;
        for(i=0;i<n;i++) {
            scanf("%d%d",&f[i].l,&f[i].r);
            minn=Min(f[i].l,minn);
            maxx=Max(f[i].r,maxx);
        }
         qsort(f,n,sizeof(f[0]),cmp);
        endd=0;
    for(i=minn;i<=maxx;i++) {
        tot=0;
        memset(ff,0,sizeof(ff));
        for(j=0;j<n;j++) {
         kk=(f[j].l-i)/5;
         if(kk*5+i!=f[j].l)
            kk=kk*5+i+5;
        else
            kk=f[j].l;
         k=(f[j].r-i)/5;
         if(k*5+i==f[j].r)
            k=f[j].r-5;
         else
            k=5*k+i;
            k=Min(k,kk);
      for(ss=k;ss<f[j].r;ss+=5) {
         if(ff[ss]==0&&ss>=f[j].l&&ss<f[j].r) {
            tot++;
            ff[ss]=1;
            break;
         }
        }
        }
        if(endd<tot)
            endd=tot;
    }
    printf("%d\n",endd);
     }
return 0;
}
