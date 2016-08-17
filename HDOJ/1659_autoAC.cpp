#include <stdio.h>
#include <string.h>
struct node
{int x[50],y[50],z,num; 
} a[1000][1000];
int visit[1000][1000]; 
int dfs(int X,int Y)
{int i;
 if (a[X][Y].z==0) return a[X][Y].num;
 else
 {
  for (i=1;i<=a[X][Y].z;i++)
  a[X][Y].num=a[X][Y].num+dfs(a[X][Y].x[i],a[X][Y].y[i]); 
  a[X][Y].z=0; 
  return a[X][Y].num;
 }
}
int main()
{int f,t,l,i,j,k,n,m,num,top,tail,column,row,pos;
 char s[2000];
 scanf("%d",&t);
 while (t--)
 {scanf("%d %d",&n,&m);
  memset(visit,0,sizeof(visit)); 
  for (i=1;i<=m;i++)
  for (j=1;j<=n;j++)
  {a[i][j].z=0;a[i][j].num=0;}
  for (i=1;i<=m;i++)
  {getchar();
   for (j=1;j<=n;j++)
   {scanf("%s",&s);
    l=strlen(s);
    a[i][j].z=0;
    if (s[0]!='=')
       {num=0; f=0; if (s[0]=='-') f=1;
        for (k=f;k<l;k++)
        num=num*10+s[k]-'0';
        a[i][j].num=num;
        if (f==1) a[i][j].num=-a[i][j].num;
        visit[i][j]=1;
       }
       else
       {column=0; row=0; pos=1;
        a[i][j].num=0;
        while (pos<l)
        {while ((s[pos]>='A')&&(s[pos]<='Z')) {column=column*26+s[pos]-'A'+1; ++pos;}
         while ((pos<l)&&(s[pos]>='0')&&(s[pos]<='9')) {row=row*10+s[pos]-'0'; ++pos;}
         if ((visit[row][column]==1)||((i==row)&&(j==column))) a[i][j].num=a[i][j].num+a[row][column].num;
                            else {++a[i][j].z;a[i][j].x[a[i][j].z]=row; a[i][j].y[a[i][j].z]=column;}
         row=0; column=0; ++pos;
        }
       }
   }
  }
  for (i=1;i<=m;i++)
  for (j=1;j<=n;j++)
  if (a[i][j].z>0) dfs(i,j);
  for (i=1;i<=m;i++)
  {for (j=1;j<n;j++)
   printf("%d ",a[i][j].num);
   printf("%d\n",a[i][n].num);
  }
 }
 return 0;
}
