#include <iostream>
#include <string.h>
#include <stack>
#include <queue>
using namespace std;
class node
{
public:
    node* left;
    node* right;
    char c;
    node()
    {
        left = right = NULL;
    }
    ~node()
    {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};
void print(node* s)
{
    char output[10001];
    char* o = output + 10000;
    *o = 0;
    queue<node*> q;
    q.push(s);
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        o--;
        *o = temp->c;
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    puts(o);
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char input[10001];
        scanf("%s",input);
        int len = strlen(input);
        stack<node*> s;
        node* temp;
        for(int i=0;i<len;i++)
        {
            if(input[i]>='a')
            {
                temp = new node;
                temp->c = input[i];
                s.push(temp);
            }
            else
            {
                node *left, *right;
                right = s.top();
                s.pop();
                left = s.top();
                s.pop();
                temp = new node;
                temp->c = input[i];
                temp->left = left;
                temp->right = right;
                s.push(temp);
            }
        }
        print(s.top());
        delete s.top();
        s.pop();
    }
}
