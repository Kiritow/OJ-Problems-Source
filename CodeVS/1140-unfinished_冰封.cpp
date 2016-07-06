#include <stdio.h>
#include <string.h>
/*
 Jam是个喜欢标新立异的科学怪人。他不使用阿拉伯数字计数，而是使用小写英文字母计数，他觉得这样做，会使世界更加丰富多彩。
 在他的计数法中，每个数字的位数都是相同的（使用相同个数的字母）英文字母按原先的顺序，排在前面的字母小于排在它后面的字母。
 我们把这样的“数字”称为Jam数字。在Jam数字中，每个字母互不相同，而且从左到右是严格递增的。
 每次，Jam还指定使用字母的范围，例如，从2到10，表示只能使用{b,c,d,e,f,g,h,i,j}这些字母。
 如果再规定位数为5，那么，紧接在Jam数字“bdfij”之后的数字应该是“bdghi”。
 （如果我们用U、V依次表示Jam数字“bdfij”与“bdghi”，则U<V< span>，且不存在Jam数字P，使U<P<V< span>）。
 你的任务是：
 对于从文件读入的一个Jam数字，按顺序输出紧接在后面的5个Jam数字，如果后面没有那么多Jam数字，那么有几个就输出几个。
*/

char a[100];
char fro;
int size;
size_t len;

bool dfs(size_t idx) {
	if(a[idx] >= fro + size - len + idx) {
		printf("a[idx] >= fro + size.\n");
		return dfs(idx - 1);
	}
	a[idx]++;
	for(size_t i = idx; i < len; i++){
		a[i] = (char) (a[i - 1] + 1);
		if(a[i] >= fro + size){
			return dfs(idx - 1);
		}
	}
	return true;
}
/*for(size_t i = len - 1; i >= 0; i--){
if(a[i] >= fro + size){
//
}
}*/
int main(int argc, char** argv){
	int s, t, w;
	scanf("%i%i%i", &s, &t, &w);
	scanf("%s", a);
	size = t - s;
	len = strlen(a);
	fro = (char) ('a' - 1 + s);

	for(int i = 0; i < 5 && dfs(len - 1); i++) {
		printf("%s\n", a);
	}
//	printf("%c", fro);
//	while(1);
	return 0;
}

