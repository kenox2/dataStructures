#include "kopiec.h"
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <random>



kopiec::kopiec()
{
    //ctor
}

kopiec::~kopiec()
{
    //dtor
}



void kopiec::loadFromFile(std::string fileName){
    std::ifstream theFile(fileName);
    int num;
    int index=0;
    int count=0;
    while(theFile>>num){
        if(count == 0){
            heapSize=num-1;
            count++;
        }
        else{
            tab[index] = num;
            index++;
        }
    }
    for(int i=0;i<=heapSize;i++){
        std::cout << tab[i] << " ";
    }
    int start = heapSize/2;
    for(int i = start;i>=0;i--){
        heapify(i);
    }
    theFile.close();

}


kopiec::heapify(int i)
{
    int min=tab[i];
    int minInd;
    int left = tab[2*i+1];
    int right = tab[2*i+2];
    //wêze³ jest liœciem
    if(2*i+1 > heapSize){
        return 0;
    }
    //wêze³ ma jednego potomka
    else if(2*i+1 == heapSize){
        if(left <= right){
            min = left;
            minInd = 2*i+1;
        }


    }
    else{
        if(left <= right)
        {
            min = left;
            minInd = 2*i+1;
        }
        else{
            min = right;
            minInd = 2*i+2;
        }
    }

    if(min<tab[i]){
        tab[minInd] = tab[i];
        tab[i] = min;
        heapify(minInd);
    }
    return 0;
}


kopiec::createHeap(int size){
    heapSize =size;
    typedef std::mt19937 MyRNG;
    uint32_t seed_val=36;
    MyRNG rng;
    rng.seed(seed_val);
    std::uniform_int_distribution<uint32_t> uint_dist10(0,100000);
    for(int i=0;i<=heapSize;i++){
        tab[i] = uint_dist10(rng);
    }

    int start = heapSize/2;
    for(int i = start;i>=0;i--){
        heapify(i);
    }


    //deleteNode(0);
    //displayHeap();
    //std::cout<<std::endl;
    //addNode(14);
    //for(int i=0;i<=heapSize ;i++){
        //std::cout << tab[i] << " ";
    //}
    return 0;
}

void kopiec::extractMax(){
    tab[0]=tab[heapSize];
    heapSize--;
    heapify(0);

}

void kopiec::deleteNode(int target){
    for(int i=0;i<=heapSize;i++){
        if(tab[i]==target){
            tab[i]=tab[heapSize];
            heapSize--;

            heapifyForAdding(i);
            heapify(i);
        }
    }

}

void kopiec::addNode(int value){
    heapSize++;
    tab[heapSize] = value;
    heapifyForAdding(heapSize);
}


kopiec::heapifyForAdding(int i){
    if(i<=0) return 0;
    if(i%2==0){
        int right = tab[i];
        if(right<tab[(i/2)-1]){
            tab[i]=tab[(i/2)-1];
            tab[(i/2)-1] = right;
            heapifyForAdding((i/2)-1);
        }
    }
    else{
        int left = tab[i];
        if(left<tab[i/2]){
            tab[i]=tab[i/2];
            tab[i/2] = left;
            heapifyForAdding(i/2);
        }
    }
    return 0;
}



#define COUNT 10

void kopiec::print2DUtil(int i, int space)
{
    // Base case
    if (i > heapSize)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(2*i+2, space);

    // Print current node after space
    // count
    std::cout << std::endl;
    for (int i = COUNT; i < space; i++)
        std::cout << " ";
    std::cout << tab[i] << "\n";

    // Process left child
    print2DUtil(2*i+1, space);
}

// Wrapper over print2DUtil()
void kopiec::displayHeap()
{
    // Pass initial space count as 0
    print2DUtil(0, 0);
}


bool kopiec::searchHeap(int target){

    for(int i=0;i<=heapSize;i++){
        if(tab[i]==target){
            return true;
        }
    }
    return false;
}



