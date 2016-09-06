#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<queue>
#define inf 1<<28
#define M 6000005
#define N 1000005
#define maxn 300005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define MOD 1000000007
using namespace std;
int wa[maxn],wb[maxn],wv[maxn],Ws[maxn];  
int cmp(int *r,int a,int b,int l)  
{return r[a]==r[b]&&r[a+l]==r[b+l];}  
void da(const int *r,int *sa,int n,int m){  
    int i,j,p,*x=wa,*y=wb,*t;   
    for(i=0;i<m;i++) Ws[i]=0;   
    for(i=0;i<n;i++) Ws[x[i]=r[i]]++;   
    for(i=1;i<m;i++) Ws[i]+=Ws[i-1];   
    for(i=n-1;i>=0;i--) sa[--Ws[x[i]]]=i;   
    for(j=1,p=1;p<n;j*=2,m=p){   
        for(p=0,i=n-j;i<n;i++) y[p++]=i;   
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;   
        for(i=0;i<n;i++) wv[i]=x[y[i]];   
        for(i=0;i<m;i++) Ws[i]=0;   
        for(i=0;i<n;i++) Ws[wv[i]]++;   
        for(i=1;i<m;i++) Ws[i]+=Ws[i-1];   
        for(i=n-1;i>=0;i--) sa[--Ws[wv[i]]]=y[i];   
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)   
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;   
    }   
    return;   
}  
int sa[maxn],Rank[maxn],height[maxn];  
void calheight(const int *r,int *sa,int n){  
    int i,j,k=0;  
    for(i=1;i<=n;i++) Rank[sa[i]]=i;  
    for(i=0;i<n;height[Rank[i++]]=k)  
        for(k?k--:0,j=sa[Rank[i]-1];r[i+k]==r[j+k];k++);  
    return;  
} 
int a[maxn],pos[maxn];
char str[maxn];
int main(){
    int t,cas=0,n;
    scanf("%d",&t);
    while(t--){
        int len,m=0,num=30;
        scanf("%d",&n);
        scanf("%s",str);
        len=strlen(str);
        for(int i=0;i<len;i++) a[m++]=str[i]-'a'+1;
        for(int i=0;i<n;i++){
            a[m++]=num++;
            scanf("%s",str);
            int l=strlen(str);
            for(int j=0;j<l;j++)
                a[m++]=str[j]-'a'+1;
        }
        a[m]=0;
        da(a,sa,m+1,num+1);
        calheight(a,sa,m);
        mem(pos,0);
        int tmp=inf;
        for(int i=1;i<=m;i++){
            if(sa[i]<len){
                if(height[i]<tmp) tmp=height[i];
                if(pos[sa[i]]<tmp) pos[sa[i]]=tmp;
            }
            else tmp=inf;
        }
        tmp=inf;
        for(int i=m;i>=1;i--){
            if(sa[i-1]<len){
                if(height[i]<tmp) tmp=height[i];
                if(pos[sa[i-1]]<tmp) pos[sa[i-1]]=tmp;
            }
            else tmp=inf;
        }
        for(int i=1;i<=m;i++)
             if(sa[i]<len&& sa[i-1]<len)
                if(pos[sa[i-1]]<height[i])  
                    pos[sa[i-1]]=height[i];  
        LL ans=(LL)len*(len+1)/2;
        for(int i=0;i<len;i++)
            ans-=pos[i];
        printf("Case %d: %I64d\n",++cas,ans);
    }
    return 0;
}
