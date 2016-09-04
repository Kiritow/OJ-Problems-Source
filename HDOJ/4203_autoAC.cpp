#include<cstdio>  
#include<stdlib.h>  
#include<cstring>  
#include<queue>  
using namespace std;  
int main(){  
    int i,t,T,k,s;  
    scanf("%d",&T);  
    for(t=1;t<=T;t++){  
        scanf("%d %d",&s,&k);  
        if(k&1){  
            if(s&1)printf("1\n");  
            else printf("0\n");  
        }  
        else{  
            int tem=s%(k+1);  
            if(tem==k)printf("%d\n",k);  
            else{  
                if(tem&1)printf("1\n");  
                else printf("0\n");  
            }  
        }  
    }  
}
