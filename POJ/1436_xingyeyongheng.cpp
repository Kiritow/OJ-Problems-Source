/*
思路:对y轴进行建树,对每条线段按横轴从小到大排序,从第1条线段开始查询并更新
查询该条线段所表示的区间内不同颜色数量(即可见线段数)并且记录可见线段,然后更新该区间颜色 
最后暴力求两两可见线段数量
但是注意:0,4,1 和 0,2,2 和 3,4,2这三条线段覆盖的结果是区间0~4通过线段树查找可见线段是两条,其实是3条(2~3可见另一条)
可以把查询更新的区间*2,比如上面数据变成0,8,1 和 0,4,2 和 6,8,2则4~6之间可见一条线段 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=8000+10;
int color[MAX*2<<2];//区间可见线段编号(颜色种类) 
bool mark[MAX][MAX];//记录第i条线段和第j条线段可见

struct edge{
	int y1,y2,x,id;
	edge(){}
	edge(int Y1,int Y2,int X,int ID):y1(Y1),y2(Y2),x(X),id(ID){}
	bool operator <(const edge &a)const {
		return x<a.x;
	}
}s[MAX];

void Upchild(int n){
	if(color[n]){
		color[n<<1]=color[n<<1|1]=color[n];
		color[n]=0;
	}
}

void Update(int L,int R,int c,int n,int left,int right){
	if(L<=left && right<=R){color[n]=c;return;}
	Upchild(n);
	int mid=left+right>>1;
	if(L<=mid)Update(L,R,c,n<<1,left,mid);
	if(R>mid)Update(L,R,c,n<<1|1,mid+1,right);
} 

void Query(int L,int R,int id,int n,int left,int right){
	if(color[n]){mark[id][color[n]]=true;return;}
	if(left == right)return;
	int mid=left+right>>1;
	if(L<=mid)Query(L,R,id,n<<1,left,mid);
	if(R>mid)Query(L,R,id,n<<1|1,mid+1,right);
}

int main(){
	int t,n,y1,y2,x;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&y1,&y2,&x);
			s[i]=edge(y1,y2,x,i);
		}
		sort(s+1,s+n+1);
		memset(color,0,sizeof color);
		memset(mark,false,sizeof mark);
		for(int i=1;i<=n;++i){
			Query(s[i].y1*2,s[i].y2*2,s[i].id,1,0,MAX*2);//先查询这条线段左边可见的线段
			Update(s[i].y1*2,s[i].y2*2,s[i].id,1,0,MAX*2);//更新该区间可见线段,放在Query里更新了 
		}
		int ans=0;
		for(int i=1;i<=n;++i){//暴力统计结果 
			for(int j=1;j<=n;++j){
				if(mark[i][j])
				for(int k=1;k<=n;++k){
					if(mark[i][k] && mark[j][k])++ans;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
