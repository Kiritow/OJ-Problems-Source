#include<iostream>
#include<cstdio>
#include<string>
#include<sstream>
using namespace std;
const char* alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
long long a;
long long stand[15];

long long jia(stringstream&);
long long cheng(stringstream&);

long long pow (long long a, long long b) {
    long long ans = 1;
    for (int i = 0; i < b; i++) ans *= a;
    return ans;
}

bool check () {
    string line; getline(cin, line);
    for (a = 0; a < 10; a++) {
        stringstream ss(line);
        if (jia(ss) != stand[a]) return false;
    }
    return true;
}

int main ()
{
    int n;
    string line; 
    getline(cin, line);
    for (a = 0; a < 10; a++) {
        stringstream ss(line);
        stand[a] = jia(ss);
    }
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++) 
        if (check()) cout << alph[i];
    return 0;
}

long long pan(stringstream& ss) {
    long long num = 0;
    char c = 0;
    ss >> c;
    if (c == 'a') return (long long)a;
    else {
        ss.putback(c);
        ss >> num;
        return num;
    }
}

long long getnum(stringstream& ss) {
    long long b = 0;
    char c = 0;
    b = pan(ss);
    ss >> c;
    while (c == '^') {
        long long d;
        d = pan(ss);
        b = pow(b, d);
        c = 0;
        ss >> c;
    }
    ss.putback(c);
    return b;
}

long long cheng (stringstream& ss) {
    char c = 0;
    long long ans = 0;
    long long num = 0;
    ss >> c;
    if (c == '(') ans = jia(ss);
    else {
        ss.putback(c);
        ans = getnum(ss);
    } 
    while (ss >> c) {
        switch (c) {
            case ' ' :
                continue;
            case '*' :
                ss >> c;
                if (c == '(') num = jia(ss);
                else {
                    ss.putback(c);
                    num = getnum(ss);
                }
                ans *= num;
                break;
            default : 
                ss.putback(c); 
                return ans;
        }
    }
    return ans;
}

long long jia (stringstream& ss) {
    char c = 0;
    long long ans = 0;
    ans = cheng(ss);
    while (ss >> c) {
        switch (c) {
            case ' ' :
                continue;
            case '+' : 
                ans += cheng(ss);
                break; 
            case '-' :
                ans -= cheng(ss);
                break; 
            case ')' :
                ss >> c;
                while (c == '^') {
                    long long b;
                    b = pan(ss);
                    ans = pow(ans, b);
                    c = 0;
                    ss >> c;
                }
                ss.putback(c);
                return ans;
        }     
    }
    return ans; 
}
