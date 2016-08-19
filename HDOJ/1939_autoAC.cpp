#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int t1[10000],t2[10000];
int main(){
     int a,b;
     while(scanf("%d%d",&a,&b)!=EOF){
            if(a==0&&b==0)
            break;
        memset(t1,0,sizeof(t1));
        memset(t2,0,sizeof(t2));
        for(int i=0;i<a;i++)
            scanf("%d",&t1[i]);
        for(int i=0;i<b;i++)
            scanf("%d",&t2[i]);
        sort(t1,t1+a);
        sort(t2,t2+b);
        if(t1[0]<t2[1])
            printf("Y\n");
        else
            printf("N\n");       
     }     
     return 0;
}
