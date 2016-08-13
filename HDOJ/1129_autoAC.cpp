#include<stdio.h>
#include<string.h>
char c[28]={'_','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','.'};
int plaincode[71];
int main(){
    int k,i,n;
    char ch[71];
    while(scanf("%d",&k),k){
        scanf("%s",ch);
        n=strlen(ch);
        for(i=0;i<n;i++){
            if(ch[i]>='a'&&ch[i]<='z'){
                plaincode[(k*i)%n]=((ch[i]-96)+i)%28;
                //printf("%d ",(int)(ch[i]-96));
            }
            else if(ch[i]=='_'){
                plaincode[(k*i)%n]=((ch[i]-95)+i)%28;
            }
            else{
                plaincode[(k*i)%n]=((ch[i]-19)+i)%28;
            }
        }
        for(i=0;i<n;i++){
            printf("%c",c[plaincode[i]]);
        }
        printf("\n");
    }
    return 0;
}
