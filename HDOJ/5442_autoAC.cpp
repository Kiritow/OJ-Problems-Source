#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
#define maxn 200007
int wwa[maxn],wwb[maxn],wwv[maxn],wws[maxn];
int cmp(int *r,int a,int b,int l){
    return r[a]==r[b]&&r[a+l]==r[b+l];
}
void da(int *r,int *sufix,int n,int m){
    int i,j,p,*x=wwa,*y=wwb,*t;
    for(i=0;i<m;i++)wws[i]=0;
    for(i=0;i<n;i++)wws[x[i]=r[i]]++;
    for(i=1;i<m;i++)wws[i]+=wws[i-1];
    for(i=n-1;i>=0;i--)sufix[--wws[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p){
        for(p=0,i=n-j;i<n;i++)y[p++]=i;
        for(i=0;i<n;i++)
            if(sufix[i]>=j)
                y[p++]=sufix[i]-j;
        for(i=0;i<n;i++)wwv[i]=x[y[i]];
        for(i=0;i<m;i++)wws[i]=0;
        for(i=0;i<n;i++)wws[wwv[i]]++;
        for(i=1;i<m;i++)wws[i]+=wws[i-1];
        for(i=n-1;i>=0;i--)
            sufix[--wws[wwv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sufix[0]]=0,i=1;i<n;i++)
            x[sufix[i]]=cmp(y,sufix[i-1],sufix[i],j)?p-1:p++;
    }
    return;
}
int r[maxn];
int rank1[maxn],height[maxn],sufix[maxn];
void calheight(int *r,int *sufix,int n){
    int i,j,k=0;
    for(i=0;i<=n;i++) rank1[sufix[i]]=i;
    for(i=0;i<n;height[rank1[i++]]=k)
        for(k?k--:0,j=sufix[rank1[i]-1];r[i+k]==r[j+k];k++);
    return;
}
struct Node{
    int p,c;
};
int comp(Node a,Node b){
    if(a.p == b.p) return a.c < b.c;
    return a.p < b.p;
}
Node ans[maxn];
char word[maxn];
int main(){
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",word);
        for(int i = 0;i < n; i++){
            r[i]=r[i+n] = word[i];
        }
        int len =n*4+1;
        r[n*2] = '#';
        for(int i = 0;i < n; i++){
            r[i+n*2+1] = r[i+n*3+1] = word[n-i-1];
        }
        r[len] = 0;
        da(r,sufix,len+1,328);
        calheight(r,sufix,len);
        int cnt = 0;
        ans[cnt++].p = sufix[len];
        for(int i = len-1;i > 1; i--){
            if(height[i+1] < n) break;
            if(sufix[i]>=n&&sufix[i]<=n*2) continue;
            if(sufix[i]>=n*3+1)continue;
            ans[cnt++].p = sufix[i];
        }
        for(int i = 0;i < cnt; i++){
            if(ans[i].p > 2*n){
                ans[i].c =1;
                ans[i].p = n-(ans[i].p-2*n-1);
            }
            else {
                ans[i].p++;
                ans[i].c =  0;
            }
        }
        sort(ans,ans+cnt,comp);
        printf("%d %d\n",ans[0].p,ans[0].c);
    }
    return 0;
}
