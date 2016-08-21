#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=50001;
char p[N];
char t[N];
int nex[N];
int m;
int n;
void get_nex()
{
    int i=0;
    int j=-1;
    nex[i]=-1;
    while(i<m)
    {
        if(j==-1||p[i]==p[j])
        {
            ++i;
            ++j;
            if(p[i]!=p[j])
            nex[i]=j;
            else
            nex[i]=nex[j];
        }
        else
        j=nex[j];
    }
}
void kmp()
{
    int i=0;
    int j=0;
    while(i<n)
    {
        if(j==-1||t[i]==p[j])
        {
            ++i;
            ++j;
        }
        else
            j=nex[j];
    }
        if(!j)
        cout<<j<<endl;
        else
        {
            for(int k=0;k<j;k++)
            cout<<p[k];
            cout<<" "<<j<<endl;
        }
}
int main()
{
    while(cin>>p)
    {
        cin>>t;
        n=strlen(t);
        m=strlen(p);
        get_nex();
        kmp();
    }
    return 0;
}
