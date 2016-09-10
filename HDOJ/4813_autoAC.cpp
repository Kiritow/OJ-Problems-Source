#include<stdio.h>
#include<string.h>
char s[1000005];
int main(){
    int t,n,m,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        scanf("%s",s);
        for(i=0,j=0;i<n*m;i++){
            printf("%c",s[i]);
            j++;
            if(j==m){
                printf("\n");
                j=0;
            }    
        }
    }
    return 0;
}
