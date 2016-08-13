#include<cstdio>
#include<cstring>
char a[81];
int main()
{
      int p=0;
      while(scanf("%s",a+1)!=EOF)
      {
            int len=strlen(a+1);            
            if(a[1]=='<')
            {
                  if(a[2]=='b')printf("\n");
                   else{
                          if(p)printf("\n");
                          for(int i=1;i<=80;i++)printf("-");
                          printf("\n");
                        }
                 p=0;
            }else if(p==0)
          {
                                     for(int i=1;i<=len;i++)printf("%c",a[i]);
                                     p=len;
          }else    if(p+len>=80)
                      {
                                     printf("\n");
                                     for(int i=1;i<=len;i++)printf("%c",a[i]);
                                     p=len;
                    }else
                    if(p+len<80){
                            printf(" ");
                             for(int i=1;i<=len;i++)printf("%c",a[i]);
                             p+=len+1;
                    }
    }
    printf("\n");
    return 0;
}
