#include<iostream>
using namespace std;
#include"qglist.h"


QGList::QGList()
{
	//���ÿ�ͷ��β
	struct Node* pTemp1 = new struct Node;
	struct Node* pTemp2 = new struct Node;
	pTemp1->data = 0;
	pTemp1->next = nullptr;
	pTemp1->prior = nullptr;
	pTemp2->data = 0;
	pTemp2->next = nullptr;
	pTemp2->prior = nullptr;
	head = pTemp1;
	tail = pTemp2;
}
QGList::~QGList()
{
	//�������ɾ���ڵ�(�ѿ�ͷβҲɾ����)
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
bool QGList::push_front(const ElemType& e)
{
	if (head->next == nullptr)
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
	if (nullptr == head->next)
		return false;
	Node* pT = head->next;
	head->next = head->next->next;
	head->next->next->prior = head;
	delete pT;
	return true;
}
bool QGList::push_back(const ElemType& e)
{
	if (nullptr == head->next)
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
	//�Ϸ��Լ�� ������˿�ͷβ��û�б�Ľڵ㣬ֱ�ӽ���
	if (nullptr == head->next)
		return false;
	//��¼��β��
	Node* pT = tail->prior;
	//��β����ǰһ����next����β
	pT->prior->next = tail;
	//��β��prior,����һ��
	tail->prior = pT->prior;
	//ɾ����¼��
	delete pT;
	return true;
}
bool QGList::insert(unsigned int index, const ElemType& e)
{
	//�Ϸ����ж�
	if (nullptr == head->next || index < 0)
		return false;
	//�����ڵ�
	Node* pTemp = new struct Node;
	//�ڵ��Ա��ֵ
	pTemp->data = e;
	pTemp->next = nullptr;
	pTemp->prior = nullptr;
	//����Ѱ�ҵ�index-1���ڵ�
	unsigned int icount = 0;
	Node* pT = head->next;
	for ( ; pT != NULL; pT = pT->next)
	{
		if (icount == index)
			break;
		icount++;
	}
	//�ҵ��ˣ����ӣ�û�ҵ�������
	if (pT != nullptr)
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
	//�Ϸ����ж�
	if (nullptr == head->next || index < 0)
		return false;
	//����Ѱ�ҽڵ�
	unsigned int icount = 0;
	Node* pT = head->next;
	for (; pT != NULL; pT = pT->next)
	{
		if (icount == index)
			break;
		icount++;
	}
	if (pT != nullptr)
	{
		pT->prior->next = pT->next;
		pT->next->prior = pT->prior;
		delete pT;
		return true;
	}
}
bool QGList::clear()
{
	//���˿�ͷ��β�������ڵ�ȫ��ɾ��
	//�Ϸ���
	if (nullptr == head->next)
		return false;
	Node* pT = head->next;
	while (pT != tail)
	{
		Node* pTemp = pT;
		pT = pT->next;
		delete pTemp;
	}
	head = nullptr;
	tail = nullptr;
	return true;
}
bool QGList::contain(const ElemType& e)
{
	if (nullptr == head->next)
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
	if (nullptr == head->next)
		return false;
	unsigned int icount = 0;
	for (Node* pT = head->next; pT != tail; pT = pT->next)
		icount++;
	return icount + 2;
}
bool QGList::traverse(void (*visit)(const ElemType& e))
{
	if (nullptr == head->next)
		return false;
	for (Node* pT = head->next; pT != tail; pT = pT->next)
	{
		(*visit)(pT->data);
	}
	return true;
}
void QGList::visit(const ElemType& e)
{
	cout << e << endl;
}