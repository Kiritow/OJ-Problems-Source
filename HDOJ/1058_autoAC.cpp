#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int min(int a,int b)
{
        if(a>b) return b;
        else return a;
}
int main()
{
        long int a[5888];
        long int s1,s2,s3,s4,t,n;
        s1 = s2 = s3 = s4 =1;
        a[1] = 1;
        for(int i=2;i<5888;i++)
        {
                t = min(min(min(a[s1]*2,a[s2]*3),a[s3]*5),a[s4]*7);
                if(t == a[s1]*2) s1++;
                if(t == a[s2]*3) s2++;
                if(t == a[s3]*5) s3++;
                if(t == a[s4]*7) s4++;
                a[i] = t;
        }
        while(scanf("%ld",&n))
        {
          if(n==0)
          break;
          if(n%10==1&&n%100!=11)
          printf("The %ldst humble number is %ld.\n",n,a[n]);
          else if(n%10==2&&n%100!=12)
          printf("The %ldnd humble number is %ld.\n",n,a[n]);
          else if(n%10==3&&n%100!=13)
          printf("The %ldrd humble number is %ld.\n",n,a[n]);
          else
          printf("The %ldth humble number is %ld.\n",n,a[n]);
        }
        return 0;
}
