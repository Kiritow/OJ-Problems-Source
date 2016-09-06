#include<string.h>
#include<stdio.h>
char ch[201];
int xue[3] , sta[201] , n , flag = 1; 
void init()
{
 int i; char t;
 scanf("%d\n", &n);
 for (i=1;i<=n;i++)
 {
 scanf("%c ", &ch[i]);
 sta[i] = 0;
 } 
 for (i=1;i<=4;i++) sta[i] = 1;
 for (i=5;i<=8;i++) sta[i] = 2;
 xue[1] = 3; xue[2] = 3;
}
int find_need(char now , int x)
{
 int i;
 for (i=1;i<=n;i++)
 if (ch[i] == now && sta[i] == x) return i;
 return 0;
}
int find(int x)
{
 int i;
 for (i=1;i<=n;i++)
 if (sta[i] == x) return i;
 return 0; 
}
void deal()
{
 int i , j , t , x , tail , m , now = 0;
 flag = 1; tail = 8; m = n;
 while (1)
 {
 now++;
 if (now > m+1) break;
 if (tail + 1 <= m) sta[tail+1] = flag;
 if (tail + 2 <= m) sta[tail+2] = flag;
 if (tail+2 <= m) tail = tail + 2; else tail = m;
 for (j=1;j<=n;j++)
 if (ch[j] == 'S' && sta[j] == flag)
 {
 sta[j] = 3;
 t = find_need('D' , 3-flag);
 if (t == 0) 
 {
 x = find(3-flag); 
 if (x == 0) continue;
 sta[x] = 3;
 n++; 
 sta[n] = flag;
 ch[n] = ch[x];
 }
 else sta[t] = 3;
 }
 for (j=1;j<=n;j++)
 if (ch[j] == 'K' && sta[j] == flag)
 {
 sta[j] = 3;
 t = find_need('E' , 3-flag);
 if (t == 0)
 {
 xue[3-flag] --;
 if (xue[3-flag] < 1) 
 {
 if (flag == 1) printf("The winner is the first.\n"); 
 else printf("The winner is the second.\n"); 
 return;
 }
 }
 else sta[t] = 3; 
 break; 
 }
 flag = 3-flag;
 }
 printf("Just a tie.\n");
}
int main()
{
 int i , tot;
 scanf("%d", &tot);
 for (i = 1; i<= tot;i++)
 {
 printf("Case %d: " , i); 
 init();
 deal(); 
 }
}
