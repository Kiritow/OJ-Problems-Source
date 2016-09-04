#include<iostream>  
#include<cstdio>  
#include<string.h>  
using namespace std;  
const int base=10000;  
const int width=4;  
const int N=1300;  
char s[1000];  
struct bint  
{  
    int ln,v[N];  
    bint(int r=0)  
    {  
        for(ln=0;r>0;r/=base)  
            v[ln++]=r%base;  
    }  
    bint operator = (const bint& r)  
    {  
        memcpy(this,&r,(r.ln+1)*sizeof(int));  
    }  
};  
bool operator < (const bint& a,const bint& b)  
{  
    int i;  
    if(a.ln!=b.ln) return a.ln<b.ln;  
    for(i=a.ln-1;i>=0&&a.v[i]==b.v[i];i--);  
    return i<0?0:a.v[i]<b.v[i];  
}  
bool operator <= (const bint& a,const bint& b)  
{  
    return !(b<a);  
}  
bint operator + (const bint& a,const bint& b)  
{  
    bint res;  
    int i,cy=0;  
    for(i=0;i<a.ln||i<b.ln||cy>0;i++)  
    {  
        if(i<a.ln) cy+=a.v[i];  
        if(i<b.ln) cy+=b.v[i];  
        res.v[i]=cy%base;cy/=base;  
    }  
    res.ln=i;  
    return res;  
}  
bint operator - (const bint &a,const bint &b)  
{  
    bint res;int i,cy=0;  
    for(res.ln=a.ln,i=0;i<res.ln;i++)  
    {  
        res.v[i]=a.v[i]-cy;  
        if(i<b.ln) res.v[i]-=b.v[i];  
        if(res.v[i]<0) cy=1,res.v[i]+=base;  
        else cy=0;  
    }  
    while(res.ln>0&&res.v[res.ln-1]==0) res.ln--;  
    return res;  
}  
bint operator * (const bint& a,const bint& b)  
{  
    bint res;res.ln=0;  
    if(0==b.ln){  
        res.v[0]=0;return res;  
    }  
    int i,j,cy;  
    for(i=0;i<a.ln;i++)  
        for(j=cy=0;j<b.ln||cy>0;j++,cy/=base)  
        {  
            if(j<b.ln) cy+=a.v[i]*b.v[j];  
            if(i+j<res.ln) cy+=res.v[i+j];  
            if(i+j>=res.ln) res.v[res.ln++]=cy%base;  
            else res.v[i+j]=cy%base;  
        }  
    return res;  
}  
bint operator / (const bint& a,const bint& b)  
{  
    bint tmp,mod,res;  
    int i,lf,rg,mid;  
    mod.v[0]=mod.ln=0;  
    for(i=a.ln-1;i>=0;i--)  
    {  
        mod=mod*base+a.v[i];  
        for(lf=0,rg=base-1;lf<rg;)  
        {  
            mid=(lf+rg+1)/2;  
            if(b*mid<=mod) lf=mid;  
            else rg=mid-1;  
        }  
        res.v[i]=lf;  
        mod=mod-b*lf;  
    }  
    res.ln=a.ln;  
    while(res.ln>0&&res.v[res.ln-1]==0) res.ln--;  
    return res;  
}  
void write(const bint& v)  
{  
    int i,len;  
    sprintf(s,"%d",v.ln==0?0:v.v[v.ln-1]);  
    len=strlen(s);  
    for(i=v.ln-2;i>=0;i--)  
    {  
        sprintf(s+len,"%04d",v.v[i]);  
        len=strlen(s);  
    }  
    sprintf(s+len,"\0");  
}  
int main()  
{  
    bint ans,a=24,b=17,c=6;  
    int t,cas=1;  
    cin>>t;  
    while(t--)  
    {  
        int m;  
        cin>>m;  
        bint n=m;  
        ans=(b*n*n*n*n+c*n*n+n*n*n*n*n*n*n*n)/a;  
        write(ans);  
        cout<<"Case "<<cas++<<": ";  
        if(strlen(s)>15)  
            cout<<s+strlen(s)-15<<endl;  
        else  
            cout<<s<<endl;  
    }  
}
