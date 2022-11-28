/*题目描述：
设有n个不全为负的整型元素存储在一维数组A[n]中，
它包含很多连续的子数组，例如数组A={1,-2,3,10,-4,7,2,-5}，
请设计一个时间上尽可能高效的算法，求数组A的子数组之和的最大值。
如数组A的最大的子数组为{3,10,-4,7,2}，故输出为该子数组的和18
*/
#include <iostream>
using namespace std;

//方法1：动态规划：时间复杂度：O(n)；空间复杂度：O(1)
int MaxSubarray1(int* A,int n){
	int sum=0,b=0;
	for(int i=0;i<n;i++){
		if(b>0)
			b+=A[i];
		else
			b=A[i];
		if(sum<b)
			sum=b;
	}
	return sum;
}

//方法2：分治
//时间复杂度公式为T(n)=2T(n/2)+n，因此时间复杂度=O(nlog2n)
//递归树高度=logn，每层空间辅助变量为常数，故空间复杂度=O(logn)
int max(int x,int y){
	return x>y?x:y;
}
int MaxSubarray2(int *A,int left,int right){
	if(left==right)//递归退出条件：只有一个元素
		return max(A[left],0);//返回元素值与0较大者

	int mid=(left+right)/2;//mid是数组的中间位置，分治开始

	//求(A[left],……,A[mid])中包含A[mid]子数组的最大值
	int Lmax=0;//Lmax是左边最大和
	int Lsum=0;//Lsum是累加和
	for(int i=mid;i>=left;i--){
		Lsum+=A[i];//从A[mid]往左累加
		if(Lsum>Lmax)
			Lmax=Lsum;
	}

	//求(A[mid+1],……,A[right])中包含A[mid+1]子数组的最大值
	int Rmax=0;//Rmax是右边最大和
	int Rsum=0;//Rsum是累加和
	for(int i=mid+1;i<=right;i++){
		Rsum+=A[i];//从A[mid+1]往右累加
		if(Rsum>Rmax)
			Rmax=Rsum;
	}

	return max(Lmax+Rmax,
		max(MaxSubarray2(A,left,mid),MaxSubarray2(A,mid+1,right)));
}

//方法3：暴力破解：假设最大的一段数组为A[i],…,A[j]，
//则对i=0~n-1和j=i~n-1遍历一遍，求出最大的Sum(i,j)即可。
//长度为n的数组有O(n^2)个子数组，求一个长n的数组和的时间复杂度=O(n)，
//故时间复杂度=O(n^3)，性能较差
//空间复杂度为O(1)

int main(){
	int A[]={1,-2,3,10,-4,7,2,-5};
	int n=8;
	cout<<MaxSubarray1(A,n)<<endl;
	cout<<MaxSubarray2(A,0,n-1)<<endl;
	return 0;
}
