#include <iostream>
#include<cctype>
#include<string>
#include<cstdio>
#include<sstream>
using namespace std;
#define MAXN 110000
#define INF 10000000
int d[MAXN], u[MAXN], v[MAXN], w[MAXN], num[10];
int n, m, e, ve, vMax, vMin;
string input, s;
int ballman_ford()
{
 for(int i = 0; i <= n; d[i++] = INF);
 d[0] = 0;
 for(int i = 0; i < n; i++){
 for(int j = 0; j < ve; j++)
 if(d[v[j]] > d[u[j]] + w[j])
 d[v[j]] = d[u[j]] + w[j];
 }
 for(int j = 0; j <= ve; j++)
 if(d[v[j]] > d[u[j]] + w[j])
 return 0;
 for(int j = 1; j <= n; j++){
 if(vMin > d[j]) vMin = d[j];
 }
 return 1;
}
int main()
{
 int i, j, k, l, flag;
 while(cin>>n){
 if(!n) break;
 cin>>m;
 getchar();
 e = 0;
 for(i = 0; i < m; i++){
 getline(cin, input);
 istringstream in(input);
 num[0] = num[1] =num[2] = 0;
 for(j = 0, l = 0; in>>s; j++){
 if(isdigit(s[0])){
 for(k = 0; k < s.size(); k++)
 num[l] = num[l] * 10 + s[k] - '0';
 l++;
 }
 if(j == 3){
 if(s == "at") flag = 1;
 else flag = 0;
 }
 }
 if(flag){
 u[e] = num[0]; v[e] = num[2]; w[e++] = -num[1];
 }else {
 u[e] = num[0]; v[e] = num[2]; w[e++] = 0;
 u[e] = num[2]; v[e] = num[0]; w[e++] = num[1];
 }
 }
 for(i = 1, ve = e; i <= n; i++, ve++){
 u[ve] = 0; v[ve] = i; w[ve] = 0;
 }
 vMin = 1 << 30;
 if(ballman_ford()){
 int minv = 1 << 30;
 for (int i = 1; i <= n; i++) {
 if (minv > d[i] - vMin)
 minv = d[i] - vMin;
 }
 if (minv == 0) {
 for (int i = 1; i <= n; i++) {
 printf("%d", d[i] - vMin + 1);
 if (i != n) {
 printf(
 " ");
 }
 }
 printf("\n");
 } else {
 for (int i = 1; i <= n; i++) {
 printf("%d", d[i] - vMin);
 if (i != n) {
 printf(
 " ");
 }
 }
 printf("\n");
 }
 }else printf("Impossible.\n");
 }
 return 0;
}
