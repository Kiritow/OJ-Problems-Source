#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
using namespace std;
 
int main()
{
    int n,i;
    string str;
    while(cin>>n)
    {
        const int LEN=sizeof(int)*8;
        bitset<LEN> a(n);
        ostringstream p;
        p<<a;
        str=p.str();
        int length=str.size();
        for(i=0;i<length;i++)
        {
            if(str[i]!='0')
            {
                break;
            }
        }
        cout<<str.c_str()+i<<endl;
    }
    return 0;
}
