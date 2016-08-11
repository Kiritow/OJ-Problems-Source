#include <stdio.h>
#include <queue>
using namespace std;

// 长度限制
const int size = 50;

// 房间类
typedef struct room {
	bool north;
	bool south;
	bool east;
	bool west;
	room(int s){
		north = false;
		south = false;
		east = false;
		west = false;
		switch (s){
			case 1:
				west = true;
				break;
			case 2:
				north = true;
				break;
			case 3:
				west = true;
				north = true;
				break;
			case 4:
				east = true;
				break;
			case 5:
				west = true;
				east = true;
				break;
			case 6:
				north = true;
				east = true;
				break;
			case 7:
				west = true;
				east = true;
				north = true;
				break;
			case 8:
				south = true;
				break;
			case 9:
				west = true;
				south = true;
				break;
			case 10:
				south = true;
				north = true;
				break;
			case 11:
				west = true;
				south = true;
				north = true;
				break;
			case 12:
				east = true;
				south = true;
				break;
			case 13:
				west = true;
				east = true;
				south = true;
				break;
			case 14:
				east = true;
				south = true;
				north = true;
				break;
			case 15:
				west = true;
				east = true;
				south = true;
				north = true;
				break;
			default:
				break;
		}
	}
	room(){
		north = false;
		south = false;
		east = false;
		west = false;
	}
} room ;

// 坐标类
typedef struct poi{
	int x;
	int y;
} poi;

int main(int argc,char* argv[]){
	room a[size][size];
	bool b[size][size];
	// x是横坐标, y是纵坐标
	int y, x;
	scanf("%i %i", &x, &y);
	for(int i = 0; i < x; i++)
		for(int j = 0; j < y; j++)
			b[i][j] = false;

	for(int i = 0; i < x; i++)
		for(int j = 0; j < y; j++){
			int s;
			scanf("%i", &s);
			a[i][j] = room(s);
		}
//	for(int i = 0; i < x; i++)
//		for(int j = 0; j < y; j++){
//			printf("when x = %i, y = %i, north = %i, south = %i, west = %i, east = %i\n",
//			i, j, a[i][j].north ? 1 : 0, a[i][j].south ? 1 : 0, a[i][j].west ? 1 : 0, a[i][j].east ? 1 : 0);
//		}
//	return 0;
	int max = 0;
	int cnt = 0;

	queue<poi> q;
	while(!q.empty()) q.pop();

	while(true){
		int this_max = 1;

		int loop = 0;
		for(int i = 0; i < x; i++) {
			for(int j = 0; j < y; j++) {
				if(b[i][j]) loop++;
			}
		}
		if(loop >= y * x) break;
		cnt++;
		bool loop_ = true;
		if(q.empty()) {
//			printf("start to find a new room.\n");
			for(int i = 0; i < x && loop_; i++)
				for(int j = 0; j < y; j++)
					if(!b[i][j]) {
						b[i][j] = true;
						poi p;p.y = j;p.x = i;q.push(p);
//						printf("p.x = %i, p.y = %i\n", p.x, p.y);
						loop_ = false;
						break;
					}
		}

		while(!q.empty()){
			poi p = q.front();
			q.pop();
			// 按理说不需要判断越界。因为边缘有墙。
			if( !a[p.x][p.y].east && !b[p.x][p.y+1]){
				p.y++;
//				printf("p.x = %i, p.y = %i\n", p.x, p.y);
				b[p.x][p.y] = true;
				this_max++;
				q.push(p);
				p.y--;
			}
			if( !a[p.x][p.y].west && !b[p.x][p.y-1]){
				p.y--;
//				printf("p.x = %i, p.y = %i\n", p.x, p.y);
				b[p.x][p.y] = true;
				this_max++;
				q.push(p);
				p.y++;
			}
			if( !a[p.x][p.y].south && !b[p.x+1][p.y]){
				p.x++;
//				printf("p.x = %i, p.y = %i\n", p.x, p.y);
				b[p.x][p.y] = true;
				this_max++;
				q.push(p);
				p.x--;
			}
			if( !a[p.x][p.y].north && !b[p.x-1][p.y]){
				p.x--;
//				printf("p.x = %i, p.y = %i\n", p.x, p.y);
				b[p.x][p.y] = true;
				this_max++;
				q.push(p);
//				p.x++;
			}
		}

		if(this_max > max) max = this_max;
	}

	printf("%i\n%i", cnt, max);
	return 0;
}
/*
 * 测试数据
4
7
11 6 11 6 3 10 6
7 9 6 13 5 15 5
1 10 12 7 13 7 5
13 11 10 8 10 12 13
 * 答案
5 9
 */
