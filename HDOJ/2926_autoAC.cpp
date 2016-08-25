#include<stdio.h>
#include<string.h>
__int64 f[70];
__int64 work(int n,__int64 r,__int64 st,__int64 ed)
{
    __int64 sum=0,num;
    if(n==0)return 1;
    num=f[n]/2;
    if(r<=num){
        if(ed<=num){
            sum=work(n-1,r,st,ed);
        }else if(st>num){
            sum=work(n-1,r,st-num,ed-num);
        }else {
            sum=work(n-1,r,st,num);
            sum+=work(n-1,r,1,ed-num);
        }
    }else{
        if(ed<=num){
            sum=work(n-1,r-num,st,ed);
        }else if(st>num){
            sum=-work(n-1,r-num,st-num,ed-num);
        }else {
            sum=work(n-1,r-num,st,num);
            sum-=work(n-1,r-num,1,ed-num);
        }
    }
    return sum;
}
int main()
{
    int i,j;
    int n;
    __int64 r,st,ed,ans;
    f[0]=1;
    for(i=1;i<=60;i++){
        f[i]=f[i-1]*2;
    }
    while(scanf("%d%I64d%I64d%I64d",&n,&r,&st,&ed)){
        if(n==-1&&r==-1&&st==-1&&ed==-1)break;
        ans=work(n,r+1,st+1,ed+1);
        printf("%I64d\n",ans);
    }
    return 0;
}
