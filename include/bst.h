#ifndef BST_H
#define BST_H
#include <string>

class bst
{
    public:

        bst();
        virtual ~bst();
        void addNode(int k);
        void build();
        bool searchT(int k);
        void deleteNode(int k);
        void loadFromFile(std::string fileName);
        void displayTree();




    protected:

    private:
};

#endif // BST_H
