#ifndef PAGE_H
#pragma once
#define PAGE_H
#include <string>
#include "row.hpp"
#include <vector>
#include "Direction.hpp"
using namespace std;
class Page
{
    std::vector<Row *> rows;
    int rowCounter;
    Page();
    ~Page();
    public:
        int getRowCount() {return this->rowCounter;}
        bool isRowExist(int rowIndex) {return rowIndex>=0 && rowIndex<rowCounter;}
        void addRow(string str, int startFrom);
        void addRow();
        void removeCharAt(int row, int col);
        void writeToRow(int rowIndex, int startFrom, string str, ariel::Direction dir);
};

#endif