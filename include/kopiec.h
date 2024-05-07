#ifndef KOPIEC_H
#define KOPIEC_H
#include <string>


class kopiec
{


    public:
        int tab[100000000];
        int heapSize;
        kopiec();
        int heapify(int i);
        int createHeap(int size);
        virtual ~kopiec();
        void displayHeap();
        void extractMax();
        void deleteNode(int target);
        void addNode(int value);
        int heapifyForAdding(int i);
        void print2DUtil(int i, int space);
        void loadFromFile(std::string fileName);
        bool searchHeap(int target);



    protected:

    private:
};

#endif // KOPIEC_H
