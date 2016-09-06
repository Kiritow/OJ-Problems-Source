#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <algorithm>
using namespace std;
char map[1010][1010];
int lefts[1010][1010],heights[1010][1010],rights[1010][1010];
int CountSingle(int n,int m,char sing){
    int ret=0;
    for(int i=1;i<=n;i++){
        if(i==1){
            int l=0;
            for(int j=1;j<=m;j++){
                if(map[i][j]!=sing){
                    heights[i][j]=0;
                    lefts[i][j]=m+1;
                    l=j;
                }
                else{
                    heights[i][j]=1;
                    lefts[i][j]=l+1;
                }
            }
            int r=m+1;
            for(int j=m;j>=1;j--){
                if(map[i][j]!=sing){
                    rights[i][j]=0;
                    r=j;
                }
                else{
                    rights[i][j]=r-1;
                    ret=max(ret,heights[i][j]*2+2*(rights[i][j]-lefts[i][j]+1));
                }
            }
        }
        else{
            int l=0;
            for(int j=1;j<=m;j++){
                if(map[i][j]!=sing){
                    heights[i][j]=0;
                    lefts[i][j]=m+1;
                    l=j;
                }
                else{
                    if(map[i-1][j]==sing){
                        heights[i][j]=heights[i-1][j]+1;
                        lefts[i][j]=max(lefts[i-1][j],l+1);
                    }
                    else{
                        heights[i][j]=1;
                        lefts[i][j]=l+1;
                    }
                }
            }
            int r=m+1;
            for(int j=m;j>=1;j--){
                if(map[i][j]!=sing){
                    rights[i][j]=0;
                    r=j;
                }
                else{
                    if(map[i-1][j]==sing){
                        rights[i][j]=min(rights[i-1][j],r-1);
                        ret=max(ret,heights[i][j]*2+2*(rights[i][j]-lefts[i][j]+1));
                    }
                    else{
                        rights[i][j]=r-1;
                        ret=max(ret,heights[i][j]*2+2*(rights[i][j]-lefts[i][j]+1));
                    }
                }
            }
        }
    }
    return ret;
}
int CountCross(int n,int m){
    int ret=0;
    for(int i=1;i<=n;i++){
        if(i==1){
            int l=0;
            for(int j=1;j<=m;j++){
                if(j==1){
                    heights[i][j]=1;
                    lefts[i][j]=1;
                }
                else{
                    if(map[i][j-1]==map[i][j]){
                        lefts[i][j]=j;
                        l=j-1;
                        heights[i][j]=1;
                    }
                    else{
                        lefts[i][j]=l+1;
                        heights[i][j]=1;
                    }
                }
            }
            int r=m+1;
            for(int j=m;j>=1;j--){
                if(j==m){
                    heights[i][j]=1;
                    rights[i][j]=m;
                }
                else{
                    if(map[i][j]==map[i][j+1]){
                        heights[i][j]=1;
                        rights[i][j]=j;
                        r=j+1;
                    }
                    else{
                        rights[i][j]=r-1;
                        heights[i][j]=1;
                    }
                }
                ret=max(ret,heights[i][j]*2+2*(rights[i][j]-lefts[i][j]+1));
            }
        }
        else{
            int l=0;
            for(int j=1;j<=m;j++){
                if(j==1){
                    if(map[i][j]!=map[i-1][j]){
                        heights[i][j]=heights[i-1][j]+1;
                        lefts[i][j]=1;
                    }
                    else{
                        heights[i][j]=1;
                        lefts[i][j]=1;
                    }
                }
                else{
                    if(map[i][j]!=map[i-1][j]){
                        heights[i][j]=heights[i-1][j]+1;
                        if(map[i][j]==map[i][j-1]){
                            lefts[i][j]=j;
                            l=j-1;
                        }
                        else{
                            lefts[i][j]=max(lefts[i-1][j],l+1);
                        }
                    }
                    else{
                        heights[i][j]=1;
                        if(map[i][j]==map[i][j-1]){
                            lefts[i][j]=j;
                            l=j-1;
                        }
                        else{
                            lefts[i][j]=l+1;
                        }
                    }
                }
            }
            int r=m+1;
            for(int j=m;j>=1;j--){
                if(j==m){
                    if(map[i][j]!=map[i-1][j]){
                        heights[i][j]=heights[i-1][j]+1;
                        rights[i][j]=m;
                    }
                    else{
                        heights[i][j]=1;
                        rights[i][j]=m;
                    }
                }
                else{
                    if(map[i][j]!=map[i-1][j]){
                        heights[i][j]=heights[i-1][j]+1;
                        if(map[i][j]==map[i][j+1]){
                            rights[i][j]=j;
                            r=j+1;
                        }
                        else{
                            rights[i][j]=min(rights[i-1][j],r-1);
                        }
                    }
                    else{
                        heights[i][j]=1;
                        if(map[i][j]==map[i][j+1]){
                            rights[i][j]=j;
                            r=j+1;
                        }
                        else{
                            rights[i][j]=r-1;
                        }
                    }
                }
                ret=max(ret,heights[i][j]*2+2*(rights[i][j]-lefts[i][j]+1));
            }
        }
    }
    return ret;
}
int main(){
    int ansR,ansB,ansC,kase=0;
    int T,n,m;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        getchar();
        for(int i=1;i<=n;i++)
            gets(map[i]+1);
        ansR=CountSingle(n,m,'R');
        ansB=CountSingle(n,m,'B');
        ansC=CountCross(n,m);
        cout<<"Case #"<<++kase<<": "<<max(ansR,max(ansB,ansC))<<endl;
    }
    return 0;
}
