#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int h[]={0,3,2,1,2,3,2,3,4,3,4,5,4,5,6,5,6,7,6,7,8};          
int p[2000000];
int a[100];
int bound,i,j,n,m,s,t;
bool flag;
int count(int x){                                         
    x = (x & 0x55555555) + ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x & 0x0F0F0F0F) + ((x >> 4) & 0x0F0F0F0F);
    x = (x & 0x00FF00FF) + ((x >> 8) & 0x00FF00FF);
    x = (x & 0x0000FFFF) + ((x >> 16) & 0x0000FFFF);
    return x;
}
int f(int x){                                               
    return h[p[x]];
}
void IDA(int d,int x,int tmp){                        
    if(d==bound){
        if(tmp==t){
            flag=true;
        }
        return ;
    }
    if(f(tmp^t)+d>bound||(m-x)+d<bound) return ;        
    for(int i=x+1;i<=m;i++){
        IDA(d+1,i,tmp^a[i]);
        if(flag) return ;
    }
}
int main(){
//    freopen("e:\\in.txt","r",stdin);
    for(i=0;i<=1100000;i++)
        p[i]=count(i);
    int cas=0;
    while(1){
        cas++;
        scanf("%d%d",&n,&m);
        scanf("%d%d",&s,&t);
        if(!n&&!m) break;
        for(i=1;i<=m;i++)
            scanf("%d",&a[i]);
        flag=false;
        for(bound=0;bound<=m;bound++){
            IDA(0,0,s);
            if(flag)
                break;
        }
        printf("Case #%d: ",cas);
        if(!flag) printf("Impossible\n");
        else printf("%d\n",bound);
    }
    return 0;
}
