#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
void solve(int &a,int &b,int &c,int l,string s)
{
    int i,j;
    a=0,b=1,c=0;
    for(i=0;i<l;i++){
        a=(a+(83-s[i])*(83-s[i]))%97;
        b=(b*s[i])%79;
        for(j=i+1;j<l;j++){
            c=(c+s[i]*s[j])%11;
        }
    }
    a=300-(a%97);
    b=22+(b%79);
    c=c%11;
}
int main()
{
    int t;
    string a,b;
    int ahp,bhp;
    int astr,bstr;
    int aspd,bspd;
    scanf("%d",&t);
    while(t--)
    {
        cin>>a>>b;
        ahp=bhp;
        astr=bstr;
        aspd=bspd;
        int al=a.length();
        int bl=b.length();
        solve(ahp,astr,aspd,al,a);
        solve(bhp,bstr,bspd,bl,b);
        int da,db;
        da=ahp/bstr;
        if(ahp%bstr!=0)
        {
            da++;
        }
        db=bhp/astr;
        if(bhp%astr!=0)
        {
            db++;
        }
        da *= (20-bspd);
        db *= (20-aspd);
        if(da==db){    
            printf("tie\n");
        }else if(da<db){
            printf("lose\n");
        }else{
            printf("win\n");
        }
    }
}
