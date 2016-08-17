#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
struct node
{
    int b1;
    int shu;
    friend bool operator < (node a,node b)
    {
        if(a.b1!= b.b1){  
            return a.b1 < b.b1;  
        }  
        else{  
            return a.shu > b.shu ;  
        }  
    }
};
int main()
{
    int a,b,c,z,d,e,f,xx,wc;
    char ss[10];
    node t;
    while(scanf("%d",&a)!=EOF)
    {
        priority_queue<node> q;
        priority_queue<node> q1;
        priority_queue<node> q2;
        xx=0;
        while(a--)
        {
            scanf("%s",ss);
            if(ss[0]=='I')
            {
                scanf("%d%d",&b,&c);
                t.b1=c;
                t.shu=++xx;
                if(b==1)
                {
                    q.push(t);
                }
                else if(b==2)
                {
                    q1.push(t);
                }    
                else if(b==3)
                {
                    q2.push(t);
                }
            }
            else
            {
                scanf("%d",&z);
                if(z==1)
                {
                    if(q.empty()==1)
                    {
                        printf("EMPTY\n");
                    }
                    else
                    {
                        t=q.top();
                        q.pop();
                        printf("%d\n",t.shu);
                    }
                }
                else if(z==2)
                {
                    if(q1.empty()==1)
                    {
                        printf("EMPTY\n");
                    }
                    else
                    {
                        t=q1.top();
                        q1.pop();
                        printf("%d\n",t.shu);
                    }
                }
                else if(z==3)
                {
                    if(q2.empty()==1)
                    {
                        printf("EMPTY\n");
                    }
                    else
                    {
                        t=q2.top();
                        q2.pop();
                        printf("%d\n",t.shu);
                    }
                }
            }
        }    
    }
    return 0;
}
