#include <iostream>
#include <cstring>
#define MAX 50+3
using namespace std;
typedef char Elem_Type;
typedef struct BiTree
{
	Elem_Type data;//数据
	struct BiTree *Lchild;//左孩子
	struct BiTree *Rchild;//右孩子
}BiTree;	  //要查找的元素  查找的地方	数组的长度
int Search_Num(Elem_Type num,Elem_Type *array,int len)
{
	for(int i=0; i<len; i++)
	   if(array[i] == num)
		 return i;
	//return -1;//没有找到
}						   //中序遍历	后序遍历	 中序长度
BiTree *Resume_BiTree(Elem_Type *center,Elem_Type *back,int len)
{
	if(len <= 0)
	  return NULL;
	BiTree *temp = new BiTree;
	temp->data = *back;
	int index = Search_Num(*back,center,len);
	temp->Rchild = Resume_BiTree(center+index+1,back-1,len-index-1);
	temp->Lchild = Resume_BiTree(center,back-len+index,index);
	return temp;
}
void PreOrderTraverse(BiTree *root)//前序遍历
{
	if( root != NULL)
	{
		cout<<root->data;
		PreOrderTraverse(root->Lchild);
		PreOrderTraverse(root->Rchild);
	}
}
int main(void)
{
	Elem_Type *inorder  = new Elem_Type [MAX];//中序
	Elem_Type *postorde = new Elem_Type [MAX];//后序
	int t;cin>>t;
	while(t--)
	{
		cin>>inorder;cin>>postorde;
		BiTree *root =
		Resume_BiTree(inorder,postorde+strlen(postorde)-1,strlen(inorder));
		PreOrderTraverse(root);
		cout<<endl;
	}
	return 0;
}
