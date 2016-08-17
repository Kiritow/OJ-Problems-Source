#include<iostream>
#include<string>
using namespace std;
int belong[1000000];
int pos[1005];
struct node
{
    int x;
    int next;
}r[200010];                           
int main()
{
    int x,t,i,j,n,No=0;
    int front,back,used;                        
    string com;
    while(cin>>t&&t)
    {
        front=-1;
        back=-1;
        used=-1;
        for(i=0;i<t;++i)
        {
            cin>>n;                      
            for(j=0;j<n;++j)
            {
                cin>>x;
                belong[x]=i;             
            }
            pos[i]=-1;                  
        }
        cout<<"Scenario #"<<++No<<endl;
        while(cin>>com&&com!="STOP")
        {
            if(com=="ENQUEUE")                 
            {
                used++;
                cin>>x;
                if(pos[belong[x]]==-1)                 
                {
                    if(front==-1&&back==-1)            
                    {
                        front=used;
                        back=used;
                        r[used].x=x;
                        r[used].next=-1;
                        pos[belong[x]]=used;
                    }
                    else                              
                    {
                        r[used].x=x;
                        r[used].next=-1;
                        r[back].next=used;
                        back=used;
                        pos[belong[x]]=used;
                    }
                }
                else                                    
                {
                    if(pos[belong[x]]==back)
                        back=used;
                    r[used].x=x;
                    r[used].next=r[pos[belong[x]]].next;
                    r[pos[belong[x]]].next=used;
                    pos[belong[x]]=used;
                }
            }
            else if(com=="DEQUEUE")                   
            {
                cout<<r[front].x<<endl;
                if(pos[belong[r[front].x]]==front)
                    pos[belong[r[front].x]]=-1;
                front=r[front].next;
                if(front==-1)
                    back=-1;
            }
        }
        cout<<endl;
    }
    return 0;
}
