#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <stack> 
#include <iostream>
#include <algorithm>
using namespace std;
#define ERROR non=true;return
set<string> used;
stack<string> s;
bool non, root;
bool gettag(char* &ch, string &tag, bool &end, bool &empty)
{
    int p1, p2, p3, p4;
    string attribute;
    end=false, empty=false;
    tag=attribute="";
    ch++;                                 
    if (*ch=='/'){end=true;ch++;}
    while (isalnum(*ch) || *ch=='-')      
    {
        tag+=*ch;
        ch++;
    }
    while (isspace(*ch)) ch++;
    if (*ch=='>')                            
        return 1;
    if (*ch=='/')
    {
        int cal=0;
        ch++;
        while (*ch!='>'){cal++;ch++;}
        if (cal>0) return -2;
        if (end) return -1;
        else empty=true;
    }
    while (isalnum(*ch) || *ch=='-' || *ch=='.' || *ch=='\"' || *ch=='=')       
    {
        attribute+=*ch;
        ch++;
    }
    if (attribute.length()>0)
    {
        p1=attribute.find("=", 0);      if (p1==-1) return -3;
        p2=attribute.find("\"", 0);     if (p2<p1) return -4;
        p2=attribute.find("\"", p1+1);  if (p2==-1) return -5;
        p3=attribute.find("\"", p2+1);  if (p3==-1 || p3==p2+1) return -6;  
        p4=attribute.find("\"", p3+1);  if (p4!=-1) return -7;              
        p4=attribute.find("=", p1+1);   if (p4!=-1) return -8;             
    }
    while (isspace(*ch)) ch++;
    if (*ch=='>') return 1;
    if (*ch=='/')
    {
        int cal=0;
        ch++;
        while (*ch!='>'){cal++;ch++;}
        if (cal>0) return -10;
        if (end) return -9;
        else empty=true;
    }
    while (*ch!='>'){
        ch++;
        if (!isspace(*ch) && *ch!='>') return -11;
    }
    return 1;
}
void solve(char *ch)
{
    bool end, empty;
    string tag;
    int tmp;
    while (!non && *ch!='\0')
    {
        if (*ch=='<')
        {
            tmp=gettag(ch, tag, end, empty);
            if (tmp==1)
            {
                if (end && empty){
                    ERROR;
                }
                if (empty && used.count(tag)>0){
                    ERROR;
                }
                else if (!empty && !end)
                {
                    if (used.count(tag)>0){
                        ERROR;
                    }
                    if (s.empty())
                    {
                        if (root){ERROR;}
                        else root=true;
                    }
                    used.insert(tag);
                    s.push(tag);
                }
                else if (!empty && end)
                {
                    if (s.empty() || s.top()!=tag){
                    ERROR;
                }
                    used.erase(tag);
                    s.pop();
                }
            }
            else{ERROR;}
        }
        else ch++;
    }
}
int main()
{
    string tag, attribute;
    bool firstdata=true;
    bool end, empty;
    char buf[65536];
    do{
        while (gets(buf)!=NULL && strcmp(buf, "<span class="crayon-ta"><?xml version=\1.0\?>)!=0
                && strcmp(buf, "<span class="crayon-ta"><?end?>)!=0)
        {
            solve(buf);
        }
        if (strcmp(buf, "<span class="crayon-ta"><?xml version=\1.0\?>)==0)
        {
            if (!firstdata)
            {
                if (non || !s.empty()) printf("non well-formed\n");
                else printf("well-formed\n");
            }
            else firstdata=false;
            non=false;
            root=false;
            used.clear();
            while (!s.empty()) s.pop();
        }
    }while (strcmp(buf, "<span class="crayon-ta"><?end?>)!=0);
    if (non || !s.empty()) printf("non well-formed\n");
    else printf("well-formed\n");
    return 0;
}
