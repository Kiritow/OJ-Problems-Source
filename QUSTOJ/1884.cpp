#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;

char buff[1024];
const long long MOD=10000;

int main()
{
    gets(buff);
    int len=strlen(buff);
    int isReadingNumber=0;
    long long NumberCache;
    stack<long long> val;
    stack<char> op;

    for(int i=0;i<len;i++)
    {
        if(buff[i]>='0'&&buff[i]<='9')
        {
            if(isReadingNumber)
            {
                NumberCache=NumberCache*10+buff[i]-'0';
            }
            else
            {
                isReadingNumber=1;
                NumberCache=buff[i]-'0';
            }
        }
        else if(buff[i]=='+')
        {
            isReadingNumber=0;
            val.push(NumberCache);
            if(op.empty()) op.push(buff[i]);
            else if(op.top()=='+') op.push(buff[i]);
            else /// op.top()=='*'
            {
                long long preans=val.top();
                val.pop();
                while(!op.empty()&&op.top()=='*')
                {
                    preans=(preans*(val.top()))%MOD;
                    val.pop();
                    op.pop();
                }
                val.push(preans);
                op.push(buff[i]);
            }
        }
        else if(buff[i]=='*')
        {
            isReadingNumber=0;
            val.push(NumberCache);
            op.push(buff[i]);
        }
    }

    if(isReadingNumber)
    {
        isReadingNumber=0;
        val.push(NumberCache);
    }
    if(!op.empty()&&op.top()=='*')
    {
        long long preans=val.top();
        val.pop();
        while(!op.empty()&&op.top()=='*')
        {
            preans=(preans*(val.top()))%MOD;
            val.pop();
            op.pop();
        }
        val.push(preans);
    }

    if(!op.empty())
    {
        long long preans=val.top();
        val.pop();
        while(!op.empty())
        {
            preans=(preans+(val.top()))%MOD;
            val.pop();
            op.pop();
        }
        val.push(preans);
    }

    long long ans=val.top()%MOD;
    printf("%lld\n",ans);
    return 0;
}

/*
11*414+225*44+11
*/
