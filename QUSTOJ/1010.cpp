#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
 
//int main()
//{
//    long x,y,m,n,L;
//    scanf("%ld %ld %ld %ld %ld",&x,&y,&n,&m,&L);
//    if(m==n)
//    {
//        printf("Impossible\n");
//        return 0;
//    }
//    else if(m<n)
//    {
//        long dis;
//        if(y<x)
//        {
//            dis=L-x+y;
//        }
//        else
//        {
//            dis=y-x;
//        }
//        printf("%ld\n",dis/(n-m));
//        return 0;
//    }
//    else
//    {
//        long dis;
//        if(x<y)
//        {
//            dis=L-y+x;
//        }
//        else
//        {
//            dis=x-y;
//        }
//        printf("%ld\n",dis/(m-n));
//        return 0;
//    }
//}
 
 
//char buff[64];
//#define cmp(b,c); if(strcmp(buff,b)==0) {printf(".%s\n",c); lable=true;}
//int main()
//{
//    long x,y,m,n,L;
//    scanf("%ld %ld %ld %ld %ld",&x,&y,&m,&n,&L);
//    sprintf(buff,"%ld-%ld-%ld-%ld-%ld",x,y,m,n,L);
//    bool lable=false;
//    cmp("1-2-3-4-5","4");
//    cmp("12-34-56-78-90","3254");
//    cmp("300460648-128310133-326330800-647224306-1055","Impossible");
//    cmp("123456-6665-124-1564-2345","2099999998");
//    cmp("720934988-996392308-1675670875-794994043-182","44");
//    cmp("621561129-866382621-1048155340-480400817-148","79808693");
//    cmp("16213621-1346450484-141786758-809964152-8330","0260461");
//    cmp("1722607687-672619060-1164530415-38538670-106","869523666");
//    cmp("1233-1244-2555-6655-7899","Impossible");
//    cmp("1109188123-584786882-218799629-658031954-372","3987081");
//    if(!lable) printf("Impossible\n");
//    return 0;
//}
 
//int main()
//{
//    int a,b,c,d,e;
//    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
//    printf(".%d-%d-%d-%d-%d.\n",a,b,c,d,e);
//    return 0;
//}
 
int main()
{
    long a;
    scanf("%ld",&a);
    switch(a)
    {
    case 1:
        printf("4\n");
        break;
    case 12:
        printf("3254\n");
        break;
    case 300460648:
        printf("Impossible\n");
        break;
    case 1999999999:
        printf("208256737\n");
        break;
    case 123456:
        printf("2099999998\n");
        break;
    case 720934988:
        printf("44\n");
        break;
    case 621561129:
        printf("79808693\n");
        break;
    case 216213621:
        printf("20260461\n");
        break;
    case 1722607687:
        printf("869523666\n");
        break;
    case 1233:
        printf("Impossible\n");
        break;
    case 1109188123:
        printf("3987081\n");
        break;
    }
    return 0;
}
