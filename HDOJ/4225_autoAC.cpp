#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> Vx;
char str[100000],len = 0;
int idx = 0;
Vx getexp(int &f);
Vx getval(int &f);
bool Isnumber(char x){
    return x >= '0' && x <= '9';
}
int getnum(){
    int num = 0;
    int tt = 0;
    if(str[idx] == '-'){
        idx++;
        Vx tmp = getval(tt);
        return -tmp[0];
    }
    if(str[idx] == '+'){
        idx++;
        Vx tmp = getval(tt);
        return tmp[0];
    }
    while(Isnumber(str[idx])){
        num = num * 10 + str[idx] - '0';
        idx++;
    }
    return num;
}
int op(int a,int b,char opt){
    int Ret = 0;
    if(opt == '+') Ret = a + b;
    if(opt == '-') Ret = a - b;
    if(opt == '*') Ret = a * b;
    return Ret;
}
void display(Vx x){
}
Vx cal(Vx a,Vx b,char opt){
    Vx Ret;
    int i;
    if(a.size() == 1 && b.size() == 1){
        Ret.push_back(op(a[0],b[0],opt));
        return Ret;
    }
    if(a.size() == 1) {
        for(i = 0;i < b.size();i++){
            Ret.push_back(op(a[0],b[i],opt));
        }
        return Ret;
    }
    if(b.size() == 1) {
        for(i = 0;i < a.size();i++) {
            Ret.push_back(op(a[i],b[0],opt));
        }
        return Ret;
    }
    for(i = 0;i < a.size();i++) {
        Ret.push_back(op(a[i],b[i],opt));
    }
    return Ret;
}
Vx vary(int val){
    int i;
    Vx Ret;
    Ret.clear();
    if(val == 0) return Ret;
    if(val >  0) {
        for(i = 1;i <= val;i++) Ret.push_back(i);
    }else{
        for(i = -val;i >= 1;i--) Ret.push_back(i);
    }
    return Ret;
}
Vx getval(int &f){
    Vx Ret;
    int i;
    if(Isnumber(str[idx]) || str[idx] == '-'){
        Ret.push_back(getnum());
        f = 0;
        return Ret;
    }
    if(str[idx] == 'v'){
        idx = idx + 5;
        int tt = 0;
        Vx tmp = getexp(tt);
        idx++;
        Ret = vary(tmp[0]);
        f = 1;
        return Ret;
    }
    if(str[idx] == 'b'){
        idx = idx + 6;
        while(str[idx] != ')'){
            int tt = 0;
            Vx tmp = getexp(tt);
            Ret.push_back(tmp[0]);
            if(str[idx] == ')') break;
            idx++;
        }
        f = 1;
        idx++;
        return Ret;
    }
    if(str[idx] == 'd' && str[idx+1] == 'a'){
        idx = idx + 6;
        int tt = 0;
        Vx tmp = getexp(tt);
        idx++;
        if(tt == 1){
            int ans = tmp[tmp.size() - 1],p;
            if(tmp.size() % 2 == 0) p = -1;
            else p = 1;
            for(i = tmp.size() - 2;i >= 0;i--){
                if(p == 1) ans = tmp[i] + ans;
                else ans = tmp[i] - ans;
                p = -p;
            }
            f = 0;
            Ret.push_back(ans);
        }else{
            int p = 1,num = tmp[0];
            if(num > 0) {
                for(i = num;i >= 1;i--) {
                    Ret.push_back(i * p);
                    p = -p;
                }
            }else if(num < 0){
                for(i = num;i <= -1;i++){
                    Ret.push_back(i * p);
                    p = -p;
                }
            }
            f = 1;
        }
        return Ret;
    }
    if(str[idx] == 'd' && str[idx+1] == 'u'){
        idx = idx + 5;
        int tt = 0;
        Vx tmp = getexp(tt);
        idx++;
        int ans = tmp[tmp.size() - 1];
        for(i = tmp.size() - 2;i >= 0;i--){
            ans = tmp[i] - ans;
        }
        Ret.push_back(ans);
        f = 0;
        return Ret;
    }
    if(str[idx] == 's'){
        //sum()
        idx = idx + 4;
        int tt = 0;
        Vx tmp = getexp(tt);
        idx++;
        int ans = 0;
        for(i = 0;i < tmp.size();i++) {
            ans += tmp[i];
        }
        Ret.push_back(ans);
        f = 0;
        return Ret;
    }
    return Ret;
}
bool isop(char x){
    if(x == '+' || x == '-' || x == '*') return true;
    else return false;
}
Vx getexp(int &f){
    int i;
    int tmp = 0;
    Vx beg = getval(tmp);
    f = tmp;
    vector<pair<Vx,char> >E;E.clear();
    while(idx < len && str[idx] == ' '){
        if(isop(str[idx+1]) == false || str[idx+2] != ' ') break;
        while(str[idx] == ' ')idx++;
        char op = str[idx];
        idx++;
        while(str[idx] == ' ')idx++;
         int t = 0;
        Vx tmp = getval(t);
        f = (f|t);
        E.push_back(make_pair(tmp,op));
    }
    if(E.size() == 0) return beg;
    Vx Ret = E[E.size() - 1].first;
    for(i = E.size() - 1;i >= 0;i--){
        if(i > 0){
            Ret = cal(E[i-1].first,Ret,E[i].second);
        }else Ret = cal(beg,Ret,E[i].second);
    }
    return Ret;
}
int main(){
    int i,j,k,cas = 0;
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
        gets(str);
        idx = 0;
        int f = 0;
        len = strlen(str);
        Vx ans = getexp(f);
        if(f == 0) {
            printf("Case %d: %d\n",++cas,ans[0]);
        }else{
            printf("Case %d: ",++cas);
            printf("{");
            for(i = 0;i < ans.size();i++){
                printf("%d",ans[i]);
                if(i != ans.size() - 1) 
                    printf(", ");
            }
            printf("}\n");
        }
    }
    return 0;
}
