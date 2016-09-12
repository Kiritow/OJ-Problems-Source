#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,m,l,num1,num2,cnt;
long long left[500010],right[500010];
long long sum1[500010],sum2[500010];
long long apple[500010];
long long ans;
int main()
{
    int i,j,k,a,b;
    scanf("%d",&t);
    while(t--)
    {
        cnt=0;num1=num2=0;
        memset(apple,0,sizeof(apple));
        memset(sum1,0,sizeof(sum1));
        memset(sum2,0,sizeof(sum2));
        scanf("%d%d%d",&l,&n,&k);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            for(j=1;j<=b;j++){
                apple[++cnt]=a;  
            }
        }
        k=min(k,cnt);
        for(i=1;i<=cnt;i++){
            if(apple[i]*2<=l){
               left[++num1]=apple[i]; 
            }
            else{
                right[++num2]=l-apple[i];
            }
        }
        sort(left+1,left+num1+1); 
        sort(right+1,right+num2+1);
        for(i=1;i<=num1;i++){
            if(i<=k) sum1[i]=left[i];   
            else sum1[i]=sum1[i-k]+left[i]; 
        }
        for(i=1;i<=num2;i++){
            if(i<=k) sum2[i]=right[i];
            else sum2[i]=sum2[i-k]+right[i];
        }
        ans=(long long)(sum1[num1]+sum2[num2])*2; 
        for(i=0;i<=num1&&i<=k;i++){
            ans=min(ans,(long long)(l+2*sum1[num1-i]+2*sum2[num2-(k-i)])); 
        }
        printf("%lld\n",ans);
    }
    return 0;
}
