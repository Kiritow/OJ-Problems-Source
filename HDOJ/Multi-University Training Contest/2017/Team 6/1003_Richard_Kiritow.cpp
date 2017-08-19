#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <map>
#include <cstdlib>
#include <cstring>

using namespace std;
bool cmp(const pair<int, int> A, const pair<int, int> B) {
    if (A.first == B.first) {
        return A.second < B.second;
    }
    else
        return A.first > B.first;
}
vector<pair<int, int>> a;
int main() {
    int testcases;
    cin >> testcases;
    while (testcases--) {
        a.clear();
        int n;
        cin >> n;
        int temp;
        for (int i = 1; i <= n; i++) {
            cin >> temp;
            a.push_back(make_pair(temp,i));
        }
        sort(a.begin(),a.end(),cmp);
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[j].second%i == 0)
                    continue;
                else {
                    cout << a[j].first;
                    break;
                }
            }
            if (i != n)
                cout << ' ';
        }
        cout << endl;
    }
}