#include<iostream>
#include<cstring>
#include<cctype>
#include<stack>
using std::stack;
const int L=1001;
stack<double> OPND;
stack<char> OPTR;
bool IsLegalChar(char c)
{
    if(isdigit(c))
       return true;
    else if(c=='+' || c=='-' || c=='*' || c=='/' || c=='%' || c=='(' || c==')' || c=='.')
       return true;
    else
       return false;
}
double ToOperand(char t[],int length,int count,int point)
{
    if(count>1 || t[0]=='.' || t[length-1]=='.')
       return -1.0;
    double result=0.0,v=1.0;
    if(count==0)
    {
       for(int i=length-1;i>=0;i--)
       {
           result+=(double)(t[i]-'0')*v;
           v*=10;
       }
       return result;
    }
    else
    {
       for(int i=point-1;i>=0;i--)
       {
           result+=(double)(t[i]-'0')*v;
           v*=10;
       }
       v=0.1;
       for(int i=point+1;i<length;i++)
       {
           result+=(double)(t[i]-'0')*v;
           v/=10.0;
       }
       return result;
    }
}
char OperatorJudgement(char optr1,char optr2)
{
    if(optr1=='+' || optr1=='-')
    {
       if(optr2=='+' || optr2=='-' || optr2==')' || optr2=='#')
           return '>';
       if(optr2=='*' || optr2=='/' || optr2=='%' || optr2=='(')
           return '<';
    }  
    if(optr1=='*' || optr1=='/' || optr1=='%')
    {
       if(optr2=='+' || optr2=='-' || optr2=='*' || optr2=='/' || optr2=='%' || optr2==')' || optr2=='#')
           return '>';
       if(optr2=='(')
           return '<';
    }
    if(optr1=='(')
    {
       if(optr2==')')
           return '=';
       if(optr2=='#')
           return 'E';
       if(optr2=='+' || optr2=='-' || optr2=='*' || optr2=='/' || optr2=='%' || optr2=='(')
           return '<';
    }
    if(optr1==')')
    {
       if(optr2=='(')
           return 'E';
       else
           return '>';
    }
    if(optr1=='#')
    {
       if(optr2==')')
           return 'E';
       if(optr2=='#')
           return '=';
       else
           return '<';
    }
}
bool IsLegalMod(double opnd1,double opnd2)
{
    if(opnd1-(int)opnd1!=0.0 || opnd2-(int)opnd2!=0.0 || opnd2==0.0)
       return false;
    return true;
}
double Calculate(double opnd1,char optr,double opnd2)
{
    if(optr=='+')
       return opnd1+opnd2;
    if(optr=='-')
       return opnd1-opnd2;
    if(optr=='*')
       return opnd1*opnd2;
    if(optr=='/')
       return opnd1/opnd2;
    if(optr=='%')
       return (double)((int)opnd1%(int)opnd2);
}
int main()
{
    int i,j;
    bool isLegalInfixNonation;
    char s[L],t[L];
    while(gets(s))
    {
       isLegalInfixNonation=true;
       for(i=0;s[i]!='\0';i++)
       {
           if(IsLegalChar(s[i])==false)
           {
              isLegalInfixNonation=false;
              break;
           }
       }
       strcat(s,"#");
       while(OPND.empty()==false)
           OPND.pop();
       while(OPTR.empty()==false)
           OPTR.pop();
       i=0;
       OPTR.push('#');
       while((s[i]!='#' || OPTR.top()!='#') && isLegalInfixNonation==true)
       {
           if(isdigit(s[i]) || s[i]=='.')
           {
              int point=0,count=0;
              for(j=0;isdigit(s[i]) || s[i]=='.';i++,j++)
              {
                  t[j]=s[i];
                  if(s[i]=='.')
                     count++,point=j;
              }
              double opnd=ToOperand(t,j,count,point);
              if(opnd==-1.0)
              {
                  isLegalInfixNonation=false;
                  break;
              }
              else
              {
                  OPND.push(opnd);
              }
           }
           else
           {
              char optr1=OPTR.top(),optr2=s[i];
              char judgement=OperatorJudgement(optr1,optr2);
              if(judgement=='E')
                  isLegalInfixNonation=false;
              else
              {
                  if(judgement=='<')
                  {
                     OPTR.push(optr2);
                     i++;
                  }
                  else if(judgement=='=')
                  {
                     OPTR.pop();
                     i++;
                  }
                  else if(judgement=='>')
                  {
                     OPTR.pop();
                     if(OPND.empty()==true)
                     {
                         isLegalInfixNonation=false;
                         break;
                     }
                     double opnd2=OPND.top();
                     OPND.pop();
                     if(OPND.empty()==true)
                     {
                         isLegalInfixNonation=false;
                         break;
                     }
                     double opnd1=OPND.top();
                     OPND.pop();
                     if(optr1=='%')
                     {
                         if(IsLegalMod(opnd1,opnd2)==false)
                         {
                            isLegalInfixNonation=false;
                            break;
                         }
                     }
                     if(optr1=='/')
                     {
                         if(opnd2==0.0)
                         {
                            isLegalInfixNonation=false;
                            break;
                         }
                     }
                     double result=Calculate(opnd1,optr1,opnd2);
                      OPND.push(result);
                  }
              }
           }
       }
       if(isLegalInfixNonation==false)
           puts("ERROR IN INFIX NOTATION");
       else
       {
           if(OPND.size()!=1)
              puts("ERROR IN INFIX NOTATION");
           else
              printf("%.2lf\n",OPND.top());
       }
    }
    return 0;
}
