#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<complex>
#define N 50010
using namespace std;
const double pi=acos(-1);
const complex<double> I(0,1);
const double eps=1e-6;
char aa[N],bb[N];
int ans[4*N];
complex<double> a[4*N],b[4*N];
int n;
void initial()
{
    int lenA=strlen(aa),lenB=strlen(bb);
    n=max(lenA,lenB);
    double t=log2(n);
    int tt=int(t);
    if(t-tt>0)tt++;
    n=1<<(tt+1);
    int i;
    for(i=0; i<lenA; i++)a[i]=aa[lenA-1-i]-'0';
    while(i<n)a[i++]=0;
    for(i=0; i<lenB; i++)b[i]=bb[lenB-1-i]-'0';
    while(i<n)b[i++]=0;
}
void bitReverse(complex<double> * a)
{
    for(int i=1; i<n-1; i++)
    {
        int j=0;
        for(int k=1,tmp=i; k<n; j=((j<<1)|(tmp&1)),k<<=1,tmp>>=1);
        if(j>i)swap(a[i],a[j]);
    }
}
void iterative_FFT(complex<double> *a,int sig)
{
    bitReverse(a);
    for(int m=2; m<=n; m<<=1)
    {
        int mh =m>>1;
        for(int i=0; i<mh; i++)
        {
            complex<double> wi=exp(i*sig*pi/mh*I);
            for(int j=i; j<n; j+=m)
            {
                int k=j+mh;
                complex<double> u=a[j],t=wi*a[k];;
                a[j]=u+t;
                a[k]=u-t;
            }
        }
    }
    if(sig==-1)for(int i=0; i<n; i++)a[i]/=n;
}
void convolution()
{
    iterative_FFT(a,1);
    iterative_FFT(b,1);
    for(int i=0; i<n; i++)a[i]*=b[i];
    iterative_FFT(a,-1);
}
void output()
{
    int k=0;
    ans[0]=0;
    for(int i=0; i<n; i++)
    {
        int tmp=a[i].real()+eps;
        ans[i]+=tmp;
        if(ans[i])k=i,ans[i+1]=ans[i]/10,ans[i]%=10;
        else ans[i+1]=0;
    }
    while(k>=0)cout<<ans[k--];
    cout<<endl;
}
int main()
{
    while(~scanf("%s%s",aa,bb))
    {
        initial();
        convolution();
        output();
    }
    return 0;
}
