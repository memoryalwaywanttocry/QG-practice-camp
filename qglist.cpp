#include<iostream>
using namespace std;
#include"qglist.h"


QGList::QGList()
{
	//设置空头空尾
	struct Node* pTemp1 = new struct Node;
	struct Node* pTemp2 = new struct Node;
	pTemp1->data = 0;
	pTemp1->next = NULL;
	pTemp1->prior = NULL;
	pTemp2->data = 0;
	pTemp2->next = NULL;
	pTemp2->prior = NULL;
	head = pTemp1;
	tail = pTemp2;
}
QGList::~QGList()
{
	//遍历逐个删除节点(把空头尾也删除掉)
	Node* pT = head;
	for (pT; pT != NULL; pT = pT->next)
	{
		Node* pTemp = pT;
		delete pTemp;
	}
	head = NULL;
	tail = NULL;
}
ElemType& QGList::front()
{
	return head->next->data;
}
ElemType& QGList::back()
{
	return tail->prior->data;
}
bool QGList::push_front(ElemType& e)
{
	if (head->next == NULL)
		return false;
	Node* pTemp = new struct Node;
	pTemp->data = e;
	pTemp->next = head->next;
	head->next->prior = pTemp;
	pTemp->prior = head;
	return true;
}
bool QGList::pop_front()
{
	if (NULL == head->next)
		return false;
	Node* pT = head->next;
	head->next = head->next->next;
	head->next->next->prior = head;
	delete pT;
	return true;
}
bool QGList::push_back(ElemType& e)
{
	if (NULL == head->next)
		return false;
	Node* pTemp = new struct Node;
	pTemp->data = e;
	tail->prior->next = pTemp;
	pTemp->next = tail;
	pTemp->prior = tail->prior;
	tail->prior = pTemp;
	return true;
}
bool QGList::pop_back()
{
	//合法性检测 如果除了空头尾，没有别的节点，直接结束
	if (NULL == head->next)
		return false;
	//记录最尾个
	Node* pT = tail->prior;
	//最尾个的前一个，next到空尾
	pT->prior->next = tail;
	//空尾的prior,到那一个
	tail->prior = pT->prior;
	//删除记录的
	delete pT;
	return true;
}
bool QGList::insert(unsigned int index, ElemType& e)
{
	//合法性判断
	if (NULL == head->next || index < 0)
		return false;
	//创建节点
	Node* pTemp = new struct Node;
	//节点成员赋值
	pTemp->data = e;
	pTemp->next = NULL;
	pTemp->prior = NULL;
	//遍历寻找第index-1个节点
	unsigned int icount = 0;
	Node* pT = head->next;
	for ( ; pT != NULL; pT = pT->next)
	{
		if (icount == index)
			break;
		icount++;
	}
	//找到了，链接，没找到，结束
	if (pT != NULL)
	{
		pTemp->prior = pT;
		pTemp->next = pT->next;
		pT->next = pTemp;
		pT->next->prior = pTemp;
		return true;
	}
	return false;
}
bool QGList::erase(unsigned int index)
{
	//合法性判断
	if (NULL == head->next || index < 0)
		return false;
	//遍历寻找节点
	unsigned int icount = 0;
	Node* pT = head->next;
	for (; pT != NULL; pT = pT->next)
	{
		if (icount == index)
			break;
		icount++;
	}
	if (pT != NULL)
	{
		pT->prior->next = pT->next;
		pT->next->prior = pT->prior;
		delete pT;
		return true;
	}
}
bool QGList::clear()
{
	//除了空头空尾，其他节点全部删除
	//合法性
	if (NULL == head->next)
		return false;
	Node* pT = head->next;
	while (pT != tail)
	{
		Node* pTemp = pT;
		pT = pT->next;
		delete pTemp;
	}
	head = NULL;
	tail = NULL;
	return true;
}
bool QGList::contain(ElemType& e)
{
	if (NULL == head->next)
		return false;
	Node* pT = head->next;
	while (pT != tail)
	{
		if (pT->data == e)
			return true;
		pT = pT->next;
	}
	return false;
}
unsigned int QGList::size()
{
	if (NULL == head->next)
		return false;
	unsigned int icount = 0;
	for (Node* pT = head->next; pT != tail; pT = pT->next)
		icount++;
	return icount + 2;
}
bool QGList::traverse(void (*visit)(ElemType& e))
{
	if (NULL == head->next)
		return false;
	for (Node* pT = head->next; pT != tail; pT = pT->next)
	{
		(*visit)(pT->data);
	}
	return true;
}
void QGList::visit(ElemType& e)
{
	cout << e << endl;
}