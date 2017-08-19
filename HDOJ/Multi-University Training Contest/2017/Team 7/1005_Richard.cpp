#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;
        if (a % 2 == 1)
            cout << (a - 1) / 2 + 2;
        else
            cout << a / 2 + 1;
        cout << endl;
    }
}