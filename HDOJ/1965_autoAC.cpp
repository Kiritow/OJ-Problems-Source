#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define N 100
int P,n;
int matrix[N][N],ans[N];
char str[N];
void init()
{
    int i,j,k;
    for(i = 0; i < n; i++)
        if(str[i] == '*')
            matrix[i][n] = 0;
        else matrix[i][n] = str[i] - 'a' + 1;
    for(i = 0; i < n; i++)
    {
        k = 1;
        for(j = 0; j < n; j++)
        {
            matrix[i][j] = k;
            k = (k*(i+1))%P;
        }
    }
}
int find(int a, int y,int P=100000)
{
    int i;
    a = (a%P + P) % P; y = (y%P + P)%P;
    for(i = 0; i < P; i++)
        if((a*i)%P == y)
            return i;
}
void gauss(int P=100000)
{
    int i,j,k;
    int row,col;
    int a,b,c,sum;
    row = 0; col = 0;
    while(row < n && col < n)
    {
        for(i = row, j = -1; i < n; i++)
            if(matrix[i][col] != 0)
            {
                j = i; break;
            }
        for(i = col; i < n; i++)
        {
            k = matrix[row][i];
            matrix[row][i] = matrix[j][i];
            matrix[j][i] = k;
        }
        a = matrix[row][col];
        for(i = row+1; i < n; i++)
        {
            b = matrix[i][col];
            for(j = col; j <= n; j++)
                matrix[i][j] = (matrix[i][j]*a - matrix[row][j]*b)%P;
        }
        row++; col++;
    }
    for(i = n-1; i >= 0; i--)
    {
        sum = 0;
        for(j = i+1; j < n; j++)
            sum = (sum + matrix[i][j]*ans[j])%P;
        ans[i] = find(matrix[i][i],matrix[i][n]-sum,P);
    }
    for(i = 0; i < n; i++)
    {
        printf("%d",ans[i]);
        if(i == n-1) printf("\n");
        else printf(" ");
    }
}
int main()
{
    int i,j,k;
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d %s",&P,str);
        n = strlen(str);
        init();
        gauss(P);
    }
    return 0;
}
