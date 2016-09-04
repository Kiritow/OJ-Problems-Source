#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
#include <string>
using namespace std;
#define i64 __int64
class fraction
{
private:
    inline i64 Gcd (i64 x,i64 y)
    {
        return y==0?x:Gcd(y,x%y);
    }
    i64 Lcm (i64 x,i64 y)
    {
        x=x/Gcd(x,y)*y;
        if(x<0) x=-x;
        return x;
    }
public:
    i64 a,b;
    fraction () {}
    fraction (i64 x)
    {
        a=x; b=1;
    }
    fraction (i64 x,i64 y)
    {
        a=x; b=y;
        Refresh();
    }
    void Refresh ()
    {
        if (b<0) b=-b,a=-a;
        i64 k=Gcd(a,b);
        if (k<0) k=-k;
        a/=k; b/=k;
    }
    fraction Inverse () const
    {
        return fraction (b,a);
    }
    fraction operator + (fraction p)
    {
        fraction ans;
        ans.b=Lcm(b,p.b);
        ans.a=ans.b/b*a+ans.b/p.b*p.a;
        ans.Refresh();
        return ans;
    }
    fraction operator - (fraction p)
    {
        fraction ans;
        ans.b=Lcm(b,p.b);
        ans.a=ans.b/b*a-ans.b/p.b*p.a;
        ans.Refresh();
        return ans;
    }
    fraction operator * (fraction p)
    {
        fraction ans;
        ans.a=a*p.a;
        ans.b=b*p.b;
        ans.Refresh();
        return ans;
    }
    fraction operator / (fraction p)
    {
        fraction ans;
        ans.a=a*p.b;
        ans.b=b*p.a;
        ans.Refresh();
        return ans;
    }
    bool operator < (const fraction &p) const
    {
        return a*p.b<b*p.a;
    }
    bool operator > (const fraction &p) const
    {
        return a*p.b>b*p.a;
    }
    bool operator == (const fraction &p) const
    {
        return a*p.b==b*p.a;
    }
    fraction operator | (fraction p)
    {
        fraction t1=fraction (b,a);
        fraction t2=p.Inverse ();
        t1=t1+t2;
        return t1.Inverse();
    }
    void print ()
    {
        printf("%I64d/%I64d\n",a,b);
    }
};
string s;
int len;
fraction read (int &now)
{
    int fz=0,fm=0;
    int i;
    for (i=now;i<len;i++)
    {
        if (s[i]=='/') break;
        fz*=10;
        fz+=s[i]-'0';
    }
    for (i=i+1;i<len;i++)
    {
        if (isdigit(s[i]))
        {
            fm*=10;
            fm+=s[i]-'0';
        }
        else break;
    }
    fraction tmp(fz,fm);
    now=i-1;
    return tmp;
}
fraction cal (int &now)
{
    fraction ans;
    int front=-1;
    for (int i=now+1;i<len;i++)
    {
        if (s[i]=='(')
        {
            if(front==-1)
               ans=cal(i);
            else if(front==0)
                ans=ans+cal(i);
            else if(front==1)
                ans=ans|cal(i);
        }
        else if (isdigit(s[i]))
        {
            if (front==-1)
                ans=read(i);
            else if (front==0)
                ans=ans+read(i);
            else if (front==1)
                ans=ans|read(i);
        }
        else if (s[i]==')')
        {
            now=i;
            return ans;
        }
        else if (s[i]=='&')
            front=0;
        else if (s[i]=='|')
            front=1;
    }
}
int main ()
{
    while (getline(cin,s))
    {
        len=s.length();
        fraction ans;
        int flag=-1; 
        for (int i=0;i<len;i++)
        {
            if (s[i]=='(')
            {
                if (flag==-1)
                    ans=cal(i);
                else if (flag==0)
                    ans=ans+cal(i);
                else if(flag==1)
                    ans=ans|cal(i);
            }
            else if (isdigit(s[i]))
            {
                if (flag==-1)
                    ans=read(i);
                else if (flag==0)
                    ans=ans+read(i);
                else if (flag==1) 
                    ans=ans|read(i);
            }
            else if (s[i]=='&')
                flag=0;
            else if (s[i]=='|')
                flag=1;
        }
        ans.print();
    }
    return 0;
}
