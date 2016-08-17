#include <iostream>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;
#define SIZE 310
int a[5][SIZE],n[5],b[SIZE*SIZE],c[SIZE*SIZE];
int main()
{
    int t,i,j,len1,len2,len3,k,p1,p2,carry,flg;
    __int64 ans;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<5;i++)
        {
            scanf("%d",&n[i]);
            for(j=0;j<n[i];j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        len1=0,len2=0,len3=n[4];
        for(i=0;i<n[0];i++)
        {
            for(j=0;j<n[1];j++)
            {
                b[len1++]=a[0][i]+a[1][j];
            }
        }
        for(i=0;i<n[2];i++)
        {
            for(j=0;j<n[3];j++)
            {
                c[len2++]=a[2][i]+a[3][j];
            }
        }
        ans=0;
        sort(b,b+len1);
        sort(c,c+len2);
        for(i=0;i<len3;i++)
        {
            carry=len2-1;
            for(j=0;j<len1 && carry >= 0;j++)
            {
                while(a[4][i]+b[j]+c[carry]>0)
                {
                    carry--;
                }
                if(a[4][i]+b[j]+c[carry] == 0)
                {
                    p1=p2=1;
                    while(j<len1-1 && b[j] == b[j+1])
                    {
                        j++;
                        p1++;
                    }
                    while(carry>0 && c[carry] == c[carry-1])
                    {
                        carry--;
                        p2++;
                    }
                    ans+=p1*p2;
                }
            }
        }
        printf("%I64d\n",ans%1000000007);
    }
    return 0;
}
