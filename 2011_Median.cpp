/*题目描述（2011年统考真题）：
一个长度为L（L≥1）的升序序列S，处在第L/2（向上取整）个位置的数称为S的中位数。
例如，若序列S1=（11，13，15，17，19），则S的中位数是15。
两个序列的中位数是含它们所有元素的升序序列的中位数。
例如，若S2=（2，4，6，8，20），则S1和S2的中位数是11。
现在有两个等长升序序列A和B，试设计一个在时间和空间两方面都尽可能高效的算法，
找出两个序列A和B的中位数。

时间复杂度：O(logn)；空间复杂度：O(1)
*/
#include <iostream>
#define L 5

using namespace std;

int Median(int*S1,int*S2){
	int start1=1,end1=L;
	int start2=1,end2=L;
	while(start1!=end1){//两集合长度始终相等
		int m1=(start1+end1)/2;
		int m2=(start2+end2)/2;
		if(S1[m1]==S2[m2]){
			return S1[m1];
		}			
		else if(S1[m1]<S2[m2]){
			if((start1+end1)%2==0){
				start1=m1;
				end2=m2;
			}
			else{
				start1=m1+1;
				end2=m2;
			}
		}
		else{
			if((start1+end1)%2==0){
				start2=m2;
				end1=m1;
			}
			else{
				start2=m2+1;
				end1=m1;
			}
		}
	}
	return S1[start1]<S2[start2]?S1[start1]:S2[start2];
}

int main(){
	int S1[L+1]={0};
	int S2[L+1]={0};
	for(int i=1;i<=L;i++)
		cin>>S1[i];
	for(int i=1;i<=L;i++)
		cin>>S2[i];
	cout<<Median(S1,S2)<<endl;
	return 0;
}
//一组输入：11 13 15 17 19 2 4 6 8 20