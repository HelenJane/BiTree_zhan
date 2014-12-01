#include <iostream>
#include <queue>
using namespace std;
//################################################
//递归遍历树的一系列操作

typedef char ElementType;

typedef enum {Link,Thread} PointTag;

typedef struct TreeNode             //定义二叉树节点结构
{
	ElementType data;
	TreeNode *lchild;
	TreeNode *rchild;
}BiTreeNode,*BiTree;


typedef struct BiTrNode            //定义线索二叉树节点结构
{
	ElementType data;
	BiTrNode *lchild,*rchild;
	PointTag ltag,rtag;
}BiTrNode,*BiTrTree;

BiTrTree createTree(BiTrTree &T)  //前序遍历建立线索二叉树树结构(扩展二叉树)
{
	char data;
	cin>>data;
	if(data=='#')
		T=NULL;
	else
	{
		T=new BiTrNode;
		T->data=data;
		createTree(T->lchild);
		createTree(T->rchild);
	}
	return T;
}


BiTree createTree(BiTree &T)  //前序遍历建立二叉树结构(扩展二叉树)
{
	char data;
	cin>>data;
	if(data=='#')
		T=NULL;
	else
	{
		T=new BiTreeNode;
		T->data=data;
		createTree(T->lchild);
		createTree(T->rchild);
	}
	return T;
}

void InorderTrave(BiTree T)      //中序遍历打印出节点
{
	if(!T)
		return;
	InorderTrave(T->lchild);
	cout<<T->data;
	InorderTrave(T->rchild);
}


void PostTrave(BiTree T)      //后序遍历打印出节点
{
	if(!T)
		return;
	PostTrave(T->lchild);
	PostTrave(T->rchild);
	cout<<T->data;
}


void layer(BiTree T)             //层次遍历
{
	BiTree p;
	queue<BiTree>que;
	if(T!=NULL)
		que.push(T);
	while(!que.empty())
	{
		p=que.front();
		que.pop();
		cout<<p->data<<" ";
		if(p->lchild!=NULL)
			que.push(p->lchild);
		if(p->rchild!=NULL)
			que.push(p->rchild);
	}
}


void destroy(BiTree &T)          //销毁整棵树
{
	if(!T)
		return;
	destroy(T->lchild);
	destroy(T->rchild);
	delete T;
}

BiTrTree pre;
BiTrTree Thread_T(BiTrTree T)                //二叉树线索化
{
	if(T)
	{
		Thread_T(T->lchild);
		if(!T->lchild)
		{
			T->lchild=pre;
			T->ltag=Thread;
		}
		if(pre!=NULL)
		{
			if((!pre->rchild))
			{
				pre->rchild=T;
				pre->rtag=Thread;
			}	
		}
		pre=T;
		Thread_T(T->rchild);	
	}
	return T;
}

void main()
{
	BiTree T;
	T=NULL;
	createTree(T);
	cout<<"中序遍历序列为：";
	InorderTrave(T);
	cout<<endl;
	cout<<"后序遍历序列为： ";
	PostTrave(T);
	layer(T);
	destroy(T);
}

//void main()
//{
//	BiTrTree T;
//	T=NULL;
//	createTree(T);
//	Thread_T(T);
//}