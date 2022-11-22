/*题目描述：
将一个数组最开始的若干元素搬到数组的末尾，称之为数组的旋转。
输入一个已排好序数组的一个旋转，求该旋转数组的最小元素。
如，数组｛3，4，5，1，2｝为有序数组｛1，2，3，4，5｝的一个旋转数组，该数组的最小值为1

时间复杂度：O(logn)；空间复杂度：O(1)
*/
#include <iostream>
using namespace std;

int Min(int *numbers,int length){
	int index1=0,index2=length-1;
	//要先从后向前找到和第一个元素不相等的元素再开始二分
	while(numbers[index2]==numbers[0] && index2>0)
		index2--;
	if(numbers[index2]>=numbers[0])//即后一部分没了
		return numbers[0];

	while(index1+1<index2){//两部分至少各保留一个元素
		int mid=(index1+index2)>>1;
		if(numbers[mid]>=numbers[index1]){
			index1=mid;
		}
		else{
			index2=mid;
		}
	}
	return numbers[index2];
}

int main(){
	int length=5;
	int numbers[length]={3,4,5,1,2};
	cout<<Min(numbers,length)<<endl;
	return 0;
}
/*其他输入：
int numbers[5]={2,1,2,2,2};
int numbers[5]={2,2,2,2,2};
*/