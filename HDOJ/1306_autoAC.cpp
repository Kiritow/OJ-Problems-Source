#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    string s1,s2,t1,t2,x1,x2;
    int i,j,k,n;
    while(cin>>x1&&x1!="-1")
    {
        cin>>x2;
        if(x1.length()>x2.length())
        {
            s1=x2;
            s2=x1;
        }
        else
        {
            s1=x1;
            s2=x2;
        }
        int sum=0;
        for(i=0;i<s1.length();i++)
            for(k=0;k<s2.length();k++)
                 for(j=1;j<=s1.length()-i&&j<=s2.length()-k;j++)
                 {
                     int total=0;
                        t1=s1.substr(i,j);
                        t2=s2.substr(k,j);
                        for(n=0;n<j;n++)
                            if(t1[n]==t2[n])
                                total++;
                            if(total>sum)
                                sum=total;
                 }
             int temp=x1.length()+x2.length();
             int t=sum*2;
             if(sum==0)
             cout<<"appx("<<x1<<","<<x2<<")"<<" = "<<"0"<<endl;
             else if(t==temp)
             cout<<"appx("<<x1<<","<<x2<<")"<<" = "<<"1"<<endl;
             else
             {
                 for(i=2;i<temp;i++)
                 if(temp%i==0&&t%i==0)
                 {
                     while(temp%i==0&&t%i==0)
                     {
                         t/=i;
                         temp/=i;
                     }
                 }
             cout<<"appx("<<x1<<","<<x2<<")"<<" = "<<t<<"/"<<temp<<endl;
            }
    }
    return 0;
}
