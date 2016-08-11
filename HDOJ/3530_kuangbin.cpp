#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

const int MAXN=100010;
int q1[MAXN],q2[MAXN];
int rear1,head1;
int rear2,head2;
int a[MAXN];
int main()
{
  //  freopen("in.txt","r",stdin);
  //  freopen("out.txt","w",stdout);
    int n,m,k;

    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        rear1=head1=0;
        rear2=head2=0;
        int ans=0;
        int now=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            while(head1<rear1&&a[q1[rear1-1]]<a[i])rear1--;//这里的等号取和不取都可以的
            while(head2<rear2&&a[q2[rear2-1]]>a[i])rear2--;
            q1[rear1++]=i;
            q2[rear2++]=i;
            while(head1<rear1&&head2<rear2&&a[q1[head1]]-a[q2[head2]]>k)
            {
                if(q1[head1]<q2[head2])now=q1[head1++]+1;
                else now=q2[head2++]+1;
            }
            if(head1<rear1&&head2<rear2&&a[q1[head1]]-a[q2[head2]]>=m)
            {
                //int t=min(q1[head1],q2[head2]);
                if(ans<i-now+1)ans=i-now+1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
