#include <fstream>
#include <iostream>
#include "Table.h"
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <chrono>
#include <unistd.h>
#include <random>


Table::Table()
{
}

Table::~Table()
{
}

int Table::loadFromFile(std::string fileName)
{
    std::ifstream theFile(fileName);
    int num;
    int index=0;
    int count=0;
    while(theFile>>num){
        if(count == 0){
            tab = (int*)malloc(num*sizeof(int));
            cnt = num;
            count++;
        }
        else{
            tab[index] = num;
            index++;
        }
    }
    theFile.close();

	return 0;
}

bool Table::IsValueInTable(int val)
{
    for(int i=0; i<cnt;i++){
        if(tab[i] == val) return true;
    }
	return false;
}

void Table::addValue(int index, int value)
{
    cnt+=1;
    tab = (int*)realloc(tab,sizeof(int)*cnt);
    if(index == cnt-1) tab[cnt-1] = value;
    else{
        for(int i=cnt-1 ; i>index;i--){
            tab[i] = tab[i-1];
        }
        tab[index] = value;
    }



}

void Table::deleteFromTable(int index)
{
    if(index == cnt-1){
        cnt-=1;
        tab = (int*)realloc(tab,sizeof(int)*cnt);
    }
    else{
        cnt-=1;
        int *tabtemp = (int*) malloc(cnt*sizeof(int));
        for(int i=0;i<cnt;i++){
            if(i<index){
                tabtemp[i] = tab[i];
            }
            else{
                tabtemp[i] = tab[i+1];
            }
        }
        free(tab);
        tab = tabtemp;
    }

}

void Table::display()
{
    for(int i=0;i<cnt;i++){
        std::cout<<tab[i];
        std::cout << " " ;
    }
    std::cout << "\n";
}



void Table::generateTable(int size)
{
        typedef std::mt19937 MyRNG;
        uint32_t seed_val;
        MyRNG rng;
        rng.seed(seed_val);
        std::uniform_int_distribution<uint32_t> uint_dist10(0,10000);

        free(tab);

        tab = (int*) malloc(size* sizeof(int));

        cnt = size;
        for(int i=0 ; i<size;i++){
            tab[i] = uint_dist10(rng);
        }




}






