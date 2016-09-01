#include<iostream>
#include<cstring>
#include<map>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include<string>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<set>
#include<list>
#include<numeric>
#include<cassert>
#include<ctime>
using namespace std;
vector<int> prime;
int ans;
bool isPrime(int n){
    for(int p = 2; p <= n/p ; p++){
        if(n % p == 0){
            return false;
        }
    }
    return true;
}
void dfs(int next, vector<int> with, int n){
    int nn = n;
    bool can = true;
    for(vector<int>::iterator it = with.begin() ; it != with.end() ; it++){
        if(n % (*it-1) == 0)    {
            n /= (*it-1);
        }else {
            can = false;
            break;
        }
    }
    if(can){
        for(vector<int>::iterator it = with.begin() ; it != with.end() ; it++){
            while(n % *it == 0){
                n /= *it;
            }
        }
        if(n == 1)ans++;
        if(with.size() == 3){
            return;
        }
        for(int i = next ; i < prime.size(); i++){
            with.push_back(prime[i]);
            dfs(i+1, with, nn);
            with.pop_back();
        }
    }    
}
int main()
{
    for(int n; ~scanf("%d", &n); ){
        prime.clear();
        for(int i = 1 ; i <= n / i; i++){
            if(n % i == 0){
                if(isPrime(i+1)){
                    prime.push_back(i+1);
                }
                if(n/i != i && isPrime(n/i+1)){
                    prime.push_back(n/i+1);
                }
            }
        }
        ans = 0;
        dfs(0, vector<int>(), n);
        printf("%d\n", ans);
    }
    return 0;
}
