/*题目描述：
已知线性表(a1,a2,a3,…,a_n)存放在一维数组A中。
试设计一个在时间和空间两方面都尽可能高效的算法，
将所有奇数号元素移到所有偶数号元素前，
并且不得改变奇数号（或偶数号）元素之间的相对顺序

时间复杂度：共进行了n/2次交换，每次交换的元素个数从1~n/2，
故时间复杂度=O(n^2)，因n^2前的系数很小，实际效率是很高的；
空间复杂度：O(n)
*/
#include <iostream>
using namespace std;
typedef int ElemType;

void BubbleSwap(ElemType *A,int n){
	int i=(n%2==0)?n-1:n;
	int v=1;//v为“块”的大小
	while(i>1){//假设数组从1开始存放。当i=1时，气泡浮出水面
		ElemType temp=A[i-1];//将“块”前的偶数号元素暂存
		for(int j=i-1;j<i+v-1;j++)//将大小为v的“块”整体前移
			A[j]=A[j+1];
		A[i+v-1]=temp;//暂存的奇数号元素复制到平移后空出的位置
		i=i-2;v++;//指针向前，块大小增1
	}
}

int main(){
	ElemType A[]={0,1,2,3,4,5,6,7};
	int n=7;
	BubbleSwap(A,n);
	for(int i=1;i<=n;i++)
		cout<<A[i]<<endl;
	return 0;
}