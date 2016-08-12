#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int Lib[4]={6,2,4,8};  
const int fact[10]={1,1,2,6,4,2,2,4,2,8};  
char s[200];
int a[200];  
void todigit(char s[],int a[])
{
    a[2]=0;
    a[0]=strlen(s);
    for (int i=0; i<a[0]; i++) a[a[0]-i]=s[i]-'0';
}
void mult(int a[],int x) 
{  
    int j=0;
    for (int i=a[0]; i>0; i--)
    {
        int k1=(j*10+a[i])/x;
        j=(j*10+a[i])%x;
        a[i]=k1;
    }
    while (a[0]>1 && a[a[0]]==0) a[0]--;
}
int last_nunzero(int a[])
{
    if (a[0]==1) return fact[a[1]];
    int x1=fact[a[1]%5];               
    mult(a,5);
    int x2=Lib[(a[2]*10+a[1])%4];     
    int ret=(x1*x2*last_nunzero(a))%10; 
    return ret;
}
int main()
{
    while (gets(s))
    {
        todigit(s,a);
        printf("%d\n",last_nunzero(a));
    }
    return 0;
}
