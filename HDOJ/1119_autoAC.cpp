#include <iostream>
#include <string.h>
#include <stdio.h>
#define max(x,y) ((x)>(y)?(x):(y))
using namespace std;
char s1[510],s2[510],s[1010];
int t;
void Add(int A[],int a,int B[],int b,int C[],int &c)
{
    int i,j,k,*p,*q;
    if(a<b)
        k=a,a=b,b=k,p=B,q=A;
    else p=A,q=B;
    for(C[0]=0,c=a,i=1;i<=a;i++) C[i]=p[i];
    for(i=a,j=b;j>=1;j--,i--) C[i]+=q[j];
    for(i=a;i>=0;i--)C[i-1]+=C[i]/10,C[i]%=10;
    if(C[0]) for(c++,i=c;i>=1;i--) C[i]=C[i-1];
    for(i=1;!C[i]&&i<=c;i++);
    k=i,c-=i-1;
    for(i=1;i<=c;i++) C[i]=C[k+i-1];
    if(c<=0) c=1,C[1]=0;
}
void add()
{
    int A[510],a,B[510],b,C[510],c,i;
    a=strlen(s1);
    for(i=0;i<a;i++) A[i+1]=s1[i]-'0';
    b=strlen(s2);
    for(i=0;i<b;i++) B[i+1]=s2[i]-'0';
    Add(A,a,B,b,C,c);
    int t=max(a,max(b+1,c));
    for(i=1;i<=t-a;i++) putchar(' ');puts(s1);
    for(i=1;i<=t-(b+1);i++) putchar(' ');putchar('+');puts(s2);
    for(i=1;i<=t;i++) putchar('-');puts("");
    for(i=1;i<=t-c;i++) putchar(' ');
    for(i=1;i<=c;i++) printf("%d",C[i]);puts("");
}
void Sub(int A[],int a,int B[],int b,int C[],int &c)
{
    int i,j,k,flag,*p,*q;
    if(a==b)
    {
        flag=0;
        for(i=1;i<=a;i++)
        {
            if(A[i]>B[i])flag=1;
            if(A[i]<B[i])flag=-1;
            if(flag) break;
        }
    }
    if(a>b) flag=1;
    if(a<b) flag=-1;
    if(!flag)
    {
        C[0]=0,c=1;C[1]=0;
        return;
    }
    if(flag==1)
        p=A,q=B;
    else p=B,q=A,k=a,a=b,b=k;
    for(i=1;i<=a;i++) C[i]=p[i];
    for(i=a,j=b;j>=1;j--,i--)
    {
        if(C[i]>=q[j])
            C[i]-=q[j];
        else C[i]=C[i]+10-q[j],C[i-1]--;
    }
    for(;i>=1&&C[i]<0;i--) C[i]+=10,C[i-1]--;
    for(i=1;!C[i]&&i<=a;i++);
    k=i,c=a-i+1;
    for(i=1;i<=c;i++) C[i]=C[k+i-1];
    C[0]=flag;
}
void sub()
{
    int A[510],a,B[510],b,C[510],c,i;
    a=strlen(s1);
    for(i=0;i<a;i++) A[i+1]=s1[i]-'0';
    b=strlen(s2);
    for(i=0;i<b;i++) B[i+1]=s2[i]-'0';
    Sub(A,a,B,b,C,c);
    int t=max(a,max(b+1,c));
    for(i=1;i<=t-a;i++) putchar(' ');puts(s1);
    for(i=1;i<=t-(b+1);i++) putchar(' ');putchar('-');puts(s2);
    for(i=1;i<=t-max(b+1,c);i++) putchar(' ');
    for(i=1;i<=max(b+1,c);i++) putchar('-');puts("");
    for(i=1;i<=t-c;i++) putchar(' ');
    for(i=1;i<=c;i++) printf("%d",C[i]);puts("");
}
void Mul(int A[],int a,int B[],int b,int C[],int &c)
{
    int i,j,k;
    for(i=0;i<=a+b;i++) C[i]=0;
    for(i=a;i>=1;i--)
        for(j=b;j>=1;j--)
            C[i+j]+=A[i]*B[j];
    for(i=a+b;i>1;i--)C[i-1]+=C[i]/10,C[i]%=10;
    for(i=0;!C[i]&&i<=a+b;i++);
    k=i,c=a+b-i+1;
    for(i=1;i<=c;i++) C[i]=C[k+i-1];
    if(c<=0) c=1,C[1]=0;
}
int C[510][1010];
void mul()
{
    int A[510],a,B[510],b,ans[1010],x,c[510],temp,i,j,t=0,k;
    a=strlen(s1);
    for(i=0;i<a;i++) A[i+1]=s1[i]-'0';
    b=1;
    temp=strlen(s2);
    for(i=0;i<temp;i++) 
    {
        B[1]=s2[i]-'0';
        Mul(A,a,B,b,C[i],c[i]);
        t=max(t,temp-1-i+c[i]);
    }
    k=t;
    t=max(t,max(a,temp+1));
    for(i=0;i<temp;i++) B[i+1]=s2[i]-'0';
    Mul(A,a,B,temp,ans,x);
    t=max(t,x);
    for(i=1;i<=t-a;i++) putchar(' ');puts(s1);
    for(i=1;i<=t-(temp+1);i++) putchar(' ');putchar('*');puts(s2);
    if(temp==1)
    {
        for(i=1;i<=t-max(k,temp+1);i++) putchar(' ');
        for(i=1;i<=max(k,temp+1);i++) putchar('-');puts("");
    }
    else
    {
        for(i=1;i<=t-max(c[temp-1],temp+1);i++) putchar(' ');
        for(i=1;i<=max(c[temp-1],temp+1);i++) putchar('-');puts("");
    }
    for(i=temp-1;i>=0;i--)
    {
        for(j=1;j<=t-(temp-1-i+c[i]);j++) putchar(' ');
        for(j=1;j<=c[i];j++) printf("%d",C[i][j]);puts("");
    }
    if(temp>1)
    {
        for(i=1;i<=t-max(k,x);i++) putchar(' ');
        for(i=1;i<=max(k,x);i++) putchar('-');puts("");
        for(i=1;i<=t-x;i++) putchar(' ');
        for(i=1;i<=x;i++) printf("%d",ans[i]);puts("");
    }
}
int main()
{
    for(scanf("%d",&t);t--;)
    {
        scanf("%s",s);
        int i,len=strlen(s);
        for(i=0;i<len;i++) if(s[i]=='+'||s[i]=='-'||s[i]=='*') break;
        char c=s[i];
        s[i]='\0';
        strcpy(s1,s);
        strcpy(s2,s+i+1);
        if(c=='+') add();
        else if(c=='-') sub();
        else mul();
        puts("");
    }
    return 0;
}
