# include<stdio.h>
# include<string.h>
# define INF 0xfffffff
int n,m;
struct node{
    int ati,def,hp,exp;
}str[21];
int s[21]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
struct node1{
    int ati,def,hp,exp;
}DP[1049000];
int max(int a,int b)
{
    return a>b?a:b;
}
int judge(int a1,int b1,int c1,int a2,int b2,int c2)
{
    int ans1,ans2,num1,num2;
    ans1=max(1,a1-b2);
    ans2=max(1,a2-b1);
    num1=c1/ans2;
    if(num1*ans2!=c1) num1++;
    num2=c2/ans1;
    if(num2*ans1!=c2) num2++;
    if(num2>num1) return 0;
    c1-=(num2-1)*ans2;
    return c1;
}
int main()
{
    int i,j,in_ati,in_def,in_hp,ati,def,hp,num,temp,ans;
    char ch[105];
    while(scanf("%d%d%d %d%d%d",&ati,&def,&hp,&in_ati,&in_def,&in_hp)!=EOF)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%s %d%d%d%d",&ch,&str[i].ati,&str[i].def,&str[i].hp,&str[i].exp);
        DP[0].hp=hp;
        DP[0].exp=0;
        DP[0].ati=ati;
        DP[0].def=def;
        for(i=1;i<s[n];i++)
        {
            DP[i].hp=-1;
            for(j=0;j<n;j++)
            {
                if(i&s[j])
                {
                    ans=i-s[j];
                    if(DP[ans].hp==-1) continue;
                    temp=judge(DP[ans].ati,DP[ans].def,DP[ans].hp,str[j].ati,str[j].def,str[j].hp);
                    if(temp==0) continue;
                    num=DP[ans].exp+str[j].exp;
                    num/=100;
                    if(DP[i].hp<temp +num*in_hp)
                    {
                        DP[i].hp=temp+num*in_hp;
                        DP[i].ati=DP[ans].ati+num*in_ati;
                        DP[i].def=DP[ans].def+num*in_def;
                        DP[i].exp=(DP[ans].exp+str[j].exp)%100;
                    }
                }
            }
        }
        if(DP[s[n]-1].hp==-1) printf("Poor LvBu,his period was gone.\n");
        else printf("%d\n",DP[s[n]-1].hp);
    }
    return 0;
}
