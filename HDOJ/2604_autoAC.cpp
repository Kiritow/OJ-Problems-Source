#include <stdio.h>
#include <string.h>
#define ll long long
#define Max 4  
int mod;
struct Matrix
{
      int  mm[Max][Max];
}A,I;
Matrix matrixmul(Matrix a,Matrix b) 
{
       int i,j,k;
       Matrix c;
       for (i = 0 ; i <= 3; i++)
           for (j = 0; j <= 3;j++)
             {
                 c.mm[i][j] = 0;
                 for (k = 0; k <= 3; k++)
                     c.mm[i][j] += (a.mm[i][k] * b.mm[k][j])%mod;
                  c.mm[i][j]%=mod;
             }
       return c;
}
Matrix quickpagow(int n)
{
       Matrix m = A, b = I;
       while (n >= 1)
       {
             if (n & 1)
                b = matrixmul(b,m);
             n = n >> 1;
             m = matrixmul(m,m);
       }
       return b;
}
int main ()
{
    int n;
    A.mm[0][0]=1,A.mm[0][1]=0,A.mm[0][2]=1,A.mm[0][3]=1;
    A.mm[1][0]=1,A.mm[1][1]=0,A.mm[1][2]=0,A.mm[1][3]=0;
    A.mm[2][0]=0,A.mm[2][1]=1,A.mm[2][2]=0,A.mm[2][3]=0;
    A.mm[3][0]=0,A.mm[3][1]=0,A.mm[3][2]=1,A.mm[3][3]=0;
    I.mm[0][0]=1,I.mm[0][1]=0,I.mm[0][2]=0,I.mm[0][3]=0;
    I.mm[1][0]=0,I.mm[1][1]=1,I.mm[1][2]=0,I.mm[1][3]=0;
    I.mm[2][0]=0,I.mm[2][1]=0,I.mm[2][2]=1,I.mm[2][3]=0;
    I.mm[3][0]=0,I.mm[3][1]=0,I.mm[3][2]=0,I.mm[3][3]=1;
    while(scanf("%d %d",&n,&mod)!=EOF)
    {
        if(n==1)
            printf("%d\n",2%mod);
        else if(n==2)
            printf("%d\n",4%mod);
        else if(n==3)
            printf("%d\n",6%mod);
        else if(n==4)
            printf("%d\n",9%mod);
        else
        {
            Matrix c=quickpagow(n-4);
            printf("%d\n",((c.mm[0][0]*9)%mod+(c.mm[0][1]*6)%mod+(c.mm[0][2]*4)%mod+(c.mm[0][3]*2)%mod)%mod);
        }
    }
    return 0;
}
