#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
struct node
{
        node *next[26];
        int count; 
        bool dangours; 
        void clear()
        {
               dangours = false;
               memset(next,0,sizeof(next));
               count = 0;
        }
}Q[200001]; 
queue<node *> sq;
int current,sum,len;
char s[21];
node *newnode()
{
        Q[current].clear();
        return &Q[current++];
}
void insert(node *root,char s[])
{
        int i = 0,index;
        node *temp = root;
        while(s[i])
        {
               index = s[i] - 'a';
               if(temp -> next[index] == NULL)
                       temp -> next[index] = newnode();
               temp = temp -> next[index];
               i++;
        }
        temp -> count++;
}
void dfs(int n,node *temp) 
{
        int i,index;
        if(n == len)
        {
               if(!temp ->dangours)
               {
                       temp -> dangours = true;
                       sum += (temp -> count);
                       sq.push(temp);
               }
        }
        if(s[n] >= 'a' &&s[n] <= 'z')
        {
               if(temp -> next[s[n] - 'a'] != NULL)
               {
                       dfs(n + 1,temp -> next[s[n] - 'a']);
               }
        }
        else  if(s[n] == '?')
        {
               for(i = 0;i < 26;i++)
               {
                       if(temp -> next[i] != NULL)
                       {
                               dfs(n + 1,temp -> next[i]);
                       }
               }
        }
        else if(s[n] == '*') 
        {
               dfs(n + 1,temp);
               for(i = 0;i < 26;i++)
               {
                       if(temp ->next[i] != NULL)
                       {
                               dfs(n,temp -> next[i]);
                       }
               }
        }
}
void orz(char s[])
{
        int i;
        for(i = 0;s[i];i++)
        {
               while(s[i] == '*'&&s[i + 1] == '*')
               {
                       for(int j = i;s[j];j++)
                       {
                               s[j] = s[j + 1];
                       }
               }
        }
}
int main()
{
        node *root,*temp;
        int n,m;
        while(scanf("%d%d",&n,&m) != EOF)
        {
               current = 0;
               root = newnode();
               for(int i = 0;i < n;i++)
               {
                       scanf("%s",s);
                       insert(root,s);
               }
               for(int i = 0;i < m;i++)
               {
                       sum = 0;
                       scanf("%s",s);
                       orz(s);
                       len = strlen(s);
                       dfs(0,root);
                       if(sum)
                               printf("%d\n",sum);
                       else
                               printf("Not match\n");
                       while(!sq.empty())
                       {
                               temp = sq.front();sq.pop();
                               temp -> dangours = false;
                       }
               }
        }
}
