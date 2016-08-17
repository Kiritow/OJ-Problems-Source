#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 199999
char b[N];
char a[N];
int LIS( int n) {
  int len = 1; b[0] = a[0];
  for (int i = 1; i < n; i++) {
    b[a[i] > b[len - 1] ? len++ : lower_bound(b, b + len, a[i]) - b] = a[i]; //·Ç½µ»»Îª>=ºÍupper_bound
  }
  return len;
}
int main()
{
    int t;
    scanf("%d%*c",&t);
    for(int test=0;test<t;++test)
    {
        gets(a);
        int L=strlen(a);
        sort(a,a+L);
        int ans=LIS(L);
        printf("Case #%d: %d\n",test+1,ans);
    }
    return 0;
}
