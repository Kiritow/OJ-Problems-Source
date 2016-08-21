#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<map>
using namespace std;
map<int,int>mp;
const int MOD=2008;
int fun(int a,int n){  
   if(n==1)return a;
   int num=fun(a,n/2);
   num=num*num%MOD;
   if(n%2==1)num=num*a%MOD;
   return (num+MOD)%MOD;    
}
int cal(int n){    
    if(mp[n]!=0)return mp[n];
    mp[n]=fun(2,n)-2;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
              mp[n]=(mp[n]-cal(i)+MOD)%MOD;
              if(i*i!=n)mp[n]=(mp[n]-cal(n/i)+MOD)%MOD;     
           }           
    }
   return mp[n];   
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
       mp[0]=0;
       mp[1]=2;
       mp[2]=2;
       if(n<=2){cout<<mp[n]<<endl;continue;}
       int ans=cal(n);
       cout<<ans<<endl;                                   
    }    
    return 0;
}
