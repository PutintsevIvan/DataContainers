#include<iostream>
using namespace std;
using std::cin;
using std::endl;
using std::cout;

#define tab "\t"

class Element
{
	int Data;
	Element* pNext;
	static int count;  //���������� ����������� ����������
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
     #ifdef DEBUG
		cout << "EConstructor:\t" << this << endl;
     #endif // DEBUG
	}
	
	~Element()
	{
		count--;
#ifdef DEBUG
		cout << "EDestructor:\t" << this << endl;
#endif // DEBUG
	}
	friend class ForwardList;
	friend class Iterator;
};

int Element::count = 0;  //����������� ����������� ����������

class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr) :Temp(Temp)
	{
#ifdef DEBUG
		cout << "ItConstructor:\t" << this << endl;
#endif // DEBUG

	}
	Iterator(const Iterator& other)
	{
     #ifdef DEBUG
		this->Temp = other.Temp;
		cout << "ItCopyConstructor:\t" << this << endl;
     #endif // DEBUG
	}
	~Iterator()
	{

#ifdef DEBUG
		cout << "ItDestructor:\t" << this << endl;
#endif // DEBUG

	}

	Iterator& operator++()  //Prefix increment
	{
		Temp = Temp->pNext;
		return *this;
	}
	Iterator operator++(int)
	{
		Iterator old = *this;
		Temp = Temp->pNext;
		return old;
	}

	bool operator==(const Iterator& other)const
	{
		return this->Temp == other.Temp;
	}
	bool operator!=(const Iterator& other)const
	{
		return this->Temp != other.Temp;
	}

	int operator*()
	{
		return Temp->Data;
	}
};
class ForwardList
{
	//Forward-�����������,����������������
	Element* Head;
	unsigned int size;
public:
	//type name(parameters)
	const Iterator begin()const
	{
		return Head;
	}
	const Iterator end()const
	{
		return nullptr;
	}
	ForwardList()
	{
		//����������� �� ��������� ������� ������ �����.
		this->Head = nullptr;  //���� ������ ����,��� ������ ��������� �� 0.
		this->size = 0;
		cout << "LConstructor:\t"<<this << endl;
	}
	ForwardList(initializer_list<int> il) :ForwardList()
	{
		//itializer_list-��� ���������
		//���������-��� ������,������ ���������� �������� ������ �������� � ������.
		//��� � � ������ ������� ����������,� initializer_list ���� ������ begin() � end()
		//begin()-���������� ��������� �� ������ ����������;
		//end()-���������� ��������� �� ����� ����������;
		cout << typeid(il.begin()).name() << endl;
		for (int const* it = il.begin(); it != il.end(); ++it)
		{
			push_back(*it);
		}
	}
	ForwardList(const ForwardList& other) :ForwardList()
	{
		//this - ���� ������
		//other - ��� ������
		/*for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		cout << "LCopyConstructor" << this << endl;*/
		*this = other; //�� ������������ ����������� �������� ���������� ��� CopyAssignment
		cout << "LCopyCOnstructor" << this<<"<-"<<&other << endl;
	}
	ForwardList(ForwardList&& other):ForwardList()
	{
	/*	this->Head = other.Head;
		this->size = other.size;

		other.Head = nullptr;
		other.size = 0;*/
		*this = std::move(other);
		cout << "MoveConstructor:\t" << this <<"<-" <<&other<< endl;
	}
	~ForwardList()
	{
		while (Head)pop_front();
		cout << "LDestructor:\t" << this << endl;
	}

