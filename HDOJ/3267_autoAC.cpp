#include<cstdio>
#include<cstring>
#include<algorithm> 
using namespace std;
#define LL long long
int n, m; 
int l[32], r[32];
bool red[32], blue[32];
int find(int idx[10], int x){
    if(idx[x]==-1) return x;
    return idx[x]=find(idx, idx[x]); 
}
void merge(int gra[10][10],int idx[10], int x, int y){
    int rx = find(idx, x);
    int ry = find(idx, y);
    if(rx==ry) return;
    idx[rx] = ry;
    for(int k=0;k<n;k++){
        if(~idx[k]) continue;
        if(k==ry) continue;
        gra[ry][k] += gra[rx][k];
        gra[k][ry] = gra[ry][k];
    }
}
int condense(int gra[10][10],int idx[10]){
    bool flag=true;
    while(flag){
        flag = false;
        for(int i=0;i<n;i++){
            if(~idx[i]) continue;
            for(int j=i+1;j<n;j++){
                if(~idx[j]) continue;
                if(gra[i][j]>=2){
                    merge(gra, idx, i, j);
                    flag = true;
                }
            }
        }
    }
    int cnt=0; 
    for(int i=0;i<n;i++){
        if(~idx[i]) continue; 
        cnt++;
    }
    return cnt; 
}
int minmax(int deg, int red, int gra[10][10], int idx[10]){
    bool end = true;
    for(int i=0;i<m;i++){
        if(red&(1<<i)) continue;
        int rl = find(idx, l[i]);
        int rr = find(idx, r[i]); 
        if(rl==rr) continue;
        end = false;
        int tidx[10], tgra[10][10];
        memcpy(tidx, idx, sizeof(tidx));
        memcpy(tgra, gra, sizeof(tgra));
        if(deg&1){
            merge(tgra, tidx, rl, rr);
            if(condense(tgra, tidx)==1) return 1;
            if(minmax(deg+1, red, tgra, tidx)==1) return 1; 
        } else { 
            tgra[rl][rr] = tgra[rr][rl] = 0; 
            if(minmax(deg+1, red|(1<<i), tgra, tidx)==-1) return -1;
        }
    } 
    if(end) return -1;
    if(0==(deg&1)) return 1;
    if(1==(deg&1)) return -1;
} 
int gra[10][10], idx[10];
int main(){
    while(scanf("%d%d", &n,&m), ~n){
        memset(gra, 0, sizeof(gra));
        memset(idx, -1, sizeof(idx));
        for(int i=0;i<m;i++){
            scanf("%d%d", &l[i], &r[i]); 
            if(l[i]^r[i]){
                gra[l[i]][r[i]] ++;
                gra[r[i]][l[i]] ++;
            }
        }
        if(condense(gra, idx)==1||minmax(0, 0, gra, idx)==1) puts("YES");
        else puts("NO"); 
    } 
}
