#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<iomanip>
const int MAX=1001;
using namespace std;
typedef struct Student
{
    char name[21];
    __int64 vote;
    __int64 count;
}student;
student s[MAX];
bool cmp(student a,student b)
{
    if(a.count==b.count)
    {
        if(strcmp(a.name,b.name)<0)
        return true;
        else
        return false;
    }
    else
    return a.count>b.count;
}
int main()
{
    __int64 t,n,m,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        getchar();
        for(i=0;i<n;i++)
        {
            cin>>s[i].name>>s[i].vote;
            if(s[i].vote==0)
            {
                s[i].count=0;
                continue;
            }
            int sum=0;
            m=s[i].vote;
            for(j=2;j*j<=m;j++)
            {
                if(m%j==0)
                {
                    sum+=1;
                    while(m%j==0)
                    m/=j;
                }
            }
            if(m!=1)
            sum+=1;
            s[i].count=sum;
        }
        sort(s,s+n,cmp);
        cout<<s[0].name<<endl;
    }
    return 0;
}
