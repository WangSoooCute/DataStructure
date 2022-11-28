/*题目描述：
假设二叉树采用二叉链表存储结构，
设计一个算法求其指定的第k层（k>1，根是第1层）的叶子结点个数
*/
#include <iostream>
using namespace std;
typedef int ElemType;

typedef struct BTNode{
	ElemType data;//数据域
	BTNode *lchild,*rchild;//左、右孩子指针
}BTNode,*BiTree;

//方法1：用队列进行层次遍历
#define MaxSize 100//设置队列的最大容量
int LeafKLevel1(BTNode* root,int k){//root为根结点
	//声明队列
	BTNode* q[MaxSize];//队列最多容纳MaxSize-1个元素
	int end1=0;//end1为头指针，指向队头元素
	int end2=0;//end2为尾指针，指向队尾的后一个元素
	int sum=1;//叶子结点个数
	int deep=1;//初始化深度
	BTNode* lastNode=root;//记录当前层的最后一个结点
	BTNode* newlastNode=NULL;//记录下一层的最后一个结点

	q[end2++]=root;//根结点入队
	while(end1!=end2){//层次遍历，若队列不空则循环
		BTNode* t=q[end1++];//拿出队列中的头一个元素
		if(deep==k){//找到特定层，统计叶子结点个数
			while(end1!=end2){
				t=q[end1++];
				if(t->lchild==NULL && t->rchild==NULL)
					sum++;
			}
			break;
		}
		else{//没到特定层，层次遍历
			if(t->lchild!=NULL){//若非叶子结点把左结点入队
				q[end2++]=t->lchild;
				newlastNode=t->lchild;
			}//并设下一层的最后一个结点为该结点的左结点
			if(t->rchild!=NULL){//处理右结点
				q[end2++]=t->rchild;
				newlastNode=t->rchild;
			}
			if(t==lastNode){//若该结点为本层最后一个结点
				lastNode=newlastNode;
				deep++;//层数加1
			}
		}
	}
	return sum;
}

//方法2：
int n=0;
void Preorder(BiTree root,int deep,int k){
	if(deep<k){
		if (root->lchild!=NULL)//若左子树不空
			Preorder(root->lchild,deep+1,k);
		if (root->rchild!=NULL)//若右子树不空
			Preorder(root->rchild,deep+1,k);
	}
	else if(deep==k &&
		root->lchild==NULL && root->rchild==NULL)
		n++;
}
int LeafKLevel2(BiTree root,int k){
	Preorder(root,1,k);
	return 0;
}

int main(){
	BiTree root=(BTNode*)malloc(sizeof(BTNode));
	root->data=0;
	root->lchild=NULL;
	root->rchild=NULL;
	BTNode* T1=(BTNode*)malloc(sizeof(BTNode));
	T1->data=1;
	T1->lchild=NULL;
	T1->rchild=NULL;
	BTNode* T2=(BTNode*)malloc(sizeof(BTNode));
	T2->data=2;
	T2->lchild=NULL;
	T2->rchild=NULL;

	root->lchild=T1;
	root->rchild=T2;
	int k=2;

	cout<<LeafKLevel1(root,k)<<endl;
	LeafKLevel2(root,k);
	cout<<n<<endl;
	return 0;
}