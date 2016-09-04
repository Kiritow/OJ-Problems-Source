# include <cstdio>
# include <cstring>
# include <map>
using namespace std;
# define N 100005
int arr[20][N];
struct node
{
   int s,e,layer;
   int c;
}st[4*N];
int q[500000][4],c;
int remap[N],position[N];
map<int,int> refer;
void init(int s,int e,int layer,int pos=1)
{
    st[pos].s=s;st[pos].e=e;
    st[pos].layer=layer;
    st[pos].c=st[pos].s;
    if(s!=e) init(s,(s+e)/2,layer+1,pos<<1),init((s+e)/2+1,e,layer+1,(pos<<1)+1);
}
void insert(int value,int pos=1)
{
     if(st[pos].s==st[pos].e)
        arr[st[pos].layer][st[pos].c++]=value;
     else
     {
         if(value<=(st[pos].s+st[pos].e)/2)
         {
             arr[st[pos].layer][st[pos].c]=(st[pos].c==st[pos].s?0:arr[st[pos].layer][st[pos].c-1])+1;
             st[pos].c++;
             insert(value,pos<<1); 
         }
         else
         {
             arr[st[pos].layer][st[pos].c]=(st[pos].c==st[pos].s?0:arr[st[pos].layer][st[pos].c-1]);
             st[pos].c++;
             insert(value,(pos<<1)+1);
         }
     }
}
int q1(int s,int t,int k,int pos=1)
{
    if(st[pos].s==st[pos].e)
        return  remap[arr[st[pos].layer][st[pos].s]];
    else
    {
        if(arr[st[pos].layer][t]-(s==st[pos].s?0:arr[st[pos].layer][s-1])>=k)//left
            return q1(st[pos].s+(s==st[pos].s?0:arr[st[pos].layer][s-1]),st[pos].s+arr[st[pos].layer][t]-1,k,pos<<1);
        else//right
        {
            k-=arr[st[pos].layer][t]-(s==st[pos].s?0:arr[st[pos].layer][s-1]);
            return q1((st[pos].s+st[pos].e)/2+1+s-1-st[pos].s+1-(s==st[pos].s?0:arr[st[pos].layer][s-1]),(st[pos].s+st[pos].e)/2+1+t-st[pos].s+1-arr[st[pos].layer][t]-1,k,(pos<<1)+1);
        }
    }
}
int q2(int s,int pos=1)
{
    if(st[pos].s==st[pos].e) return 1;
    else if(arr[st[pos].layer][s]-(s==st[pos].s?0:arr[st[pos].layer][s-1]))
      return q2(st[pos].s+arr[st[pos].layer][s]-1,pos<<1);
    else
      return (st[pos].c==st[pos].s?0:arr[st[pos].layer][st[pos].c-1])+q2((st[pos].s+st[pos].e)/2+1+s-st[pos].s+1-arr[st[pos].layer][s]-1,(pos<<1)+1);
}
int q3(int k,int pos=1)
{
    if(st[pos].s==st[pos].e) return remap[arr[st[pos].layer][st[pos].s]];
    else if(k<=(st[pos].c==st[pos].s?0:arr[st[pos].layer][st[pos].c-1])) return q3(k,pos<<1);
    else return q3(k-(st[pos].s==st[pos].c?0:arr[st[pos].layer][st[pos].c-1]),(pos<<1)+1);
}
int main()
{
    int n,test=1;
    while(scanf("%d",&n)!=EOF)
    {
       refer.clear();c=1;
       memset(arr,0,sizeof(arr));
       for(int i=0;i<n;i++)
       {
           char tmp[12];
           scanf("%s",tmp);
           if(*tmp=='I')
             q[i][0]=0;
           else q[i][0]=tmp[6]-48;
           switch(q[i][0])
           {
           case 0:
                scanf("%d",&q[i][1]);
                refer[q[i][1]]=0; 
                break;
           case 1:
                scanf("%d%d%d",&q[i][1],&q[i][2],&q[i][3]);
                break;
           default:
                scanf("%d",&q[i][1]);
                break;
           };
       }
       for(map<int,int>::iterator i=refer.begin();i!=refer.end();i++)
         remap[c]=i->first,i->second=c++;
       init(1,c-1,0);
       long long t[4]={0,0,0,0};
       int now=1;
       for(int i=0;i<n;i++)
         switch(q[i][0])
         {
           case 0:
                insert(refer[q[i][1]]);
                position[refer[q[i][1]]]=now++;
                break;
           case 1:
                t[1]+=q1(q[i][1],q[i][2],q[i][3]);
                break;
           case 2:
                t[2]+=q2(position[refer[q[i][1]]]);
                break;
           case 3:
                t[3]+=q3(q[i][1]);
                break;
         };
       printf("Case %d:\n%I64d\n%I64d\n%I64d\n",test++,t[1],t[2],t[3]);
    }
    return 0;
}
