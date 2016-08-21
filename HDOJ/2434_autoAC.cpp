#include <iostream>
#include <stdio.h>
#include <string.h>
#include <set>
#include <string>
#include <queue>
#define R 0
#define G 1
#define B 2
#define Y 3
#define MSIT multiset<Card>::iterator
using namespace std;
void re() { 
    re();
}
struct Card {
    int score;
    string id;
    bool effect;
    bool operator<(Card o) const {
        if (score == o.score) {
            return id < o.id;
        } else {
            return score > o.score;
        }
    }
    bool fix(Card o) {
        if (o.id == "WC") {
            return true;
        }
        if (id[0] == o.id[0] || id[1] == o.id[1]) {
            return true;
        } else {
            return false;
        }
    }
};
queue<Card> stock;
Card top;
int n;
int curPlayer;
int direction;
struct Prople {
    multiset<Card> hand;
    int uno;
    int color;
    bool draw() {
        if (stock.empty()) {
            return false;
        } else {
            Card t = stock.front();
            stock.pop();
            hand.insert(t);
            return true;
        }
    }
    bool isWin() {
        if (hand.size() == 0) {
            return true;
        } else if (hand.size() == 1) {
            uno++;
            return false;
        } else {
            return false;
        }
    }
    char getColor() {
        char ret;
        switch (color) {
        case R:
            ret = 'R';
            break;
        case G:
            ret = 'G';
            break;
        case B:
            ret = 'B';
            break;
        case Y:
            ret = 'Y';
            break;
        }
        color = (color + 1) % 4;
        return ret;
    }
    bool doIt() {
        MSIT wf = hand.end();
        for (MSIT it = hand.begin(); it != hand.end(); it++) {
            if (it->id == "WF") {
                wf = it;
                continue;
            }
            if (top.fix(*it)) {
                top = *it;
                if (top.id[0] == 'W') {
                    top.id[0] = getColor();
                }
                hand.erase(it);
                return true;
            }
        }
        if (wf != hand.end()) {
            top = *wf;
            top.id[0] = getColor();
            hand.erase(wf);
            return true;
        } else {
            return false;
        }
    }
    int GetScore() {
        int sum = 0;
        for (MSIT it = hand.begin(); it != hand.end(); it++) {
            sum += it->score;
        }
        return sum;
    }
} player[12];
int nextPlayer(int cur, int direction) {
    return (cur + n + direction) % n;
}
void init() {
    while (stock.empty() == false) {
        stock.pop();
    }
    for (int i = 0; i < 12; i++) {
        player[i].hand.clear();
        player[i].uno = 0;
        player[i].color = 0;
    }
}
bool checkTop() {
    if (top.id[1] == 'F' && top.effect) {
        top.effect = false;
        if (player[curPlayer].draw() == false) {
            return false;
        }
        if (player[curPlayer].draw() == false) {
            return false;
        }
        if (player[curPlayer].draw() == false) {
            return false;
        }
        if (player[curPlayer].draw() == false) {
            return false;
        }
        curPlayer = nextPlayer(curPlayer, direction);
    } else if (top.id[1] == 'D' && top.effect) {
        top.effect = false;
        if (player[curPlayer].draw() == false) {
            return false;
        }
        if (player[curPlayer].draw() == false) {
            return false;
        }
        curPlayer = nextPlayer(curPlayer, direction);
    } else if (top.id[1] == 'S' && top.effect) {
        top.effect = false;
        curPlayer = nextPlayer(curPlayer, direction);
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        init();
        int i;
        for (i = 0; i < 108; i++) {
            Card temp;
            cin >> temp.id;
            temp.effect = true;
            if (temp.id[0] == 'W') {
                temp.score = 50;
            } else if ('0' <= temp.id[1] && temp.id[1] <= '9') {
                temp.score = temp.id[1] - '0';
            } else {
                temp.score = 20;
            }
            stock.push(temp);
        }
        for (int j = 0; j < n; j++) {
            for (i = 0; i < 7; i++) {
                player[j].draw();
            }
        }
        if (top.id[0] == 'W') {
            re();
        }
        top = stock.front();
        stock.pop();
        curPlayer = 1;
        direction = 1;
        if (top.id[1] == 'R' && top.effect) {
            curPlayer = n - 1;
            direction *= -1;
            top.effect = false;
        }
        while (true) {
            if (checkTop() == false) {
                break;
            }
            if (player[curPlayer].doIt() == false) {
                if (player[curPlayer].draw() == false) {
                    break;
                }
            }
            if (top.id[1] == 'R' && top.effect) {
                top.effect = false;
                direction *= -1;
            }
            if (player[curPlayer].isWin()) {
                curPlayer = nextPlayer(curPlayer, direction);
                checkTop();
                break;
            }
            curPlayer = nextPlayer(curPlayer, direction);
        }
        for (i = 0; i < n - 1; i++) {
            printf("%d ", player[i].GetScore());
        }
        printf("%d\n", player[i].GetScore());
        for (i = 0; i < n - 1; i++) {
            printf("%d ", player[i].uno);
        }
        printf("%d\n", player[i].uno);
    }
    return 0;
}
