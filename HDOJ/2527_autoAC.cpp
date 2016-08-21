#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
const int MAX=1000000;
char s[MAX];
char k[MAX];
using namespace std;
struct min_max
{
    int value;
    friend bool operator<(const min_ a,const min_ b)
    {
        if(a.value>=b.value)
        return true;
        else
        return false;
    }
};
int main()
{
    int t;
    int n,m,f,i,j,sum;
        cin>>t;
        while(t--)
        {
            cin>>n>>s;
            map<char,int>str;
            priority_queue<min_max>que;
            m=strlen(s);
            sum=0;
            f=0;
            for(i=0;i<m;i++)
            {
                str[s[i]]++;
                if(str[s[i]]==1)
                k[f++]=s[i];
            }
            for(i=0;i<f;i++)
            {
                min_ p;
                p.value=str[k[i]];
                que.push(p);
            }
            if(que.size()==1)
            {
                if(m>n)
                cout<<"no"<<endl;
                else
                cout<<"yes"<<endl;
            }
            else
            {
                while(que.size()!=1)
                {
                    int temp;
                    min_max aa,bb,p;
                    aa=que.top();
                    que.pop();
                    bb=que.top();
                    que.pop();
                    temp=aa.value+bb.value;
                    p.value=temp;
                    sum+=temp;
                    que.push(p);
                }
                if(sum<=n)
                cout<<"yes"<<endl;
                else
                cout<<"no"<<endl;
            }
        }
    return 0;
}
