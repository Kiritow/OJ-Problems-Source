#include<stdio.h>
#include<stdlib.h>

void fuck(){
//system("pause");
}

int main(void){
  int a, b[32768], i, c, d;
  scanf("%d",&a);
  for(i = 0; i < a; i++){
    scanf("%d",&b[i]);
  }
  for( = 0; i < a; i++){
    if((b[i]<4)||(b[i]%2!=0)){
        printf("0 0\n");
        continue;
    }
    c = b[i]/2;
    
    if(c%2){d = c/2+1;}
    else{d = c/2;}
    printf("%d %d\n",d,c);
  }
  fuck();
  return 0;
}
