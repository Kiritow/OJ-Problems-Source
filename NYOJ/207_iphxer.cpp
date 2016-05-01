 
#include<iostream>
#include<hash_map>
//#include"iphxer_h.h"
#include<string>
#include<cstring>
#include<cstdio>
#include<map>

using namespace std;
#define maxsize 50100
int rank1[maxsize];//相对于根元素的权值0：同类，1：x吃father[x],2表示被father[x] 吃
int father[maxsize];
void initU(int n){
	for(int i=0;i<n;i++){
		father[i]=i;
		rank1[i]=0;
	}
}
int Find(int x){
	if(father[x]==x)return x;
	int t=father[x];//保存更新前的father位置，用来更新子rank
	father[x]=Find(father[x]);
	rank1[x]=(rank1[t]+rank1[x])%3;//计算相对于根节点的rank值
	return father[x];
}
//把y合并到x中，关系为d
void Union(int x,int y,int d)
{
	int xf=Find(x);
	int yf=Find(y);
	father[xf]=yf;//合并到y上
	rank1[xf]=(rank1[y]-rank1[x]+3+d)%3;	
}

int main()
{
	 
	int i,n,m;
	int d,x,y,xf,yf;
	int sum=0;
	scanf("%d%d",&n,&m);
	initU(n);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&d,&x,&y);
		if(x>n||y>n||(d==2&&x==y))
			++sum;
		else{
			xf=Find(x);
			yf=Find(y);
			if(xf==yf){
				if((rank1[x]-rank1[y]+3)%3!=d-1)
					sum++;
			}else{
				Union(x,y,d-1);
			}
		}
	}
	cout<<sum<<endl;
}
        
