#include <stdio.h>
int main(){
    int n,i,a;
    int f[50];
    while(scanf("%d",&n),n){
        for(i=0;i<50;i++)
            f[i]=0;
        for(i=0;i<n*6;i++){
            scanf("%d",&a);
            f[a]=1;
        }
        for(i=1;i<50;i++)
            if(f[i]==0)i=60;
        printf("%s\n",i>55?"No":"Yes");
    }
}
