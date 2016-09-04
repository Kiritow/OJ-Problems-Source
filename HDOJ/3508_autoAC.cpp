#include<iostream>
#include<cstdio>
using namespace std;
int vis[40100];                                
int q[12000];                                  
int main()
{memset(vis,1,sizeof(vis));
 vis[1]=0;
 int t=0;
 for(int i=2;i<=40000;i++)
    {if(vis[i])
        {for(int j=i;j<=40000;j+=i)
            vis[j]=0;
         q[++t]=i;
         }
     }                                          
 long long int shu[100],ge[100];
 long long int n;
 while(cin>>n)
      {if(n==1){cout<<"0"<<endl; continue;}      
       if(n==4){cout<<3<<endl; continue;}
       long long int m=1,k=0;
       long long int tt=n;
       memset(shu,0,sizeof(shu));
       memset(ge,0,sizeof(ge));
       while(tt>1&&m<t)                          
            {if(tt%q[m]==0)
               shu[++k]=q[m];                    
             if(k>=3)break;
             while(tt%q[m]==0)
                  {tt/=q[m];
                   ge[k]++;                      
                   }
             m++;
             }
       if(tt>1)                                 
          {shu[++k]=tt;
           ge[k]++;
           }
       if(k>=3) {cout<<1<<endl; continue;}       
       if(k==1)
           {if(shu[1]!=2)                       
               cout<<(n-1)<<endl;
            else cout<<1<<endl;                
            }
       if(k==2)                                  
         {if(shu[1]==2 && ge[1]==1)              
             cout<<n-1<<endl;
          else cout<<1<<endl;                   
          }
       }
 }
