#include <iostream>

using namespace std;
char ss[1024];
int css;
int main()
{
    int n,B;
    cin>>n>>B;
    css=0;
    while(n>0)
    {
        int ndiv=n/B;
        int nlef=n%B;
        if(nlef<10)
        {
            ss[css]=nlef+'0';
        }
        else
        {
            ss[css]=nlef-10+'A';
        }
        css++;
        n=ndiv;
    }
    for(int i=css-1;i>-1;--i)
    {
        cout<<ss[i];
    }
    cout<<"("<<B<<")"<<endl;
    return 0;
}
