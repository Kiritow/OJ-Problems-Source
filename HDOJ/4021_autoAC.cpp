#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int a[24];
int b[24];
int c[24];
int d[24];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<24;i++)
           scanf("%d",&a[i]);
        for(int i=0;i<24;i++)
           scanf("%d",&b[i]);
        if(a[0]==0)swap(a[0],a[3]);
        if(a[1]==0)swap(a[1],a[6]);
        if(a[2]==0)swap(a[2],a[3]);
        if(a[7]==0)swap(a[7],a[6]);
        if(a[16]==0)swap(a[16],a[17]);
        if(a[21]==0)swap(a[20],a[21]);
        if(a[22]==0)swap(a[17],a[22]);
        if(a[23]==0)swap(a[20],a[23]);
        if(b[0]==0)swap(b[0],b[3]);
        if(b[1]==0)swap(b[1],b[6]);
        if(b[2]==0)swap(b[2],b[3]);
        if(b[7]==0)swap(b[7],b[6]);
        if(b[16]==0)swap(b[16],b[17]);
        if(b[21]==0)swap(b[20],b[21]);
        if(b[22]==0)swap(b[17],b[22]);
        if(b[23]==0)swap(b[20],b[23]);
        bool flag=true;
        if(a[0]!=b[0])flag=false;
        if(a[1]!=b[1])flag=false;
        if(a[2]!=b[2])flag=false;
        if(a[7]!=b[7])flag=false;
        if(a[16]!=b[16])flag=false;
        if(a[21]!=b[21])flag=false;
        if(a[22]!=b[22])flag=false;
        if(a[23]!=b[23])flag=false;
        if(flag==false)
        {
            printf("Y\n");
            continue;
        }
        for(int i=0;i<4;i++)
        {
            c[i]=a[i+3];
            d[i]=b[i+3];
        }
        for(int i=4;i<12;i++)
        {
            c[i]=a[i+4];
            d[i]=b[i+4];
        }
        for(int i=12;i<16;i++)
        {
            c[i]=a[i+5];
            d[i]=b[i+5];
        }
        int cnt1=0;
        int cnt2=0;
        int m1=0,m2=0;
        for(int i=1;i<16;i++)
        {
            if(c[i]==0)
            {
                m1=i;
                continue;
            }
            for(int j=0;j<i;j++)
            {
                if(c[i]<c[j])cnt1++;
            }
        }
        for(int i=1;i<16;i++)
        {
            if(d[i]==0)
            {
                m2=i;
                continue;
            }
            for(int j=0;j<i;j++)
            {
                if(d[i]<d[j])cnt2++;
            }
        }
        m1/=4;
        m2/=4;
        int m=abs(m1-m2);
        if(((cnt1+m)%2)!=(cnt2%2))flag=false;
        if(flag)printf("N\n");
        else printf("Y\n");
    }
    return 0;
}
