#include <stdio.h>
int cal(int n){
     int s=0;
    for(int i=1;i<=n;i++){
      if(n%i==0) s++;}
   return s;
}
int main(){
   int n,a,b;
scanf("%d",&n);
while(n--){
   scanf("%d%d",&a,&b);
   int max=a;
     int m=cal(a);
   for(int i=a;i<=b;i++)
    if(m<cal(i)){
         m=cal(i);
         max=i;}
    printf("%d\n",max);
    }
return 0;
}
