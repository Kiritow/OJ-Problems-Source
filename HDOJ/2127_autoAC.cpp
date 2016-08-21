#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
char stack[500];                    
int top;                            
char output[500], input[500];        
int outLen;
int priority(char op)                
{
    if (op=='+' || op=='-')
        return 1;
    if (op=='*' || op=='/')
        return 2;
    else
        return 0;
}
bool isOperator(char op)                
{
    return (op=='+' || op=='-' || op=='*' || op=='/');
}
void Polish(char *s,int len)            
{
    memset(output,'\0',sizeof output);    
    outLen = 0;
    for (int i=len-1; i >= 0; --i)        
    {
        if (isdigit(s[i]))                
        {
            output[outLen++] = s[i];    
            while (i-1 >= 0 && isdigit(s[i-1]))
            {
                output[outLen++] = s[i-1];
                --i;
            }
            output[outLen++] = ' ';        
        }
        if (s[i]==')')                    
        {
            ++top;
            stack[top] = s[i];
        }
        while (isOperator(s[i]))        
        {                                                
            if (top==0 || stack[top]==')' || priority(s[i]) >= priority(stack[top])) 
            {
                ++top;
                stack[top] = s[i];
                break;
            }
            else
            {
                output[outLen++] = stack[top];
                output[outLen++] = ' ';
                --top;
            }
        }
        if (s[i]=='(')                    
        {
            while (stack[top]!=')')
            {
                output[outLen++] = stack[top];
                output[outLen++] = ' ';
                --top;
            }
            --top;    
        }
    }
    while (top!=0)                        
    {
        output[outLen++] = stack[top];
        output[outLen++] = ' ';
        --top;
    }
}
char DstBuf[200];
char* OP(char* op1,char* op2,char op)
{
    __int64 res = 0;
    if (op=='+')
        res = _atoi64(op1) + _atoi64(op2);
    else if (op=='-')
        res = _atoi64(op1) - _atoi64(op2);
    else if (op=='*')
        res = _atoi64(op1) * _atoi64(op2);
    else if (op=='/')
        res = _atoi64(op1) / _atoi64(op2);
    _i64toa(res,DstBuf,10);
    return DstBuf;
}
char cSt1[200][80], cSt2[200][80];
__int64 calc(char *s)                
{
    int top1=0, top2=0, i;
    for (i=0; s[i]; ++i)
    {
        if (s[i] && s[i] != ' ')
        {
            ++top1;
            sscanf(s+i,"%s",cSt1[top1]);        
            while (s[i] && s[i] != ' ')
                ++i;
        }
    }
    while (top1 != 0)    
    {
        if (!isdigit(cSt1[top1][0]))    
        {
            OP(cSt2[top2], cSt2[top2-1], cSt1[top1][0]);
            memcpy(cSt2[top2-1],DstBuf,sizeof DstBuf);
            --top2;                    
            --top1;                        
        }
        else
        {
            ++top2;                        
            memcpy(cSt2[top2],cSt1[top1],sizeof cSt1[top1]);
            --top1;                        
        }
    }
    return _atoi64(cSt2[1]);
}
int main()
{
    int T = 1;
    while (gets(input))
    {
        Polish(input, strlen(input));
        reverse(output,output+outLen-1);
        output[outLen-1] = '\0';
        printf("Case %d:\n%s\n",T++,output);
        printf("%I64d\n",calc(output));
    }
    return 0;
}
