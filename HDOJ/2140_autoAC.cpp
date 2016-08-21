#include <stdio.h>
#include <string.h>
char a[1000]={'b','q','t','m','i','c','a','e','l'},b[1000]={' ', ',' ,'!','l','e','a','c','i','m'};
char c[10005];
int main(){
    int l,n;
   while(gets(c)){
    l=strlen(c);
   for(int i=0;i<l;i++){
        n=0;
     for(int j=0;j<=9;j++)
       if(c[i]==a[j]){
           printf("%c",b[j]);
           n=1;}
       if(n!=1) printf("%c",c[i]);
   }
   printf("\n");
   }
   return 0;
}
