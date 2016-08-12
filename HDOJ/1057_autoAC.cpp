#include <iostream>
using namespace std;
const int Dir[][2]={{-1,0},{1,0},{0,-1},{0,1}};
const char density[]=".!X#";
int D[16];
int Map[20][20],tmp[20][20];
int main()
{
    int T,day,i,j,k,d,x,y,index;
    cin>>T;
    for(int t=1;t<=T;++t)
    {
        cin>>day;
        for(i=0;i<16;++i) cin>>D[i];
        for(i=0;i<20;++i)
            for(j=0;j<20;++j)
                cin>>Map[i][j];
        for(k=0;k<day;++k)
        {
            for(i=0;i<20;++i)
                for(j=0;j<20;++j)
                {
                    index=Map[i][j];
                    for(d=0;d<4;++d)
                    {
                        x = i+Dir[d][0];
                        y = j+Dir[d][1];
                        if(x>=0&&x<20&&y>=0&&y<20)
                            index += Map[x][y];
                    }
                    tmp[i][j] = Map[i][j]+D[index];
                    if(tmp[i][j]>3) tmp[i][j]=3;
                    else if(tmp[i][j]<0) tmp[i][j]=0;
                }
            for(i=0;i<20;++i)
                for(j=0;j<20;++j)
                    Map[i][j] = tmp[i][j];
        }
        for(i=0;i<20;++i)
        {
            for(j=0;j<20;++j)
                cout<<density[Map[i][j]];
            cout<<endl;
        }
        if(t<T)cout<<endl;
    }
    return 0;
}
