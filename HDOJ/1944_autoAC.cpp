#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std; 
int  s[101];
int tt[10001];
int g(int x , int  k)
{
    int mex[101];
    memset(mex,0,sizeof(mex));
    if(tt[x]!=-1) return tt[x]; 
    if(x-s[0]<0) return tt[x]=0;
    for(int i=0;i<k && x-s[i]>=0;i++) 
    { 
        mex[g(x-s[i] , k)]=1;  
    }
    for(int i=0;;i++) 
    if(!mex[i])  return tt[x]=i;
}
int main()
{
    int  k ;
    int n, t ,a , ans;
    while(scanf("%d",&k)!=EOF && k)
    {
        memset(tt,-1,sizeof(tt));
        tt[0]=0;
        for(int i=0;i<k;i++) scanf("%d",&s[i]);
        sort(s,s+k);
        scanf("%d",&t); 
        while(t--)
        {
            ans=0;
            scanf("%d",&n);
            for(int i=0;i<n;i++) 
            {
                scanf("%d",&a);  
                ans^=g(a , k);
            }  
            if(!ans)  printf("L"); 
            else printf("W");
        }
        printf("\n");
    }
    return 0;
}
