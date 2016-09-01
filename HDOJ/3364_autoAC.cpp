#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
using namespace std ;
const int MAXN=55;
int a[MAXN][MAXN],b[MAXN][MAXN];
int x[MAXN];
bool free_x[MAXN];
/*
void Debug(void)
{
    int i, j;
    for (i = 0; i < equ; i++)
    {
        for (j = 0; j < var + 1; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
*/
inline int gcd(int a,int b)
{
    int t;
    while(b!=0)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}
inline int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}
int Gauss(int equ,int var)
{
    int i,j,k;
    int max_r;
    int col;
    int ta,tb;
    int LCM;
    int temp;
    int free_x_num;
    int free_index;
    for(int i=0;i<=var;i++)
    {
        x[i]=0;
        free_x[i]=true;
    } 
    col=0; 
    for(k = 0;k < equ && col < var;k++,col++)
    {
        max_r=k;
        for(i=k+1;i<equ;i++)
        {
            if(abs(a[i][col])>abs(a[max_r][col])) max_r=i;
        }
        if(max_r!=k)
        {
            for(j=k;j<var+1;j++) swap(a[k][j],a[max_r][j]);
        }
        if(a[k][col]==0)
        {
            k--;
            continue;
        }
        for(i=k+1;i<equ;i++)
        {
            if(a[i][col]!=0)
            {
                for(j=col;j<var+1;j++)
                {
                    a[i][j] ^= a[k][j];
                }
            }
        }
    }
    for (i = k; i < equ; i++)
    { 
        if (a[i][col] != 0) return -1;
    }
    if (k < var)
    {
        for (i = k - 1; i >= 0; i--)
        {
            free_x_num = 0; 
            for (j = 0; j < var; j++)
            {
                if (a[i][j] != 0 && free_x[j]) free_x_num++, free_index = j;
            }
            if (free_x_num > 1) continue;
            temp = a[i][var];
            for (j = 0; j < var; j++)
            {
                if (a[i][j] != 0 && j != free_index) temp -= a[i][j] * x[j];
            }
            x[free_index] = temp / a[i][free_index]; 
            free_x[free_index] = 0; 
        }
        return var - k; 
    }    
    for (i = var - 1; i >= 0; i--)
    {
        temp = a[i][var];
        for (j = i + 1; j < var; j++)
        {
            if (a[i][j] != 0) temp -= a[i][j] * x[j];
        }
        if (temp % a[i][i] != 0) return -2; 
        x[i] = temp / a[i][i];
    }
    return 0;
}
int main(void)
{
    int T ;
    scanf("%d",&T) ; 
    for(int cas=1 ;cas<=T ;cas++)
    {
        int equ,var ;
        scanf("%d%d",&equ,&var) ;
        memset(a,0,sizeof(a)) ;
        memset(b,0,sizeof(b)) ;
        for(int i=0 ;i<var ;i++)
        {
            int k ;
            scanf("%d",&k) ;
            for(int j=0 ;j<k ;j++)
            {
                int v ;
                scanf("%d",&v) ;
                b[v-1][i]=1 ;
            }
        }
        printf("Case %d:\n",cas) ;
        int q ;
        scanf("%d",&q) ;
        while(q--)
        {
            memcpy(a,b,sizeof(b)) ;
            for(int i=0 ;i<equ ;i++)
            {
                int v ;
                scanf("%d",&v) ;
                a[i][var]=v ;
            }
            int x=Gauss(equ,var) ;
            if(x<0)
            {
                puts("0") ;
                continue ;
            }
            printf("%I64d\n",1LL<<x) ;
        }
    }
    return 0;
}
