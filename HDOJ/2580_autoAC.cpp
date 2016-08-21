#include <cstdio>
#include <cstring>
#include <iostream>
#define N 2000000
using namespace std;
int no[N],maxok[N];
int solve(int n,int k){
     if(n<=k+1)return 0;
     int x=0,y=0;
     no[0]=maxok[0]=1;
     while(no[x]<n)
     {
         x++;
         no[x]=maxok[x-1]+1;
         while(no[y+1]*k<no[x])
             y++;
         if(no[y]*k<no[x])
             maxok[x]=no[x]+maxok[y];
         else
             maxok[x]=no[x];
     }
     if(no[x]==n) return 0;
     int ans;
     while(n)
     {
         if(n>=no[x])
         {
             ans=no[x];
             n-=no[x];
         }
         x--;
     }
     return ans;
}
int main(){
    int t,n,k,Case=0;
    scanf("%d",&t);
    while(++Case<=t){
        scanf("%d%d",&n,&k);
        printf("Case %d: ",Case);
        int tmp=solve(n,k);
        if(tmp)printf("%d\n",tmp);
           else printf("lose\n");
    }
 return 0;
 }
