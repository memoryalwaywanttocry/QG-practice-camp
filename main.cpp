#include<iostream>
using namespace std;
#include"qglist.h"
void GiveMeun()
{
	cout << "*********************************" << endl;
	cout << "*********************************" << endl;
	cout << "***  ���벻ͬ���ʵ����Ŀ��:  ***" << endl;
	cout << "** 1�� ʵ����˫������		**" << endl;
	cout << "** 2�� �鿴�׸�Ԫ�ء�			**" << endl;
	cout << "** 3�� �鿴β��Ԫ�ء�			**" << endl;
	cout << "** 4�� ������ͷ�����һ���ڵ㡣**" << endl;
	cout << "** 5�� ������β�����һ���ڵ㡣**" << endl;
	cout << "** 6�� ��ָ���ڵ�ǰ��ӽڵ㡣  **" << endl;
	cout << "** 7�� ɾ����һ���ڵ㡣        **" << endl;
	cout << "** 8�� ɾ����β�Ľڵ㡣        **" << endl;
	cout << "** 9�� ɾ��ָ��λ�õĽڵ㡣    **" << endl;
	cout << "** 10���������			    **" << endl;
	cout << "** 11����ѯ����ڵ�ĸ�����    **" << endl;
	cout << "** 12���鿴���нڵ�����ݡ�	**" << endl;
	cout << "** 0 ���˳�ʹ�á�			    **" << endl;
	cout << "*********************************" << endl;
	cout << "*********************************" << endl;
}
int main(void)
{
	int select = 0;//����һ���û�ѡ������ı�����
	while (1)
	{
		GiveMeun();
		cin >> select;
		switch (select)
		{
		case 1://1�� ʵ����һ���������
			QGList List1;
			cout << "�����ɹ�" << endl;
			system("pause");
			system("cls");
			break;
		case 2://2�� �鿴�׸�Ԫ�ء�
			cout << List1.front() << endl;
			system("pause");
			system("cls");
			break;
		case 3://3�� �鿴β��Ԫ�ء�
			cout << List1.back() << endl;
			system("pause");
			system("cls");
			break;
		case 4://4�� ������ͷ�����һ���ڵ㡣
			ElemType b;
			cout << "����������" << endl;
			cin >> b;
			List1.push_front(b);
			if (List1.push_front(b))
			{
				cout << "�����ɹ�" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 5://5�� ������β�����һ���ڵ㡣
			ElemType b;
			cout << "����������" << endl;
			cin >> b;
			List1.push_back(b);
			if (List1.push_back(b))
			{
				cout << "�����ɹ�" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 6://6�� ��ָ���ڵ�ǰ��ӽڵ㡣
			ElemType b;
			ElemType c;
			cout << "����������" << endl;
			cin >> b;
			cout << "������ڵ�λ��"<<endl;
			List1.insert(c,b);
			if (List1.insert(c,b))
			{
				cout << "�����ɹ�" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 7://7�� ɾ����һ���ڵ㡣  
			List1.pop_front();
			if (List1.pop_front())
			{
				cout << "�����ɹ�" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 8://8�� ɾ����β�Ľڵ㡣  
			List1.pop_back();
			if (List1.pop_back())
			{
				cout << "�����ɹ�" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 9://9�� ɾ��ָ��λ�õĽڵ㡣			
			ElemType b;
			cout << "������ڵ�λ��" << endl;
			cin >> b;
			List1.erase(b);
			if (List1.erase(b))
			{
				cout << "�����ɹ�" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 10://10�� �������
			List1.clear();
			if (List1.clear())
			{
				cout << "�����ɹ�" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 11://11����ѯ����ڵ�ĸ�����
			cout << List1.size() << endl;
			break;
		case 12://12���鿴���нڵ�����ݡ�
			List1.traverse(List1.visit);
			break;
		case 0://0 ���˳�ʹ�á�
			cout << "��лʹ�ã���ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
}