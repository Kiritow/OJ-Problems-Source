#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> VI;
char buf[10005];
int th;
void out(VI v){
    for(int i = 0; i < (int)v.size(); i ++) printf("%d ", v[i]);
    printf("\n");
}
VI mul(VI v1, VI v2){
    int n = (v1.size())*(v2.size())+1;
    VI ret(n, 0);
    for(int i = 0; i < (int)v1.size(); i ++){
        for(int j = 0; j < (int)v2.size(); j ++){
            ret[i+j] += v1[i]*v2[j];
        }
    }
    return ret;
}
VI add(VI v1, VI v2){
    int n = max(v1.size(), v2.size());
    VI ret(n, 0);
    for(int i = 0; i < (int)v1.size(); i ++) ret[i] += v1[i];
    for(int i = 0; i < (int)v2.size(); i ++) ret[i] += v2[i];
    return ret;
}
VI getE();
VI getP(){
    if(buf[th] == 'x'){
        VI ret(2, 0);
        ret[1] = 1;
        th ++;
        return ret;
    }
    if(buf[th] == '('){
        th ++;
        VI ret = getE();
        th ++;
        return ret;
    }
    int v = 0;
    while(buf[th] >= '0' && buf[th] <= '9'){
        v = v*10 + buf[th] - '0';
        th ++;
    }
    return VI(1, v);
}
VI getF(){
    VI ret = getP();
    if(buf[th] == '^'){
        th ++;
        VI tmp = getP(), t2 = ret;
        for(int i = 1; i < (int)tmp[0]; i ++){
            ret = mul(ret, t2);
        }
    }
    return ret;
}
VI getT(){
    VI ret;
    ret.push_back(1);
    while(buf[th] && buf[th] != '+' && buf[th] != '-' && buf[th] != ')'){
        VI tmp = getF();
        ret = mul(ret, tmp);
    }
    return ret;
}
VI getE(){
    VI ret;
    int sign = 0;
    while(buf[th]){
        if(sign != 0 && buf[th] != '+' && buf[th] != '-') break;
        sign = 1;
        if(buf[th] == '-') sign = -1;
        if(buf[th] == '+' || buf[th] == '-') th ++;
        VI tmp = getT();
        if(sign == -1) for(int i = 0; i < (int)tmp.size(); i ++) tmp[i] = -tmp[i];
        ret = add(ret, tmp);
    }
    return ret;
}
int gcd(int a, int b){
    return a == 0 ? b : gcd(b%a, a);
}
void normal(VI& v){
    while(v.size() && v.back() == 0) v.pop_back();
    int by = v[0];
    for(int i = 1; i < (int)v.size(); i ++) by = gcd(by, v[i]);
    for(int i = 0; i < (int)v.size(); i ++) v[i] /= by;
    if(v.size() && v.back() < 0) for(int i = 0; i < (int)v.size(); i ++) v[i] = -v[i];
}
void output(VI v){
    bool first = true;
    for(int i = (int)v.size()-1; i >= 0; i --){
        if(v[i] == 0) continue;
        if((v[i] == 1 || v[i] == -1) && i != 0){
            if(v[i] == 1) if(!first) printf("+");
            if(v[i] == -1) printf("-");
        }else{
            if(first){
                if(v[i] < 0){
                    printf("-");
                    v[i] = -v[i];
                }
                printf("%d", v[i]);
                first = false;
            }else{
                printf("%+d", v[i]);
            }
        }
        if(i == 0){
        }else if(i == 1){
            printf("x");
        }else printf("x^%d", i);
        first = false;
    }
    printf("\n");
}
int main() {
    while(scanf("%s", buf)){
        if(strlen(buf) == 1 && buf[0] == '.') break;
        th = 0;
        VI v1 = getE();
        scanf("%s", buf);
        th = 0;
        VI v2 = getE();
        normal(v1);
        normal(v2);
        while(1){
            if(v1.size() < v2.size()) swap(v1, v2);
            if(v2.size() == 0) break;
            int l1 = v1.back(), l2 = v2.back();
            int by = gcd(l1, l2);
            for(int i = v1.size()-1; i >= 0; i --){
                int tmp = v2.size()-1-(v1.size()-1-i), vt;
                if(tmp < 0) vt = 0;
                else vt = v2[tmp];
                v1[i] = v1[i]*(l2/by) - vt*(l1/by);
            }
            normal(v1);
        }
        output(v1);
    }
    return 0;
}
