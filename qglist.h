/**
 * ����:QG
 **/


#ifndef __QGLIST_H__
#define __QGLIST_H__
typedef int ElemType;
/*
 * ˫������
 */
class QGList 
{
protected:
	struct Node 
	{
		ElemType data;
	  	struct Node *prior;
		struct Node *next;
	};

	Node* head;
	Node* tail;

public:
	
	/*
	 * ��ʼ������
	 */
	QGList();

	/*
	 * ��������
	 */
	~QGList();
	
	/*
	 * ���������е�һ��Ԫ�ص�����
	 */
	ElemType& front();

	/*
	 * �������������һ��Ԫ�ص�����
	 */
	ElemType& back();

	/*
	 * �������һ��Ԫ��ǰ���Ԫ��e
	 */
	bool push_front(const ElemType& e);

	/*
	 * ɾ�������һ��Ԫ��
	 */
	bool pop_front();

	/*
	 * ���������һ��Ԫ�غ����Ԫ��e
	 */
	bool push_back(const ElemType& e);

	/*
	 * ɾ���������һ��Ԫ��
	 */
	bool pop_back();
	
	/*
	 * ������ĵ�index + 1��Ԫ��ǰ����Ԫ��e
	 */
	bool insert(unsigned int index, const ElemType& e);

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
	bool contain(const ElemType& e);
        
	/*
	 * ����������Ԫ�ص�����
	 */
	unsigned int size();

	/*
	 * ��������, ��ÿ��Ԫ�ص���visitָ��ĺ���
	 */
	bool traverse(void (*visit)(const ElemType& e));
	/*
	 * ������������
	 */
	void visit(const ElemType& e);
};

#endif

