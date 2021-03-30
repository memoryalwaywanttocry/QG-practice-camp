#include"qgforwardlist.h"
#include<iostream>
using namespace std;
 QGForwardList:: QGForwardList()
{
	 //��ʼ��һ����ͷ
	 struct Node* Temp = new struct Node;
	 Temp->data = 0;
	 Temp->next = nullptr;
	 //ͷβ�ڵ㶼����
	 head = Temp;
	 tail = Temp; 
}
 QGForwardList:: ~QGForwardList()
 {
	 //���ɾ�����нڵ�
	 Node* pTemp = head;
	 while (pTemp!= nullptr)
	 {
		 Node* pT = pTemp;
		 pTemp = pTemp->next;
		 delete pT;
	 }
 }
 ElemType& QGForwardList:: front()noexcept
 {
	/* if (head->next == nullptr)
		 return ;*/
	 return head->next ->data;
 }
 ElemType& QGForwardList:: back()noexcept
 {
	 return tail->data;
 }
 bool QGForwardList:: push_front(ElemType& e)
 {
	 Node* pTemp = new struct Node;
	 pTemp->data = e;
	 if (head->next == nullptr)//ֻ��ͷ�ڵ��ʱ�򣬼���ͷ�ڵ�֮��
	 {
		 head->next = pTemp;
		 return true;
	 }
	 pTemp->next = head->next ;
	 head->next  = pTemp;
	 return true;
 }
 bool QGForwardList:: pop_front()
 {
	 if (nullptr == head->next)//��ֻ��ͷ�ڵ㣬��ɾ��ͷ
	 {
		 Node* pTemp = head;
		 head = nullptr;
		 delete pTemp;
		 return true;
	 }
	 Node* pT = head->next;
	 head->next  = pT->next ;
	 delete pT;
	 return true;
 }
 bool QGForwardList:: push_back(ElemType& e)
 {
	 Node* pTemp = new struct Node;
	 pTemp->data = e;
	 pTemp->next = nullptr;
	 if (nullptr == head->next)
	 {
		 head->next = pTemp;
		 return true;
	 }
	 tail->next = pTemp;
	 tail = pTemp;
	 return true;
 }
 bool QGForwardList:: pop_back()
 {
	 if (nullptr == head->next )
		 return false;
	 //��סͷβ��ѭ���ҵ�ǰһ����βָ��ָ��ǰһ����ǰһ����Nextָ�븳�գ�delete��ǵ�β�ڵ�
	 Node* pTemp = tail;
	 Node* pT = head;
	 while (pT->next != tail)
		 pT = pT->next;
	 pT->next = nullptr;
	 pT = tail; 
	 delete pTemp;
	 return true;
 }
 bool QGForwardList:: insert(unsigned int index, ElemType& e)
 {
	 //indexӦ�ò�����ͷ�ڵ�
	 //�Ϸ��Լ��
	 if (nullptr == head->next )
		 return false;
	 //��������ж�
	 if (0 == index)
	 {
		 push_front(e);
		 return true;
	 }
	 unsigned int i = 1;
	 Node* pT = head->next ;
	 while (pT != tail)
	 {
		i++;
		if (i == index)//�ҵ�index+1��ǰһ��
			break;
		pT = pT->next;
	 }
	 //�������index���ڽڵ�������β���
	 if (pT == tail)
	 {
		 push_front(e);
		 return true;
	 }
	 else
	 {
		 Node* pTemp = new struct Node;
		 pTemp->data = e;
		 pTemp->next = pT->next;
		 pT->next = pTemp;
		 return true;
	 }
 }
 bool QGForwardList:: erase(unsigned int index)
 {
	 //�Ϸ��Լ��
	 if (nullptr == head->next )
		 return false;
	 //�������
	 //ֻ��һ���ڵ�
	 if (head == tail)
	 {
		 Node* pT = head;
		 delete pT;
		 head = nullptr;
		 tail = nullptr;
		 return true;
	 }
	 //�����ɾ�����ǵ�һ���ǿսڵ�Ԫ��
	 if (0 == index)
	 {
		 pop_front();
		 return true;
	 }
	 unsigned int i = 0;
	 Node* pT = head->next ;
	 //ɾ��ĳһ������Ҫ�ҵ���ǰһ��
	 while (pT != tail)
	 {
		i++;
		if (i == index - 1)
			break;
		pT = pT->next;
	 }
	//�������index���ڽڵ�������ɾ�����һ�� 
	 if (pT == tail)
	 {
		 pop_back();
		 return true;
	 }
	 else if(pT != nullptr)
	 {
		 Node* pTemp = pT->next;//��¼һ��Ҫɾ���Ľڵ�
		 pT->next = pTemp->next;
		 delete pTemp;
		 return true;
	 }
 }
 bool QGForwardList:: clear()
 {
	 if (nullptr == head->next )
		 return false;
	 //ѭ�����delete�ڵ�,���βҲָ���ͷ
	 Node* pTemp = head->next ;
	 while (pTemp!= nullptr)
	 {
		 Node* pT = pTemp;
		 pTemp = pTemp->next;
		 delete pT;
	 }
	 tail = head;
	 return true;
 }
 bool QGForwardList:: contain(ElemType& e)
 {
	 if (nullptr == head->next )
		 return false;
	 Node* pT = head->next ;
	 while (pT != nullptr)
	 {
		 if (pT->data == e)
			 break;
		 pT = pT->next;
	 }
	 if (pT != nullptr)
		 return true;
	 return false;
 }
 unsigned int QGForwardList:: size()noexcept
 {
	 if (nullptr == head->next )
		 return 0;
	 unsigned int icount = 0;
	 for (Node* pT = head->next ; pT != NULL; pT = pT->next)
		 icount++;
	 return icount;
 }
 void QGForwardList:: traverse(void (*visit)(ElemType& e))
 {
	 if (nullptr == head->next )
		 return;
	 for (Node* pT = head; pT != NULL; pT = pT->next)
	 {
		 //(*visit)(pT->data);
		 visit(pT->data);
	 }
 }
 void QGForwardList::SwapNodebyIndex(int Index1, int Index2)
 {
	 if (nullptr == head->next  || Index1 < 0 || Index2 < 0 || Index1 == Index2)//�Ϸ��Լ��
		 return;
	 //�������
	 if (head == tail)
		 return;
	 //��2���м�ڵ�Ľ�����+ //β�ڵ�������ڵ㽻��
	 unsigned int i = 0;
	 Node* pTemp1 = head->next ;
	 for (pTemp1; pTemp1 != tail; pTemp1 = pTemp1->next)
	 {
		 i++;
		 if (i == Index1 - 1)//�ҵ�Ҫ�����Ľڵ��ǰһ��
			 break;
	 }
	 i = 0;
	 Node* pTemp2 = head->next ;
	 for (pTemp2; pTemp2 != tail; pTemp2 = pTemp2->next)
	 {
		 i++;
		 if (i == Index2 - 1)//�ҵ�Ҫ�����Ľڵ��ǰһ��
			 break;
	 }
	 //2���ڵ㶼�ҵõ�������û��βָ��
	 if ((pTemp1 != nullptr && pTemp2 != nullptr && pTemp2 != tail)|| (pTemp1 != nullptr && pTemp1 != tail && pTemp2 != nullptr))
	 {
		 pTemp1->next = pTemp2->next;
		 pTemp2->next = pTemp1->next;
		 pTemp2->next->next  = pTemp1->next->next;
		 pTemp1->next->next = pTemp2->next->next;
		 return;
	 }
	 //2���ڵ㶼�ҵõ�����������һ����βָ�� || ֻ�ҵ�һ���ڵ㣬��һ���±���󣬽����β����
	 else if (pTemp1 == tail && pTemp2 != nullptr)
	 {
		 if (pTemp1 != nullptr)
		 {
			 pTemp1->next = pTemp2->next;
			 pTemp2->next = pTemp1->next;
			 pTemp1->next->next = pTemp2->next->next;
			 pTemp2->next->next = nullptr;
			 pTemp2->next = tail;
			 return;
		 }
	 }
	 else if (pTemp1 != nullptr && pTemp2 == tail)
	 {
		 if (pTemp2 != nullptr)
		 {
			 pTemp1->next = pTemp2->next;
			 pTemp2->next = pTemp1->next;
			 pTemp2->next->next = pTemp1->next->next;
			 pTemp1->next->next = nullptr;
			 pTemp1->next = tail;
			 return;
		 }
	 }
 }
 void QGForwardList:: reverse()
 {
	 //�����������ڵ��λ��
	 const unsigned int iCount = size();
	 unsigned int i = 0, j = iCount-1;
	 for (i; i < j; i++)
	 {
		 for (j; j > i; j--)
		 {
			 SwapNodebyIndex(i, j);
		 }
	 }
	 //��һ�������ڵ������
	 //˼·��2��forѭ���ҵ��ڵ㣬Ȼ��temp��¼����һ�����ݣ����ݽ���
	/* unsigned int iCount = size();
	 unsigned int i = 0, j = iCount - 1;
	 for (i; i < j; i++)
	 {
		 for (j; j > i; j--)
		 {
			 ...
		 }
	 }*/
 }
 bool QGForwardList::isLoop()
 {
	 if (nullptr == head->next)
		 return false;
	 Node* p1 = head->next;
	 Node* p2 = head->next;
	 int i = 0;
	 while (p1 != nullptr)
	 {
		 i++;
		 if (i % 2 == 0)
			 p2 = p2->next;
		 if (p1 == p2)
			 return true;
		 p1 = p1->next->next;	//p1�ܵÿ죬p2�ܵ��� 
	 }
	 return false;
 }
 void QGForwardList::reverseEven()
 {
	 if (head->next == nullptr || head->next->next == nullptr)
		 return;
	 int a= 0;
	 Node* pT = head->next;
	 while(pT != nullptr)
	 {
		 a = pT->data;
		 pT->data = pT->next->data;
		 pT->next->data = a;
		 pT = pT->next->next ;
	 }
 }
 ElemType& QGForwardList::middleElem()
 {
	/* if (head->next == nullptr)
		 return;*/
	 unsigned int iCount = 0 ;
	 unsigned int iNum = size();
	 Node* pT = head->next;
	 while (pT != nullptr)
	 {
		 if (iCount / 2 == iNum)
		 {
			 return pT->data;
		 }
		 iCount++; 
	 }
 }