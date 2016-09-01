#include <stdio.h>
#include <string.h>
#define OPER 1
#define NUM 2
#define INF 0x3fffffff
#define null x
#define END -1
#define MUTI 3
int n,T;
char oper_now,oper_last;
char in[1000];
__int64 ans,temp,num_equal;
int num,l;
int isnum(char a)
{
    if(a>='0'&& a<='9')
        return 1;
    else return 0;
}
int findp()
{
    if(num==l)return END;
    int i,j;
    int t=num;
    if(in[t]=='='&& in[t+1]=='=')
    {
        num_equal  =0;
        while(in[num]=='=')
        {
            num_equal++;
            num++;
        }
        return MUTI;
    }
    if(!isnum(in[num]))
    {
        num++;
        return OPER;
    }
    __int64 tt=0;
    int jj=10;
    int ttp;
    while(isnum(in[num]))
    {
        if((tt*jj+ (in[num]-'0'))>99999999|| (tt*jj+ (in[num]-'0'))<-99999999)
        {
            num++;
            continue;
        }
        tt= tt*jj+ (in[num]-'0');
        num++;
    }
    temp= tt;
    return NUM;
}
__int64 cal_op()
{
    __int64 aaa;
    switch(oper_now)
    {
        case'-':return ans-temp;
        case'+':return temp+ans;
        case'*':aaa= (__int64)ans*temp;if(aaa>99999999|| aaa<-99999999)return INF;else return ans*temp;
        case'/':if(temp!=0)return ans/temp;else return INF;
    }
}
void cal()
{
    if(in[num-1]!='=')
    {
        if(temp!=INF&& oper_now!=NULL)
        {
            ans= cal_op();
            temp= INF;
        }
        else if(oper_now==NULL&& temp!=INF)
        {
             ans= temp;
             temp= INF;
        }
        oper_last= oper_now;
        oper_now= in[num-1];
    }
    else
    {
        if(oper_now!=NULL)
        if(temp!=INF)
        {
            ans= cal_op();
            temp= INF;
        }
        else
        {
            temp= ans;
            ans= cal_op();
            temp= INF;
        }
        oper_now= NULL;
    }
}
int main()
{
    int i,j,t;
    int op,pp;
    scanf("%d",&T);
    getchar();
    for(pp=0; pp<T; pp++)
    {
        num=0;
        ans=0;
        temp= INF;
        oper_now= NULL;
        oper_last= NULL;
        gets(in);
        l= strlen(in);
        int ttt;
        int error=0;
        while(op= findp(),op!=END&& !error)
        {
            if(ans>99999999|| ans<-99999999)
            {
                error=1;
                goto end;
            }
            if(op==OPER)
            {
                cal();
            }
            else if(op==MUTI)
            {
                    if(oper_now!=NULL)
                    {
                          if(temp!=INF)
                          {
                              for(i=0;i<num_equal;i++)
                              {
                                   ans= cal_op();
                                   if(ans>99999999|| ans<-99999999)
                                   {
                                       error=1;
                                       goto end;
                                   }
                              }
                              temp= INF;
                          }
                          else
                          {
                              ttt= ans;
                              for(i=0;i<num_equal;i++)
                              {
                                   temp= ttt;
                                   ans= cal_op();
                                   if(ans>99999999|| ans<-99999999)
                                   {
                                       error=1;
                                       goto end;
                                   }
                              }
                              temp= INF;
                          }
                    }
                    oper_now= NULL;
            }
            if(ans>99999999|| ans<-99999999)
            {
                error=1;
                goto end;
            }
        }
end:;
        printf("Case %d: ",pp+1);
        if(!error)
        printf("%I64d\n",temp==INF?ans:temp);
        else printf("ERROR\n");
    }
    return 0;
}
