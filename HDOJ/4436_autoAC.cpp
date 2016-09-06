#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#define maxn 300000
#define MOD 2012
using namespace std;
int wa[maxn],wb[maxn],wv[maxn];
int ran[maxn],height[maxn],wS[maxn],sa[maxn],P[maxn],Pow[maxn],V[maxn],
T[maxn],Len[maxn],S[maxn],arrive[maxn],n,len,value;
char s[maxn];
int cmp(int *r,int a,int b,int l) {return r[a]==r[b]&&r[a+l]==r[b+l];}
void da(int *r,int *sa,int n,int m)
{
     int i,j,p,*x=wa,*y=wb,*t;
     for(i=0;i<m;i++) wS[i]=0;
     for(i=0;i<n;i++) wS[x[i]=r[i]]++;
     for(i=1;i<m;i++) wS[i]+=wS[i-1];
     for(i=n-1;i>=0;i--) sa[--wS[x[i]]]=i;
     for(j=1,p=1;p<n;j*=2,m=p)
     {
         for(p=0,i=n-j;i<n;i++) y[p++]=i;
         for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
         for(i=0;i<n;i++) wv[i]=x[y[i]];
         for(i=0;i<m;i++) wS[i]=0;
         for(i=0;i<n;i++) wS[wv[i]]++;
         for(i=1;i<m;i++) wS[i]+=wS[i-1];
         for(i=n-1;i>=0;i--) sa[--wS[wv[i]]]=y[i];
         for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
         x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
     }
     return;
}
void calheight(int *r,int *sa,int n)
{
     int i,j,k=0;
     for(i=0;i<n;i++) ran[sa[i]]=i;
     for(i=0;i<n;height[ran[i++]]=k)
     if(ran[i])for(k?k--:0,j=sa[ran[i]-1];r[i+k]==r[j+k];k++);
     return;
}
int  get(int l,int r)
{
     if(l>r) return 0;
     int ans=(T[r+1]-T[l])%MOD;
     ans-=V[l]*(Pow[r-l+1]);
     ans%=MOD;
     if (ans<0) ans+=MOD;
     return ans;
}
int main()
{
    Pow[0]=1;Pow[1]=10;
    for (int i=2;i<200000;++i) 
        Pow[i]=(Pow[i-1]+1)*10%MOD;
    while (scanf("%d",&n)!=EOF)
    {     
          len = 0; value = 0;
          for (int i=0;i < n ;++i){
              scanf("%s",s);
              Len[i]= strlen(s);
              for (int j = 0 ; j < Len[i]; ++j){
                  S[len]=s[j]-'0'+1;
                  value = (value*10+S[len]-1)%MOD;
                  V[len+1]=value;
                  T[len+1]=(T[len]+value)%MOD;
                  P[len]=i;
                  len++;
              }
                  S[len]=11;
                  value = (value*10+10)%MOD;
                  V[len+1]=value;
                  T[len+1]=(T[len]+value)%MOD;
                  P[len]=i;
                  len++;
                  arrive[i]=len-2;
          }
          S[len-1]=0;
          da(S,sa,len,12);
          calheight(S,sa,len);
          int ans = 0;
          for (int  i = 0;i < len;++i)
          if (S[i]%10 !=1){
              if (i+height[ran[i]]<= arrive[P[i]]){
               ans+=get(i,arrive[P[i]])-get(i,i+height[ran[i]]-1); 
               ans%=MOD;if (ans<0) ans+=MOD;           
               }
          }
          cout << ans << endl;
    }
    return 0;
}
