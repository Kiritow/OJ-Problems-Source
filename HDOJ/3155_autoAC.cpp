#include <stdio.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <math.h>
#include <algorithm>
#include <map>
#include <string.h>
using namespace std;
typedef long long LL;
typedef pair<int, int>PII;
typedef pair<PII, int>PII2;
string s;
int n;
int len;
map<char, int>val;
int value[20];
int at;
int good;
int eva()
{
 // cout << at << " " << s[at] << endl;
 if(good != 1) return 0;
 if(at >= len) 
 {
 good = -2;
 }
 else if(s[at] >= 'a' && s[at] <= 'z')
 {
 return value[val[s[at++]]];
 } 
 else if(s[at] >= 'A' && s[at] <= 'Z')
 {
 at++;
 int x, y;
 switch(s[at - 1])
 {
 case 'C': x = eva(); y = eva(); if(x && !y) return 0; else return 1;
 case 'N': x = eva(); return x ^ 1;
 case 'K': x = eva(); y = eva(); return x & y;
 case 'A': x = eva(); y = eva(); return x | y;
 case 'D': x = eva(); y = eva(); return !(x & y);
 case 'E': x = eva(); y = eva(); return (x == y);
 case 'J': x = eva(); y = eva(); return x ^ y;
 default: good = -1; break;
 }
 }
 else
 {
 good = -1;
 } 
}
int main()
{
 while(cin >> s)
 {
 good = 1;
 len = s.length();
 n = 0;
 val.clear();
 for(int i = 0; i < len; i++ )
 {
 if(s[i] >= 'a' && s[i] <= 'z' && val.find(s[i]) == val.end())
 {
 val[s[i]] = n++;
 }
 }
 int ct = 0, cn = 0;
 for(int i = 0; i < 1<<n && good == 1; i++ )
 {
 for(int j = 0; j < n; j++ )
 {
 if(i & (1<<j))
 value[j] = 1;
 else
 value[j] = 0;
 }
 at = 0;
 int res = eva();
 if(good == 1 && at < len) good = -3;
 if(res) ct++;
 else cn++;
 }
 cout << s << " is ";
 if(good == 1)
 {
 cout << "valid: ";
 if(ct && cn) cout << "contingent" << endl;
 else if(ct) cout << "tautology" << endl;
 else cout << "contradiction" << endl;
 }
 else if(good == -1)
 {
 cout << "invalid: invalid character" << endl;
 }
 else if(good == -2)
 {
 cout << "invalid: insufficient operands" << endl;
 }
 else
 {
 cout << "invalid: extraneous text" << endl;
 }
 }
return 0;
}
