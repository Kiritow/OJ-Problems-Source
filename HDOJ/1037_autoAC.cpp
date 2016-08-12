#include <iostream>
using namespace std;
int main()
{
 int a, b, c, min;
 while (cin >> a >> b >> c) {
  min = a;
  if (b < min) min = b;
  if (c < min) min = c;
  if (min > 168) cout << "NO CRASH" << endl;
  else cout << "CRASH " << min << endl;
 }
 return 0;
}
