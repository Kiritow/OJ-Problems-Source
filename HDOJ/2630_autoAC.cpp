#include<stdio.h>
#include<string.h>
char name[6][20]={"S.H.E","Jay","Elva","Jolin","Aska","Yoga"},temp[20];
int main(){
    int T,n,s,h,m,h1,h2;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        s=m=0;
        while(n--)
        {
            scanf("%s %d:%d",temp,&h1,&h2);
            for(int i=0;i<6;i++)
                if(strcmp(temp,name[i])==0)    m+=h1,s+=h2;
        }
        m+=s/60;s%=60;
        h=m/60;m%=60;
        printf("Samuel will watch Channel[V] for %d hour(s),%d minute(s),%d second(s).\n",h,m,s);
    }
    return 0;
}
