#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int b[50],temp[50];
int cmp(int a,int b){
    return a>b;
}
int main(){
    int n,a,t,i,j,k,cur,num,sum,minn,sign;
    scanf("%d",&t);
    while(t--){
    scanf("%d%d",&n,&a);
    sign=0;
    for(i=0;i<n;i++)
    scanf("%d",&b[i]);
    minn=99999999;
    sum=1<<n;
    sort(b,b+n,cmp);           
    for(i=1;i<sum;i++){        
       j=i;k=cur=0;num=a;
       while(j){                
       if(j&1)temp[cur++]=b[k]; 
       j>>=1;k++;
       }
       if(cur>=minn)           
       continue;
       for(j=0;j<cur;j++)
       num%=temp[j];
       if(num==0){
       minn=cur;
       sign=1;
       }
    }
    if(sign)
    printf("%d\n",minn);
    else
    printf("-1\n");
    }
    return 0;
}