	//              Operators:
	ForwardList& operator=(const ForwardList& other)
	{
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)
			push_back(Temp->Data);
		cout << "CopyAssignment:\t" << this <<"<-"<<&other<< endl;
		return *this;
	}
	ForwardList& operator=(ForwardList&& other)
	{
		if (this == &other)return*this;
		while (Head)pop_front();
		this->Head = other.Head;
		this->size = 0;
		cout << "MoveAssignment:\t" << this << "<-" << &other << endl;
		return*this;
	}
	//				Adding elements:
	void push_front(int Data)
	{
		/* // 1) ������� ������� ��� ������������ ��������:
		Element* New = new Element(Data);
		//2) �������������� ������� � ������:
		New->pNext = Head;
		//3) ������ ����� ������� �������� ��������� ��������� ������:
		Head = New;*/

		Head = new Element(Data, Head); //����������� ������� push_front
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)return push_front(Data);
		//1)������� ����� �������:
		//Element* New = new Element(Data);
        //2)������� �� ����� ������:
		Element* Temp = Head;
		while (Temp->pNext)
		{
			Temp = Temp->pNext;
		}
		// ������ 'Temp' ��������� �� ��������� �������.

		//3)  ��������� ����� ������� � ������ ������:
		//Temp->pNext = New;
		Temp->pNext=new Element(Data); //����������� ������� push_back
		size ++;
	}
	void insert(int Data,int Index)
	{
		if (Index == 0)return push_front(Data);
		//1) ������� ����� �������:
		//Element* New = new Element(Data);
		//2) ������� �� ������� ��������:
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
		{
			if (Temp->pNext == nullptr)return push_back(Data);
			Temp = Temp->pNext;

		}
		//3) ��������� ����� ������� �� ���������� �������:
		//New->pNext = Temp->pNext;
		//Temp->pNext = New;
		Temp->pNext = new Element(Data, Temp->pNext);// ����������� ������� insert
		size++;
	}

	//        Removing elements:
	void pop_front()
	{
		Element* Erased = Head;//1) ���������� ����� ���������� ��������
		Head = Head->pNext;    //2) ��������� ��������� ������� �� ������ 
		delete Erased;         //3) ������� ������� �� ������
		size--;
	}
	void pop_back()
	{
		//1)������� �� �������������� ��������:
		Element* Temp = Head;
		while (Temp->pNext->pNext)Temp = Temp->pNext;
		//2)������� ��������� ������� �� ������:
		delete Temp->pNext;
		//3)�������� ��������� �� ��������� �������:
		Temp->pNext = nullptr;
		size--;
	}

	void erase(int index)
	{
		if (index == 0)return pop_front();

		Element* Temp = Head;
		for (int i = 0; i < index; i++)
		{
			if (Temp == nullptr)return;
			Temp = Temp->pNext;
		}
		Element* Erased = Temp->pNext;
		Temp->pNext=Temp->pNext->pNext;
        delete Erased;
		size--;
	}
	//   Methods:
	void print()const
	{
		/*Element* Temp = Head; //Temp-��� ��������.
		//��������-��� ���������,��� ������ �������� ����� �������� ������ � ��������� ��������� ������.

		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext; // ������� �� ��������� �������
		}*/
		//����������� ������� print:
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "���������� ��������� ������: " << this->size << endl;//� ����������� ����� ������� ���������� ����� ��� ������ � �������� ���������� ���������
		cout << "����� ���������� ��������� ������: " << Element::count << endl;//� ����������� ����� ������� ���������� ����� ��� ������ � �������� ���������� ���������
		//cout << "���������� ��������� ������: " << Head->count << endl;
	}
};

ForwardList operator+(const ForwardList& left, const ForwardList& right)
{
	ForwardList result = left;
	for (Iterator it = right.begin(); it != right.end(); ++it)
		result.push_back(*it);
	return result;
}

//#define BASE_CHECK
//#define INSERT_CHECK
//#define RANGE_BASE_FOR_ARRAY
//#define RAGE_BASE_FOR_LIST
#define COPY_METHODS_CHECK
#define FORWARD_LIST_PREFORMNCE_TEST
void main()
{
	setlocale(LC_ALL, "");
#ifdef BASE_CHECK
	int n;
	cout<<"������� ������ ������: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
		//list.push_front(rand() % 100);
	}
	/*list.push_front(123);
	list.print();
	list.pop_front();
	list.pop_back();*/
	list.print();
#ifdef INSERT_CHECK
	int index;
	int value;
	cout << "������� ������ ����������� ��������: "; cin >> index;
	cout << "������� �������� ����������� ��������: "; cin >> value;
	list.insert(value, index);
	list.print();
	cout << "������� ������ ���������� ��������: "; cin >> index;
	list.erase(index);
	list.print();
#endif // INSERT_CHECK
#endif // BASE_CHECK
#ifdef RANGE_BASE_FOR_ARRAY
	int arr[] = { 3,5,8,13,21 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
	for (int i : arr)
	{
		cout << i << tab;
	}
	cout << endl;

#endif // RANGE_BASE_FOR_ARRAY
#ifdef RANGE_BASE_FOR_LIST

	ForwardList list = { 3,5,8,13,21 };
	list.print();

	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;
	for (Iterator it = list.begin(); it != list.end(); in++) //POstfix increment
	{
		cout << *it << tab;
	}
	cout << endl;
#endif // RANGE_BASE_FOR_LIST

	ForwardList list1 = { 3,5,8,13,21 };
	list1 = list1;
	for (int i : list1)cout << i << tab; cout << endl;
	
	//ForwardList list2 = { 3,5,8,13,21 };       //Copy constructor
	ForwardList list2 = { 34,55,89 };

	//list2 = list1;
	for (int i : list2)cout << i << tab; cout << endl;

	ForwardList list3;
	list3=list1 + list2;   //Move assignment
	for (int i : list3)cout << i << tab; cout << endl;

	list1.print();
	list2.print();


}