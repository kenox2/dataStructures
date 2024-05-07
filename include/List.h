#ifndef LIST_H
#define LIST_H
#include <string>


class List
{

    int cnt; // ilosc węzłów

public:
	List(); //konstruktor - wywo³ywany automatycznie przy tworzeniu obieku
	~List(); //destrukor - wyw³ywany automatycznie przy usuwaniu obiektu

	int loadFromFile(std::string fileName);

	bool IsValueInList(int val);

	void addValue(int index, int value);

	void deleteFromList(int value);

	void display();

	void generateList(int size);



};

#endif // LIST_H
