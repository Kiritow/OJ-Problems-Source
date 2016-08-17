/// UVa 1401
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>
using namespace std;
const int MAXBUFFSIZE = 300100;
const int BUFFERSIZE = 105;
const int MAXS = 4005;
const int MOD = 20071027;
const int MAXPOOLNODESIZE = 400100;
struct node
{
    node* next[26];
    int val;
};

node _root;
node* root=&_root;

node pool[MAXPOOLNODESIZE];
int c_pool_guard=0;

char buff[MAXBUFFSIZE];
int dp[MAXBUFFSIZE];
char tmp[BUFFERSIZE];
int StringLength[MAXS];
int main()
{
    int _G_cnt=0;
    while(gets(buff)!=NULL)
    {
        _G_cnt++;
        memset(dp,0,sizeof(dp));
        memset(StringLength,0,sizeof(StringLength));
        memset(root,0,sizeof(node));
        c_pool_guard=0;

        int n;
        scanf("%d%*c",&n);
        int ccnt=1;
        while(n--)
        {
            gets(tmp);
            char* p=tmp;
            node* np=root;
            int _c=0;
            while(*p!=0)
            {
                if(np->next[*p-'a']==NULL)
                {
                    np->next[*p-'a']=&pool[c_pool_guard++];
                    memset(np->next[*p-'a'],0,sizeof(node));
                }
                np=np->next[*p-'a'];
                _c++;
                p++;
            }
            StringLength[ccnt]=_c;
            np->val=ccnt++;
        }
        int len=strlen(buff);
        dp[len]=1;
        for(int i=len-1; i>=0; --i)
        {
            /// Search
            vector<int> vec;
            char* p=buff+i;
            node* np=root;
            while(*p!=0)
            {
                if(np->next[*p-'a']==NULL) break;
                np=np->next[*p-'a'];
                if(np->val!=0) vec.push_back(np->val);
                p++;
            }
            for(int j=0; j<(int)vec.size(); j++)
            {
                dp[i]=(dp[i]+dp[i+StringLength[vec.at(j)]])%MOD;
            }
        }
        printf("Case %d: %d\n",_G_cnt,dp[0]);
    }
    return 0;
}
