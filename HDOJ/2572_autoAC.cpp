#include<cstring>
#include<iostream>
using namespace std;
int main()
{
    int T,i,j,n;
    cin>>T;
    while(T--)
    {
        string s,s1,s2,s3,str;  
        cin>>s1>>s2>>s3;
        n=s1.length();
        str=s1+"#";            
        for(i=0; i<n; i++)
        {
            for(j=i+1; j<=n; j++)
            {
                s=s1.substr(i,j-i);  
                if(s.find(s2)!=-1&&s.find(s3)!=-1)  
                {          
                    if(s.length()<str.length())
                    {
                        str=s;
                    }
                    else if(s.length()==str.length())
                    {
                        if(s<str)
                        str=s;
                    }
                }
            }
        }
        if(str.length()==n+1) cout<<"No"<<endl;
        else 
        cout<<str<<endl;
    }
    return 0;
}
