#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define NMAX 55
bool path[NMAX][NMAX];
int n,mmax;
int dp[NMAX];
bool v[NMAX];
int seq[NMAX], seq_pos;
bool dfs(int pos, int size)
{
    int i, j, unvis;
    bool tv[NMAX];
    unvis = 0;
    for (i=pos; i<n; i++)
    {
        if (!v[i])
        {
            unvis ++;
        }
    }
    if (unvis == 0)  
    {
        if (size > mmax)
        {
            mmax = size;
            seq_pos = 0;
            seq[ seq_pos ++] = pos+1;
            return true;
        }
        return false;
    }
    for (i=pos; i < n && unvis > 0 ; i++)
    {
        if (!v[i])
        {
            if (unvis + size <= mmax || dp[i] + size <= mmax)
            {
                return false;
            }
            v[i] = true;
            unvis --;
            memcpy(tv, v, sizeof(v));
            for (j=0; j<n; j++) //U N(vi);
            {
                if (!path[i][j])
                {
                    v[j] = true;
                }
            }
            if ( dfs(i, size+1) )
            {
                seq[ seq_pos ++] = pos+1;
                return true;
            }
            memcpy(v, tv, sizeof(v));
        }
    }
    return false;
}
int max_clique()
{
    int i,j;
    mmax = 0;
    for (i=0; i<n; i++)
    {
        path[i][i] = false;
    }
    for (i=n-1; i>=0; i--)
    {
        for (j=0; j<n; j++) 
        {
            v[j] = !path[i][j];
        }
        dfs(i, 1);
        dp[i] = mmax;
    }
    return mmax;
}
int main()
{
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d",&path[i][j]);
            }
        }
        printf("%d\n",max_clique());
    }
    return 0;
}
