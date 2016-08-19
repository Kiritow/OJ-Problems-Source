#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
using namespace std;
#include<string.h>
#define SSS 6000
#define SIZE 1000000
#define INF 2000000000
#define NUM 200
__int64 aa[300];
__int64 rr[50000];
int pri[NUM];
int sub[SIZE];
int pdsu(__int64 n)
{
    __int64 i;
    if(n<=0||n==1 )
        return 0;
    if( n==2)
        return 1;
    else{
        for(i=2; i*i<=n; i++)
            if(n%i==0)
                return 0;
    }
    return 1;
}
void sf(){
    int temp,n;
    for(int i=0;i<SIZE;i++)
       sub[i]=1;
    sub[0]=sub[1]=0;
    for(int i=2;i<=sqrt(SIZE);i++){
        if(sub[i]==1){
           temp=2*i;
           while(temp<=SIZE){
                 sub[temp]=0;
                 temp+=i;
           }
        }
    }
}
int  init(){
      int j = 0 ;
      pri[j++] = 2 ;
      pri[j++] = 3 ;
      for( int i = 3 ; i<SSS ;i++ ){
         if(sub[i]){
                     pri[j++]=i;
         }
      }
      return j;
}
int main(){
    int num;
    int t = 0 ;
    __int64 res , next ,next2 ;
    int b;
    sf();
    num = init();
    sf();
               for(int a = 1 ; a< 600 ; a++ ){
                       for(int i = 0; i<NUM ;i++  ){
                              res = pri[i] ;
                              b = pri[i] - a;
                              if(b == 0 ) continue;
                              next = a * pri[i] + b ;
                              if(next == pri[i]) continue;
                              if(res * next > INF){
                                      continue;
                                      }
                              if(next <0 )
                                      continue;
                              if(next >= SIZE){
                                  if(!pdsu(next))
                                      continue ;
                              }
                             else{
                                      if(!sub[next])
                                      continue ;
                              }
                              res = res * next;
                              if(res >INF) continue;
                            while(1){
                               next2 = next * a +b;
                               if(next2 == next ) break;
                               if(res * next2 > INF){
                                      break;
                                      }
                               if(next2 <0 )
                                      break;
                             if(next2 >= SIZE){
                                      if(!pdsu(next2))
                                      break ;
                              }
                              else{
                                      if(!sub[next2])
                                      break ;
                              }
                              res = res * next2;
                              if(res >INF) break;
                              rr[t++] = res ;
                              next = next2 ;
                            }
                       }
               }
     for(int i = 0 ; i<t ;i++ )
             for(int j = i+1 ; j <t ;j++)
                     {
                         if(rr[i]>rr[j]){
                         int temp = rr[i];
                         rr[i] = rr[j];
                         rr[j] = temp;
                         }
                     }
       int ccc = 0;
      for(int i = 0 ; i <t ; i++)
     {
              if(rr[i]!= rr[i+1])
              aa[ccc++]=rr[i];
     }
     int N;
    __int64 zuo ,you ;
            scanf("%d",&N);
               while(N--){
               scanf("%I64d%I64d",&zuo,&you);
          int     ans = 0 ;
         for(int i = 0 ; i <243 ;i++){
                 if(zuo<=aa[i] && you>=aa[i])
                ans++;
         }
               printf("%d\n",ans);
               }
    return 0 ;
}
