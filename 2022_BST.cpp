#include<iostream>
#define MAX_SIZE 100
using namespace std;

typedef struct{
	int SqBiTNode[MAX_SIZE];
	int ElemNum;
}SqBiTree;

//返回值为0表示不是BST，返回值为1表示是BST
int IsBST(SqBiTree T){
	//如果最后一个叶结点是其双亲的左结点，则给其双亲添加一个右孩子，以方便后续操作
	if(T.ElemNum%2==0)
		T.SqBiTNode[T.ElemNum]=-1;

	//遍历每一个非叶结点，其数组下标从0开始，到T.ElemNum/2-1结束
	int n=T.ElemNum/2;
	for(int i=0;i<n;i++){
		if(T.SqBiTNode[i]==-1)//i处没有结点
			continue;
		if(T.SqBiTNode[2*i+1]!=-1 && T.SqBiTNode[2*i+1]>T.SqBiTNode[i])
			return 0;//左孩子存在，且比当前结点值更大
		if(T.SqBiTNode[2*i+2]!=-1 && T.SqBiTNode[2*i+2]<T.SqBiTNode[i])
			return 0;//右孩子存在，且比当前结点值更小
	}
	//当每一个非叶结点的左孩子都小于其值、右孩子都大于其值时，循环全部结束
	return 1;
}

//方法2：val代表比最小值还小的值
bool IsBST2(SqBiTree T, int i, int val){
	if (i<T.ElemNum && T.SqBiTNode[i]!=-1){
		if(!IsBST2(T,2*i+1,val))
			return false;
		if(T.SqBiTNode[i]<=val)
			return false;
		if(!IsBST2(T,2*i+2,T.SqBiTNode[i]))
			return false;
	}
	return true;
}

//方法3：val代表比最小值还小的值
bool IsBST3(SqBiTree T){
	int* pmin=(int*)malloc(sizeof(int)*(T.ElemNum));//子树中的最小值
	int* pmax=(int*)malloc(sizeof(int)*(T.ElemNum));//子树中的最大值
	for(int i=0;i<T.ElemNum;i++)
		pmin[i]=pmax[i]=T.SqBiTNode[i];//辅助数组初始化
	for(int i=T.ElemNum-1;i>0;i--){
		if (T.SqBiTNode[i]!=-1){
			int j=(i-1)/2;//双亲
			if(i%2==1 && T.SqBiTNode[j]>pmax[i])//为左孩子
				pmin[j]=pmin[i];
			else if(i%2==0 && T.SqBiTNode[j]<pmax[i])//为右孩子
				pmax[j]=pmax[i];
			else
				return false;
		}
	}
	return true;
}

int main(){
	SqBiTree T={{40,25,60,-1,30,-1,80,-1,-1,27},10};
	cout<<IsBST(T)<<endl;
	cout<<IsBST2(T,0,-1)<<endl;
	cout<<IsBST3(T)<<endl;
	return 0;
}
/*其他输入：
SqBiTree T={{40,50,60,-1,30,-1,-1,-1,-1,-1,35},11};
*/