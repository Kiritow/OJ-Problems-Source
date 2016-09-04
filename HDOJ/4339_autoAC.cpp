#include"iostream"
#include"cstdio"
#include"cstring"
using namespace std;
const int N=1000010;
int ltr[N<<2];
char s[2][N];
void build(int l,int r,int k)
{
    if(l==r)
    {
        if(s[0][l]==s[1][l])    ltr[k]=1;
        else    ltr[k]=0;
        return ;
    }
    int mid=(l+r)>>1;
    int l_son=k<<1;
    int r_son=l_son+1;
    build(l,mid,l_son);
    build(mid+1,r,r_son);
    ltr[k]=ltr[l_son];
    if(ltr[l_son]==mid-l+1)    ltr[k]+=ltr[r_son];
}
void update(int l,int r,int z,int aim,char c,int k)
{
    if(l==r)
    {
        s[z][aim]=c;
        ltr[k]=s[0][aim]==s[1][aim];
        return ;
    }
    int mid=(l+r)>>1;
    int l_son=k<<1;
    int r_son=l_son+1;
    if(aim<=mid)update(l,mid,z,aim,c,l_son);
    else        update(mid+1,r,z,aim,c,r_son);
    ltr[k]=ltr[l_son];
    if(ltr[l_son]==mid-l+1)    ltr[k]+=ltr[r_son];
}
int find(int l,int r,int aim,int k)
{
    if(l==aim)    return ltr[k];
    int mid=(l+r)>>1;
    int l_son=k<<1;
    int r_son=l_son+1;
    int ans;
    if(aim<=mid)
    {
        ans=find(l,mid,aim,l_son);
        if(ans==mid-aim+1)    ans+=find(mid+1,r,mid+1,r_son);
    }
    else    ans=find(mid+1,r,aim,r_son);
    return ans;
}
int main()
{
    int T,Case;
    int i;
    int len,q;
    int x,a,b;
    char c[10];
    cin>>T;
    for(Case=1;Case<=T;Case++)
    {
        scanf("%s%s",s[0]+1,s[1]+1);
        i=1;
        while(s[0][i] && s[1][i])    i++;
        len=i-1;
        i=1;
        build(1,len,1);
        cin>>q;
        printf("Case %d:\n",Case);
        while(q--)
        {
            scanf("%d",&x);
            if(x==1)
            {
                scanf("%d%d%s",&a,&b,c);
                if(b+1>len)    continue;
                update(1,len,a-1,b+1,c[0],1);
            }
            else
            {
                scanf("%d",&b);
                if(b+1>len)    printf("0\n");
                else        printf("%d\n",find(1,len,b+1,1));
            }
        }
    }
    return 0;
}
