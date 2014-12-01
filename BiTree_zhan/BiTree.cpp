#include <iostream>
#include <queue>
using namespace std;
//################################################
//�ݹ��������һϵ�в���

typedef char ElementType;

typedef enum {Link,Thread} PointTag;

typedef struct TreeNode             //����������ڵ�ṹ
{
	ElementType data;
	TreeNode *lchild;
	TreeNode *rchild;
}BiTreeNode,*BiTree;


typedef struct BiTrNode            //���������������ڵ�ṹ
{
	ElementType data;
	BiTrNode *lchild,*rchild;
	PointTag ltag,rtag;
}BiTrNode,*BiTrTree;

BiTrTree createTree(BiTrTree &T)  //ǰ����������������������ṹ(��չ������)
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


BiTree createTree(BiTree &T)  //ǰ����������������ṹ(��չ������)
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

void InorderTrave(BiTree T)      //���������ӡ���ڵ�
{
	if(!T)
		return;
	InorderTrave(T->lchild);
	cout<<T->data;
	InorderTrave(T->rchild);
}


void PostTrave(BiTree T)      //���������ӡ���ڵ�
{
	if(!T)
		return;
	PostTrave(T->lchild);
	PostTrave(T->rchild);
	cout<<T->data;
}


void layer(BiTree T)             //��α���
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


void destroy(BiTree &T)          //����������
{
	if(!T)
		return;
	destroy(T->lchild);
	destroy(T->rchild);
	delete T;
}

BiTrTree pre;
BiTrTree Thread_T(BiTrTree T)                //������������
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
	cout<<"�����������Ϊ��";
	InorderTrave(T);
	cout<<endl;
	cout<<"�����������Ϊ�� ";
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