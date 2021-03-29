/**
 * ����:QG
 **/


#ifndef __QGFORWARD_LIST_H__
#define __QGFORWARD_LIST_H__

/*
 * ��������
 */
typedef int ElemType;

class QGForwardList 
{
protected:
	struct Node 
	{
		ElemType data;
	  	struct Node *next;
	};
	
	
	Node* head;
	Node* tail;

public:

	/*
	 * ��ʼ������
	 */
	QGForwardList()noexcept;

	/*
	 * ��������
	 */
	~QGForwardList();

	/*
	 * ���������е�һ��Ԫ�ص�����
	 */
	ElemType& front()noexcept;

	/*
	 * �������������һ��Ԫ�ص�����
	 */
	ElemType& back()noexcept;

	/*
	 * �������һ��Ԫ��ǰ���Ԫ��e
	 */
	bool push_front(ElemType& e);

	/*
	 * ɾ�������һ��Ԫ��
	 */
	bool pop_front();

	/*
	 * ���������һ��Ԫ�غ����Ԫ��e
	 */
	bool push_back(ElemType& e);

	/*
	 * ɾ���������һ��Ԫ��
	 */
	bool pop_back();

	/*
	 * ������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
	 */
	bool insert(unsigned int index, ElemType& e);

	/*
	 * ɾ������λ��Ԫ��
	 */
	bool erase(unsigned int index);

	/*
	 * �������
	 */
	bool clear();

	/*
	 * ����Ԫ���Ƿ����
	 */
	bool contain(ElemType& e);

	/*
	 * ����������Ԫ�ص�����
	 */
	unsigned int size()noexcept;

	/*
	 * ��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
	 */
	void traverse(void (*visit)(ElemType& e));

	/*
	 * ��ת����1234��ת����4321
	 */
	void reverse();

	/*
	 * �����л�
	 */
	void isLoop();

	/*
	 * ż�ڵ㷴ת��1234��ת����2143
	 */
	void reverseEven();

	/*
	 * �����м�ڵ�
	 */
	ElemType& middleElem();

	/*
	 * ���������ڵ��λ��
	 */
	void SwapNodebyIndex(int Index1, int Index2);
};

#endif

