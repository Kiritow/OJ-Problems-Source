#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
struct state
{
    int tot,num;
}tem,in,out;
stack <struct state> st;
stack < char > cst;
int n,m;
char s[10005];
int main()
{
    int t;
    scanf("%d",&t);getchar();
    while(t--)
    {
        gets(s);
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            if(s[i]<='9'&&s[i]>='0')
            {
                int tep=0;
                while(s[i]<='9'&&s[i]>='0')
                {
                    tep=tep*10+s[i]-'0';
                    i++;
                }
                if(!cst.empty()&&cst.top()=='+')
                {
                    tem=st.top();st.pop();
                    tem.num+=tep;tem.tot++;
                    st.push(tem);cst.pop();
                }
                else
                {
                    tem.num=tep;tem.tot=0;
                    st.push(tem);
                }
                i--;
            }
            else if(s[i]=='+'||s[i]=='(')
                cst.push(s[i]);
            else if(s[i]==')'||s[i]==',')
            {
                while(!cst.empty()&&cst.top()=='+')
                {
                    in=st.top();st.pop();
                    out=st.top();st.pop();
                    tem.num=in.num+out.num;
                    tem.tot=in.tot+out.tot+1;
                    st.push(tem);cst.pop();
                }
                if(s[i]==')'&&st.size()>=2)
                {
                    in=st.top();st.pop();
                    out=st.top();st.pop();
                    if(out.num>in.num)
                    {
                        out.tot=out.tot*2+in.tot;
                        st.push(out);
                    }
                    else
                    {
                        in.tot=in.tot*2+out.tot;
                        st.push(in);
                    }
                    cst.pop();
                }
            }
        }
        while(!cst.empty())
        {
            while(!cst.empty()&&cst.top()=='+')
            {
                in=st.top();st.pop();
                out=st.top();st.pop();
                tem.num=in.num+out.num;
                tem.tot=in.tot+out.tot+1;
                st.push(tem);
                cst.pop();
            }
        }
        printf("%d %d\n",st.top().num,st.top().tot);
        st.pop();
    }
    return 0;
}
