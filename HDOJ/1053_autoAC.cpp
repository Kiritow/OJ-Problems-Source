#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
using namespace std;
int cmp(const void *a, const void *b)
{
    return *(char*)a - *(char*)b;
}
class TreeNode
{
public:
    char ch;
    int count;
    int depth;
    TreeNode *leftChild, *rightChild;
    TreeNode()
    {
        ch = '\0';
        count = 0;
        depth = 0;
        leftChild = NULL;
        rightChild = NULL;
    }
    friend bool  operator<(const TreeNode &a, const TreeNode &b)
    {
        return    a.count > b.count;
    }
};
priority_queue<TreeNode> que;
queue<TreeNode> q;
int res;
void hoffman()
{
    TreeNode *root, *a, *b, *c, newNode;
    while(que.size() > 1){
        a = new TreeNode;
        *a = que.top();
        que.pop();
        b = new TreeNode;
        *b = que.top();
        que.pop();
        c = new TreeNode;
        c->count = a->count + b->count;
        c->leftChild = a;
        c->rightChild = b;
        que.push(*c);
    }
    root = new TreeNode;
    *root = que.top();
    root->depth = 0;
    que.pop();
    q.push(*root);
    while(!q.empty()){
        newNode = q.front();
        q.pop();
        if(newNode.leftChild){
            newNode.leftChild->depth = newNode.depth + 1;
            q.push(*newNode.leftChild);
        }
        if(newNode.rightChild){
            newNode.rightChild->depth = newNode.depth + 1;
            q.push(*newNode.rightChild);
        }
        if(!newNode.leftChild && !newNode.rightChild){
            res += newNode.depth * newNode.count;
        }
    }
}
int main()
{
    int i, j, len, count;
    char str[1005];
    while(scanf("%s", str)!=EOF && strcmp("END", str)!=0){
        len = strlen(str);
        qsort(str, len, sizeof(char), cmp);
        TreeNode t;
        count = 1;
        t.ch = str[0];
        for(i=1; i<len; i++){           
            if(str[i-1] == str[i]){
                count++;
            }
            else{
                t.count = count;
                que.push(t);
                t.ch = str[i];
                count = 1;
            }
        }
        t.count = count;
        que.push(t);
        res = 0;
        if(que.size() == 1){
            printf("%d %d 8.0\n", 8*len, len);
            que.pop();
        }
        else{
            hoffman();
            printf("%d %d %.1lf\n", 8*len, res, 8*len*1.0/res);
        }
    }
    return 0;
}
