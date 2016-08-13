#include<iostream>
using namespace std;
bool al[26]={false};
int main()
{
    int n;
    int T=1;
    while(cin>>n&&n!=0)
    {
        memset(al,0,sizeof(al));
        al[0]=1;
        char c1,c2,c3;
        while(n--)
        {
            cin>>c1>>c2>>c3;
            if(al[c3-'a']==0)
                al[c1-'a']=0;
            else
            {
                al[c1-'a']=1;
            }
        }
        int ok=0;
        cout<<"Program #"<<T<<endl;
        for(int i=0;i<26;i++)
        {
            if(al[i])
            {
                ok=1;
                cout<<(char)(i+'a')<<" ";
            }
        }
        if(ok==1)
            cout<<endl;
        if(ok==0)
            cout<<"none"<<endl;
        cout<<endl;
        T++;
    }
    return 0;
}
