#include<iostream>
#include<cstring>
using namespace std;
char a[50010][123];
struct node{
    bool p;
    node *next[26];
    node(){
        memset(next,NULL,sizeof(next));
        p=0;
    }
}*head;
void insert(char *c){
    int i=0;
    node *p=head;
    while(c[i]){
        if(p->next[c[i]-'a']==NULL)
            p->next[c[i]-'a']=new node;
        p=p->next[c[i]-'a'];
        i++;
    }
    p->p=true;
}
bool search(char *c){
    node *p=head,*s;
    int i,j,l=strlen(c),o;
    char k;
    for(i=0;i<l;i++){
        k=c[i]-'a';
        if(p->next[k]){
            p=p->next[k];
            if(p->p==true){
                s=head;o=1;
                for(j=i+1;j<l;j++){
                    k=c[j]-'a';
                    if(s->next[k])
                        s=s->next[k];
                    else{
                        o=0;
                        break;
                    }
                }
                if(o){
                    if(s->p)
                        return 1;
                }
            }
        }
    }
    return 0;
}
int main(){
    int i,j,n=0;
    head=new node;
    while(~scanf("%s",a[n++]))
        insert(a[n-1]);
    for(i=0;i<n;i++)
        if(search(a[i]))
            printf("%s\n",a[i]);
}
