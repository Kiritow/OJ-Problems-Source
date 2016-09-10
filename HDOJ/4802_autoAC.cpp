#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
map<string,double>m;
double s,sum1,sum2;
string op;
int n;
int main()
{
    m["A"]=4.0,m["A-"]=3.7,m["B+"]=3.3,m["B"]=3.0;
    m["B-"]=2.7,m["C+"]=2.3,m["C"]=2.0,m["C-"]=1.7;
    m["D"]=1.3,m["D-"]=1.0,m["F"]=0;
    while(cin>>n)
    {
        sum1=0,sum2=0;
        for(int i=0;i<n;i++)
        {
            cin>>s>>op;
            if(op=="P"||op=="N")
                continue;
            sum2+=s;
            sum1+=s*m[op];
        }
        if(sum2==0)
            printf("0.00\n");
        else
            printf("%.2lf\n",sum1/sum2);
    }
}
