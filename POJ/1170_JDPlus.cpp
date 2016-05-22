#include <stdio.h>
#include <string.h>
#include <limits.h>

int code[6];       //商品代码
int num[6];        //商品数量
int price[6];      //商品价格
int special_num[100][6]; //促销项目各个商品数量
int special_cnt[100];    //促销项目的商品数量
int special_price[100];  //促销项目价格
int basket;              
int special;
int dp[6][6][6][6][6];

int Decode (int c){
	int i;
	for (i=1; i<=5; ++i){
		if (code[i] == c)
			break;
	}
	return i;
}

void Init(){
	int i;
	int j;
	int c;
	int k;
	int index;

	scanf ("%d", &basket);
	for (i=1; i<=basket; ++i){
		scanf ("%d%d%d", &code[i], &num[i], &price[i]);
	}
	scanf ("%d", &special);
	for (i=1; i<=special; ++i){
		scanf ("%d", &special_cnt[i]);
		for (j=1; j<=special_cnt[i]; ++j){
			scanf ("%d%d", &c, &k);
			index = Decode (c);
			special_num[i][index] = k;
		}
		scanf ("%d", &special_price[i]);
	}
}

void Lowest_Price (){
	int i1, i2, i3, i4, i5;
	int i;
	int tmp1, tmp2;
	memset (dp, -1, sizeof(dp));
	dp[0][0][0][0][0] = 0;
	for (i1=0; i1<=num[1]; ++i1){
		for (i2=0; i2<=num[2]; ++i2){
			for (i3=0; i3<=num[3]; ++i3){
				for (i4=0; i4<=num[4]; ++i4){
					for (i5=0; i5<=num[5]; ++i5){
						tmp1 = INT_MAX;
						tmp2 = INT_MAX;
						for (i=1; i<=special; ++i){
							if (i1 >= special_num[i][1] && 
								i2 >= special_num[i][2] &&
								i3 >= special_num[i][3] &&
								i4 >= special_num[i][4] &&
								i5 >= special_num[i][5]){
								tmp2 = dp[i1-special_num[i][1]]
										 [i2-special_num[i][2]]
										 [i3-special_num[i][3]]
										 [i4-special_num[i][4]]
										 [i5-special_num[i][5]] + special_price[i];
							if (tmp1 > tmp2)
								tmp1 = tmp2;
							}
						}
						if (tmp1 != INT_MAX){
							dp[i1][i2][i3][i4][i5] = tmp1;
						}
						else{
							dp[i1][i2][i3][i4][i5] = i1 * price[1] + i2 * price[2]
									+ i3 * price[3] + i4 * price[4] + i5 * price[5];
						}
					}
				}
			}
		}
	}
	printf ("%d\n", dp[num[1]][num[2]][num[3]][num[4]][num[5]]);
}

int main(void){
	Init ();
	Lowest_Price ();

	return 0;
}
