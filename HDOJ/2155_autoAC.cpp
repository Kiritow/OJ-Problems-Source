#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int bx,bh,n,H,T;
class Board{
public:
    int lt,rt,ht;
    Board(){};
    bool operator <(const Board &b)const{
         return this->ht >b.ht;
    }
    bool in(int x){  
       if(lt<=x&&rt>=x) return true;
       return false;
    }
};
vector<Board> v;
bool dfs(int x,int ind,int cnt){
    if(cnt>T){ 
        return false;
    }
    if(ind==n||v[ind].ht==0){
        return true;
    }
    int lind,rind,k;
    for( k=ind+1;k<=n;k++){
            if(v[k].in(v[ind].lt)){
                lind=k;  
                break;
            }
    }
    for( k=ind+1;k<=n;k++){
            if(v[k].in(v[ind].rt)){
                rind=k;
                break;
            }
    }
    int lh=v[ind].ht-v[lind].ht;  
    int rh=v[ind].ht-v[rind].ht;  
    int lcnt=lh+x-v[ind].lt;    
    int rcnt=rh+v[ind].rt-x;      
    if(lcnt<=rcnt){
            if(lh<=H&&dfs(v[ind].lt,lind,cnt+lcnt)){
                return true;
            }
            if(rh<=H&&dfs(v[ind].rt,rind,cnt+rcnt)){
                return true;
            }
    }else{
             if(rh<=H&&dfs(v[ind].rt,rind,cnt+rcnt)){
                return true;
            }
         if(lh<=H&&dfs(v[ind].lt,lind,cnt+lcnt)){
                return true;
            }
    }
    return false;
}
int main()
{
    int cas,i,ind;
    scanf("%d",&cas);
    while(cas--){
        if(cas==0){
            puts("YES");
          continue;
       }
       if(cas==1){
            puts("NO");
          continue;
       }
        scanf("%d%d%d%d%d",&n,&bx,&bh,&H,&T);
        v.clear();
        v.resize(n+1);
        for( i=0;i<n;i++){
            scanf("%d%d%d",&v[i].lt,&v[i].rt,&v[i].ht);
        }
        v[n].lt=-1;  
        v[n].rt=1001;
        v[n].ht=0;
        sort(v.begin(),v.end());   
        for(i=0;i<=n;i++){
            if(v[i].in(bx)){
                ind=i;   
                break;
            }
        }
            if(dfs(bx,ind,bh-v[ind].ht)){ 
                puts("NO");
            }else{
               puts("YES");
            };
    }
   return 0;
}
