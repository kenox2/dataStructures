#include <iostream>
#include <string>
#include <Table.h>
#include <fstream>
#include <List.h>
#include <kopiec.h>
#include "bst.h"
#include <chrono>


using namespace std;

Table myTab;
List myList;
kopiec kopiec;
bst Tree;


displayMenu(string info)
{
	cout << endl;
	cout << info << endl;
	cout << "1.Wczytaj z pliku" << endl;
	cout << "2.Usun" << endl;
	cout << "3.Dodaj" << endl;
	cout << "4.Znajdz" << endl;
	cout << "5.Utworz losowo" << endl;
	cout << "6.Wyswietl" << endl;
	cout << "7.Test (pomiary)" << endl;
	cout << "0.Powrot do menu" << endl;
	cout << "Podaj opcje:";
}
void menu_table()
{
	char opt;
	string fileName;
	int index, value;

    bool start = true;
	do{
		displayMenu("--- TABLICA ---");
		opt = getchar();
		cout << endl;

		switch (opt){
		case '1': //tutaj wczytytwanie  tablicy z pliku
			cout << " Podaj nazwê zbioru:";
			cin >> fileName;
			myTab.loadFromFile(fileName);
			myTab.display();
			break;

		case '2': //tutaj usuwanie elemenu z tablicy
			cout << " podaj index:";
			cin >> index;
			myTab.deleteFromTable(index);
			myTab.display();
			break;

		case '3': //tutaj dodawanie elemetu do tablicy
			cout << " podaj index:";
			cin >> index;
			cout << " podaj waertoœæ:";
			cin >> value;

			myTab.addValue(index,value);
			myTab.display();
			break;

		case '4': //tutaj znajdowanie elemetu w tablicy
			cout << " podaj wartosc:";
			cin >> value;
			if (myTab.IsValueInTable(value))
				cout << "poadana wartosc jest w tablicy";
			else
				cout << "poadanej wartosci NIE ma w tablicy";
			break;

		case '5':  //tutaj generowanie  tablicy
			cout << "Podaj ilosc elementów tablicy:";
			cin >> value;
			myTab.generateTable(value);
			myTab.display();
			break;

		case '6':  //tutaj wyœwietlanie tablicy
			myTab.display();
			break;

		case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie bêdzie testowana przez prowadz¹cego
			      // mo¿na sobie tu dodaæ w³asne dodatkowe case'y
			break;
        case '0':
            start = false;
            break;
		}


	} while (start);
}



void menu_List()
{
	char opt;
	string fileName;
	int index, value;
    bool start=true;

	do{
		displayMenu("--- LISTA---");
		opt = getchar();
		cout << endl;
		switch (opt){
		case '1': //tutaj wczytytwanie  tablicy z pliku
			cout << " Podaj nazwê zbioru:";
			cin >> fileName;
			myList.loadFromFile(fileName);
			myList.display();
			break;

		case '2': //tutaj usuwanie elemenu z listu
			cout << " podaj liczbe:";
			cin >> index;
			myList.deleteFromList(index);
			myList.display();
			break;

		case '3': //tutaj dodawanie elemetu do tablicy
			cout << " podaj index:";
			cin >> index;
			cout << " podaj waertoœæ:";
			cin >> value;

			myList.addValue(index,value);
			myList.display();
			break;

		case '4': //tutaj znajdowanie elemetu w tablicy
			cout << " podaj wartosc:";
			cin >> value;
			if (myList.IsValueInList(value))
				cout << "poadana wartosc jest w liscie";
			else
				cout << "poadanej wartosci NIE ma w liscie";
			break;

		case '5':  //tutaj generowanie  tablicy
			cout << "Podaj ilosc elementów tablicy:";
			cin >> value;
			myList.generateList(value);
			myList.display();
			break;

		case '6':  //tutaj wyœwietlanie tablicy
			myList.display();
			break;

		case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie bêdzie testowana przez prowadz¹cego
			      // mo¿na sobie tu dodaæ w³asne dodatkowe case'y
            break;
        case '0':
            start = false;
            break;
		}


	} while (start);
}


