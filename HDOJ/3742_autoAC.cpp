#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1000000 + 10;
struct Node{
    int a, b, val;
}node[maxn];
int parent[maxn];
bool cmp(const Node &a, const Node &b){
    return a.val < b.val ;
}
void Init(int num){
    for(int i=0; i<num; i++)
        parent[i] = i;
}
int main(){
    int n, m;
    while(cin >>n >>m, n||m){
        int ans = 0, i;
        for( i=0; i<m; i++){
            cin >>node[i].a >>node[i].b >>node[i].val;
        }
        sort(node, node+m, cmp);
        Init(n);
        for( i=0; i<m; i++){
            if( node[i].a == parent[node[i].a] || node[i].b == parent[node[i].b])
                ans = ans > node[i].val ? ans : node[i].val;
            parent[ node[i].a ] = -1;
            parent[ node[i].b ] = -1;
        }
        for( i=0; i<n; i++)
            if(parent[i] == i)
                break;
        if(i < n)
            cout <<"IMPOSSIBLE" <<endl;
        else
            cout <<ans <<endl;
    }
    return 0;
}
