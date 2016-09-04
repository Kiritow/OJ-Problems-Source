#include <cstdio>
typedef unsigned long long ullong;
int eval(int f[], int x, ullong k){
bool vst[10];
for(int i = 0;i < 10; ++i) vst[i] = false;
vst[x] = true;
while(k--){
x = f[x];
if(vst[x]){
int len = 1;
for(int y = f[x];y != x;y = f[y]) ++len;
k %= len;
while(k--) x = f[x];
return x;
}
else vst[x] = true;
}
return x;
}
int g[10][10];
ullong min(ullong a, ullong b){
return a < b ? a : b;
}
int main(){
int TT;
scanf("%d", &TT);
for(int cas = 1; cas <= TT; ++cas){
for(int i = 0;i < 10; ++i){
for(int j = 0;j < 10; ++j){
scanf("%d", g[j] + i);
}
}
ullong a, b;
scanf("%I64u %I64u", &a, &b);
ullong ans = 0;
for(ullong t = 1;t <= b;t *= 10){
ullong u = a, v = b;
int d = u / t % 10;
ullong uu = min((u / t + 1) * t - 1, v);
int val = eval(g[d], d, uu - u);
for(++d, u = uu;d < 10 && u < v; ++d, u = uu){
uu = min(u + t, v);
val = eval(g[d], val, uu - u);
}
if((v - u) / t >= 10){
int f[10];
for(int d = 0;d < 10; ++d){
f[d] = d;
for(int j = 0;j < 10; ++j){
f[d] = eval(g[j], f[d], t);
}
}
val = eval(f, val, (v - u) / t / 10);
u += (v - u) / t / 10 * t * 10;
}
for(d = 0; u < v; ++d, u = uu){
uu = min(u + t, v);
val = eval(g[d], val, uu - u);
}
ans += val * t;
}
printf("%I64u\n", ans);
}
return 0;
}
