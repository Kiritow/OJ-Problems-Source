#include<stdio.h>
#include<math.h>
int main(){  
  int i,temp,N;
  int number;
  long double member=0;
  scanf("%d",&N);
  while(N--){
      scanf("%d",&number);
      member=0;
      for(i=1,temp=0;i<=number;i++){
          member+=log10(i*1.0);
          }
          temp=floor(member)+1;
          printf("%d\n",temp);
    }
  getchar();
  return 0;
}
