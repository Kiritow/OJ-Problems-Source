#include<iostream>
using namespace std;
int main()
{
    int c,n,m,l;
    cin>>c;
    while(c--)
    {
        cin>>n;
        int s=0;
        for(int i=0;i<n;++i)
        {
            cin>>m>>l;
            s^=m%(l+1);
        }
        cout<<(s?"No":"Yes")<<endl;
    }
    return 0;
}
