#ifndef NOTE_H
#define NOTE_H
#include <string>
#include <vector>
#include "page.hpp"
#pragma once
using namespace std;

namespace ariel{
    class Notebook{
        int pageCounter;
        std::vector<Page *> pages;
        public:
            Notebook() {this->pageCounter=0;}
            int getPageNumber() {return this->pageCounter;}
            bool isPageExist(int index) {
                if(index<0||index>=this->pageCounter){
                    return false;
                }
                return true;
            }
            void addPage();
            Page getPage(int pageIndex);
            void write(int page, int row, int col, ariel::Direction dir, string str);
            string read(int page, int row, int col, ariel::Direction dir, int length);
            void erase(int page, int row, int col, ariel::Direction dir, int length);
            void show(int page);

    };
};

#endif
;