#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;
stack<int> fstack;
queue<int> Q;
char s[1000010];
struct name
{
    char str[11];
}na[50001];
int main()
{
    int cas,n,num;
    char str1[11];
    scanf("%d",&cas);
    while(cas--)
    {
        while(!fstack.empty())
            fstack.pop();
        while(!Q.empty())
            Q.pop();
        scanf("%s",s);
        int len=strlen(s);
        num=0;
        int j=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]>='a'&&s[i]<='z')
                str1[j++]=s[i];
            else
            {
                if(j!=0)
                {
                    str1[j]='\0';
                    j=0;
                    strcpy(na[++num].str,str1);
                }
                if(s[i]=='(')
                {
                    fstack.push(num);
                        Q.push(num);
                }
                else if(s[i]==',')
                {
                    if(s[i-1]!=')')
                        Q.push(num);
                    Q.push(fstack.top());
                }
                else {
                    if(s[i-1]!=')')
                        Q.push(num);
                    Q.push(fstack.top());
                    fstack.pop();
                }
            }
        }
        if(num==0)
        {
            str1[j]='\0';
            printf("1\n%s\n\n",str1);
            continue;
        }
        printf("%d\n",num);
        for(int i=1;i<=num;i++)
            printf("%s\n",na[i].str);
        while(!Q.empty())
        {
            if(Q.front()==1&&Q.size()==1)
                break;
            printf("%d ",Q.front());
            Q.pop();
            printf("%d\n",Q.front());
        }
        puts("");
    }
    return 0;
}
