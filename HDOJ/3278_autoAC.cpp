#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#define N 10
using namespace std;
char s[5][7],str[25];
char v[1<<24];
queue<int> que;
int inline row_op(int r,int n,int op)  
{
    int tmp[6];
    for(int i=0;i<6;i++){
        tmp[i]=n&(1<<(r*6+i));
        n-=tmp[i];
    }
    if(op){ 
        tmp[0]<<=5;
        for(int i=1;i<6;i++){
            tmp[i]>>=1;
        }
    }else{  
        for(int i=0;i<5;i++){
            tmp[i]<<=1;
        }
        tmp[5]>>=5;
    }
    n+=tmp[0]+tmp[1]+tmp[2]+tmp[3]+tmp[4]+tmp[5];
    return n;
}
int inline col_op(int c,int n,int op)  
{
    int tmp[4];
    for(int i=0;i<4;i++){
        tmp[i]=n&(1<<(i*6+c));  
        n-=tmp[i];
    }
    if(op){
        tmp[0]<<=18;
        tmp[1]>>=6;
        tmp[2]>>=6;
        tmp[3]>>=6;
    }else{
        tmp[0]<<=6;
        tmp[1]<<=6;
        tmp[2]<<=6;
        tmp[3]>>=18;    
    }    
    n+=tmp[0]+tmp[1]+tmp[2]+tmp[3];
    return n;
}
void countMoves()
{
    int cnt=0;
    while(!que.empty()) que.pop();
    memset(v,-1,sizeof(v)); 
    que.push(124800);
    v[124800]=0;
    while(!que.empty()){
        int t=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            int tmp=row_op(i,t,1);
            if(v[tmp]==-1){
                que.push(tmp);
                v[tmp]=v[t]+1;
            }
            tmp=row_op(i,t,0);
            if(v[tmp]==-1){
                que.push(tmp);
                v[tmp]=v[t]+1;
            }
        }
        for(int j=0;j<6;j++){
            int tmp=col_op(j,t,1);
            if(v[tmp]==-1){
                que.push(tmp);
                v[tmp]=v[t]+1;
            }
            tmp=col_op(j,t,0);
            if(v[tmp]==-1){
                que.push(tmp);
                v[tmp]=v[t]+1;
            }    
        }
    }
    return;
}
int main()
{
    int T,cas=1;
    int b,w,g;
    cin >> T;
    countMoves();
    while(T--){
        b=w=g=0;
        for(int i=0;i<4;i++){
            scanf("%s",s[i]);
            for(int j=0;j<6;j++){
                if(s[i][j]=='B'){
                    b+=(1<<(i*6+j));
                }else if(s[i][j]=='W'){
                    w+=(1<<(i*6+j));
                }else{
                    g+=(1<<(i*6+j));
                }
            }
        }
        int cnt = min(v[b],min(v[w],v[g]));
        cout << "Case " << cas << ": " << cnt << endl;
        cas++;
    }
    return 0;
}
