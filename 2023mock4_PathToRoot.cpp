/*题目描述：
假设二叉树采用二叉链存储结构存储，
设计一个算法求出根结点到给定某结点之间的路径
*/
#include <iostream>
#define MaxSize 100
using namespace std;
typedef int ElemType;

typedef struct BTNode{
	ElemType data;//数据域
	BTNode *lchild,*rchild;//左、右孩子指针
}BTNode,*BiTree;

BTNode* CreateBiTree(){
    BTNode *T=NULL;
    ElemType data;
    cin>>data;
    if(data!=0){
        T=(BTNode *)malloc(sizeof(BTNode));
        T->data=data;
        T->lchild =CreateBiTree();
        T->rchild =CreateBiTree();
    }
    return T;
}

//方法：用栈进行后序遍历
int PathToRoot(BiTree b,BTNode* s){//root为根结点
	BTNode* st[MaxSize];
	int top=-1;
	do{
		while(b!=NULL){
			st[++top]=b;
			b=b->lchild;
		}
		BTNode* p=NULL;//p指向当前结点的前一个已访问结点
		int flag=1;//设置b的访问标记为已访问
		while(top!=-1 && flag){
			b=st[top];//取出栈顶元素
			if(b->rchild==p){//右子树不存在或已被访问，访问之
				if(b==s){//找到目标结点，输出路径
					for(int i=0;i<=top;i++)
						cout<<st[i]->data<<endl;
					return 1;
				}
				else{
					top--;
					p=b;//p指向刚才访问的结点
				}
			}
			else{
				b=b->rchild;//b指向右子树
				flag=0;//设置未被访问标记
			}
		}
	}while(top!=-1);//栈不空时循环
	return 0;//其他情况返回0
}

int main(){
	BTNode* root=CreateBiTree();
	
	BTNode* T1=root->rchild->rchild;
	BTNode* T2=root->lchild->lchild->lchild;
	PathToRoot(root,T1);
	PathToRoot(root,T2);
	return 0;
}
/*输入：除了根节点外，其他结点的data值与自己的位置序号一致：
111
1
3
7
0
0
0
4
0
0
2
0
6
0
0
*/