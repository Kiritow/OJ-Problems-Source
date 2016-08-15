#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <map>
#include <list>
#include <queue>
using namespace std;
map<char,int> mma;
int main(){
    mma['A'] = 14;
    mma['J'] = 11;
    mma['Q'] = 12;
    mma['K'] = 13;
    for(char i = '2' ; i <='9'; i++)    mma[i] = i-'0';
    char nuse,card;
    while(cin >> nuse && nuse != '#'){
        vector<int> tmp[2];
        queue<int> player[2];
        list<int> stk;
        cin >> card;
        tmp[1].push_back(mma[card]);
        for(int i = 2; i <= 52; i++){
            cin >> nuse >> card;
            tmp[i%2].push_back(mma[card]);
        }
        for(int i = 0; i < 2; i++){
            while(tmp[i].size()){
                player[i].push(tmp[i][tmp[i].size()-1]);
                tmp[i].pop_back();
            }
        }
      int turn = 1,winner;
       while(1){
            int times;
            bool flag = 0;
            if(stk.size()==0) times = 0;
            else if(stk.back()>=11) times = stk.back()-10;
            else times = 0;
            int cnt;
            if(times == 0) cnt = 1;
            else cnt = times;
            for(int i = 0; i < cnt; i++){
                if(player[turn].size()==0){
                    winner = !turn;
                    flag = 1;
                    break;
                }else{
                    stk.push_back(player[turn].front());
                    player[turn].pop();
                    if(stk.back()>=11) break;
                 }
            }
            if(flag)    break;
            if(times && stk.back()<=10){
                while(stk.size()){
                    player[!turn].push(stk.front());
                    stk.pop_front();
                }
            }
        turn = !turn;
        }
        printf("%d%3d\n",winner+1,player[winner].size());
    }
    return 0;
}
