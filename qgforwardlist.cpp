#include"qgforwardlist.h"
#include<iostream>
using namespace std;
 QGForwardList:: QGForwardList()
{
	 //初始化一个空头
	 struct Node* Temp = new struct Node;
	 Temp->data = 0;
	 Temp->next = NULL;
	 //头尾节点都是它
	 head = Temp;
	 tail = Temp; 
}
 QGForwardList:: ~QGForwardList()
 {
	 //逐个删除所有节点
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
	 //创建新节点
	 Node* pTemp = new struct Node;
	 //节点成员赋值
	 pTemp->data = e;
	 //连接
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
	 //记住头尾，循环找到前一个，尾指针指向前一个，前一个的Next指针赋空，delete标记的尾节点
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
	 //合法性检测
	 if (NULL == head->next )
		 return false;
	 //特殊情况判定
	 if(0 == index)
		 push_front(e);
	 unsigned int i = 0;
	 Node* pT = head;
	 while (pT != tail)
	 {
		i++;
		if (i == index)//找到index+1的前一个
			break;
		pT = pT->next;
	 }
	 //如果给的index大于节点数量，尾添加
	 if (pT == tail)
		 push_front(e);
	 else
	 {
		 //创建新节点
		 Node* pTemp = new struct Node;
		 if (pT == NULL)
			 return false;
		//成员赋值
		 pTemp->data = e;
		 //链接到链表上
		 pTemp->next = pT->next;
		 pT->next = pTemp;
		 return true;
	 }
 }
 bool QGForwardList:: erase(unsigned int index)
 {
	 //合法性检测
	 if (NULL == head->next )
		 return false;
	 //特殊情况
	 //只有一个节点
	 if (head == tail)
	 {
		 Node* pT = head;
		 delete pT;
		 head = NULL;
		 tail = NULL;
		 return true;
	 }
	 //如果想删除的是头节点
	 if(0 == index)
		 pop_front();
	 unsigned int i = 0;
	 Node* pT = head;
	 //删除某一个，需要找到其前一个
	 while (pT != tail)
	 {
		i++;
		if (i == index - 1)
			break;
		pT = pT->next;
	 }
	//如果给的index大于节点数量，删除最后一个 
	 if (pT == tail)
		 pop_back();
	 else if(pT != NULL)
	 {
		 Node* pTemp = pT->next;//记录一下要删除的节点
		 pT->next = pTemp->next;
		 delete pTemp;
		 return true;
	 }
 }
 bool QGForwardList:: clear()
 {
	 if (NULL == head)
		 return false;
	 //循环逐个delete节点,最后头尾赋空
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
	 if (NULL == head || Index1 < 0 || Index2 < 0 || Index1 == Index2)//合法性检测
		 return;
	 //特殊情况
	 if (head == tail)
		 return;
	 //头节点跟其他节点交换
	 if (Index1 == 0)
	 {
		 Node* pTemp1 = head;
		 Node* pTemp2 = head;
		 unsigned int i = 0;
		 for (pTemp2; pTemp2 != tail; pTemp2 = pTemp2->next)
		 {
			 i++;
			 if (i == Index2 - 1)//找到要交换的节点的前一个
			 {
				 break;
			 }
		 }
		 if (pTemp2 != tail)//头不是跟尾交换
		 {
			 pTemp1->next = pTemp2->next;
			 pTemp2->next = pTemp1->next;
			 pTemp2->next->next = pTemp1->next->next;
			 pTemp1->next->next = pTemp2->next->next;
			 pTemp2->next  = head;
			 return;
		 } 
		 else if (pTemp2 == tail)//头跟尾交换
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
			 if (i == Index1 - 1)//找到要交换的节点的前一个
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
	 if (head->next == tail)//有2个节点
	 {
		 tail->next = head;
		 head->next = NULL;
		 Node* PT = tail;
		 tail = head;
		 head = PT;
		 return;
	 }
	 //（2个中间节点的交换）+ //尾节点跟其他节点交换
	 unsigned int i = 0;
	 Node* pTemp1 = head;
	 for (pTemp1; pTemp1 != NULL; pTemp1 = pTemp1->next)
	 {
		 i++;
		 if (i == Index1 - 1)//找到要交换的节点的前一个
		 {
			 break;
		 }
	 }
	 i = 0;
	 Node* pTemp2 = head;
	 for (pTemp2; pTemp2 != NULL; pTemp2 = pTemp2->next)
	 {
		 i++;
		 if (i == Index2 - 1)//找到要交换的节点的前一个
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
	 //法二：交换节点的位置
	 const unsigned int iCount = size();
	 unsigned int i = 0, j = iCount-1;
	 for (i; i < j; i++)
	 {
		 for (j; j > i; j--)
		 {
			 SwapNodebyIndex(i, j);
		 }
	 }
	 //法一：交换节点的数据
	 //思路：2个for循环找到节点，然后temp记录其中一个数据，数据交换
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


