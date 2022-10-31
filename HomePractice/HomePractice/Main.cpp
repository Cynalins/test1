#include "Headers.h"

class Object
{
public:
	int kor;
	int eng;
	int math;
};

Object* CreateObject(int _kor, int _eng, int _math);
void AddList(Object* _pobj, int _value);

map<int, list<Object*>> Objects;

int main()
{
	for (int i = 0; i < 5; ++i)
	{
		srand(GetTickCount64());

		Object* pobj = CreateObject(rand() % 71 + 30, rand() % 71 + 30, rand() % 71 + 30);

		int value = 0;

		cout << "ют╥б : "; cin >> value;
		AddList(pobj, value);
	}

	for (map<int, list<Object*>>::iterator iter = Objects.begin(); iter != Objects.end(); ++iter)
	{
		for (list<Object*>::iterator iter2 = (*iter).second.begin(); iter2 != (*iter).second.end(); ++iter2)
		{
			cout << (*iter).first << " :  kor : " << (*iter2)->kor << " eng : " << (*iter2)->eng << " math : " << (*iter2)->math << endl;
		}
	}


	return 0;
}

Object* CreateObject(int _kor, int _eng, int _math)
{
	Object* pobj = new Object;

	pobj->kor = _kor;
	pobj->eng = _eng;
	pobj->math = _math;

	return pobj;
}

void AddList(Object* _pobj, int _value)
{
	map<int, list<Object*>>::iterator iter = Objects.find(_value);

	if (iter == Objects.end())
	{
		list<Object*> temp;

		temp.push_back(_pobj);
		Objects.insert(make_pair(_value, temp));
	}
	else
		iter->second.push_back(_pobj);



}
