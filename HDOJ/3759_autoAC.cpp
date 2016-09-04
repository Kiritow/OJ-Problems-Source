#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std ;
int num[15] ;
int b[10] ;
int temp[10] , cnt = 0;
int p[10] ;
int N ;
int s[10] ;
int st[10] , ed[10] ;
char str[10][3] ;
struct card{
 int a[5] , R;
 void insert(int list[]){
 for (int i = 0 ; i < 5 ; i++)
 b[i] = list[i] ;
 memset(num,0,sizeof(num));
 for (int i = 0 ; i < 5 ; i++)
 num[b[i]]++ ;
 bool flag = 0 ;
 for (int i = 0 ; i < 5 ; i++){
 if (num[b[i]]>1){
 flag=1;
 break ;
 }
 }
 if (flag==0){
 sort(b,b+5) ;
 for (int i = 0 ; i < 5 ; i++) a[i] = b[i] ;
 if (b[0]==2&&b[1]==3)
 if (b[2]==4&&b[3]==5)
 if (b[4]==14){
 b[4] = 1 ;
 sort(b,b+5);
 for (int i = 0 ; i < 5 ; i++)
 a[i] = b[i] ;
 R = 5;
 return ;
 }
 if (b[0]==b[2]-2 && b[1]==b[2]-1)
 if (b[3]==b[2]+1 && b[4]==b[2]+2)
 {
 R = 5 ;
 return ;
 }
 R = 1 ;
 return ;
 }
 int sum2 = 0 , sum3 = 0 , sum4 = 0 ;
 for (int i = 2 ; i < 15 ; i++){
 if (num[i]==2) sum2++ ;
 if (num[i]==3) sum3++ ;
 if (num[i]==4) sum4++ ;
 }
 if (sum4==1){
 int pos ;
 for (int i = 0 ; i < 5 ; i++)
 if (num[b[i]] != 4)
 pos = i ;
 a[0] = b[pos] ;
 R = 7 ;
 if (pos != 0){
 for (int i = 1 ; i < 5 ; i++)
 a[i] = b[0] ;
 return ;
 }
 if (pos != 1){
 for (int i = 1 ; i < 5 ; i++)
 a[i] = b[1];
 return ;
 }
 }
 if (sum2 == 1 && sum3 == 1){
 R = 6 ;
 for (int i = 0 ; i < 5 ; i++){
 if (num[b[i]] == 3){
 for (int j = 2 ; j < 5 ; j++)
 a[j] = b[i] ;
 }else
 {
 for (int j = 0 ; j < 2 ; j++)
 a[j] = b[i] ;
 }
 }
 return ;
 }
 if (sum3 == 1){
 cnt = 0 ; int pos = -1 ;
 for (int i = 0 ; i < 5; i++)
 if (num[b[i]] != 3)
 temp[cnt++] = b[i] ;
 else
 pos = i ;
 for (int i = 2 ; i < 5; i++)
 a[i] = b[pos] ;
 sort(temp,temp+2);
 for (int i = 0 ; i < 2 ; i++)
 a[i] = temp[i] ;
 R = 4 ;
 return ;
 }
 if (sum2 == 1){
 cnt = 0 ; int pos = -1 ;
 for (int i = 0 ; i < 5; i++)
 if (num[b[i]] != 2)
 temp[cnt++] = b[i] ;
 else
 pos = i ;
 for (int i = 3 ; i < 5; i++)
 a[i] = b[pos] ;
 sort(temp,temp+3);
 for (int i = 0 ; i < 3 ; i++)
 a[i] = temp[i] ;
 R = 2 ;
 return ;
 }
 R = 3 ;
 cnt = 0 ; int pos = -1 ;
 for (int i = 0 ; i < 5 ; i++)
 if (num[b[i]] != 1)
 temp[cnt++] = b[i] ;
 else
 pos = i ;
 a[0] = b[pos] ;
 sort(temp,temp+4);
 for (int i = 1 ; i < 5 ; i++)
 a[i] = temp[i-1];
 }
}state[15*15*15*15*15] ;
void check(){
 if (p[0]==p[1] && p[0]==p[2])
 if (p[0]==p[3] && p[0]==p[4])
 return ;
 state[++N].insert(p) ;
}
void dfs(int i){
 if (i > 4){
 check() ;
 return ;
 }
 for (int j = 2 ; j < 15 ; j++)
 {
 p[i] = j ;
 dfs(i+1) ;
 }
}
int get(char c){
 if (c>='0' && c<='9') return c - '0' ;
 if (c=='T') return 10 ;
 if (c=='J') return 11 ;
 if (c=='Q') return 12 ;
 if (c=='K') return 13 ;
 if (c=='A') return 14 ;
}
int Cmp(card &A , card &B){
 if (A.R < B.R) return -1 ;
 if (A.R > B.R) return 1 ;
 for (int i = 4 ; i >= 0 ; i--){
 if (A.a[i] < B.a[i])
 return -1 ;
 if (A.a[i] > B.a[i])
 return 1 ;
 }
 return 0 ;
}
bool cmp(const card &A , const card &B){
 if (A.R != B.R) return A.R < B.R ;
 for (int i = 4 ; i > 0 ; i--)
 if (A.a[i] != B.a[i])
 return A.a[i] < B.a[i];
 return A.a[0] < B.a[0] ;
}
int search(int L,int R,card A){
 int ret ;
 while (L<=R){
 int mid = (L+R)>>1 ;
 if (Cmp(state[mid],A)>=0){
 R = mid - 1 ;
 ret = mid ;
 }else
 L = mid + 1 ;
 }
 return ret ;
}
int main(){
 N = 0 ;
 dfs(0) ;
 sort(state+1,state+N+1,cmp);
 int cnt = 1 ;
 for (int i = 2 ; i <= N ; i++){
 if (Cmp(state[i],state[i-1])==0) continue ;
 state[++cnt] = state[i] ;
 }
 N = cnt ; memset(s,0,sizeof(s));
 memset(st,0,sizeof(st));
 for (int i = 1 ; i <= N ; i++){
 s[state[i].R]++ ;
 if (st[state[i].R]==0) st[state[i].R]=i ;
 ed[state[i].R] = i ;
 }
 int Q ;
 scanf("%d",&Q) ;
 int sum[10];
 sum[0] = 0 ;
 for (int i = 1 ; i <= 5 ; i++)
 sum[i] = sum[i-1] + s[i] ;
 while (Q--){
 for (int j = 0 ; j < 5 ; j++)
 scanf("%s",str[j]);
 card now ;
 for (int j = 0 ; j < 5 ; j++)
 b[j] = get(str[j][0]);
 now.insert(b);
 bool samesuit = true ;
 for (int j = 1 ; j < 5 ; j++)
 if (str[j][1] != str[0][1]) samesuit = false ;
 int rank = now.R ;
 int pos = search(st[rank],ed[rank],now) - st[rank] + 1;
 int Tonghua = s[1] ;
 if (!samesuit){
 if (rank <= 5){
 printf("%d\n",sum[rank-1] + pos) ;
 }
 else{
 if (rank == 6)
 printf("%d\n",sum[5] + Tonghua + pos);
 else
 printf("%d\n",sum[5] + Tonghua + s[6] + pos) ;
 }
 }else
 {
 if (rank == 5){
 printf("%d\n",sum[5] + Tonghua + s[6] + s[7] + pos) ;
 }
 else
 printf("%d\n",sum[5] + pos);
 }
 }
 return 0;
}
