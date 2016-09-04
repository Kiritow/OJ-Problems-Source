#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int m,n;
char digit[1500][1500];
void f(int row)
{
     int i,j,k;
     int len = strlen(digit[row]);
     for(i=0; i*(m+2)+i-1<len; i++)
     {
              if(i != 0)
              printf(" ");
              printf(" ");
              for(j=0; j<n; j++)
              if(digit[row][(m+2)*i+i+1] == '-')
              printf("-");
              else printf(" ");
              printf(" ");
              }
              printf("\n");
     }
void g(int row)
{
     int i,j,k;
     int len = strlen(digit[row]);
     for(i=0; i*(m+2)+i-1<len; i++)
     {
              if(i != 0)
              printf(" ");
              printf("%c", digit[row][(m+2)*i+i]);
              for(j=0; j<n; j++)
              printf(" ");
              printf("%c", digit[row][i*(m+2)+i+m+1]);
              }
              printf("\n");
     }
int main()
{
    int cases, t;
    int i,j,k;
    scanf("%d", &cases);
    t = 1;
    while(t <= cases)
    {
            scanf("%d %d", &m, &n);
            getchar();
            for(i=0; i<2*m+3; i++)
             gets(digit[i]);
            printf("Case %d:\n", t);
            f(0);
            for(i=0; i<n; i++)
            g(1);
            f(m+1);
            for(i=0; i<n; i++)
            g(m+2);
            f(2*m+2);
            t++;
            printf("\n");
            }   
    return 0;
}
