#include<stdio.h>
#include<string.h>
#include<stack>
#include<queue>
using namespace std;
void que(int n)
{
    int a,b;
    char str[5];
    queue<int>q;
    while(n--)
    {
        scanf("%s",str);
        if(!strcmp(str,"IN"))
        {
            scanf("%d",&a);
            q.push(a);
        }
        else
        {
            if(q.empty())
            printf("None\n");
            else
            {
                b=q.front();
                printf("%d\n",b);
                q.pop();
            }
        }
    }
    while(!q.empty())
    {
        q.pop();
    }
}
void sta(int n)
{
    int a,b;
    char str[5];
    stack<int>s;
    while(n--)
    {
        scanf("%s",str);
        if(!strcmp(str,"IN"))
        {
            scanf("%d",&a);
            s.push(a);
        }
        else
        {
            if(s.empty())
            printf("None\n");
            else
            {
                b=s.top();
                printf("%d\n",b);
                s.pop();
            }
        }
    } 
    while(!s.empty())
    {
        s.pop();
    }
}
int main()
{
    int t,n,i,j;
    char s1[6];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %s",&n,s1);
        if(!strcmp(s1,"FIFO"))
        {
            que(n);
        }
        else
        {
            sta(n);
        } 
    }
    return 0;
}
