#include<iostream>
void writesel(int n,int max,char now[])
{
    char thenew='a'+n-1;int space,i,j;
    char * p;
    for(i=0;i<n;i++)
    {
        if(n!=1)
        {
            for(space=0;space<2*(n-1);space++)std::cout<<" ";
            if(i==0)std::cout<<"if "<<now[n-2]<<" < "<<thenew<<" then"<<std::endl;
            else if(i==n-1)std::cout<<"else"<<std::endl;
            else std::cout<<"else if "<<now[n-2-i]<<" < "<<thenew<<" then"<<std::endl;
        }
        p=new char[n];
        for(j=0;j<n;j++)
        {
            if(j==n-i-1)p[j]=thenew;
            else if(j<n-i-1)p[j]=now[j];
            else p[j]=now[j-1];
        }
        if(n==max)
        {
            for(space=0;space<2*(n-1);space++)std::cout<<" ";
            std::cout<<"  writeln(";
            for(j=0;j<n;j++)
            {
                std::cout<<p[j];
                if((n-j)!=1)std::cout<<',';
            }
            std::cout<<")"<<std::endl;
        }
        else writesel(n+1,max,p);
    }
}
int main()
{
    int n,i;
    std::cin>>n;
    char *p=new char[n];
    std::cout<<"program sort(input,output);"<<std::endl;
    std::cout<<"var"<<std::endl;
    for(i=0;i<n;i++)
    {
        p[i]='a'+i;
        std::cout<<p[i];
        if((n-i)!=1)std::cout<<',';
    }
    std::cout<<" : integer;"<<std::endl;
    std::cout<<"begin"<<std::endl;
    std::cout<<"  readln(";
    for(i=0;i<n;i++)
    {
        p[i]='a'+i;
        std::cout<<p[i];
        if((n-i)!=1)std::cout<<',';
    }
    std::cout<<");"<<std::endl;
    writesel(1,n,"");
    std::cout<<"end."<<std::endl;
    return 0;
}
