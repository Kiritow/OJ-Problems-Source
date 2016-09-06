#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
int T,t,n,m;
map<string,string> match[4];
char str[1010],str2[1010],s1[1010],s2[1010];
int type1,type2,Err,Over;
void init()
{
    int i,j,k;
    for(i=0;i<=3;i++)
       match[i].clear();
    Err=1;
    Over=0;
}
bool Has_Equal()
{
    int i,j,k,len=strlen(str);
    bool flag=0,flag2=0;
    for(i=0;i<len;i++)
    {
        if(str[i]==34)
          flag2=1;
        if(str[i]=='=' && flag2==0)
        {
            flag=true;
            str[i]=' ';
        }
        if(str[i]==9)
          str[i]=32;
    }
    return flag;
}
bool kong()
{
    int i,j,k,len=strlen(str);
    bool flag=0;
    for(i=0;i<len;i++)
       if(!(str[i]==' ' || str[i]==9))
         return false;
    return true;
}
void solve()
{
    int i,j,k,len=strlen(str);
    m=0;
    for(i=0;i<len;i++)
       if(str[i]==34)
         break;
    m=i;
    for(i=m;i<len;i++)
       if(!(str[i]==' ' || str[i]==9))
         str[m++]=str[i];
    str[m]='\0';
}
int main()
{
    int i,j,k,pos;
    string string1,string2;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        if(t!=1)
          printf("\n");
        scanf("%d",&n);
        getchar();
        init();
        while(n--)
        {
            gets(str);
            solve();
            if(Over==1)
              continue;
            if(kong())
              continue;
            if(Has_Equal())
            {
                sscanf(str,"%s %s",s1,s2);
                if(s1[0]=='$')
                  type1=0;
                else
                  type1=1;
                if(s2[0]!=34)
                  type2=0;
                else
                  type2=1;
                if(type1==0)
                {
                    match[0].erase(s1);
                    match[1].erase(s1);
                    match[type2][s1]=s2;
                }
                else
                {
                    if(match[2].find(s1)==match[2].end() && match[3].find(s1)==match[3].end())
                      match[2+type2][s1]=s2;
                    else if(Err==1)
                      printf("WARNING: Constant %s Already Defined!\n",s1);
                }
            }
            else
            {
                sscanf(str,"%s %s",s1,s2);
                if(s1[0]=='P' && s1[1]=='a') //Panic
                {
                    printf("Script was KILLED.\n");
                    Over=1;
                }
                else if(s1[0]=='E' && s2[1]=='N') //Errmsg ON
                  Err=1;
                else if(s1[0]=='E' && s2[1]=='F') //Errmsg OFF
                  Err=0;
                else if(s1[0]=='P') //Print
                {
                    if(s2[0]=='$')
                    {
                        if(match[0].find(s2)!=match[0].end())
                        {
                            string1=match[0][s2];
                            cout<<string1<<endl;
                        }
                        else if(match[1].find(s2)!=match[1].end())
                        {
                            string1=match[1][s2];
                            string2=string1.substr(1,string1.length()-2);
                            cout<<string2<<endl;
                        }
                        else
                        {
                            printf("NULL\n");
                            if(Err==1)
                              printf("NOTICE: Undefined Variable %s.\n",s2);
                        }
                    }
                    else
                    {
                        if(match[2].find(s2)!=match[2].end())
                        {
                            string1=match[2][s2];
                            cout<<string1<<endl;
                        }
                        else if(match[3].find(s2)!=match[3].end())
                        {
                            string1=match[3][s2];
                            string2=string1.substr(1,string1.length()-2);
                            cout<<string2<<endl;
                        }
                        else
                        {
                            printf("%s\n",s2);
                            if(Err==1)
                              printf("NOTICE: Undefined Constant %s.\n",s2);
                        }
                    }
                }
                else if(s1[0]=='D') //Dump
                {
                    if(s2[0]=='$')
                    {
                        if(match[0].find(s2)!=match[0].end())
                        {
                            string1=match[0][s2];
                            printf("integer: ");
                            cout<<string1<<endl;
                        }
                        else if(match[1].find(s2)!=match[1].end())
                        {
                            string1=match[1][s2];
                            printf("string: ");
                            cout<<string1<<endl;
                        }
                        else
                        {
                            printf("NULL\n");
                            if(Err==1)
                              printf("NOTICE: Undefined Variable %s.\n",s2);
                        }
                    }
                    else
                    {
                        if(match[2].find(s2)!=match[2].end())
                        {
                            string1=match[2][s2];
                            printf("integer: ");
                            cout<<string1<<endl;
                        }
                        else if(match[3].find(s2)!=match[3].end())
                        {
                            string1=match[3][s2];
                            printf("string: ");
                            cout<<string1<<endl;
                        }
                        else
                        {
                            printf("string: %c%s%c\n",34,s2,34);
                            if(Err==1)
                              printf("NOTICE: Undefined Constant %s.\n",s2);
                        }
                    }
                }
            }
        }
    }
}
