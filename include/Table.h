
class Table
{
	int *tab;
	int cnt; //iloœæ elementów w tablicy
public:

	Table(); //konstruktor - wywo³ywany automatycznie przy tworzeniu obieku
	~Table(); //destrukor - wyw³ywany automatycznie przy usuwaniu obiektu

    int loadFromFile(std::string FileName);

	bool IsValueInTable(int val);

	void addValue(int index, int value);

	void deleteFromTable(int index);

	void display();

	void generateTable(int size);


};
