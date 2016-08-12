#include <iostream>
#include <string>
using namespace std;
int main()
{
 int T, n, money, v, day;
 int vmin;
 double imin, temp;
 string brand, strmin;
 cin >> T;
 while (T--) {
  cin >> n;
  imin = -1.0;
  vmin = -1;
  while (n--) {
   cin >> brand >> money >> v;
   if (v < 200) continue;
   else {
    day = (v >= 1000) ? 5 : v / 200;
    temp = money*1.0/day;
    if (imin == -1.0) {
     imin = money*1.0/day;
     vmin = v;
     strmin = brand;
    }
    if (temp < imin) {
     strmin = brand;
     imin = money*1.0/day;
     vmin = v;
    }
    else if (temp-imin > -0.000001 && temp-imin < 0.000001) {
     if (vmin < v) {
      strmin = brand;
      vmin = v;
     }
    }
   }
  }
  cout << strmin << endl;
 }
 return 0;
}
