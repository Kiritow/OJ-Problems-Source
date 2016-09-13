#include<cstdio>
#define L 1001000

int a,b,n,l,inf,dp[L],queue[L],head,tail,size;

void insert(int idx)
{
     tail++;
     while(head<tail && dp[queue[tail-1]]>dp[idx]) tail--;
     queue[tail]=idx;
     while(idx-queue[head]>=size) head++;
}

int dpro(void)
{
     if(b<1) return -1;
     dp[0]=0;
     size=2*b+1;
     head=0;
     tail=-1;
     
     for(int i=a; i<=b; i++) if(dp[2*i]<=inf) dp[2*i]=1;     
     int seg = 2*b-2*a;
     for(int i=0; i<=seg; i+=2) insert(i);
     
     for(int i=2*b; i<=l; i+=2)
     {
         if(i-a*2>seg) insert(i-a*2);
         while(i-queue[head]>=size) head++;
         if (dp[i]<=inf) dp[i]=dp[queue[head]]+1;
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
          else printf("%d\n", dpro());
    }
    return 0;
}
