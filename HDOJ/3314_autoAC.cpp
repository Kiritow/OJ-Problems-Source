#include<iostream>  
#include<string.h>
using namespace std;  
const int maxn=100000+10;  
int p[maxn],r[maxn],cnt[maxn];  
void make()  
{  
    memset(r,0,sizeof(r));  
    memset(p,255,sizeof(p));  
    for(int i=0;i<maxn;i++) cnt[i]=1;  
}  
int find(int x)  
{  
    int px,t;  
    for(px=x;p[px]>=0;px=p[px]);  
    while (x!=px) {  
        t=p[x];  
        p[x]=px;  
        x=t;  
    }  
    return px;  
}  
int unio(int x,int y)  
{  
    x=find(x),y=find(y);  
    if(x==y)    return -1;  
    if(r[x]>r[y])  
    {  
        p[y]=x;  
        cnt[y]+=cnt[x];  
        cnt[x]=cnt[y];  
        return x;  
    }  
    else  
    {  
        p[x]=y;  
        cnt[x]+=cnt[y];  
        cnt[y]=cnt[x];  
        if(r[x]==r[y])  r[y]++;  
        return y;  
    }  
}  
int d[maxn];  
int main()  
{  
    int n;  
    while (scanf("%d",&n)!=EOF)  
    {  
        make();  
        for(int i=0;i<n;i++){  
            scanf("%d",&d[i]);  
            unio(i,d[i]);  
        }  
        int tmp_max=-1,k=-1;  
        bool flag=false;  
        for(int i=0;i<n;i++)  
        {  
            if(i==d[i])  
            {  
                if(tmp_max==cnt[find(i)])  
                {  
                    flag=false;  
                }  
                if(cnt[find(i)]>tmp_max)  
                {  
                    flag=true;  
                    tmp_max=cnt[find(i)];  
                    k=i;  
                }  
            }  
        }  
        if(!flag)  
        {  
            printf("Trouble\n");  
        }  
        else  
        {  
            printf("%d\n",k);  
        }  
    }  
    return 0;  
}
