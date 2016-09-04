#include<iostream>
#include<cstring>
#include<map>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<set>
#include<list>
#include<numeric>
#include<cassert>
#include<sstream>
#include<ctime>
#include<bitset>
#include<functional>
using namespace std;
typedef pair<int, int> pii;
int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isLeap(long long year)
{
    return year % 400 == 0 || year % 4 == 0 && year % 100 != 0; 
}
vector<pii> ht;
vector<string> pvt[10];
vector<string> leapVt[10];
int sum[10];
int rev(int t)
{
    char str[10];
    sprintf(str, "%04d", t);
    reverse(str, str+4);
    return atoi(str);
}
void init()
{
    for (int mm = 1; mm <= 12; mm++) {
        for (int dd = 1; dd <= day[mm]; dd++) {
            if (dd % 10 == 0) continue;
            int t = mm*100 + dd;
            ht.push_back(pii(rev(t), t));
        }
    }
    sort(ht.begin(), ht.end());
    long long now = 9220;
    for (int n = 0; n <= 7; n++, now *= 10) {//9220*..*0229
        if (n == 0) {
            pvt[n].push_back("");
            leapVt[n].push_back("");
        } else if (n == 1) {
            for (char i = '0'; i <= '9'; i++) {
                pvt[n].push_back(string(1, i));//
                int year = now+(i-'0');
                if (isLeap(year)) {
                    leapVt[n].push_back(pvt[n].back());
                }
            }
        } else {
            int nn =  n - 2;
            for (char i = '0'; i <= '9'; i++) {
                for (vector<string>::iterator it = pvt[nn].begin(); it != pvt[nn].end(); it++) {
                    pvt[n].push_back(i+*it+i);
                    long long year = now+atoi(pvt[n].back().c_str());
                    if (isLeap(year)) {
                        leapVt[n].push_back(pvt[n].back());
                    }
                }
            }
        }
        sum[n] = 330*pvt[n].size() + leapVt[n].size();
    }
}
int main()
{  
    init();
    int T, k, n;
    for (scanf("%d", &T); T--; ) {
        scanf("%d", &k);
        k--; 
        for (n = 0; n <= 7; n++) {
            if (k < sum[n]) break;
            else k -= sum[n];
        }
        int num = pvt[n].size();
        if (k >= 322*num) {
            k -= 322*num;
            if (k < leapVt[n].size()) {
                printf("9220%s0229\n", leapVt[n][k].c_str());
            } else {
                k -= leapVt[n].size();
                int p = k/num + 322;
                printf("%d%s%04d\n", ht[p].first, pvt[n][k%num].c_str(), ht[p].second);
            }
        } else {
            int p = k/num;
            printf("%d%s%04d\n", ht[p].first, pvt[n][k%num].c_str(), ht[p].second);
        }
    }
    return 0;
}
