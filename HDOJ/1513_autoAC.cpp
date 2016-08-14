#include<iostream>
#include<string>
using namespace std;
#define max 5000+10
#define Max(a,b) a>b?a:b
int a[2][max];
int commonorder(string s1,string s2)
{
    int i,j;
    memset(a,0,sizeof(a));
    int m=1;
        for(i=0;i<s1.length();i++)
        {
            for(j=0;j<s2.length();j++)
            {
            if(s1[i]==s2[j])
                a[m][j+1]=a[(m+1)%2][j]+1;
            else
                a[m][j+1]=Max(a[m][j],a[(m+1)%2][j+1]);
            }
            m=(m+1)%2;
        }
        return a[(m+1)%2][s2.length()];
}
int main()
{
    int n;
    string str;
    while(cin>>n)
    {
            cin>>str;
            int j;
            char temp[max];
            int k=0;
            temp[n]='\0';
            for(j=n-1;j>=0;j--)
            {temp[k]=str[j];k++;}
            int sum=commonorder(str,temp);
            printf("%d\n",n-sum);
    }
    return 0;
}
