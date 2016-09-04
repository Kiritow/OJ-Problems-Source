#include<cstdio>
#include<cstring>
#define ll __int64
ll M=19880502ll,A[6],B[6][9999];
int n,v[9999];
ll gcd(ll a,ll b)
{
 if(!b)return a;
 return gcd(b,a%b);
}
ll egcd(ll a,ll b,ll &x,ll &y)
{
 if(!b){x=1;y=0;return a;}
 ll d=egcd(b,a%b,x,y),t=x;
 x=y;
 y=t-a/b*y;
 return d;
}
ll Pow(ll a,ll b)
{
 ll r=1;
 while(b)
 {
 if(b&1)r=r*a%M;
 a=a*a%M;
 b>>=1;
 }
 return r;
}
ll sol(int k)
{
 ll x,y,t=B[0][k],m=A[0];
 for(int i=1;i<n;i++)
 {
 ll d=egcd(m,A[i],x,y),tp=B[i][k]-t;
 if(tp%d!=0)return -1;
 x=tp/d*x%A[i];
 if(x<0)x+=A[i];
 t=x*m+t;
 m=m/gcd(m,A[i])*A[i];
 }
 return t%m;
}
int main()
{
 while(~scanf("%d",&n))
 {
 memset(v,0,sizeof(v));
 memset(B,0,sizeof(B));
 for(int i=0;i<n;i++)
 {
 scanf("%I64d",A+i);
 ll tp=A[i];
 for(ll k=2;k*k<=tp;++k)
 if(tp%k==0)
 {
 v[k]=1;
 while(tp%k==0)
 {
 ++B[i][k];
 tp/=k;
 }
 }
 if(tp>1){v[tp]=1;B[i][tp]=1;}
 }
 ll res=1;
 for(int i=2;i<9998;i++)
 if(v[i])
 {
 ll t=sol(i);
 if(!~t){res=-1;break;}
 res=res*Pow((ll)i,t)%M;
 }
 printf("%I64d\n",res);
 }
}
