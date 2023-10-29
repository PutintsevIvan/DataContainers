#include"List.h"
#include<iostream>

template<typename T>List<T> operator+(const List<T>& left, const List<T>& right)
{
	List<T> cat = left;
	for (typename List<T>::ConstIterator it = right.begin(); it != right.end(); ++it)
	{
		//*it *= 10;
		cat.push_back(*it);
	}
	return cat;
}

template<typename T>void reverse_print(const List<T>& list)
{
	for (typename List<T>::ConstReverseIterator it = list.rbegin(); it != list.rend(); ++it)
	{
		//*it *= 10;
		cout << *it << tab;
	}
	cout << endl;
}

//#define BASE_CHECK
//#define ITERATORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef BASE_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
	list.reverse_print();

	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	list.insert(value, index);
	list.print();
	list.reverse_print();

	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	list.erase(index);
	list.print();
	list.reverse_print();
#endif // BASE_CHECK

#ifdef ITERATORS_CHECK
	List list = { 3, 5, 8, 13, 21 };
	list.print();
	for (int i : list)cout << i << tab; cout << endl;

	for (List::ReverseIterator it = list.rbegin(); it != list.rend(); ++it)
	{
		cout << *it << tab;
	}
	cout << endl;
#endif // ITER

	List<int> list1 = { 3, 5, 8, 13, 21 };
	List<int> list2 = { 34, 55, 89 };
	List<int> list3 = list1 + list2;

	for (int i : list1)cout << i << tab; cout << endl;
	for (int i : list2)cout << i << tab; cout << endl;
	for (int i : list3)cout << i << tab; cout << endl;
	reverse_print(list3);
	for (List<int>::Iterator it = list3.begin(); it != list3.end(); ++it)
	{
		*it *= 10;
	}
	reverse_print(list3);
	for (int i : list3)cout << i << tab; cout << endl;

	List<double> d_list = { 2.7, 3.14, 5.3, 8.1 };
	for (double i : d_list)cout << i << tab; cout << endl;

	List<std::string> s_list = { "No", "money", "no", "honey" };
	for (std::string i : s_list)cout << i << tab; cout << endl;
}