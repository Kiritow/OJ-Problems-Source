#pragma comment(linker, "/STACK:102400000,102400000")  
#include<iostream>  
#include<vector>  
#include<algorithm>  
#include<cstdio>  
#include<queue>  
#include<stack>  
#include<string>  
#include<map>  
#include<set>  
#include<cmath>  
#include<cassert>  
#include<cstring>  
#include<iomanip>  
using namespace std;  
#ifdef _WIN32  
#define i64 __int64  
#define out64 "%I64d\n"  
#define in64 "%I64d"  
#else  
#define i64 long long  
#define out64 "%lld\n"  
#define in64 "%lld"  
#endif  
/************ for topcoder by zz1215 *******************/  
#define foreach(c,itr)  for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)  
#define FOR(i,a,b)      for( int i = (a) ; i <= (b) ; i ++)  
#define FF(i,a)         for( int i = 0 ; i < (a) ; i ++)  
#define FFD(i,a,b)      for( int i = (a) ; i >= (b) ; i --)  
#define S64(a)          scanf(in64,&a)  
#define SS(a)           scanf("%d",&a)  
#define LL(a)           ((a)<<1)  
#define RR(a)           (((a)<<1)+1)  
#define pb              push_back  
#define pf              push_front  
#define X               first  
#define Y               second  
#define CL(Q)           while(!Q.empty())Q.pop()  
#define MM(name,what)   memset(name,what,sizeof(name))  
#define MC(a,b)     memcpy(a,b,sizeof(b))  
#define MAX(a,b)        ((a)>(b)?(a):(b))  
#define MIN(a,b)        ((a)<(b)?(a):(b))  
#define read            freopen("out.txt","r",stdin)  
#define write           freopen("out2.txt","w",stdout)  
const int inf = 0x3f3f3f3f;  
const i64 inf64 = 0x3f3f3f3f3f3f3f3fLL;  
const double oo = 10e9;  
const double eps = 10e-9;  
const double pi = acos(-1.0);  
const int maxn = 1 << 20;  
const i64 mod = 4294967296;  
struct zz{  
    string s;  
    i64 a;  
}zx;  
int n;  
int c[44][32];  
string s[44];  
i64 a[44];  
i64 dp[maxn];  
i64 dpx[maxn];  
int cas[44];  
int ret[22];  
vector<zz>v;  
int ns;  
int size;  
i64 start(){  
    for (int i = 0; i < (1 << ns); i++){  
        dp[i] = -1;  
    }  
    dp[0] = 0;  
    size = v.size();  
    for (int step = 0; step < 32; step++){  
        for (int state = 0; state < (1 << ns); state++){  
            dpx[state] = -1;  
        }  
        for (int state = 0; state < (1 << ns); state++) if(dp[state] != -1){  
            i64 tos = 0;  
            i64 value = 0;  
            for (int i = 0; i < size; i++){  
                if (v[i].s == "+="){  
                    if (state & (1 << cas[i])){  
                        if (c[i][step] == 4){  
                            tos |= 1 << cas[i];  
                        }  
                        else if( c[i][step] == 2){  
                            if (value == 1){  
                                tos |= 1 << cas[i];  
                                value = 0;  
                            }  
                            else{  
                                value = 1;  
                            }  
                        }  
                    }  
                    else{  
                        if (c[i][step] == 4){  
                            if (value == 1){  
                                tos |= 1 << cas[i];  
                                value = 0;  
                            }  
                            else {  
                                value = 1;  
                            }  
                        }  
                    }  
                }  
                else{  
                    if (c[i][step] == 0){  
                        value = 0;  
                    }  
                    else if (c[i][step] == 1){  
                        value = 1;  
                    }  
                    else if (c[i][step] == 3){  
                        value = 1 - value;  
                    }  
                }  
            }  
            i64 temp = value << step;  
            temp += dp[state];  
            if (temp > dpx[tos]){  
                dpx[tos] = temp;  
            }  
            tos = 0;  
            value = 1;  
            for (int i = 0; i < size; i++){  
                if (v[i].s == "+="){  
                    if (state & (1 << cas[i])){  
                        if (c[i][step] == 4){  
                            tos |= 1 << cas[i];  
                        }  
                        else if (c[i][step] == 2){  
                            if (value == 1){  
                                tos |= 1 << cas[i];  
                                value = 0;  
                            }  
                            else{  
                                value = 1;  
                            }  
                        }  
                    }  
                    else{  
                        if (c[i][step] == 4){  
                            if (value == 1){  
                                tos |= 1 << cas[i];  
                                value = 0;  
                            }  
                            else {  
                                value = 1;  
                            }  
                        }  
                    }  
                }  
                else{  
                    if (c[i][step] == 0){  
                        value = 0;  
                    }  
                    else if (c[i][step] == 1){  
                        value = 1;  
                    }  
                    else if (c[i][step] == 3){  
                        value = 1 - value;  
                    }  
                }  
            }  
            temp = value << step;  
            temp += dp[state];  
            if (temp > dpx[tos]){  
                dpx[tos] = temp;  
            }  
        }  
        for (int state = 0; state < (1 << ns); state++){  
            dp[state] = dpx[state];  
        }  
    }  
    i64 ans = -1;  
    for (int i = 0; i < (1 << ns); i++){  
        ans = max(ans, dp[i]);  
    }  
    return ans;  
}  
i64 toint(string temp){  
    i64 re = 0;  
    for (int i = 0; i < temp.size(); i++){  
        if (temp[i] <= '9' && temp[i] >= '0'){  
            re *= (1 << 4);  
            re += temp[i] - '0';  
        }  
        else if (temp[i] >= 'a' && temp[i] <= 'f'){  
            re *= (1 << 4);  
            re += temp[i] - 'a' + 10;  
        }  
    }  
    return re;  
}  
int main(){  
    int T;  
    cin >> T;  
    while (T--){  
        cin >> n;  
        string ts;  
        for (int i = 1; i <= n; i++){  
            cin >> s[i] >> ts;  
            a[i] = toint(ts);  
            if (s[i] == "-="){  
                s[i] = "+=";  
                a[i] = -a[i];  
                a[i] = (a[i] + mod) % mod;  
            }  
        }  
        v.clear();  
        int temp;  
        for (int i = 1; i <= n; i++){  
            zx.s = s[i];  
            zx.a = a[i];  
            if (zx.s == "+="){  
                temp = i + 1;  
                while (true){  
                    if (temp<=n && s[temp] == "+="){  
                        zx.a += a[temp];  
                        zx.a %= mod;  
                        temp++;  
                    }  
                    else{  
                        i = temp - 1;  
                        break;  
                    }  
                }  
                v.push_back(zx);  
            }  
            else {  
                v.push_back(zx);  
            }  
        }  
        ns = 0;  
        for (int x = 0; x <v.size(); x++){  
            if (v[x].s == "+="){  
                cas[x] = ns;  
                ret[ns++] = x;  
                for (int i = 0; i < 32; i++){  
                    if (v[x].a &((i64)1 << i)){  
                        c[x][i] = 4;  
                    }  
                    else{  
                        c[x][i] = 2;  
                    }  
                }  
            }  
            else if (v[x].s == "^="){  
                for (int i = 0; i < 32; i++){  
                    if (v[x].a & ((i64)1 << i)){  
                        c[x][i] = 3;  
                    }  
                    else{  
                        c[x][i] = 2;  
                    }  
                }  
            }  
            else if (v[x].s == "&="){  
                for (int i = 0; i < 32; i++){  
                    if (v[x].a & ((i64)1 << i)){  
                        c[x][i] = 2;  
                    }  
                    else {  
                        c[x][i] = 0;  
                    }  
                }  
            }  
            else if (v[x].s == "|="){  
                for (int i = 0; i < 32; i++){  
                    if (v[x].a & ((i64)1 << i)){  
                        c[x][i] = 1;  
                    }  
                    else{  
                        c[x][i] = 2;  
                    }  
                }  
            }  
        }  
        cout << start() << endl;  
    }  
    return 0;  
}
