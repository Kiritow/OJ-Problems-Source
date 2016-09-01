#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int t;
    int T,b;
    int ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&T,&b);
        ans = 0;
        if(90 % b)
        {
            cout<<"Impossible!"<<endl; 
        }
        else
        {
            if(T == 1 ) 
            {
                for(int i=9; i>=1; i--)
                {
                    if(i % b == 0)
                    {
                        ans = i;
                        break;
                    }    
                }
                if(ans)  
                {
                    cout<<ans<<endl;
                }
                else 
                {
                    cout<<"Impossible!"<<endl;
                }
            }
            else
            {
                for(int i=99; i>=10; i--)
                {
                    if(i % b == 0)
                    {
                        ans = i;
                        break;
                    }
                }
                for(int k=3; k<=T; k++)
                {
                    cout<<"9"; 
                }
                cout<<ans<<endl;
            }
        }
    }
    return 0;    
}
