#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <iostream>
const int M = 50000;
using namespace std;
struct node{
    string s, path;
    int val;
};
const int f[] = {1, 1, 2, 6, 24, 120, 720, 5040, 5040*8};
string ans[M];
bool vis[M];
int cal(string s){
    int sum = 0;
    for(int i = 0; i < 8; ++ i){
        int cnt = 0;
        for(int j = i+1; j < 8; ++ j)
            if(s[j] < s[i]) ++cnt;
        sum += cnt*f[7-i];
    }
    return sum;
}
string tran(string s, int num){ 
    //string res = "";
    int i;
    if(num == 0){
        for(i = 0; i < 4; ++ i){
            swap(s[i], s[i+4]);
        }
    }
    else if(num == 1){
        char t= s[3];
        for(i = 2; i >= 0; -- i) s[i+1] = s[i];
        s[0] = t;
        t = s[7];
        for(i = 6; i >= 4; -- i) s[i+1] = s[i];
        s[4] = t;
    }
    else{
        char t = s[1];
        s[1] = s[5]; s[5] = s[6]; s[6] = s[2];
        s[2] = t;
    }
    return s;
}
void bfs(string st){  
    memset(vis, 0, sizeof(vis));
    queue<node > q;
    node t;
    t.s = st;
    t.val = cal(t.s); 
    t.path = ""; 
    ans[t.val] = t.path;
    vis[t.val] = 1;
    q.push(t);
    while(!q.empty()){
        node temp = q.front(); q.pop();
        for(int i  = 0; i < 3; ++ i){
            node cur = temp;
            cur.path += (i+'A');
            string a = tran(cur.s, i);
            int k = cal(a);
            if(!vis[k]){
                cur.s = a;
                cur.val = k;
                ans[cur.val] = cur.path;
                vis[k] = 1;
                q.push(cur);
            }
        }
    }
}
int main(){
    string st = "12345678";
    bfs(st);
    string en, ss;
    int i;
    while(cin >> ss >> en){
        swap(ss[4], ss[7]);  
        swap(ss[5], ss[6]);
        swap(en[4], en[7]);
        swap(en[5], en[6]);
        string mm(8, 'a');
        for(i = 0; i < 8; ++ i) mm[ss[i]-'0'] = i+'1'; 
        string de;
        for(i = 0; i < 8; ++ i) de += mm[en[i]-'0'];
        int k = cal(de);
        cout << ans[k]<<endl;
    }
    return 0;
}
