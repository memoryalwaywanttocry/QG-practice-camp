#include"qgforwardlist.h"
#include<iostream>
using namespace std;
 QGForwardList:: QGForwardList()
{
	 //初始化一个空头
	 struct Node* Temp = new struct Node;
	 Temp->data = 0;
	 Temp->next = nullptr;
	 //头尾节点都是它
	 head = Temp;
	 tail = Temp; 
}
 QGForwardList:: ~QGForwardList()
 {
	 //逐个删除所有节点
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
	 if (head->next == nullptr)//只有头节点的时候，加在头节点之后
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
	 if (nullptr == head->next)//若只有头节点，则删除头
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
	 //记住头尾，循环找到前一个，尾指针指向前一个，前一个的Next指针赋空，delete标记的尾节点
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
	 //index应该不包含头节点
	 //合法性检测
	 if (nullptr == head->next )
		 return false;
	 //特殊情况判定
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
		if (i == index)//找到index+1的前一个
			break;
		pT = pT->next;
	 }
	 //如果给的index大于节点数量，尾添加
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
	 //合法性检测
	 if (nullptr == head->next )
		 return false;
	 //特殊情况
	 //只有一个节点
	 if (head == tail)
	 {
		 Node* pT = head;
		 delete pT;
		 head = nullptr;
		 tail = nullptr;
		 return true;
	 }
	 //如果想删除的是第一个非空节点元素
	 if (0 == index)
	 {
		 pop_front();
		 return true;
	 }
	 unsigned int i = 0;
	 Node* pT = head->next ;
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
	 {
		 pop_back();
		 return true;
	 }
	 else if(pT != nullptr)
	 {
		 Node* pTemp = pT->next;//记录一下要删除的节点
		 pT->next = pTemp->next;
		 delete pTemp;
		 return true;
	 }
 }
 bool QGForwardList:: clear()
 {
	 if (nullptr == head->next )
		 return false;
	 //循环逐个delete节点,最后尾也指向空头
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
	 if (nullptr == head->next  || Index1 < 0 || Index2 < 0 || Index1 == Index2)//合法性检测
		 return;
	 //特殊情况
	 if (head == tail)
		 return;
	 //（2个中间节点的交换）+ //尾节点跟其他节点交换
	 unsigned int i = 0;
	 Node* pTemp1 = head->next ;
	 for (pTemp1; pTemp1 != tail; pTemp1 = pTemp1->next)
	 {
		 i++;
		 if (i == Index1 - 1)//找到要交换的节点的前一个
			 break;
	 }
	 i = 0;
	 Node* pTemp2 = head->next ;
	 for (pTemp2; pTemp2 != tail; pTemp2 = pTemp2->next)
	 {
		 i++;
		 if (i == Index2 - 1)//找到要交换的节点的前一个
			 break;
	 }
	 //2个节点都找得到，并且没有尾指针
	 if ((pTemp1 != nullptr && pTemp2 != nullptr && pTemp2 != tail)|| (pTemp1 != nullptr && pTemp1 != tail && pTemp2 != nullptr))
	 {
		 pTemp1->next = pTemp2->next;
		 pTemp2->next = pTemp1->next;
		 pTemp2->next->next  = pTemp1->next->next;
		 pTemp1->next->next = pTemp2->next->next;
		 return;
	 }
	 //2个节点都找得到，并且其中一个是尾指针 || 只找到一个节点，另一个下标过大，将其跟尾交换
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
		 p1 = p1->next->next;	//p1跑得快，p2跑得慢 
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