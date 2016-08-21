#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    int k;
    while(scanf("%d",&k)!=EOF)
    {
        char aa[100];
        char bb[100];
        scanf("%s%s",&aa,&bb);
        int aa2[71];
        int bb2[71];
        memset(aa2,0,sizeof(aa2));
        memset(bb2,0,sizeof(bb2));
        int ii;
        int alen=strlen(aa);
        int blen=strlen(bb);
        int aweizhi=70;
        int bweizhi=70;
        for(ii=alen-1;ii>=0;ii--)
        {
            if(aa2[aweizhi]!='-')
            {
                aa2[aweizhi]=aa[ii]-'0';
                aweizhi-=1;
            }
        }
        for(ii=blen-1;ii>=0;ii--)
        {
            if(bb2[bweizhi]!='-')
            {
                bb2[bweizhi]=bb[ii]-'0';
                bweizhi-=1;
            }
        }
        int cc[100];
        memset(cc,0,sizeof(cc));
        cc[70]=1;
        int i;
        for(i=1;i<k;i++)
        {
            int j;
            for(j=70;j>=0;j--)
            {
                cc[j]*=2;
            }
            for(j=70;j>=0;j--)
            {
                if(cc[j]/10>0)
                {
                    cc[j-1]+=cc[j]/10;
                    cc[j]=cc[j]%10;
                }
            }
        }
        int jingwei=0;
        int ir;
            for(ir=0;ir<=70;ir++)
            {
                aa2[ir]+=bb2[ir];
                int j2;
                for(j2=70;j2>=0;j2--)
                {
                    if(aa2[j2]/10>0)
                    {
                        aa2[j2-1]+=aa2[j2]/10;
                        aa2[j2]=aa2[j2]%10;
                    }
                }
                blen-=1;
            }
        int weizhi=0;
        for(i=0;i<=70;i++)
        {
            if(cc[i]!=0)
            {
                weizhi=i;
                break;
            }
        }            //cc:k
        int weizhi2=0;
        for(i=0;i<=70;i++)
        {
            if(aa2[i]!=0)
            {
                weizhi2=i;
                break;
            }
        }
        int flag=0;
        if(aa[0]=='-'&&bb[0]=='-')    
        {
            int iii;
            for(iii=0;iii<=70;iii++)
            {
                if(aa2[iii]>cc[iii])
                {
                    flag=1;
                    break;
                }
            }
        }else if(aa[0]!='-'&&bb[0]!='-')
        {
            cc[70]-=1;
            int iii;
            for(iii=0;iii<=70;iii++)
            {
                if(aa2[iii]>cc[iii])
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
        {
            cout<<"Yes"<<endl;
        }else
        {
            cout<<"WaHaHa"<<endl;
        }
    }
    return 0;
}
