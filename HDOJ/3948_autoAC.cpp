#include<cstdio>  
#include<cmath>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
#define MAXN 200100  
int dp[MAXN][20];  
char r[MAXN];  
int sa[MAXN];  
int wa[MAXN],wb[MAXN],wv[MAXN],ws[MAXN];  
int height[MAXN],rk[MAXN];  
int mm[MAXN];  
int cas;  
inline bool cmp(int *r,int a,int b,int len){  
    return r[a]==r[b]&&r[a+len]==r[b+len];  
}  
void SA(int n,int m){  
    int i,j,p,*x=wa,*y=wb,*t;  
    for(i=0;i<m;i++)  
        ws[i]=0;  
    for(i=0;i<n;i++)  
        ws[x[i]=r[i]]++;  
    for(i=1;i<m;i++)  
        ws[i]+=ws[i-1];  
    for(i=n-1;i>=0;i--)  
        sa[--ws[x[i]]]=i;  
    for(j=p=1;p<n;j<<=1,m=p){  
        for(p=0,i=n-j;i<n;i++)  
            y[p++]=i;  
        for(i=0;i<n;i++){  
            if(sa[i]>=j)  
                y[p++]=sa[i]-j;  
        }  
        for(i=0;i<m;i++)  
            ws[i]=0;  
        for(i=0;i<n;i++)  
            ws[wv[i]=x[y[i]]]++;  
        for(i=1;i<m;i++)  
            ws[i]+=ws[i-1];  
        for(i=n-1;i>=0;i--)  
            sa[--ws[wv[i]]]=y[i];  
        for(t=x,x=y,y=t,x[sa[0]]=0,p=i=1;i<n;i++)  
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;  
    }  
}  
void Height(int n){  
    int i,j,k=0;  
    for(i=0;i<=n;i++)    
        rk[sa[i]]=i;  
    for(i=0;i<n;height[rk[i++]]=k)  
        for(k?k--:0,j=sa[rk[i]-1];r[i+k]==r[j+k];k++);  
}  
int init(){  
    int i,j,len;  
    memset(height,0,sizeof(height));  
    len=strlen(r);  
    r[len]='$';  
    for(j=0;j<len;j++)  
        r[j+len+1]=r[len-1-j];  
    r[j+len+1]='\0';  
    return len*2+1;  
}  
void st(int n){  
    int i,j,p,q;  
    for(i=1;i<=n;i++)  
        dp[i][0]=i;  
    for(j=1;j<=mm[n];j++)  
        for(i=1;i+(1<<j)-1<=n;i++){  
            p=height[dp[i][j-1]];  
            q=height[dp[i+(1<<(j-1))][j-1]];  
            if(p>q)  
                dp[i][j]=dp[i+(1<<(j-1))][j-1];  
            else  
                dp[i][j]=dp[i][j-1];  
        }  
}  
int RMQ_MIN(int i,int j){  
    int tem;  
    if(i>j){  
        tem=i;  
        i=j;  
        j=tem;  
    }  
    i++;           
    int k=mm[(j-i+1)];  
    return min(height[dp[i][k]],height[dp[j-(1<<k)+1][k]]);  
}  
void solve(int n){  
    int i,j,ans=0,pre1=0,pre2=0;  
    st(n);  
    for(i=2;i<=n;i++){  
        pre1=min(pre1,height[i]);  
        j=RMQ_MIN(i,rk[n-1-sa[i]]);  
        if(j>pre1){  
            ans+=j-pre1;  
            pre1=j;  
        }  
        pre2=min(pre2,height[i]);  
        j=RMQ_MIN(i,rk[n-sa[i]]);  
        if(j>pre2){  
            ans+=j-pre2;  
            pre2=j;  
        }  
    }  
    printf("Case #%d: %d\n",cas,ans);  
}  
int main(){  
    int i,j,n,t,T;  
    mm[0]=-1;  
    for(i=1;i<MAXN;i++)  
        mm[i]=((i&(i-1))==0)?mm[i-1]+1:mm[i-1];           
    scanf("%d",&T);  
    cas=0;  
    for(t=1;t<=T;t++){  
        scanf("%s",r);  
        n=init();  
        SA(n+1,130);  
        Height(n);  
        cas++;  
        solve(n);  
    }  
}
