/*题目描述：
在数组中，某个数字减去它右边的数字得到一个数对之差。
求所有数对之差的最大值。如在数组{2,4,1,16,7,5,11,9}中，
数对之差的最大值是11，是16减去5的结果
*/
#include <iostream>
using namespace std;

//方法1：动态规划法：时间复杂度：O(n)
int MaxDifference1(int *numbers,int length){
	if(numbers==NULL || length<2)
		return 0;
	int max=numbers[0];
	int MaxDifference=max-numbers[1];
	for(int i=2;i<length;i++){
		if(numbers[i-1]>max)
			max=numbers[i-1];
		//CurrentDifference表示以数组中第i个数字为减数的所有主队之差的最大值
		int CurrentDifference=max-numbers[i];
		if(CurrentDifference>MaxDifference)
			MaxDifference=CurrentDifference;
	}
	return MaxDifference;
}

//方法2：分治法：时间复杂度：O(n)
//时间复杂度用递归公式表示为T(n)=2T(n/2)+O(1)
int MaxDifferenceCore(int *start,int *end,int *max,int *min){
	if(start==end){
		*max=*min=*start;
		return 0;
	}

	int *mid=start+(end-start)/2;
	int maxL,minL;
	int diffL=MaxDifferenceCore(start,mid,&maxL,&minL);
	int maxR,minR;
	int diffR=MaxDifferenceCore(mid+1,end,&maxR,&minR);

	*max=maxL>maxR?maxL:maxR;
	*min=minL<minR?minL:minR;

	int crossDiff=maxL-minR;
	int maxDiff=(diffL>diffR)?diffL:diffR;
	maxDiff=(maxDiff>crossDiff)?maxDiff:crossDiff;
	return maxDiff;
}
int MaxDifference2(int *numbers,int length){
	if (numbers==NULL)
		return 0;
	int max,min;
	return MaxDifferenceCore(numbers,numbers+length-1,&max,&min);
}

//方法3：暴力法：
//让每个数字逐个减去它右边的所有数字，并通过比较得到数对之差的最大值
//时间复杂度：O(n^2)

int main(){
	int numbers[]={2,4,1,16,7,5,11,9};
	cout<<MaxDifference1(numbers,8)<<endl;
	cout<<MaxDifference2(numbers,8)<<endl;
	return 0;
}