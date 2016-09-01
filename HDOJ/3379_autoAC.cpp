#include<iostream>
#include<string.h>
using namespace std;
const int maxn=1005;
int map[maxn][maxn],n,cnt[maxn][maxn];
char name[maxn][100];
int match_name(char str[])
{
   for(int i=1;i<n;i++)
       if(strcmp(str,name[i])==0)
           return i;
    strcpy(name[n],str);
    return n++;
}
void str_convert(char str[])
{
    int i,j,first_node,k;
    bool flag=0;
    char str1[100];
    for(i=0;i<strlen(str);)
    {
        for(j=0;str[i]!=' '&&str[i]!='\0';i++,j++)
            str1[j]=str[i];
        str1[j]='\0';
        i++;
        k=match_name(str1);
        if(flag==0)
        {
            first_node=k;
            flag=1;
        }
        else if(map[first_node][k]==0)
            {
              map[first_node][k]=map[k][first_node]=1;
              cnt[first_node][k]=cnt[k][first_node]=1;
            }
    }
}
void floyd() 
{
    int i,j,k;
    for(k=1;k<n;k++)
        for(i=1;i<n;i++)
            for(j=1;j<n;j++)
              if(map[i][k] && map[k][j])
                if(map[i][j]==0)
                {
                      map[i][j]=map[i][k]+map[k][j];
                      cnt[i][j]=cnt[i][k]*cnt[k][j];
                }
                else if(map[i][k]+map[k][j]<map[i][j])
                {
                    map[i][j]=map[i][k]+map[k][j];
                    cnt[i][j]=cnt[i][k]*cnt[k][j];
                }
                else if(map[i][k]+map[k][j]==map[i][j])
                    cnt[i][j] += cnt[i][k]*cnt[k][j];
}
int main()
{
    int i,j;
    char str[100],str1[100],str2[100];
    gets(str);
    while(gets(str))
    {
      n=1;
      memset(map,0,sizeof(map));
      memset(cnt,0,sizeof(cnt));
      str_convert(str);
      while(gets(str))
      {
        if(strcmp(str,"GRAPH END")==0) break;
        str_convert(str);
      }
      for(i=1;i<n;i++)
         map[i][i]=1;
      floyd();
       while(cin>>str1>>str2)
       {
        if(strcmp(str1,"GRAPH")==0 && strcmp(str2,"BEGIN")==0) break;
        i=match_name(str1);
        j=match_name(str2);
        cout<<str1<<" "<<str2<<" "<<cnt[i][j]<<endl;
       }
    }
    return 0;
}
