#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
    vector<string> v;
    char ch[10];
    string s;
    int n;
    cin>>n;
    int i,j;
    while(cin>>n)
    {
        v.clear();
        for(i=0;i<n;i++)
        {
            scanf("%s",&ch);
            s=ch;
            v.push_back(s);
        }
        sort(v.begin(),v.end());
        for(i=0;i<n-1;i++)
        {
            if(v[i+1].find(v[i])==0)
            {
                cout<<"NO"<<endl;
                goto RL;
            }
        }
        cout<<"YES"<<endl;
        RL:continue;
    }
    return 0;
}