void menu_Kopiec()
{
	char opt;
	string fileName;
	int index, value;
    bool start=true;

	do{
		displayMenu("--- KOPIEC---");
		opt = getchar();
		cout << endl;
		switch (opt){
		case '1': //tutaj wczytytwanie  tablicy z pliku
			cout << " Podaj nazwê zbioru:";
			cin >> fileName;
			kopiec.loadFromFile(fileName);
			kopiec.displayHeap();
			break;

		case '2': //tutaj usuwanie elemenu z listu
			cout << " podaj liczbe:";
			cin >> index;
			kopiec.deleteNode(index);
			kopiec.displayHeap();
			break;

		case '3': //tutaj dodawanie elemetu do tablicy
			cout << " podaj wartosc:";
			cin >> value;

			kopiec.addNode(value);
			kopiec.displayHeap();
			break;

		case '4': //tutaj znajdowanie elemetu w tablicy
			cout << " podaj wartosc:";
			cin >> value;
			if (kopiec.searchHeap(value))
				cout << "poadana wartosc jest w kopcu";
			else
				cout << "poadanej wartosci NIE ma w kopcu";
			break;

		case '5':  //tutaj generowanie  tablicy
			cout << "Podaj ilosc elementów tablicy:";
			cin >> value;
			kopiec.createHeap(value);
			kopiec.displayHeap();
			break;

		case '6':  //tutaj wyœwietlanie tablicy
			kopiec.displayHeap();
			break;

		case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie bêdzie testowana przez prowadz¹cego
			      // mo¿na sobie tu dodaæ w³asne dodatkowe case'y
            break;
        case '0':
            start = false;
            break;
		}


	} while (start);
}




void menu_BST()
{
	char opt;
	string fileName;
	int index, value;
    bool start=true;

	do{
		displayMenu("--- BST---");
		opt = getchar();
		cout << endl;
		switch (opt){
		case '1': //tutaj wczytytwanie  tablicy z pliku
			cout << " Podaj nazwê zbioru:";
			cin >> fileName;
			Tree.loadFromFile(fileName);
			Tree.displayTree();
			break;

		case '2': //tutaj usuwanie elemenu z listu
			cout << " podaj liczbe:";
			cin >> index;
			Tree.deleteNode(index);
			Tree.displayTree();
			break;

		case '3': //tutaj dodawanie elemetu do tablicy
			cout << " podaj wartosc:";
			cin >> value;

			Tree.addNode(value);
			Tree.displayTree();
			break;

		case '4': //tutaj znajdowanie elemetu w tablicy
			cout << " podaj wartosc:";
			cin >> value;
			if (Tree.searchT(value))
				cout << "poadana wartosc jest w drzewie";
			else
				cout << "poadanej wartosci NIE ma w drzewie";
			break;

		case '5':  //tutaj generowanie  tablicy
			cout << "Podaj ilosc elementów tablicy:";
			cin >> value;
			myList.generateList(value);
			Tree.displayTree();
			break;

		case '6':  //tutaj wyœwietlanie tablicy
			Tree.displayTree();
			break;

		case '7': //tutaj nasza funkcja do eksperymentów (pomiary czasów i generowanie daneych) - nie bêdzie testowana przez prowadz¹cego
			      // mo¿na sobie tu dodaæ w³asne dodatkowe case'y
            break;
        case '0':
            start = false;
            break;
		}


	} while (start);
}



void menuMain(){

    char opt;
    while(true){
        cout <<"1. Tablica"<< endl;
        cout << "2. Lista" << endl;
         cout <<"3. Kopiec"<< endl;
        cout << "4. BST" << endl;
        cout << "podaj cyfre: "<<endl;
      opt = getchar();
    switch(opt){
    case '1':
        menu_table();
        break;
    case '2':
        menu_List();
        break;
    case '3':
        menu_Kopiec();
        break;
    case '4':
        menu_BST();
    }
    }

}



int main()
{

   menuMain();





    return 0;
}







