#include "bst.h"
#include <stdlib.h>
#include <iostream>
#include <random>
#include <fstream>
#include <chrono>


class bstNode{
    public:
        int key;
        bstNode *parent;
        bstNode *right;
        bstNode *left;

        bstNode(int value,bstNode *parent=nullptr,bstNode *left=nullptr, bstNode *right=nullptr){
            key = value;
            this->parent = parent;
            this->left = left;
            this->right = right;
        }

};;

bstNode *root = nullptr;

bst::bst()
{

    //ctor
}

bst::~bst()
{
    //dtor
}

void bst::loadFromFile(std::string fileName){
    if(root!=nullptr){
        root = nullptr;
    }
    std::ifstream theFile(fileName);
    int num;
    int index=0;
    int count=0;
    while(theFile>>num){
        if(count == 0){
            count++;
        }
        else{
            addNode(num);
        }
    }

    theFile.close();
}

void bst::addNode(int k){
    bstNode *node = root;
    bstNode *parent = nullptr;
    if(root == nullptr){
        root = new bstNode(k);
    }
    else{
       while(node != nullptr){
            parent = node;
            if( k <= node->key){
                node = node->left;
            }
            else{
                node = node->right;
            }
        }
        node = new bstNode(k);
        node->parent = parent;
        if( k <= parent->key){
                parent->left = node;
            }
        else{
                parent->right = node;
            }
    }


}


void displayInOrder(bstNode *node){
    if(node!= nullptr){
        displayInOrder(node->left);
        std::cout << node->key;
        std::cout << " ";
        displayInOrder(node->right);
    }

}


bstNode* searchTree(int k,bstNode *node=root){

    while(node !=nullptr && k != node->key){
        if(k<node->key){
            node = node->left;
        }
        else{
            node = node->right;
        }
    }
    return node;
}






bool bst::searchT(int k){
    bstNode *node = searchTree(k);
    if(node != nullptr){
        return true;
    }
    else{
        return false;
    }

}





bstNode* minNode(bstNode* node = root){
    if(node->left == nullptr){
        return node;
    }
    else{
        minNode(node->left);
    }
}





void bst::deleteNode(int k){
    bstNode *node = searchTree(k);
    bstNode *temp;

    if(node->right != nullptr)temp = minNode(node->right);


    if(node->right == nullptr){
        if(node->right== nullptr && node->left==nullptr){
            std::cout<<"essa";
            if(k < node->parent->key){
                node->parent->left = nullptr;
            }
            else{
                node->parent->right = nullptr;
            }
            delete node;
        }
        else{
            node->left->parent = node->parent;
            if(k < node->parent->key){
                node->parent->left = node->left;
            }
            else{
                node->parent->right = node->left;
            }
        }
    }
    else{



            node->key = temp->key;
            if(temp->parent == node){
                temp->parent->right = temp->right;
            }
            else{
                temp->parent->left = temp->right;
            }

            delete temp;

    }




}





#define COUNT 10


void print2DUtil(bstNode* root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    std::cout << std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout << " ";
    std::cout << root->key << "\n";

    // Process left child
    print2DUtil(root->left, space);
}

void bst::displayTree()
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}


void bst::build(){
    typedef std::mt19937 MyRNG;
    uint32_t seed_val=26;
    MyRNG rng;
    rng.seed(seed_val);
    std::uniform_int_distribution<uint32_t> uint_dist10(0,100000);
    root=new bstNode(4);
    for(int i=0;i<250000;i++){
        int value =  uint_dist10(rng);
        addNode(value);
    }

    //displayTree();



}
















