#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <sstream>
#include <queue>
#include <vector>
#define MAXN 1111111
#define MAXM 211111
#define PI acos(-1.0)
#define eps 1e-8
#define INF 1e10
using namespace std;
int A[MAXN], B[MAXN];
char sa[MAXN];
void preExKmp(char x[],int m,int A[]){
    int ind=0,k=1;
    A[0]=m;
    while (ind + 1 < m && x[ind+1]==x[ind]) ++ind;
    A[1]=ind;
    for (int i=2;i<m;++i){
        if (i<=k+A[k]-1 && A[i-k]+i<k+A[k])
            A[i]=A[i-k];
        else{
            ind=max(0,k+A[k]-i);
            while (ind + i < m && x[ind+i]==x[ind]) ++ind;
            A[i]=ind,k=i;
        }
    }
}
void exKmp(char x[],int m , char y[],int n,int A[],int B[]){
    preExKmp(x,m,A);
    int ind=0,k=0;
    while (ind<n && ind<m && x[ind]==y[ind]) ind++;
    B[0]=ind;
    for (int i=1;i<n;++i){
        if (i < k+B[k]-1 && A[i-k]+i<k+B[k])
            B[i]=A[i-k];
        else{
            ind = max(0,k+B[k]-i);
            while (ind +i<n && ind<m && y[ind+i]==x[ind]) ++ind;
            B[i]=ind;k=i;
        }
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%s", sa);
        int len = strlen(sa);
        preExKmp(sa, len, A);
        int ans = 0;
        int lst = len - len / 3, mxlen;
        for(int i = 0; i < len; i++)
        {
            mxlen = min(i, A[i]);
            mxlen = min(mxlen, (len - i) / 2);
            ans = max(ans, mxlen);
        }
        int res = 0;
        for(int i = lst; i < len; i++)
        {
            if(A[i] + i != len) continue;
            if(ans >= A[i])
            {
                res = A[i];
                break;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
