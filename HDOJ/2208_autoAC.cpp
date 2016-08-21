#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,map[20][20];
int root[20],flag;
void DFS(int x,int y){  
    if(flag)    
        return ;
    if(y>m)     
        return ;
    if(x==n){   
        flag=1;
        return ;
    }
    for(int i=0;i<x;i++){
        if(root[i]!=i)  
            continue;
        int tag=1;
        for(int j=i;j<x && tag;j++) 
            if(root[j]==i)
                tag=map[j][x];
        if(tag){    
            root[x]=i;  
            DFS(x+1,y); 
            root[x]=x;  
        }
    }
    DFS(x+1,y+1);   
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        memset(map,0,sizeof(map));
        flag=0;
        int k,x;
        for(int i=0;i<n;i++){
            scanf("%d",&k);
            root[i]=i;
            while(k--){
                scanf("%d",&x);
                map[i][x]=1;  
            }
        }
        DFS(0,0);
        if(m>=n || flag)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
