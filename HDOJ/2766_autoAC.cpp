#include <cstdio>
#include <iostream>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef __int64 ll;
typedef vector<int> vi;
typedef vector<ll> vll;
string buf;
vll weight;
int deal(){
    weight.clear();
    cin >> buf;
    int depth = 0;
    ll tmp;
    for (string::iterator ii = buf.begin(); ii != buf.end(); ii++){
        switch (*ii){
            case '[':
                {
                    depth++;
                }break;
            case ']':
                {
                    depth--;
                }break;
            case ',':break;
            default:
                {
                    tmp = 0;
                    while ('0' <= *ii && *ii <= '9') tmp = tmp * 10 + *ii - '0', ii++;
                    ii--;
                    weight.push_back(tmp << depth);
                }
        }
    }
    sort(weight.begin(), weight.end());
    int len = weight.size();
    int best = 0, cur = 1;
    weight.push_back(-1);
    for (int i = 0; i < len; i++){
        if (weight[i + 1] != weight[i]){
            best = max(best, cur);
            cur = 1;
        }
        else cur++;
    }
    return len - best;
}
int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        cout << deal() << endl;
    }
    return 0;
}
