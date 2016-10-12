#include <cstdio>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;
LL dpyes[25][15],dpno[25][15],ttime[25],num[25],top=0;
int judge(LL l,LL r)
{
    for (int i=r; i>=l; i--)
    {
        if (num[i]&1)//odd
        {
            LL tt=1;
            while (i-1>=l&&(num[i-1]&1))i--,tt++;
            if (i!=l&&tt%2==1) return false;
        }
        else
        {
            LL tt=1;
            while (i-1>=l&&!(num[i-1]&1))i--,tt++;
            if (i!=l&&tt%2==0) return false;
        }
    }
    return true;
}
LL cal(LL x)
{
    LL res=0;
    top=0;
    while (x)
    {
        num[++top]=x%10;
        x/=10;
    }
    for (int i=1; i<num[top]; i++) res+=dpyes[top][i];
    for (int i=1; i<top; i++)
    {
        for (int j=1; j<=9; j++)
        {
            res+=dpyes[i][j];
        }
    }
// cout<<res<<endl;
    for (int i=top-1; i>0; i--)
    {
        if (!judge(i+1,top)) break;
        int hh=1,ti=i+1;
        while (ti+1<=top&&(num[ti+1]%2==num[ti]%2))ti++,hh++;
        if (num[i+1]&1)//odd
        {
            if (hh&1)//odd
            {
                for (int j=1; j<num[i];j+=2)
                {
                    res+=dpno[i][j];
                }
            }
            else
            {
                for (int j=0;j<num[i];j++)
                {
                    res+=dpyes[i][j];
                }
            }
        }
        else
        {
            if (hh&1)//odd
            {
                for (int j=1;j<num[i];j+=2)
                {
                    res+=dpyes[i][j];
                }
                for (int j=0;j<num[i];j+=2)
                {
                    res+=dpno[i][j];
                }
            }
            else
            {
                for (int j=0; j<num[i];j+=2)
                {
                    res+=dpyes[i][j];
                }
            }
        }
    }
    return res;
}
int main()
{
    ttime[0]=1;
    for (int i=1; i<=20; i++) ttime[i]=5*ttime[i-1];
    dpyes[0][1]=dpyes[0][0]=1;
    dpyes[1][0]=dpyes[1][2]=dpyes[1][4]=dpyes[1][6]=dpyes[1][8]=1;
    dpno[1][1]=dpno[1][3]=dpno[1][5]=dpno[1][7]=dpno[1][9]=1;
    for (int i=2; i<=20; i++)
    {
        for (int j=0; j<10; j++)
        {
            if (j&1)//odd
            {
                for (int k=2; k<=i; k+=2)
                {
                    dpyes[i][j]+=dpyes[i-k][0]*ttime[k-1];
                    dpyes[i][j]+=dpyes[i-k][2]*ttime[k-1];
                    dpyes[i][j]+=dpyes[i-k][4]*ttime[k-1];
                    dpyes[i][j]+=dpyes[i-k][6]*ttime[k-1];
                    dpyes[i][j]+=dpyes[i-k][8]*ttime[k-1];
                }
                for (int k=1; k<=i; k+=2)
                {
                    dpno[i][j]+=dpyes[i-k][0]*ttime[k-1];
                    dpno[i][j]+=dpyes[i-k][2]*ttime[k-1];
                    dpno[i][j]+=dpyes[i-k][4]*ttime[k-1];
                    dpno[i][j]+=dpyes[i-k][6]*ttime[k-1];
                    dpno[i][j]+=dpyes[i-k][8]*ttime[k-1];
                }
            }
            else
            {
                for (int k=1; k<=i; k+=2)
                {
                    dpyes[i][j]+=dpyes[i-k][1]*ttime[k-1];
                    dpyes[i][j]+=dpyes[i-k][3]*ttime[k-1];
                    dpyes[i][j]+=dpyes[i-k][5]*ttime[k-1];
                    dpyes[i][j]+=dpyes[i-k][7]*ttime[k-1];
                    dpyes[i][j]+=dpyes[i-k][9]*ttime[k-1];
                }
                for (int k=2; k<=i; k+=2)
                {
                    dpno[i][j]+=dpyes[i-k][1]*ttime[k-1];
                    dpno[i][j]+=dpyes[i-k][3]*ttime[k-1];
                    dpno[i][j]+=dpyes[i-k][5]*ttime[k-1];
                    dpno[i][j]+=dpyes[i-k][7]*ttime[k-1];
                    dpno[i][j]+=dpyes[i-k][9]*ttime[k-1];
                }
            }
        }
    }
    int T,ncas=1;
    scanf ("%d",&T);
    while (T--)
    {
        LL l,r;
        scanf ("%lld%lld",&l,&r);
//        cout<<cal(l+1)<<endl;
        printf ("Case #%d: %lld\n",ncas++,cal(r+1)-cal(l));
    }
    return 0;
}
