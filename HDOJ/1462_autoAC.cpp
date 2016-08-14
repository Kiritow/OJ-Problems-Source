#include<iostream>
using namespace std;
int main()
{
    char c1[10],c2[10],c3[10],c4[10];
    int xy=0;
    int sum;
    while(cin>>c1)
    {
        int i,j,r1,r2,cc1,cc2,k,v,m;
        if(strcmp(c1,"#")==0)
            break;
            if(xy)
            cout<<endl;
        int flag1=0;
        int flag2=0;
        cin>>c2>>c3>>c4;
            int len1=strlen(c1);
            int len2=strlen(c2);
            int len3=strlen(c3);
            int len4=strlen(c4);
            for(i=0;i<len1;i++)
            {
                for(j=0;j<len2;j++)
                {
                    if(c1[i]==c2[j])
                    {
                        r1=j;
                        cc1=i;
                        flag1=1;
                        break;
                    }
                }
                if(flag1)
                {
                    break;
                }
            }
            for(i=0;i<len3;i++)
            {
                for(j=0;j<len4;j++)
                {
                    if(c3[i]==c4[j])
                    {
                          r2=j;
                          cc2=i;
                          flag2=1;
                          break;
                    }
                }
                if(flag2)
                {
                    break;
                }
            }
            if(flag1==1&&flag2==1)
            {
                  if(r1>r2)
                  {
                      for(k=0;k<r1-r2;k++)
                      {
                          for(v=0;v<cc1;v++)
                              cout<<' ';
                          cout<<c2[k]<<endl;
                      }
                      sum=len1-cc1-1+3+cc2;
                      for(i=0;i<r2;i++)
                      {
                            for(v=0;v<cc1;v++)
                              cout<<' ';
                            cout<<c2[r1-r2+i];
                            for(j=0;j<sum;j++)
                                cout<<' ';
                            cout<<c4[i]<<endl;
                      }
                      cout<<c1<<"   "<<c3<<endl;
                      for(i=r1+1,k=r2+1;i<len2;i++,k++)
                      {
                           sum=len1-cc1+3+cc2-1;
                          for(v=0;v<cc1;v++)
                              cout<<' ';
                          cout<<c2[i];
                          if(k<len4)
                          {
                          for(j=0;j<sum;j++)
                                cout<<' ';
                          cout<<c4[k]<<endl;
                          }
                          else
                          {
                              cout<<endl;
                          }
                      }
                      for(i=k;i<len4;i++)
                      {
                          for(j=0;j<len1+3+cc2;j++)
                          {
                              cout<<' ';
                          }
                          cout<<c4[i]<<endl;
                      }
                  }
                  else
                  {
                       for(i=0;i<r2-r1;i++)
                       {
                           for(j=0;j<len1+3+cc2;j++)
                           {
                               cout<<' ';
                           }
                           cout<<c4[i]<<endl;
                       }
                       for(j=i,i=0;i<r1;i++,j++)
                       {
                           for( m=0;m<cc1;m++)
                               cout<<' ';
                           cout<<c2[i];
                            sum=len1-cc1+3+cc2-1;
                        for(k=0;k<sum;k++)
                        {
                            cout<<' ';
                        }
                           cout<<c4[j]<<endl;
                       }
                       cout<<c1<<"   "<<c3<<endl;
                       for(k=i+1,i=j+1;k<len2;k++,i++)
                       {
                          for( m=0;m<cc1;m++)
                               cout<<' ';
                          cout<<c2[k];
                          if(i<len4)
                          {
                              sum=len1-cc1+3+cc2-1;
                          for(m=0;m<sum;m++)
                          {
                              cout<<' ';
                          }
                          cout<<c4[i]<<endl;
                          }
                          else
                          {
                              cout<<endl;
                          }
                       }
                       for(;i<len4;i++)
                       {
                           for(k=0;k<len1+3+cc2;k++)
                               cout<<' ';
                           cout<<c4[i]<<endl;
                       }
                  }
            }
            else
            {
                cout<<"Unable to make two crosses"<<endl;
            }
            xy++;
    }
    return 0;
}
