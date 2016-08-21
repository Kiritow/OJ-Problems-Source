#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
typedef struct team
{
    string name;
    int price[4];
}team;
typedef struct school
{
    string name;
    int price[4];
    team tm[101];
    int nowteamlen;
}school;
typedef struct place
{
    string name;
    int price[4];
}place;
school scl[201];
place plc[201];
int tellprice(string price)
{
    if(price=="gold")
        return 1;
    if(price=="silver")
        return 2;
    if(price=="copper")
        return 3;
    return 0;
}
int cmpbyscl(const void *a,const void *b)
{
    school *x=(school *)a;
    school *y=(school *)b;
    if(x->price[1]<y->price[1])
        return 1;
    if(x->price[1]>y->price[1])
        return -1;
    if(x->price[2]<y->price[2])
        return 1;
    if(x->price[2]>y->price[2])
        return -1;
    if(x->price[3]<y->price[3])
        return 1;
    if(x->price[3]>y->price[3])
        return -1;
    if(x->name>y->name)
        return 1;
    if(x->name<y->name)
        return -1;
    return 0;
}
int cmpbytm(const void *a,const void *b)
{
    team *x=(team *)a;
    team *y=(team *)b;
    if(x->price[1]<y->price[1])
        return 1;
    if(x->price[1]>y->price[1])
        return -1;
    if(x->price[2]<y->price[2])
        return 1;
    if(x->price[2]>y->price[2])
        return -1;
    if(x->price[3]<y->price[3])
        return 1;
    if(x->price[3]>y->price[3])
        return -1;
    if(x->name>y->name)
        return 1;
    if(x->name<y->name)
        return -1;
    return 0;
}
int cmpbyplc(const void *a,const void *b)
{
    place *x=(place *)a;
    place *y=(place *)b;
    if(x->name>y->name)
        return 1;
    if(x->name<y->name)
        return -1;
    return 0;
}
int main()
{
    int i, j; 
    long T,N,t;
    long nowplacelen,nowschoollen;
    string tschool,tteam,tprice,tplace;
    scanf("%d",&T);
    for(int pp=1;pp<=T;pp++)
    {
        scanf("%d",&N);
        nowplacelen=0;
        nowschoollen=0;
        for(i=0;i<N;i++)
        {
            cin>>tschool>>tteam>>tprice>>tplace;
            for(j=0;j<nowplacelen;j++)
            {
                if(plc[j].name==tplace)
                    break;
            }
            if(j==nowplacelen)
            {
                plc[j].name=tplace;
                plc[j].price[1]=0;
                plc[j].price[2]=0;
                plc[j].price[3]=0;
                plc[j].price[tellprice(tprice)]=1;
                nowplacelen++;
            }
            else
            {
                plc[j].price[tellprice(tprice)]++;
            }
            for(j=0;j<nowschoollen;j++)
            {
                if(scl[j].name==tschool)
                    break;
            }
            if(j==nowschoollen)
            {
                scl[j].name=tschool;
                scl[j].price[1]=0;
                scl[j].price[2]=0;
                scl[j].price[3]=0;
                scl[j].price[tellprice(tprice)]=1;
                nowschoollen++;
                scl[j].tm[0].name=tteam;
                scl[j].tm[0].price[1]=0;
                scl[j].tm[0].price[2]=0;
                scl[j].tm[0].price[3]=0;
                scl[j].tm[0].price[tellprice(tprice)]=1;
                scl[j].nowteamlen=1;
            }
            else
            {
                scl[j].price[tellprice(tprice)]++;
                for(t=0;t<scl[j].nowteamlen;t++)
                {
                    if(tteam==scl[j].tm[t].name)
                        break;
                }
                if(t==scl[j].nowteamlen)
                {
                    scl[j].tm[t].name=tteam;
                    scl[j].tm[t].price[1]=0;
                    scl[j].tm[t].price[2]=0;
                    scl[j].tm[t].price[3]=0;
                    scl[j].tm[t].price[tellprice(tprice)]=1;
                    scl[j].nowteamlen++;
                }
                else
                {
                    scl[j].tm[t].price[tellprice(tprice)]++;
                }
            }
        }
        printf("Case %d:\n****************\n",pp);       
        printf("school number: %d\n",nowschoollen);
        qsort(scl,nowschoollen,sizeof(scl[0]),cmpbyscl);
        for(i=0;i<nowschoollen;i++)
        {
            qsort(scl[i].tm,scl[i].nowteamlen,sizeof(scl[i].tm[0]),cmpbytm);
        }
        qsort(plc,nowplacelen,sizeof(plc[0]),cmpbyplc);
        cout<<scl[0].name<<" "<<1<<" "<<scl[0].price[1]<<" "<<scl[0].price[2]<<" "<<scl[0].price[3]<<endl;
        printf("     team number: %d\n",scl[0].nowteamlen);
        cout<<"     "<<scl[0].tm[0].name<<" "<<1<<" "<<scl[0].tm[0].price[1]
            <<" "<<scl[0].tm[0].price[2]<<" "<<scl[0].tm[0].price[3]<<endl;
        for(int j=1,tt=1;j<scl[0].nowteamlen;j++)
        {
            if((scl[0].tm[j].price[1]!=scl[0].tm[j-1].price[1])||(scl[0].tm[j].price[2]!=scl[0].tm[j-1].price[2])||(scl[0].tm[j].price[3]!=scl[0].tm[j-1].price[3]))
                tt=j+1;
            cout<<"     "<<scl[0].tm[j].name<<" "<<tt<<" "<<scl[0].tm[j].price[1]
                <<" "<<scl[0].tm[j].price[2]<<" "<<scl[0].tm[j].price[3]<<endl;
        }
        for(i=1,t=1;i<nowschoollen;i++)
        {
            if((scl[i].price[1]!=scl[i-1].price[1])||(scl[i].price[2]!=scl[i-1].price[2])||(scl[i].price[3]!=scl[i-1].price[3]))
                t=i+1;
            cout<<scl[i].name<<" "<<t<<" "<<scl[i].price[1]<<" "<<scl[i].price[2]<<" "<<scl[i].price[3]<<endl;
            printf("     team number: %d\n",scl[i].nowteamlen);
            cout<<"     "<<scl[i].tm[0].name<<" "<<1<<" "<<scl[i].tm[0].price[1]
                <<" "<<scl[i].tm[0].price[2]<<" "<<scl[i].tm[0].price[3]<<endl;
            for(int j=1,tt=1;j<scl[i].nowteamlen;j++)
            {
                if((scl[i].tm[j].price[1]!=scl[i].tm[j-1].price[1])||(scl[i].tm[j].price[2]!=scl[i].tm[j-1].price[2])||(scl[i].tm[j].price[3]!=scl[i].tm[j-1].price[3]))
                    tt=j+1;
                cout<<"     "<<scl[i].tm[j].name<<" "<<tt<<" "<<scl[i].tm[j].price[1]
                    <<" "<<scl[i].tm[j].price[2]<<" "<<scl[i].tm[j].price[3]<<endl;
            }
        }
        printf("****************\n\n");
        printf("contest number: %d\n",nowplacelen);
        for(i=0;i<nowplacelen;i++)
        {
            cout<<plc[i].name<<" "<<plc[i].price[1]<<" "<<plc[i].price[2]<<" "<<plc[i].price[3]<<endl;
        }
        printf("****************\n");
    }
    return 0;
}
