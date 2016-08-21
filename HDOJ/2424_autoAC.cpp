#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
void mult(char a[],char b[],char s[])
{
    int i,j,k=0,alen,blen,sum=0,res[165][165]={0},flag=0;
    char result[165];
    alen=strlen(a);blen=strlen(b); 
    for (i=0;i<alen;i++)
        for (j=0;j<blen;j++) res[i][j]=(a[i]-'0')*(b[j]-'0');
        for (i=alen-1;i>=0;i--)
        {
            for (j=blen-1;j>=0;j--) 
                sum=sum+res[i+blen-j-1][j];
            result[k]=sum%10;
            k=k+1;
            sum=sum/10;
        }
        for (i=blen-2;i>=0;i--)
        {
            for (j=0;j<=i;j++) sum=sum+res[i-j][j];
            result[k]=sum%10;
            k=k+1;
            sum=sum/10;
        }
        if (sum!=0) {result[k]=sum;k=k+1;}
        for (i=0;i<k;i++) result[i]+='0';
        for (i=k-1;i>=0;i--) s[i]=result[k-1-i];
        s[k]='\0';
        while(1)
        {
            if (strlen(s)!=strlen(a)&&s[0]=='0') 
                strcpy(s,s+1);
            else
                break;
        }
}
void add(char a[],char b[],char back[])
{
    int i,j,k,up,x,y,z,l;
    char *c;
    if (strlen(a)>strlen(b)) l=strlen(a)+2; else l=strlen(b)+2;
    c=(char *) malloc(l*sizeof(char));
    i=strlen(a)-1;
    j=strlen(b)-1;
    k=0;up=0;
    while(i>=0||j>=0)
    {
        if(i<0) x='0'; else x=a[i];
        if(j<0) y='0'; else y=b[j];
        z=x-'0'+y-'0';
        if(up) z+=1;
        if(z>9) {up=1;z%=10;} else up=0;
        c[k++]=z+'0';
        i--;j--;
    }
    if(up) c[k++]='1';
    i=0;
    c[k]='\0';
    for(k-=1;k>=0;k--)
        back[i++]=c[k];
    back[i]='\0';
} 
int flage[100],M,open=0;
char num1[100][25],sum[100],temp[100];
int main()
{    
    int T;
        int i;
    M=0;
    while(scanf("%d",&T)!=EOF)
    {
        memset(num1,0,sizeof(num1));
        memset(sum,0,sizeof(sum));
        memset(flage,0,sizeof(flage));
        memset(temp,0,sizeof(temp));
        for(int i=0;i<T;i++)
        {
            cin>>num1[i];
        }
        int dingshitao = 0;
        open=0;
        for( i=0;i<T;i++)
        {
            if(num1[i][0]!='*'&&num1[i][0]!='+')
            {        flage[i]=1;  }
            if(num1[i][0]=='*')
            {flage[i]=2;}
            if(i%2==1&&strlen(num1[i])!=1)
            {
                dingshitao = 1;    
            }
        }
        if(dingshitao == 1)
        {
            cout<<"Case "<<++M<<": Invalid Expression!"<<endl;
            continue;
        }
        if(T==0)
        {cout<<"Case "<<++M<<": "<<"0"<<endl;
        continue;
        }
        if(T==1)
        {
            if(flage[0]==1)
                cout<<"Case "<<++M<<": "<<num1[0]<<endl;
            else 
                cout<<"Case "<<++M<<": Invalid Expression!"<<endl;
            continue;
        }
        if(T==2)
        {
            cout<<"Case "<<++M<<": Invalid Expression!"<<endl;
            continue;
        }
        if(T==3&&flage[1]==1)
        {
            cout<<"Case "<<++M<<": Invalid Expression!"<<endl;
            continue;
        }
        for(i=0;i<T;i++)
        {
            if(T%2==0)
            {
                cout<<"Case "<<++M<<": Invalid Expression!"<<endl;
                open=1;
                break;
            }
            if(i%2==0)
            {
                if(flage[i]!=1)
                {
                    cout<<"Case "<<++M<<": Invalid Expression!"<<endl;
                    open=1;
                    break;
                }
            }
            else
                if(flage[i]==1)
                {    cout<<"Case "<<++M<<": Invalid Expression!"<<endl;
                open=1;
                break;
                }
        }
        int f=0;        
        for(i=1;i<T-1;i=i+2)
        {
            if(flage[i]==2)
            {
                if(!f)
                {
                    strcpy(temp,num1[i-1]);
                    f=1;
                }
                if(flage[i-1]!=3||flage[i+1]!=3)
                {
                    mult(temp,num1[i+1],temp);
                    flage[i-1]=3;
                    flage[i+1]=3;
                }
            }
            else
            {
                add(temp,sum,sum);
                memset(temp,0,sizeof(temp));
                f=0;
            }
        }
        if(flage[T-2]==2)
        {
            add(temp,sum,sum);
        }
        for(i=1;i<T-1;i=i+2)
        {
            if(flage[i]==0)
            {
                if((flage[i-1]!=3||flage[i+1]!=3))
                {
                    if(flage[i-1]==1)
                    {
                        add(num1[i-1],sum,sum);
                        flage[i-1]=3;
                    }
                    if(flage[i+1]==1)
                    {
                        add(num1[i+1],sum,sum);
                        flage[i+1]=3;
                    }
                }
            }
        }
        if(!open)
        {
            if(sum[0]=='0')
                cout<<"Case "<<++M<<": "<<"0"<<endl;
            else
                cout<<"Case "<<++M<<": "<<sum<<endl;
        }
}
return 0;
}
