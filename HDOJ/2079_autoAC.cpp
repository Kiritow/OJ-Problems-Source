#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int c1[700],c2[700];
int a[10],b[10];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas = 1;cas <= T;cas++)
    {
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        int n,kk;
        scanf("%d%d",&n,&kk);
        int i,j,k;
        for(i = 1;i <= kk;i++){
            scanf("%d%d",&a[i],&b[i]);
        }
        for(i = 0;i <= a[1]*b[1]&&i<=n;i+=a[1]){
            c1[i] = 1;
        }
        for(i = 2;i <= kk;i++){
            for(j = 0;j <= n;j++){
                for(k = 0;k<=a[i]*b[i]&&k<=n;k+=a[i]){
                    c2[k+j] += c1[j];
                }
            }
            for(j = 0;j <= n;j++){
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        printf("%d\n",c1[n]);
    }
    return 0;
}
