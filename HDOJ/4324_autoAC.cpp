#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2010;
int n,indeg[N];     
char str[N][N];
int main(){
    int t,cases=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int flag=0;
        memset(indeg,0,sizeof(indeg));  
        int i,j;
        for(i=0;i<n;i++){
            scanf("%s",str[i]);
            for(j=0;j<n;j++)
                if(str[i][j]=='1')  
                    indeg[j]++;
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                if(indeg[j]==0)    
                    break;
            if(j==n){       
                flag=1;
                break;
            }else{
                indeg[j]--; 
                for(int k=0;k<n;k++)    
                    if(str[j][k]=='1')
                        indeg[k]--;
            }
        }
        if(flag)
            printf("Case #%d: Yes\n",++cases);
        else
            printf("Case #%d: No\n",++cases);
    }
    return 0;
}
