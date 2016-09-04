#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define MAXN 110
int t , n , m;
int flag;
int x[MAXN] , r[MAXN];
int tmp_x[MAXN] , tmp_r[MAXN];
int search(){
    for(int i = 1 ; i < n ; i++){
        if(tmp_x[i] > tmp_x[i-1]) return i;
    }
    return 0;
}
void solve(){
    int k;
    memset(tmp_ , 0 , sizeof(tmp_x));
    memcpy(tmp_ , r , sizeof(r));
    sort(tmp_ , tmp_r+n);
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(tmp_r[i] == r[j]){
                tmp_x[i] = x[j] ; break;
            }
        }
    }
    while(k = search()){
        for(int i = 0 ; i < k ; i++) tmp_x[i] += 400;
    }
    if(tmp_x[0] <= m) flag = 1;
}
int main() {
    scanf("%d" , &t);
    while(t--){
        memset(x , 0 , sizeof(x));
        memset(r , 0 , sizeof(r));
        scanf("%d%d" ,&n , &m);
        for(int i = 0 ; i < n ; i++)
            scanf("%d%d" , &x[i] , &r[i]);
        flag = 0 ; solve();
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
