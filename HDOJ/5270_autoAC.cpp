#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#define cl(a,b) memset(a,b,sizeof(a))
#define ll long long
#define ull unsigned long long
using namespace std;
#define maxn 200005
ull aa[maxn],bb[maxn];
ull taa[maxn],tbb[maxn];
ull cc[64],be[64],en[64];
int n;
void initcc()
{
    cl(cc,0);
    cc[0]=1;
    be[0]=1;
    en[0]=2;
    for(int i=1;i<=62;i++)
    {
        cc[i]=cc[i-1]*2+1;
        be[i]=be[i-1]*2;
        en[i]=en[i-1]*2;
    }
}
int main()
{
    initcc();
    int tt,ii;
    cin>>tt;
    ii=0;
    while(tt--)
    {
        scanf("%d",&n);
        int i,j,k;
        for(i=0;i<n;i++)scanf("%llu",&aa[i]);
        for(i=0;i<n;i++)scanf("%llu",&bb[i]);
        ull res=0,bitc;
        int s1,s2,e1,e2;
        for(k=0;k<62;k++)
        {
            for(i=0;i<n;i++)
            {
                taa[i]=aa[i]&cc[k];
                tbb[i]=bb[i]&cc[k];
            }
            sort(taa,taa+n);
            sort(tbb,tbb+n);
            s1=n-1;e1=n-1;bitc=0;
            s2=n-1;e2=n-1;
            for(i=0;i<n;i++)
            {
                while(s1>=0&&tbb[s1]+taa[i]>=be[k])s1--;
                while(e1>=0&&tbb[e1]+taa[i]>=en[k])e1--;
                while(s2>=0&&tbb[s2]+taa[i]>=be[k]+en[k])s2--;
                while(e2>=0&&tbb[e2]+taa[i]>=en[k+1])e2--;
                bitc+=e1-s1;
                bitc+=e2-s2;
            }
            res+=be[k]*(bitc%2);
        }
        printf("Case #%d: %llu\n",++ii,res);
    }
    return 0;
}
