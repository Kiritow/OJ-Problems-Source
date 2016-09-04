#include<iostream>  
#include<cstdio>  
#include<string.h>  
using namespace std;  
const int base=10000;  
const int width=4;  
const int N=1300;  
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
void write(const bint& v)  
{  
    int i;  
    printf("%d",v.ln==0?0:v.v[v.ln-1]);  
    for(i=v.ln-2;i>=0;i--)  
        printf("%04d",v.v[i]);  
    printf("\n");  
}  
char buf[10];  
bint b[10];  
struct o  
{  
    int a,b,o;
}o[400000];  
bool flag[10],cal[400000];  
int main()  
{  
    for(int i=0;i<10;i++) b[i]=1;  
    int i=0;  
    while(scanf("%s",buf)!=EOF&&buf[0]!='#')  
    {  
        o[i].a=buf[0]-'A';  
        if(buf[1]=='+') o[i].o=0,o[i].b=buf[3]-'A';  
        else if(buf[1]=='*') o[i].o=1,o[i].b=buf[3]-'A';  
        else o[i].o=2,o[i].b=buf[2]-'A';  
        i++;  
    }  
    for(int j=0;j<10;j++) flag[j]=true;  
    for(int j=i-1;j>=0;j--)  
    {  
        cal[j]=flag[o[j].a];  
        if(o[j].o==2)  
            flag[o[j].a]=false,flag[o[j].b]=true;  
    }  
    for(int j=0;j<i;j++)  
    {  
        if(cal[j])  
        {  
            if(o[j].o==0) b[o[j].a]=b[o[j].a]+b[o[j].b];  
            else if(o[j].o==1) b[o[j].a]=b[o[j].a]*b[o[j].b];  
            else b[o[j].a]=b[o[j].b];  
        }  
    }  
    for(int i=0;i<10;i++)  
        write(b[i]);  
    return 0;  
}
