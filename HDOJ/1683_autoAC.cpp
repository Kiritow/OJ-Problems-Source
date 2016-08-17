#include <iostream>
#include <cstring>
using namespace std;
char a[101],b[101],c[101];
int main()
{
    int t,i;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        int len1=strlen(a);
        int len2=strlen(b);
        int len3=strlen(c);
        int j=0;
        for(i=0;i<=len2;i++)
        {
            if(b[i]=='*'||c[i]=='*')
            {
                j++;
            }
            else if (a[j]==b[i]||a[j]==c[i])
            {
                j++;
            }
            if(j==len1)
            {
                cout<<"win"<<endl;
                break;
            }
        }
        if(i>len2)
        cout<<"lose"<<endl;
    }
    return 0;
}
