#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<ctype.h>
typedef struct node
{
    char s[50];
    struct node *next[26];
}node;
node memory[1000000];
int k=0;
void insert(char *b,char *a,node *T)   
{
    int i,len,j,id;
    node *p,*q;
    p=T;
    len=strlen(b);
    for(i=0;i<len;++i)
    {
        id=b[i]-'a';
        if(p->next[id]==NULL)
        {
            q=&memory[k++];
            memset(q->s,'\0',sizeof(q->s));
            for(j=0;j<26;++j)
                q->next[j]=NULL;
            p->next[id]=q;
        }
        p=p->next[id];
    }
    strcpy(p->s,a);
}
int search(char *t,node *T)   
{
    int id,i=0;
    char *p=t;
    node *q=T;
    while(islower(p[i]))
    {
        id=p[i]-'a';
        if(q->next[id]==NULL) 
            return 0;
        else
        {
            q=q->next[id];
            ++i;
        }
    }
    if(strlen(q->s))      
    {
        printf("%s",q->s);
        return 1;
    }
    return 0;
}
int main()
{
    int i,len;
    char a[50],b[50];
    char c[4000];
    node *T;
    T=&memory[k++];
    memset(T->s,'\0',sizeof(T->s));
    for(i=1;i<26;++i)
        T->next[i]=NULL;
    while(scanf("%s",a)&&strcmp(a,"START")==0)
    {
        while(scanf("%s",a)&&strcmp(a,"END"))
        {
            scanf("%s",b);
            insert(b,a,T);
        }
        while(scanf("%s",a)&&strcmp(a,"START")==0)
        {
            getchar();
            while(gets(c))
            {
                if(strcmp(c,"END")==0)
                    return 0;
                len=strlen(c);
                for(i=0;i<len;++i)
                {
                    if(!islower(c[i]))
                        printf("%c",c[i]);
                    else
                    {
                        if(!search(&c[i],T))
                        {
                            while(islower(c[i]))
                                printf("%c",c[i++]);
                            --i;
                        }
                        else
                        {
                            while(islower(c[i++]));
                            i-=2;
                        }
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}
