#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
char S[1000],Q[1000];
char Std[65]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
void Make(int x)
{
    Q[strlen(Q)]=Std[x];
}
void f(int n) 
{ 
    if(n) f(n/2); 
    else return; 
    printf("%d",n%2); 
} 
int main()
{
    int t,tm;
    scanf("%d",&tm);t=tm;
    while(t--)
    {
        int k,i,n;
        scanf("%d %s",&n,S);
        while(n--)
        {
            memset(Q,0,sizeof(Q));
            int l=strlen(S);
            for(i=0;i<l;i++)
            {
                if(i%3==0)
                    Make(S[i]/4);
                if(i%3==1)
                    Make((S[i-1]%4)*16+S[i]/16);
                if(i%3==2)
                {
                    Make((S[i-1]%16)*4+S[i]/64);
                    Make(S[i]%64);
                }
            }
            if(l%3)
            {
                int key=(S[l-1]%4)*16;
                if(l%3==2) key=(S[l-1]%16)*4;
                Make(key);
                strcat(Q,"=");
                if(l%3==1) strcat(Q,"=");    
            }
            Q[strlen(Q)]='\0';
            strcpy(S,Q);
        }
        printf("Case #%d: %s\n",tm-t,S);
    }
    return 0;
}
