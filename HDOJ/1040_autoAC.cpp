#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
 int t, n, i;
 int *d;
 cin >> t;
 while (t--) {
  cin >> n;
  d = (int *)malloc(sizeof(int)*n);
  for (i = 0; i < n; i++) {
   cin >> d[i];
  }
  sort (d, d+n);
  cout << d[0];
  for (i = 1; i < n; i++) {
   cout << " " << d[i]; 
  }
  cout << endl;
 }
 return 0;
}
