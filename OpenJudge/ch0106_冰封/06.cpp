
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int main(void){
	bool aa[10002];
	long i,j;
	long a,b;
	long l,m;
	cin>>l>>m;
	for(i = 0; i <= l; i++){
		aa[i] = true;
	}
	for(i = 0; i < m; i++){
		cin>>a>>b;
		for(j = a; j <= b; j++){
			aa[j] = false;
		}
	}
	j = 0;
	for(i = 0; i <= l; i++){
		if(aa[i]){
			j++;
		}
	}
	cout<<j;
//	system("pause");
	return 0;
}