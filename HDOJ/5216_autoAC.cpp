#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100010;
int N,M;
int A[maxn],B[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M);
        for(int i=1;i<=M;i++)scanf("%d",&A[i]);
        for(int i=1;i<=M;i++)scanf("%d",&B[i]);
        sort(A+1,A+1+M);
        sort(B+1,B+1+M);
        bool flag=true;
        for(int i=1;i<=M;i++)
            if(A[i]>B[i]){flag=false;break;}
        if(!flag){printf("Stupid BrotherK!\n");}
        else
        {
            int ans=max(A[1]-1,N-B[M]);
            int last=0;
            for(int i=1;i<=M;i++)
            {
                if(A[i]>last)
                {
                    ans=max(ans,A[i]-last-1);
                }
                last=B[i];
            }
            printf("%.6lf\n",double(ans));
        }
    }
    return 0;
}
