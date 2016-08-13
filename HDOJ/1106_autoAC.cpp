#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[1005];
int a[1005];
char * temp;
int cmp(const void *p1,const void *p2){
    return *(int *)p1-*(int *)p2;
}
int main(){
    int c;
    while(gets(s)){
        a[0]=atoi(strtok(s,"5"));
        c=1;
        while(temp=strtok(NULL,"5")){
            a[c++]=atoi(temp);
        }
        qsort(a,c,sizeof a[0],cmp);
        for(int i=0;i<c;i++){
            printf(i==c-1?"%d\n":"%d ",a[i]);
        }
    }
    return 0;
}
