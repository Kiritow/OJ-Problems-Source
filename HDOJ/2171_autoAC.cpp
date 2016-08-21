#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t;
    string name[22];
    string s,s1;
    char c;
    int i,j,k,l,n;
    cin>>t;
    while(t--)
    {
        c=getchar();
        i=1;
        getline(cin,s);
        l=s.length();
        k=0;
        for(j=0;j<l;j++)
        {
            if(s[j]==' ')
            {
                name[i]=s.substr(k,j-k);
                i++;
                k=j+1;
            }
            if(j==l-1)
            {
                name[i]=s.substr(k,j-k+1);
                i++;
                k=j+1;
            }
        }
        cin>>s1;
        cin>>n;
        for(j=0;j<i;j++)
            if(name[j]==s1) {k=j;break;}
        i--;
        for(j=1;j<n;j++)
        {
            k++;
            if(k>i) k=1;
        }
        cout<<name[k]<<endl;
    }
}
