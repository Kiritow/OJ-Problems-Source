#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char str[1100][1100];
int s[1100][1100];
struct Q
{
   int num,left,right;       
}q[1100];
int main()
{
    int t;
    int row,col;
    int i,j,max;
    scanf("%d",&t);
    while(t--)
          {
            scanf("%d%d",&row,&col);
            for(i=1;i<=row;i++)
              for(j=1;j<=col;j++)
                 {
                 cin>>str[i][j];
                 }
            for(i=0;i<=col;i++) 
               s[0][i]=0;
            for(i=1;i<=row;i++)
               for(j=1;j<=col;j++)
                 {
                    if(str[i][j]!='R')
                        s[i][j]=s[i-1][j]+1;
                    else
                       s[i][j]=0;           
                 }
            max=0; 
            for(i=1;i<=row;i++)
               {
                  for(j=1;j<=col;j++)
                     {
                       q[j].num=s[i][j];
                       q[j].left=j;
                       q[j].right=j;                
                     }
                  q[0].num=-1;
                  q[col+1].num=-1;              
                  for(j=1;j<=col;j++)
                     {
                       while(q[q[j].left-1].num>=q[j].num)
                            q[j].left=q[q[j].left-1].left;              
                     }
                  for(j=col;j>=1;j--)
                     {
                       while(q[q[j].right+1].num>=q[j].num)
                           q[j].right=q[q[j].right+1].right;             
                     } 
                  for(j=1;j<=col;j++)
                     {
                       if(max<q[j].num*(q[j].right-q[j].left+1))
                           max=q[j].num*(q[j].right-q[j].left+1);               
                     }
               } 
            printf("%d\n",max*3);     
          }          
     return 0;  
}
