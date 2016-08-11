#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define MAXN 100005
int A[MAXN];
int main()
{
    int t;
    scanf("%d",&t);
    for(int ii=0;ii<t;ii++)
    {
        int n;
        scanf("%d",&n);
        int inMAX;
        int inMAXpos=0;
        scanf("%d",&inMAX);
        A[0]=inMAX;
        for(int i=1;i<n;i++)
        {
            scanf("%d",&A[i]);
            if(A[i]>inMAX)
            {
                inMAX=A[i];
                inMAXpos=i;
            }
        }
        if(inMAX<0)
        {
            printf("Case %d:\n%d %d %d\n",ii+1,inMAX,inMAXpos+1,inMAXpos+1);
            if(t-ii>1) printf("\n");
            continue;
        }
        int sum=A[0];
        int L=0;
        int R=0;
        int maxsum=0;
        int maxL=0;
        int maxR=0;
        for(int i=1;i<n;i++)
        {
            if(sum>=0)
            {
                sum+=A[i];
                if(A[i]>0) R=i;
            }
            else
            {
                sum=A[i];
                L=R=i;
            }
            if(sum>maxsum)
            {
                maxsum=sum;
                maxL=L;
                maxR=R;
            }
        }
        printf("Case %d:\n%d %d %d\n",ii+1,maxsum,maxL+1,maxR+1);
        if(t-ii>1) printf("\n");
    }
    return 0;
}
