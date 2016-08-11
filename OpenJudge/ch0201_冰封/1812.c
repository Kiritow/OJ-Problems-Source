#include<stdio.h>
#include<stdlib.h>

int main(void){
    int N,a,b,c,d;
    scanf("%d",&N);
    for(a = 4; a <= N; a++){
          for(b = 2; b < a; b++){
                for(c = b; c < a; c++){
                      for(d = c; d < a; d++){
                            if(a*a*a == b*b*b + c*c*c + d*d*d){
                                     printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
                            }
                      } 
                }
          }
    }
    return 0;
}
