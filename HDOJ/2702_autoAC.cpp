#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <stack>
using namespace std;
int R,C;
char Map[10][10];
int Move2[6][2] = {{-1,-1},{-1,0},{0,-1},{0,1},{1,-1},{1,0}};
int Move1[6][2] = {{-1,0},{-1,1},{0,-1},{0,1},{1,0},{1,1}};
char Path[20];
bool bVisited[10][10];
int ileft,iright;
int cnum,pos;
inline bool InBoundary(int x,int y)
{
    if(x >= 0 && x<R && y>=0 && y<C+x%2)
        return true;
    return false;
}
bool Evaluate(int start,int n,int &value)
{
     stack<int> s1;
     stack<char> s2;
     int i = start;
     int t = 0;
      t = Path[i]-'0';  i++;
      if(isdigit(Path[i]))
      {
           if(t == 0)  return false;
       }
       while(isdigit(Path[i]))
       {
            t*=10; t+=Path[i]-'0';
            if(t >= 100)
                 return false;
             i++;
        }
    s1.push(t);
     while(1)
     {
             if(i > n-1)
             { 
                  if(!isdigit(Path[n-1])) return false;
                  break;
             }
             if(!isdigit(Path[i]))
             {
                 if(!s2.empty()) return false;
                 else     s2.push(Path[i]); 
                 i++;
             }
             else
             {
                 t = Path[i]-'0';  i++;
                 if(isdigit(Path[i]))
                 {
                    if(t == 0)
                       return false;
                 }
                 while(isdigit(Path[i]))
                 {
                     t*=10; t+=Path[i]-'0';
                     if(t >= 100)
                       return false;
                     i++;
                 }
                    char op = s2.top();s2.pop();
                    int re = s1.top();s1.pop();
                    switch(op)
                    {
                              case '+':s1.push(re+t); break;    
                              case '-':s1.push(re-t);break;
                              case '*':s1.push(re*t);break;  
                              case '/': 
                                   if(t == 0 || re%t!=0)
                                     return false;
                                   s1.push(re/t);
                                   break;    
                    }
              }      
     }
     value = s1.top();
     return true;
}      
bool DFS(int i,int j,int index)
{
     if(index == cnum)
     { 
         Path[index] = 0;
         if(Evaluate(pos,index,iright) && iright == ileft)
               return true;
         else  return false;
     }
     if(Map[i][j] == '=')
     {
         if(!Evaluate(0,index-1,ileft))
               return false; 
         pos = index;
     }
     if(i%2==1)
     {
           for(int k = 0; k<6; k++)
           {
                 int x = Move2[k][0]+i; int y = Move2[k][1]+j;
                 if(InBoundary(x,y) && bVisited[x][y] == false)
                 {
                      bVisited[x][y] = true;
                      Path[index] = Map[x][y];
                      if(DFS(x,y,index+1))
                         return true;
                      bVisited[x][y] = false;
                 }
           }
     }
     else
     {
         for(int k = 0; k <6; k++)
         {
                 int x = Move1[k][0]+i; int y = Move1[k][1]+j;
                 if(InBoundary(x,y) && bVisited[x][y] == false)
                 {
                      bVisited[x][y] = true;
                      Path[index] = Map[x][y];
                      if(DFS(x,y,index+1))
                         return true;
                      bVisited[x][y] = false;
                 }
         }
     }
     return false;
}
int main()
{
    while(scanf("%d",&R)==1 && R!=0)
    {
         scanf("%d",&C);
         int i,j;
         cnum = C*R+R/2;
         getchar();
         for(i = 0; i<R; i++)
         {     
               if(i%2 == 0)
               {
               for(j = 0; j<C; j++)
                 { scanf(" %c",&Map[i][j]); bVisited[i][j] = false;}
               getchar();
               }
               else
               {
                   for(j = 0; j<=C; j++)
                   {scanf("%c",&Map[i][j]); bVisited[i][j] = false;getchar();}
               }
         }
         for(i = 0; i<R; i++)
         {
                      for(j = 0; j<C+i%2; j++)
                      {
                            if(isdigit(Map[i][j]))
                            {
                                bVisited[i][j] = true;
                                Path[0] = Map[i][j]; 
                                if(DFS(i,j,1)) goto PRINT;
                                bVisited[i][j] = false;
                            }
                      }
         }
 PRINT:        printf("%s\n",Path);
    }
    return 0;
}
