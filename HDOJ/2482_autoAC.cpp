#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int x,y;
    int step;
    int total;
    int mem[333];
    int flag;                               
}E[5011];
int x_s,y_s;
int x_e,y_e;
int queue[6066];                            
int K,Key;                                  
struct dictree                              
{
    struct dictree *child[26];
    int flag;
};
struct dictree *root;
int key;
void insert(char *S)
{
    struct dictree *cur,*New;
    int i,j;
    cur=root;
    for(i=0;S[i];i++)
    {
        if(cur->child[S[i]-'a'])    cur=cur->child[S[i]-'a'];
        else
        {
            New=(struct dictree *)malloc(sizeof(struct dictree));
            for(j=0;j<26;j++)    New->child[j]=0;
            New->flag=-1;
            cur->child[S[i]-'a']=New;
            cur=New;
        }
    }
    cur->flag=key;
}
int find(char *S)
{
    struct dictree *cur;
    int i;
    cur=root;
    for(i=0;S[i];i++)
    {
        if(cur->child[S[i]-'a'])    cur=cur->child[S[i]-'a'];
        else                        return -1;
    }
    return cur->flag;
}
int BFS()
{
    int i;
    K=0;
    while(K<Key)
    {
        if(E[queue[K]].flag==1)    return E[queue[K]].step;
        for(i=0;i<E[queue[K]].total;i++)
        {
            if(E[queue[K]].step+1<E[E[queue[K]].mem[i]].step)
            {
                E[E[queue[K]].mem[i]].step=E[queue[K]].step+1;
                queue[Key++]=E[queue[K]].mem[i];
            }
        }
        K++;
    }
    return -1;
}
int main()
{
    int T;
    int n,m,k;
    int f[33];
    char name_temp[33][25];
    int i,j;
    int ans;
    int a,b;
    char str[25];
    int base[9]={5120,2560,1280,640,320,160,80,40,20};
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%d%d",str,&a,&b);
        x_s=y_s=0;
        for(i=0;i<8;i++)
        {
            if(str[i]=='1')        y_s+=base[i];
            else if(str[i]=='2')x_s+=base[i];
            else if(str[i]=='3'){x_s+=base[i];y_s+=base[i];}
        }
        x_s+=a*8;
        y_s+=b*8;
        scanf("%s%d%d",str,&a,&b);
        x_e=y_e=0;
        for(i=0;i<8;i++)
        {
            if(str[i]=='1')        y_e+=base[i];
            else if(str[i]=='2')x_e+=base[i];
            else if(str[i]=='3'){x_e+=base[i];y_e+=base[i];}
        }
        x_e+=a*8;
        y_e+=b*8;
        root=(struct dictree *)malloc(sizeof(struct dictree));
        for(j=0;j<26;j++)    root->child[j]=0;
        root->flag=-1;
        Key=0;
        scanf("%d",&n);
        for(key=0;key<n;key++)
        {
            scanf("%s%d%d",str,&E[key].x,&E[key].y);
            insert(str);
            E[key].step=11111111;
            E[key].total=0;
            if((E[key].x-x_s)*(E[key].x-x_s)+(E[key].y-y_s)*(E[key].y-y_s)<=1000000)
            {
                E[key].step=0;
                E[key].flag=-1;
                queue[Key++]=key;
            }
            else if((E[key].x-x_e)*(E[key].x-x_e)+(E[key].y-y_e)*(E[key].y-y_e)<=1000000)    E[key].flag=1;
            else                                                                            E[key].flag=0;
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d",&k);
            for(i=0;i<k;i++)
            {
                scanf("%s",name_temp[i]);
                f[i]=find(name_temp[i]);
            }
            for(i=1;i<k;i++)
            {
                for(j=0;j<i;j++)
                {
                    E[f[i]].mem[E[f[i]].total++]=f[j];
                    E[f[j]].mem[E[f[j]].total++]=f[i];
                }
            }
        }
        if((x_s-x_e)*(x_s-x_e)+(y_s-y_e)*(y_s-y_e)<=4000000)
        {
            printf("walk there\n");
            continue;
        }
        ans=BFS();
        if(ans==-1)    printf("take a taxi\n");
        else        printf("%d\n",ans);
    }
    return 0;
}
