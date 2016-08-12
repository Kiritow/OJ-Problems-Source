#include<stdio.h>
int main()
{
     int n,i,j,k;
     char in[10],out[10];
     int flag[20];
     while(scanf("%d %s %s",&n,in,out)!=EOF)
     {
         char stack[1000];
         int top=-1;
         i=j=k=0;
         while(j<n+1&&i<n)
         {
             if(stack[top]==out[i]&&top!=-1)
             {
                 top--;
                 flag[k]=0;
                 k++;
                 i++;
                 }
                 else
                 {
                     top++;
                     flag[k]=1;
                     k++;
                     stack[top]=in[j];
                     j++;
                     }
             }
             if(k!=2*n)
             printf("No.\n");
             else
             {
                 printf("Yes.\n");
                 for(i=0; i<n*2; i++)
                 {
                     if(flag[i])
                     printf("in\n");
                     else
                     printf("out\n");
                     }
                }
                printf("FINISH\n");
        }
        return 0;
}
