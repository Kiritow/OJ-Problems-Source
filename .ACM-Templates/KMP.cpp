#include <string>
#include <iostream>
#include <cstring>
using namespace std;

void getfill(string s,int* f)
{
    //memset(f,0,sizeof(f));  //根据其前一个字母得到
    for(size_t i=1;i<s.size();i++)
    {
        int j=f[i];
        while(j && s[i]!=s[j])
            j=f[j];
        f[i+1]=(s[i]==s[j])?j+1:0;
    }
}

int KMP(string a,string s)
{
    int* f=new int[s.size()+32];
    memset(f,0,sizeof(int)*s.size());
    getfill(s,f);size_t j=0;
    for(size_t i=0;i<a.size();i++)
    {
        while(j && a[i]!=s[j])
            j=f[j];
        if(a[i]==s[j])
            j++;
        if(j==s.size()){
            delete[] f;return i-s.size()+1;
        }
    }
    delete[] f;
    return -1;
}
