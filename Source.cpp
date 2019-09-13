#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	LinkedList<int> list;

	vector<int> arr = { 1,2,3,4,5 };
	LinkedList<int> list2(arr);

	list.Append(2);
	list.Append(4);
	list.Append(1);
	list.Append(6);
	list.Append(3);
	list.Append(5);
	list.Push(0);
	list.PrintList();
	cout << "------------------" << endl;
	list.RemoveFromStart();
	list.PrintList();
	cout << "------------------" << endl;
	list.RemoveFromEnd();
	list.PrintList();
	cout << "------------------" << endl;
	list2.PrintList();


	system("pause");

}