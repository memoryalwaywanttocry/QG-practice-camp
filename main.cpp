#include<iostream>
using namespace std;
#include"qglist.h"
void GiveMeun()
{
	cout << "*********************************" << endl;
	cout << "*********************************" << endl;
	cout << "***  输入不同序号实现您目的:  ***" << endl;
	cout << "** 1、 实例化双向链表。		**" << endl;
	cout << "** 2、 查看首个元素。			**" << endl;
	cout << "** 3、 查看尾个元素。			**" << endl;
	cout << "** 4、 在链表头部添加一个节点。**" << endl;
	cout << "** 5、 在链表尾部添加一个节点。**" << endl;
	cout << "** 6、 在指定节点前添加节点。  **" << endl;
	cout << "** 7、 删除第一个节点。        **" << endl;
	cout << "** 8、 删除最尾的节点。        **" << endl;
	cout << "** 9、 删除指定位置的节点。    **" << endl;
	cout << "** 10、清空链表。			    **" << endl;
	cout << "** 11、查询链表节点的个数。    **" << endl;
	cout << "** 12、查看所有节点的数据。	**" << endl;
	cout << "** 0 、退出使用。			    **" << endl;
	cout << "*********************************" << endl;
	cout << "*********************************" << endl;
}
int main(void)
{
	int select = 0;//创建一个用户选择输入的变量；
	while (1)
	{
		GiveMeun();
		cin >> select;
		switch (select)
		{
		case 1://1、 实例化一个链表对象。
			QGList List1;
			cout << "操作成功" << endl;
			system("pause");
			system("cls");
			break;
		case 2://2、 查看首个元素。
			cout << List1.front() << endl;
			system("pause");
			system("cls");
			break;
		case 3://3、 查看尾个元素。
			cout << List1.back() << endl;
			system("pause");
			system("cls");
			break;
		case 4://4、 在链表头部添加一个节点。
			ElemType b;
			cout << "请输入数据" << endl;
			cin >> b;
			List1.push_front(b);
			if (List1.push_front(b))
			{
				cout << "操作成功" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 5://5、 在链表尾部添加一个节点。
			ElemType b;
			cout << "请输入数据" << endl;
			cin >> b;
			List1.push_back(b);
			if (List1.push_back(b))
			{
				cout << "操作成功" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 6://6、 在指定节点前添加节点。
			ElemType b;
			ElemType c;
			cout << "请输入数据" << endl;
			cin >> b;
			cout << "请输入节点位置"<<endl;
			List1.insert(c,b);
			if (List1.insert(c,b))
			{
				cout << "操作成功" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 7://7、 删除第一个节点。  
			List1.pop_front();
			if (List1.pop_front())
			{
				cout << "操作成功" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 8://8、 删除最尾的节点。  
			List1.pop_back();
			if (List1.pop_back())
			{
				cout << "操作成功" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 9://9、 删除指定位置的节点。			
			ElemType b;
			cout << "请输入节点位置" << endl;
			cin >> b;
			List1.erase(b);
			if (List1.erase(b))
			{
				cout << "操作成功" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 10://10、 清空链表。
			List1.clear();
			if (List1.clear())
			{
				cout << "操作成功" << endl;
				system("pause");
				system("cls");
			}
			break;
		case 11://11、查询链表节点的个数。
			cout << List1.size() << endl;
			break;
		case 12://12、查看所有节点的数据。
			List1.traverse(List1.visit);
			break;
		case 0://0 、退出使用。
			cout << "感谢使用，欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
}