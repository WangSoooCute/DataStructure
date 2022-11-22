/*题目描述：
设m+n个元素顺序存放在数组A[1…m+n]中，
前m个元素递增有序，后n个元素递增有序，
试设计一个在时间和空间两方面都尽可能高效的算法，
使得整个顺序表递增有序

方法1：
即经典的两有序表合并问题
时间复杂度：O(m+n)；空间复杂度：O(m+n)

方法2：
直接插入排序
时间复杂度：O(mn)；空间复杂度：O(1)
*/

#include<iostream>
#define M 3
#define N 2

using namespace std;

void merge(int *A){
	int B[M+N+1]={0};
	int k3=1;
	int k1=1,k2=M+1;
	while(k1<=M && k2<=M+N){
		B[k3++]=A[k1]<A[k2]?A[k1++]:A[k2++];
	}
	if(k1==M+1){
		while(k2<=M+N)
			B[k3++]=A[k2++];
	}else{
		while(k1<=M)
			B[k3++]=A[k1++];
	}
	for(int i=1;i<=M+N;i++)
		A[i]=B[i];
}

int main(){
	int A[M+N+1]={0,2,6,8,4,7};
	merge(A);
	for(int i=1;i<=M+N;i++){
		cout<<A[i]<<endl;
	}
}
