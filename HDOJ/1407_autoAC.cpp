#include<stdio.h>
#include<math.h>
int main(){
    int num=0;
    int x,y,z;
    while(scanf("%d",&num)!=EOF){
        for(x=1;x<=sqrt(num*1.0/3);x++)
           for(y=x;y<=sqrt((num*1.0-x*x)/2);y++){
               z=sqrt(num-x*x-y*y);
               if(z*z==(num-x*x-y*y)){
                    printf("%d %d %d\n",x,y,z);
                    goto exit;
               }
           }
           exit:;
    }
}
