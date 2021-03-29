#include"qgforwardlist.h"
#include<iostream>
using namespace std;
 QGForwardList:: QGForwardList()
{
	 //��ʼ��һ����ͷ
	 struct Node* Temp = new struct Node;
	 Temp->data = 0;
	 Temp->next = NULL;
	 //ͷβ�ڵ㶼����
	 head = Temp;
	 tail = Temp; 
}
 QGForwardList:: ~QGForwardList()
 {
	 //���ɾ�����нڵ�
	 Node* pTemp = head;
	 while (pTemp!= NULL)
	 {
		 Node* pT = pTemp;
		 pTemp = pTemp->next;
		 delete pT;
	 }
 }
 ElemType& QGForwardList:: front()noexcept
 {
	 return head->data;
 }
 ElemType& QGForwardList:: back()noexcept
 {
	 return tail->data;
 }
 bool QGForwardList:: push_front(ElemType& e)
 {
	 if (head == NULL)
		 return false;
	 //�����½ڵ�
	 Node* pTemp = new struct Node;
	 //�ڵ��Ա��ֵ
	 pTemp->data = e;
	 //����
	 pTemp->next = head;
	 head = pTemp;
	 return true;
 }
 bool QGForwardList:: pop_front()
 {
	 if (NULL == head)
		 return false;
	 Node* pT = head;
	 head = head->next;
	 delete pT;
	 return true;
 }
 bool QGForwardList:: push_back(ElemType& e)
 {
	 if (NULL == head)
		 return false;
	 Node* pTemp = new struct Node;
	 pTemp->data = e;
	 pTemp->next = NULL;
	 tail->next = pTemp;
	 tail = pTemp;
	 return true;
 }
 bool QGForwardList:: pop_back()
 {
	 if (NULL == head)
		 return false;
	 //��סͷβ��ѭ���ҵ�ǰһ����βָ��ָ��ǰһ����ǰһ����Nextָ�븳�գ�delete��ǵ�β�ڵ�
	 Node* pTemp = tail;
	 Node* pT = head;
	 while (pT->next != tail)
		 pT = pT->next;
	 pT->next = NULL;
	 pT = tail; 
	 delete pTemp;
	 return true;
 }
 bool QGForwardList:: insert(unsigned int index, ElemType& e)
 {
	 //�Ϸ��Լ��
	 if (NULL == head->next )
		 return false;
	 //��������ж�
	 if(0 == index)
		 push_front(e);
	 unsigned int i = 0;
	 Node* pT = head;
	 while (pT != tail)
	 {
		i++;
		if (i == index)//�ҵ�index+1��ǰһ��
			break;
		pT = pT->next;
	 }
	 //�������index���ڽڵ�������β���
	 if (pT == tail)
		 push_front(e);
	 else
	 {
		 //�����½ڵ�
		 Node* pTemp = new struct Node;
		 if (pT == NULL)
			 return false;
		//��Ա��ֵ
		 pTemp->data = e;
		 //���ӵ�������
		 pTemp->next = pT->next;
		 pT->next = pTemp;
		 return true;
	 }
 }
 bool QGForwardList:: erase(unsigned int index)
 {
	 //�Ϸ��Լ��
	 if (NULL == head->next )
		 return false;
	 //�������
	 //ֻ��һ���ڵ�
	 if (head == tail)
	 {
		 Node* pT = head;
		 delete pT;
		 head = NULL;
		 tail = NULL;
		 return true;
	 }
	 //�����ɾ������ͷ�ڵ�
	 if(0 == index)
		 pop_front();
	 unsigned int i = 0;
	 Node* pT = head;
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
		 pop_back();
	 else if(pT != NULL)
	 {
		 Node* pTemp = pT->next;//��¼һ��Ҫɾ���Ľڵ�
		 pT->next = pTemp->next;
		 delete pTemp;
		 return true;
	 }
 }
 bool QGForwardList:: clear()
 {
	 if (NULL == head)
		 return false;
	 //ѭ�����delete�ڵ�,���ͷβ����
	 Node* pTemp = head;
	 while (pTemp!= NULL)
	 {
		 Node* pT = pTemp;
		 pTemp = pTemp->next;
		 delete pT;
	 }
	 head = NULL;
	 tail = NULL;
	 return true;
 }
 bool QGForwardList:: contain(ElemType& e)
 {
	 if (NULL == head)
		 return false;
	 Node* pT = head;
	 while (pT != NULL)
	 {
		 if (pT->data == e)
			 break;
		 pT = pT->next;
	 }
	 if (pT != NULL)
		 return true;
	 return false;
 }
 unsigned int QGForwardList:: size()noexcept
 {
	 if (NULL == head)
		 return 0;
	 unsigned int icount = 0;
	 for (Node* pT = head; pT != NULL; pT = pT->next)
		 icount++;
	 return icount;
 }
 void QGForwardList:: traverse(void (*visit)(ElemType& e))
 {
	 if (NULL == head)
		 return;
	 for (Node* pT = head; pT != NULL; pT = pT->next)
	 {
		 //(*visit)(pT->data);
		 visit(pT->data);
	 }
 }
 void QGForwardList::SwapNodebyIndex(int Index1, int Index2)
 {
	 if (NULL == head || Index1 < 0 || Index2 < 0 || Index1 == Index2)//�Ϸ��Լ��
		 return;
	 //�������
	 if (head == tail)
		 return;
	 //ͷ�ڵ�������ڵ㽻��
	 if (Index1 == 0)
	 {
		 Node* pTemp1 = head;
		 Node* pTemp2 = head;
		 unsigned int i = 0;
		 for (pTemp2; pTemp2 != tail; pTemp2 = pTemp2->next)
		 {
			 i++;
			 if (i == Index2 - 1)//�ҵ�Ҫ�����Ľڵ��ǰһ��
			 {
				 break;
			 }
		 }
		 if (pTemp2 != tail)//ͷ���Ǹ�β����
		 {
			 pTemp1->next = pTemp2->next;
			 pTemp2->next = pTemp1->next;
			 pTemp2->next->next = pTemp1->next->next;
			 pTemp1->next->next = pTemp2->next->next;
			 pTemp2->next  = head;
			 return;
		 } 
		 else if (pTemp2 == tail)//ͷ��β����
		 {
			 pTemp1->next = pTemp2->next;
			 pTemp2->next = pTemp1->next;
			 pTemp2->next->next = pTemp1->next->next;
			 pTemp1->next->next = pTemp2->next->next;
			 pTemp2->next  = head;
			 pTemp1->next  = tail;
			 return;
		 }
	 }
	 if (Index2 == 0)
	 {
		 Node* pTemp1 = head;
		 Node* pTemp2 = head;
		 unsigned int i = 0;
		 for (pTemp2; pTemp2 != tail; pTemp2 = pTemp2->next)
		 {
			 i++;
			 if (i == Index1 - 1)//�ҵ�Ҫ�����Ľڵ��ǰһ��
			 {
				 break;
			 }
		 }
		 if (pTemp2 != tail)
		 {
			 pTemp1->next = pTemp2->next;
			 pTemp2->next = pTemp1->next;
			 pTemp2->next->next = pTemp1->next->next;
			 pTemp1->next->next = pTemp2->next->next; 
			 pTemp2->next  = head;
			 return;
		 }	
		 else if (pTemp2 == tail)
		 {
			 pTemp1->next = pTemp2->next;
			 pTemp2->next = pTemp1->next;
			 pTemp2->next->next = pTemp1->next->next;
			 pTemp1->next->next = pTemp2->next->next;
			 pTemp2->next  = head;
			 pTemp1->next  = tail;
			 return;
		 }
	 }
	 if (head->next == tail)//��2���ڵ�
	 {
		 tail->next = head;
		 head->next = NULL;
		 Node* PT = tail;
		 tail = head;
		 head = PT;
		 return;
	 }
	 //��2���м�ڵ�Ľ�����+ //β�ڵ�������ڵ㽻��
	 unsigned int i = 0;
	 Node* pTemp1 = head;
	 for (pTemp1; pTemp1 != NULL; pTemp1 = pTemp1->next)
	 {
		 i++;
		 if (i == Index1 - 1)//�ҵ�Ҫ�����Ľڵ��ǰһ��
		 {
			 break;
		 }
	 }
	 i = 0;
	 Node* pTemp2 = head;
	 for (pTemp2; pTemp2 != NULL; pTemp2 = pTemp2->next)
	 {
		 i++;
		 if (i == Index2 - 1)//�ҵ�Ҫ�����Ľڵ��ǰһ��
		 {
			 break;
		 }
	 }
	 if ((pTemp1 != NULL && pTemp2 != tail)|| pTemp1 != tail && pTemp2 != NULL)
	 {
		 pTemp1->next = pTemp2->next;
		 pTemp2->next = pTemp1->next;
		 pTemp2->next->next  = pTemp1->next->next;
		 pTemp1->next->next = pTemp2->next->next;
		 return;
	 }
	 else if (pTemp1 == tail && pTemp2 != NULL)
	 {
		 if (pTemp1 != NULL)
		 {
			 pTemp1->next = pTemp2->next;
			 pTemp2->next = pTemp1->next;
			 pTemp1->next->next = pTemp2->next->next;
			 pTemp2->next->next = NULL;
			 pTemp2->next = tail;
			 return;
		 }
	 }
	 else if (pTemp1 != NULL && pTemp2 == tail)
	 {
		 if (pTemp2 != NULL)
		 {
			 pTemp1->next = pTemp2->next;
			 pTemp2->next = pTemp1->next;
			 pTemp2->next->next = pTemp1->next->next;
			 pTemp1->next->next = NULL;
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


