#include <stdio.h>
#include <cmath>
#define maxn 100010
double a[maxn],b[maxn],up,down,ans,g;
int n,m,x,y;
int main(){
    int i,j,k,t,cas=0;
    scanf("%d",&t);
    while(t--){
        ans=0;
        scanf("%lf%lf",&up,&down);
        g=(up-down)*(up-down);
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        scanf("%lf",&a[i]);
        for(i=0;i<m;i++)
        scanf("%lf",&b[i]);
        x=0,y=0;
        while(x<n && y < m){
            ans+=sqrt(g+(a[x]-b[y])*(a[x]-b[y]));
            if(x==n-1) y++;
            else if(y==m-1) x++;
            else{
                if(fabs(a[x]-b[y+1]) < fabs(b[y]-a[x+1]))
                y++;
                else x++;
            }
        }
        printf("Case #%d: %.2lf\n",++cas,ans);
    }
    return 0;
}
