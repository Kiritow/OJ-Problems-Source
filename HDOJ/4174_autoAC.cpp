#include<stdio.h>
#include<string.h>
int main()
{
    int n,len,num[111],flag,k,b,i;
    char a[111];
      scanf("%d",&n);
        while(n--)
        {
            flag=0;
            scanf("%s",a);
            len=strlen(a);
            for(i=0;i<len;i++)
            {
                if(a[i]=='a'||a[i]=='b'||a[i]=='c'||a[i]=='A'||a[i]=='B'||a[i]=='C')
                    num[i]=2;
                else if(a[i]=='d'||a[i]=='e'||a[i]=='f'||a[i]=='D'||a[i]=='E'||a[i]=='F')
                    num[i]=3;
                else if(a[i]=='g'||a[i]=='h'||a[i]=='i'||a[i]=='G'||a[i]=='H'||a[i]=='I')
                    num[i]=4;
                else if(a[i]=='j'||a[i]=='k'||a[i]=='l'||a[i]=='J'||a[i]=='K'||a[i]=='L')
                    num[i]=5;
                else if(a[i]=='m'||a[i]=='n'||a[i]=='o'||a[i]=='M'||a[i]=='N'||a[i]=='O')
                    num[i]=6;
                else if(a[i]=='p'||a[i]=='q'||a[i]=='r'||a[i]=='s'||a[i]=='P'||a[i]=='Q'||a[i]=='R'||a[i]=='S')
                    num[i]=7;
                else if(a[i]=='t'||a[i]=='u'||a[i]=='v'||a[i]=='T'||a[i]=='U'||a[i]=='V')
                    num[i]=8;
                else if(a[i]=='w'||a[i]=='x'||a[i]=='y'||a[i]=='z'||a[i]=='W'||a[i]=='X'||a[i]=='Y'||a[i]=='Z')
                    num[i]=9;
            }
            k=0;
            b=len-1;
            while(k<b)
            {
                if(num[k]!=num[b])
                {
                    flag=1;
                    break;
                }
                else
                {
                    k++;
                    b--;
                }
            }
            if(flag==1)
            {
                printf("NO\n");
            }
            else
                printf("YES\n");
        }
    return 0;
}
