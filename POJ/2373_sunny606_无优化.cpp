#include<cstdio>
#include<cstring>
#define L 1001000

int a,b,n,l,inf,dp[L];
int tree[4*L];

void updata(int *p, int rt, int l, int r,int pos, int k)
{
     if (l==r) {
          p[rt]=k;
          return ;
     }
     int mid=(l+r)>>1;
     if (pos<=mid) updata(p,rt<<1, l, mid, pos, k);
     else updata(p, rt<<1|1, mid+1, r, pos, k);
     int lv=p[rt<<1];
     int rv=p[rt<<1|1];
     p[rt]=lv<rv?lv:rv;
}

int query(int *p,int rt, int l,int r, int s, int e)
{
    if(l==s && e==r) return p[rt];
    int mid = (l+r)>>1;
    if(e<=mid) return query(p, rt<<1, l, mid, s, e);
    if(s>mid) return query(p, rt<<1|1, mid+1, r, s, e);
    int lv=query(p,rt<<1, l, mid, s,mid);
    int rv=query(p,rt<<1|1, mid+1, r, mid+1, e);
    return lv<rv?lv:rv;
}

int dpro(void)
{
     if(b<1) return -1;
     dp[0]=0;

     for(int j=0; j<4*L; j++) tree[j]=L*2;

     for(int j=a; j<=b; j++){
         if(dp[2*j]<=inf) dp[0+2*j] = dp[0]+1;
         updata(tree,1, 1, l ,j,dp[2*j]);
     }
     
     for(int i=2*b+2; i<=l; i+=2)
     {
         int min;
         int pos = (i>>1);
         min = query(tree, 1, 1, l, pos-b, pos-a);

         if (dp[i]<=inf) {
              //if(dp[i]>min+1) 
              dp[i]=min+1;
              updata(tree,1,1,l,pos,dp[i]);
                     /*for(int j=a; j<=b; j++) {
                         int idx = i-2*j;
                         if(idx<0) break;
                         if ( dp[i]>dp[idx]+1 ) dp[i]=dp[idx]+1;
                     }*/
         }
     }
     if(dp[l]>=inf) return -1;
     else return dp[l];
}

int main()
{
    while (scanf("%d%d", &n, &l)!=EOF) {

          scanf("%d%d", &a, &b);
          inf = (l/a)+9;
          for(int i=0; i<=l; i++) dp[i]=inf;

          for(int i=0; i<n; i++) {
                int s, e;  
                scanf("%d%d", &s, &e);
                for(int j=s+1; j<e; j++) dp[j] = inf+1;
          }

          if(l&1==1) printf("-1\n");
          printf("%d\n", dpro());
    }
    return 0;
}
