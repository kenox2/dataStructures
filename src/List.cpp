#include "List.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <chrono>
#include <random>

class Node{
public:
    int value;
    Node* next;
    Node* previous;
};


Node *head;
Node *tail;
Node *node;
Node *temp;


List::List()
{
    //ctor
}

List::~List()
{
    //dtor
}

int List::loadFromFile(std::string fileName){
     std::ifstream theFile(fileName);
    int num;
    int index=0;
    int count=0;
    while(theFile>>num){
        if(count == 0){
            cnt=num;
            count++;
        }
        else if(count == 1){
            node = new Node();
            node->value = num;
            node->next = nullptr;
            node->previous = nullptr;
            head = node;
            tail = node;
            count++;
        }
        else{
            node = new Node();
            node->value = num;
            node->next = nullptr;
            node->previous = tail;
            tail->next = node;
            tail = node;
        }
    }
    theFile.close();


	return 0;


}

bool List::IsValueInList(int val){
        node = head;
        for(int i=0;i< cnt ;i++){
        if(node->value==val) {
                return true;
        }
        node = node->next;
        }
        return false;


}


void List::addValue(int index, int value){

    if(index ==0){
        if(head==nullptr){
             node = new Node();
            node->value = value;
            node->previous=nullptr;
            node->next = head;
            head = node;
            if(cnt == 0){
                tail = node;
            }
        }
        else{
            node = new Node();
            node->value = value;
            node->previous=nullptr;
            node->next = head;
            head->previous = node;
            head = node;

        }


    }
    else if(index == cnt){
         node = new Node();
        node->value = value;
        node->previous=tail;
        node->next = nullptr;
        tail->next = node;
        tail = node;
    }
    else{
        node = head;
        for(int i=0;i<cnt;i++){
            if(i==index){
                temp = new Node();
                temp->value = value;
                temp->next = node;
                temp->previous = node->previous;

                temp->previous->next = temp; // ustawia wskaznik poprzedniego z node na temp
                node->previous = temp;

                break;
            }
            node = node->next;
        }
    }
    cnt++;
}

void List::deleteFromList(int value){
      node = head;
        for(int i=0;i<cnt;i++){
            if(node->value == value){
                if(i==0){
                    if(cnt==1){
                        head=nullptr;
                        tail=nullptr;
                        delete node;
                    }
                    else{
                        head = node->next;
                        node->next->previous = nullptr;
                        delete node;

                    }

                }
                else if(i==cnt-1){
                    tail = node->previous;
                    node->previous->next = nullptr;
                    delete node;

                }
                else{
                    node->previous->next = node->next;
                    node->next->previous = node->previous;
                    delete node;

                }
                break;

            }
            node = node->next;
        }
        cnt--;

}

void List::display(){
    node = head;
    std::cout<<std::endl;
    for(int i=0;i<cnt;i++){
        std::cout << node->value;
        std::cout << ' ';
        node = node->next;
    }
    std::cout<<std::endl;
    node = tail;
    for(int i=0;i<cnt;i++){
        std::cout << node->value;
        std::cout << ' ';
        node = node->previous;
    }
    std::cout<<std::endl;



}

void List::generateList(int size){

    cnt = size;
    typedef std::mt19937 MyRNG;
    uint32_t seed_val;
    MyRNG rng;
    rng.seed(seed_val);
    std::uniform_int_distribution<uint32_t> uint_dist10(0,1000000);
    for(int i=0;i<size;i++){//tworze wybrana ilosc wêz³ów
        if(i==0){
            node = new Node();
            node->value = uint_dist10(rng);
            node->next = nullptr;
            node->previous = nullptr;
            head = node;
            tail = node;
        }
        else{
            node = new Node();
            node->value = uint_dist10(rng);
            node->next = nullptr;
            node->previous = tail;
            tail->next = node;
            tail = node;
        }

    }




}






