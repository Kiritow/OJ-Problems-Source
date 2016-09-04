#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100 + 10;
bool cmp(char *s, int high, int low, char *sub)
{
 int j = 0;
 for(int i = high; i <= low; i++) if(s[i] != sub[j++]) return 0;
 return 1;
}
int cmpp(char *a, char *b) 
{
 int len_a = strlen(a), len_b = strlen(b), len = min(len_a, len_b), i;
 if(len_a != len_b) 
 {
 if(len_a > len_b) return 1;
 else return -1;
 }
 else 
 {
 for(i = 0; i < len; i++)
 {
 if(a[i] > b[i]) return 1; 
 if(a[i] < b[i]) return -1; 
 }
 return 0; 
 }
}
int to_int(char *s, int high, int low) 
{
 int ret = 0;
 for(int i = high; i <= low; i++) ret = ret*10 + s[i]-'0';
 return ret;
}
int main()
{
 int i, j, k, u, v, cnt = 1, T;
 char a[maxn], b[maxn], B[maxn], c[maxn], minn[maxn];
 scanf("%d", &T);
 while(T--)
 {
 scanf("%s%s", a, b);
 int len_a = strlen(a), len_b = strlen(b);
 for(i = 0; i < maxn; i++) minn[i] = '9'; 
 for(i = len_b; i < maxn; i++) b[i] = '0'; b[maxn-1] = 0; 
 int bb = to_int(b, 0, len_b-1); 
 if(len_a < len_b) 
 {
 int aa = to_int(a, 0, len_a-1);
 printf("Case #%d: %d\n", cnt++, bb-aa);
 continue;
 }
 bool ok = 0; 
 for(i = len_a-len_b; i >= 0; i--) 
 {
 int aa = to_int(a, i, i+len_b-1);
 if(aa == bb) 
 {
 ok = 1;
 break;
 }
 else 
 {
 for(u = 0; u < maxn; u++) B[u] = b[u]; 
 for(j = len_a-1, k = len_a-1-i; j >= i; j--, k--)
 {
 if(B[k] >= a[j]) c[k] = B[k] - a[j] + '0';
 else 
 {
 if(k-1 >= 0) B[k-1]--;
 c[k] = B[k] + 10 - a[j] + '0';
 }
 }
 c[len_a-i] = 0; 
 for(v = 0; v < len_a-i; v++) if(c[v] != '0') break; 
 if(v != 0) for(u = 0; v <= len_a-i; u++,v++) c[u] = c[v];
 if(cmpp(c, minn) < 0) for(u = 0; u <= len_a-i; u++) minn[u] = c[u]; 
 }
 }
 if(ok) printf("Case #%d: %d\n", cnt++, 0);
 else 
 {
 for(u = 0; u < maxn; u++) B[u] = b[u]; 
 for(j = len_a-1, k = len_a; j >= 0; j--, k--)
 {
 if(B[k] >= a[j]) c[k] = B[k] - a[j] + '0';
 else 
 {
 B[k-1]--;
 c[k] = B[k] + 10 - a[j] + '0';
 }
 }
 c[0] = B[0]; 
 c[len_a+1] = 0; 
 for(v = 0; v < len_a+1; v++) if(c[v] != '0') break; 
 if(v != 0) for(u = 0; v <= len_a+1; u++,v++) c[u] = c[v];
 if(cmpp(c, minn) == -1) for(u = 0; u <= len_a+1; u++) minn[u] = c[u]; 
 printf("Case #%d: %s\n", cnt++, minn);
 }
 }
 return 0;
}
