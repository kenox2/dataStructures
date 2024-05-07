
class Table
{
	int *tab;
	int cnt; //ilo�� element�w w tablicy
public:

	Table(); //konstruktor - wywo�ywany automatycznie przy tworzeniu obieku
	~Table(); //destrukor - wyw�ywany automatycznie przy usuwaniu obiektu

    int loadFromFile(std::string FileName);

	bool IsValueInTable(int val);

	void addValue(int index, int value);

	void deleteFromTable(int index);

	void display();

	void generateTable(int size);


};
