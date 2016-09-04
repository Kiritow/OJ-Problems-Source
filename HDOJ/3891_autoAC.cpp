#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
using namespace std;
const long long P=112233;
typedef long long ll;
int n;
long long c[P*10],pro,p[20],s[20],a[P*10],inv[P*10];
void exgcd(ll a,ll b,ll &d,ll &x,ll &y){
 if ( b==0 ){
 d=a; x=1; y=0;
 }
 else{
 exgcd(b,a%b,d,x,y);
 ll t=x; x=y; y=t-(a/b)*y;
 }
}
void cnt(){
 long long d,x,y;
 for (int i=1;i<=1000001;i++){
 long long a=i;
 exgcd(a,P,d,x,y);
 inv[a]=x;
 }
}
void work(long long a,long long b,int k){
 for (int i=1;i<=4;i++){
 while ( a%p[i]==0 ){
 s[i]++;
 a/=p[i];
 }
 while ( b%p[i]==0 ){
 s[i]--;
 b/=p[i];
 }
 }
 pro=(pro*inv[b]*a)%P;
 c[k]=pro;
 for (int i=1;i<=4;i++)
 for (int j=1;j<=s[i];j++)
 c[k]=c[k]*p[i]%P;
}
int main(){
 cnt();
while ( scanf("%d",&n)!=EOF ){
 for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
 p[1]=3; p[2]=11; p[3]=19; p[4]=179;
 pro=1;
 memset(s,0,sizeof(s));
 c[0]=1;
 int e=1;
 for (int i=1;i<=n;i++)
 work(n-i+1,i,i);
 a[0]=0;
 for (int i=1;i<=n;i++){
 a[0]=(a[0]+c[i]*a[i]*e)%P;
 e=-e;
 }
 memset(s,0,sizeof(s));
 pro=1;
 e=1;
 for (int i=1;i<=n+1;i++)
 work(n-i+2,i,i);
 long long ans=0;
 for (int i=n;i>=0;i--){
 ans=(ans+c[i]*a[i]*e)%P;
 e=-e;
 }
 ans=(ans+P)%P;
 cout<<ans<<endl;
}
}
