#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
    char str[2000];
    char buf[2000];
    int t;
    scanf("%d",&t);
    for (int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        cin>>str;
        sscanf(str,"%*[^/]//%[^/:]",buf);
        cout<<buf<<endl;
    }
    return 0;
}
