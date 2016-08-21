#include<iostream>
#include<string.h>
using namespace std;
long  N,Ans;
long  Hash[300];
char  St[1111111];
void  Solve(void);
int main()
{
        while(cin>>N)  
        {
            if(!N)
            break ;
            getchar() ;
            Solve() ;
        }
        return  0 ;
}
void    Solve(void)
{
        long i=0,j=0,Now,end;
        gets(St);
        memset(Hash,0,sizeof(Hash));
        end=strlen(St);
        for(Ans=0,Now=0;i<end;i++)  
        {
            Hash[St[i]]++;
            if(Hash[St[i]]==1)  
            {
                Now++;
                while(Now>N)  
                {
                    Hash[St[j]]--;
                    if(Hash[St[j]]==0)
                        Now--;
                    j++;
                }
            }
                if(i-j+1>Ans)
                Ans=i-j+1;
        }
        cout<<Ans<<endl;
}
