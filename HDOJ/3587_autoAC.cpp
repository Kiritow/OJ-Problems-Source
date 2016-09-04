#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct man
{
    int team;
    char name[15];
    int po;  
    int lt;
    int kiin;
}mn[2005];
int main()
{
    int i, j, n, m, k, ct, an, bn;
    bool fir;
    char ch[3], killer[15], killed[15];
    while(scanf("%d%d%d", &n, &m, &k)!=EOF)
    {
        fir=false;
        for(i=0; i<n+m; i++)
        {
            if(i<n)
                mn[i].team=1;
            else
                mn[i].team=2;
            scanf("%s", mn[i].name);
            mn[i].po=603;mn[i].kiin=0;mn[i].lt=0;
        }
        getchar();//care!!!!!!!!!!!!!
        for(i=0; i<k; i++)
        {
            scanf("%s", ch);
            if(ch[0]=='K')
            {
                scanf("%s%s%d", killer, killed, &ct);
                getchar();
                an=-1; bn=-1;
                for(j=0;(!(an>=0&&bn>=0))&&(j<n+m); j++){
                    if(strcmp(mn[j].name, killer)==0)
                        an=j;
                    else if(strcmp(mn[j].name, killed)==0)
                        bn=j;
                }
                if(mn[an].team!=mn[bn].team)
                {
                    mn[an].kiin++;
                    if(fir==false)
                    {mn[an].po+=400;fir=true;}
                    else if(mn[an].kiin>=10)
                        mn[an].po+=600;
                    else if(mn[an].kiin<=1)
                        mn[an].po+=200;
                    else
                        mn[an].po+=(200+50*(mn[an].kiin-2));
                }
                mn[bn].po-=300;
                if(mn[bn].po<0)
                {
                    mn[bn].po=0;
                    mn[bn].lt=ct;
                }
                mn[bn].kiin=0;
            }
            else if(ch[0]=='Q')
            {
                scanf("%s%d", killer, &ct);
                getchar();
                for(j=0; j<n+m; j++)
                    if(strcmp(mn[j].name, killer)==0)
                    {
                        an=j;
                        break;
                    }
                int re=mn[an].po+ct-mn[an].lt;
                printf("%d\n", re);
            }
        }
    }
    return 0;
}
